#include "customer.h"
#include <stdio.h>




int main()
{
    customerPtr customer1, customer2, customer3;
    int x = 100;
    int shipping = 10;

    customer1 = createBronzeCustomer("Johnny", "Ashdod");
    customer2 = createSilverCustomer("Johnny", "Ashdod");
    customer3 = createGoldCustomer("Johnny", "Ashdod");

    printf("C1: Original price was %d + %d shipping, after discount %.2f\n",
            x, shipping, placeOrder(customer1, x, shipping));

    printf("C2: Original price was %d + %d shipping, after discount %.2f\n",
            x, shipping, placeOrder(customer2, x, shipping));

    printf("C3: Original price was %d + %d shipping, after discount %.2f\n",
            x, shipping, placeOrder(customer3, x, shipping));
    return 0;
}
