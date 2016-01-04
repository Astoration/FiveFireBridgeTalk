//
//  JiverMessageListQuery.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 6. 26..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  Class used to retrieve a number of previous or next messages based on a timestamp. This class is not used directly, but instead [`queryMessageListInChannel:`](./Jiver.html#//api/name/queryMessageListInChannel:) of [`Jiver`](./Jiver.html) must be used to creat instances.
 */
@interface JiverMessageListQuery : NSObject

- (id) initWithJiverClient:(JiverClient *)client andChannelUrl:(NSString *)channelUrl;

- (BOOL) isLoading;

/**
 *  Used to retrieve next messages based on a timestamp
 *
 *  @param messageTs Base timestamp (UTC)
 *  @param limit     Number of messages to retrieve
 *  @param onResult  Callback invoked upon successful retrieval. queryResult is an array of [`JiverMessageModel`](./JiverMessageModel.html)
 *  @param onError   Callback invoked upon failure
 */
- (void) nextWithMessageTs:(long long)messageTs andLimit:(int)limit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

/**
 *  Used to retrieve previous messages based on a timestamp
 *
 *  @param messageTs Base timestamp (UTC)
 *  @param limit     Number of messages to retrieve
 *  @param onResult  Callback invoked upon successful retrieval. queryResult is an array of [`JiverMessageModel`](./JiverMessageModel.html)
 *  @param onError   Callback invoked upon failure
 */
- (void) prevWithMessageTs:(long long)messageTs andLimit:(int)limit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

/**
 *  Used to retrieve previous and next messages based on a timestamp
 *
 *  @param messageTs Base timestamp (UTC)
 *  @param prevLimit Number of previous messages to retrieve
 *  @param nextLimit Number of next messages to retrieve
 *  @param onResult  Callback invoked upon successful retrieval. queryResult is an array of [`JiverMessageModel`](./JiverMessageModel.html)
 *  @param onError   Callback invoked upon failure
 */
- (void) loadWithMessageTs:(long long)messageTs prevLimit:(int)prevLimit andNextLimit:(int)nextLimit resultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSError *error))onError;

@end
