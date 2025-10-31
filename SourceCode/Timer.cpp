#include "all.h"

Timer* Timer::getInstance() {
    static Timer instance;
    return &instance;
}

void Timer::initialize() {
    start_time = std::chrono::steady_clock::now();
    prev_time = start_time;
    delta_time = 0.0f;
    total_time = 0.0f;
}

void Timer::update() {
    auto now = std::chrono::steady_clock::now();

    // åoâﬂïbêî
    delta_time = std::chrono::duration<float>(now - prev_time).count();
    total_time = std::chrono::duration<float>(now - start_time).count();

    // FPSåvéZ
    if (delta_time > 0.0f)
        fps = 1.0f / delta_time;
    else
        fps = 0.0f;

    prev_time = now;
}

float Timer::getDeltaTime() const {
    return delta_time;
}

float Timer::getFPS() const {
    return fps;
}

float Timer::getTotalTime() const {
    return total_time;
}
