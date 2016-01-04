//
//  Jiver.h
//  JiverExample
//
//  Created by JIVER Developers on 2015. 3. 2. in San Francisco, CA.
//  Copyright (c) 2015년 JIVER.CO. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AdSupport/AdSupport.h>
#import "JiverClient.h"
#import "JiverFileInfo.h"
#import "JiverChannelListQuery.h"
#import "JiverAPIClient.h"
#import "JiverBroadcastMessage.h"
#import "JiverMessagingChannel.h"
#import "JiverReadStatus.h"
#import "JiverTypeStatus.h"
#import "JiverMessagingChannelListQuery.h"
#import "JiverMemberListQuery.h"
#import "JiverMessageListQuery.h"
#import "JiverSystemMessage.h"
#import "JiverWSClient.h"
#import "JiverMessagingUnreadCountQuery.h"
#import "JiverMention.h"
#import "JiverStructuredMessage.h"
#import "JiverBlockedUser.h"

#define kJiverInitWithIDFA 0
#define kJiverInitWithIDFV 1

typedef enum {
    JiverDataTypeNone,
//    JiverDataTypeJoin = 0,
//    JiverDataTypeLoadMore = 1,
//    JiverDataTypeLoadNext,
//    JiverDataTypeLoadPrev,
//    JiverDataTypeLoadWithCursor,
    JiverDataTypeMessage,
    JiverDataTypeSystemMessage,
    JiverDataTypeBroadcastMessage,
    JiverDataTypeFileLink,
    JiverDataTypeReadStatus,
    JiverDataTypeStartTyping,
    JiverDataTypeEndTyping,
    JiverDataTypeStructuredMessage,
} JiverDataType;

@class JiverChannelListQuery;
@class JiverClient;
@class JiverMessagingChannelListQuery;
@class JiverMemberListQuery;
@class JiverFileInfo;
@class JiverFileLink;
@class JiverMessagingUnreadCountQuery;

/**
 *  `Jiver` is the main class of [JIVER](http://jiver.io). This class offers connection to JIVER platform, login, setting event callback blocks, message transfers, and others. This class will be defined as a Single Instance in an iOS app. The typical usage order is as the following:
 *
 *  1. Initializing(`initWith...`)
 *  1. Setting User Information(`loginWith...`)
 *  1. Setting Event Callback Blocks(`setEventHandler...`)
 *  1. Setting Channels(`join...`)
 *  1. Connecting(`connectWith...`)
 *  1. Message Transfering(`sendMessage...`)
 */
@interface Jiver : NSObject

/**
 *  Returns current version of JIVER iOS Framework
 *
 *  @return Current JIVER iOS Framework version
 */
+ (NSString *) VERSION;

+ (BOOL) JIVER_LOG_DEBUG;

+ (NSString *) WS_HOST;

+ (NSString *) API_HOST;

/**
 *  Instance of [`Jiver`](./Jiver.html) class
 *
 *  @return Instance of JIVER class.
 */
+ (Jiver *) sharedInstance;

/**
 *  Returns `JiverBlockedUser` instance which is used for managing the list of blocked users. `JiverBlockedUser` instance updates automatically when connected to JIVER server.
 *
 *  @return `JiverBlockedUser` instance.
 */
+ (JiverBlockedUser *) jiverBlockedUser;

/**
 *  Set a new `JiverBlockedUser`. `JiverBlockedUser` instance updates automatically, so modifying using this method may cause problems. Do not call this method directly.
 *
 *  @param newJiverBlockedUser New `JiverBlockedUser` instance
 */
+ (void) setJiverBlockedUser:(JiverBlockedUser *)newJiverBlockedUser;

/**
 *  JIVER Application ID set using initialization method([`initAppId:`](#//api/name/initAppId:), [`igawInitUserId:andAppId:`](#//api/name/igawInitUserId:andAppId:), [`igawInitAppId:`](#//api/name/igawInitAppId:))
 */
@property (retain) NSString *appId;

/**
 *  Displays connection status with the messaging server
 */
