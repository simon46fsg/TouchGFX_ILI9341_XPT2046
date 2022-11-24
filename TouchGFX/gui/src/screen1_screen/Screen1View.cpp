#include <gui/screen1_screen/Screen1View.hpp>

extern TemperatureSensor temperatureSensor;

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::handleTickEvent() {
	brewing_data1.updateTempData(temperatureSensor.temp);
}
