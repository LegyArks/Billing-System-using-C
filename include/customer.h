#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "billing.h"

void add_customer(Customer customers[], int *customer_count);
void display_customers(Customer customers[], int customer_count);
void edit_customer(Customer customers[], int customer_count);
void delete_customer(Customer customers[], int *customer_count);

#endif // customer.h
