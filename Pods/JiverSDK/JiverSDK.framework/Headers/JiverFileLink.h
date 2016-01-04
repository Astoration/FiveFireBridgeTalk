//
//  FileLink.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverFileInfo.h"
#import "JiverSender.h"
#import "JiverMessageModel.h"
#import "JiverBlockedUser.h"

/**
 *  Class for file being transfered through messaging. This class includes sender, file information, and message blocked status
 */
@interface JiverFileLink : JiverMessageModel

/**
 *  Message sender. Uses [`JiverSender`](./JiverSender.html) class
 */
@property (retain) JiverSender *sender;

/**
 *  File information. Uses [`JiverFileInfo`](./JiverFileInfo.html) class
 */
@property (retain) JiverFileInfo *fileInfo;

@property BOOL isOpMessage;

@property BOOL isGuestMessage;

@property (retain) NSDictionary *jsonObj;

/**
 *  Returns YES if sent by a blocked user, otherwise returns NO
 */
@property BOOL isBlocked;

- (id) initWithDic:(NSDictionary *)dic inPresent:(BOOL)present;

/**
 *  Get the name of the sender
 *
 *  @return User name of the sender
 */
- (NSString *)getSenderName;

- (NSString *) toJson;

@end
