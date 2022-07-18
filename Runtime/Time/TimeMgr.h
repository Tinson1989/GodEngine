#pragma once
#include<thread>
#include<chrono>
#include<Runtime/Interface/IModule.h>

namespace GodEngine
{
    class TimeMgr : ITickableModule{
    public:
        virtual int Initialize() noexcept;
        virtual void Finalize() noexcept;
        virtual void Tick() noexcept;

        void PreTick() noexcept;
        void PostTick() noexcept;
        void MicroSleep(unsigned long long ns) noexcept;
        float GetTotalMsTime() noexcept;
        float GetDeltaMsTime() noexcept;

    private:
        bool mFirstUpdate;
        std::chrono::time_point<std::chrono::high_resolution_clock> mStartTime;//开始时间
        std::chrono::time_point<std::chrono::high_resolution_clock> mLastUpdateTime;//上次更新时间

        std::chrono::time_point<std::chrono::high_resolution_clock> mFrameStartTime;//
        std::chrono::time_point<std::chrono::high_resolution_clock> mFrameEndTime;

        std::chrono::time_point<std::chrono::high_resolution_clock> mLastStatisticTime;
        int mFrameCount;
        float mFPS;
        std::chrono::nanoseconds mDeltaTime;
    };
} // namespace GodEngine