@property BOOL connected;

@property BOOL mLoginRequired;

@property (retain) NSOperationQueue *taskQueue;

@property (retain) NSOperationQueue *imageTaskQueue;

- (id) initWithAppId:(NSString *)appId;

+ (void) initWithAppKey:(NSString *)appKey;

+ (void) initByIDFVWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initByIDFAWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId withBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) initUserId:(NSString *)userId andAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

/**
 *  Initialize JIVER instance using Application ID
 *
 *  @param appId Application ID. Application ID. The value for your app is found on [JIVER Dashboard](https://dashboard.jiver.co/)
 */
+ (void) initAppId:(NSString *)appId;

+ (void) initAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

/**
 *  Initialize JIVER instance using Application ID and device ID
 *
 *  @param appId    Application ID. Application ID. The value for your app is found on [JIVER Dashboard](https://dashboard.jiver.co/)
 *  @param deviceId Device ID. See [IDFA](https://developer.apple.com/library/prerelease/ios/documentation/AdSupport/Reference/ASIdentifierManager_Ref/#//apple_ref/occ/instp/ASIdentifierManager/advertisingIdentifier) or [IDFV](https://developer.apple.com/library/prerelease/ios/documentation/UIKit/Reference/UIDevice_Class/#//apple_ref/occ/instp/UIDevice/identifierForVendor)
 */
+ (void) initAppId:(NSString *)appId withDeviceId:(NSString *)deviceId ;

+ (void) igawInitByIDFVWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFAWithBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId withBundle:(NSBundle *)bundle andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFVWithAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitByIDFAWithAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId andAppId:(NSString *)appId DEPRECATED_ATTRIBUTE;

+ (void) igawInitUserId:(NSString *)userId andAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

/**
 *  Initialize JIVER instance using Application ID (IGAWorks only)
 *
 *  @param appId Application ID. The value for your app is found on [IGAWorks' JIVER Dashboard](http://www.igaworks.com/)
 */
+ (void) igawInitAppId:(NSString *)appId;

+ (void) igawInitAppId:(NSString *)appId selectDeviceId:(int)deviceIdType DEPRECATED_ATTRIBUTE;

/**
 *  Initialize JIVER instance using Application ID and device ID (IGAWorks only)
 *
 *  @param appId Application ID. The value for your app is found on [IGAWorks' JIVER Dashboard](http://www.igaworks.com/)
 *  @param deviceId Device ID. See [IDFA](https://developer.apple.com/library/prerelease/ios/documentation/AdSupport/Reference/ASIdentifierManager_Ref/#//apple_ref/occ/instp/ASIdentifierManager/advertisingIdentifier) or [IDFV](https://developer.apple.com/library/prerelease/ios/documentation/UIKit/Reference/UIDevice_Class/#//apple_ref/occ/instp/UIDevice/identifierForVendor)
 */
+ (void) igawInitAppId:(NSString *)appId withDeviceId:(NSString *)deviceId;

/**
 *  Set a user name used for identification during chat. User name will be displayed during messaging. IDFV value will be assigned to [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @param userName User name
 */
+ (void) loginWithUserName:(NSString *)userName;

/**
 *  Set a user name and a profile image used for identification during chat. User name will be displayed during messaging. IDFV value will be assigned to [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @param userName User name
 *  @param imageUrl Profile image URL
 */
+ (void) loginWithUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl;

/**
 *  (IGAWorks only) Set a User ID used for login. User ID is a unique value assigned to identify a user. IDFV value will be assigned to [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @param userId User ID
 */
+ (void) igawLoginWithUserId:(NSString *)userId;

/**
 *  (IGAWorks only) Set a user name used for identification during chat. User name will be displayed during messaging. IDFV value will be assigned to [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @param userName User name
 */
+ (void) igawLoginWithUserName:(NSString *)userName;

/**
 *  (IGAWorks only) Set a user name and a profile image used for identification during chat. User name will be displayed during messaging. IDFV value will be assigned to [`guestId`](./JiverUser.html#//api/name/guestId)
 *
 *  @param userName User name
 *  @param imageUrl Profile image URL
 */
