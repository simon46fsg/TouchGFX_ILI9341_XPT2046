#include <gui/screen1_screen/Screen1View.hpp>

extern TemperatureSensor temperatureSensor;
extern PressureSensor pressureSensor;

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
	static uint8_t i = 0;
	i++;
	if (i < 30) {
		brewing_data1.updateTempData(temperatureSensor.temp);
		brewing_data1.updatePressureData(pressureSensor.pressure);
		brewing_data1.invalidate();
		i = 0;
	}
}
