#include <iostream>
#include "Interface/IApplication.hpp"
using namespace std;
using namespace GodEngine;

namespace GodEngine{
    extern IApplication* gpApp;
}

int main(int argc, char** argv)
{
    int ret;
    if((ret = gpApp->Initialize()) != 0){
        cout << "App Initialize failed, will exit now." << endl;
        return ret;
    }

    while (!gpApp->IsQuit()){
        gpApp->Tick();
    }
    
    gpApp->Finalize();
    return 0;
}
