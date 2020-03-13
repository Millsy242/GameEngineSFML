//
//  MyGame.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 03/11/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef MyGame_hpp
#define MyGame_hpp
#include "Game.hpp"

class MyGame : public Game
{
    public:
        MyGame(std::shared_ptr<ige::FileLogger> LOG, std::shared_ptr<SettingsManager> SM) ;
        void Start() override;
        void Input(  float dt) override;
        void Render(std::shared_ptr<Window> window) override;
        void UI() override;
        void EarlyUpdate() override;
        void LateUpdate() override;
        void FixedUpdate(float dt) override;
        void Exit() override; 
    private:
    sf::RectangleShape r; 
};

#endif /* MyGame_hpp */
