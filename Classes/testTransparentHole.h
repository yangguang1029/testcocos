//
//  testTransparentHole.h
//  testcocoscpp
//
//  Created by guangy on 3/3/15.
//
//

#ifndef __testcocoscpp__testTransparentHole__
#define __testcocoscpp__testTransparentHole__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;



class HoleNode : public Node {
public:
    void setHole(const Rect& rect);
    void draw(Renderer *renderer, const Mat4& transform, uint32_t flags);
    void onDraw(const Mat4& transform, uint32_t flags);
    
    static HoleNode* create(const Rect& rect);
    
private:
    Vec2 _squareVertices[8];
    Color4F  _squareColors[8];
    CustomCommand _customCommand;
    Vec3 _noMVPVertices[8];
    GLushort _indices[24];

    bool init();
};

class TestTransparentHole : public Layer {
    
public:
    static Scene* createScene();
    
private:
    bool init();
    
};

#endif /* defined(__testcocoscpp__testTransparentHole__) */
