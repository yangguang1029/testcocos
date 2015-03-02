#include "HelloWorldScene.h"
#include <iostream>
#include <vector>
#include "blurSprite.h"

using namespace std;

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    mWinSize = Director::getInstance()->getWinSize();
 
    
//    s = Sprite::create("hall_bg.jpg");
//    s->setPosition(Point(mWinSize.width / 2, mWinSize.height / 2));
    
//    auto fileUtils = FileUtils::getInstance();
//    std::string frag = fileUtils->getStringFromFile(FileUtils::getInstance()->fullPathForFilename("gray.fsh"));
//    
//    auto size = s->getContentSize();
//
//    GLProgram* p = GLProgram::createWithByteArrays(ccPositionTextureColor_noMVP_vert, frag.c_str());
//    GLProgramState* ps = GLProgramState::create(p);
//    
//    s->setGLProgramState(ps);
    
//    this->addChild(s);
    
//    Sprite* s = Sprite::create("fuck.png");
//    s->setPosition(Point(mWinSize.width / 2, mWinSize.height / 2));
//    this->addChild(s);
//    
//    Size ss = s->getContentSize();
//    RenderTexture* render = RenderTexture::create(ss.width * 0.2, ss.height * 0.2, Texture2D::PixelFormat::RGBA8888, 0);
//    render->ignoreAnchorPointForPosition(true);
//    render->setPosition(Point(mWinSize.width / 2, mWinSize.height / 2));
//    render->beginWithClear(0, 0, 0, 0);
//    s->setScale(0.2);
//    s->visit();
//    render->end();
//    
//    s->removeFromParent();
    
//    SpriteBlur* blur = new SpriteBlur();
//    blur->initWithTexture(render->getSprite()->getTexture(), Rect(0, 0,  ss.width * 0.2, ss.height * 0.2));
//    blur->setPosition(Point(mWinSize.width / 2, mWinSize.height / 2));
//    blur->setBlurRadius(7);
//    this->addChild(blur);
    
//    Sprite* news = Sprite::createWithTexture(render->getSprite()->getTexture());
//    news->setPosition(Point(mWinSize.width / 2, mWinSize.height / 2));
//    this->addChild(news);
//
//    MenuItemSprite* item = MenuItemSprite::create(Sprite::create("CloseNormal.png") , Sprite::create("CloseNormal.png"), [&rad, blur](Ref* sender){
////        s->removeFromParent();
//        rad += 1;
//        blur->setBlurRadius(rad);
//    });
//    Menu* menu = Menu::create(item, NULL);
//    menu->setPosition(Point(mWinSize.width * 0.8, mWinSize.height * 0.8));
//    this->addChild(menu, 1);
    
    auto winsize = Director::getInstance()->getWinSize();
    s = Sprite::create("HelloWorld.png");
    s->setPosition(Point(winsize.width / 2, winsize.height / 2));
    this->addChild(s);
    
    mgp = GLProgram::createWithFilenames("gray.vsh", "gray.fsh");
    
    mgs = GLProgramState::create(mgp);
    mgs->setUniformFloat("height", s->getContentSize().height);
    s->setGLProgramState(mgs);
    
//    my = winsize.height / 2 + s->getContentSize().height / 2;
    my = 1;
//    mgs->setUniformCallback("fuck", [this](GLProgram* program, Uniform* uniform) {
//        program->setUniformLocationWith1f(uniform->location, my);
//    });
    
    mu = glGetUniformLocation(mgp->getProgram(), "delta");
    mgp->setUniformLocationWith1f(mu,0);
    this->scheduleUpdate();
    
    return true;
}

void HelloWorld::update(float delta) {
//    my -= 3;
    my -= 0.05;
    if (my == 0) {
        this->unscheduleUpdate();
    }
//    mgs->setUniformFloat("fuck", my);
}

void HelloWorld::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4 &transform, uint32_t flags) {
    
//    mgs->setUniformFloat("fuck", my);
//    mgp->setUniformLocationWith1f(mu, my);
//    s->setGLProgram(mgp);
    Layer::draw(renderer, transform, flags);
}

//void HelloWorld::draw(cocos2d::Renderer *renderer, const cocos2d::Mat4& transform, uint32_t flags) {
//    GLProgramState* gs = s->getGLProgramState();
//    gs->setUniformVec2("offset", Vec2(mu , mv ));
////    CCLOG("offset : %f %f", mu, mv);
//    s->setGLProgramState(gs);
//    s->getGLProgram()->updateUniforms();
//    Layer::draw(renderer, transform, flags);
//}


