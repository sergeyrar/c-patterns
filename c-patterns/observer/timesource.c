#include <stdio.h>
#include <string.h>
#include "timesource.h"
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

typedef struct Observer_list_node_s
{   
    TimeObserver observer;
    struct Observer_list_node_s* next;
}Observer_list_t;

static Observer_list_t* HEAD = NULL;


static char time_string[40];

static void* get_current_time(void *not_used)
{

    struct timeval tv;
    struct tm* ptm;
    long milliseconds;

    while(1)
    {
        gettimeofday(&tv, NULL);
        ptm = localtime (&(tv.tv_sec));
        /* Format the date and time, down to a single second. */
        strftime (time_string, sizeof (time_string), "%Y-%m-%d %H:%M:%S", ptm);
        /* Compute milliseconds from microseconds. */
        milliseconds = tv.tv_usec / 1000;
        /* Print the formatted time, in seconds, followed by a decimal point
           and the milliseconds. */
        sprintf(time_string, "%s.%03ld;", time_string, milliseconds);
    }

    return NULL;
}





static void* report_time(void *not_used)
{
    while(1)
    {
        Observer_list_t* node_ptr = HEAD;
        while(node_ptr)
        {
            node_ptr->observer.notification_function(node_ptr->observer.instance, time_string);
            node_ptr = node_ptr->next;
        }
        sleep(1);
    }

    return NULL;
}

int start()
{
    int ret;
    pthread_t update_users, get_time;

    if ((ret = pthread_create(&update_users, NULL, report_time, NULL)) < 0)
    {
        fprintf(stderr,"Failed to create update_users thread\n");
    }

    if ((ret = pthread_create(&get_time, NULL, get_current_time, NULL)) < 0)
    {
        fprintf(stderr,"Failed to create update_users thread\n");
    }
    
    while (1)
    {
        sleep(100);
    }

    return 0;
}


static void add_node(TimeObserver observer)
{
    static int first_invocation = 1;
    Observer_list_t* node_ptr = HEAD;
    Observer_list_t* new_node;
    
    new_node = malloc(sizeof(Observer_list_t));
    new_node->observer = observer;
    new_node->next = NULL;

    if (HEAD == NULL)
    {   
        HEAD = new_node;
    }
    else
    {
        while(node_ptr->next)
            node_ptr = node_ptr->next;

        node_ptr->next = new_node;
    }


    if (first_invocation)
    {
        start();
        first_invocation = 0;
    }

}

static void remove_node(TimeObserver observer)
{
    Observer_list_t* node_ptr = HEAD;
    Observer_list_t* temp;
    
    if(HEAD == NULL)
        return;

    if(!memcmp(&HEAD->observer, &observer, sizeof(observer)))
    {   
        node_ptr = HEAD->next;
        free(HEAD);
        HEAD = node_ptr;
    }
    else
    {
        do
        {
            if(!memcmp(&node_ptr->next->observer, &observer, sizeof(observer)))
            {
                temp = node_ptr->next;
                node_ptr->next = temp->next;
                free(temp);
            }
        }while(node_ptr->next != NULL);
    }
}





void attach(const TimeObserver observer)
{
    add_node(observer);
}


void detach(const TimeObserver observer)
{
    remove_node(observer);
}

