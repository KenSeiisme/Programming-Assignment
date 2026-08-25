#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits> 
#include <cctype>
#include <algorithm>
#include <utility>
#include <ctime>

using namespace std;

// Data structure for Customer details
struct Customer {
    string idCustomer;
    string nameCustomer;
    string genderCustomer;
    string phoneCustomer;
    string emailCustomer;
    string passwordCustomer;
};

// Data structure for Member details
struct Member {
    string idMember;
    string nameMember;
    string genderMember;
    string phoneMember;
    string emailMember;
    string passwordMember;
};

// Data structure for Salon Staff details
struct Staff {
    string idStaff;
    string nameStaff;
    string genderStaff;
    string phoneStaff;
    string emailStaff;
    string passwordStaff;
    string positionStaff;
};

// Define timeslot set
struct Timeslot {
    int num;
    string time;
    string appointmentID;
    bool isBooked;
    string staffID;
    string staffName;
    string customerID;
    string customerName;
    string service;
    string status;
};

// Global ID counters
int customerCounter = 1005;
int memberCounter = 1005;
int staffCounter = 1011;
int appointmentCounter = 1001;

const int MAX_CUSTOMERS = 100;
const int MAX_MEMBERS = 100;
const int MAX_STAFF = 100;

int customerCount = 4;
int memberCount = 4;
int staffCount = 10;

// Total slots and days in month
const int TOTAL_SLOTS = 7;
const int DAYS_IN_MONTH = 31;

Timeslot defaultDaySlots[TOTAL_SLOTS] = {
    {1, "09:00 AM - 11:00 AM", "", false, "", "", "", "", "", ""},
    {2, "11:00 AM - 01:00 PM", "", false, "", "", "", "", "", ""},
    {3, "01:00 PM - 03:00 PM", "", false, "", "", "", "", "", ""},
    {4, "03:00 PM - 05:00 PM", "", false, "", "", "", "", "", ""},
    {5, "05:00 PM - 07:00 PM", "", false, "", "", "", "", "", ""},
    {6, "07:00 PM - 09:00 PM", "", false, "", "", "", "", "", ""},
    {7, "09:00 PM - 11:00 PM", "", false, "", "", "", "", "", ""}
};

Timeslot schedule[DAYS_IN_MONTH][TOTAL_SLOTS];

// Color word for appointment
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[93m";

Customer customerDB[MAX_CUSTOMERS] = {
    {"C1001", "Viknesh a/l Vijayan", "Male", "013-5678901", "viknesh129@gmail.com", "SolarPower2026!"},
    {"C1002", "Priya a/p Anbalagan", "Female", "014-6789012", "priya59@gmail.com", "Bikoma72!q"},
    {"C1003", "Teo Bao Bin", "Male", "016-7890123", "bb520go@gmail.com", "k8n9vp2m5x"},
    {"C1004", "Lily Yee", "Female", "017-8901234", "lilyisflower43@gmail.com", "K0N9VP2M5Z"}
};

Member memberDB[MAX_MEMBERS] = {
    {"M1001", "Eren Chew", "Male", "017-6543210", "erenono097@gmail.com", "k8N9vP2mX5"},
    {"M1002", "Tan Shin Nang", "Male", "018-2345678", "startan67@gmail.com", "b9M3zP7wR#"},
    {"M1003", "Noor Siti", "Female", "011-12345678", "siti945@gmail.com", "TungtSahur345"},
    {"M1004", "Alice Low", "Female", "019-5678901", "alicelow@gmail.com", "76WhatheDogDoing//"}
};

Staff staffDB[MAX_STAFF] = {
    {"STF1001", "Kim Ji Soo", "Female", "011-2233445", "jisookim123@gmail.com", "k8N9vP2m!", "Hair Stylist"},
    {"STF1002", "Sarah Jenkins", "Female", "017-8899001", "sarah36@gmail.com", "r9W!z2#k&", "Hair Color Stylist"},
    {"STF1003", "Sim Jia Yih", "Female", "011-10546505", "jiayih@gmail.com", "j7N5qW8mX2z%", "Hair Color Stylist"},
    {"STF1004", "Lim Xiao Qing", "Female", "018-9032655", "xiaoqing@gmail.com", "w9K4zM2pR!", "Nail Technician"},
    {"STF1005", "Lim Cai Xuan", "Female", "012-6125939", "caixuan@gmail.com", "t3X8qP5mL9#", "Receptionist"},
    {"STF1006", "Lee Hao Zheng", "Male", "016-5011218", "haozheng@gmail.com", "y8M2!zR9#vW@", "Nail Technician"},
    {"STF1007", "Ng Jun Sheng", "Male", "017-3746889", "junsheng@gmail.com", "h3N9!qX5$k&", "Receptionist"},
    {"STF1008", "Lao Teh", "Male", "017-88990012", "laoteh@gmail.com", "c9P5!xT2$w@", "Skincare Specialist"},
    {"STF1009", "Noor Shahirah", "Female", "010-86043225", "shahirah@gmail.com", "k6P3#wT8$mL&", "Skincare Specialist"},
    {"STF1010", "Roslizawati", "Female", "017-88378451", "rosealwaysrosie@gmail.com", "But860//wt=", "Hair Stylist"}
};

// Function Declarations
void logo();
void mainMenu();
void customerPortal();
void registerCustomer();
void registerMember();
void customerMemberLogin();
void staffPortal();
void registerStaff();
void staffLogin();
void showCustomerMemberUI(const string& userId, const string& accountType);
void memberCustomerProfile(const string& userId, const string& accountType);
void viewProfile(const string& userId, const string& accountType);
void editProfileCMUI(const string& userId, const string& accountType);
void showStaffUI(const string& username);
void memberManagement();
void staffManagement();
void showStaffList();
void showMemberCustomerList();
void clearInput();
bool isValidEmail(const string& email);
bool isValidPassword(const string& pass);
bool isValidPhoneNumber(const string& phone);
bool isValidName(const string& name);
void AppointmentStaff();
void AppointmentCustomer(const string& currentUserId, const string& currentUserName);
void ViewAllAppointment(const Timeslot schedule[], int size, string filterStaffID = "");
void getCurrentSystemTime(int& year, int& month, int& day, int& hour);
void CreateAppointmentStaff();
void CreateAppointmentCustomer(const string& customerID, const string& customerName);
void CancelAppointment(const string& currentUserId = "");
void RescheduleAppointment(const string& currentUserId = "");
void ViewStaffSchedule();
void initMonthlySchedule();

int main() {
    logo();
    mainMenu();
    return 0;
}

int findCustomerIndex(const string& id) {
    for (int i = 0; i < customerCount; ++i) {
        if (customerDB[i].idCustomer == id) return i;
    }
    return -1;
}

int findMemberIndex(const string& id) {
    for (int i = 0; i < memberCount; ++i) {
        if (memberDB[i].idMember == id) return i;
    }
    return -1;
}

int findStaffIndex(const string& id) {
    string searchID = id;
    transform(searchID.begin(), searchID.end(), searchID.begin(), ::toupper);

    for (int i = 0; i < staffCount; ++i) {
        string dbID = staffDB[i].idStaff;
        transform(dbID.begin(), dbID.end(), dbID.begin(), ::toupper);

        if (dbID == searchID) return i;
    }
    return -1;
}

bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
        if (!isalpha(c) && !isspace(c) && c != '\'' && c != '-') return false;
    }
    return true;
}

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

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void logo() {
    cout << R"(
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
 ######    ######       ######     ###    ##        #######  ##    ##    
##    ##  ##    ##     ##    ##   ## ##   ##       ##     ## ###   ##    
##        ##           ##        ##   ##  ##       ##     ## ####  ##    
##   #### ##   ####     ######  ##     ## ##       ##     ## ## ## ##    
##    ##  ##    ##           ## ######### ##       ##     ## ##  ####    
##    ##  ##    ##     ##    ## ##     ## ##       ##     ## ##   ###    
 ######    ######       ######  ##     ## ########  #######  ##    ##    
##### ##### ##### ##### ##### ##### ##### ##### ##### ##### ##### #####  
)" << endl;
}

