/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef BREWING_DATABASE_HPP
#define BREWING_DATABASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class brewing_dataBase : public touchgfx::Container
{
public:
    brewing_dataBase();
    virtual ~brewing_dataBase();
    virtual void initialize();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::TextAreaWithOneWildcard temperature;
    touchgfx::TextAreaWithOneWildcard pressure;
    touchgfx::TextAreaWithOneWildcard timer;

private:

};

#endif // BREWING_DATABASE_HPP
