//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <string>
//#include <limits>
//#include <cstdlib> // for system("cls")
//using namespace std;
//
//void displayTimeSlots(const vector<string>& slots, const vector<bool>& avail) {
//    const int idW = 4;
//    const int timeW = 15;
//    const int availW = 10;
//
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//    cout << "| " << left << setw(idW - 2) << "ID"
//        << " | " << left << setw(timeW - 2) << "Time Slot"
//        << " | " << left << setw(availW - 2) << "Available" << " |\n";
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//
//    for (size_t i = 0; i < slots.size(); ++i) {
//        cout << "| " << right << setw(idW - 2) << (i + 1)
//            << " | " << left << setw(timeW - 2) << slots[i]
//            << " | " << left << setw(availW - 2) << (avail[i] ? "Yes" : "No") << " |\n";
//    }
//
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//}
//
//void printHeaderArt() {
//    cout << R"(                                                                                                                                                                  
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
//                                                                         
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
//                                                                         
//                                                                         
// ######    ######       ######     ###    ##        #######  ##    ##    
//##    ##  ##    ##     ##    ##   ## ##   ##       ##     ## ###   ##    
//##        ##           ##        ##   ##  ##       ##     ## ####  ##    
//##   #### ##   ####     ######  ##     ## ##       ##     ## ## ## ##    
//##    ##  ##    ##           ## ######### ##       ##     ## ##  ####    
//##    ##  ##    ##     ##    ## ##     ## ##       ##     ## ##   ###    
// ######    ######       ######  ##     ## ########  #######  ##    ##    
//                                                                         
//                                                                         
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
//                                                                         
//##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####        
//                                                                         )" << endl;
//}
//
//void printMenu() {
//    cout << "Welcome to the Appointment Scheduler!\n" << endl;
//    cout << "Please select an option from the menu below:" << endl;
//    cout << "1. View All Appointment" << endl;
//    cout << "2. Create a New Appointment" << endl;
//    cout << "3. Cancel Appointment" << endl;
//    cout << "4. Reschedule Appointment" << endl;
//    cout << "5. View Staff Schedule" << endl;
//    cout << "6. Exit\n" << endl;
//}
//
//int main() {
//    // example time slots and availability (replace with your data source)
//    vector<string> slots = {
//        "09:00 - 09:30", "09:30 - 10:00", "10:00 - 10:30",
//        "10:30 - 11:00", "11:00 - 11:30", "13:00 - 13:30",
//        "13:30 - 14:00", "14:00 - 14:30"
//    };
//    vector<bool> avail = { true, false, true, true, false, true, true, false };
//
//    while (true) {
//        system("cls"); // clear console on Windows (optional)
//        printHeaderArt();
//        printMenu();
//
//        int option = 0;
//        if (!(cin >> option)) {
//            // handle non-integer input
//            cin.clear();
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//            cout << "Invalid input. Press Enter to return to menu...";
//            cin.get(); // consume leftover newline
//            cin.get(); // wait for Enter
//            continue;
//        }
//
//        // consume the newline after the number so subsequent getline/get works
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//        if (option < 1 || option > 6) {
//            cout << "Invalid option. Please select a valid option from the menu." << endl;
//        }
//        else {
//            switch (option) {
//            case 1:
//                cout << "You selected: View All Appointment" << endl << endl;
//                displayTimeSlots(slots, avail);
//                break;
//            case 2:
//                cout << "You selected: Create a New Appointment" << endl;
//                break;
//            case 3:
//                cout << "You selected: Cancel Appointment" << endl;
//                break;
//            case 4:
//                cout << "You selected: Reschedule Appointment" << endl;
//                break;
//            case 5:
//                cout << setw(50) << "You selected: View Staff Schedule" << endl;
//                break;
//            case 6:
//                cout << "Exiting the program. Goodbye!" << endl;
//                return 0;
//            }
//        }
//
//        cout << "\nPress Enter to return to the menu...";
//        cin.get(); // wait for Enter
//    }
//
//    return 0;
//}