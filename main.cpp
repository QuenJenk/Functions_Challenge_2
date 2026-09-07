#include <iostream>
#include <limits>
// Quentin Jenkins 9/7/26 Program that calculates the average and letter grade of assignments.

static void inputGrades(double& g1, double& g2, double& g3);
static double calculateAverage(double g1, double g2, double g3);
static char getLetterGrade( double average);
static double getValidGrade(int gradeNumber);
int main() {
    double grade1 = -1.0;
    double grade2 = -1.0;
    double grade3 = -1.0;
    int choice;
    do {
        std::cout << "         GRADES          \n";
        std::cout << "1. Input Grades\n";
        std::cout << "2. Calculate and Display Average\n";
        std::cout << "3. Assign and Display Letter Grade\n";
        std::cout << "4. Quit\n";
        std::cout << "Enter your choice (1-4): ";
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
            case 1:
                inputGrades(grade1, grade2, grade3);
                break;
            case 2:
                if (grade1 < 0 || grade2 < 0 || grade3 < 0) {
                    std::cout << "Error: Please input grades first (Option 1).\n";
                } else {
                    double avg = calculateAverage(grade1, grade2, grade3);
                    std::cout << "\nThe average of the three grades is: " << avg << "\n";
                }

                break;
            case 3:
                if (grade1 < 0 || grade2 < 0 || grade3 < 0) {
                    std::cout << "Error: Please input grades first (Option 1).\n";
                } else {
                    const double avg = calculateAverage(grade1, grade2, grade3);
                    const char letter = getLetterGrade(avg);
                    std::cout << "\nBased on the average of " << avg
                              << ", the Letter Grade is: " << letter << "\n";
                }

                break;
            case 4:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please select an option from 1 to 4.\n";
        }

    } while (choice != 4);
    return 0;
}

double getValidGrade(const int gradeNumber) {
    double grade;
    while (true) {
        std::cout << "Enter grade " << gradeNumber << " (0 - 100): ";
        if (std::cin >> grade && grade >= 0.0 && grade <= 100.0) {
            return grade;
        } else {
            std::cout << "Invalid input. Grade must be a number between 0 and 100.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void inputGrades(double& g1, double& g2, double& g3) {
    std::cout << "\n--- Input Student Grades ---\n";
    g1 = getValidGrade(1);
    g2 = getValidGrade(2);
    g3 = getValidGrade(3);
    std::cout << "Grades successfully recorded!\n";
}

double calculateAverage(const double g1, const double g2, const double g3) {
    return (g1 + g2 + g3) / 3.0;
}

char getLetterGrade(const double average) {
    if (average >= 90.0) return 'A';
    if (average >= 80.0) return 'B';
    if (average >= 70.0) return 'C';
    if (average >= 60.0) return 'D';
    return 'F';
}