#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <limits> 
#include <cctype>
using namespace std;



const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";

// Logo
void logo() {
	cout << R"(                                                                                                                                                                             
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
																		 
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
																		 
																		 
 ######    ######       ######     ###    ##        #######  ##    ##    
##    ##  ##    ##     ##    ##   ## ##   ##       ##     ## ###   ##    
##        ##           ##        ##   ##  ##       ##     ## ####  ##    
##   #### ##   ####     ######  ##     ## ##       ##     ## ## ## ##    
##    ##  ##    ##           ## ######### ##       ##     ## ##  ####    
##    ##  ##    ##     ##    ## ##     ## ##       ##     ## ##   ###    
 ######    ######       ######  ##     ## ########  #######  ##    ##    
																		 
																		 
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
																		 
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####        
																		 )" << endl;
}

// Menu
void menu() {
	cout << "Welcome to the Appointment Scheduler!\n" << endl;
	cout << "Please select an option from the menu below:" << endl;
	cout << "1. View All Appointment" << endl;
	cout << "2. Create a New Appointment" << endl;
	cout << "3. Cancel Appointment" << endl;
	cout << "4. Reschedule Appointment" << endl;
	cout << "5. View Staff Schedule" << endl;
	cout << "6. Appointment Marking" << endl;
	cout << "0. Exit\n" << endl;
}

//define timeslot set
struct Timeslot {
	int id;
	string time;
	bool isBooked;
	string staffName;
	string service;
};

//timeslot
void displayAppointment(const Timeslot schedule[], int size) {

	//separator
	string separator = "+" + string(5, '-') + "+" + string(21, '-') + "+" + string(11, '-') + "+" + string(17, '-') + "+" + string(19, '-') + "+";

	//header
	cout << separator << endl;
	cout << "| " << left << setw(4) << "ID"
		<< "| " << setw(20) << "Time Slot"
		<< "| " << setw(10) << "Status"
		<< "| " << setw(16) << "Staff"
		<< "| " << setw(18) << "Service" << "|" << endl;
	cout << separator << endl;

	//details
	for (int i = 0; i < size; i++) {
		string statusAppointment = schedule[i].isBooked ? "Booked" : "Available";
		string statuscolor = schedule[i].isBooked ? RED : GREEN;
		string staffname = schedule[i].isBooked ? schedule[i].staffName : "-";
		string service = schedule[i].isBooked && !schedule[i].service.empty() ? schedule[i].service : "-";

		cout << "| " << left << setw(4) << schedule[i].id
			 << "| " << setw(20) << schedule[i].time
			 << "| " << statuscolor << setw(10) << statusAppointment << RESET
			 << "| " << setw(16) << staffname
			 << "| " << setw(18) << service << "|" << endl;
	}
	cout << separator << endl;
}

//total slots
const int TOTAL_SLOTS = 7;

//details
Timeslot schedule[TOTAL_SLOTS] = {
    {1, "09:00 AM - 10:00 AM", false, ""},
    {2, "10:00 AM - 11:00 AM", true,  "John Tan", "Haircut"},
    {3, "11:00 AM - 12:00 PM", false, ""},
    {4, "01:00 PM - 02:00 PM", true,  "Alice Lim", "Makeup"},
    {5, "02:00 PM - 03:00 PM", false, ""},
    {6, "03:00 PM - 04:00 PM", false, ""},
    {7, "04:00 PM - 05:00 PM", false, ""}
};



