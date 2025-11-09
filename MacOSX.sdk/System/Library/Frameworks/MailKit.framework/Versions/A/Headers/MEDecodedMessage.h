//
//  MEDecodedMessage.h
//  MailKit
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MEMessageSecurityInformation;

NS_ASSUME_NONNULL_BEGIN

/// @brief Contains information about a decoded message
API_AVAILABLE(macos(12.0)) API_UNAVAILABLE(ios, watchos, tvos, macCatalyst)
@interface MEDecodedMessage : NSObject <NSSecureCoding>

/// @brief The decoded MIME data for the message
/// The decoded data should not be encrypted or contain any signatures that were decoded. The @c rawData here should only contain MIME parts that a standard email parser can decode without needing to decrypt. All information on the encryption and signature status should be defined in @c securityInformation.
/// If the message is unable to be decrypted this should be left nil and an error message will be displayed to the user.
@property (nonatomic, nullable, readonly, copy) NSData *rawData;

/// @brief The security information for whether or not the message was signed, encrypted, or had an errors in decoding.
@property (nonatomic, readonly, strong) MEMessageSecurityInformation *securityInformation;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithData:(nullable NSData *)rawData securityInformation:(MEMessageSecurityInformation *)securityInformation;
@end

NS_ASSUME_NONNULL_END
