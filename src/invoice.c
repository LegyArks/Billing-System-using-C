#include <stdio.h>
#include "../include/invoice.h"
#include "../include/customer.h"
#include "../include/item.h"

void create_invoice(Invoice invoices[], int *invoice_count, Customer customers[], int customer_count, Item items[], int item_count) {
    Invoice new_invoice;
    new_invoice.id = *invoice_count + 1;

    printf("Enter Customer ID: ");
    scanf("%d", &new_invoice.customer_id);

    // Check if customer exists
    int customer_index = -1;
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == new_invoice.customer_id) {
            customer_index = i;
            break;
        }
    }
    if (customer_index == -1) {
        printf("Customer not found.\n");
        return;
    }

    new_invoice.total_price = 0;

    char add_more;
    do {
        printf("Available items:\n");
        printf("%-5s %-20s %-10s\n", "ID", "Name", "Price");
        for (int i = 0; i < item_count; i++) {
            printf("%-5d %-20s %-10.2f\n", items[i].id, items[i].name, items[i].price);
        }

        printf("Enter Item ID: ");
        scanf("%d", &new_invoice.item_id);

        // Check if item exists
        int item_index = -1;
        for (int i = 0; i < item_count; i++) {
            if (items[i].id == new_invoice.item_id) {
                item_index = i;
                break;
            }
        }
        if (item_index == -1) {
            printf("Item not found.\n");
            return;
        }

        printf("Enter quantity: ");
        scanf("%d", &new_invoice.quantity);

        new_invoice.total_price += items[item_index].price * new_invoice.quantity;

        printf("Add another item? (y/n): ");
        scanf(" %c", &add_more); // Notice the space before %c to consume any leftover newline character

    } while (add_more == 'y' || add_more == 'Y');

    invoices[*invoice_count] = new_invoice;
    (*invoice_count)++;

    printf("Invoice created successfully.\n");
}

void display_invoices(Invoice invoices[], int invoice_count) {
    printf("%-5s %-12s %-8s %-8s %-12s\n", "ID", "Customer ID", "Item ID", "Quantity", "Total Price");
    for (int i = 0; i < invoice_count; i++) {
        printf("%-5d %-12d %-8d %-8d %-12.2f\n",
            invoices[i].id, invoices[i].customer_id, invoices[i].item_id, invoices[i].quantity, invoices[i].total_price);
    }
}

void generate_report(Invoice invoices[], int invoice_count) {
    float total_revenue = 0;
    for (int i = 0; i < invoice_count; i++) {
        total_revenue += invoices[i].total_price;
    }
    printf("Total Revenue: %.2f\n", total_revenue);
}
