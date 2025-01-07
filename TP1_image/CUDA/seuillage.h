
// #define SEUILLAGE_H
// #ifndef SEUILLAGE_H

// includes, system
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_I 960
#define SIZE_J 1280

#define BLOCK_SIZE 16

// Prototype
void runTest(int argc, char** argv);
extern "C" void seuillage_C_ij(float reference[][SIZE_J][SIZE_I],
                               float idata[][SIZE_J][SIZE_I]);
extern "C" void seuillage_C_ji(float reference[][SIZE_J][SIZE_I],
                               float idata[][SIZE_J][SIZE_I]);

// #endif
