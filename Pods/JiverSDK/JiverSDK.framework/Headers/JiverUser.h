//
//  User.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  User class. Either a new user is created or logged in using an existing user based on the parameters set using [`loginWithUserName:`](./Jiver.html#//api/name/loginWithUserName:), [`loginWithUserName:andUserImageUrl:`](./Jiver.html#//api/name/loginWithUserName:andUserImageUrl:), [`igawLoginWithUserId:`](/Jiver.html#//api/name/igawLoginWithUserId:), [`igawLoginWithUserName:`](./Jiver.html#//api/name/igawLoginWithUserName:), [`igawLoginWithUserName:andUserImageUrl:`](./Jiver.html#//api/name/igawLoginWithUserName:andUserImageUrl:), [`loginWithUserId:andUserName:`](./Jiver.html#//api/name/loginWithUserId:andUserName:) methods. [`guestId`](./JiverUser.html#//api/name/guestId) is used to identify unique users, so we recommending using [`guestId`](./JiverUser.html#//api/name/guestId) to map the app's users to JIVER users.
 */
@interface JiverUser : NSObject

/**
 *  Integer value ID asssigned to users
 */
@property long long userId;

/**
 *  User name
 */
@property (retain) NSString *name;

/**
 *  Profile iamge URL
 */
@property (retain) NSString *imageUrl;

/**
 *  Unique identifier assigned to users
 */
@property (retain) NSString *guestId;

@property (retain) NSDictionary *jsonObj;

- (id) initWithDic:(NSDictionary *)dic;

@end
