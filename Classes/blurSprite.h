//
//  blurSprite.h
//  testcocoscpp
//
//  Created by guangy on 1/16/15.
//
//

#ifndef __testcocoscpp__blurSprite__
#define __testcocoscpp__blurSprite__

#include <stdio.h>
#include "cocos2d.h"

using namespace cocos2d;

class SpriteBlur : public Sprite
{
public:
    ~SpriteBlur();
    bool initWithTexture(Texture2D* texture, const Rect&  rect);
    void initGLProgram();
    
    static SpriteBlur* create(const char *pszFileName);
    void setBlurRadius(float radius);
    void setBlurSampleNum(float num);
    
protected:
    float _blurRadius;
    float _blurSampleNum;
};


#endif /* defined(__testcocoscpp__blurSprite__) */
