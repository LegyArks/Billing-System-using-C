#ifndef INVOICE_H
#define INVOICE_H

#include "billing.h"

void create_invoice(Invoice invoices[], int *invoice_count, Customer customers[], int customer_count, Item items[], int item_count);
void display_invoices(Invoice invoices[], int invoice_count);
void generate_report(Invoice invoices[], int invoice_count);

#endif // invoice.h
