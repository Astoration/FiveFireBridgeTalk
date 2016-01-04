//
//  MemberInMessagingChannel.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class for members within Messaging/Group messaging channel. The values are identical to [`JiverUser`](./JiverUser.html) class
 */
@interface JiverMemberInMessagingChannel : NSObject

/**
 *  Member ID generated upon creation
 */
@property long long memberId;

/**
 *  Member name
 */
@property (retain) NSString *name;

/**
 *  Member's profile image URL
 */
@property (retain) NSString *imageUrl;

/**
 *  Unique ID to identify the member
 */
@property (retain) NSString *guestId;

@property long long lastReadMillis;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *) dic;

- (NSString *) toJson;

@end
