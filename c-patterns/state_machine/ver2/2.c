#include <stdio.h>

typedef enum
{
    stopped,
    started
} State;

typedef enum
{
    stopEvent,
    startEvent
} Event;

#define NO_OF_STATES 2
#define NO_OF_EVENTS 2

static State TransitionTable[NO_OF_STATES][NO_OF_EVENTS] = {
    {   stopped, started },
    {   stopped, started } };

void startWatch(DigitalStopWatch instance)
{
    const State currentState = instance->state;
    instance->state = TransitionTable[currentState][startEvent];
}

void stopWatch(DigitalStopWatch instance)
{
    const State currentState = instance->state;
    instance->state = TransitionTable[currentState][stopEvent];
}
