#pragma once
#include <chrono>
#include "all.h"

class Timer {
public:
    // �������i�Q�[���N�����Ɉ�x�Ăԁj
    void initialize();

    // ���t���[���Ăԁi���ԍX�V�j
    void update();

    // �O�t���[���Ƃ̌o�ߎ��ԁi�b�j
    float getDeltaTime() const;

    // ���݂�FPS
    float getFPS() const;

    // �o�ߎ��ԁi�Q�[���J�n����̍��v�j
    float getTotalTime() const;

    // �V���O���g���C���X�^���X�擾
    static Timer* getInstance();

private:
    Timer() = default;  // �V���O���g���p
    ~Timer() = default;

    std::chrono::steady_clock::time_point prev_time;
    std::chrono::steady_clock::time_point start_time;

    float delta_time = 0.0f;
    float total_time = 0.0f;
    float fps = 0.0f;
};