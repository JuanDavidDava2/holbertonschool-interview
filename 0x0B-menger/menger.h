#ifndef MENGER_SPONGE_H
#define MENGER_SPONGE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void menger(int level);
char **startSponge(size_t size);
void closeSponge(char **sponge, size_t size);
void recordLevel(char **sponge, int level, size_t i, size_t j, short center,
                size_t limitI, size_t limitJ);
void printRecord(char **sponge, size_t size);

#endif