void mainMenu() {
    int choice = 0;
    while (true) {
        cout << "--------------MAIN SYSTEM MENU--------------\n";
        cout << "[ 1 ] Customer / Member\n";
        cout << "[ 2 ] Staff\n";
        cout << "[ 3 ] Exit System\n";
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

void customerPortal() {
    int choice = 0;
    while (true) {
        cout << "============ CUSTOMER/MEMBER PORTAL ============\n";
        cout << "[ 1 ] Customer Registration\n";
        cout << "[ 2 ] Member Registration\n";
        cout << "[ 3 ] Customer / Member Login\n";
        cout << "[ 4 ] Exit (Return to Main Menu)\n";
        cout << "Select option (1-4): ";

        if (!(cin >> choice)) {
            clearInput();
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
            customerMemberLogin();
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
    if (customerCount >= MAX_CUSTOMERS) {
        cout << "[Error] Customer database capacity reached!\n";
        return;
    }

    Customer newCustomer;
    cout << "\n--- NEW CUSTOMER REGISTRATION ---\n";
    string customerGeneratedID = "C" + to_string(customerCounter++);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newCustomer.nameCustomer);
        if (isValidName(newCustomer.nameCustomer)) break;
        cout << "[Error] Invalid name! Only can use alphabet. Try again.\n";
    }

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
        cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
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
    newCustomer.idCustomer = customerGeneratedID;
    customerDB[customerCount++] = newCustomer;

    cout << "\n[Success] Customer registration completed!\n";
    cout << "============================================\n";
    cout << " Assigned Customer ID : " << customerGeneratedID << "\n";
    cout << " Name                 : " << newCustomer.nameCustomer << "\n";
    cout << " Phone                : " << newCustomer.phoneCustomer << "\n";
    cout << " Email                : " << newCustomer.emailCustomer << "\n";
    cout << "============================================\n";
    cout << "Please keep your Customer ID to log in.\n";
}

void registerMember() {
    if (memberCount >= MAX_MEMBERS) {
        cout << "[Error] Member database capacity reached!\n";
        return;
    }
    char response;
    Member newMember;
    cout << "\n--- NEW MEMBER REGISTRATION ---\n";

    cout << "Do you already pay the Member Fee ? (Y=yes,N=no): ";
    cin >> response;
    response = toupper(response);

    if (response == 'Y') {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        while (true) {
            cout << "Enter Full Name: ";
            getline(cin, newMember.nameMember);
            if (isValidName(newMember.nameMember)) break;
            cout << "[Error] Invalid name! Only can use alphabet. Try again.\n";
        }

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

        while (true) {
            cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
            cin >> newMember.phoneMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPhoneNumber(newMember.phoneMember)) break;
            cout << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n";
        }

        while (true) {
            cout << "Enter Email Address (must end with @gmail.com): ";
            cin >> newMember.emailMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidEmail(newMember.emailMember)) break;
            cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
        }

        while (true) {
            cout << "Enter Password (min 8 chars, must contain letters & digits): ";
            cin >> newMember.passwordMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPassword(newMember.passwordMember)) break;
            cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
        }

        string memberGeneratedID = "M" + to_string(memberCounter++);
        newMember.idMember = memberGeneratedID;
        memberDB[memberCount++] = newMember;

        cout << "\n[Success] Member registration completed!\n";
        cout << "================================================\n";
        cout << " Assigned Member ID : " << memberGeneratedID << "\n";
        cout << " Name               : " << newMember.nameMember << "\n";
        cout << " Phone              : " << newMember.phoneMember << "\n";
        cout << " Email              : " << newMember.emailMember << "\n";
        cout << "=================================================\n";
        cout << "Please keep your Member ID to log in.\n";
    }
    else {
        cout << "Please pay Member Fee first at the counter." << endl;
    }
}

void customerMemberLogin() {
    string idCustomerMember, passCustomerMember;
    cout << "\n--- CUSTOMER / MEMBER LOGIN ---\n";
    cout << "Customer ID / Member ID: ";
    cin >> idCustomerMember;
    cout << "Password: ";
    cin >> passCustomerMember;

    int memIdx = findMemberIndex(idCustomerMember);
    if (memIdx != -1 && memberDB[memIdx].passwordMember == passCustomerMember) {
        cout << "\nMember login successful!\n";
        showCustomerMemberUI(idCustomerMember, "Member");
        return;
    }

    int custIdx = findCustomerIndex(idCustomerMember);
    if (custIdx != -1 && customerDB[custIdx].passwordCustomer == passCustomerMember) {
        cout << "\nCustomer login successful!\n";
        showCustomerMemberUI(idCustomerMember, "Customer");
        return;
    }

    cout << "\n[Error] Invalid Customer/Member ID or Password.\n";
}

void showCustomerMemberUI(const string& userId, const string& accountType) {
    int choice = 0;
    string name;
    if (accountType == "Member") {
        int idx = findMemberIndex(userId);
        name = memberDB[idx].nameMember;
    }
    else {
        int idx = findCustomerIndex(userId);
        name = customerDB[idx].nameCustomer;
    }
    while (true) {
        cout << "\n************************************************\n";
        cout << "           CUSTOMER/MEMBER DASHBOARD           \n";
        cout << " Welcome: " << name << " (" << accountType << " - " << userId << ")\n";
        cout << "**************************************************\n";
        cout << "[ 1 ] Your Profile\n";
        cout << "[ 2 ] Service\n";
        cout << "[ 3 ] Appointment\n";
        cout << "[ 4 ] Billing\n";
        cout << "[ 5 ] Logout\n";
        cout << "Select action: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }
        if (choice == 5) {
            cout << "Logging out of Customer Dashboard...\n";
            break;
        }
        switch (choice) {
        case 1:
            memberCustomerProfile(userId, accountType);
            break;
        case 2:
            cout << "\n-> [Customer UI] Service module selected.\n";
            break;
        case 3:
            cout << "\n-> [Customer UI] Appointment module selected.\n";
            AppointmentCustomer(userId, name);
            break;
        case 4:
            cout << "\n-> [Customer UI] Billing module selected.\n";
            break;
        default:
            cout << "Invalid selection.\n";
        }
    }
}

void memberCustomerProfile(const string& userId, const string& accountType) {
    int choice = 0;
    while (true) {
        cout << "============ MEMBER/CUSTOMER PROFILE ============\n";
        cout << "[ 1 ] View your profile\n";
        cout << "[ 2 ] Edit Profile\n";
        cout << "[ 3 ] Exit (Return to Main Menu)\n";
        cout << "Select option (1-3): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input.\n";
            continue;
        }

        switch (choice) {
        case 1:
            viewProfile(userId, accountType);
            break;
        case 2:
            editProfileCMUI(userId, accountType);
            break;
        case 3:
            cout << "Returning to Main Menu...\n";
            return;
        default:
            cout << "Invalid option. Try again.\n";
        }
    }
}

void viewProfile(const string& userId, const string& accountType) {
    cout << "\n========================================\n";
    cout << "           YOUR PROFILE INFO            \n";
    cout << "========================================\n";
    if (accountType == "Member") {
        int idx = findMemberIndex(userId);
        cout << " ID           : " << userId << "\n";
        cout << " Account Type : " << accountType << "\n";
        cout << " Name         : " << memberDB[idx].nameMember << "\n";
        cout << " Gender       : " << memberDB[idx].genderMember << "\n";
        cout << " Phone        : " << memberDB[idx].phoneMember << "\n";
        cout << " Email        : " << memberDB[idx].emailMember << "\n";
    }
    else {
        int idx = findCustomerIndex(userId);
        cout << " ID           : " << userId << "\n";
        cout << " Account Type : " << accountType << "\n";
        cout << " Name         : " << customerDB[idx].nameCustomer << "\n";
        cout << " Gender       : " << customerDB[idx].genderCustomer << "\n";
        cout << " Phone        : " << customerDB[idx].phoneCustomer << "\n";
        cout << " Email        : " << customerDB[idx].emailCustomer << "\n";
    }
    cout << "========================================\n";
}

