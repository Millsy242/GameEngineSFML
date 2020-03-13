//
//  MyIntro.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#ifndef MyIntro_hpp
#define MyIntro_hpp
#include <stdio.h>
#include "Intro.hpp"

class MyIntro : public Intro
{
public:
    MyIntro(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM);
    
    void Start() override;
    void Input(  float dt) override;
    void Render(std::shared_ptr<Window> window) override;
    void FixedUpdate(float dt) override;
    void EarlyUpdate() override;
    void LateUpdate() override;
    void UI() override;
private:
        sf::Sprite a; 
};

#endif /* MyIntro_hpp */
