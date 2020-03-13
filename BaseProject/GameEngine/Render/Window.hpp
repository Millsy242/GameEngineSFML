//
//  Window.hpp
//  SFGameEngine
//
//  Created by Daniel Harvey on 27/05/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#ifndef Window_hpp
#define Window_hpp


#include "imgui.h"
#include "imgui-SFML.h"
#include "FpsLite.hpp"
#include <SFML/Graphics.hpp>
#include "FileLogger.hpp"
#include <thread>
#include <queue>
#include "Rect.hpp"
#include <TGUI/TGUI.hpp>
#include "TypeDefs.h"

class Window
{
public:
    Window(std::shared_ptr<ige::FileLogger> LOG);
    void Start(const std::string& windowName,sf::Vector2u WindowSize,sf::Vector2u PixelSize = {1,1},bool Fullscreen = false);
    void Update();
    void BeginDraw(Colour colour = Colours::magenta);
    void draw(const sf::Drawable& drawable);
    void draw(myRect &rec, Colour col = Colours::red);
    void draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type);
    void draw(const sf::VertexBuffer &vertexBuffer);
    void draw(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount);
    void draw(const std::vector<std::pair<float, float>> &vecModelCoordinates, float x, float y, float r = 0.0f, float s = 1.0f, Colour col = Colours::white );
    
    void EndDraw();
    void Close();
    void SetWindowSize(sf::Vector2u size);
    void SetPixelSize(int Size_X,int Size_Y);
    void SetVsync(bool Vsync);
    void SetTitle(std::string &title);
    bool IsOpen() const;
    void OnResize(float newx, float newy);
    void WindowDebug(); 

    float getDT();
    double GetFPS();
    
    
    void UseRenderTexture(int PX,int PY);
    void SetScreenSize(sf::Vector2u size);
    sf::Vector2u GetScreenSize();
    sf::Vector2u GetWindowSize();
    sf::Vector2u GetWindowCentre();
    sf::Vector2u GetScreenCentre();
    sf::Vector2i GetMouse();
    sf::Vector2i GetPixelSize(); 
   
    
    bool RenderToTexture = false;
    
    bool HasMouse{true}, InFocus{true}, VerticalSync{false}, FullScreen{false};
    unsigned int DrawCalls{0},FrameRateLimit{0};
    
    
private:
    void CalculateDT();
    sf::RenderTarget *target; 
    sf::RenderWindow window;
    sf::RenderTexture RT; 
    sf::Sprite windowtexture;
    sf::Clock clock;
    sf::Event event;
    sf::Sprite RenderSprite; 
    
    tgui::Gui GUI; 
    
    kairos::FpsLite fps;
    float deltatime;
    int PixelW{1},PixelH{1};

    std::shared_ptr<ige::FileLogger> log;
};


#endif /* Window_hpp */

