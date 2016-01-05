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
    let APP_ID = "2B979C6D-C9BF-47AE-8FCF-62AE455D387D"
    let USER_ID = UIDevice.currentDevice().identifierForVendor!.UUIDString
    let USER_NAME = "Astora"
    let CHANNEL_URL = "41ad5.Lobby"
    let TableView = UITableView()
    let ToolBar = MessageInputView()
    var SelfMember : JiverMember?
    var TargetMember : JiverMember?
    var HeaderName = [String]()
    var RowIndex = [Int]()
    var TalkContent = [[String]]()
    var Messages = [JiverMessage]()
    let JiverMessages = JiverMessagingChannel.init()
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
        self.TableView.registerClass(UITableViewCell.self, forCellReuseIdentifier: "cell")
        self.ToolBar.frame.size.width = self.view.bounds.width
        self.ToolBar.frame.size.height = 50
        self.ToolBar.frame.origin.y = self.view.bounds.height-50
        self.view.addSubview(TableView)
        self.view.addSubview(ToolBar)
        self.TableView.frame.size.width = self.view.bounds.width
        self.TableView.frame.size.height = self.view.bounds.height-50
        startJiver()
        Jiver.queryMessageListInChannel(CHANNEL_URL).prevWithMessageTs(LLONG_MAX, andLimit: 50, resultBlock: {messages in
            self.Messages = messages.flatMap { $0 as? JiverMessage}
            self.Messages = self.Messages.reverse()
            self.numberOfSectionsInTableView(self.TableView)
            self.TableView.dataSource = self
            self.TableView.delegate = self
            self.TableView.reloadData()
        }
        , endBlock: {_ in})
        self.navigationItem.leftBarButtonItem = UIBarButtonItem(barButtonSystemItem: .Stop, target: self, action: "cancleButtonDidTap")
        self.title = TargetMember!.name
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "keyboardWillShow:", name: UIKeyboardWillShowNotification, object: nil)
        NSNotificationCenter.defaultCenter().addObserver(self, selector: "keyboardWillHide:", name: UIKeyboardWillHideNotification, object: nil)
    }
    func cancleButtonDidTap() {
        self.dismissViewControllerAnimated(true, completion: nil)
    }
    func startJiver(){
        
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
    func keyboardWillHide(notification: NSNotification) {
        self.ToolBar.frame.origin.y = self.view.frame.height - 50
    }

}

extension TalkRoomViewController : UITableViewDataSource {
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.RowIndex[section]
    }
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("cell")!
        cell.textLabel?.text = self.TalkContent[indexPath.section][indexPath.row]
        if self.HeaderName[indexPath.section] == self.TargetMember?.name {
            cell.textLabel?.textAlignment = .Left
        } else {
            cell.textLabel?.textAlignment = .Right
        }
        cell.layer.borderWidth = 0
        return cell
    }
    func numberOfSectionsInTableView(tableView: UITableView) -> Int {
        var CountSection = 1
        var CountRow = 1
        var Content = [String]()
        var preSender = self.Messages[0].getSenderName()
        Content.append(self.Messages[0].message)
        self.HeaderName.append(preSender)
        var curSender = self.Messages[1].getSenderName()
        if preSender != curSender {
            self.RowIndex.append(CountRow)
            self.TalkContent.append(Content)
            Content.removeAll()
            Content.append(self.Messages[1].message)
            CountRow=1
            CountSection++
            self.HeaderName.append(curSender)
        }else {
            CountRow++
            Content.append(self.Messages[1].message)
        }
        for index in 2...self.Messages.count-1{
            preSender = self.Messages[index-1].getSenderName()
            curSender = self.Messages[index].getSenderName()
            if preSender != curSender {
                self.RowIndex.append(CountRow)
                self.TalkContent.append(Content)
                Content.removeAll()
                Content.append(self.Messages[index].message)
                CountRow=1
                CountSection++
                self.HeaderName.append(curSender)
            }else {
                CountRow++
                Content.append(self.Messages[index].message)
            }
        }
        self.RowIndex.append(CountRow)
        self.TalkContent.append(Content)
        var lastIndex = self.HeaderName.count
        var i=0
        while i<lastIndex{
            print("HN:\(HeaderName.count)")
            print("i:\(i)")
            print("lt:\(lastIndex)")
            print("tc:\(self.TalkContent.count)")
            print("rid:\(self.RowIndex.count)")
            if !(self.HeaderName[i] == self.TargetMember?.name || self.HeaderName[i] == self.SelfMember?.name){
                self.HeaderName.removeAtIndex(i)
                self.TalkContent.removeAtIndex(i)
                self.RowIndex.removeAtIndex(i)
                i=0
                lastIndex--
                CountSection--
            }else{
                i++
            }
        }
        return CountSection
    }
    func tableView(tableView: UITableView, titleForHeaderInSection section: Int) -> String? {
        return self.HeaderName[section]
    }
}

extension TalkRoomViewController : UITableViewDelegate{
    func tableView(tableView: UITableView, viewForHeaderInSection section: Int) -> UIView? {
        let view = SectionLabel()
        view.text = "  " + self.HeaderName[section]
        view.font = UIFont.boldSystemFontOfSize(17)
        view.backgroundColor = UIColor.whiteColor()
        if self.HeaderName[section] == self.SelfMember?.name{
            view.textAlignment = .Right
            view.text = self.HeaderName[section]
            view.sizeToFit()
            view.textColor = UIColor.blueColor()
        }
        
        return view
    }
}