//
//  SystemMessage.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverMessageModel.h"

#define kJiverCategoryNone 0
#define kJiverCategoryChannelJoin 10100
#define kJiverCategoryChannelLeave 10101
#define kJiverCategoryChannelInvite 10102
#define kJiverCategoryTooManyMessages 10200
#define kJiverCategoryMessagingUserBlocked 10300
#define kJiverCategoryMessagingUserDeactivated 10400

/**
 *  Class used for system messages. The object is returned when systemMessageReceived callback is invoked by [`setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) of [`Jiver`](./Jiver.html)
 */
@interface JiverSystemMessage : JiverMessageModel

/**
 *  Message body
 */
@property (retain) NSString *message;

@property (retain) NSDictionary *jsonObj;

/**
 *  Message type
 *
 *  - Joined the channel  - 10100
 *  - Left the channel - 10101
 *  - Invited to the channel - 10102
 *  - Muted - 10500
 */
@property long long category;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;
- (NSString *) toJson;

@end
