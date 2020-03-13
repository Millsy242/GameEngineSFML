//
//TypeDefs.h
//GameEngineSFML
//
//CreatedbyDanielHarveyon09/03/2020.
//Copyright©2020DanielHarvey.Allrightsreserved.
//

#ifndef TypeDefs_h
#define TypeDefs_h

#include <SFML/Graphics/Color.hpp>

//TypeDefs
typedef sf::Color Colour;
typedef sf::Keyboard::Key Key;

//namespaces
namespace Colours
{
   static const Colour maroon(128,0,0),
    darkred(139,0,0),
    brown(165,42,42),
    firebrick(178,34,34),
    crimson(220,20,60),
    red(255,0,0),
    tomato(255,99,71),
    coral(255,127,80),
    indianred(205,92,92),
    lightcoral(240,128,128),
    darksalmon(233,150,122),
    salmon(250,128,114),
    lightsalmon(255,160,122),
    orangered(255,69,0),
    darkorange(255,140,0),
    orange(255,165,0),
    gold(255,215,0),
    darkgoldenrod(184,134,11),
    goldenrod(218,165,32),
    palegoldenrod(238,232,170),
    darkkhaki(189,183,107),
    khaki(240,230,140),
    olive(128,128,0),
    yellow(255,255,0),
    yellowgreen(154,205,50),
    darkolivegreen(85,107,47),
    olivedrab(107,142,35),
    lawngreen(124,252,0),
    chartreuse(127,255,0),
    greenyellow(173,255,47),
    darkgreen(0,100,0),
    green(0,128,0),
    forestgreen(34,139,34),
    lime(0,255,0),
    limegreen(50,205,50),
    lightgreen(144,238,144),
    palegreen(152,251,152),
    darkseagreen(143,188,143),
    mediumspringgreen(0,250,154),
    springgreen(0,255,127),
    seagreen(46,139,87),
    mediumaquamarine(102,205,170),
    mediumseagreen(60,179,113),
    lightseagreen(32,178,170),
    darkslategray(47,79,79),
    teal(0,128,128),
    darkcyan(0,139,139),
    aqua(0,255,255),
    cyan(0,255,255),
    lightcyan(224,255,255),
    darkturquoise(0,206,209),
    turquoise(64,224,208),
    mediumturquoise(72,209,204),
    paleturquoise(175,238,238),
    aquamarine(127,255,212),
    powderblue(176,224,230),
    cadetblue(95,158,160),
    steelblue(70,130,180),
    cornflowerblue(100,149,237),
    deepskyblue(0,191,255),
    dodgerblue(30,144,255),
    lightblue(173,216,230),
    skyblue(135,206,235),
    lightskyblue(135,206,250),
    midnightblue(25,25,112),
    navy(0,0,128),
    darkblue(0,0,139),
    mediumblue(0,0,205),
    blue(0,0,255),
    royalblue(65,105,225),
    blueviolet(138,43,226),
    indigo(75,0,130),
    darkslateblue(72,61,139),
    slateblue(106,90,205),
    mediumslateblue(123,104,238),
    mediumpurple(147,112,219),
    darkmagenta(139,0,139),
    darkviolet(148,0,211),
    darkorchid(153,50,204),
    mediumorchid(186,85,211),
    purple(128,0,128),
    thistle(216,191,216),
    plum(221,160,221),
    violet(238,130,238),
    magenta(255,0,255),
    orchid(218,112,214),
    mediumvioletred(199,21,133),
    palevioletred(219,112,147),
    deeppink(255,20,147),
    hotpink(255,105,180),
    lightpink(255,182,193),
    pink(255,192,203),
    antiquewhite(250,235,215),
    beige(245,245,220),
    bisque(255,228,196),
    blanchedalmond(255,235,205),
    wheat(245,222,179),
    cornsilk(255,248,220),
    lemonchiffon(255,250,205),
    lightgoldenrodyellow(250,250,210),
    lightyellow(255,255,224),
    saddlebrown(139,69,19),
    sienna(160,82,45),
    chocolate(210,105,30),
    peru(205,133,63),
    sandybrown(244,164,96),
    burlywood(222,184,135),
    tan(210,180,140),
    rosybrown(188,143,143),
    moccasin(255,228,181),
    navajowhite(255,222,173),
    peachpuff(255,218,185),
    mistyrose(255,228,225),
    lavenderblush(255,240,245),
    linen(250,240,230),
    oldlace(253,245,230),
    papayawhip(255,239,213),
    seashell(255,245,238),
    mintcream(245,255,250),
    slategray(112,128,144),
    lightslategray(119,136,153),
    lightsteelblue(176,196,222),
    lavender(230,230,250),
    floralwhite(255,250,240),
    aliceblue(240,248,255),
    ghostwhite(248,248,255),
    honeydew(240,255,240),
    ivory(255,255,240),
    azure(240,255,255),
    snow(255,250,250),
    black(0,0,0),
    dimgrey(105,105,105),
    grey(128,128,128),
    Darkgrey(169,169,169),
    silver(192,192,192),
    lightgrey(211,211,211),
    gainsboro(220,220,220),
    whitesmoke(245,245,245),
    white(255,255,255);
}
namespace Input
{
#include "imgui.h"
#include "imgui-SFML.h"

    inline bool IsKeyDown(int key_index)
    {
        return ImGui::IsKeyDown(key_index);
    }
    inline bool IsKeyPressed(int key_index)
    {
        return ImGui::IsKeyPressed(key_index);
    }
    inline bool IsKeyReleased(int key_index)
    {
        return ImGui::IsKeyReleased(key_index);
    }
    inline bool IsMouseDown(int mouse_index)
    {
        return ImGui::IsMouseDown(mouse_index);
    }
    inline bool IsMouseClicked(int mouse_index)
    {
        return ImGui::IsMouseClicked(mouse_index);
    }
    inline bool IsMouseReleased(int mouse_index)
    {
        return ImGui::IsMouseReleased(mouse_index);
    }
    inline bool IsMouseDoubleClicked(int mouse_index)
    {
        return ImGui::IsMouseDoubleClicked(mouse_index);
    }
    inline bool IsMouseHoveringRect(sf::Vector2f &Recmin, sf::Vector2f &Recmax)
    {
        return ImGui::IsMouseHoveringRect(ImVec2(Recmin),ImVec2(Recmax));
    }
    inline bool IsMouseDragging()
    {
        return ImGui::IsMouseDragging();
    }

}

#endif/*TypeDefs_h*/