+ (void) igawLoginWithUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl;

/**
 *  (IGAWorks only) Set User ID and access token for login. A correct access token needs to be used in order to connect to the chat servers.
 *
 *  @param userId      User ID
 *  @param accessToken Access token
 */
+ (void) igawLoginWithUserId:(NSString *)userId andAccessToken:(NSString *)accessToken;

/**
 *  (IGAWorks only) Set User ID, user name, profile image, and access token for login. A correct access token needs to be used in order to connect to the chat servers.
 *
 *  @param userId      User ID
 *  @param userName    User name
 *  @param imageUrl    Profile image URL
 *  @param accessToken Access token
 */
+ (void) igawLoginWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken;

/**
 *  Set User ID and User name for login
 *
 *  @param userId   User ID
 *  @param userName User name
 */
+ (void) loginWithUserId:(NSString *)userId andUserName:(NSString *)userName;

/**
 *  Set User ID, user name, profile image, and access token for login. A correct access token needs to be used in order to connect to the chat servers.
 *
 *  @param userId      User ID
 *  @param userName    User name
 *  @param imageUrl    Profile image URL
 *  @param accessToken Access token
 */
+ (void) loginWithUserId:(NSString *)userId andUserName:(NSString *)userName andUserImageUrl:(NSString *)imageUrl andAccessToken:(NSString *)accessToken;

/**
 *  Join a channel. You can make user join an Open Chat anytime, but you need to add a user to Members in case of Messaging Channels or Group Messaging Channels.
 *
 *  @param channelUrl Channel URL
 */
+ (void) joinChannel:(NSString *)channelUrl;

/**
 *  Leave a channel
 *
 *  @param channelUrl Channel URL
 */
+ (void) leaveChannel:(NSString *)channelUrl;

/**
 *  Get current channel URL
 *
 *  @return Channel URL
 */
+ (NSString *) getChannelUrl;

/**
 *  Get the [`guestId`](./JiverUser.html#//api/name/guestId) of the current user
 *
 *  @return User ID
 */
+ (NSString *) getUserId;

/**
 *  Get the user name of the current user
 *
 *  @return User name
 */
+ (NSString *) getUserName;