void editProfileCMUI(const string& userId, const string& accountType) {
    int updateChoice = 0;
    while (true) {
        cout << "\n--- SELECT FIELD TO EDIT OR CHANGE ---\n";
        cout << "1. Email Address\n";
        cout << "2. Phone Number\n";
        cout << "3. Password\n";
        cout << "4. Cancel & Return\n";
        cout << "Select option (1-4): ";

        if (!(cin >> updateChoice)) {
            clearInput();
            cout << "[Error] Invalid selection. Try again.\n";
            continue;
        }

        if (updateChoice == 4) {
            break;
        }

        switch (updateChoice) {
        case 1: {
            string newEmail;
            while (true) {
                cout << "Enter new Email Address (must end with @gmail.com): ";
                cin >> newEmail;
                if (isValidEmail(newEmail)) break;
                cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
            }
            if (accountType == "Member") memberDB[findMemberIndex(userId)].emailMember = newEmail;
            else customerDB[findCustomerIndex(userId)].emailCustomer = newEmail;

            cout << "\n[Success] Email updated successfully!\n";
            break;
        }
        case 2: {
            string newPhone;
            cout << "Enter new Phone Number: ";
            cin >> newPhone;
            if (accountType == "Member") memberDB[findMemberIndex(userId)].phoneMember = newPhone;
            else customerDB[findCustomerIndex(userId)].phoneCustomer = newPhone;

            cout << "\n[Success] Phone number updated successfully!\n";
            break;
        }
        case 3: {
            string newPass;
            while (true) {
                cout << "Enter new Password (min 8 chars, letter & digit): ";
                cin >> newPass;
                if (isValidPassword(newPass)) break;
                cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
            }
            if (accountType == "Member") memberDB[findMemberIndex(userId)].passwordMember = newPass;
            else customerDB[findCustomerIndex(userId)].passwordCustomer = newPass;

            cout << "\n[Success] Password updated successfully!\n";
            break;
        }
        default:
            cout << "\n[Error] Invalid option selected. Try again.\n";
        }
    }
}

