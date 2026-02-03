
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char location[50];
} Supplier;

typedef struct {
    int id;
    char name[50];
    float price;
    Supplier *supplier; 
} Product;

Supplier* createSupplier(const char *name, const char *location) {
    Supplier *new_supplier = (Supplier *)malloc(sizeof(Supplier));
    
    if (new_supplier == NULL) {
        printf("Memory allocation failed for Supplier!\n");
        return NULL;
    }
    
    strcpy(new_supplier->name, name);
    strcpy(new_supplier->location, location);
    
    return new_supplier;
}

Product* createProduct(int id, const char *name, float price, Supplier *supplier) {
    Product *new_product = (Product *)malloc(sizeof(Product));
    
    if (new_product == NULL) {
        printf("Memory allocation failed for Product!\n");
        return NULL;
    }
    
    new_product->id = id;
    strcpy(new_product->name, name);
    new_product->price = price;
    new_product->supplier = supplier;  
    
    return new_product;
}

void displayProduct(Product *product) {
    if (product == NULL) {
        printf("Product is NULL!\n");
        return;
    }
    
    printf("\n========================================\n");
    printf("PRODUCT DETAILS:\n");
    printf("========================================\n");
    printf("Product ID: %d\n", product->id);
    printf("Product Name: %s\n", product->name);
    printf("Price: Rs. %.2f\n", product->price);
    
    if (product->supplier != NULL) {
        printf("\nSUPPLIER INFORMATION:\n");
        printf("----------------------------------------\n");
        printf("Supplier Name: %s\n", product->supplier->name);
        printf("Location: %s\n", product->supplier->location);
    } else {
        printf("No supplier assigned!\n");
    }
    printf("========================================\n");
}

void freeProduct(Product *product) {
    if (product != NULL) {
        if (product->supplier != NULL) {
            free(product->supplier);
        }
        free(product);
    }
}

void updateProductPrice(Product *product, float new_price) {
    if (product == NULL) {
        printf("Product is NULL!\n");
        return;
    }
    product->price = new_price;
    printf("Product price updated successfully!\n");
}

int main() {
    printf("\n========== PRODUCT & SUPPLIER MANAGEMENT ==========\n");
    
    Supplier *supplier1 = createSupplier("TechCorp Industries", "Mumbai");
    Supplier *supplier2 = createSupplier("Global Electronics", "Delhi");
    Supplier *supplier3 = createSupplier("Premium Parts Co", "Bangalore");
    
    Product *product1 = createProduct(101, "Laptop", 50000.00, supplier1);
    Product *product2 = createProduct(102, "Keyboard", 2000.00, supplier2);
    Product *product3 = createProduct(103, "Monitor", 15000.00, supplier1);
    Product *product4 = createProduct(104, "Headphones", 3500.00, supplier3);
    
    displayProduct(product1);
    displayProduct(product2);
    displayProduct(product3);
    displayProduct(product4);
    
    printf("\n========== UPDATING PRODUCT PRICE ==========\n");
    updateProductPrice(product1, 52000.00);
    printf("Updated Product:\n");
    displayProduct(product1);
    
    printf("\n========== POINTER OPERATIONS ==========\n");
    printf("Product 2 Address: %p\n", (void *)product2);
    printf("Product 2 Supplier Address: %p\n", (void *)product2->supplier);
    printf("Product 2 Name: %s\n", product2->name);
    printf("Product 2 Supplier Name: %s\n", product2->supplier->name);
    printf("Product 2 Supplier Location: %s\n", product2->supplier->location);
    
    printf("\n========== FREEING MEMORY ==========\n");
    freeProduct(product1);
    freeProduct(product2);
    freeProduct(product3);
    freeProduct(product4);
    printf("All memory freed successfully!\n");
    
    printf("\n========== PROGRAM COMPLETED ==========\n\n");
    
    return 0;
}
