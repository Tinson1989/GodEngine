#pragma once
#include "Interface/IApplication.hpp"

namespace GodEngine{
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