void appointmentManagement(){
    int option, Appointment_time;

    //looping menu
    do
    {
        logo();
        menu();

        // Get user input
        cin >> option;

        //validation for number input not char
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number from 1 to " << TOTAL_SLOTS << '.' << endl;
            cout << "\nPress Enter to return to the menu...";
            cin.get();
            continue;
        }

        switch (option) {
        case 1:
            cout << "You selected: View All Appointment" << endl;
            displayAppointment(schedule, TOTAL_SLOTS);
            break;
        case 2: {
            cout << "You selected: Create a New Appointment" << endl;
            displayAppointment(schedule, TOTAL_SLOTS);
            cout << "Which timeslot do you prefer?" << endl;
            cin >> Appointment_time;

            //check user input
            if (cin.fail() || Appointment_time < 1 || Appointment_time > TOTAL_SLOTS) {
                cin.clear();
                cout << RED << "\n[Error] Invalid timeslot ID! Please choose between 1 and " << TOTAL_SLOTS << "." << RESET << endl;
                break;
            }

            int slotIndex = Appointment_time - 1;
            int staffoption, Appointmentoption;

            if (schedule[slotIndex].isBooked) {
                cout << RED << "\n[Sorry] Timeslot " << Appointment_time << " is already booked!" << RESET << endl;
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "Select a Staff you preferred";
                cin >> staffoption;
                switch (staffoption) {
                case 1:
                    schedule[slotIndex].staffName = "Name";
                    break;


                }

                cout << "Enter a Service\n" << endl;
                cout << "Please select an option from the menu below:" << endl;
                cout << "1. Wedding Event" << endl;
                cout << "2. Hair dressing with make up" << endl;
                cin >> Appointmentoption;

                switch (Appointmentoption) {
                case 1:
                    schedule[slotIndex].service = "Wedding Event";
                    break;
                case 2:
                    schedule[slotIndex].service = "Hair dressing with make up";
                    break;
                default:
                    cout << "Invalid option. Please select a valid option from the menu." << endl;

                }

                schedule[slotIndex].isBooked = true;

                cout << GREEN << "\n[Success] Appointment successfully created for Timeslot " << schedule[slotIndex].time << "!" << RESET << endl;
            }

            break;
        }
        case 3:
            cout << "You selected: Cancel Appointment" << endl;
            break;
        case 4:
            cout << "You selected: Reschedule Appointment" << endl;
            break;
        case 5:
            cout << "You selected: View Staff Schedule" << endl;
            break;
        case 6:
            cout << "You selected: Appoinment Marking" << endl;
            break;
        case 0:
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please select a valid option from the menu." << endl;
            break;
        }
        //check option and stop the progress to show menu details, clear the number the looping before
        if (option != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (option != 0);
}

// Data structure for Customer details
struct Customer {
    string nameCustomer;
    string genderCustomer;
    string phoneCustomer;
    string emailCustomer;
    string passwordCustomer;
};

// Data structure for Member details
struct Member {
    string nameMember;
    string genderMember;
    string phoneMember;
    string emailMember;
    string passwordMember;
};

// Data structure for Salon Staff details
struct Staff {
    string nameStaff;
    string genderStaff;
    string phoneStaff;
    string emailStaff;
    string passwordStaff;
    string positionStaff;
};

// Global ID counters
int customerCounter = 1005;
int memberCounter = 1005;
int staffCounter = 1011;

// In-memory databases storing full struct data
unordered_map<string, Customer> customerDB = {
    //Customer ID,Name Customer,Customer Gender,Phone Number,Email,Password
    {"C1001", {"Viknesh a/l Vijayan", "Male", "013-5678901", "viknesh129@gmail.com", "SolarPower2026!"}},
    {"C1002", {"Priya a/p Anbalagan", "Female", "014-6789012", "priya59@gmail.com", "Bikoma72!q"}},
    {"C1003", {"Teo Bao Bin", "Male", "016-7890123", "bb520go@gmail.com", "k8n9vp2m5x"}},
    {"C1004", {"Lily Yee", "Female", "017-8901234", "lilyisflower43@gmail.com", "K0N9VP2M5Z"}},
};

unordered_map<string, Member> memberDB = {
    //Member ID,Member Name,Member Gender,Phone Number,Email,Password
    {"M1001", {"Eren Chew", "Male", "017-6543210", "erenono097@gmail.com", "k8N9vP2mX5"}},
    {"M1002", {"Tan Shin Nang", "Male", "018-2345678", "startan67@gmail.com", "b9M3zP7wR#"}},
    {"M1003", {"Noor Siti", "Female", "011-12345678", "siti945@gmail.com", "TungtSahur345"}},
    {"M1004", {"Alice Low", "Female", "019-5678901", "alicelow@gmail.com", "76WhatheDogDoing//"}}
};

unordered_map<string, Staff> staffDB = {
    //Staff ID,Name Staff,Staff Gender,Phone Number,Email,Password,Position
    {"STF1001", {"Kim Ji Soo", "Female", "011-2233445", "jisookim123@gmail.com", "k8N9vP2m!", "Hair Stylis"}},
    {"STF1002", {"Sarah Jenkins", "Female", "017-8899001", "sarah36@gmail.com", "r9W!z2#k&", "Hair Color Stylist"}},
    {"STF1003", {"Sim Jia Yih", "Female", "011-10546505", "jiayih@gmail.com", "j7N5qW8mX2z%", "Hair Color Stylist"}},
    {"STF1004", {"Lim Xiao Qing", "Female", "018-9032655", "xiaoqing@gmail.com", "w9K4zM2pR!", "Nail Technician"}},
    {"STF1005", {"Lim Cai Xuan", "Female", "012-6125939", "caixuan@gmail.com", "t3X8qP5mL9#", "Receptionist"}},
    {"STF1006", {"Lee Hao Zheng", "Male", "016-5011218", "haozheng@gmail.com", "y8M2!zR9#vW@", "Nail Technician"}},
    {"STF1007", {"Ng Jun Sheng", "Male", "017-3746889", "junsheng@gmail.com", "h3N9!qX5$k&", "Receptionist"}},
    {"STF1008", {"Lao Teh", "Male", "017-88990012", "laoteh@gmail.com", "c9P5!xT2$w@", "Skincare Specialist"}},
    {"STF1009", {"Noor Shahirah", "Female", "010-86043225", "shahirah@gmail.com", "k6P3#wT8$mL&", "Skincare Specialist"}},
    {"STF1010", {"Roslizawati", "Female", "017-88378451", "rosealwaysrosie@gmail.com", "But860//wt=", "Hair Stylis"}},
};

// Function Declarations
//Sim Jia Yih Part
void mainMenu(); //Main Page choose Staff or Customer
void customerPortal();
void staffPortal();
void registerCustomer();
void registerMember();
void customerLogin();
void registerStaff();
void staffLogin();
void showCustomerUI(const string& username, const string& accountType); //Customer User Interface
void showStaffUI(const string& username); //Staff User Interface
void memberManagement();
void staffManagement();
void showStaffList(); //Staff Table
void showMemberCustomerList(); // Member and Customer Table
void clearInput();
// This Part use to check is valid or not
bool isValidEmail(const string& email);
bool isValidPassword(const string& pass);
bool isValidPhoneNumber(const string& phone);
bool isValidName(const string& name);

////////////////////

// Validation Functions
// Check name contains letters/spaces only (no digits)
bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
        if (!isalpha(c) && !isspace(c) && c != '\'' && c != '-') return false;
    }
    return true;
}

