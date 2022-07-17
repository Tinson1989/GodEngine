#pragma once
#include"Runtime/Logging/Assert.h"

namespace GodEngine
{
    class IModule{
    public:
        //这是用来初始化模块的
        virtual int Initialize() noexcept = 0;
        //在模块结束的时候打扫战场
        virtual void Finalize() noexcept = 0;
    };

    class ITickableModule : public IModule{
        //让驱动模块驱动该模块执行
        virtual void Tick() noexcept = 0;
    };
} // namespace GodEngine
