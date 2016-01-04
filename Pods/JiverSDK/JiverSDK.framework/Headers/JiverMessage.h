//
//  Message.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverSender.h"
#import "JiverMessageModel.h"

/**
 *  Class for messaging. Used in callbacks retrieving the messages.
 *
 *  - Returns from `messageReceived` callback in [`setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) of [`Jiver`](./Jiver.html)
 *  - Returns as a part of `queryResult` from `onResult` in [`nextWithMessageTs:andLimit:resultBlock:endBlock:`](./JiverMessageListQuery.html#//api/name/nextWithMessageTs:andLimit:resultBlock:endBlock:), [`prevWithMessageTs:andLimit:resultBlock:endBlock:`](./JiverMessageListQuery.html#//api/name/prevWithMessageTs:andLimit:resultBlock:endBlock:), [`loadWithMessageTs:prevLimit:andNextLimit:resultBlock:endBlock:`](./JiverMessageListQuery.html#//api/name/loadWithMessageTs:prevLimit:andNextLimit:resultBlock:endBlock:) of [`JiverMessageListQuery`](./JiverMessageListQuery.html)
 */

@interface JiverMessage : JiverMessageModel

/**
 *  Message body
 */
@property (retain) NSString *message;

/**
 *  Message sender
 */
@property (retain) JiverSender *sender;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

/**
 *  Additional data sent along with the message
 */
@property (retain) NSString *data;

@property (retain) NSDictionary *jsonObj;

/**
 *  Message ID used for verifying successful delivery
 */
@property (retain) NSString *tempId;

/**
 *  Returns YES if the user is blocked, otherwise returns NO
 */
@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

/**
 *  Method used for checking if the senders are the same person
 *
 *  @param msg Message to compare
 *
 *  @return Returns YES if the same, otherwise returns NO
 */
- (BOOL) hasSameSender:(JiverMessage *)msg;

/**
 *  Returns the name of the sender
 *
 *  @return User name of the sender
 */
- (NSString *)getSenderName;

- (void) mergeWith:(JiverMessage *)merge DEPRECATED_ATTRIBUTE;

- (NSString *) toJson;

@end