// Check phone number contains at least one dash '-'
bool isValidPhoneNumber(const string& phone) {
    if (phone.empty()) return false;
    if (phone.find('-') == string::npos) return false;
    for (char c : phone) {
        if (!isdigit(c) && c != '-' && !isspace(c)) return false;
    }
    return true;
}

bool isValidEmail(const string& email) {
    string domain = "@gmail.com";
    if (email.length() < domain.length()) return false;
    return email.compare(email.length() - domain.length(), domain.length(), domain) == 0;
}

bool isValidPassword(const string& pass) {
    if (pass.length() < 8) return false;
    bool hasLetter = false;
    bool hasDigit = false;
    for (char c : pass) {
        if (isalpha(c)) hasLetter = true;
        if (isdigit(c)) hasDigit = true;
    }
    return hasLetter && hasDigit;
}

// Clear stream errors and buffer on invalid input
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Main System Navigation
void mainMenu() {
    int choice = 0;
    while (true) {
        cout << "\n========================================\n";
        cout << "            MAIN SYSTEM MENU            \n";
        cout << "========================================\n";
        cout << "1. Customer / Member\n";
        cout << "2. Staff\n";
        cout << "3. Exit System\n";
        cout << "Select option (1-3): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            customerPortal();
            break;
        case 2:
            staffPortal();
            break;
        case 3:
            cout << "Exiting application. Goodbye!\n";
            return;
        default:
            cout << "Invalid selection. Please enter 1, 2, or 3.\n";
        }
    }
}

// --- CUSTOMER PORTAL ---
void customerPortal() {
    int choice = 0;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "            CUSTOMER/MEMBER PORTAL             \n";
        cout << "----------------------------------------\n";
        cout << "1. Customer Registration\n";
        cout << "2. Member Registration\n";
        cout << "3. Customer / Member Login\n";
        cout << "4. Exit (Return to Main Menu)\n";
        cout << "Select option (1-4): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
        case 1:
            registerCustomer();
            break;
        case 2:
            registerMember();
            break;
        case 3:
            customerLogin();
            break;
        case 4:
            cout << "Returning to Main Menu...\n";
            return;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}

