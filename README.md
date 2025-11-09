# Mac OSX SDKs

A collection of the MacOSx SDKs. Each commit is a new version of the SDK, to
allow easily diffing for the differences between each version.

If you don't need this entire repository, each SDK is available
[here](https://github.com/roblabla/MacOSX-SDKs/releases).

**Important**

Modern versions of Xcode (7.3+) need you to edit the `MinimumSDKVersion` in this file to use older SDKs:
`/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Info.plist`

**Usage**

Set the SDKROOT environment variable:
```
export SDKROOT=path-to-old-sdk
```

If you put an old SDK in a nonstandard path, Apple's hacks in /usr/bin which redirect to calling Apple's
tools in the XCode installation may fail. If your build system fails to find the compiler, explicitly
specify its path:

```
export CC="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang"
export CXX="/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++"
```

If you are building a project with CMake, using the default Unix Makefile generator may fail to
find the real `make` binary even if you put it in your $PATH before /usr/bin. To hack around this, install
[Ninja](https://ninja-build.org/) in your $PATH and use the Ninja CMake generator by running your CMake
configure step with:

```
cmake -G Ninja -S project-root-dir -B build-output-dir
```
