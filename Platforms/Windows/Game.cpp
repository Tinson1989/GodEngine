#include <iostream>
#include"Configuration/Configuration.h"
#include"Runtime/Logging/Assert.h"

using namespace std;

int main(int argc, char** argv)
{
    cout << "EngineVersion:" << Engine_Version_Major << "." << Engine_Version_Minor << endl;
    cout << "EngineBuildType:" << BUILD_TYPE << endl;
    int a, b;
    a = 1, b = 2;
    Assert(a > b);
    return 0;
}
