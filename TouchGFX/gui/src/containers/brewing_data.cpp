#include <gui/containers/brewing_data.hpp>

brewing_data::brewing_data()
{

}

void brewing_data::initialize()
{
    brewing_dataBase::initialize();
}

void brewing_data::updateTempData(float temp) {
	Unicode::snprintf(temperatureBuffer, TEMPERATURE_SIZE, "%d", temp);
	temperature.invalidate();
}
