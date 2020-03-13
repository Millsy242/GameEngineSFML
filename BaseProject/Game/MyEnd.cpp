//
//  MyEnd.cpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//

#include "MyEnd.hpp"




MyEnd::MyEnd(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : End(LOG,SM)
{
    
}

void MyEnd::Input(  float dt)
{
    *log << "End Input";
}
void MyEnd::Render(std::shared_ptr<Window> window)
{
    *log << "End Render";
    window->BeginDraw(Colours::silver);
    
    window->EndDraw();
}
void MyEnd::EarlyUpdate()
{
    *log << "End Early Update";
}
void MyEnd::LateUpdate()
{
    *log << "End Late Update";
}
void MyEnd::FixedUpdate(float dt)
{
    *log << "End Fixed Update";
}

void MyEnd::UI()
{
    *log << "UI";
    ImGui::Begin("End UI");
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
