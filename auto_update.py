#!/usr/bin/env python
# /// script
# requires-python = ">=3.14"
# dependencies = [
#     "requests",
# ]
# ///

from pathlib import Path
import plistlib
import requests
import shutil
import subprocess
from tempfile import TemporaryDirectory


COOKIE = ''

def get_sdk_name(plist_path: Path) -> str:
    out = subprocess.run(['plutil', '-extract', 'name', 'raw', str(plist_path)], capture_output=True, text=True)
    if out.returncode != 0:
        out = subprocess.run(['plutil', '-extract', 'DisplayName', 'raw', str(plist_path)], capture_output=True, text=True, check=True)
    name = out.stdout.removesuffix('\n')
    return name


def get_build() -> str:
    with open("MacOSX.sdk/System/Library/CoreServices/SystemVersion.plist", "rb") as f:
        data = plistlib.load(f)
    return data['ProductBuildVersion']


def get_sdks() -> list:
    r = requests.get('https://xcodereleases.com/data.json')
    r.raise_for_status()
    data = [xcode for xcode in r.json() if 'release' in xcode['version']['release'] or 'gm' in xcode['version']['release']]
    #data = [xcode for xcode in r.json()]
    sdks = []
    seen_builds = set()
    for elem in data:
        if elem.get('sdks', {}).get('macOS', None) is None:
            continue

        for sdk in elem['sdks']['macOS']:
            if 'build' in sdk:
                build_id = sdk['build']
            else:
                build_id = sdk['number']

        if build_id in seen_builds:
            continue
        seen_builds.add(build_id)
        elem['BuildID'] = build_id
        sdks.append(elem)
    return sdks

build_id = get_build()
sdks = get_sdks()
pos = next(idx for idx, v in enumerate(sdks) if v['BuildID'] == build_id)

for sdk in reversed(sdks[:pos]):
    # Download the SDK
    url = sdk['links']['download']['url']
    print(f"Downloading Xcode {sdk['version']['number']} ({sdk['version']['build']})")
    with TemporaryDirectory(delete=False) as tmpdir:
        tmpdir = Path(tmpdir)
        xip_path = tmpdir / 'xcode.xip'
        cookies = {'ADCDownloadAuth': COOKIE}
        with requests.get(url, stream=True, cookies=cookies) as r:
            r.raise_for_status()
            with open(xip_path, 'wb') as f:
                for chunk in r.iter_content(chunk_size=1024 * 1024):
                    f.write(chunk)

        subprocess.run(['xip', '--expand', str(xip_path)], check=True, cwd=tmpdir)

        xcode_path = next(x for x in tmpdir.iterdir() if x.suffix == '.app')
        sdk_path = xcode_path / "Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk"
        sdk_name = get_sdk_name(sdk_path / "SDKSettings.plist")

        if Path('MacOSX.sdk').exists():
            shutil.rmtree('MacOSX.sdk')

        shutil.copytree(sdk_path, 'MacOSX.sdk', symlinks=True)
        subprocess.run(['git', 'add', 'MacOSX.sdk'], check=True)
        subprocess.run(['git', 'commit', '-m', sdk_name], check=True)
