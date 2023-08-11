#include <iostream>
#include <stdio.h>
#include <string>
#include <limits>
#pragma warning(disable : 4996)
using namespace std;

int main() {
    int credit = 0, totalCredit = 0, totalTotalCredit = 0, sem = 3, recorders[3] = { 0 }, b = 1, recorder = 0, creditR[3][100][10];
    double marks[100], totalPoints = 0.0, totalTotalPoints = 0.0, gpa, points, cgpa;
    char subjects[3][100][10]; // Assuming a maximum subject code length of 10 characters
    string name;
    char id[10]; // Assuming student ID length of 10 characters

    printf("Enter your name: ");
    getline(cin, name); // Using getline for names with spaces

    printf("Enter your student ID: KPKL");
    if (scanf("%s", id) != 1) {
        printf("Invalid input for student ID.\n");
        return 1;
    }

    for (int i = 1; i <= sem; i++) {
        bool validRecorder = false;

        while (!validRecorder) {
            printf("How many subjects do you have in semester %d: ", i);
            if (scanf("%d", &recorder) != 1) {
                printf("Invalid input. Please enter a valid positive number.\n");
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            else if (recorder < 0) {
                printf("Invalid input. Please enter a valid positive number.\n");
            }
            else {
                validRecorder = true;
            }
        }
        recorders[i - 1] = recorder;

        for (int m = 1; m <= recorder; m++) {
            printf("Enter your semester %d subject %d code: ", i, m);
            if (scanf("%9s", subjects[i][m]) != 1) {
                printf("Invalid input for subject code.\n");
                return 1;
            }

            printf("Enter your marks of this subject: ");
            if (scanf("%lf", &marks[m]) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                return 1; // Exiting with error code
            }

            printf("Enter your credits of this subject: ");
            if (scanf("%d", &credit) != 1) {
                printf("Invalid input. Please enter a valid number.\n");
                return 1; // Exiting with error code
            }
            creditR[i][m][0] = credit; // Store credit for each subject
            totalCredit += credit;
            totalTotalCredit += credit;

            if (marks[m] >= 80 && marks[m] <= 100) {
                points = 4.0 * credit;
            }
            else if (marks[m] >= 75 && marks[m] <= 79) {
                points = 3.75 * credit;
            }
            else if (marks[m] >= 70 && marks[m] <= 74) {
                points = 3.5 * credit;
            }
            else if (marks[m] >= 65 && marks[m] <= 69) {
                points = 3.0 * credit;
            }
            else if (marks[m] >= 60 && marks[m] <= 64) {
                points = 2.75 * credit;
            }
            else if (marks[m] >= 55 && marks[m] <= 59) {
                points = 2.5 * credit;
            }
            else if (marks[m] >= 50 && marks[m] <= 54) {
                points = 2.0 * credit;
            }
            else if (marks[m] >= 0 && marks[m] <= 49) {
                points = 0 * credit;
            }
            else {
                printf("Marks input invalid.\n\n");
                return 1; // Exiting with error code
            }

            totalPoints += points;
            totalTotalPoints += points;
        }

        gpa = totalPoints / totalCredit;
        printf("Semester %d GPA: %lf\n", i, gpa);

        // Reset GPA's credit and points counter
        totalCredit = 0;
        totalPoints = 0;
    }

    cgpa = totalTotalPoints / totalTotalCredit;

    printf("Student Name: %s\n", name.c_str());
    printf("Student ID: KPKL%s\n", id);
    printf("Number. | Course Code | Credit Hours\n");
    for (int m = 1; m <= sem; m++) {
        for (int k = 1; k <= recorders[m - 1]; k++) {
            printf("   %d.  | %s    |  %d\n", b, subjects[m][k], creditR[m][k][0]); // Display credit for each subject
            b++;
        }
    }
    printf("CGPA: %lf\n", cgpa);

    return 0;
}
