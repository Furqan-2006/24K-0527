#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
};

struct Crop {
    char cropType[100];
    char growthStage[100];
    float expectedYield;
    struct Weather* forecast; 
};

struct Equipment {
    char name[100];
    char status[100];
    float fuelLevel;
    char activitySchedule[100];
};

struct Sensor {
    float soilNutrients;
    float pHLevel;
    float pestActivity;
};

struct Field {
    char gpsCoordinates[100];
    float soilHealth;
    float moistureLevel;
    struct Crop* crops;           
    int numCrops;
    struct Equipment* equipment;
    int numEquipment;
    struct Sensor* sensors;
    int numSensors;
};

struct RegionalHub {
    struct Field* fields;
    int numFields;
    char aggregateData[100];
};

struct Field* initializeField(int numFields);
void displayFieldData(const struct Field* field);
void cleanupField(struct Field* field);

int main() {
    int numFields;
    printf("Enter the number of fields: ");
    scanf("%d", &numFields);

    struct Field* fields = initializeField(numFields);

    for (int i = 0; i < numFields; i++) {
        printf("\nField %d Details:\n", i + 1);
        displayFieldData(&fields[i]);
    }

    for (int i = 0; i < numFields; i++) {
        cleanupField(&fields[i]);
    }
    free(fields);

    return 0;
}

struct Field* initializeField(int numFields) {
    struct Field* fields = (struct Field*)malloc(numFields * sizeof(struct Field));
    for (int i = 0; i < numFields; i++) {
        printf("\nEnter details for Field %d:\n", i + 1);
        printf("GPS Coordinates: ");
        getchar(); 
        fgets(fields[i].gpsCoordinates, 100, stdin);
        fields[i].gpsCoordinates[strcspn(fields[i].gpsCoordinates, "\n")] = '\0'; 
        printf("Soil Health: ");
        scanf("%f", &fields[i].soilHealth);
        printf("Moisture Level: ");
        scanf("%f", &fields[i].moistureLevel);

        printf("Enter the number of crops for this field: ");
        scanf("%d", &fields[i].numCrops);
        fields[i].crops = (struct Crop*)malloc(fields[i].numCrops * sizeof(struct Crop));
        for (int j = 0; j < fields[i].numCrops; j++) {
            printf("  Crop %d Type: ", j + 1);
            getchar(); 
            fgets(fields[i].crops[j].cropType, 100, stdin);
            fields[i].crops[j].cropType[strcspn(fields[i].crops[j].cropType, "\n")] = '\0'; 
            printf("  Growth Stage: ");
            fgets(fields[i].crops[j].growthStage, 100, stdin);
            fields[i].crops[j].growthStage[strcspn(fields[i].crops[j].growthStage, "\n")] = '\0'; 
            printf("  Expected Yield: ");
            scanf("%f", &fields[i].crops[j].expectedYield);

            fields[i].crops[j].forecast = (struct Weather*)malloc(sizeof(struct Weather));
            printf("  Temperature: ");
            scanf("%f", &fields[i].crops[j].forecast->temperature);
            printf("  Rainfall: ");
            scanf("%f", &fields[i].crops[j].forecast->rainfall);
            printf("  Wind Speed: ");
            scanf("%f", &fields[i].crops[j].forecast->windSpeed);
        }

        printf("Enter the number of equipment for this field: ");
        scanf("%d", &fields[i].numEquipment);
        fields[i].equipment = (struct Equipment*)malloc(fields[i].numEquipment * sizeof(struct Equipment));
        for (int j = 0; j < fields[i].numEquipment; j++) {
            printf("  Equipment %d Name: ", j + 1);
            getchar(); // To clear the newline character
            fgets(fields[i].equipment[j].name, 100, stdin);
            fields[i].equipment[j].name[strcspn(fields[i].equipment[j].name, "\n")] = '\0'; // Remove newline
            printf("  Status: ");
            fgets(fields[i].equipment[j].status, 100, stdin);
            fields[i].equipment[j].status[strcspn(fields[i].equipment[j].status, "\n")] = '\0'; // Remove newline
            printf("  Fuel Level: ");
            scanf("%f", &fields[i].equipment[j].fuelLevel);
            printf("  Activity Schedule: ");
            getchar(); // To clear the newline character
            fgets(fields[i].equipment[j].activitySchedule, 100, stdin);
            fields[i].equipment[j].activitySchedule[strcspn(fields[i].equipment[j].activitySchedule, "\n")] = '\0'; // Remove newline
        }

        printf("Enter the number of sensors for this field: ");
        scanf("%d", &fields[i].numSensors);
        fields[i].sensors = (struct Sensor*)malloc(fields[i].numSensors * sizeof(struct Sensor));
        for (int j = 0; j < fields[i].numSensors; j++) {
            printf("  Sensor %d Soil Nutrients: ", j + 1);
            scanf("%f", &fields[i].sensors[j].soilNutrients);
            printf("  pH Level: ");
            scanf("%f", &fields[i].sensors[j].pHLevel);
            printf("  Pest Activity: ");
            scanf("%f", &fields[i].sensors[j].pestActivity);
        }
    }
    return fields;
}

void displayFieldData(const struct Field* field) {
    printf("GPS Coordinates: %s\n", field->gpsCoordinates);
    printf("Soil Health: %.2f\n", field->soilHealth);
    printf("Moisture Level: %.2f\n", field->moistureLevel);

    printf("Crops:\n");
    for (int i = 0; i < field->numCrops; i++) {
        printf("  Crop %d: %s, Growth Stage: %s, Expected Yield: %.2f\n", i + 1, field->crops[i].cropType,
               field->crops[i].growthStage, field->crops[i].expectedYield);
        printf("    Weather - Temperature: %.2f, Rainfall: %.2f, Wind Speed: %.2f\n",
               field->crops[i].forecast->temperature, field->crops[i].forecast->rainfall,
               field->crops[i].forecast->windSpeed);
    }

    printf("Equipment:\n");
    for (int i = 0; i < field->numEquipment; i++) {
        printf("  Equipment %d: %s, Status: %s, Fuel Level: %.2f, Activity Schedule: %s\n", i + 1, field->equipment[i].name,
               field->equipment[i].status, field->equipment[i].fuelLevel, field->equipment[i].activitySchedule);
    }

    printf("Sensors:\n");
    for (int i = 0; i < field->numSensors; i++) {
        printf("  Sensor %d: Soil Nutrients: %.2f, pH Level: %.2f, Pest Activity: %.2f\n", i + 1, field->sensors[i].soilNutrients,
               field->sensors[i].pHLevel, field->sensors[i].pestActivity);
    }
}

void cleanupField(struct Field* field) {
    for (int i = 0; i < field->numCrops; i++) {
        free(field->crops[i].forecast);
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
}
