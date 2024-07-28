#include <stdio.h>
#include "../include/item.h"

void add_item(Item items[], int *item_count) {
    int num_items;
    char add_more;

    do {
        printf("How many items do you want to add? ");
        scanf("%d", &num_items);

        for (int i = 0; i < num_items; i++) {
            if (*item_count >= MAX_items) {
                printf("Item limit reached. Cannot add more items.\n");
                return;
            }

            Item new_item;
            new_item.id = *item_count + 1;

            printf("Enter name of item %d: ", new_item.id);
            scanf("%s", new_item.name);

            printf("Enter price of item %d: ", new_item.id);
            scanf("%f", &new_item.price);

            items[*item_count] = new_item;
            (*item_count)++;
        }

        printf("Items added successfully.\n");
        printf("Do you want to add more items? (y/n): ");
        scanf(" %c", &add_more); // Notice the space before %c to consume any leftover newline character

    } while (add_more == 'y' || add_more == 'Y');
}

void display_items(Item items[], int item_count) {
    printf("%-5s %-20s %-10s\n", "ID", "Name", "Price");
    for (int i = 0; i < item_count; i++) {
        printf("%-5d %-20s %-10.2f\n", items[i].id, items[i].name, items[i].price);
    }
}

void edit_item(Item items[], int item_count) {
    int id;
    printf("Enter item ID to edit: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < item_count; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    printf("Enter new name for item %d: ", id);
    scanf("%s", items[index].name);
    printf("Enter new price for item %d: ", id);
    scanf("%f", &items[index].price);

    printf("Item updated successfully.\n");
}

void delete_item(Item items[], int *item_count) {
    int id;
    printf("Enter item ID to delete: ");
    scanf("%d", &id);

    int index = -1;
    for (int i = 0; i < *item_count; i++) {
        if (items[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Item not found.\n");
        return;
    }

    for (int i = index; i < *item_count - 1; i++) {
        items[i] = items[i + 1];
    }

    (*item_count)--;
    printf("Item deleted successfully.\n");
}
