#include <stdio.h>
#include "CustomerStrategy.h"
#include "customer.h"
#include <stdlib.h>
#include <string.h>



typedef struct
{
    double amount;
    double shipping;
}order_t;

typedef struct customer
{
    const char* name;
    const char* address;
    order_t order;
    customerPriceStrategy priceStrategy;
}customer_t;


static int is_legal(customerPtr customer)
{
    /*
    switch(customer->priceStrategy)
    {
        case bronzePriceStrategy:
        case silverPriceStrategy:
        case goldPriceStrategy:
            return 1;

        default: return 0;
    }
    */

    return 1;
}


static customerPtr createCustomer(const char* name, const char *address, customerPriceStrategy priceStrategy)
#ifndef _CLIENT_H
#define _CLIENT_H

typedef struct customer* customerPtr; /*TODO: why doesn't customer_t work? */


customerPtr createBronzeCustomer(const char* name, const char *address);


customerPtr createSilverCustomer(const char* name, const char *address);


customerPtr createGoldCustomer(const char* name, const char *address);



double placeOrder(customerPtr customer, double amount, double shipping);

#endif
{   
    customerPtr customer = malloc(sizeof(customer_t));
    if(customer)
    {
        customer->name          = strdup(name);
        customer->address       = strdup(address);
        customer->priceStrategy = priceStrategy; 
    }

    return customer;
}




double placeOrder(customer_t* customer, double amount, double shipping)
{
    customer->order.amount   = amount;
    customer->order.shipping = shipping;

    if(is_legal(customer))
        return customer->priceStrategy(customer->order.amount, customer->order.shipping);

    return 0;
}


customerPtr createBronzeCustomer(const char* name, const char *address)
{
    return createCustomer(name, address, bronzePriceStrategy);
}

customerPtr createSilverCustomer(const char* name, const char *address)
{
    return createCustomer(name, address, silverPriceStrategy);
}

customerPtr createGoldCustomer(const char* name, const char *address)
{
    return createCustomer(name, address, goldPriceStrategy);
}


/*
void changeCategory(customerPtr customer, customerPriceStrategy newPriceStrategy)
{
    if(is_legal(customer))
    {
        customer->priceStrategy = newPriceStrategy;
    }

}
*/
