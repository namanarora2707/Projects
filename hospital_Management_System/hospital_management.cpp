#include <iostream>
#include <vector>
using namespace std;

struct hospital {
    string name, address, bloodG;
    int age;
    string contact;  // Changed from int to string
};

hospital hsptl;
vector<hospital> vh;

int main() {
    int value;

    while (true) {
        cout << "1. Admit patient" << endl;
        cout << "2. Show all patients" << endl;
        cout << "3. Dismiss patient" << endl;
        cout << "4. Exit" << endl;
        cin >> value;
        cin.ignore(); // Clears newline character from input buffer

        switch (value) {
            case 1: {
                int choice;
                do {
                    cout << "Name: ";
                    getline(cin, hsptl.name);
                    cout << "Age: ";
                    cin >> hsptl.age;
                    cin.ignore();
                    cout << "Contact: ";
                    getline(cin, hsptl.contact); // Use getline for full input
                    cout << "Blood Group: ";
                    getline(cin, hsptl.bloodG);
                    cout << "Address: ";
                    getline(cin, hsptl.address);

                    vh.push_back(hsptl);
                    cout << "Patient admitted!" << endl;

                    cout << "Enter 1 to continue admitting patients, 0 to stop: ";
                    cin >> choice;
                    cin.ignore();
                } while (choice == 1);
                break;
            }

            case 2: {
                cout << "List of admitted patients:\n";
                for (size_t i = 0; i < vh.size(); i++) {
                    cout << "Patient " << i + 1 << ": " << vh[i].name 
                         << ", Age: " << vh[i].age 
                         << ", Contact: " << vh[i].contact 
                         << ", Blood Group: " << vh[i].bloodG 
                         << ", Address: " << vh[i].address << endl;
                }
                break;
            }

            case 3: {
                int index;
                cout << "Enter patient number to dismiss: ";
                cin >> index;
                if (index > 0 && index <= vh.size()) {
                    vh.erase(vh.begin() + index - 1);
                    cout << "Patient dismissed!" << endl;
                } else {
                    cout << "Invalid patient number!" << endl;
                }
                break;
            }

            case 4:
                cout << "Exiting program..." << endl;
                return 0;

            default:
                cout << "Invalid input! Please enter a valid option." << endl;
        }
    }
}