void registerCustomer() {
    Customer newCustomer;
    cout << "\n--- NEW CUSTOMER REGISTRATION ---\n";
    string customerGeneratedID = "C" + to_string(customerCounter++);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newCustomer.nameCustomer); // Reads spaces correctly
        if (isValidName(newCustomer.nameCustomer)) break;
        cout << "[Error] Invalid name! Only can use alphabet. Try again.\n";
    }

    // 2. Gender Prompt
    string genderInput;
    while (true) {
        cout << "Enter Gender (m/f): ";
        cin >> genderInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (genderInput == "m" || genderInput == "M") {
            newCustomer.genderCustomer = "Male";
            break;
        }
        else if (genderInput == "f" || genderInput == "F") {
            newCustomer.genderCustomer = "Female";
            break;
        }
        else {
            cout << "[Error] Invalid gender! Please enter 'm' for Male or 'f' for Female.\n";
        }
    }

    while (true) {
        cout << "Enter Phone Number: ";
        cin >> newCustomer.phoneCustomer;
        if (isValidPhoneNumber(newCustomer.phoneCustomer)) break;
        cout << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n";
    }

    while (true) {
        cout << "Enter Email Address (must end with @gmail.com): ";
        cin >> newCustomer.emailCustomer;
        if (isValidEmail(newCustomer.emailCustomer)) break;
        cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
    }

    while (true) {
        cout << "Enter Password (min 8 chars, must contain letters & digits): ";
        cin >> newCustomer.passwordCustomer;
        if (isValidPassword(newCustomer.passwordCustomer)) break;
        cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
    }

    customerDB[customerGeneratedID] = newCustomer;

    cout << "\n[Success] Customer registration completed!\n";
    cout << "========================================\n";
    cout << " Assigned Customer ID : " << customerGeneratedID << "\n";
    cout << " Name                 : " << newCustomer.nameCustomer << "\n";
    cout << " Phone                : " << newCustomer.phoneCustomer << "\n";
    cout << " Email                : " << newCustomer.emailCustomer << "\n";
    cout << "========================================\n";
    cout << "Please keep your Customer ID to log in.\n";
}


void registerMember() {
    char response;
    Member newMember;
    cout << "\n--- NEW VIP MEMBER REGISTRATION ---\n";

    cout << "Do you already pay the Member Fee ? (Y=yes,N=no): ";
    cin >> response;
    response = toupper(response);

    if (response == 'Y') {
        // Clear leftover '\n' from the fee choice prompt
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // 1. Full Name Prompt
        while (true) {
            cout << "Enter Full Name: ";
            getline(cin, newMember.nameMember); // Reads spaces correctly
            if (isValidName(newMember.nameMember)) break;
            cout << "[Error] Invalid name! Only can use alphabet. Try again.\n";
        }

        // 2. Gender Prompt
        string genderInput;
        while (true) {
            cout << "Enter Gender (m/f): ";
            cin >> genderInput;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (genderInput == "m" || genderInput == "M") {
                newMember.genderMember = "Male";
                break;
            }
            else if (genderInput == "f" || genderInput == "F") {
                newMember.genderMember = "Female";
                break;
            }
            else {
                cout << "[Error] Invalid gender! Please enter 'm' for Male or 'f' for Female.\n";
            }
        }

        // 3. Phone Number Prompt
        while (true) {
            cout << "Enter Phone Number: ";
            cin >> newMember.phoneMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPhoneNumber(newMember.phoneMember)) break;
            cout << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n";
        }

        // 4. Email Prompt
        while (true) {
            cout << "Enter Email Address (must end with @gmail.com): ";
            cin >> newMember.emailMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidEmail(newMember.emailMember)) break;
            cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
        }

        // 5. Password Prompt
        while (true) {
            cout << "Enter Password (min 8 chars, must contain letters & digits): ";
            cin >> newMember.passwordMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPassword(newMember.passwordMember)) break;
            cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
        }

        // Generate ID only after all input succeeds
        string memberGeneratedID = "M" + to_string(memberCounter++);
        memberDB[memberGeneratedID] = newMember;

        cout << "\n[Success] VIP Member registration completed!\n";
        cout << "========================================\n";
        cout << " Assigned Member ID : " << memberGeneratedID << "\n";
        cout << " Name               : " << newMember.nameMember << "\n";
        cout << " Phone              : " << newMember.phoneMember << "\n";
        cout << " Email              : " << newMember.emailMember << "\n";
        cout << "========================================\n";
        cout << "Please keep your Member ID to log in.\n";
    }
    else {
        cout << "Please pay Member Fee first at the counter." << endl;
    }
}

void customerLogin() {
    string userCustomer, passCustomer;
    cout << "\n--- CUSTOMER / VIP MEMBER LOGIN ---\n";
    cout << "Customer ID / Member ID: ";
    cin >> userCustomer;
    cout << "Password: ";
    cin >> passCustomer;

    auto itMem = memberDB.find(userCustomer);
    if (itMem != memberDB.end() && itMem->second.passwordMember == passCustomer) {
        cout << "\nMember login successful!\n";
        showCustomerUI(userCustomer, "Member");
        return;
    }

    auto itCust = customerDB.find(userCustomer);
    if (itCust != customerDB.end() && itCust->second.passwordCustomer == passCustomer) {
        cout << "\nCustomer login successful!\n";
        showCustomerUI(userCustomer, "Standard Customer");
        return;
    }

    cout << "\n[Error] Invalid Customer/Member ID or Password.\n";
}

