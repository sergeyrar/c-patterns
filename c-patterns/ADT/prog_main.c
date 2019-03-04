#include "customer.h"
#include <stdio.h>



int main()
{
    CustomerPtr customer1;

    printf("address of customer1 before creation is ox%p\n", customer1);
    customer1 = createCustomer("Jhonny", "Ashdod");
    printf("address of customer1 after creation is ox%p\n", customer1);

    destroyCustomer(&customer1);

    printf("address of customer1 is ox%p\n", customer1);
    /* TODO: try to print data of CustomerPtr */

    return 0;
}
