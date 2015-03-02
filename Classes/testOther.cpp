//
//  testOther.cpp
//  testcocoscpp
//
//  Created by guangy on 2/27/15.
//
//

#include "testOther.h"

Scene* TestOther::createScene() {
    Scene* scene = Scene::create();
    TestOther* layer = new TestOther();
    if (layer->init()) {
        layer->autorelease();
        scene->addChild(layer);
    }
    return scene;
}

bool TestOther::init() {
    if (Layer::init() == false) {
        return false;
    }
    Size winsize = Director::getInstance()->getWinSize();

    
    Sprite* s2 = Sprite::create("fuck.png");
    Size size = s2->getContentSize();
    s2->setPosition(Point(winsize.width/2, winsize.height / 2));
    
    std::string fs = FileUtils::getInstance()->getStringFromFile("colorline.fsh");
    std::string vs = FileUtils::getInstance()->getStringFromFile("colorline.vsh");
    GLProgram* gp = GLProgram::createWithByteArrays(vs.c_str(), fs.c_str());
    GLProgramState* gs = GLProgramState::create(gp);
    gs->setUniformFloat("width", size.width);
    s2->setGLProgramState(gs);
    this->addChild(s2);
    
    return true;
}