/**
 *  Set callback blocks for events.
 *
 *  @param connect                  Calls when connection is made to the chat server. Occurs when [`connect`](./Jiver.html#//api/name/connect) or [`connectWithMessageTs:`](./Jiver.html#//api/name/connectWithMessageTs:) is used
 *  @param error                    Calls when an error occurs
 *  @param channelLeft              Calls when the user leaves a channel. Occurs after [`leaveChannel:`](./Jiver.html#//api/name/leaveChannel:) has been called.
 *  @param messageReceived          Calls when new message is received. Occurs when a user sends a message using [`sendMessage:`](./Jiver.html#//api/name/sendMessage:), [`sendMessage:withTempId:`](./Jiver.html#//api/name/sendMessage:withTempId:), [`sendMessage:withData:`](./Jiver.html#//api/name/sendMessage:withData:),  [`sendMessage:withData:andTempId:`](./Jiver.html#//api/name/sendMessage:withData:andTempId:), [`sendMessage:withData:andTempId:mentionedUserIds:`](./Jiver.html#//api/name/sendMessage:withData:andTempId:mentionedUserIds:)
 *  @param systemMessageReceived    Calls when system message is received
 *  @param broadcastMessageReceived Calls when broadcasted message is received
 *  @param fileReceived             Calls when file is received. Occurs when a user sends a message using [`sendFile:`](./Jiver.html#//api/name/sendFile:)
 *  @param messagingStarted         Calls when a new conversation begins. Occurs when [`inviteMessagingWithChannelUrl:andUserId:`](./Jiver.html#//api/name/inviteMessagingWithChannelUrl:andUserId:) , [`inviteMessagingWithChannelUrl:andUserIds:`](./Jiver.html#//api/name/inviteMessagingWithChannelUrl:andUserIds:) , [`startMessagingWithUserId:`](./Jiver.html#//api/name/startMessagingWithUserId:) , [`startMessagingWithUserIds:`](./Jiver.html#//api/name/startMessagingWithUserIds:) , [`joinMessagingWithChannelUrl:`](./Jiver.html#//api/name/joinMessagingWithChannelUrl:) has been called.
 *  @param messagingUpdated         Calls when a messaging channel has been updated. Occurs when [`inviteMessagingWithChannelUrl:andUserId:`](./Jiver.html#//api/name/inviteMessagingWithChannelUrl:andUserId:), [`inviteMessagingWithChannelUrl:andUserIds:`](./Jiver.html#//api/name/inviteMessagingWithChannelUrl:andUserIds:) has been called inside Group Messaging Channels.
 *  @param messagingEnded           Calls when messaging has ended. Occurs when [`endMessagingWithChannelUrl:`](./Jiver.html#//api/name/endMessagingWithChannelUrl:) is called
 *  @param allMessagingEnded        Calls when all messaging has ended at once. Occurs when [`endAllMessaging`](./Jiver.html#//api/name/endAllMessaging) is called.
 *  @param messagingHidden          Calls when a messaging channel becomes hidden. Occurs when [`hideMessagingWithChannelUrl:`](./Jiver.html#//api/name/hideMessagingWithChannelUrl:) is called.
 *  @param allMessagingHidden       Calls when all messaging channels becomes hidden at once. Occurs when [`hideAllMessaging`](./Jiver.html#//api/name/hideAllMessaging) is called.
 *  @param readReceived             Calls when Read command is called.
 *  @param typeStartReceived        Calls when typing event starts. Information regarding the user and the timestamp of the event can be found within [`JiverTypeStatus`](./JiverTypeStatus.html) class.
 *  @param typeEndReceived          Calls when typing event ends. Information regarding the user and the timestamp of the event can be found within [`JiverTypeStatus`](./JiverTypeStatus.html) class.
 *  @param allDataReceived          Calls when any data is received.
 *  @param messageDelivery          Calls when the current user successfully sends a message. Use this o find out if the message has been successfully delivered when [`sendMessage:`](./Jiver.html#//api/name/sendMessage:), [`sendMessage:withTempId:`](./Jiver.html#//api/name/sendMessage:withTempId:), [`sendMessage:withData:`](./Jiver.html#//api/name/sendMessage:withData:), [`sendMessage:withData:andTempId:`](./Jiver.html#//api/name/sendMessage:withData:andTempId:), [`sendMessage:withData:andTempId:mentionedUserIds:`](./Jiver.html#//api/name/sendMessage:withData:andTempId:mentionedUserIds:), [`sendFile:`](./Jiver.html#//api/name/sendFile:) were used to send messages.
 */

+ (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *messageId))messageDelivery;

// TODO:
//+ (void) setEventHandlerConnectBlock:(void (^)(JiverChannel *channel))connect errorBlock:(void (^)(NSInteger code))error channelLeftBlock:(void (^)(JiverChannel *channel))channelLeft messageReceivedBlock:(void (^)(JiverMessage *message))messageReceived systemMessageReceivedBlock:(void (^)(JiverSystemMessage *message))systemMessageReceived broadcastMessageReceivedBlock:(void (^)(JiverBroadcastMessage *message))broadcastMessageReceived fileReceivedBlock:(void (^)(JiverFileLink *fileLink))fileReceived structuredMessageReceivedBlock:(void (^)(JiverStructuredMessage *message))structuredMessageReceived messagingStartedBlock:(void (^)(JiverMessagingChannel *channel))messagingStarted messagingUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingUpdated messagingEndedBlock:(void (^)(JiverMessagingChannel *channel))messagingEnded allMessagingEndedBlock:(void (^)())allMessagingEnded messagingHiddenBlock:(void (^)(JiverMessagingChannel *channel))messagingHidden allMessagingHiddenBlock:(void (^)())allMessagingHidden readReceivedBlock:(void (^)(JiverReadStatus *status))readReceived typeStartReceivedBlock:(void (^)(JiverTypeStatus *status))typeStartReceived typeEndReceivedBlock:(void (^)(JiverTypeStatus *status))typeEndReceived allDataReceivedBlock:(void (^)(NSUInteger jiverDataType, int count))allDataReceived messageDeliveryBlock:(void (^)(BOOL send, NSString *message, NSString *data, NSString *messageId))messageDelivery;

