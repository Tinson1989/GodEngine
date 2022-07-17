#pragma once
namespace GodEngine{
    template<typename T>
    class Singleton{
    public:
        static T* GetInstance(){
            if(nullptr == pInstance){
                pInstance = new T();
            }
            return pInstance;
        }

    private:
        //静态变量声明  
        static T* pInstance;
    };

    //静态变量定义
    template<typename T>
    T* Singleton<T>::pInstance = nullptr;
}