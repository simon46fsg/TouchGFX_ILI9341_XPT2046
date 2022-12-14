#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

extern "C" {
	#include "../../Hardware_Interfacee/temp_sensor.h"
	#include "../../Hardware_Interfacee/pressure_sensor.h"
}


class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent();
    void startStopWatch();
    void resetStopWatch();
protected:
    float stopWatchTime;
    bool stopWatchIsRunning;
};

#endif // SCREEN1VIEW_HPP
