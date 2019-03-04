#ifndef _CLIENT_H
#define _CLIENT_H

typedef struct customer* customerPtr; /*TODO: why doesn't customer_t work? */


customerPtr createBronzeCustomer(const char* name, const char *address);


customerPtr createSilverCustomer(const char* name, const char *address);


customerPtr createGoldCustomer(const char* name, const char *address);



double placeOrder(customerPtr customer, double amount, double shipping);

#endif
