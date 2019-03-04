#include <stdio.h>

typedef enum
{
    stopped,
    started
} State;


typedef struct DigitalStopWatch
{
    State state;
    int source;
    char *display;
}DigitalStopWatch;




void StartWatch(DigitalStopWatch *instance)
{
    switch(instance->state)
    {   
        case started:
            /*Already started -> Do nothing */
            break;
        case stopped:
            instance->state = started;
            break;
        default:
            printf("Error: no such state\n");
            break;
    }
}
    
void StopWatch(DigitalStopWatch *instance)
{
    switch(instance->state)
    {   
        case started:
            instance->state = stopped;
            break;
        case stopped:
            /*Already stopped -> Do nothing */
            break;
        default:
            printf("Error: no such state\n");
            break;
    }
}




int main()
{
    struct DigitalStopWatch watch1;
    watch1.state = stopped;

    printf("watch state is %d - should be 0\n", watch1.state);
    StartWatch(&watch1);
    printf("watch state is %d - should be 1\n", watch1.state);
    StartWatch(&watch1);
    printf("watch state is %d - should be 1\n", watch1.state);
    StopWatch(&watch1);
    printf("watch state is %d - should be 0\n", watch1.state);


    return 0;
}
