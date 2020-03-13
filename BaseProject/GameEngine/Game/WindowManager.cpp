//
//  WindowManager.cpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "WindowManager.hpp"
#include "MyGame.hpp"
#include "MyMenu.hpp"
#include "MyIntro.hpp"
#include "MyEnd.hpp"

void WindowManager::Start()
{
    log = std::shared_ptr<ige::FileLogger>(new ige::FileLogger("0.5","GameLog.txt"));
    settings = std::shared_ptr<SettingsManager>(new SettingsManager());
    settings->Setup();
    
    window = std::shared_ptr<Window>(new Window(log));
    window->Start(" ",settings->MenuSize);
    ChangeWindow(windowType::eIntro);
}
void WindowManager::Update() 
{
    while(currentWindow->Continue)
    {
        settings->Setup();
        currentWindow->Update();
        if(currentWindow->Continue)
        {
            if(CurrentWindowType == windowType::eIntro)
                ChangeWindow(windowType::eMenu);
            else if(CurrentWindowType == windowType::eMenu)
                ChangeWindow(windowType::eGame);
            else if(CurrentWindowType == windowType::eGame)
                ChangeWindow(windowType::eEnd);
            else if(CurrentWindowType == windowType::eEnd)
                ChangeWindow(windowType::eMenu);
        }
    }
    *log << "Exiting";
}
void WindowManager::Exit()
{
    currentWindow->Exit();
}
void WindowManager::FixedUpdate(float dt)
{
    
}
void WindowManager::Render(std::shared_ptr<Window> window)
{

}
void WindowManager::Input(float dt)
{

}
void WindowManager::ChangeWindow(windowType wt)
{
    if(CurrentWindowType != wt)
    {
        CurrentWindowType = wt;
        UpdateFromSettings();
        switch (wt)
        {
            case windowType::eIntro:
                currentWindow = std::make_shared<MyIntro>(log,settings);
                *log << "Changing to Intro";
                break;
            case windowType::eMenu:
                currentWindow = std::make_shared<MyMenu>(log,settings);
                *log << "Changing to Menu";
                break;
            case windowType::eGame:
                currentWindow = std::make_shared<MyGame>(log,settings);
                *log << "Changing to Game";
                break;
            case windowType::eEnd:
                currentWindow = std::make_shared<MyEnd>(log,settings);
                *log << "Changing to End";
                break;
            default:
                break;
        }
        currentWindow->GiveWindow(window);
        currentWindow->Start();
    }
}
void WindowManager::UpdateFromSettings()
{
    switch (CurrentWindowType)
           {
               case windowType::eIntro:
                    window->Start("Intro", settings->MenuSize);
                   *log << "Changing to Intro";
                   break;
               case windowType::eMenu:
                    window->Start("Menu", settings->MenuSize);
                   *log << "Changing to Menu";
                   break;
               case windowType::eGame:
                   window->Start("Game", settings->GameSize, settings->PixelSize, settings->Fullscreen);
                   *log << "Changing to Game";
                   break;
               case windowType::eEnd:
                    window->Start("End", settings->MenuSize);
                   *log << "Changing to End";
                   break;
               default:
                   break;
           }

    window->SetVsync(settings->Vsync);
}
