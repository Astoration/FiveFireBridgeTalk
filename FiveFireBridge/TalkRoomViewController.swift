//
//  TalkRoomViewController.swift
//  FiveFireBridge
//
//  Created by Sunrin on 2016. 1. 4..
//  Copyright © 2016년 astoration. All rights reserved.
//

import Foundation
import UIKit
import JiverSDK

class TalkRoomViewController : UIViewController{
    let TableView = UITableView()
    let ToolBar = MessageInputView()
    var SelfMember : JiverMember?
    var TargetMember : JiverMember?
    
    override init(nibName nibNameOrNil: String?, bundle nibBundleOrNil: NSBundle?) {
        super.init(nibName: nibNameOrNil, bundle: nibBundleOrNil)
    }
    func TalkRoomInit(_SelfMember: JiverMember, _TargetMember: JiverMember){
        self.TargetMember = _TargetMember
        self.SelfMember = _SelfMember
    }

    required init?(coder aDecoder: NSCoder) {
        fatalError("init(coder:) has not been implemented")
    }
    
    deinit {
        NSNotificationCenter.defaultCenter().removeObserver(self)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        ToolBar.initView()
        self.ToolBar.frame.size.width = self.view.bounds.width
        self.ToolBar.frame.size.height = 50
        self.ToolBar.frame.origin.y = self.view.bounds.height-50
        self.view.addSubview(TableView)
        self.view.addSubview(ToolBar)
        self.TableView.frame.size.width = self.view.bounds.width
        self.TableView.frame.size.height = self.view.bounds.height-50
        startJiver()
        self.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .Stop, target: self, action: "cancleButtonDidTap")
        self.title = TargetMember!.name
        
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "keyboardWillShow:", name: UIKeyboardWillShowNotification, object: nil)
    }
    func cancleButtonDidTap() {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    func startJiver(){
        let APP_ID = "2B979C6D-C9BF-47AE-8FCF-62AE455D387D"
        let USER_ID = UIDevice.currentDevice().identifierForVendor!.UUIDString
        let USER_NAME = Jiver.deviceUniqueID()
        let CHANNEL_URL = "41ad5.Lobby"
        
        Jiver.initAppId(APP_ID)
        Jiver.loginWithUserId(USER_ID, andUserName: USER_NAME)
        Jiver.joinChannel(CHANNEL_URL)
        Jiver.connect()
        Jiver.setEventHandlerConnectBlock(
            { channel in
                print("connection Succsess!")
            }
            , errorBlock: { _ in }
            , channelLeftBlock: { _ in }
            , messageReceivedBlock: { message in
                print("Message received: \(message.message)")
            }
            , systemMessageReceivedBlock: { _ in }
            , broadcastMessageReceivedBlock: { _ in }
            , fileReceivedBlock: { _ in }
            , messagingStartedBlock: { _ in
                print("Messaging Started")
                Jiver.typeStart()
                Jiver.sendMessage("Hello")
                Jiver.typeEnd()
            }
            , messagingUpdatedBlock: { _ in }
            , messagingEndedBlock: { _ in }
            , allMessagingEndedBlock: { _ in }
            , messagingHiddenBlock: { _ in }
            , allMessagingHiddenBlock: { _ in }
            , readReceivedBlock: { _ in }
            , typeStartReceivedBlock: { _ in }
            , typeEndReceivedBlock: { _ in }
            , allDataReceivedBlock: { _ in }
            , messageDeliveryBlock: { _ in }
        )
    }
    
    func keyboardWillShow(notification: NSNotification) {
        let keyboardRect = notification.userInfo![UIKeyboardFrameEndUserInfoKey]!.CGRectValue
        self.ToolBar.frame.origin.y = self.view.frame.height - keyboardRect.height - self.ToolBar.frame.size.height
    }

}