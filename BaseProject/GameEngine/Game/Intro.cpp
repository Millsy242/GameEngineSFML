//
//  Intro.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "Intro.hpp"

 Intro::Intro(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM)
{
    log = LOG;
    settings = SM;
}

void Intro::Start()
{

}
void Intro::Input(  float dt)
{
    *log << "Intro Input";
}
void Intro::Render(std::shared_ptr<Window> window)
{
    *log << "Intro Render";
    window->BeginDraw(Colours::black);
    
    window->EndDraw();
}
void Intro::UI()
{

}
void Intro::EarlyUpdate()
{
    *log << "Intro Early Update";
}
void Intro::LateUpdate()
{
    *log << "Intro Late Update";
}
void Intro::FixedUpdate(float dt)
{
    *log << "Intro Fixed Update";
}

void Intro::PostRender()
{
    
}
