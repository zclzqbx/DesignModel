/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/20/2018 04:03:53 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#include <iostream>

using namespace std;

class Singleton{
    public:
        static Singleton* get_instance();
        ~Singleton();
        void out_info();
        void set_attr(int);

    private:
       Singleton();
    private:
       static Singleton *instance;
       int attr;
};

Singleton* Singleton::instance = nullptr;

Singleton* Singleton::get_instance()
{
    if (instance == nullptr)
    {
        instance = new Singleton();
    }

    return instance;
}

Singleton::Singleton()
{

}

Singleton::~Singleton()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

void Singleton::out_info()
{
    cout << attr << endl;
}

void Singleton::set_attr(int _attr)
{
    attr = _attr;
}

int main()
{
    Singleton *ptr = Singleton::get_instance();

    ptr->set_attr(520);
    ptr->out_info();
    cout << hex << ptr << endl;

    Singleton *ptr_2 = Singleton::get_instance();
    cout << hex << ptr_2 << endl;
    return 0;
}

