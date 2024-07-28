#include <stdio.h>
#include <string.h>
#include "../include/customer.h"

void add_customer(Customer customers[], int *customer_count) {
    Customer new_customer;
    new_customer.id = *customer_count + 1;
    printf("Enter customer name: ");
    scanf("%s", new_customer.name);
    printf("Enter customer phone: ");
    scanf("%s", new_customer.phone);
    customers[*customer_count] = new_customer;
    (*customer_count)++;
}

void display_customers(Customer customers[], int customer_count) {
    for (int i = 0; i < customer_count; i++) {
        printf("ID: %d, Name: %s, Phone: %s\n", customers[i].id, customers[i].name, customers[i].phone);
    }
}

void edit_customer(Customer customers[], int customer_count) {
    int id;
    printf("Enter customer ID to edit: ");
    scanf("%d", &id);
    for (int i = 0; i < customer_count; i++) {
        if (customers[i].id == id) {
            printf("Enter new customer name: ");
            scanf("%s", customers[i].name);
            printf("Enter new customer phone: ");
            scanf("%s", customers[i].phone);
            printf("Customer updated successfully.\n");
            return;
        }
    }
    printf("Customer not found.\n");
}

void delete_customer(Customer customers[], int *customer_count) {
    int id;
    printf("Enter customer ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < *customer_count; i++) {
        if (customers[i].id == id) {
            for (int j = i; j < *customer_count - 1; j++) {
                customers[j] = customers[j + 1];
            }
            (*customer_count)--;
            printf("Customer deleted successfully.\n");
            return;
        }
    }
    printf("Customer not found.\n");
}
