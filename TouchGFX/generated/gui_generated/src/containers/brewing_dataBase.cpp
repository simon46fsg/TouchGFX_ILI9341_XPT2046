/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/brewing_dataBase.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

brewing_dataBase::brewing_dataBase()
{
    setWidth(79);
    setHeight(72);
    temperature.setPosition(0, 0, 70, 24);
    temperature.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    temperature.setLinespacing(0);
    temperature.setWildcard(touchgfx::TypedText(T_WILDCARD_TEMP).getText());
    temperature.setTypedText(touchgfx::TypedText(T_TEMP_UNIT));

    pressure.setPosition(0, 48, 79, 24);
    pressure.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    pressure.setLinespacing(0);
    pressure.setWildcard(touchgfx::TypedText(T_WILDCARD_PRESSURE).getText());
    pressure.setTypedText(touchgfx::TypedText(T_PRESSURE_UNIT));

    timer.setPosition(0, 24, 79, 24);
    timer.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    timer.setLinespacing(0);
    timer.setWildcard(touchgfx::TypedText(T_WILDCARD_TIMER).getText());
    timer.setTypedText(touchgfx::TypedText(T_TIMER_UNIT));

    add(temperature);
    add(pressure);
    add(timer);
}

brewing_dataBase::~brewing_dataBase()
{

}

void brewing_dataBase::initialize()
{

}
