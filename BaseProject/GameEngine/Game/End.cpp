//
//  End.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "End.hpp"

 End::End(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM)
{
    log = LOG;
    settings = SM;
}

void End::Start()
{

}
void End::Input(  float dt)
{
    *log << "End Input";
}
void End::Render(std::shared_ptr<Window> window)
{
    *log << "End Render";
    window->BeginDraw(Colours::black);
    
    window->EndDraw();
}
void End::UI()
{

}
void End::EarlyUpdate()
{
    *log << "End Early Update";
}
void End::LateUpdate()
{
    *log << "End Late Update";
}
void End::FixedUpdate(float dt)
{
    *log << "End Fixed Update";
}

void End::PostRender()
{
    
}
