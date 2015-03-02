//
//  testOther.h
//  testcocoscpp
//
//  Created by guangy on 2/27/15.
//
//

#ifndef __testcocoscpp__testOther__
#define __testcocoscpp__testOther__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class TestOther : public Layer {
    
public:
    static Scene* createScene();
    
private:
    bool init();
};

#endif /* defined(__testcocoscpp__testOther__) */