void showCustomerUI(const string& username, const string& accountType) {
    int choice = 0;
    while (true) {
        cout << "\n****************************************\n";
        cout << "           CUSTOMER DASHBOARD           \n";
        cout << " Account: " << username << " (" << accountType << ")\n";
        cout << "****************************************\n";
        cout << "1. Service\n";
        cout << "2. Appointment\n";
        cout << "3. Billing\n";
        cout << "4. Logout\n";
        cout << "Select action: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 4) {
            cout << "Logging out of Customer Dashboard...\n";
            break;
        }

        switch (choice) {
        case 1:
            cout << "\n-> [Customer UI] Displaying Service\n";
            break;
        case 2:
            cout << "\n-> [Customer UI] Opening Appointment\n";
            appointmentManagement();
            break;
        case 3:
            cout << "\n-> [Customer UI] Opening Billing...\n";
            break;
        default:
            cout << "Invalid selection.\n";
        }
    }
}

// --- STAFF PORTAL ---
void staffPortal() {
    int choice = 0;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "              STAFF PORTAL               \n";
        cout << "----------------------------------------\n";
        cout << "1. Staff Registration\n";
        cout << "2. Staff Login\n";
        cout << "3. Exit (Return to Main Menu)\n";
        cout << "Select option (1-3): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            registerStaff();
            break;
        case 2:
            staffLogin();
            break;
        case 3:
            cout << "Returning to Main Menu...\n";
            return;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}

void registerStaff() {
    Staff newStaff;
    cout << "\n--- NEW HAIR SALON STAFF REGISTRATION ---\n";
    string generatedID = "STF" + to_string(staffCounter++);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newStaff.nameStaff); // Reads spaces correctly
        if (isValidName(newStaff.nameStaff)) break;
        cout << "[Error] Invalid name! Only can use alphabet. Try again.\n";
    }

    // 2. Gender Prompt
    string genderInput;
    while (true) {
        cout << "Enter Gender (m/f): ";
        cin >> genderInput;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (genderInput == "m" || genderInput == "M") {
            newStaff.genderStaff = "Male";
            break;
        }
        else if (genderInput == "f" || genderInput == "F") {
            newStaff.genderStaff = "Female";
            break;
        }
        else {
            cout << "[Error] Invalid gender! Please enter 'm' for Male or 'f' for Female.\n";
        }
    }

    while (true) {
        cout << "Enter Phone Number: ";
        cin >> newStaff.phoneStaff;
        if (isValidPhoneNumber(newStaff.phoneStaff)) break;
        cout << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n";
    }

    while (true) {
        cout << "Enter Email Address (must end with @gmail.com): ";
        cin >> newStaff.emailStaff;
        if (isValidEmail(newStaff.emailStaff)) break;
        cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
    }

    while (true) {
        cout << "Enter Password (Minimun 8 chars, must contain letters & digits): ";
        cin >> newStaff.passwordStaff;
        if (isValidPassword(newStaff.passwordStaff)) break;
        cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
    }

    int posChoice = 0;
    while (true) {
        cout << "\nWhat position do you want to hire for?\n";
        cout << "1. Hair Stylist\n";
        cout << "2. Skincare Specialist\n";
        cout << "3. Hair Color Stylist\n";
        cout << "4. Nail Technician\n";
        cout << "5. Receptionist\n";
        cout << "Select position (1-5): ";

        if (cin >> posChoice && posChoice >= 1 && posChoice <= 5) {
            switch (posChoice) {
            case 1: newStaff.positionStaff = "Hair Stylist"; break;
            case 2: newStaff.positionStaff = "Skincare Specialist"; break;
            case 3: newStaff.positionStaff = "Hair Color Stylist"; break;
            case 4: newStaff.positionStaff = "Nail Technician"; break;
            case 5: newStaff.positionStaff = "Receptionist"; break;
            }
            break;
        }
        else {
            clearInput();
            cout << "[Error] Invalid position selection. Please enter a number between 1 and 5.\n";
        }
    }

    staffDB[generatedID] = newStaff;

    cout << "\n[Success] Staff registration completed!\n";
    cout << "========================================\n";
    cout << " Assigned Staff ID : " << generatedID << "\n";
    cout << " Name              : " << newStaff.nameStaff << "\n";
    cout << " Position          : " << newStaff.positionStaff << "\n";
    cout << " Phone             : " << newStaff.phoneStaff << "\n";
    cout << " Email             : " << newStaff.emailStaff << "\n";
    cout << "========================================\n";
    cout << "Please keep your Staff ID to log in.\n";
}
void staffLogin() {
    string user, pass;
    cout << "\n--- STAFF / ADMIN LOGIN ---\n";
    cout << "Staff ID: ";
    cin >> user;
    cout << "Password: ";
    cin >> pass;

    auto it = staffDB.find(user);
    if (it != staffDB.end() && it->second.passwordStaff == pass) {
        cout << "\nStaff authentication successful!\n";
        cout << "Welcome, " << it->second.nameStaff << " (" << it->second.positionStaff << ")!\n";
        showStaffUI(user);
    }
    else {
        cout << "\n[Error] Invalid Staff credentials.\n";
    }
}

