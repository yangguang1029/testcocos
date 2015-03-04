//
//  testTransparentHole.cpp
//  testcocoscpp
//
//  Created by guangy on 3/3/15.
//
//

#include "testTransparentHole.h"

HoleNode* HoleNode::create(const cocos2d::Rect &rect) {
    HoleNode* node = new HoleNode();
    if (node->init()) {
        node->setHole(rect);
        node->autorelease();
    }
    return node;
}

bool HoleNode::init() {
    if (Node::init()) {
        for (int i = 0; i < 8; i++) {
            _squareColors[i] = Color4F(0.5, 0.5, 0.5, 0.5);
        }
        _indices[0] = 0;
        _indices[1] = 1;
        _indices[2] = 4;
        _indices[3] = 1;
        _indices[4] = 5;
        _indices[5] = 4;
        _indices[6] = 1;
        _indices[7] = 6;
        _indices[8] = 5;
        _indices[9] = 1;
        _indices[10] = 2;
        _indices[11] = 6;
        _indices[12] = 6;
        _indices[13] = 2;
        _indices[14] = 7;
        _indices[15] = 7;
        _indices[16] = 2;
        _indices[17] = 3;
        _indices[18] = 4;
        _indices[19] = 7;
        _indices[20] = 3;
        _indices[21] = 0;
        _indices[22] = 4;
        _indices[23] = 3;
       
        setGLProgramState(GLProgramState::getOrCreateWithGLProgramName(GLProgram::SHADER_NAME_POSITION_COLOR_NO_MVP));
        return true;
    }
    return false;
}

void HoleNode::setHole(const cocos2d::Rect &rect) {
    Size winsize = Director::getInstance()->getWinSize();
    _squareVertices[0].x = 0;
    _squareVertices[0].y = 0;
    
    _squareVertices[1].x = winsize.width;
    _squareVertices[1].y = 0;
    
    _squareVertices[2].x = winsize.width;
    _squareVertices[2].y = winsize.height;
    
    _squareVertices[3].x = 0;
    _squareVertices[3].y = winsize.height;
    
    _squareVertices[4].x = rect.origin.x;
    _squareVertices[4].y = rect.origin.y;
    
    _squareVertices[5].x = rect.origin.x + rect.size.width;
    _squareVertices[5].y = rect.origin.y;
    
    _squareVertices[7].x = rect.origin.x;
    _squareVertices[7].y = rect.origin.y + rect.size.height;
    
    _squareVertices[6].x = rect.origin.x + rect.size.width;
    _squareVertices[6].y = rect.origin.y + rect.size.height;
}

void HoleNode::draw(Renderer *renderer, const Mat4 &transform, uint32_t flags)
{
    _customCommand.init(_globalZOrder);
    _customCommand.func = CC_CALLBACK_0(HoleNode::onDraw, this, transform, flags);
    renderer->addCommand(&_customCommand);
    
    for(int i = 0; i < 8; ++i)
    {
        Vec4 pos;
        pos.x = _squareVertices[i].x; pos.y = _squareVertices[i].y; pos.z = _positionZ;
        pos.w = 1;
        _modelViewTransform.transformVector(&pos);
        _noMVPVertices[i] = Vec3(pos.x,pos.y,pos.z)/pos.w;
    }
}

void HoleNode::onDraw(const Mat4& transform, uint32_t flags)
{
    getGLProgram()->use();
    getGLProgram()->setUniformsForBuiltins(transform);
    
    GL::enableVertexAttribs( GL::VERTEX_ATTRIB_FLAG_POSITION | GL::VERTEX_ATTRIB_FLAG_COLOR );

    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_POSITION, 3, GL_FLOAT, GL_FALSE, 0, _noMVPVertices);
    glVertexAttribPointer(GLProgram::VERTEX_ATTRIB_COLOR, 4, GL_FLOAT, GL_FALSE, 0, _squareColors);
    
    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_SHORT, _indices);
    
//    CC_INCREMENT_GL_DRAWN_BATCHES_AND_VERTICES(1,8);
}

Scene* TestTransparentHole::createScene() {
    Scene* s = Scene::create();
    TestTransparentHole* layer = new TestTransparentHole();
    if (layer->init()) {
        layer->autorelease();
        s->addChild(layer);
    }
    return s;
}

bool TestTransparentHole::init() {
    if (Layer::init()) {
        
        Size winsize = Director::getInstance()->getWinSize();
        //方法1：用clippingNode实现
//        Sprite* s = Sprite::create("hall_bg.jpg");
//        s->setPosition(Point(winsize.width / 2, winsize.height / 2));
//        this->addChild(s);
//
//        LayerColor* hider = LayerColor::create(Color4B(128, 128, 128, 128), winsize.width, winsize.height);
//        
//        DrawNode* dn = DrawNode::create();
//        
//        Vec2 points[4];
//        points[0] = Vec2(winsize.width * 0.4, winsize.height * 0.4);
//        points[1] = Vec2(winsize.width * 0.6, winsize.height * 0.4);
//        points[2] = Vec2(winsize.width * 0.6, winsize.height * 0.6);
//        points[3] = Vec2(winsize.width * 0.4, winsize.height * 0.6);
//        
//        dn->drawPolygon(points, 4, Color4F(0, 0, 0, 0), 1, Color4F(0, 0, 0, 0));
//        
//        ClippingNode* cn = ClippingNode::create();
//        cn->setAnchorPoint(Point(0, 0));
//        cn->setStencil(dn);
//        cn->setInverted(true);
//        cn->addChild(hider);
//        
//        this->addChild(cn);
        
        //方法2，用自定义的node实现，重写draw方法
        
        Sprite* s = Sprite::create("hall_bg.jpg");
        s->setPosition(Point(winsize.width / 2, winsize.height / 2));
        this->addChild(s);
        
        HoleNode* hn = HoleNode::create(Rect(100, 100, 200, 200));
        this->addChild(hn);
        
        
        
        //方法3，用透明图片使用blend实现
//        Sprite* h = Sprite::create("transhole.png");
//        h->setPosition(Point(winsize.width / 2, winsize.height / 2));\
//        h->setBlendFunc({GL_ONE, GL_ZERO});
//        this->addChild(h);
//
//        Sprite* s = Sprite::create("HelloWorld.png");
//        s->setPosition(Point(winsize.width / 2, winsize.height / 2));
//        BlendFunc blend = {GL_DST_ALPHA, GL_ZERO};
//        s->setBlendFunc(blend);
//        this->addChild(s);
        
        //方法4，用一个很小的半透明图片，使用texParam平铺开，再在shader内判断区域把透明度变成0，应该可以?
        //这里用layercolor在shader上改，貌似不起作用，因为片段着色器里面的a_texcoord貌似是(0,0)，而顶点着色器只作用于4个顶点？
//        Sprite* s = Sprite::create("hall_bg.jpg");
//        s->setPosition(Point(winsize.width / 2, winsize.height / 2));
//        this->addChild(s);
//        LayerColor* lc = LayerColor::create(Color4B(125, 125, 125, 125), winsize.width, winsize.height);
//        GLProgram* gp = GLProgram::createWithFilenames("Shaders/transparent_hole.vsh", "Shaders/transparent_hole.fsh");
//        GLProgramState* gs = GLProgramState::create(gp);
//        lc->setGLProgramState(gs);
//        this->addChild(lc);
        
        return true;
    }
    return false;
}