#ifndef WRENCH_SYMBOL_HPP
#define WRENCH_SYMBOL_HPP

#include <gui_generated/containers/wrench_symbolBase.hpp>

class wrench_symbol : public wrench_symbolBase
{
public:
    wrench_symbol();
    virtual ~wrench_symbol() {}

    virtual void initialize();
    virtual void handleTickEvent();
protected:
};

#endif // WRENCH_SYMBOL_HPP
