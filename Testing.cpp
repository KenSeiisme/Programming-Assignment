//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <string>
//using namespace std;
//
//void displayTimeSlots(const vector<string>& slots, const vector<bool>& avail) {
//    const int idW = 4;
//    const int timeW = 15;
//    const int availW = 10;
//
//    // header line
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//    // column titles
//    cout << "| " << left << setw(idW-2) << "ID"
//         << " | " << left << setw(timeW-2) << "Time Slot"
//         << " | " << left << setw(availW-2) << "Available" << " |\n";
//    // separator
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//
//    // rows
//    for (size_t i = 0; i < slots.size(); ++i) {
//        cout << "| " << right << setw(idW-2) << (i + 1)
//             << " | " << left << setw(timeW-2) << slots[i]
//             << " | " << left << setw(availW-2) << (avail[i] ? "Yes" : "No") << " |\n";
//    }
//
//    // footer line
//    cout << '+' << string(idW, '-') << '+' << string(timeW, '-') << '+' << string(availW, '-') << '+' << '\n';
//}
//
//int main() {
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
//
//    cout << "Welcome to the Appointment Scheduler!\n" << endl;
//    cout << "Please select an option from the menu below:" << endl;
//    cout << "1. View All Appointment" << endl;
//    cout << "2. Create a New Appointment" << endl;
//    cout << "3. Cancel Appointment" << endl;
//    cout << "4. Reschedule Appointment" << endl;
//    cout << "5. View Staff Schedule" << endl;
//    cout << "6. Exit\n" << endl;
//
//    int option;
//    cin >> option;
//
//    if (option < 1 || option > 6) {
//        cout << "Invalid option. Please select a valid option from the menu." << endl;
//    }
//    else {
//        switch (option) {
//        case 1: {
//            // 示例时段与可用性（可替换为从数据源读取）
//            vector<string> slots = {
//                "09:00 - 09:30", "09:30 - 10:00", "10:00 - 10:30",
//                "10:30 - 11:00", "11:00 - 11:30", "13:00 - 13:30",
//                "13:30 - 14:00", "14:00 - 14:30"
//            };
//            vector<bool> avail = { true, false, true, true, false, true, true, false };
//
//            cout << "You selected: View All Appointment" << endl << endl;
//            displayTimeSlots(slots, avail);
//            break;
//        }
//        case 2:
//            cout << "You selected: Create a New Appointment" << endl;
//            break;
//        case 3:
//            cout << "You selected: Cancel Appointment" << endl;
//            break;
//        case 4:
//            cout << "You selected: Reschedule Appointment" << endl;
//            break;
//        case 5:
//            cout << setw(50) << "You selected: View Staff Schedule" << endl;
//            break;
//        case 6:
//            cout << setw(50) << "Exiting the program. Goodbye!" << endl;
//            break;
//        default:
//            cout << setw(50) << "Invalid option. Please select a valid option from the menu." << endl;
//            break;
//        }
//    }
//
//    return 0;
//}