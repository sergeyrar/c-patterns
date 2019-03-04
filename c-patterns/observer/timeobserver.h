#ifndef _TIME_OBSERVER_H
#define _TIME_OBSERVER_H


typedef void (*ChageTimeNotification)(void* instance, void* newTime);

typedef struct
{
    void* instance;
    ChageTimeNotification notification_function;
}TimeObserver;







#endif
