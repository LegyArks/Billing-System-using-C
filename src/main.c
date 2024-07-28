#include <stdio.h>
#include "../include/billing.h"
#include "../include/customer.h"
#include "../include/item.h"
#include "../include/invoice.h"
#include "../include/persistence.h"

// Function prototypes for persistence
void save_data(Customer customers[], int customer_count, Item items[], int item_count, Invoice invoices[], int invoice_count);
void load_data(Customer customers[], int *customer_count, Item items[], int *item_count, Invoice invoices[], int *invoice_count);

int main() {
    Customer customers[MAX_customers];
    Item items[MAX_items];
    Invoice invoices[MAX_invoices];
    
    int customer_count = 0, item_count = 0, invoice_count = 0;
    int choice;

    load_data(customers, &customer_count, items, &item_count, invoices, &invoice_count);

    while (1) {
        printf("\nBilling System Menu:\n");
        printf("1. Add Customer\n");
        printf("2. Display Customers\n");
        printf("3. Edit Customer\n");
        printf("4. Delete Customer\n");
        printf("5. Add Item\n");
        printf("6. Display Items\n");
        printf("7. Edit Item\n");
        printf("8. Delete Item\n");
        printf("9. Create Invoice\n");
        printf("10. Display Invoices\n");
        printf("11. Generate Report\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_customer(customers, &customer_count);
                break;
            case 2:
                display_customers(customers, customer_count);
                break;
            case 3:
                edit_customer(customers, customer_count);
                break;
            case 4:
                delete_customer(customers, &customer_count);
                break;
            case 5:
                add_item(items, &item_count);
                break;
            case 6:
                display_items(items, item_count);
                break;
            case 7:
                edit_item(items, item_count);
                break;
            case 8:
                delete_item(items, &item_count);
                break;
            case 9:
                create_invoice(invoices, &invoice_count, customers, customer_count, items, item_count);
                break;
            case 10:
                display_invoices(invoices, invoice_count);
                break;
            case 11:
                generate_report(invoices, invoice_count);
                break;
            case 0:
                save_data(customers, customer_count, items, item_count, invoices, invoice_count);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

void save_data(Customer customers[], int customer_count, Item items[], int item_count, Invoice invoices[], int invoice_count) {
    save_customers(customers, customer_count);
    save_items(items, item_count);
    save_invoices(invoices, invoice_count);
}

void load_data(Customer customers[], int *customer_count, Item items[], int *item_count, Invoice invoices[], int *invoice_count) {
    load_customers(customers, customer_count);
    load_items(items, item_count);
    load_invoices(invoices, invoice_count);
}

// to run this code
// gcc -o billing_system src/main.c src/customer.c src/item.c src/invoice.c src/persistence.c
// ./billing_system