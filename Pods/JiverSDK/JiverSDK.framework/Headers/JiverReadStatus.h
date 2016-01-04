//
//  ReadStatus.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverUser.h"

/**
 *  Class used for handling read receipts of a user within Messaging/Group messaging channel. This class is returned when `readReceivedBlock` callback of [`Jiver setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:)is called, and this callback is invoked when another user in the channel calls [`markAsRead`](./Jiver.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Jiver.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Jiver.html#//api/name/markAllAsRead).
 */
@interface JiverReadStatus : NSObject

/**
 *  User who called [`markAsRead`](./Jiver.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Jiver.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Jiver.html#//api/name/markAllAsRead) after joining the channel
 */
@property (retain) JiverUser *user;

/**
 *  Timestamp when the user called [`markAsRead`](./Jiver.html#//api/name/markAsRead), [`markAsReadForChannel:`](./Jiver.html#//api/name/markAsReadForChannel:), [`markAllAsRead`](./Jiver.html#//api/name/markAllAsRead)
 */
@property long long timestamp;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

/**
 *  Returns a unique identifier [`JiverUser`](./JiverUser.html)의 [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @return [`JiverUser guestId`](./JiverUser.html#//api/name/guestId)
 */
- (NSString *) getUserId;

- (NSString *) toJson;

@end
