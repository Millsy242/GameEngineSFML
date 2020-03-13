//
//  MyMenu.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyMenu.hpp"

MyMenu::MyMenu(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Menu(LOG,SM)
{
    
}
void MyMenu::GameSettingsMenu()
{
    ImGui::Text("This is the Game Settings Menu!\nIt should be used for settings related to ingame variables.");
}
void MyMenu::Input(  float dt)
{
    *log << "Menu Input";
}
void MyMenu::Render(std::shared_ptr<Window> window)
{
    *log << "Menu Render";
    window->BeginDraw(Colours::orangered);
    
    window->EndDraw();
}
void MyMenu::EarlyUpdate()
{
    *log << "Menu Early Update";
}
void MyMenu::LateUpdate()
{
    *log << "Menu Late Update";
}
void MyMenu::FixedUpdate(float dt)
{
    *log << "Menu Fixed Update";
}
void MyMenu::GameSettingsMenuTWO()
{
    
}
