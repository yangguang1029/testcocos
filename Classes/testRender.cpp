//
//  testRender.cpp
//  testcocoscpp
//
//  Created by guangy on 1/22/15.
//
//

#include "testRender.h"

TestRender::TestRender() {
    Label* l = Label::create();
    l->setPosition(Point(400, 300));
    l->setString("fuck");
    this->addChild(l);
    
}