void showStaffUI(const string& username) {
    int choice = 0;
    while (true) {
        cout << "\n========================================\n";
        cout << "          STAFF CONTROL PANEL           \n";
        cout << " Staff ID: " << username << " | " << staffDB[username].nameStaff
            << " (" << staffDB[username].positionStaff << ")\n";
        cout << "========================================\n";
        cout << "1. Member Info\n";
        cout << "2. Staff Info Management\n";
        cout << "3. Service management\n";
        cout << "4. Appointment Management\n";
        cout << "5. View History\n";
        cout << "6. Reporting\n";
        cout << "7. Logout\n";
        cout << "Select admin task: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        if (choice == 7) {
            cout << "Logging out of Staff Control Panel...\n";
            break;
        }

        switch (choice) {
        case 1: { // Enclosed block scope for local variables
            string confirmID;
            cout << "\n----------------------------------------\n";
            cout << "         STAFF VERIFICATION REQUIRED    \n";
            cout << "----------------------------------------\n";
            cout << "Enter Staff ID to access Member Management: ";
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

            auto it = staffDB.find(confirmID);
            if (it != staffDB.end() && confirmID == username) {
                cout << "\n[Access Granted] Verified identity: " << it->second.nameStaff << "\n";
                memberManagement();
            }
            else {
                cout << "\n[Access Denied] Invalid or mismatched Staff ID!\n";
            }
            break;
        }
        case 2: { // Added missing braces here
            string confirmID;
            cout << "\n----------------------------------------\n";
            cout << "         STAFF VERIFICATION REQUIRED    \n";
            cout << "----------------------------------------\n";
            cout << "Enter Staff ID to access Staff Management: "; // Fixed text
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

            auto it = staffDB.find(confirmID);
            if (it != staffDB.end() && confirmID == username) {
                cout << "\n[Access Granted] Verified identity: " << it->second.nameStaff << "\n";
                staffManagement();
            }
            else {
                cout << "\n[Access Denied] Invalid or mismatched Staff ID!\n";
            }
            break;
        }
        case 3:
            cout << "\n[System] Service management module selected.\n";
            break;
        case 4:
            cout << "\n[System] Appointment management module selected.\n";
            appointmentManagement();
            break;
        case 5:
            cout << "\n[System] View history module selected.\n";
            break;
        case 6:
            cout << "\n[System] Reporting module selected.\n";
            break;
        default:
            cout << "Invalid selection.\n";
        }
    }
}

