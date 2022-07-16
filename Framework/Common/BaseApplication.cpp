#include"BaseApplication.hpp"
namespace GodEngine{
    int BaseApplication::Initialize(){
        mQuit = false;
        return 0;
    }

    void BaseApplication::Finalize(){

    }

    void BaseApplication::Tick(){

    }

    bool BaseApplication::IsQuit(){
        return mQuit;
    }


}