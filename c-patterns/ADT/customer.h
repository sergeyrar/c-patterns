#ifndef _customer_h
#define _customer_h

typedef struct Customer *CustomerPtr;

/* Create new customer */
CustomerPtr createCustomer(const char *name, const char *address);

/* Destroy a given customer */
void destroyCustomer(CustomerPtr* customer);




#endif
