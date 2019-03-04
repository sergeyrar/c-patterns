#include "customer.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct Customer
{   
    char* name;
    char* address;
    size_t n_orders;
    int orders[20];
};


CustomerPtr createCustomer(const char* name, const char* address)
{
    CustomerPtr customer = malloc(sizeof(struct Customer));
    if(customer)
    {   
        customer->name = strdup(name);
        customer->address = strdup(address);
    }
    
    printf("Allocated customer 0x%p with name:%s address:%s\n",
                (void*)customer, customer->name, customer->address);

    return customer;
}


void destroyCustomer(CustomerPtr *customer)
{
    if (*customer)
    {
        free((*customer)->name);
        free((*customer)->address);
        free(*customer);
        *customer = NULL;
    }
    printf("Cleared customer\n");
}
