//
//  ViewController.swift
//  FiveFireBridge
//
//  Created by Sunrin on 2016. 1. 4..
//  Copyright © 2016년 astoration. All rights reserved.
//

import UIKit
import JiverSDK

class ViewController: UIViewController {
    
    let TableView = UITableView()
    var Members = [JiverMember]()
    var SelfMember : JiverMember?

    override func viewDidLoad() {
        super.viewDidLoad()
        self.TableView.dataSource=self
        self.TableView.delegate=self
        self.TableView.registerClass(UITableViewCell.self, forCellReuseIdentifier: "cell")
        self.view.addSubview(TableView)
        
        self.TableView.frame.size.width = self.view.bounds.width
        self.TableView.frame.size.height = self.view.bounds.height

        self.startJiver()
        self.title = "YubiniTalk"
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    func startJiver(){
        let APP_ID = "2B979C6D-C9BF-47AE-8FCF-62AE455D387D"
        let USER_ID = UIDevice.currentDevice().identifierForVendor!.UUIDString
        let USER_NAME = Jiver.deviceUniqueID()
        let CHANNEL_URL = "41ad5.Lobby"
        
        Jiver.initAppId(APP_ID)
        Jiver.loginWithUserId(USER_ID, andUserName: USER_NAME)
        Jiver.joinChannel(CHANNEL_URL)
        
        Jiver.queryMemberListInChannel(CHANNEL_URL).nextWithResultBlock(
            { members in
                self.Members = members.flatMap { $0 as? JiverMember }
                for member in members {
                    print("member: \(member.name)")
                    if member.name == USER_NAME {
                        self.SelfMember = member as? JiverMember
                    }
                }
                self.TableView.reloadData()
            },
            endBlock: { error in
                print(error)
            }
        )
        
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
}

extension ViewController : UITableViewDataSource {
    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return self.Members.count
    }
    func tableView(tableView: UITableView, cellForRowAtIndexPath indexPath: NSIndexPath) -> UITableViewCell {
        let cell = tableView.dequeueReusableCellWithIdentifier("cell")!
        cell.textLabel?.text = String(self.Members[indexPath.row].name)
        return cell
    }
}

extension ViewController : UITableViewDelegate {
    func tableView(tableView: UITableView, didSelectRowAtIndexPath indexPath: NSIndexPath) {
        let TalkRoom = TalkRoomViewController()
        TalkRoom.TalkRoomInit(
            self.SelfMember!
            , _TargetMember: self.Members[indexPath.row]
        )
        let navigationController = UINavigationController(rootViewController: TalkRoom)
        self.presentViewController(navigationController,animated: true, completion: nil)
    }
}
