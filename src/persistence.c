#include <stdio.h>
#include "../include/billing.h"

void save_customers(Customer customers[], int customer_count) {
    FILE *file = fopen("customers.dat", "wb");
    if (file) {
        fwrite(&customer_count, sizeof(int), 1, file);
        fwrite(customers, sizeof(Customer), customer_count, file);
        fclose(file);
    } else {
        printf("Error saving customers.\n");
    }
}

void load_customers(Customer customers[], int *customer_count) {
    FILE *file = fopen("customers.dat", "rb");
    if (file) {
        fread(customer_count, sizeof(int), 1, file);
        fread(customers, sizeof(Customer), *customer_count, file);
        fclose(file);
    }
}

void save_items(Item items[], int item_count) {
    FILE *file = fopen("items.dat", "wb");
    if (file) {
        fwrite(&item_count, sizeof(int), 1, file);
        fwrite(items, sizeof(Item), item_count, file);
        fclose(file);
    } else {
        printf("Error saving items.\n");
    }
}

void load_items(Item items[], int *item_count) {
    FILE *file = fopen("items.dat", "rb");
    if (file) {
        fread(item_count, sizeof(int), 1, file);
        fread(items, sizeof(Item), *item_count, file);
        fclose(file);
    }
}

void save_invoices(Invoice invoices[], int invoice_count) {
    FILE *file = fopen("invoices.dat", "wb");
    if (file) {
        fwrite(&invoice_count, sizeof(int), 1, file);
        fwrite(invoices, sizeof(Invoice), invoice_count, file);
        fclose(file);
    } else {
        printf("Error saving invoices.\n");
    }
}

void load_invoices(Invoice invoices[], int *invoice_count) {
    FILE *file = fopen("invoices.dat", "rb");
    if (file) {
        fread(invoice_count, sizeof(int), 1, file);
        fread(invoices, sizeof(Invoice), *invoice_count, file);
        fclose(file);
    }
}
