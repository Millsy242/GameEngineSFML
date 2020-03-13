//
//  Intro.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef Intro_hpp
#define Intro_hpp

#include "WindowHolder.hpp"
#include <stdio.h>

class Intro : public WindowHolder
{
public:
    Intro(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM);
    ~Intro(){};
        
    virtual void Start() override;
    virtual void Input(  float dt) override;
    virtual void Render(std::shared_ptr<Window> window) override;
    virtual void PostRender() override;
    virtual void UI() override;
    virtual void EarlyUpdate() override;
    virtual void LateUpdate() override;
    virtual void FixedUpdate(float dt) override;
    
protected:
    
};
#endif /* Intro_hpp */
