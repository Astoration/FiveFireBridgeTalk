//
//  MessagingChannelListQuery.h
//  JiverExample
//
//  Created by Jed Kyung on 2015. 4. 20..
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JiverClient.h"

@class JiverClient;

/**
 *  Class used to retrieve the list of Messaging/Group messaging channels that the current user is in. This class is not used directly, but instead [`Jiver queryMessagingChannelList`](./Jiver.html#//api/name/queryMessagingChannelList) must be used. The class supports Pagination, by assigning [`setLimit:`](./JiverMessagingChannelListQuery.html#//api/name/setLimit:), then calling [`nextWithResultBlock:endBlock:`](./JiverMessagingChannelListQuery.html#//api/name/nextWithResultBlock:endBlock:) repeatedly to get next results. If there is no more page to be shown, [`hasNext`](./JiverMessagingChannelListQuery.html#//api/name/hasNext) value becomes NO.
 */
@interface JiverMessagingChannelListQuery : NSObject

- (id) initWithClient:(JiverClient *)jiverClient;

- (BOOL) isLoading;

/**
 *  Set the number of channels per page (limit)
 *
 *  @param lmt Number of channels per page
 */
- (void) setLimit:(int) lmt;

/**
 *  Stop retrieving the channel list
 */
- (void) cancel;

/**
 *  Check if there is more channels to retrieve
 *
 *  @return Returns YES if there is a next page, otherwise returns NO
 */
- (BOOL) hasNext;

/**
 *  Get the list of Messaging/Group messaging channels the current user is in
 *
 *  @param onResult Callback invoked upon success. queryResult is an array of [`JiverMessagingChannel`](./JiverMessagingChannel.html)
 *  @param onError  Callback invoked upon error
 */
- (void) nextWithResultBlock:(void (^)(NSMutableArray *queryResult))onResult endBlock:(void (^)(NSInteger code))onError;

@end
