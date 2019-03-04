#ifndef _TIME_SRV_H
#define _TIME_SRV_H


typedef struct DigitalStopWatch* DigitalStopWatchPtr;
typedef void (*display_func)(void* instance, void* data);



DigitalStopWatchPtr createDigitalWatch(void);

void destroyDigitalWatch(DigitalStopWatchPtr watch);

//void updateDisplay(DigitalStopWatchPtr watch, const char* newTime);

void register_clock(display_func callback);


#endif
