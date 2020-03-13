//
//  MyEnd.hpp
//  GameEngineSFML
//
//  Created by Daniel Harvey on 09/03/2020.
//  Copyright © 2020 Daniel Harvey. All rights reserved.
//


#ifndef MyEnd_hpp
#define MyEnd_hpp
#include <stdio.h>
#include "End.hpp"

class MyEnd : public End
{
public:
    MyEnd(std::shared_ptr<ige::FileLogger> LOG,std::shared_ptr<SettingsManager> SM);
    

    void Input(  float dt) override;
    void Render(std::shared_ptr<Window> window) override;
    void FixedUpdate(float dt) override;
    void EarlyUpdate() override;
    void LateUpdate() override;
    void UI() override;
private:
    
};

#endif /* MyEnd_hpp */
