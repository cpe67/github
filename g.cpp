#include <iostream>
#include <string>
using namespace std;

int main() {
    string display = "0";
    string operation = "";
    double prevValue = 0;
    double currentValue = 0;
    bool newNumber = true;

    int choice;
    while (true) {
        cout << "\n=== Simple Calculator ===" << endl;
        cout << "Display: " << display << endl;
        cout << "\n--- Number Buttons ---" << endl;
        cout << "1-9: Numbers (1-9)" << endl;
        cout << "0: Zero" << endl;
        cout << "\n--- Operation Buttons ---" << endl;
        cout << "11: +" << endl;
        cout << "12: -" << endl;
        cout << "13: *" << endl;
        cout << "14: /" << endl;
        cout << "15: %" << endl;
        cout << "16: =" << endl;
        cout << "17: Clear" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 9) {
            if (newNumber) {
                display = to_string(choice);
                newNumber = false;
            } else {
                display += to_string(choice);
            }
        } else if (choice == 0) {
            if (newNumber) {
                display = "0";
            } else if (display != "0") {
                display += "0";
            }
        } else if (choice >= 11 && choice <= 15) {
            currentValue = stod(display);
            if (operation != "" && !newNumber) {
                if (operation == "+") prevValue += currentValue;
                else if (operation == "-") prevValue -= currentValue;
                else if (operation == "*") prevValue *= currentValue;
                else if (operation == "/") prevValue /= currentValue;
                else if (operation == "%") prevValue = (int)prevValue % (int)currentValue;
                display = to_string(prevValue);
            } else {
                prevValue = currentValue;
            }
            
            if (choice == 11) operation = "+";
            else if (choice == 12) operation = "-";
            else if (choice == 13) operation = "*";
            else if (choice == 14) operation = "/";
            else if (choice == 15) operation = "%";
            
            newNumber = true;
        } else if (choice == 16) {
            currentValue = stod(display);
            if (operation == "+") prevValue += currentValue;
            else if (operation == "-") prevValue -= currentValue;
            else if (operation == "*") prevValue *= currentValue;
            else if (operation == "/") prevValue /= currentValue;
            else if (operation == "%") prevValue = (int)prevValue % (int)currentValue;
            
            display = to_string(prevValue);
            operation = "";
            newNumber = true;
        } else if (choice == 17) {
            display = "0";
            operation = "";
            prevValue = 0;
            newNumber = true;
        }
    }
    return 0;
}