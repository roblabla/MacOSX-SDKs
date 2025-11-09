#if (defined(USE_UIKIT_PUBLIC_HEADERS) && USE_UIKIT_PUBLIC_HEADERS) || !__has_include(<UIKitCore/UIImageVariants.h>)
//
//  UIImageVariants.h
//  UIKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, UIImageVariant) {
    UIImageVariantNone = 0,              // don't use any shape. This is different than unspecified.

    UIImageVariantCircle = 1 << 1,       // prefer a circle shape
    UIImageVariantSquare = 1 << 2,       // prefer a square shape
    UIImageVariantRectangle = 1 << 3,    // prefer a rectangle shape

    UIImageVariantSlash = 1 << 16,       // prefer a slash accessory

    UIImageVariantFill = 1 << 30,        // prefer a filled shape
} API_AVAILABLE(ios(15.0)) NS_REFINED_FOR_SWIFT;

#else
#import <UIKitCore/UIImageVariants.h>
#endif
