//
//  MEMessageAction.h
//  MailKit
//
//  Copyright © 2020 Apple Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger,  MEMessageActionMessageColor) {
    MEMessageActionMessageColorNone,
    MEMessageActionMessageColorGreen,
    MEMessageActionMessageColorYellow,
    MEMessageActionMessageColorOrange,
    MEMessageActionMessageColorRed,
    MEMessageActionMessageColorPurple,
    MEMessageActionMessageColorBlue,
    MEMessageActionMessageColorGray,
} API_AVAILABLE(macos(12.0)) API_UNAVAILABLE(ios, watchos, tvos, macCatalyst);

/// @brief An action that can be performed on a mail message.
API_AVAILABLE(macos(12.0)) API_UNAVAILABLE(ios, watchos, tvos, macCatalyst)
@interface MEMessageAction : NSObject <NSSecureCoding>

/// @brief Moves the mail message to the user's trash mailbox for the account.
@property (class, readonly) MEMessageAction *moveToTrashAction;

/// @brief Moves the mail message to the user's archive mailbox for the account.
@property (class, readonly) MEMessageAction *moveToArchiveAction;

/// @brief Moves the mail message to the user's junk mailbox for the account.
@property (class, readonly) MEMessageAction *moveToJunkAction;

/// @brief Marks the mail message as read.
@property (class, readonly) MEMessageAction *markAsReadAction;

/// @brief Marks the mail  message as unread.
@property (class, readonly) MEMessageAction *markAsUnreadAction;

/// @brief Marks the mail message as flagged.
@property (class, readonly) MEMessageAction *flagAction;

/// @brief Removes any flags from the mail message.
@property (class, readonly) MEMessageAction *unflagAction;

/// @brief Adds a color to the message when shown in the message list.
+ (MEMessageAction *)setColorActionWithColor:(MEMessageActionMessageColor)color NS_SWIFT_NAME(setColor(_:));

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