void staffPortal() {
    int choice = 0;
    while (true) {
        cout << "============ STAFF PORTAL ============\n";
        cout << "[ 1 ] Staff Registration\n";
        cout << "[ 2 ] Staff Login\n";
        cout << "[ 3 ] Exit (Return to Main Menu)\n";
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
    if (staffCount >= MAX_STAFF) {
        cout << "[Error] Staff database capacity reached!\n";
        return;
    }

    Staff newStaff;
    cout << "\n--- NEW HAIR SALON STAFF REGISTRATION ---\n";
    string generatedID = "STF" + to_string(staffCounter++);

    clearInput();

    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newStaff.nameStaff);
        if (isValidName(newStaff.nameStaff)) break;
        cout << "[Error] Invalid name! Alphabet only. Try again.\n";
    }

    string genderInput;
    while (true) {
        cout << "Enter Gender (m/f): ";
        cin >> genderInput;
        clearInput();

        if (genderInput == "m" || genderInput == "M") {
            newStaff.genderStaff = "Male";
            break;
        }
        else if (genderInput == "f" || genderInput == "F") {
            newStaff.genderStaff = "Female";
            break;
        }
        else {
            cout << "[Error] Invalid gender! Enter 'm' or 'f'.\n";
        }
    }

    while (true) {
        cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
        cin >> newStaff.phoneStaff;
        clearInput();
        if (isValidPhoneNumber(newStaff.phoneStaff)) break;
        cout << "[Error] Invalid phone number format.\n";
    }

    while (true) {
        cout << "Enter Email Address (must end with @gmail.com): ";
        cin >> newStaff.emailStaff;
        clearInput();
        if (isValidEmail(newStaff.emailStaff)) break;
        cout << "[Error] Invalid email address.\n";
    }

    while (true) {
        cout << "Enter Password (Minimun 8 chars, must contain letters & digits): ";
        cin >> newStaff.passwordStaff;
        clearInput();
        if (isValidPassword(newStaff.passwordStaff)) break;
        cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
    }

    int posChoice = 0;
    while (true) {
        cout << "\nWhat position do you want to hire for?\n";
        cout << "[ 1 ] Hair Stylist\n[ 2 ] Skincare Specialist\n[ 3 ] Hair Color Stylist\n[ 4 ] Nail Technician\n[ 5 ] Receptionist\n";
        cout << "Select position (1-5): ";

        if (cin >> posChoice && posChoice >= 1 && posChoice <= 5) {
            clearInput();
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
    newStaff.idStaff = generatedID;
    staffDB[staffCount++] = newStaff;

    cout << "\n[Success] Staff registration completed!\n";
    cout << "========================================\n";
    cout << " Assigned Staff ID : " << generatedID << "\n";
    cout << " Name              : " << newStaff.nameStaff << "\n";
    cout << " Position          : " << newStaff.positionStaff << "\n";
    cout << " Phone             : " << newStaff.phoneStaff << "\n";
    cout << " Email             : " << newStaff.emailStaff << "\n";
    cout << "========================================\n";
    cout << "Please keep your Staff ID to log in.\n\n";
}

void staffLogin() {
    string idStaff, passStaff;
    cout << "\n--- STAFF LOGIN ---\n";

    cout << "Staff ID: ";
    cin >> idStaff;

    cout << "Password: ";
    cin >> passStaff;
    clearInput();

    int idx = findStaffIndex(idStaff);
    if (idx != -1 && staffDB[idx].passwordStaff == passStaff) {
        cout << "\nStaff authentication successful!\n";
        cout << "Welcome, " << staffDB[idx].nameStaff << " (" << staffDB[idx].positionStaff << ")!\n";
        showStaffUI(idStaff);
    }
    else {
        cout << "\n[Error] Invalid Staff credentials.\n";
    }
} // FIXED: Removed extra trailing closing brace here

void showStaffUI(const string& username) {
    int choice = 0;
    int idx = findStaffIndex(username);
    while (true) {
        cout << "\n************************************************************\n";
        cout << "                STAFF CONTROL PANEL           \n";
        cout << " Staff ID: " << username << " | " << staffDB[idx].nameStaff
            << " (" << staffDB[idx].positionStaff << ")\n";
        cout << "\n************************************************************\n";
        cout << "[ 1 ] Customer/Member Info Management\n";
        cout << "[ 2 ] Staff Info Management\n";
        cout << "[ 3 ] Service management\n";
        cout << "[ 4 ] Appointment Management\n";
        cout << "[ 5 ] View History\n";
        cout << "[ 6 ] Reporting\n";
        cout << "[ 7 ] Logout\n";
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
        case 1: {
            string confirmID;
            cout << "============= STAFF VERIFICATION REQUIRED =============\n";
            cout << "Enter Staff ID to access Member Management: ";
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int confirmIdx = findStaffIndex(confirmID);
            if (confirmIdx != -1 && confirmID == username) {
                cout << "\n[Access Granted] Verified identity: " << staffDB[confirmIdx].nameStaff << "\n";
                memberManagement();
            }
            else {
                cout << "\n[Access Denied] Invalid or mismatched Staff ID!\n";
            }
            break;
        }
        case 2: {
            string confirmID;
            cout << "============= STAFF VERIFICATION REQUIRED =============\n";
            cout << "Enter Staff ID to access Staff Management: ";
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int confirmIdx = findStaffIndex(confirmID);
            if (confirmIdx != -1 && confirmID == username) {
                cout << "\n[Access Granted] Verified identity: " << staffDB[confirmIdx].nameStaff << "\n";
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
            AppointmentStaff();
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
    cout << right << setw(70) << "< TABLE STAFF >" << endl;
    string border = "+----------+------------------------+----------+----------------+----------------------------+----------------------+----------------------+";

    cout << "\n" << border << "\n";
    cout << "| " << left << setw(9) << "Staff ID"
        << "| " << setw(22) << "Name"
        << " | " << setw(8) << "Gender"
        << " | " << setw(14) << "Phone number"
        << " | " << setw(26) << "Email"
        << " | " << setw(20) << "Password"
        << " | " << setw(20) << "Position" << " |\n";

    cout << border << "\n";

    for (int i = 0; i < staffCount; ++i) {
        cout << "| " << left << setw(9) << staffDB[i].idStaff
            << "| " << setw(22) << staffDB[i].nameStaff
            << " | " << setw(8) << staffDB[i].genderStaff
            << " | " << setw(14) << staffDB[i].phoneStaff
            << " | " << setw(26) << staffDB[i].emailStaff
            << " | " << setw(20) << staffDB[i].passwordStaff
            << " | " << setw(20) << staffDB[i].positionStaff << " |\n";
        cout << border << "\n";
    }
}

void staffManagement() {
    int choice = 0;
    while (true) {
        cout << "========== STAFF MANAGEMENT MENU ==========\n";
        cout << "[ 1 ] View Staff Table\n";
        cout << "[ 2 ] Search Staff\n";
        cout << "[ 3 ] Delete Staff\n";
        cout << "[ 4 ] Update Staff Information\n";
        cout << "[ 5 ] Return to Staff Control Panel\n";
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

        string idStaff;
        switch (choice) {
        case 1: {
            showStaffList();
            break;
        }
        case 2: {
            cout << "\nEnter Staff ID to search: ";
            cin >> idStaff;

            int idx = findStaffIndex(idStaff);
            if (idx != -1) {
                cout << "\n[Found] ID: " << staffDB[idx].idStaff
                    << " | Name: " << staffDB[idx].nameStaff
                    << " | Gender: " << staffDB[idx].genderStaff
                    << " | Phone: " << staffDB[idx].phoneStaff
                    << " | Email: " << staffDB[idx].emailStaff
                    << " | Position: " << staffDB[idx].positionStaff << "\n";
            }
            else {
                cout << "\n[Error] Staff ID '" << idStaff << "' not found.\n";
            }
            break;
        }
        case 3: {
            cout << "\nEnter Staff ID to delete: ";
            cin >> idStaff;

            int idx = findStaffIndex(idStaff);
            if (idx != -1) {
                for (int i = idx; i < staffCount - 1; ++i) {
                    staffDB[i] = staffDB[i + 1];
                }
                staffCount--;
                cout << "\n[Success] Staff '" << idStaff << "' deleted successfully.\n";
            }
            else {
                cout << "\n[Error] Staff ID '" << idStaff << "' not found. Delete canceled.\n";
            }
            break;
        }
        case 4: {
            cout << "\nEnter Staff ID to update: ";
            cin >> idStaff;

            int idx = findStaffIndex(idStaff);
            if (idx == -1) {
                cout << "\n[Error] Staff ID '" << idStaff << "' not found. Update canceled.\n";
                break;
            }

            cout << "\n========== SELECT FIELD TO UPDATE ==========\n";
            cout << "[ 1 ] Email Address\n";
            cout << "[ 2 ] Phone Number\n";
            cout << "[ 3 ] Password\n";
            cout << "[ 4 ] Position\n";
            cout << "Select option (1-4): ";

            int updateChoice = 0;
            if (!(cin >> updateChoice)) {
                clearInput();
                cout << "[Error] Invalid selection. Update canceled.\n";
                break;
            }

            switch (updateChoice) {
            case 1: {
                string newEmail;
                while (true) {
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
                }
                staffDB[idx].emailStaff = newEmail;
                cout << "\n[Success] Email updated successfully for Staff ID '" << idStaff << "'!\n";
                break;
            }
            case 2: {
                string newPhone;
                cout << "Enter new Phone Number: ";
                cin >> newPhone;
                staffDB[idx].phoneStaff = newPhone;
                cout << "\n[Success] Phone number updated successfully for Staff ID '" << idStaff << "'!\n";
                break;
            }
            case 3: {
                string newPass;
                while (true) {
                    cout << "Enter new Password (min 8 chars, letter & digit): ";
                    cin >> newPass;
                    if (isValidPassword(newPass)) break;
                    cout << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n";
                }
                staffDB[idx].passwordStaff = newPass;
                cout << "\n[Success] Password updated successfully for Staff ID '" << idStaff << "'!\n";
                break;
            }
            case 4: {
                string newPos;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter new Hair Salon Position: ";
                getline(cin, newPos);
                staffDB[idx].positionStaff = newPos;
                cout << "\n[Success] Position updated successfully for Staff ID '" << idStaff << "'!\n";
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
    cout << right << setw(75) << "< TABLE MEMBER & CUSTOMER >" << endl;

    string border = "+----------+------------------------+----------+----------------+----------------------------+----------------------+";

    cout << "\n" << border << "\n";
    cout << "| " << left << setw(8) << "ID"
        << " | " << setw(22) << "Name"
        << " | " << setw(8) << "Gender"
        << " | " << setw(14) << "Phone number"
        << " | " << setw(26) << "Email"
        << " | " << setw(20) << "Password" << " |\n";

    cout << border << "\n";

    for (int i = 0; i < memberCount; ++i) {
        cout << "| " << left << setw(8) << memberDB[i].idMember
            << " | " << setw(22) << memberDB[i].nameMember
            << " | " << setw(8) << memberDB[i].genderMember
            << " | " << setw(14) << memberDB[i].phoneMember
            << " | " << setw(26) << memberDB[i].emailMember
            << " | " << setw(20) << memberDB[i].passwordMember << " |\n";
        cout << border << "\n";
    }

    for (int i = 0; i < customerCount; ++i) {
        cout << "| " << left << setw(8) << customerDB[i].idCustomer
            << " | " << setw(22) << customerDB[i].nameCustomer
            << " | " << setw(8) << customerDB[i].genderCustomer
            << " | " << setw(14) << customerDB[i].phoneCustomer
            << " | " << setw(26) << customerDB[i].emailCustomer
            << " | " << setw(20) << customerDB[i].passwordCustomer << " |\n";
        cout << border << "\n";
    }
}

void memberManagement() {
    int choice = 0;
    while (true) {
        cout << "========== CUSTOMER/MEMBER MANAGEMENT MENU ==========\n";
        cout << "[ 1 ] View Customer/Member Table\n";
        cout << "[ 2 ] Search Customer/Member\n";
        cout << "[ 3 ] Delete Customer/Member\n";
        cout << "[ 4 ] Update Customer/Member Information\n";
        cout << "[ 5 ] Return to Staff Control Panel\n";
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

            int memIdx = findMemberIndex(id);
            if (memIdx != -1) {
                cout << "\n[Found] ID: " << memberDB[memIdx].idMember
                    << " | Type: Member | Name: " << memberDB[memIdx].nameMember
                    << " | Phone: " << memberDB[memIdx].phoneMember
                    << " | Email: " << memberDB[memIdx].emailMember << "\n";
            }
            else {
                int custIdx = findCustomerIndex(id);
                if (custIdx != -1) {
                    cout << "\n[Found] ID: " << customerDB[custIdx].idCustomer
                        << " | Type: Standard Customer | Name: " << customerDB[custIdx].nameCustomer
                        << " | Phone: " << customerDB[custIdx].phoneCustomer
                        << " | Email: " << customerDB[custIdx].emailCustomer << "\n";
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

            int memIdx = findMemberIndex(id);
            if (memIdx != -1) {
                for (int i = memIdx; i < memberCount - 1; ++i) {
                    memberDB[i] = memberDB[i + 1];
                }
                memberCount--;
                cout << "\n[Success] Member '" << id << "' deleted successfully.\n";
            }
            else {
                int custIdx = findCustomerIndex(id);
                if (custIdx != -1) {
                    for (int i = custIdx; i < customerCount - 1; ++i) {
                        customerDB[i] = customerDB[i + 1];
                    }
                    customerCount--;
                    cout << "\n[Success] Customer '" << id << "' deleted successfully.\n";
                }
                else {
                    cout << "\n[Error] ID '" << id << "' not found. Delete canceled.\n";
                }
            }
            break;
        }
        case 4: {
            cout << "\nEnter Customer/Member ID to update: ";
            cin >> id;

            int memIdx = findMemberIndex(id);
            int custIdx = findCustomerIndex(id);

            if (memIdx == -1 && custIdx == -1) {
                cout << "\n[Error] ID '" << id << "' not found. Update canceled.\n";
                break;
            }

            cout << "\n========== SELECT FIELD TO UPDATE ==========\n";
            cout << "[ 1 ] Email Address\n";
            cout << "[ 2 ] Phone Number\n";
            cout << "[ 3 ] Cancel & Return\n";
            cout << "Select option (1-3): ";

            int updateChoice = 0;
            if (!(cin >> updateChoice)) {
                clearInput();
                cout << "[Error] Invalid selection. Update canceled.\n";
                break;
            }
            if (updateChoice == 3) {
                break;
            }

            switch (updateChoice) {
            case 1: {
                string newEmail;
                while (true) {
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n";
                }
                if (memIdx != -1) memberDB[memIdx].emailMember = newEmail;
                else customerDB[custIdx].emailCustomer = newEmail;
                cout << "\n[Success] Email updated successfully for ID '" << id << "'!\n";
                break;
            }
            case 2: {
                string newPhone;
                cout << "Enter new Phone Number (e.g.: xxx-xxxxxxxx): ";
                cin >> newPhone;
                if (memIdx != -1) memberDB[memIdx].phoneMember = newPhone;
                else customerDB[custIdx].phoneCustomer = newPhone;
                cout << "\n[Success] Phone number updated successfully for ID '" << id << "'!\n";
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

void AppointmentStaff() {

    initMonthlySchedule();

    int option = 0;
    
    do {
        cout << "\nWelcome to the Appointment Scheduler!\n" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "1. View All Appointment" << endl;
        cout << "2. Create a New Appointment" << endl;
        cout << "3. Cancel Appointment" << endl;
        cout << "4. Reschedule Appointment" << endl;
        cout << "5. View Staff Schedule" << endl;
        cout << "6. Appointment Marking" << endl;
        cout << "0. Exit\n" << endl;

        cout << "Select option: ";
        cin >> option;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number from 1 to 6." << endl;
            cout << "\nPress Enter to return to the menu...";
            cin.get();
            continue;
        }

        switch (option) {
        case 1: {
            int day;
            cout << "Enter day (1 to 31): ";
            cin >> day;
            if (cin.fail() || day < 1 || day > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid day! Please enter a day from 1 to 31." << endl;
                break;
            }

            int dayIndex = day - 1;
            cout << "You selected: View All Appointment for Day " << day << endl;
            ViewAllAppointment(schedule[dayIndex], TOTAL_SLOTS);
            break;
        }
        case 2: {
            cout << "You selected: Create a New Appointment" << endl;
            CreateAppointmentStaff();
            break;
        }
        case 3:
            cout << "You selected: Cancel Appointment" << endl;
            CancelAppointment();
            break;
        case 4:
            cout << "You selected: Reschedule Appointment" << endl;
            RescheduleAppointment();
            break;
        case 5:
            cout << "You selected: View Staff Schedule" << endl;
            ViewStaffSchedule();
            break;
        case 6:
            cout << "You selected: Appointment Marking" << endl;
            break;
        case 7:
            cout << "Returning to Staff Menu..." << endl;
            return;
        default:
            cout << "Invalid option. Please select a valid option from the menu." << endl;
        }

        if (option != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (option != 0);
}

void AppointmentCustomer(const string& currentUserId, const string& currentUserName) {

    initMonthlySchedule();

    int option = 0;

    do {
        cout << "\nWelcome to the Appointment Scheduler!\n" << endl;
        cout << "Please select an option from the menu below:" << endl;
        cout << "1. Create a New Appointment" << endl;
        cout << "2. Cancel Appointment" << endl;
        cout << "3. Reschedule Appointment" << endl;
        cout << "0. Exit\n" << endl;

        cout << "Select option: ";
        cin >> option;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number from 1 to 3." << endl;
            cout << "\nPress Enter to return to the menu...";
            cin.get();
            continue;
        }

        switch (option) {
        case 1: {
            cout << "You selected: Create a New Appointment" << endl;
            CreateAppointmentCustomer(currentUserId, currentUserName);
            break;
        }
        case 2: {
            cout << "You selected: Cancel Appointment" << endl;
            CancelAppointment(currentUserId);
            break;
        }
        case 3:
            cout << "You selected: Reschedule Appointment" << endl;
            RescheduleAppointment(currentUserId);
            break;
        default:
            cout << "Invalid option. Please select a valid option from the menu." << endl;
        }

        if (option != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (option != 0);
}

void ViewAllAppointment(const Timeslot schedule[], int size, string filterStaffID) {
    int w_num = string(" ").length();
    int w_time = string("Time Slot").length();
    int w_id = string("Appointment ID").length();
    int w_status = string("Status").length();
    int w_staffID = string("Staff ID").length();
    int w_staffName = string("Staff Name").length();
    int w_custID = string("Customer ID").length();
    int w_custName = string("Customer Name").length();
    int w_service = string("Service").length();

    for (int i = 0; i < size; i++) {
        if (!filterStaffID.empty() && schedule[i].staffID != filterStaffID && schedule[i].isBooked) {
            continue;
        }
        
        string AppointmentIDStr = schedule[i].isBooked ? schedule[i].appointmentID : "-";
        string statusStr = schedule[i].isBooked ? schedule[i].status : "Available";
        string staffIDStr = schedule[i].isBooked ? schedule[i].staffID : "-";
        string staffNameStr = schedule[i].isBooked ? schedule[i].staffName : "-";
        string custIDStr = schedule[i].isBooked ? schedule[i].customerID : "-";
        string custNameStr = schedule[i].isBooked ? schedule[i].customerName : "-";
        string serviceStr = (schedule[i].isBooked && !schedule[i].service.empty()) ? schedule[i].service : "-";

        //find table width
        w_num = max(w_num, (int)to_string(schedule[i].num).length());
        w_time = max(w_time, (int)schedule[i].time.length());
        w_id = max(w_id, (int)AppointmentIDStr.length());
        w_status = max(w_status, (int)statusStr.length());
        w_staffID = max(w_staffID, (int)staffIDStr.length());
        w_staffName = max(w_staffName, (int)staffNameStr.length());
        w_custID = max(w_custID, (int)custIDStr.length());
        w_custName = max(w_custName, (int)custNameStr.length());
        w_service = max(w_service, (int)serviceStr.length());
    }

    string separator
        = "+" + string(w_num + 2, '-')
        + "+" + string(w_time + 2, '-')
        + "+" + string(w_id + 2, '-')
        + "+" + string(w_status + 2, '-')
        + "+" + string(w_staffID + 2, '-')
        + "+" + string(w_staffName + 2, '-')
        + "+" + string(w_custID + 2, '-')
        + "+" + string(w_custName + 2, '-')
        + "+" + string(w_service + 2, '-') + "+";

    //header
    cout << separator << endl;
    cout << "| " << left << setw(w_num) << " " << " "
        << "| " << setw(w_time) << "Time Slot" << " "
        << "| " << setw(w_id) << "Appointment ID" << " "
        << "| " << setw(w_status) << "Status" << " "
        << "| " << setw(w_staffID) << "Staff ID" << " "
        << "| " << setw(w_staffName) << "Staff Name" << " "
        << "| " << setw(w_custID) << "Customer ID" << " "
        << "| " << setw(w_custName) << "Customer Name" << " "
        << "| " << setw(w_service) << "Service" << " |\n";

    cout << separator << endl;

    for (int i = 0; i < size; i++) {
        if (!filterStaffID.empty() && schedule[i].staffID != filterStaffID && schedule[i].isBooked) {
            continue;
        }

        //table info width
        string appointmentID = schedule[i].isBooked ? schedule[i].appointmentID : "-";
        string statusAppointment = schedule[i].isBooked ? schedule[i].status : "Available";
        string statuscolor = schedule[i].isBooked ? RED : GREEN;
        string staffID = schedule[i].isBooked ? schedule[i].staffID : "-";
        string staffname = schedule[i].isBooked ? schedule[i].staffName : "-";
        string customerID = schedule[i].isBooked ? schedule[i].customerID : "-";
        string customerName = schedule[i].isBooked ? schedule[i].customerName : "-";
        string service = (schedule[i].isBooked && !schedule[i].service.empty()) ? schedule[i].service : "-";

        cout << "| " << left << setw(w_num) << schedule[i].num << " "
            << "| " << setw(w_time) << schedule[i].time << " "
            << "| " << setw(w_id) << appointmentID << " "
            << "| " << statuscolor << setw(w_status) << statusAppointment << RESET << " "
            << "| " << setw(w_staffID) << staffID << " "
            << "| " << setw(w_staffName) << staffname << " "
            << "| " << setw(w_custID) << customerID << " "
            << "| " << setw(w_custName) << customerName << " "
            << "| " << setw(w_service) << service << " "
            << "|" << endl;
    }
    cout << separator << endl;
}

void initMonthlySchedule() {
    for (int day = 0; day < DAYS_IN_MONTH; day++) {
        for (int slot = 0; slot < TOTAL_SLOTS; slot++) {
            schedule[day][slot] = defaultDaySlots[slot];
        }
    }
}

void getCurrentSystemTime(int& year, int& month, int& day, int& hour) {
    time_t now = time(0);
    tm ltm;
    localtime_s(&ltm, &now);

    year = 1900 + ltm.tm_year;
    month = 1 + ltm.tm_mon;
    day = ltm.tm_mday;
    hour = ltm.tm_hour;
}

//appointmentID counter
string generateAppointmentID() {
    string newID = "APT" + to_string(appointmentCounter);
    appointmentCounter++; 
    return newID;
}

void CreateAppointmentStaff() {

    cout << "\n==========================================" << endl;
    cout << "           CREATE APPOINTMENT             " << endl;
    cout << "==========================================\n" << endl;

    string customerID;
    string customerName;

    cout << "Enter the customer ID: ";
    cin >> customerID;

    //check member exist
    int memIdx = findMemberIndex(customerID);
    if (memIdx != -1) {
        customerName = memberDB[memIdx].nameMember;
    }
    else {
        int custIdx = findCustomerIndex(customerID);
        if (custIdx != -1) {
            customerName = customerDB[custIdx].nameCustomer;
        }
    }

    //check customer exist
    if (customerName.empty()) {
        cout << RED << "\n[Error] ID '" << customerID << "' not found in Customer or Member database!" << RESET << endl;
        return;
    }
    else {
        cout << GREEN << "[Found] Name: " << customerName << RESET << endl;
    }

    //bring time
    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);
    cout << "Today is: " << curYear << "-" << curMonth << "-" << curDay << endl;

    int dayOption;
    cout << "Enter Day of the Month (1 - 31): ";
    cin >> dayOption;

    //check day
    if (cin.fail() || dayOption < 1 || dayOption > 31) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid day input!" << RESET << endl;
        return;
    }

    //pass day cant book
    if (dayOption < curDay) {
        cout << RED << "\n[Error] Cannot book appointments for past dates!" << RESET << endl;
        return;
    }

    //open the day customer input
    int dayIndex = dayOption - 1;
    ViewAllAppointment(schedule[dayIndex], TOTAL_SLOTS);

    //input time
    int Appointment_time;
    cout << "Enter the timeslot you prefer: ";
    cin >> Appointment_time;

    //check timeslot
    if (cin.fail() || Appointment_time < 1 || Appointment_time > TOTAL_SLOTS) {
        cin.clear();
        cout << RED << "\n[Error] Invalid timeslot ID! Please choose between 1 and " << TOTAL_SLOTS << "." << RESET << endl;
        return;
    }

    int slotIndex = Appointment_time - 1;
    int slotStartHours[] = { 9, 11, 13, 15, 17, 19, 21 };

    //pass time cant book
    if (dayOption == curDay && slotStartHours[slotIndex] <= curHour) {
        cout << RED << "\n[Error] This time slot has already passed for today!" << RESET << endl;
        return;
    }

    //cant book duplicate
    if (schedule[dayIndex][slotIndex].isBooked) {
        cout << RED << "\n[Sorry] Timeslot is already booked!" << RESET << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    //show staff menu
    for (int i = 0; i < staffCount; i++) {
        cout << (i + 1) << ". " << staffDB[i].nameStaff
            << " (" << staffDB[i].idStaff << " - " << staffDB[i].positionStaff << ")\n";
    }

    cout << "\nSelect a Staff you preferred: ";
    int staffoption;
    cin >> staffoption;

    //check staff option
    if (cin.fail() || staffoption < 1 || staffoption > staffCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid input!" << RESET << endl;
        return;
    }

    int Appointmentoption;
    cout << "\nEnter a Service:\n";
    cout << "1. Wedding Event\n";
    cout << "2. Hair dressing with make up\n";
    cout << "Select service: ";
    cin >> Appointmentoption;

    switch (Appointmentoption) {
    case 1:
        schedule[dayIndex][slotIndex].service = "Wedding Event";
        break;
    case 2:
        schedule[dayIndex][slotIndex].service = "Hair dressing with make up";
        break;
    default:
        // FIXED: Added return to avoid booking slot with an invalid service
        cout << RED << "[Error] Invalid service option. Booking canceled." << RESET << endl;
        return;
    }

    //intepret data to timeslot
    int selectedIndex = staffoption - 1;

    schedule[dayIndex][slotIndex].appointmentID = generateAppointmentID();
    schedule[dayIndex][slotIndex].staffID = staffDB[selectedIndex].idStaff;
    schedule[dayIndex][slotIndex].staffName = staffDB[selectedIndex].nameStaff;
    schedule[dayIndex][slotIndex].customerID = customerID;
    schedule[dayIndex][slotIndex].customerName = customerName;
    schedule[dayIndex][slotIndex].status = "Booked";
    schedule[dayIndex][slotIndex].isBooked = true;

    cout << GREEN << "\n[Success] Appointment successfully created for Timeslot " << schedule[dayIndex][slotIndex].time << "!" << RESET << endl;
    cout << "\n------- Appointment Detail -------" << endl;
    cout << "Day         : Day " << (dayIndex + 1) << endl;
    cout << "Time Slot   : " << schedule[dayIndex][slotIndex].time << endl;
    cout << "Customer    : " << schedule[dayIndex][slotIndex].customerName << " (" << schedule[dayIndex][slotIndex].customerID << ")" << endl;
    cout << "Staff       : " << schedule[dayIndex][slotIndex].staffName << " (" << schedule[dayIndex][slotIndex].staffID << ")" << endl;
    cout << "Service     : " << schedule[dayIndex][slotIndex].service << endl;
    cout << "----------------------------------" << endl;
    cout << "Your Appointment ID is: " << YELLOW << schedule[dayIndex][slotIndex].appointmentID << RESET << endl;
}

void CreateAppointmentCustomer(const string& customerID, const string& customerName) {

    cout << "\n==========================================" << endl;
    cout << "           CREATE APPOINTMENT             " << endl;
    cout << "==========================================\n" << endl;

    //bring time
    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);
    cout << "Today is: " << curYear << "-" << curMonth << "-" << curDay << endl;

    int dayOption;
    cout << "Enter Day of the Month (1 - 31): ";
    cin >> dayOption;

    //check day
    if (cin.fail() || dayOption < 1 || dayOption > 31) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid day input!" << RESET << endl;
        return;
    }

    //pass day cant book
    if (dayOption < curDay) {
        cout << RED << "\n[Error] Cannot book appointments for past dates!" << RESET << endl;
        return;
    }

    //open the day customer input
    int dayIndex = dayOption - 1;
    ViewAllAppointment(schedule[dayIndex], TOTAL_SLOTS);

    //input time
    int Appointment_time;
    cout << "Enter the timeslot you prefer: ";
    cin >> Appointment_time;

    //check timeslot
    if (cin.fail() || Appointment_time < 1 || Appointment_time > TOTAL_SLOTS) {
        cin.clear();
        cout << RED << "\n[Error] Invalid timeslot ID! Please choose between 1 and " << TOTAL_SLOTS << "." << RESET << endl;
        return;
    }

    int slotIndex = Appointment_time - 1;
    int slotStartHours[] = { 9, 11, 13, 15, 17, 19, 21 };

    //passed time cant book
    if (dayOption == curDay && slotStartHours[slotIndex] <= curHour) {
        cout << RED << "\n[Error] This time slot has already passed for today!" << RESET << endl;
        return;
    }

    //cant book duplicate
    if (schedule[dayIndex][slotIndex].isBooked) {
        cout << RED << "\n[Sorry] Timeslot is already booked!" << RESET << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;

    //show staff menu
    for (int i = 0; i < staffCount; i++) {
        cout << (i + 1) << ". " << staffDB[i].nameStaff
            << " (" << staffDB[i].idStaff << " - " << staffDB[i].positionStaff << ")\n";
    }

    cout << "\nSelect a Staff you preferred: ";
    int staffOption;
    cin >> staffOption;

    //check staff option
    if (cin.fail() || staffOption < 1 || staffOption > staffCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid input!" << RESET << endl;
        return;
    }

    int Appointmentoption;
    cout << "\nEnter a Service:\n";
    cout << "1. Wedding Event\n";
    cout << "2. Hair dressing with make up\n";
    cout << "Select service: ";
    cin >> Appointmentoption;

    switch (Appointmentoption) {
    case 1:
        schedule[dayIndex][slotIndex].service = "Wedding Event";
        break;
    case 2:
        schedule[dayIndex][slotIndex].service = "Hair dressing with make up";
        break;
    default:
        cout << RED << "[Error] Invalid service option. Booking canceled." << RESET << endl;
        return;
    }

    //intepret data to timeslot
    int selectedIndex = staffOption - 1;
    schedule[dayIndex][slotIndex].appointmentID = generateAppointmentID();
    schedule[dayIndex][slotIndex].staffID = staffDB[selectedIndex].idStaff;
    schedule[dayIndex][slotIndex].staffName = staffDB[selectedIndex].nameStaff;
    schedule[dayIndex][slotIndex].customerID = customerID;
    schedule[dayIndex][slotIndex].customerName = customerName;
    schedule[dayIndex][slotIndex].status = "Booked";
    schedule[dayIndex][slotIndex].isBooked = true;

    cout << GREEN << "\n[Success] Appointment successfully created for Timeslot " << schedule[dayIndex][slotIndex].time << "!" << RESET << endl;
    cout << "\n------- Appointment Detail -------" << endl;
    cout << "Day         : " << (dayIndex + 1) << "-" << curMonth << "-" << curYear << endl;
    cout << "Time Slot   : " << schedule[dayIndex][slotIndex].time << endl;
    cout << "Customer    : " << schedule[dayIndex][slotIndex].customerName << " (" << schedule[dayIndex][slotIndex].customerID << ")" << endl;
    cout << "Staff       : " << schedule[dayIndex][slotIndex].staffName << " (" << schedule[dayIndex][slotIndex].staffID << ")" << endl;
    cout << "Service     : " << schedule[dayIndex][slotIndex].service << endl;
    cout << "----------------------------------" << endl;
    cout << "Your Appointment ID is: " << YELLOW << schedule[dayIndex][slotIndex].appointmentID << RESET << endl;
}

void CancelAppointment(const string& currentUserId) {

    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);

    string targetID;
    cout << "\n==========================================" << endl;
    cout << "           CANCEL APPOINTMENT             " << endl;
    cout << "==========================================\n" << endl;
    cout << "Enter Appointment ID to cancel (e.g. APT1001): ";
    cin >> targetID;

    //default is false
    bool found = false;

    for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
        for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

            //check wether is "booked" and have an "id"
            if (schedule[dayIndex][slotIndex].isBooked && schedule[dayIndex][slotIndex].appointmentID == targetID) {
                found = true;

                //permission checking
                if (!currentUserId.empty() && schedule[dayIndex][slotIndex].customerID != currentUserId) {
                    cout << RED << "\n[Error] You do not have permission to cancel another customer's appointment!" << RESET << endl;
                    return;
                }

                //print the details let user double check
                cout << "\n------- Appointment Detail -------" << endl;
                cout << "Day         : " << (dayIndex + 1) << "-" << curMonth << "-" << curYear << endl;
                cout << "Time Slot   : " << schedule[dayIndex][slotIndex].time << endl;
                cout << "Customer    : " << schedule[dayIndex][slotIndex].customerName << " (" << schedule[dayIndex][slotIndex].customerID << ")" << endl;
                cout << "Staff       : " << schedule[dayIndex][slotIndex].staffName << " (" << schedule[dayIndex][slotIndex].staffID << ")" << endl;
                cout << "Service     : " << schedule[dayIndex][slotIndex].service << endl;
                cout << "----------------------------------" << endl;

                // double confirm
                char confirm;
                cout << "Are you sure you want to cancel this appointment? (Y/N): ";
                cin >> confirm;

                if (confirm == 'Y' || confirm == 'y') {
                    schedule[dayIndex][slotIndex].isBooked = false;
                    schedule[dayIndex][slotIndex].status = "Available";
                    schedule[dayIndex][slotIndex].appointmentID = "-";
                    schedule[dayIndex][slotIndex].customerID = "-";
                    schedule[dayIndex][slotIndex].customerName = "-";
                    schedule[dayIndex][slotIndex].staffID = "-";
                    schedule[dayIndex][slotIndex].staffName = "-";
                    schedule[dayIndex][slotIndex].service = "-";

                    cout << GREEN << "\n[Success] Appointment " << targetID << " has been cancelled successfully!" << RESET << endl;
                }
                else {
                    cout << RED << "\n[Info] Cancellation aborted." << RESET << endl;
                }
                return;
            }
        }
    }
    //if didnt found
    if (!found) {
        cout << RED << "\n[Error] Appointment ID '" << targetID << "' not found or is already cancelled." << RESET << endl;
    }
}

void RescheduleAppointment(const string& currentUserId) {

    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);

    string targetID;
    cout << "\n==========================================" << endl;
    cout << "          RESCHEDULE APPOINTMENT          " << endl;
    cout << "==========================================\n" << endl;
    cout << "Enter Appointment ID to reschedule (e.g. APT1001): ";
    cin >> targetID;

    //default is false
    bool found = false;

    for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
        for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

            //check wether is "booked" and have an "id"
            if (schedule[dayIndex][slotIndex].isBooked && schedule[dayIndex][slotIndex].appointmentID == targetID) {
                found = true;

                //permission checking
                if (!currentUserId.empty() && schedule[dayIndex][slotIndex].customerID != currentUserId) {
                    cout << RED << "\n[Error] You do not have permission to reschedule another customer's appointment!" << RESET << endl;
                    return;
                }

                //print the details let user double check
                cout << "\n------- Current Appointment Detail -------" << endl;
                cout << "Day         : " << (dayIndex + 1) << "-" << curMonth << "-" << curYear << endl;
                cout << "Time Slot   : " << schedule[dayIndex][slotIndex].time << endl;
                cout << "Customer    : " << schedule[dayIndex][slotIndex].customerName << " (" << schedule[dayIndex][slotIndex].customerID << ")" << endl;
                cout << "Staff       : " << schedule[dayIndex][slotIndex].staffName << " (" << schedule[dayIndex][slotIndex].staffID << ")" << endl;
                cout << "Service     : " << schedule[dayIndex][slotIndex].service << endl;
                cout << "------------------------------------------" << endl;

                // 1. input new day
                int newDayOption;
                cout << "\nEnter New Day of the Month (1 - 31): ";
                cin >> newDayOption;

                // check day
                if (cin.fail() || newDayOption < 1 || newDayOption > 31) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "\n[Error] Invalid day input!" << RESET << endl;
                    return;
                }

                // pass day cant book
                if (newDayOption < curDay) {
                    cout << RED << "\n[Error] Cannot reschedule to past dates!" << RESET << endl;
                    return;
                }

                // open the day customer input
                int newDayIndex = newDayOption - 1;
                ViewAllAppointment(schedule[newDayIndex], TOTAL_SLOTS);

                // 2. input new time
                int newSlotOption;
                cout << "Enter the new timeslot you prefer: ";
                cin >> newSlotOption;

                // check timeslot
                if (cin.fail() || newSlotOption < 1 || newSlotOption > TOTAL_SLOTS) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "\n[Error] Invalid timeslot ID!" << RESET << endl;
                    return;
                }

                int newSlotIndex = newSlotOption - 1;
                int slotStartHours[] = { 9, 11, 13, 15, 17, 19, 21 };

                // pass time cant book
                if (newDayOption == curDay && slotStartHours[newSlotIndex] <= curHour) {
                    cout << RED << "\n[Error] This time slot has already passed for today!" << RESET << endl;
                    return;
                }

                // cant book duplicate
                if (schedule[newDayIndex][newSlotIndex].isBooked) {
                    cout << RED << "\n[Sorry] Selected timeslot is already booked!" << RESET << endl;
                    return;
                }

                // 3. transfer data to new slot
                schedule[newDayIndex][newSlotIndex].appointmentID = schedule[dayIndex][slotIndex].appointmentID;
                schedule[newDayIndex][newSlotIndex].customerID = schedule[dayIndex][slotIndex].customerID;
                schedule[newDayIndex][newSlotIndex].customerName = schedule[dayIndex][slotIndex].customerName;
                schedule[newDayIndex][newSlotIndex].staffID = schedule[dayIndex][slotIndex].staffID;
                schedule[newDayIndex][newSlotIndex].staffName = schedule[dayIndex][slotIndex].staffName;
                schedule[newDayIndex][newSlotIndex].service = schedule[dayIndex][slotIndex].service;
                schedule[newDayIndex][newSlotIndex].status = "Booked";
                schedule[newDayIndex][newSlotIndex].isBooked = true;

                // 4. reset original slot
                schedule[dayIndex][slotIndex].isBooked = false;
                schedule[dayIndex][slotIndex].status = "Available";
                schedule[dayIndex][slotIndex].appointmentID = "-";
                schedule[dayIndex][slotIndex].customerID = "-";
                schedule[dayIndex][slotIndex].customerName = "-";
                schedule[dayIndex][slotIndex].staffID = "-";
                schedule[dayIndex][slotIndex].staffName = "-";
                schedule[dayIndex][slotIndex].service = "-";

                cout << GREEN << "\n[Success] Appointment " << targetID << " has been rescheduled successfully!" << RESET << endl;
                return;
            }
        }
    }

    //if didnt found
    if (!found) {
        cout << RED << "\n[Error] Appointment ID '" << targetID << "' not found or is already cancelled." << RESET << endl;
    }
}

void ViewStaffSchedule() {
    cout << "\n==========================================" << endl;
    cout << "           VIEW STAFF SCHEDULE            " << endl;
    cout << "==========================================\n" << endl;

    //staff menu
    for (int i = 0; i < staffCount; i++) {
        cout << (i + 1) << ". " << staffDB[i].nameStaff
            << " (" << staffDB[i].idStaff << " - " << staffDB[i].positionStaff << ")\n";
    }

    cout << "\nSelect a Staff: ";
    int staffOption;
    cin >> staffOption;

    if (cin.fail() || staffOption < 1 || staffOption > staffCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid staff option!" << RESET << endl;
        return;
    }

    int selectedStaff = staffOption - 1;
    string targetStaffID = staffDB[selectedStaff].idStaff;
    string targetStaffName = staffDB[selectedStaff].nameStaff;

    //choose specific day or all appointment 
    int dayOption;
    cout << "\nEnter Day of Month (1 - 31, or enter 0 to view ALL days): ";
    cin >> dayOption;

    if (cin.fail() || dayOption < 0 || dayOption > 31) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid day input!" << RESET << endl;
        return;
    }

    //display the month
    if (dayOption == 0) {
        cout << "\n===========================================" << endl;
        cout << " Full Schedule for: " << GREEN << targetStaffID << " - " << targetStaffName << RESET << endl;
        cout << "===========================================" << endl;

        bool hasBooking = false;

        //header
        int w_day = string("Day").length();
        int w_time = string("Time Slot").length();
        int w_id = string("Appointment ID").length();
        int w_custID = string("Customer ID").length();
        int w_custName = string("Customer Name").length();
        int w_service = string("Service").length();

        //find table width
        for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                if (schedule[dayIndex][slotIndex].isBooked && schedule[dayIndex][slotIndex].staffID == targetStaffID) {
                    string dayStr = "Day " + to_string(dayIndex + 1);
                    w_day = max(w_day, (int)dayStr.length());
                    w_time = max(w_time, (int)schedule[dayIndex][slotIndex].time.length());
                    w_id = max(w_id, (int)schedule[dayIndex][slotIndex].appointmentID.length());
                    w_custID = max(w_custID, (int)schedule[dayIndex][slotIndex].customerID.length());
                    w_custName = max(w_custName, (int)schedule[dayIndex][slotIndex].customerName.length());
                    w_service = max(w_service, (int)schedule[dayIndex][slotIndex].service.length());
                }
            }
        }

        string separator
            = "+" + string(w_day + 2, '-')
            + "+" + string(w_time + 2, '-')
            + "+" + string(w_id + 2, '-')
            + "+" + string(w_custID + 2, '-')
            + "+" + string(w_custName + 2, '-')
            + "+" + string(w_service + 2, '-') + "+";

        //header
        cout << separator << endl;
        cout << "| " << left << setw(w_day) << "Day" << " "
            << "| " << setw(w_time) << "Time Slot" << " "
            << "| " << setw(w_id) << "Appointment ID" << " "
            << "| " << setw(w_custID) << "Customer ID" << " "
            << "| " << setw(w_custName) << "Customer Name" << " "
            << "| " << setw(w_service) << "Service" << " |\n";
        cout << separator << endl;

        for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                if (schedule[dayIndex][slotIndex].isBooked && schedule[dayIndex][slotIndex].staffID == targetStaffID) {
                    hasBooking = true;
                    string dayStr = "Day " + to_string(dayIndex + 1);
                    //table info width
                    cout << "| " << left << setw(w_day) << dayStr << " "
                        << "| " << setw(w_time) << schedule[dayIndex][slotIndex].time << " "
                        << "| " << setw(w_id) << schedule[dayIndex][slotIndex].appointmentID << " "
                        << "| " << setw(w_custID) << schedule[dayIndex][slotIndex].customerID << " "
                        << "| " << setw(w_custName) << schedule[dayIndex][slotIndex].customerName << " "
                        << "| " << setw(w_service) << schedule[dayIndex][slotIndex].service << " "
                        << "|" << endl;
                }
            }
        }

        cout << separator << endl;

        if (!hasBooking) {
            cout << YELLOW << "\nNo appointments found for " << targetStaffName << " throughout this month." << RESET << endl;
        }

    }
    else {
        //show the specific day
        int dayIndex = dayOption - 1;
        cout << "\nSchedule for " << GREEN << targetStaffID << " - " << targetStaffName << RESET
            << " on Day " << dayOption << ":" << endl;

        //filter by staffID
        ViewAllAppointment(schedule[dayIndex], TOTAL_SLOTS, targetStaffID);
    }
}

void MarkAppointmentStatus() {
    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);

    string targetID;
    cout << "\n==========================================" << endl;
    cout << "         MARK APPOINTMENT STATUS          " << endl;
    cout << "==========================================\n" << endl;
    cout << "Enter Appointment ID to mark (e.g. APT1001): ";
    cin >> targetID;

    // default is false
    bool found = false;

    for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
        for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

            // check whether is "booked" and have an "id"
            if (schedule[dayIndex][slotIndex].isBooked && schedule[dayIndex][slotIndex].appointmentID == targetID) {
                found = true;

                // print current details for confirmation
                cout << "\n------- Appointment Detail -------" << endl;
                cout << "Day           : " << (dayIndex + 1) << "-" << curMonth << "-" << curYear << endl;
                cout << "Time Slot     : " << schedule[dayIndex][slotIndex].time << endl;
                cout << "Customer      : " << schedule[dayIndex][slotIndex].customerName << " (" << schedule[dayIndex][slotIndex].customerID << ")" << endl;
                cout << "Staff         : " << schedule[dayIndex][slotIndex].staffName << " (" << schedule[dayIndex][slotIndex].staffID << ")" << endl;
                cout << "Service       : " << schedule[dayIndex][slotIndex].service << endl;
                cout << "Current Status: " << YELLOW << schedule[dayIndex][slotIndex].status << RESET << endl;
                cout << "----------------------------------" << endl;

                // select new status
                cout << "\nSelect New Status:\n";
                cout << "1. Completed (已完成)\n";
                cout << "2. In Progress (进行中)\n";
                cout << "3. No-Show (未出席)\n";
                cout << "4. Cancelled (标记取消)\n";
                cout << "Select status option (1 - 4): ";

                int markOption;
                cin >> markOption;

                if (cin.fail() || markOption < 1 || markOption > 4) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << RED << "\n[Error] Invalid status option!" << RESET << endl;
                    return;
                }

                switch (markOption) {
                case 1:
                    schedule[dayIndex][slotIndex].status = "Completed";
                    break;
                case 2:
                    schedule[dayIndex][slotIndex].status = "In Progress";
                    break;
                case 3:
                    schedule[dayIndex][slotIndex].status = "No-Show";
                    break;
                case 4:
                    // 如果选择标记为 Cancelled，自动释放该 Timeslot
                    schedule[dayIndex][slotIndex].status = "Cancelled";
                    schedule[dayIndex][slotIndex].isBooked = false;
                    break;
                }

                cout << GREEN << "\n[Success] Appointment " << targetID
                    << " status updated to: " << schedule[dayIndex][slotIndex].status << RESET << endl;
                return;
            }
        }
    }

    // if didn't find
    if (!found) {
        cout << RED << "\n[Error] Appointment ID '" << targetID << "' not found or is already cancelled." << RESET << endl;
    }
}