#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Content {
    char title[100];
    double rating;
    int runtime; // in minutes
    char encodingFormats[100];
};

struct UserProfile {
    double* engagementScores;  
    char username[100];
};

struct DevicePreferences {
    int* resolution; 
    char** playbackHistory;
    double* bandwidthUsage;
};

void initializeUserProfiles(struct UserProfile** userProfiles, int numUsers, int numCategories) {
    for (int i = 0; i < numUsers; i++) {
        userProfiles[i] = (struct UserProfile*)malloc(sizeof(struct UserProfile));
        userProfiles[i]->engagementScores = (double*)malloc(numCategories * sizeof(double));
        printf("Enter username for user %d: ", i + 1);
        scanf("%s", userProfiles[i]->username);

        for (int j = 0; j < numCategories; j++) {
            printf("Enter engagement score for category %d: ", j + 1);
            scanf("%lf", &userProfiles[i]->engagementScores[j]);
        }
    }
}

void initializeContentMetadata(struct Content*** contentMetadata, int numCategories, int numContents) {
    for (int i = 0; i < numCategories; i++) {
        contentMetadata[i] = (struct Content**)malloc(numContents * sizeof(struct Content*));
        for (int j = 0; j < numContents; j++) {
            contentMetadata[i][j] = (struct Content*)malloc(sizeof(struct Content));
            printf("Enter title for content %d in category %d: ", j + 1, i + 1);
            getchar();  
            fgets(contentMetadata[i][j]->title, 100, stdin);
            contentMetadata[i][j]->title[strcspn(contentMetadata[i][j]->title, "\n")] = '\0'; 
            printf("Enter rating for %s: ", contentMetadata[i][j]->title);
            scanf("%lf", &contentMetadata[i][j]->rating);
            printf("Enter runtime (in minutes) for %s: ", contentMetadata[i][j]->title);
            scanf("%d", &contentMetadata[i][j]->runtime);
            printf("Enter encoding format for %s: ", contentMetadata[i][j]->title);
            getchar(); 
            fgets(contentMetadata[i][j]->encodingFormats, 100, stdin);
            contentMetadata[i][j]->encodingFormats[strcspn(contentMetadata[i][j]->encodingFormats, "\n")] = '\0'; 
        }
    }
}

void initializeDevicePreferences(struct DevicePreferences** devicePreferences, int numUsers, int numDevices) {
    for (int i = 0; i < numUsers; i++) {
        devicePreferences[i] = (struct DevicePreferences*)malloc(sizeof(struct DevicePreferences));
        devicePreferences[i]->resolution = (int*)malloc(numDevices * sizeof(int));
        devicePreferences[i]->playbackHistory = (char**)malloc(numDevices * sizeof(char*));
        devicePreferences[i]->bandwidthUsage = (double*)malloc(numDevices * sizeof(double));

        for (int j = 0; j < numDevices; j++) {
            devicePreferences[i]->playbackHistory[j] = (char*)malloc(100 * sizeof(char));

            printf("Enter resolution preference for device %d: ", j + 1);
            scanf("%d", &devicePreferences[i]->resolution[j]);
            printf("Enter playback history for device %d: ", j + 1);
            getchar(); 
            fgets(devicePreferences[i]->playbackHistory[j], 100, stdin);
            devicePreferences[i]->playbackHistory[j][strcspn(devicePreferences[i]->playbackHistory[j], "\n")] = '\0'; 
            printf("Enter bandwidth usage for device %d: ", j + 1);
            scanf("%lf", &devicePreferences[i]->bandwidthUsage[j]);
        }
    }
}

int main() {
    int numUsers, numCategories, numContents, numDevices;

    printf("Enter number of users: ");
    scanf("%d", &numUsers);
    printf("Enter number of content categories: ");
    scanf("%d", &numCategories);
    printf("Enter number of contents per category: ");
    scanf("%d", &numContents);
    printf("Enter number of devices per user: ");
    scanf("%d", &numDevices);

    struct UserProfile** userProfiles = (struct UserProfile**)malloc(numUsers * sizeof(struct UserProfile*));
    struct Content*** contentMetadata = (struct Content***)malloc(numCategories * sizeof(struct Content**));
    struct DevicePreferences** devicePreferences = (struct DevicePreferences**)malloc(numUsers * sizeof(struct DevicePreferences*));

    initializeUserProfiles(userProfiles, numUsers, numCategories);
    initializeContentMetadata(contentMetadata, numCategories, numContents);
    initializeDevicePreferences(devicePreferences, numUsers, numDevices);

    for (int i = 0; i < numUsers; i++) {
        printf("User %d: %s\n", i + 1, userProfiles[i]->username);
        for (int j = 0; j < numCategories; j++) {
            printf("Engagement score for category %d: %.2f\n", j + 1, userProfiles[i]->engagementScores[j]);
        }
    }

    for (int i = 0; i < numUsers; i++) {
        free(userProfiles[i]->engagementScores);
        free(userProfiles[i]);
    }
    free(userProfiles);

    for (int i = 0; i < numCategories; i++) {
        for (int j = 0; j < numContents; j++) {
            free(contentMetadata[i][j]);
        }
        free(contentMetadata[i]);
    }
    free(contentMetadata);

    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numDevices; j++) {
            free(devicePreferences[i]->playbackHistory[j]);
        }
        free(devicePreferences[i]->resolution);
        free(devicePreferences[i]->playbackHistory);
        free(devicePreferences[i]->bandwidthUsage);
        free(devicePreferences[i]);
    }
    free(devicePreferences);

    return 0;
}
