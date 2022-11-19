/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>


Screen1ViewBase::Screen1ViewBase() :
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler)
{

    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);

    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    background.setPosition(0, 0, 320, 240);
    background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));

    flexButton1.setBoxWithBorderPosition(0, 0, 81, 77);
    flexButton1.setBorderSize(5);
    flexButton1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton1.setPosition(0, 163, 81, 77);
    flexButton1.setAction(flexButtonCallback);

    flexButton2.setBoxWithBorderPosition(0, 0, 81, 72);
    flexButton2.setBorderSize(5);
    flexButton2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    flexButton2.setPosition(239, 168, 81, 72);
    flexButton2.setAction(flexButtonCallback);

    brewing_data1.setXY(16, 15);

    wrench_symbol1.setXY(249, 9);

    add(__background);
    add(background);
    add(flexButton1);
    add(flexButton2);
    add(brewing_data1);
    add(wrench_symbol1);
}

void Screen1ViewBase::setupScreen()
{
    brewing_data1.initialize();
    wrench_symbol1.initialize();
}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton1)
    {
        //Interaction1
        //When flexButton1 clicked hide brewing_data1
        //Hide brewing_data1
        brewing_data1.setVisible(false);
        brewing_data1.invalidate();
    }
    else if (&src == &flexButton2)
    {
        //Interaction2
        //When flexButton2 clicked show brewing_data1
        //Show brewing_data1
        brewing_data1.setVisible(true);
        brewing_data1.invalidate();
    }
}
