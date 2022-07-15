#pragma once
#include "Interface/IApplication.hpp"

namespace Zephyr{
    class BaseApplication : public IApplication{
    public:
	    int Initialize() override;
	    void Finalize() override;
	    void Tick() override;
	    bool IsQuit() override;
    protected:
        bool mQuit;
    };
}
