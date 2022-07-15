#pragma once
#include"Interface/IRuntimeModule.hpp"
namespace Zephyr{
    class GraphicsMgr : public IRuntimeModule{
    public:
        virtual ~GraphicsMgr(){}
    };
}