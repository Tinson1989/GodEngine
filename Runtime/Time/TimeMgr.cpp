#include"TimeMgr.h"
#include"Runtime/Application/Application.h"
#include<iostream>
#include<sstream>

namespace GodEngine
{
    int TimeMgr::Initialize() noexcept{
        mFirstUpdate = true;
        mStartTime = mLastStatisticTime = std::chrono::high_resolution_clock::now();
        mFrameCount = 0;
        return 0;
    }

    void TimeMgr::Finalize() noexcept{

    }

    void TimeMgr::Tick() noexcept{
        auto duration = mFrameStartTime - mLastStatisticTime;
        if(duration > std::chrono::seconds(1)){
            mFPS = mFrameCount;
            mFrameCount = 0;
            mLastStatisticTime = mFrameStartTime;

            // if(Director::GetInstance()->mFps){
            //     std::ostringstream   ostr;
            //     ostr << "SCARLETT ENGINE FPS: " << m_fFPS;
            //     Director::GetInstance()->mFps->SetText(ostr.str());
            // }
        }else{
            mFrameCount++;
        }
    }

    void TimeMgr::PreTick() noexcept{
        if(mFirstUpdate){
            mLastUpdateTime = std::chrono::high_resolution_clock::now();
            mFirstUpdate = false;
        }

        mFrameStartTime = std::chrono::high_resolution_clock::now();
        mDeltaTime = mFrameStartTime - mLastUpdateTime;
        mLastUpdateTime = mFrameStartTime;
    }

    void TimeMgr::PostTick() noexcept{
        mFrameEndTime = std::chrono::high_resolution_clock::now();
        auto total = mFrameEndTime - mFrameStartTime;
        long long interval = 15000000;
        long long sleep = interval - total.count();
        if(sleep > 0){
            MicroSleep(sleep);
        }
    }

    void TimeMgr::MicroSleep(unsigned long long ns) noexcept{
        std::this_thread::sleep_for(std::chrono::nanoseconds(ns));
    }

    float TimeMgr::GetDeltaMsTime() noexcept{
        auto delta = mFrameStartTime - mStartTime;
        return delta.count() / 1000000.0f;
    }

    float TimeMgr::GetDeltaMsTime() noexcept{
        return mDeltaTime.count() / 1000000.0f;
    }
} // namespace GodEngine
