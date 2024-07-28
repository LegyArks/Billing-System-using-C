#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include "customer.h"
#include "item.h"
#include "invoice.h"

void save_customers(Customer customers[], int customer_count);
void load_customers(Customer customers[], int *customer_count);

void save_items(Item items[], int item_count);
void load_items(Item items[], int *item_count);

void save_invoices(Invoice invoices[], int invoice_count);
void load_invoices(Invoice invoices[], int *invoice_count);

#endif // PERSISTENCE_H
