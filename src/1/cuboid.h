#ifndef CUBOID_H
#define CUBOID_H

#include "../utils.h"

double hypotenuse_of(long, long, long);
long area_of_rectangle(long, long, long);

bool cuboid_handler(const char[][MAX_LINE_LENGTH], const int,
                    const char[][MAX_LINE_LENGTH], char[]);

#endif
