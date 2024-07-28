#ifndef ITEM_H
#define ITEM_H

#include "billing.h"

void add_item(Item items[], int *item_count);
void display_items(Item items[], int item_count);
void edit_item(Item items[], int item_count);
void delete_item(Item items[], int *item_count);

#endif // item.h
