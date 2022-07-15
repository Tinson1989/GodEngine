#pragma once
namespace Zephyr{
    class IRuntimeModule{
    public:
        virtual ~IRuntimeModule(){}

        virtual int Initialize() = 0;   //初始化模块的
        virtual void Finalize() = 0;    //模块结束的时候打扫战场的
        virtual void Tick() = 0;        //让驱动模块驱动该模块执行
    };
}