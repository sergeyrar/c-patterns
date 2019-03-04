#include "time_srv.h"
#include <stdio.h>
#include <unistd.h>


const char newTime[40];

void updateDisplay(void* digitalWatch, void* newTime)
{   
    if(digitalWatch == NULL || newTime == NULL)
    {
        printf("test\n");
    }
    DigitalStopWatchPtr watch_ptr = (DigitalStopWatchPtr)digitalWatch;
    char *newTime_ptr = (char *)newTime;
    printf("In update display callback function for digital stopwatch: %s \n", newTime_ptr);
}


int main()
{
    DigitalStopWatchPtr watch1 = NULL;
    register_clock(updateDisplay);
    watch1 = createDigitalWatch();
    updateDisplay(NULL, NULL);

    while(1)
    {
        sleep(10);
    }
}



