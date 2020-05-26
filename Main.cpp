#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <future>
#include <random>
#include "Bear.h"

using namespace std;

int amountOfHoney = 100;
mutex mtx;
Bear bear;

void Bee()
{
    while (bearAlive)
    {
        mtx.lock();
        amountOfHoney += 5;
        cout << "ID thread = " << this_thread::get_id() << "\t Bee was created honey: " << amountOfHoney << endl;
        mtx.unlock();
        this_thread::sleep_for(chrono::milliseconds(rand() % 5000));
    }
}

int main()
{
    
    cout << "\t\tHoney into box: " << amountOfHoney << endl;
    this_thread::sleep_for(chrono::milliseconds(3000));
    
    thread bearThread(&Bear::eatOfHoney, bear, ref(amountOfHoney), ref(mtx));

    std::vector<std::future<void>> vector;    
        for (unsigned i = 0; i < 3; ++i)
        {
            vector.emplace_back(std::async(std::launch::async, Bee));
        }       
 
    bearThread.join();

    return 0;
}