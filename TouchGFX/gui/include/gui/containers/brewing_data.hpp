#ifndef BREWING_DATA_HPP
#define BREWING_DATA_HPP

#include <gui_generated/containers/brewing_dataBase.hpp>

class brewing_data : public brewing_dataBase
{
public:
    brewing_data();
    virtual ~brewing_data() {}

    virtual void initialize();
protected:
};

#endif // BREWING_DATA_HPP