/**
 *  Get the instance of the current channel
 *
 *  @return Channel instance
 */
+ (JiverChannel *) getCurrentChannel;

/**
 *  Start Messaging with the person using User ID([`guestId`](./JiverUser.html#//api/name/guestId))
 *
 *  @param userId The other person's User ID to start Messaging with
 */
+ (void) startMessagingWithUserId:(NSString *)userId;

/**
 *  Start Group Messaging with people using the array of User IDs([`guestId`](./JiverUser.html#//api/name/guestId)) (Messaging/Group Messaging only)
 *
 *  @param userIds NSArray of User IDs containing the list of people to start Group Messaging with
 */
+ (void) startMessagingWithUserIds:(NSArray *)userIds;

/**
 *  Join Messaging channel. In order to join a Group Messaging Channel, the user needs to be in the member list of that channel. (Messaging/Group Messaging only)
 *
 *  @param channelUrl Channel URL to join
 */
+ (void) joinMessagingWithChannelUrl:(NSString *)channelUrl;

/**
 *  Invite the list of users with User ID([`guestId`](./JiverUser.html#//api/name/guestId)) to the Messaging channel. (Messaging/Group Messaging only)
 *
 *  @param channelUrl Channel URL of the Messaging channel to invite into
 *  @param userId     User ID of the invitee
 */
