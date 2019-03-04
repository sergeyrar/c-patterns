#include "CustomerStrategy.h"
#include <stdio.h>


double bronzePriceStrategy(double amount, double shipping)
{
    return (amount + shipping);
}
double silverPriceStrategy(double amount, double shipping)
{
    return (amount * 0.90 + shipping);
}
double goldPriceStrategy(double amount, double shipping)
{
    return (amount * 0.90);
}

