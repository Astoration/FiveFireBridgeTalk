//
//  Sender.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 6..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class used for sender.
 */
@interface JiverSender : NSObject

/**
 *  Integer number ID assigned to user for identification.
 */
@property long long senderId;

/**
 *  User name
 */
@property (retain) NSString *name;

/**
 *  Profile image URL
 */
@property (retain) NSString *imageUrl;

/**
 *  ID used for identification. Same as [`JiverUser guestID`](./JiverUser.html#//api/name/guestId)
 */
@property (retain) NSString *guestId;

- (id) initWithDic:(NSDictionary *)dic;

@end
