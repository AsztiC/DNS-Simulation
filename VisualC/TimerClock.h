#include <iostream>
#include <chrono>
#include <thread>
#include <assert.h>

class TimerClock
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    std::chrono::steady_clock::time_point stop;

public:
    long int elapsed() {
        stop = std::chrono::steady_clock::now();
        //https://stackoverflow.com/questions/54287779/stdchronomilliseconds-count-returns-in-microseconds
        return std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count();
    }
    void reset() {
        start = std::chrono::steady_clock::now();
    }


};

