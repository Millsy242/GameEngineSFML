//
//  WindowManager.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 17/10/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef WindowManager_hpp
#define WindowManager_hpp
#include "Base.hpp"
#include <SFML/Graphics.hpp>
#include "Window.hpp"


#include <thread>
#include "FileLogger.hpp"
#include "SettingsManager.hpp"

class WindowHolder;

class WindowManager : public Base
{
public:
    enum class windowType
    {
        eNull,
        eIntro,
        eGame,
        eMenu,
        eEnd
    };
    
    WindowManager() {};
    ~WindowManager(){};
    
    void Start() override;
    void Update() override;
    void FixedUpdate(float dt) override;
    void Exit() override;
    void Render(std::shared_ptr<Window> window) override;
    void Input(  float dt) override;
    
    void ChangeWindow(windowType wt);
    void UpdateWindow();
    void UpdateFromSettings(); 
    
private:
    std::shared_ptr<WindowHolder> currentWindow;
    std::shared_ptr<Window> window;
    std::shared_ptr<ige::FileLogger> log = nullptr;
    std::shared_ptr<SettingsManager> settings;
    windowType CurrentWindowType = windowType::eNull;

};

#endif /* WindowManager_hpp */
