#include <gui/containers/wrench_symbol.hpp>

wrench_symbol::wrench_symbol()
{

}

void wrench_symbol::initialize()
{
    wrench_symbolBase::initialize();
    Application::getInstance()->registerTimerWidget(this);
}

void wrench_symbol::handleTickEvent() {
	bool test = circle1.isTouchable();
}
