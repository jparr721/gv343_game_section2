//
// Created by Kyle Flynn on 10/5/2018.
//

#include <cmath>
#include <iostream>
#include "Animator.hpp"

void Animator::init(int start, int end, int &ptr, float duration) {
    this->start = start;
    this->end = end;
    this->ptr = &ptr;
    this->duration = duration;
    this->timeElapsed = 0.0f;
    this->updateInterval = 0.1f;
    this->calculateIncrement();
}

void Animator::setUpdateInterval(float interval) {
    this->updateInterval = interval;
    this->calculateIncrement();
}

void Animator::run(sf::Clock& clock) {
    if (this->timeElapsed > this->updateInterval) {
        this->timeElapsed = 0.0f;
        this->lastTime = clock.getElapsedTime().asSeconds();
        if (this->start > this->end) {
            // If we want to end less than where we started.
            if (*this->ptr > this->end) {
                *this->ptr += this->increment;
            } else {
                *this->ptr = this->end;
            }
        } else {
            // If we want to end more than where we started.
            if (*this->ptr < this->end) {
                *this->ptr += this->increment;
            } else {
                std::cout << "Stopping!" << std::endl;
                *this->ptr = this->end;
            }
        }
        std::cout << *this->ptr << std::endl;
    } else {
        this->timeElapsed = clock.getElapsedTime().asSeconds() - lastTime;
    }
}

void Animator::calculateIncrement() {
    // First, get the distance we need to cover.
    int difference = std::abs(this->start - this->end);

    // Next, calculate total cycles from 0 to the end duration, using the update interval.
    auto cycles = (int) (this->duration / this->updateInterval);

    // Finally, calculate the proportion of cycles to the total distance required to travel.
    this->increment = difference / cycles;
    std::cout << difference << " | " << cycles << " | " << this->increment << std::endl;
}