+ (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andUserId:(NSString *)userId;

/**
 *  Invite the list of users with User IDs([`guestId`](./JiverUser.html#//api/name/guestId)) to the Messaging channel. (Messaging/Group Messaging only)
 *
 *  @param channelUrl Channel URL of the Messaging channel to invite into
 *  @param userIds    NSArray of User IDs containing the list of people to invite
 */
+ (void) inviteMessagingWithChannelUrl:(NSString *)channelUrl andUserIds:(NSArray *)userIds;

/**
 *  End Messaging (Messaging/Group Messaging only)
 *
 *  @param channelUrl Channel URL to end messaging
 */
+ (void) endMessagingWithChannelUrl:(NSString *)channelUrl;

/**
 *  End all Messaging by the user (Messaging/Group Messaging only)
 */
+ (void) endAllMessaging;

/**
 *  Hide the target Messaging channel from the Messaging channel list. (Messaging/Group Messaging only)
 *
 *  @param channelUrl Channel URL of the Messaging channel to hide
 */
+ (void) hideMessagingWithChannelUrl:(NSString *)channelUrl;

/**
 *  Hide all of user's Messaging channels from the list (Messaging/Group Messaging only)
 */
+ (void) hideAllMessaging;

/**
 *  Notify that the typing started (Messaging/Group Messaging only)
 */
+ (void) typeStart;

/**
 *  Notify that the typing ended (Messaging/Group Messaging only)
 */
+ (void) typeEnd;

/**
 *  Mark all messages read within the current channel. This will set the Unread message count to 0 for the current channel. (Messaging/Group Messaging only)
 */
+ (void) markAsRead;

/**
 *  Mark all messages read within the targeted channel. This will set the Unread message count to 0 for the targeted channel. (Messaging/Group Messaging only)
 *
 *  @param channelUrl Target Messaging Channel URL
 */
+ (void) markAsReadForChannel:(NSString *)channelUrl;

/**
 *  Mark all messages read within all of the joined channels. This will set the Unread message count to 0 for all of the joined channels. (Messaging/Group Messaging only)
 */
+ (void) markAllAsRead;

/**
 *  Connect to the chat server. Upon connection, some of the previous messages will be retrieved. connect callback will be invoked once connected.
 */
+ (void) connect;

/**
 *  Connect to the chat server. Upon connection, some of the messages prior to the given timestamp will be retrieved. connect callback will be invoked once connected.
 *
 *  @param messageTs UTC timestamp
 */
+ (void) connectWithMessageTs:(long long)messageTs;

/**
 *  Cancel all running asynchronous jobs
 */
+ (void) cancelAll;

/**
 *  Disconnect from chat server
 */
+ (void) disconnect;

/**
 *  Register callback for Messaging channel/Group messaging channel update and user mentions
 *
 *  @param messagingChannelUpdated Calls upon Messaging channel updates
 *  @param mentionUpdated          Calls upon user mentions
 */
+ (void) registerNotificationHandlerMessagingChannelUpdatedBlock:(void (^)(JiverMessagingChannel *channel))messagingChannelUpdated mentionUpdatedBlock:(void (^)(JiverMention *mention))mentionUpdated;

/**
 *  Unregister callback for Messaging channel/Group messaging channel update and user mentions
 */
+ (void) unregisterNotificationHandlerMessagingChannelUpdatedBlock;

/**
 *  Send a message
 *
 *  @param message Message body
 */
+ (void) sendMessage:(NSString *)message;

/**
 *  Send a temporary message with an ID. Temporary message ID is used to identify the message. Temporary ID can be used with [`messageDelivery`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) to verify successfull message delivery
 *
 *  @param message Message body
 *  @param tempId  Temporary ID used for message identification
 */
+ (void) sendMessage:(NSString *)message withTempId:(NSString *)tempId;

/**
 *  Send a message with data
 *
 *  @param message Message body
 *  @param data    Data to send
 */
+ (void) sendMessage:(NSString *)message withData:(NSString *)data;

/**
 *  Send a temporary message and data with an ID. Temporary message ID is used to identify the message. Temporary ID can be used with [`messageDelivery`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) to verify successfull message delivery
 *
 *  @param message Message body
 *  @param data    Data to send
 *  @param tempId  Temporary ID used for message identification
 */
+ (void) sendMessage:(NSString *)message withData:(NSString *)data andTempId:(NSString *)tempId;

/**
 *  Send a message, data, and the list of User IDs to send mentions with a temporary ID. Temporary message ID is used to identify the message. Temporary ID can be used with [`messageDelivery`](./Jiver.html#//api/name/setEventHandlerConnectBlock:errorBlock:channelLeftBlock:messageReceivedBlock:systemMessageReceivedBlock:broadcastMessageReceivedBlock:fileReceivedBlock:messagingStartedBlock:messagingUpdatedBlock:messagingEndedBlock:allMessagingEndedBlock:messagingHiddenBlock:allMessagingHiddenBlock:readReceivedBlock:typeStartReceivedBlock:typeEndReceivedBlock:allDataReceivedBlock:messageDeliveryBlock:) to verify successfull message delivery. Users within the list of User IDs will invoke [`mentionUpdated`](./Jiver.html#//api/name/registerNotificationHandlerMessagingChannelUpdatedBlock:mentionUpdatedBlock:) callbacks.
 *
 *  @param message          Message body
 *  @param data             Data to send
 *  @param tempId           Temporary ID used for message identification
 *  @param mentionedUserIds NSArray of the User IDs to send mentions to
 */
+ (void) sendMessage:(NSString *)message withData:(NSString *)data andTempId:(NSString *)tempId mentionedUserIds:(NSArray *)mentionedUserIds;

/**
 *  Send a file
 *
 *  @param fileInfo File information
 */
+ (void) sendFile:(JiverFileInfo *)fileInfo;

/**
 *  Upload a file
 *
 *  @param file        File data using NSData class
 *  @param type        File type
 *
 *  - `video`
 *  - `image`
 *  - `etc`
 *  @param size        File size
 *  @param customField Custom data
 *  @param onUpload    Callback block invoked upon completition of the upload
 */
+ (void) uploadFile:(NSData *)file type:(NSString *)type hasSizeOfFile:(unsigned long)size withCustomField:(NSString *)customField uploadBlock:(void (^)(JiverFileInfo *fileInfo, NSError *error))onUpload;

/**
 *  Create an instance of [`JiverMessagingChannelListQuery`](./JiverMessagingChannelListQuery.html) to get the list of Messaging/Group Messaging channels
 *
 *  @return [`JiverMessagingChannelListQuery`](./JiverMessagingChannelListQuery.html) instance.
 */
+ (JiverMessagingChannelListQuery *) queryMessagingChannelList;

/**
 *  Create an instance of [`JiverChannelListQuery`](./JiverChannelListQuery.html) to get the list of Open Chat Channels
 *
 *  @return [`JiverChannelListQuery`](./JiverChannelListQuery.html) instance
 */
+ (JiverChannelListQuery *) queryChannelList;

/**
 *  Create an instance of [`JiverChannelListQuery`](./JiverChannelListQuery.html) to get the list of Open Chat Channels based on the searched keyword
 *
 *  @param keyword Keyword used to search the channels
 *
 *  @return Searched [`JiverChannelListQuery`](./JiverChannelListQuery.html) instance
 */
+ (JiverChannelListQuery *) queryChannelListWithKeyword:(NSString *)keyword;

/**
 *  Create the instance of [`JiverChannelListQuery`](./JiverChannelListQuery.html) for Unity
 *
 *  @return [`JiverChannelListQuery`](./JiverChannelListQuery.html) instance
 */
+ (JiverChannelListQuery *) queryChannelListForUnity;

/**
 *  Create the instance of [`JiverMemberListQuery`](./JiverMemberListQuery.html) to get the list of members within the target channel
 *
 *  @param channelUrl Channel URL
 *
 *  @return [`JiverMemberListQuery`](./JiverMemberListQuery.html) instance.
 */
+ (JiverMemberListQuery *) queryMemberListInChannel:(NSString *)channelUrl;

/**
 *  Create the instance of [`JiverMessageListQuery`](./JiverMessageListQuery.html)  to retrieve the messages within the target channel 
 *
 *  @param channelUrl Channel URL.
 *
 *  @return [`JiverMessageListQuery`](./JiverMessageListQuery.html) instance.
 */
+ (JiverMessageListQuery *) queryMessageListInChannel:(NSString *)channelUrl;

/**
 *  Create the instance of [`JiverMessagingUnreadCountQuery`](./JiverMessagingUnreadCountQuery.html) to get the unread message count for the target user
 *
 *  @return [`JiverMessagingUnreadCountQuery`](./JiverMessagingUnreadCountQuery.html) instance.
 */
+ (JiverMessagingUnreadCountQuery *) queryMessagingUnreadCount;

+ (void) messageReceived:(JiverMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) fileReceived:(JiverFileLink *)fileLink DEPRECATED_ATTRIBUTE;

+ (void) broadcastMessageReceived:(JiverBroadcastMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) systemMessageReceived:(JiverSystemMessage *)msg DEPRECATED_ATTRIBUTE;

+ (void) messagingStarted:(JiverMessagingChannel *)channel DEPRECATED_ATTRIBUTE;

+ (void) messagingEnded:(JiverMessagingChannel *)channel DEPRECATED_ATTRIBUTE;

/**
 *  Get IDFV for the Device
 *
 *  @return Device IDFV
 */
+ (NSString *) deviceUniqueID;

/**
 *  Get the chat server connection status
 *
 *  @return WSReadyState
 *
 *  - `WS_CONNECTING` - Connecting to the chat server
 *  - `WS_OPEN` - Connected to the chat server
 *  - `WS_CLOSING` - Disconnecting from the chat server
 *  - `WS_CLOSED` - Disconnected from the chat server
 */
+ (enum WSReadyState) connectState;

/**
 *  For UnitTest
 */
+ (void) testUserBlockListResultBlock:(void (^)(NSDictionary *response, NSError *error))onResult;

@end
