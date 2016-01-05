//
//  SectionLabel.swift
//  FiveFireBridge
//
//  Created by Sunrin on 2016. 1. 5..
//  Copyright © 2016년 astoration. All rights reserved.
//

import Foundation
import UIKit

class SectionLabel : UILabel{
    override func drawTextInRect(rect: CGRect) {
        let insets: UIEdgeInsets = UIEdgeInsets(top: 0.0, left: 10.0, bottom: 0.0, right: 10.0)
        super.drawTextInRect(UIEdgeInsetsInsetRect(rect, insets))
        
    }
}