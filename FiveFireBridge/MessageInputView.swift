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
    let SendButton = UIBarButtonItem(title: "Send", style: .Plain, target: nil, action: "SendButtonDidTap")
    func initView(){
        self.items = [UIBarButtonItem]()
        TextField.frame.size.width = UIScreen.mainScreen().bounds.width - 70
        TextField.frame.size.height = 40
        TextField.borderStyle = .Line
        TextField.backgroundColor = UIColor.whiteColor()
        TextField.frame.origin.x = 0
        TextField.placeholder = "메세지를 입력해주세요."
        let paddingView = UIView(frame: CGRectMake(0, 0, 15, self.TextField.frame.height))
        TextField.leftView = paddingView
        TextField.leftViewMode = UITextFieldViewMode.Always
        TextField.borderStyle = .RoundedRect
        TextField.targetForAction("TextFieldDidSet", withSender: nil)
        var negativeSeparator: UIBarButtonItem = UIBarButtonItem(barButtonSystemItem: .FixedSpace, target: nil, action: nil)
        negativeSeparator.width = -12
        let tempBarButtonItem = UIBarButtonItem(customView: TextField)
        self.items?.append(negativeSeparator)
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
        TextField.text = ""
        Jiver.typeEnd()
    }
}