//
//  ChattingTableViewController.swift
//  FiveFireBridge
//
//  Created by Sunrin on 2016. 1. 4..
//  Copyright © 2016년 astoration. All rights reserved.
//
import UIKit

class ChattingTable: UITableViewController{
    let InputView = MessageInputView()
    let TableView = UITableView()
    override func viewDidLoad(){
        super.viewDidLoad()
        self.TableView.frame=self.view.bounds
        self.TableView.dataSource=self
        self.TableView.delegate=self
        self.view.addSubview(TableView)
        self.view.addSubview(InputView)
    }
}
//extension ChattingTableViewController: UITableViewDataSource{
//    func tableView(tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
//        return 100
//    }
//}