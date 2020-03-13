//
//  Window.cpp
//  SFGameEngine
//
//  Created by Daniel Harvey on 27/05/2019.
//  Copyright © 2019 Daniel Harvey. All rights reserved.
//

#include "Window.hpp"
#include <iostream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>

Window::Window(std::shared_ptr<ige::FileLogger> LOG)
{
    log = LOG;
}

void Window::Start(const std::string& windowName,sf::Vector2u WindowSize,sf::Vector2u PixelSize, bool Fullscreen)
{
    *log << "Creating SFML window";
    FullScreen = Fullscreen;
    if(Fullscreen)
        window.create(sf::VideoMode(WindowSize.x,WindowSize.y,32), windowName, sf::Style::Fullscreen);
    else
        window.create(sf::VideoMode(WindowSize.x,WindowSize.y,32), windowName, sf::Style::Default);
    
    if(FrameRateLimit != 0)
       window.setFramerateLimit(FrameRateLimit);
    
    UseRenderTexture(PixelSize.x, PixelSize.y);

    *log << "Setting up ImGui";
    ImGui::SFML::Init(window);
    *log << "Setting up TGui";
    GUI.setTarget(window);
    CalculateDT();
}
void Window::UseRenderTexture(int PX,int PY)
{
    if(PX > 0 && PY > 0)
    {
        PixelW = PX;
        PixelH = PY;
    }
    
    if(PixelW == 1 && PixelH == 1)
    {
        target = &window;
        RenderToTexture = false;
    }
    else
    {
        target = &RT;
        RT.create(GetWindowSize().x/PixelW, GetWindowSize().y/PixelH);
        RenderSprite = sf::Sprite();
        RenderSprite.setPosition(0,0);
        RenderToTexture = true;
    }
}
sf::Vector2i Window::GetMouse()
{
    auto pos = sf::Mouse::getPosition(window);
    if(RenderToTexture)
    {
        return sf::Vector2i(pos.x/PixelW,pos.y/PixelH);
    }
    else
    {
        return pos;
    }
}
void Window::Close()
{
    window.close();
}
void Window::SetPixelSize(int Size_X,int Size_Y)
{
    UseRenderTexture(Size_X, Size_Y);
}
void Window::SetScreenSize(sf::Vector2u size)
{
    RT.create(size.x, size.y);
    if(window.getSize().x/size.x != PixelW || window.getSize().y/size.y != PixelH )
    {
        PixelH = window.getSize().y/size.y;
        PixelW = window.getSize().x/size.x;
    }
}
sf::Vector2u Window::GetScreenSize()
{
    return target->getSize();
}
void Window::SetVsync(bool Vsync)
{
    VerticalSync = Vsync;
    window.setVerticalSyncEnabled(Vsync);
}
void Window::SetWindowSize(sf::Vector2u size)
{
    window.setSize(size);
    RT.create(size.x/PixelW, size.y/PixelH);
}
void Window::Update()
{
    *log << "Updating Window";
    fps.update();
    ImGui::SFML::Update(window, sf::seconds(deltatime));
   
    while (window.pollEvent(event))
    {
         ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
        {
            window.close();
        }
        else if (event.type == sf::Event::Resized)
        {
            OnResize(event.size.width, event.size.height);
        }
        else if (event.type == sf::Event::MouseEntered)
        {
            HasMouse = true;
        }
        else if (event.type == sf::Event::MouseLeft)
        {
            HasMouse = false;
        }
        else if (event.type == sf::Event::LostFocus)
        {
            InFocus = false;
        }
        else if (event.type == sf::Event::GainedFocus)
        {
            InFocus = true;
        }
        else if (event.type == sf::Event::JoystickConnected)
        {
            std::cout<< "JoyStick Connected\n";
        }
        else if (event.type == sf::Event::JoystickDisconnected)
        {
           std::cout<< "JoyStick Disconnected\n";
        }
        else
        {
            
        }
    }
}

void Window::OnResize(float newx, float newy)
{
    SetWindowSize(sf::Vector2u(newx,newy));
}

