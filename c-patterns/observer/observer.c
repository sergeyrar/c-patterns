#include "timesource.h"
#include "timeobserver.h" // API towards clock source
#include "time_srv.h"     // API towards clock clients
#include <assert.h>
#include <stdlib.h>

typedef char* Display;
static display_func run_in_client;




struct DigitalStopWatch
{
    char watch_name[30];
    Display watchDisplay;  
};

void register_clock(display_func callback)
{
    run_in_client = callback;
}

static void changedTime(void* instance, void* newTime)
{
    DigitalStopWatchPtr digitalWatch = instance;
    assert(NULL != digitalWatch);

    run_in_client(digitalWatch, newTime);
}





DigitalStopWatchPtr createDigitalWatch(void)
{
    DigitalStopWatchPtr watch = malloc(sizeof *watch);

    if (NULL != watch)
    {
        TimeObserver observer = {0};
        observer.instance = watch;
        observer.notification_function = changedTime;

        attach(observer);
    }

    return watch;
}


void destroyDigitalWatch(DigitalStopWatchPtr watch)
{
    TimeObserver observer = {0};
    observer.instance = watch;
    observer.notification_function = changedTime;

    detach(observer);
    free(watch);
}
