//
//  TestScrollTable.h
//  testcocoscpp
//
//  Created by guangy on 1/19/15.
//
//

#ifndef __testcocoscpp__TestScrollTable__
#define __testcocoscpp__TestScrollTable__

#include <stdio.h>
#include "cocos2d.h"
#include "GUI/CCScrollView/CCScrollView.h"
#include "GUI/CCScrollView/CCTableView.h"

using namespace cocos2d;
using namespace cocos2d::extension;

class ScrollTableLayer : public cocos2d::Layer, public cocos2d::extension::TableViewDataSource , public cocos2d::extension::TableViewDelegate {
private:
    cocos2d::extension::ScrollView* mScroll;
    cocos2d::extension::TableView *mTable1, *mTable2, *mTable3;
    
    Size mCellSize;
    
public:
    ScrollTableLayer();
    virtual ~ScrollTableLayer();
    
    virtual cocos2d::Size tableCellSizeForIndex(TableView *table, ssize_t idx);
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(TableView *table);
    
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    
    virtual void scrollViewDidScroll(ScrollView* view);
};

#endif /* defined(__testcocoscpp__TestScrollTable__) */
