//
//  MyGame.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "MyGame.hpp"


MyGame::MyGame(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM) : Game(LOG, SM)
{
    
}
void MyGame::Start()
{
    *log << "Game Start";
    
    r.setSize({20.f/window->GetPixelSize().x,20.f/window->GetPixelSize().y});
    r.setPosition(0,0);
    auto tenpcX = window->GetScreenSize().x*0.01;
    auto tenpcY = window->GetScreenSize().y*0.01;
    SetGameArea(myRect(tenpcX,tenpcY,window->GetScreenSize().x-tenpcX,window->GetScreenSize().y-tenpcY));

}
void MyGame::Input(  float dt)
{
   *log << "Game Input";
    float speed = 200 * dt;
    if(Input::IsKeyDown(Key::Right))
        r.move(speed, 0);
    if(Input::IsKeyDown(Key::Left))
    r.move(-speed, 0);
    if(Input::IsKeyDown(Key::Up))
    r.move(0, -speed);
    if(Input::IsKeyDown(Key::Down))
    r.move(0, speed);

}
void MyGame::Render(std::shared_ptr<Window> window)
{
    *log << "Game Render";
    window->BeginDraw(Colours::forestgreen );
    
    window->draw(GameArea);
    
    window->draw(r);

    Game::DebugRender(window);
    window->EndDraw();
}
void MyGame::UI()
{
    *log << "UI";
    Game::GameUI();
}
void MyGame::EarlyUpdate()
{
    *log << "Game Early Update";

}
void MyGame::LateUpdate()
{
    *log << "Game Late Update";
}
void MyGame::FixedUpdate(float dt)
{
    *log << "Game Fixed Update";
    
    if(r.getPosition().x + r.getSize().x > GameArea.right)
        r.setPosition(GameArea.right - r.getSize().x, r.getPosition().y);
    if(r.getPosition().y + r.getSize().y > GameArea.base)
        r.setPosition(r.getPosition().x, GameArea.base - r.getSize().y);
    if(r.getPosition().x < GameArea.left)
        r.setPosition(GameArea.left, r.getPosition().y);
    if(r.getPosition().y < GameArea.top)
        r.setPosition(r.getPosition().x,GameArea.top);
}
void MyGame::Exit()
{

}
