#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <iomanip>
using namespace std;

struct StudentStruct {
    string name;
    int grade;
};
void clearInputBuffer() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    vector<StudentStruct> StudentVector;
    int choice = 0;
    cout << "Select a data entry mode:\n";
    cout << "1. Counter-controlled (enter a fixed number of students)\n";
    cout << "2. Sentinel-controlled (enter 'STOP' to finish)\n";
    cout << "Enter your choice (1 or 2):";
    cin >> choice;

    while (cin.fail() || (choice != 1 && choice != 2)) {
        cout << "Invalid input. Please enter 1 or 2: ";
        cin.clear();
        clearInputBuffer();
        cin >> choice;
    }

    clearInputBuffer();

    if (choice == 1) {
        int n = 0;
        cout << "\nHow many students will you enter? ";
        cin >> n;

        while (cin.fail() || n <= 0) {
            cout << "Please enter a positive integer: ";
            cin.clear();
            clearInputBuffer();
            cin >> n;
        }

        clearInputBuffer();

        for (int i = 1; i <= n; ++i) {
            StudentStruct a;

            cout << "\nStudent #" << i << " name: ";
            getline(cin, a.name);

            cout << "Student #" << i << " grade (0-100): ";
            cin >> a.grade;

            while (cin.fail() || a.grade < 0 || a.grade > 100) {
                cout << "Invalid grade. Enter a grade from 0 to 100: ";
                cin.clear();
                clearInputBuffer();
                cin >> a.grade;
            }

            clearInputBuffer();
            StudentVector.push_back(a);
        }

    } else {
        while (true) {
            StudentStruct a;

            cout << "\nEnter student name (or type stop to finish): ";
            getline(cin, a.name);
            if (a.name == "stop") break;

            cout << "Enter " << a.name << "'s grade (0-100): ";
            cin >> a.grade;

            while (cin.fail() || a.grade < 0 || a.grade > 100) {
                cout << "Invalid grade. Enter a grade from 0 to 100: ";
                cin.clear();
                clearInputBuffer();
                cin >> a.grade;
            }

            clearInputBuffer();
            StudentVector.push_back(a);
        }
    }

    if (StudentVector.empty()) {
        cout << "\nNo student data entered.\n";
        return 0;
    }

    double total = 0.0;
    int highestGrade = StudentVector[0].grade;
    string highestName = StudentVector[0].name;
    int lowestGrade = StudentVector[0].grade;
    string lowestName = StudentVector[0].name;

    for (size_t i = 0; i < StudentVector.size(); ++i) {
        total += StudentVector[i].grade;
        if (StudentVector[i].grade > highestGrade) {
            highestGrade = StudentVector[i].grade;
            highestName = StudentVector[i].name;
        }
        if (StudentVector[i].grade < lowestGrade) {
            lowestGrade = StudentVector[i].grade;
            lowestName = StudentVector[i].name;
        }
    }

    double average = total / StudentVector.size();

    cout << left << setw(16) << "\nClass Summary:\n";
    cout << fixed << setprecision(1);
    cout << left << setw(16) << "Class average: " << average << "\n";
    cout << left << setw(16) << "Highest: " << highestName << " (" << highestGrade << ")\n";
    cout << left << setw(16) << "Lowest : " << lowestName  << " (" << lowestGrade  << ")\n\n";

    cout << left << setw(15) << "Student"
    << setw(10) << "Grade"
    << right << setw(10) << "Pass/Fail" << "\n";

    for (size_t i = 0; i < StudentVector.size(); ++i) {
        const string result = (StudentVector[i].grade >= 65) ? "Pass" : "Fail";
        cout << left << setw(15) << StudentVector[i].name
             << setw(10) << StudentVector[i].grade
             << right << setw(10) << result << "\n";
    }
    return 0;
}
