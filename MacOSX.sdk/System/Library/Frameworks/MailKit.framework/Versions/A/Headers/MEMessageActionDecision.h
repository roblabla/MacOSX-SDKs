//
//  MEMessageActionDecision.h
//  Email
//
//  Copyright © 2021 Apple Inc. All rights reserved.
//

@class MEMessageAction;

NS_ASSUME_NONNULL_BEGIN

API_AVAILABLE(macos(12.0)) API_UNAVAILABLE(ios, watchos, tvos, macCatalyst)
@interface MEMessageActionDecision : NSObject <NSSecureCoding>
@property (class, readonly) MEMessageActionDecision *invokeAgainWithBody;
+ (MEMessageActionDecision *)applyAction:(MEMessageAction *)action NS_SWIFT_NAME(action(_:));
- (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
@end

NS_ASSUME_NONNULL_END
