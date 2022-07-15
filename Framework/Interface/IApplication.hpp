#pragma once
#include"IRuntimeModule.hpp"
namespace Zephyr{
    class IApplication : public IRuntimeModule{
    public:
        virtual int Initialize() = 0;
        virtual void Finalize() = 0;
        virtual void Tick() = 0;
        virtual bool IsQuit() = 0;
    };
}