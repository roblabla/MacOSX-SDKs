//
//  MEMessageSecurityHandler.h
//  MailKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <MailKit/MEMessageDecoder.h>
#import <MailKit/MEMessageEncoder.h>

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(12.0)) API_UNAVAILABLE(ios, watchos, tvos, macCatalyst)
@protocol MEMessageSecurityHandler <MEMessageEncoder, MEMessageDecoder>

#if !TARGET_OS_WATCH
/// @brief Invoked by Mail to request a subclass of @c MEExtensionViewController. Extensions can maintain any additional state in their subclasses and associate it with  @c messsageComposeSession instance.
- (nullable MEExtensionViewController *)extensionViewControllerForMessageSigners:(NSArray<MEMessageSigner *> *)messageSigners NS_SWIFT_NAME(extensionViewController(signers:));
#endif

@end

NS_ASSUME_NONNULL_END
