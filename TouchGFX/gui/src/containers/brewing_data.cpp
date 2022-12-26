#include <gui/containers/brewing_data.hpp>

brewing_data::brewing_data()
{

}

void brewing_data::initialize()
{
    brewing_dataBase::initialize();
}

void brewing_data::updateTempData(float temp) {
	Unicode::snprintfFloat(temperatureBuffer, TEMPERATURE_SIZE, "%2.2f", temp);
	temperature.invalidate();
}

void brewing_data::updatePressureData(float pressureVal) {
	Unicode::snprintfFloat(pressureBuffer, PRESSURE_SIZE, "%2.1f", pressureVal);
	pressure.invalidate();
}

void brewing_data::updateTimer(float seconds) {
	Unicode::snprintfFloat(timerBuffer, TIMER_SIZE, "%4.2f", seconds);
	temperature.invalidate();
}