void showStaffList() {
    cout << right << setw(70) << "Table Staff" << endl;
    string border = "+----------+--------------+----------------------+-----------------+---------------------------+--------------+";
    cout << "\n" << border << "\n";
    cout << "| " << left << setw(8) << "ID"
        << "| " << setw(13) << "Type"
        << "| " << setw(19) << "Name"
        << "| " << setw(15) << "Phone number"
        << "| " << setw(23) << "Email"
        << "| " << setw(15) << "Password"
        << "| " << setw(15) << "Position" << "|\n";

    cout << border << "\n";

    for (const auto& entry : staffDB) {
        cout << "| " << left << setw(8) << entry.first
            << "| " << setw(13) << "Staff"
            << "| " << setw(19) << entry.second.nameStaff
            << "| " << setw(15) << entry.second.phoneStaff
            << "| " << setw(23) << entry.second.emailStaff
            << "| " << setw(15) << entry.second.passwordStaff
            << "| " << setw(15) << entry.second.positionStaff << "|\n";
        cout << border << "\n";
    }

}
// --- SUB-MENU: STAFF MANAGEMENT ---
void staffManagement() {
    int choice = 0;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "          STAFF MANAGEMENT MENU         \n";
        cout << "----------------------------------------\n";
        cout << "1. View Staff Table\n";
        cout << "2. Search Staff\n";
        cout << "3. Delete Staff\n";
        cout << "4. Update Staff Information\n";
        cout << "5. Return to Staff Control Panel\n";
        cout << "Select option (1-5): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Returning to Staff Control Panel...\n";
            break;
        }

        string id;
        switch (choice) {
        case 1: {
            showStaffList();
            break;
        }
        case 2: {
            cout << "\nEnter Staff ID to search: ";
            cin >> id;

            auto it = staffDB.find(id);
            if (it != staffDB.end()) {
                cout << "\n[Found] ID: " << it->first
                    << " | Name: " << it->second.nameStaff
                    << " | Gender: " << it->second.genderStaff
                    << " | Phone: " << it->second.phoneStaff
                    << " | Email: " << it->second.emailStaff
                    << " | Position: " << it->second.positionStaff << "\n";
            }
            else {
                cout << "\n[Error] Staff ID '" << id << "' not found.\n";
            }
            break;
        }
        case 3: {
            cout << "\nEnter Staff ID to delete: ";
            cin >> id;

            if (staffDB.erase(id)) {
                cout << "\n[Success] Staff '" << id << "' deleted successfully.\n";
            }
            else {
                cout << "\n[Error] Staff ID '" << id << "' not found. Delete canceled.\n";
            }
            break;
        }
        case 4: {
            cout << "\nEnter Staff ID to update: ";
            cin >> id;

            auto it = staffDB.find(id);
            if (it == staffDB.end()) {
                cout << "\n[Error] Staff ID '" << id << "' not found. Update canceled.\n";
                break;
            }

            cout << "\n--- SELECT FIELD TO UPDATE ---\n";
            cout << "1. Email Address\n";
            cout << "2. Phone Number\n";
            cout << "3. Password\n";
            cout << "4. Position\n";
            cout << "Select option (1-4): ";

            int updateChoice = 0;
            if (!(cin >> updateChoice)) {
                clearInput();
                cout << "[Error] Invalid selection. Update canceled.\n";
                break;
            }

            switch (updateChoice) {
            case 1: { // Update Email
                string newEmail;
                while (true) {
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
                }
                it->second.emailStaff = newEmail;
                cout << "\n[Success] Email updated successfully for Staff ID '" << id << "'!\n";
                break;
            }
            case 2: { // Update Phone Number
                string newPhone;
                cout << "Enter new Phone Number: ";
                cin >> newPhone;
                it->second.phoneStaff = newPhone;
                cout << "\n[Success] Phone number updated successfully for Staff ID '" << id << "'!\n";
                break;
            }
            case 3: { // Update Password
                string newPass;
                while (true) {
                    cout << "Enter new Password (min 8 chars, letter & digit): ";
                    cin >> newPass;
                    if (isValidPassword(newPass)) break;
                    cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
                }
                it->second.passwordStaff = newPass;
                cout << "\n[Success] Password updated successfully for Staff ID '" << id << "'!\n";
                break;
            }
            case 4: { // Update Position
                string newPos;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter new Hair Salon Position: ";
                getline(cin, newPos);
                it->second.positionStaff = newPos;
                cout << "\n[Success] Position updated successfully for Staff ID '" << id << "'!\n";
                break;
            }
            default:
                cout << "\n[Error] Invalid option selected. Update canceled.\n";
            }
            break;
        }
        default:
            cout << "Invalid option. Please enter 1 to 5.\n";
        }
    }
}
void showMemberCustomerList() {
    cout << right << setw(70) << "Table Customer and Member" << endl;
    string border = "+---------+--------------+--------------------+----------------+------------------------+----------------+";
    cout << "\n" << border << "\n";
    cout << "| " << left << setw(8) << "ID"
        << "| " << setw(13) << "Type"
        << "| " << setw(19) << "Name"
        << "| " << setw(15) << "Phone number"
        << "| " << setw(23) << "Email"
        << "| " << setw(15) << "Password" << "|\n";
    cout << border << "\n";

    for (const auto& entry : memberDB) {
        cout << "| " << left << setw(8) << entry.first
            << "| " << setw(13) << "Member"
            << "| " << setw(19) << entry.second.nameMember
            << "| " << setw(15) << entry.second.phoneMember
            << "| " << setw(23) << entry.second.emailMember
            << "| " << setw(15) << entry.second.passwordMember << "|\n";
        cout << border << "\n";
    }
    for (const auto& entry : customerDB) {
        cout << "| " << left << setw(8) << entry.first
            << "| " << setw(13) << "Customer"
            << "| " << setw(19) << entry.second.nameCustomer
            << "| " << setw(15) << entry.second.phoneCustomer
            << "| " << setw(23) << entry.second.emailCustomer
            << "| " << setw(15) << entry.second.passwordCustomer << "|\n";
        cout << border << "\n";
    }
}

