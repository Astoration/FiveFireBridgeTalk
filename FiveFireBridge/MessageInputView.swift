//
//  MessageInputView.swift
//  FiveFireBridge
//
//  Created by Sunrin on 2016. 1. 4..
//  Copyright © 2016년 astoration. All rights reserved.
//
import JiverSDK
import Foundation
import UIKit
class MessageInputView: UIToolbar {
    let TextField = UITextField()
    let SendButton = UIBarButtonItem()
    func initView(){
        self.items = [UIBarButtonItem]()
        TextField.frame.size.width = UIScreen.mainScreen().bounds.width*0.7
        TextField.frame.size.height = 45
        TextField.borderStyle = .Line
        TextField.backgroundColor = UIColor.whiteColor()
        TextField.placeholder = "메세지를 입력해주세요."
        let tempBarButtonItem = UIBarButtonItem(customView: TextField)
        self.items?.append(tempBarButtonItem)
        self.items?.append(SendButton)
    }
    
    func TextFieldDidChanged(){
        if TextField.text?.isEmpty == false{
            Jiver.typeStart()
        }
    }
    func SendButtonDidTap(){
        if TextField.text?.isEmpty == true{
            return
        }
        Jiver.sendMessage(TextField.text, withTempId: UIDevice.currentDevice().identifierForVendor!.UUIDString)
        Jiver.typeEnd()
    }
}