void Window::BeginDraw(Colour colour)
{
    *log << "Starting render";
    DrawCalls = 0;
    
    if(RenderToTexture)
        RT.clear(Colours::blue);
    window.clear(colour);
}
void Window::draw(const sf::Drawable& drawable)
{
     *log << "Drawing drawable";
    ++DrawCalls;
      target->draw(drawable);
}
void Window::draw(const sf::Vertex *vertices, std::size_t vertexCount, sf::PrimitiveType type)
{
    ++DrawCalls;
    target->draw(vertices,vertexCount,type);
}
void Window::draw(const sf::VertexBuffer &vertexBuffer)
{
    ++DrawCalls;
    target->draw(vertexBuffer);
}
void Window::draw(const sf::VertexBuffer &vertexBuffer, std::size_t firstVertex, std::size_t vertexCount)
{
    ++DrawCalls;
    target->draw(vertexBuffer,firstVertex,vertexCount);
}
void Window::draw(myRect &rec,Colour col)
{
    sf::VertexArray arr(sf::Lines,8);
    
    arr[0].position = sf::Vector2f(rec.left,rec.top);
    arr[0].color = col;
    arr[1].position = sf::Vector2f(rec.right,rec.top);
    arr[1].color = col;
    arr[2].position = sf::Vector2f(rec.right,rec.top);
    arr[2].color = col;
    arr[3].position = sf::Vector2f(rec.right,rec.base);
    arr[3].color = col;
    arr[4].position = sf::Vector2f(rec.left,rec.top);
    arr[4].color = col;
    arr[5].position = sf::Vector2f(rec.left,rec.base);
    arr[5].color = col;
    arr[6].position = sf::Vector2f(rec.left,rec.base);
    arr[6].color = col;
    arr[7].position = sf::Vector2f(rec.right,rec.base);
    arr[7].color = col;

    draw(arr);
}
void Window::draw(const std::vector<std::pair<float, float>> &vecModelCoordinates, float x, float y, float r, float s, Colour col )
{
    //Please note: this code was taken and adapted from the console game engine, writted by Javidx9
       //https://github.com/OneLoneCoder/videos/blob/master/olcConsoleGameEngineGL.h
       // pair.first = x coordinate
       // pair.second = y coordinate

       // Create translated model vector of coordinate pairs
       std::vector<std::pair<float, float>> vecTransformedCoordinates;
       int verts = (int)vecModelCoordinates.size();
       vecTransformedCoordinates.resize(verts);

       // Rotate
       for (int i = 0; i < verts; i++)
       {
           vecTransformedCoordinates[i].first = vecModelCoordinates[i].first * cosf(r) - vecModelCoordinates[i].second * sinf(r);
           vecTransformedCoordinates[i].second = vecModelCoordinates[i].first * sinf(r) + vecModelCoordinates[i].second * cosf(r);
       }

       // Scale
       for (int i = 0; i < verts; i++)
       {
           vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first * s;
           vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second * s;
       }

       // Translate
       for (int i = 0; i < verts; i++)
       {
           vecTransformedCoordinates[i].first = vecTransformedCoordinates[i].first + x;
           vecTransformedCoordinates[i].second = vecTransformedCoordinates[i].second + y;
       }

       // Draw Closed Polygon
    //could optimise this to 1 draw call !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
       for (int i = 0; i < verts + 1; i++)
       {
           int j = (i + 1);
           
           sf::Vertex line[] =
           {
               sf::Vertex({vecTransformedCoordinates[i % verts].first, vecTransformedCoordinates[i % verts].second}),
               sf::Vertex({vecTransformedCoordinates[j % verts].first, vecTransformedCoordinates[j % verts].second})
           };
           line[0].color = col;
           line[1].color = col;
           draw(line, 2, sf::Lines);
       }
}
void Window::EndDraw()
{
     *log << "Finishing Draw";

    ImGui::EndFrame();
    if(RenderToTexture)
    {
        RT.display();
        RenderSprite.setTexture(RT.getTexture());
        RenderSprite.setScale(PixelW, PixelH);
        window.draw(RenderSprite);
        ++DrawCalls;
    }
    
    ImGui::SFML::Render(window);
    window.display();
    CalculateDT();
}
void Window::CalculateDT()
{
    deltatime = clock.restart().asSeconds();
}
bool Window::IsOpen() const
{
    return window.isOpen();
}
sf::Vector2u Window::GetWindowSize()
{
    return window.getSize();
}
sf::Vector2u Window::GetWindowCentre()
{    
    return sf::Vector2u(window.getSize().x/2,window.getSize().y/2);
}
sf::Vector2u Window::GetScreenCentre()
{
     return sf::Vector2u(target->getSize().x/PixelW/2,target->getSize().y/PixelH/2);
}
void Window::SetTitle(std::string &title)
{
    window.setTitle(title);
}
float Window::getDT()
{
    return deltatime;
}
double Window::GetFPS()
{
    return fps.getFps();
}
sf::Vector2i Window::GetPixelSize()
{
    return {PixelW,PixelH};
}
 void Window::WindowDebug()
{
    ImGui::Begin("Window Debug Data");
    ImGui::Text("Window Size: %i,%i\nWindow Position: %i,%i\nAnti Aliasing Level: %u\nattributeFlags: %u\ndepthBits: %u\nmajorVersion: %u\nminorVersion: %u\nsRgbCapable: %u\nstencilBits: %u\nDelta Time: %f s\nFPS: %f\nDrawCalls: %d\nVsync: %d\nHasMouse: %d\nInFocus: %d\nFullScreen: %d\nFrameRate Limit: %d",
                window.getSize().x,
                window.getSize().y,
                window.getPosition().x,
                window.getPosition().y,
                window.getSettings().antialiasingLevel,
                window.getSettings().attributeFlags,
                window.getSettings().depthBits,
                window.getSettings().majorVersion,
                window.getSettings().minorVersion,
                window.getSettings().sRgbCapable,
                window.getSettings().stencilBits,
                deltatime,
                fps.getFps(),
                DrawCalls,
                VerticalSync,
                HasMouse,
                InFocus,
                FullScreen,
                FrameRateLimit);
    ImGui::End();

}
