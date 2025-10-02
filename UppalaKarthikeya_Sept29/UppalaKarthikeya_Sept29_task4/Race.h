#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <cstdlib>
#include <ctime>

const int TRACK_LENGTH = 70;

// Functions to move tortoise and hare
void moveTortoise(int* tortoisePosition);
void moveHare(int* harePosition);

// Function to print race track
void printRaceTrack(int tortoisePosition, int harePosition);

#endif
