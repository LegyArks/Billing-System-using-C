#ifndef BILLING_H
#define BILLING_H

#define MAX_customers 100
#define MAX_items 100
#define MAX_invoices 100

typedef struct {
    int id;
    char name[50];
    char phone[15];
} Customer;

typedef struct {
    int id;
    char name[50];
    float price;
} Item;

typedef struct {
    int id;
    int customer_id;
    int item_id;
    int quantity;
    float total_price;
} Invoice;

#endif // billing.h
