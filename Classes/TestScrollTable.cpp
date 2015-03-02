//
//  TestScrollTable.cpp
//  testcocoscpp
//
//  Created by guangy on 1/19/15.
//
//

#include "TestScrollTable.h"

using namespace cocos2d;
using namespace cocos2d::extension;

ScrollTableLayer::ScrollTableLayer() {
    Size winsize = Director::getInstance()->getWinSize();
    
    Size csize = Size(winsize.width * 2, winsize.height);
    
    Layer* container = Layer::create();
    container->setContentSize(csize);
    
    mScroll = ScrollView::create(winsize, container);
    mScroll->setDelegate(this);
    mScroll->setDirection(ScrollView::Direction::HORIZONTAL);
    
    Size tsize = Size(winsize.width * 0.6, winsize.height);
    mCellSize = Size (winsize.width * 0.6, 100);
    
    mTable1 = new TableView();
    mTable1->initWithViewSize(tsize, nullptr);
    mTable1->setDataSource(this);
    mTable1->autorelease();
    
    mTable2 = new TableView();
    mTable2->initWithViewSize(tsize, nullptr);
    mTable2->setDataSource(this);
    mTable2->autorelease();
    
    mTable3 = new TableView();
    mTable3->initWithViewSize(tsize, nullptr);
    mTable3->setDataSource(this);
    mTable3->autorelease();
    
    mTable1->setTag(1);
    mTable2->setTag(2);
    mTable3->setTag(3);
    
    mTable2->setPosition(Point(winsize.width * 0.66, 0));
    mTable3->setPosition(Point(winsize.width * 1.32, 0));
    
    container->addChild(mTable1);
    container->addChild(mTable2);
    container->addChild(mTable3);
    
    mTable1->reloadData();
    mTable2->reloadData();
    mTable3->reloadData();
    
    mTable1->setColor(Color3B::RED);
    mTable2->setColor(Color3B::BLUE);
    mTable3->setColor(Color3B::GREEN);
    
    this->addChild(mScroll);
    
}

ScrollTableLayer::~ScrollTableLayer() {

}

TableViewCell* ScrollTableLayer::tableCellAtIndex(cocos2d::extension::TableView *table, ssize_t idx) {
    TableViewCell* cell = table->dequeueCell();
    int tag = table->getTag();
    Color4B color = tag > 1 ? tag == 2 ? Color4B::RED : Color4B::GREEN : Color4B::BLUE;
    Label* label;
    if (cell == nullptr) {
        cell = new TableViewCell();
        LayerColor* lc = LayerColor::create(color, mCellSize.width, mCellSize.height);
        cell->addChild(lc);
        
        label = Label::create();
        label->setPosition(Point(mCellSize.width / 2, mCellSize.height / 2));
        label->setTag(99);
        cell->addChild(label);
    } else {
        label = (Label*)cell->getChildByTag(99);
    }
    label->setString(std::to_string(tag) + "_" + std::to_string(idx));
    return cell;
}

Size ScrollTableLayer::tableCellSizeForIndex(cocos2d::extension::TableView *table, ssize_t idx) {
    return mCellSize;
}

ssize_t ScrollTableLayer::numberOfCellsInTableView(cocos2d::extension::TableView *table) {
    return 10;
}

void ScrollTableLayer::tableCellTouched(TableView* table, TableViewCell* cell) {

}

void ScrollTableLayer::scrollViewDidScroll(ScrollView* view) {
    Vec2 offset = view->getContentOffset();
}