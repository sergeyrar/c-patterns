#ifndef _CUST_STRATEGY_
#define _CUST_STRATEGY_

double bronzePriceStrategy(double amount, double shipping);
double silverPriceStrategy(double amount, double shipping);
double goldPriceStrategy(double amount, double shipping);

typedef double (*customerPriceStrategy)(double amount, double shipping);

#endif
