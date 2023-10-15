#include <stdio.h>
#include <string.h>

// Define a structure to represent a task
struct Task {
    char name[50];
    int weight;
    double score; // Change data type to double
};

int main() {
    int numTasks;
    int numMandatoryTasks;
    int numAdvancedTasks;

    printf("If the Project has Advanced Tasks, enter 'yes' (without quotes); otherwise, enter 'no': ");
    char hasAdvanced[4];
    scanf("%s", hasAdvanced);

    if (strcmp(hasAdvanced, "yes") == 0) {
        printf("Enter the number of mandatory tasks: ");
        scanf("%d", &numMandatoryTasks);
        printf("Enter the number of advanced tasks: ");
        scanf("%d", &numAdvancedTasks);
        numTasks = numMandatoryTasks + numAdvancedTasks;
    } else {
        printf("Enter the number of mandatory tasks: ");
        scanf("%d", &numMandatoryTasks);
        numTasks = numMandatoryTasks;
        numAdvancedTasks = 0; // Initialize advanced tasks to 0
    }

    // Declare an array of tasks
    struct Task tasks[numTasks];

    // Input task weights and deadlines for mandatory tasks
    for (int i = 0; i < numMandatoryTasks; i++) {
        printf("Enter the weight of mandatory task %d: ", i);
        scanf("%d", &tasks[i].weight);

        int deadline;
        do {
            printf("Enter the deadline for mandatory task %d (1 for 100%, 2 for 65%, 3 for 50%): ", i);
            scanf("%d", &deadline);
            if (deadline < 1 || deadline > 3) {
                printf("Invalid deadline. Please enter 1, 2, or 3.\n");
            }
        } while (deadline < 1 || deadline > 3);

        switch (deadline) {
            case 1:
                tasks[i].score = tasks[i].weight;  // 100% of the weight
                break;
            case 2:
                tasks[i].score = 0.65 * tasks[i].weight;  // 65% of the weight
                break;
            case 3:
                tasks[i].score = 0.50 * tasks[i].weight;  // 50% of the weight
                break;
        }
    }

    // Input task weights and deadlines for advanced tasks
    for (int i = numMandatoryTasks; i < numTasks; i++) {
        printf("Enter the weight of advanced task %d: ", i - numMandatoryTasks);
        scanf("%d", &tasks[i].weight);

        int deadline;
        do {
            printf("Enter the deadline for advanced task %d (1 for 100%, 2 for 65%, 3 for 50%): ", i - numMandatoryTasks);
            scanf("%d", &deadline);
            if (deadline < 1 || deadline > 3) {
                printf("Invalid deadline. Please enter 1, 2, or 3.\n");
            }
        } while (deadline < 1 || deadline > 3);

        switch (deadline) {
            case 1:
                tasks[i].score = tasks[i].weight;  // 100% of the weight
                break;
            case 2:
                tasks[i].score = 0.65 * tasks[i].weight;  // 65% of the weight
                break;
            case 3:
                tasks[i].score = 0.50 * tasks[i].weight;  // 50% of the weight
                break;
        }
    }

    // Calculate the sum of scores and the sum of weights for mandatory and advanced tasks
    double totalMandatoryScore = 0.0; // Change data type to double
    double totalAdvancedScore = 0.0; // Change data type to double
    int totalMandatoryWeight = 0;
    int totalAdvancedWeight = 0;
    
    for (int i = 0; i < numTasks; i++) {
        if (i < numMandatoryTasks) {
            totalMandatoryScore += tasks[i].score;
            totalMandatoryWeight += tasks[i].weight;
        } else {
            totalAdvancedScore += tasks[i].score;
            totalAdvancedWeight += tasks[i].weight;
        }
    }

    // Calculate the project final score based on the specified formula
    double mandatoryPercentage = (totalMandatoryWeight > 0) ? (totalMandatoryScore / totalMandatoryWeight * 100.0) : 0.0;
    double advancedPercentage = (numAdvancedTasks > 0) ? (totalAdvancedWeight > 0 ? (totalAdvancedScore / totalAdvancedWeight * 100.0) : 0.0) : 0.0; // Set advanced percentage to 0 if there are no advanced tasks
    double finalScore = mandatoryPercentage + (advancedPercentage / 100.0);

    // Display the sorted tasks with scores and the project final score
    printf("Sorted tasks with scores and the project final score:\n");
    for (int i = 0; i < numTasks; i++) {
        if (i < numMandatoryTasks) {
            printf("Mandatory Task %d: Weight: %d, Score: %.2f\n", i, tasks[i].weight, tasks[i].score);
        } else {
            printf("Advanced Task %d: Weight: %d, Score: %.2f\n", i - numMandatoryTasks, tasks[i].weight, tasks[i].score);
        }
    }

    printf("Mandatory Task Percentage: %.2f%%\n", mandatoryPercentage);
    printf("Advanced Task Percentage: %.2f%%\n", advancedPercentage);
    printf("Project Final Score: %.2f%%\n", finalScore);

    return 0;
}
