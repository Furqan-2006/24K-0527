#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*** initializeInventory(int* numSpecies) {
    printf("Enter the number of species: ");
    scanf("%d", numSpecies);

    char*** inventory = (char***)malloc(*numSpecies * sizeof(char**));
    for (int i = 0; i < *numSpecies; i++) {
        inventory[i] = NULL; 
    }
    return inventory;
}

void addSupplies(char*** inventory, int speciesIndex, int* numSupplies) {
    printf("Enter the number of supplies for species %d: ", speciesIndex + 1);
    scanf("%d", numSupplies);

    inventory[speciesIndex] = (char**)malloc(*numSupplies * sizeof(char*));
    printf("Enter supplies for species %d:\n", speciesIndex + 1);
    for (int i = 0; i < *numSupplies; i++) {
        char buffer[256];
        printf("Supply %d: ", i + 1);
        getchar(); 
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 
        inventory[speciesIndex][i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(inventory[speciesIndex][i], buffer);
    }
}

void updateSupply(char*** inventory, int speciesIndex, int supplyIndex) {
    printf("Enter new name for supply %d of species %d: ", supplyIndex + 1, speciesIndex + 1);
    char buffer[256];
    getchar(); 
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = '\0'; 

    free(inventory[speciesIndex][supplyIndex]);
    inventory[speciesIndex][supplyIndex] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
    strcpy(inventory[speciesIndex][supplyIndex], buffer);

    printf("Supply updated successfully.\n");
}

void removeSpecies(char*** inventory, int* numSpecies, int speciesIndex, int* suppliesCount) {
    for (int i = 0; i < suppliesCount[speciesIndex]; i++) {
        free(inventory[speciesIndex][i]);
    }
    free(inventory[speciesIndex]);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        inventory[i] = inventory[i + 1];
        suppliesCount[i] = suppliesCount[i + 1];
    }
    (*numSpecies)--;

    printf("Species removed successfully.\n");
}

void displayInventory(char*** inventory, int numSpecies, int* suppliesCount) {
    printf("\n--- Inventory ---\n");
    for (int i = 0; i < numSpecies; i++) {
        printf("Species %d supplies:\n", i + 1);
        for (int j = 0; j < suppliesCount[i]; j++) {
            printf("  - %s\n", inventory[i][j]);
        }
    }
    printf("------------------\n");
}

int main() {
    int numSpecies;
    char*** inventory = initializeInventory(&numSpecies);

    int* suppliesCount = (int*)calloc(numSpecies, sizeof(int));
    int choice;
    do {
        printf("\n--- Pets in Heart Inventory System ---\n");
        printf("1. Add Supplies for a Species\n");
        printf("2. Update a Supply\n");
        printf("3. Remove a Species\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int speciesIndex;
            printf("Enter species index (1 to %d): ", numSpecies);
            scanf("%d", &speciesIndex);
            speciesIndex--;
            addSupplies(inventory, speciesIndex, &suppliesCount[speciesIndex]);
            break;
        }
        case 2: {
            int speciesIndex, supplyIndex;
            printf("Enter species index (1 to %d): ", numSpecies);
            scanf("%d", &speciesIndex);
            speciesIndex--;
            printf("Enter supply index (1 to %d): ", suppliesCount[speciesIndex]);
            scanf("%d", &supplyIndex);
            supplyIndex--;
            updateSupply(inventory, speciesIndex, supplyIndex);
            break;
        }
        case 3: {
            int speciesIndex;
            printf("Enter species index (1 to %d) to remove: ", numSpecies);
            scanf("%d", &speciesIndex);
            speciesIndex--;
            removeSpecies(inventory, &numSpecies, speciesIndex, suppliesCount);
            break;
        }
        case 4:
            displayInventory(inventory, numSpecies, suppliesCount);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    for (int i = 0; i < numSpecies; i++) {
        for (int j = 0; j < suppliesCount[i]; j++) {
            free(inventory[i][j]);
        }
        free(inventory[i]);
    }
    free(inventory);
    free(suppliesCount);

    return 0;
}