// --- SUB-MENU: MEMBER MANAGEMENT ---
void memberManagement() {
    int choice = 0;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "         MEMBER MANAGEMENT MENU         \n";
        cout << "----------------------------------------\n";
        cout << "1. View Member Table\n";
        cout << "2. Search Member\n";
        cout << "3. Delete Member\n";
        cout << "4. Update Member Information\n";
        cout << "5. Return to Staff Control Panel\n";
        cout << "Select option (1-5): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a valid number.\n";
            continue;
        }

        if (choice == 5) {
            cout << "Returning to Staff Control Panel...\n";
            break;
        }

        string id;
        switch (choice) {
        case 1: {
            showMemberCustomerList();
            break;
        }
        case 2: {
            cout << "\nEnter Customer/Member ID to search: ";
            cin >> id;

            auto itMem = memberDB.find(id);
            if (itMem != memberDB.end()) {
                cout << "\n[Found] ID: " << itMem->first
                    << " | Type: VIP Member | Name: " << itMem->second.nameMember
                    << " | Phone: " << itMem->second.phoneMember
                    << " | Email: " << itMem->second.emailMember << "\n";
            }
            else {
                auto itCust = customerDB.find(id);
                if (itCust != customerDB.end()) {
                    cout << "\n[Found] ID: " << itCust->first
                        << " | Type: Standard Customer | Name: " << itCust->second.nameCustomer
                        << " | Phone: " << itCust->second.phoneCustomer
                        << " | Email: " << itCust->second.emailCustomer << "\n";
                }
                else {
                    cout << "\n[Error] Member/Customer ID '" << id << "' not found.\n";
                }
            }
            break;
        }
        case 3: {
            cout << "\nEnter Customer/Member ID to delete: ";
            cin >> id;

            if (memberDB.erase(id)) {
                cout << "\n[Success] VIP Member '" << id << "' deleted successfully.\n";
            }
            else if (customerDB.erase(id)) {
                cout << "\n[Success] Customer '" << id << "' deleted successfully.\n";
            }
            else {
                cout << "\n[Error] ID '" << id << "' not found. Delete canceled.\n";
            }
            break;
        }
        case 4: {
            cout << "\nEnter Customer/Member ID to update: ";
            cin >> id;

            auto itMem = memberDB.find(id);
            auto itCust = customerDB.find(id);

            if (itMem == memberDB.end() && itCust == customerDB.end()) {
                cout << "\n[Error] ID '" << id << "' not found. Update canceled.\n";
                break;
            }

            cout << "\n--- SELECT FIELD TO UPDATE ---\n";
            cout << "1. Email Address\n";
            cout << "2. Phone Number\n";
            cout << "3. Password\n";
            cout << "Select option (1-3): ";

            int updateChoice = 0;
            if (!(cin >> updateChoice)) {
                clearInput();
                cout << "[Error] Invalid selection. Update canceled.\n";
                break;
            }

            switch (updateChoice) {
            case 1: { // Update Email
                string newEmail;
                while (true) {
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
                }
                if (itMem != memberDB.end()) itMem->second.emailMember = newEmail;
                else itCust->second.emailCustomer = newEmail;
                cout << "\n[Success] Email updated successfully for ID '" << id << "'!\n";
                break;
            }
            case 2: { // Update Phone Number
                string newPhone;
                cout << "Enter new Phone Number: ";
                cin >> newPhone;
                if (itMem != memberDB.end()) itMem->second.phoneMember = newPhone;
                else itCust->second.phoneCustomer = newPhone;
                cout << "\n[Success] Phone number updated successfully for ID '" << id << "'!\n";
                break;
            }
            case 3: { // Update Password
                string newPass;
                while (true) {
                    cout << "Enter new Password (min 8 chars, letter & digit): ";
                    cin >> newPass;
                    if (isValidPassword(newPass)) break;
                    cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
                }
                if (itMem != memberDB.end()) itMem->second.passwordMember = newPass;
                else itCust->second.passwordCustomer = newPass;
                cout << "\n[Success] Password updated successfully for ID '" << id << "'!\n";
                break;
            }
            default:
                cout << "\n[Error] Invalid option selected. Update canceled.\n";
            }
            break;
        }
        default:
            cout << "Invalid option. Please enter 1 to 5.\n";
        }
    }
}


int main() {

    mainMenu();


	return 0;
}



