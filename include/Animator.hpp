//
// Created by Kyle Flynn on 10/5/2018.
//

#ifndef CIS_343_02_ANIMATOR_H
#define CIS_343_02_ANIMATOR_H

#include <SFML/Graphics.hpp>

class Animator {
public:
    void init(int start, int end, int& ptr, float duration);
    void run(sf::Clock& clock);
    void setUpdateInterval(float interval);
private:
    void calculateIncrement();

    int start;
    int end;
    int increment;
    int* ptr;
    float duration;
    float timeElapsed;
    float lastTime;
    float updateInterval;
};

#endif //CIS_343_02_ANIMATOR_H
