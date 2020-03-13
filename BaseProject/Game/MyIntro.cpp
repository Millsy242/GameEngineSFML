//
//  MyIntro.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "MyIntro.hpp"

MyIntro::MyIntro(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Intro(LOG,SM)
{
    
}
void MyIntro::Start()
{
    a.setTexture(ResourceHolder::get().textures.get("Menu Icons/Start"));
    
    a.setScale(0.5, 0.5);
}
void MyIntro::Input(  float dt)
{
    *log << "Intro Input";
}
void MyIntro::Render(std::shared_ptr<Window> window)
{
    *log << "Intro Render";
    window->BeginDraw(Colours::seagreen);
    window->draw(a);
    window->EndDraw();
}
void MyIntro::EarlyUpdate()
{
    *log << "Intro Early Update";
}
void MyIntro::LateUpdate()
{
    *log << "Intro Late Update";
}
void MyIntro::FixedUpdate(float dt)
{
    *log << "Intro Fixed Update";
}
void MyIntro::UI()
{
    *log << "UI";
    ImGui::Begin("Intro UI");
    if(ImGui::Button("skip"))
    {
         Active = false;
    }
    if(ImGui::Button("Exit"))
    {
         Active = false;
        Continue = false;
    }
    ImGui::End();

}
