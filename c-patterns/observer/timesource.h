#ifndef _TIME_SOURCE_H
#define _TIME_SOURCE_H

#include "timeobserver.h"

void attach(const TimeObserver observer);
void detach(const TimeObserver observer);



#endif
