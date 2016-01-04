//
//  JiverMention.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 7. 30..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverSender.h"

/**
 *  Class used for user memtions. This class is returned as an object when mentionUpdated callback is invoked from [`registerNotificationHandlerMessagingChannelUpdatedBlock:mentionUpdatedBlock:`](./Jiver.html#//api/name/registerNotificationHandlerMessagingChannelUpdatedBlock:mentionUpdatedBlock:) of [`Jiver`](./Jiver.html)
 */
@interface JiverMention : NSObject

/**
 *  Channel URL where the user was mentioned
 */
@property (retain) NSString *channelUrl;

/**
 *  Type of the channel the user was mentioned in
 */
@property (retain) NSString *channelType;

/**
 *  Message sent during the mention
 */
@property (retain) NSString *message;

/**
 *  The sender who mentioned the user
 */
@property (retain) JiverSender *sender;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *) dic;

- (NSString *) toJson;

/**
 *  User name of the sender
 *
 *  @return User name
 */
- (NSString *) getSenderName;

/**
 *  Profile image URL of the sender
 *
 *  @return Profile image URL
 */
- (NSString *) getSenderImageUrl;

@end
