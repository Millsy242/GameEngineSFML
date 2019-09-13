//
//  Game.hpp
//  BaseProject
//
//  Created by Daniel Harvey on 13/09/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp
#include "WindowHolder.hpp"

#include <stdio.h>
class Game : public WindowHolder
{
public:
    Game();
    ~Game(){};
    
    void Start() override;
    void Input() override;
    void Render() override;
    void UI() override;
    void EarlyUpdate() override;
    void LateUpdate() override;
private:
    
};
#endif /* Game_hpp */