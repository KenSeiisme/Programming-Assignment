#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits> 
#include <cctype>
#include <algorithm>
#include <utility>
#include <ctime>
#include <sstream>
#include <fstream>

using namespace std;

//Sim Jia Yih
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ng Jun Sheng
// Data structure for Services details
struct Services {
    string serviceID;
    string servicename;
    double price;
    int duration;
};

// Data structure for Booking details
struct Bookings {
    string bookingID;
    string customerID;
    string staffID;
    string serviceID;
    string date;
    string time;
    string status;//confirm, cancelled, completed
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lee Hao Zheng
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
    double price;
};

//Appontment Service
struct AppointmentService {
    string serviceID;
    string serviceName;
    double price;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lim Cai Xuan
struct TotalBooking_Report {
    string appointmentId;
    string customerName;
    string staffName;
    string serviceName;
    int quantity;
    double price;
    int day;
    int month;
    int year;
    string timeSlot;
    string status;
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Global ID counters
int customerCounter = 1005;
int memberCounter = 1005;
int staffCounter = 1011;
int serviceCounter = 1006;
int bookingCounter = 1011;
int appointmentCounter = 1001;
int appointmentServiceCounter = 1003;

const int MAX_CUSTOMERS = 100;
const int MAX_MEMBERS = 100;
const int MAX_STAFF = 100;
//Booking
const int MAX_SERVICES = 100;
const int MAX_BOOKINGS = 100;
//AppointmentService
const int MAX_APPOINTMENT_SERVICES = 100;
const int MAX_REPORT_SIZE = 100;

int customerCount = 4;
int memberCount = 4;
int staffCount = 10;
int servicecount = 5;
int bookingCount = 10;
int appointmentServiceCount = 2;
int Booking_reportCount = 0;

// Total slots and days in month
const int TOTAL_SLOTS = 7;
const int MONTH_IN_YEAR = 12;
const int DAYS_IN_MONTH = 31;
const int daysInMonth[MONTH_IN_YEAR] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Color word for appointment
const string RESET = "\033[0m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[93m";

//Jia Yih
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Jun Sheng
Services servicesDB[MAX_SERVICES] = {
    //Service ID, Service Name, Price, Duration
    {"SI1001", "HairCut", 30.00, 30},
    {"SI1002", "HairStyling", 50.00, 60},
    {"SI1003", "Coolouring", 85.00, 90},
    {"SI1004", "NailArt", 120.00, 90},
    {"SI1005", "Skin Care Threatment ", 110.00, 90},
};

Bookings bookingDB[MAX_BOOKINGS] = {
    { "B1001", "C1001", "STF1001", "SI1001", "15/08/2026", "09:00 AM", "Completed" },
    { "B1002", "M1001", "STF1002", "SI1002", "16/08/2026", "11:00 AM", "Completed" },
    { "B1003", "C1002", "STF1003", "SI1003", "17/08/2026", "01:00 PM", "Completed" },
    { "B1004", "M1002", "STF1004", "SI1004", "18/08/2026", "03:00 PM", "Completed" },
    { "B1005", "C1003", "STF1005", "SI1005", "19/08/2026", "05:00 PM", "Completed" },
    { "B1006", "M1003", "STF1001", "SI1001", "20/08/2026", "09:00 AM", "Completed" },
    { "B1007", "C1004", "STF1002", "SI1002", "21/08/2026", "11:00 AM", "Completed" },
    { "B1008", "M1004", "STF1003", "SI1003", "22/08/2026", "01:00 PM", "Completed" },
    { "B1009", "C1001", "STF1004", "SI1004", "23/08/2026", "03:00 PM", "Completed" },
    { "B1010", "M1001", "STF1005", "SI1005", "24/08/2026", "05:00 PM", "Completed" },
};
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Hao Zheng
Timeslot defaultDaySlots[TOTAL_SLOTS] = {
    {1, "09:00 AM - 11:00 AM", "", false, "", "", "", "", "", "", 0},
    {2, "11:00 AM - 01:00 PM", "", false, "", "", "", "", "", "", 0},
    {3, "01:00 PM - 03:00 PM", "", false, "", "", "", "", "", "", 0},
    {4, "03:00 PM - 05:00 PM", "", false, "", "", "", "", "", "", 0},
    {5, "05:00 PM - 07:00 PM", "", false, "", "", "", "", "", "", 0},
    {6, "07:00 PM - 09:00 PM", "", false, "", "", "", "", "", "", 0},
    {7, "09:00 PM - 11:00 PM", "", false, "", "", "", "", "", "", 0}
};

Timeslot schedule[MONTH_IN_YEAR][DAYS_IN_MONTH][TOTAL_SLOTS];

AppointmentService appointmentServiceDB[MAX_APPOINTMENT_SERVICES] = {
    {"AS1001", "Wedding Event", 500.00},
    {"AS1002", "Hair dressing with make up", 150.00}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Cai Xuan
TotalBooking_Report bookingReport[MAX_REPORT_SIZE];

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Function Declarations
void logo();
void mainMenu();
//Customer and member area - JIA YIH
void customerPortal();
void registerCustomer();
void registerMember();
void customerMemberLogin();
void staffPortal();
void showCustomerMemberUI(const string& userId, const string& accountType);
void memberCustomerProfile(const string& userId, const string& accountType);
void viewProfile(const string& userId, const string& accountType);
void editProfileCMUI(const string& userId, const string& accountType);
//Staff area
void registerStaff();
void staffLogin();
void showStaffUI(const string& username);
void memberManagement();
void staffManagement();
void showStaffList();
void showMemberCustomerList();
void clearInput();
//Validation
bool isValidEmail(const string& email);
bool isValidPassword(const string& pass);
bool isValidPhoneNumber(const string& phone);
bool isValidName(const string& name);
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Booking - JUN SHENG
void memberBookingMenu(const string& customerID);//main page for customer
void viewServices();
void searchBooking(const string& customerID);
void addSingleBooking(const string& customerID);
void addMultipleBooking(const string& customerID);
void editBooking(const string& customerID);
void cancelBooking(const string& customerID);
void viewBooking(const string& customerID);
void generateBookingSlip(const string& customerID);
bool isDuplicateBooking(const Bookings& newBooking);
bool validateBooking(const Bookings& booking);
bool ValidDate(const string& date);
bool ValidTime(const string& time);
int findServiceID(const string& serviceID);
int findStaffID(const string& staffID);

//Staff Booking
void staffBookingMenu();//main page for staff
void addService();
void deleteService();
void editService();
void searchService();
void staffAddBooking();
void staffViewBooking();
void staffEditBooking();
void rescheduleCancelBooking();
void staffSearchBooking();
void staffBookingValidation();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Appointment - HAO ZHENG
void SaveScheduleToFile();
void LoadScheduleFromFile();
void AppointmentStaff();
void AppointmentCustomer(const string& currentUserId, const string& currentUserName);
void ViewAllAppointment(const Timeslot schedule[], int size, string filterStaffID = "");
void getCurrentSystemTime(int& year, int& month, int& day, int& hour);
void CreateAppointmentStaff();
void CreateAppointmentCustomer(const string& customerID, const string& customerName);
void CancelAppointment(const string& currentUserId = "");
void RescheduleAppointment(const string& currentUserId = "");
void ViewStaffSchedule();
void AppointmentMarking();
void ViewAppointmentServices();
void AddAppointmentService();
void EditAppointmentService();
void DeleteAppointmentService();
void inYearlySchedule();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Reporting - CAI XUAN
bool isValidDateRange(int month, int year, int week);
void setupTestData();
void loadService();
void loadAppointments();
void loadDataFromTeamSystem();
void displayBarchart(string reportTitle, int month, int year, int weekFilter, int type, ostream& out = cout);
void RevenueReport(ostream& out = cout);
void StaffReport(ostream& out = cout);
void ReportExport();
void reportingMenu();
void Reporting();
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    logo();
    inYearlySchedule();
    LoadScheduleFromFile();
    mainMenu();
    return 0;
}

//Sim Jia Yih
//find user
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
//Validation name,phone number,email and passsword
bool isValidName(const string& name) {
    if (name.empty()) return false;
    for (char c : name) {
        if (isdigit(c)) return false;
        if (!isalpha(c) && !isspace(c) && c != '\'' && c != '-') return false;
    }
    return true;
}

bool isValidPhoneNumber(const string& phone) {
    // Find position of the dash
    size_t dashPos = phone.find('-');

    // Dash must exist and be at index 3 (exactly 3 digits before it)
    if (dashPos != 3) return false;

    // Ensure there are no additional dashes
    if (phone.rfind('-') != 3) return false;

    // Verify the first 3 characters are digits
    for (int i = 0; i < 3; ++i) {
        if (!isdigit(phone[i])) return false;
    }

    // Verify there is content after the dash
    if (phone.length() <= 4) return false;

    // Verify all characters after the dash are digits
    for (size_t i = 4; i < phone.length(); ++i) {
        if (!isdigit(phone[i])) return false;
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
//Display one time output,without unlimited
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
            cout << RED << "Invalid input. Please enter a valid number.\n" << RESET;
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
            cout << RED << "Invalid selection. Please enter 1, 2, or 3.\n" << RESET;
        }
    }
}
//After choose customer/member it will go to customer portal
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
            cout << RED << "Invalid option. Try again.\n" << RESET;
        }
    }
}
//register customer
void registerCustomer() {
    if (customerCount >= MAX_CUSTOMERS) {
        cout << RED << "[Error] Customer database capacity reached!\n" << RESET;
        return;
    }
    //Generated Customer ID 
    Customer newCustomer;
    cout << "\n--- NEW CUSTOMER REGISTRATION ---\n";

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //while(true) means infinate loop forever play until correct
    while (true) {
        cout << "Enter Full Name: ";
        getline(cin, newCustomer.nameCustomer);
        if (isValidName(newCustomer.nameCustomer)) break;
        cout << RED << "[Error] Invalid name! Only can use alphabet. Try again.\n" << RESET;;
    }

    string genderInput;
    while (true) {
        cout << "Enter Gender (m/f): ";
        cin >> genderInput;

        if (genderInput == "m" || genderInput == "M") {
            newCustomer.genderCustomer = "Male";
            break;
        }
        else if (genderInput == "f" || genderInput == "F") {
            newCustomer.genderCustomer = "Female";
            break;
        }
        else {
            cout << RED << "[Error] Invalid gender! Please enter 'm' for Male or 'f' for Female.\n" << RESET;
        }
    }

    while (true) {
        cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
        cin >> newCustomer.phoneCustomer;
        if (isValidPhoneNumber(newCustomer.phoneCustomer)) break;
        cout << RED << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n" << RESET;
    }

    while (true) {
        cout << "Enter Email Address (must end with @gmail.com): ";
        cin >> newCustomer.emailCustomer;
        if (isValidEmail(newCustomer.emailCustomer)) break;
        cout << RED << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n" << RESET;
    }

    while (true) {
        cout << "Enter Password (min 8 chars, must contain letters & digits): ";
        cin >> newCustomer.passwordCustomer;
        if (isValidPassword(newCustomer.passwordCustomer)) break;
        cout << RED << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n" << RESET;
    }
    //Generated Customer ID
    string customerGeneratedID = "C" + to_string(customerCounter++);
    //Save to database
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
//register as member
void registerMember() {
    if (memberCount >= MAX_MEMBERS) {
        cout << RED << "[Error] Member database capacity reached!\n" << RESET;
        return;
    }
    char response, responseRenew;
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
            cout << RED << "[Error] Invalid name! Only can use alphabet. Try again.\n" << RESET;
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
                cout << RED << "[Error] Invalid gender! Please enter 'm' for Male or 'f' for Female.\n" << RESET;
            }
        }

        while (true) {
            cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
            cin >> newMember.phoneMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPhoneNumber(newMember.phoneMember)) break;
            cout << RED << "[Error] Invalid phone number! Only can use digit and must at '-' . Try again.\n" << RESET;
        }

        while (true) {
            cout << "Enter Email Address (must end with @gmail.com): ";
            cin >> newMember.emailMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidEmail(newMember.emailMember)) break;
            cout << RED << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n" << RESET;
        }

        while (true) {
            cout << "Enter Password (min 8 chars, must contain letters & digits): ";
            cin >> newMember.passwordMember;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (isValidPassword(newMember.passwordMember)) break;
            cout << RED << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n" << RESET;
        }
        //Generated Member ID
        string memberGeneratedID = "M" + to_string(memberCounter++);
        //Save to database
        newMember.idMember = memberGeneratedID;
        memberDB[memberCount++] = newMember;//add and save in member database

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
//login member or customer
void customerMemberLogin() {
    string idCustomerMember, passCustomerMember;
    cout << "\n--- CUSTOMER / MEMBER LOGIN ---\n";
    cout << "Customer ID / Member ID: ";
    cin >> idCustomerMember;
    cout << "Password: ";
    cin >> passCustomerMember;

    int memIdx = findMemberIndex(idCustomerMember);
    if (memIdx != -1 && memberDB[memIdx].passwordMember == passCustomerMember) {
        cout << GREEN << "\nMember login successful!\n" << RESET;
        showCustomerMemberUI(idCustomerMember, "Member");
        return;
    }

    int custIdx = findCustomerIndex(idCustomerMember);
    if (custIdx != -1 && customerDB[custIdx].passwordCustomer == passCustomerMember) {
        cout << GREEN << "\nCustomer login successful!\n" << RESET;
        showCustomerMemberUI(idCustomerMember, "Customer");
        return;
    }

    cout << RED << "\n[Error] Invalid Customer/Member ID or Password.\n" << RESET;
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
            cout << RED << "[Error] Invalid input.\n" << RESET;
            continue;
        }
        if (choice == 5) {
            cout << "Logging out of Customer Dashboard...\n";
            SaveScheduleToFile();
            break;
        }
        switch (choice) {
        case 1:
            memberCustomerProfile(userId, accountType);
            break;
        case 2:
            cout << "\n-> [Customer UI] Service module selected.\n";
            memberBookingMenu(userId);
            break;
        case 3:
            cout << "\n-> [Customer UI] Appointment module selected.\n";
            AppointmentCustomer(userId, name);
            break;
        case 4:
            cout << "\n-> [Customer UI] Billing module selected.\n";
            break;
        default:
            cout << RED << "[Error] Invalid selection.\n" << RESET;
        }
    }
}

void memberCustomerProfile(const string& userId, const string& accountType) {
    int choice = 0;
    while (true) {
        cout << "============ MEMBER/CUSTOMER PROFILE ============\n";
        cout << "[ 1 ] View your profile\n";
        cout << "[ 2 ] Edit Profile\n";
        cout << "[ 3 ] Renew membership\n";
        cout << "[ 4 ] Exit (Return to Main Menu)\n";
        cout << "Select option (1-4): ";

        if (!(cin >> choice)) {
            clearInput();
            cout << RED << "[Error] Invalid input.\n" << RESET;
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
            if (accountType == "Customer") {//When login as customer it will give this message
                cout << RED << "\n[Access Denied] Standard customers cannot renew membership.\n" << RESET;
                cout << "Please register as a Member first to enjoy membership features.\n";
            }
            else {
                cout << "\n[Success] Membership renewed successfully!\n";
            }
            break;
        case 4:
            cout << "Returning to Main Menu...\n";
            return;
        default:
            cout << RED << "[Error] Invalid option. Try again.\n" << RESET;
        }
    }
}

void viewProfile(const string& userId, const string& accountType) { //show the information same as customer or member log in
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
            cout << RED << "[Error] Invalid selection. Try again.\n" << RESET;
            continue;
        }

        if (updateChoice == 4) {
            break;
        }

        switch (updateChoice) {
        case 1: {
            string newEmail;
            while (true) {
                //change member or customer email
                cout << "Enter new Email Address (must end with @gmail.com): ";
                cin >> newEmail;
                if (isValidEmail(newEmail)) break;
                cout << RED << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n" << RESET;
            }
            if (accountType == "Member") memberDB[findMemberIndex(userId)].emailMember = newEmail;//member
            else customerDB[findCustomerIndex(userId)].emailCustomer = newEmail;//email

            cout << GREEN << "\n[Success] Email updated successfully!\n" << RESET;
            break;
        }
        case 2: {
            //change member or customer phone number
            string newPhone;
            cout << "Enter new Phone Number: ";
            cin >> newPhone;
            if (accountType == "Member") memberDB[findMemberIndex(userId)].phoneMember = newPhone;//member
            else customerDB[findCustomerIndex(userId)].phoneCustomer = newPhone;//customer

            cout << GREEN << "\n[Success] Phone number updated successfully!\n" << RESET;
            break;
        }
        case 3: {
            //change member or customer password
            string newPass;
            while (true) {
                cout << "Enter new Password (min 8 chars, letter & digit): ";
                cin >> newPass;
                if (isValidPassword(newPass)) break;
                cout << RED << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n" << RESET;
            }
            if (accountType == "Member") memberDB[findMemberIndex(userId)].passwordMember = newPass;//member
            else customerDB[findCustomerIndex(userId)].passwordCustomer = newPass;//customer

            cout << GREEN << "\n[Success] Password updated successfully!\n" << RESET;
            break;
        }
        default:
            cout << RED << "\n[Error] Invalid option selected. Try again.\n" << RESET;
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
            cout << RED << "[Error] Invalid input.\n" << RESET;
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
            cout << RED << "[Error] Invalid option. Try again.\n" << RESET;
        }
    }
}

void registerStaff() {
    if (staffCount >= MAX_STAFF) {
        cout << RED << "[Error] Staff database capacity reached!\n" << RESET;
        return;
    }

    Staff newStaff;
    cout << "\n--- NEW HAIR SALON STAFF REGISTRATION ---\n";
    string generatedID = "STF" + to_string(staffCounter++);

    clearInput();

    while (true) {
        //write name with alphabet only
        cout << "Enter Full Name: ";
        getline(cin, newStaff.nameStaff);
        if (isValidName(newStaff.nameStaff)) break;
        cout << RED << "[Error] Invalid name! Alphabet only. Try again.\n" << RESET;
    }
    //choose gender
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
            cout << RED << "[Error] Invalid gender! Enter 'm' or 'f'.\n" << RESET;
        }
    }
    //must have digit and dash
    while (true) {
        cout << "Enter Phone Number (e.g.: xxx-xxxxxxxx): ";
        cin >> newStaff.phoneStaff;
        clearInput();
        if (isValidPhoneNumber(newStaff.phoneStaff)) break;
        cout << RED << "[Error] Invalid phone number format.\n" << RESET;
    }
    // eneter email must add "@gmail.com"
    while (true) {
        cout << "Enter Email Address (must end with @gmail.com): ";
        cin >> newStaff.emailStaff;
        clearInput();
        if (isValidEmail(newStaff.emailStaff)) break;
        cout << RED << "[Error] Invalid email address.\n" << RESET;
    }
    // password must at least 8 characters and digit and alphabet
    while (true) {
        cout << "Enter Password (Minimun 8 chars, must contain letters & digits): ";
        cin >> newStaff.passwordStaff;
        clearInput();
        if (isValidPassword(newStaff.passwordStaff)) break;
        cout << RED << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n" << RESET;
    }

    int posChoice = 0;
    while (true) {
        cout << "\nWhat position do you want to hire for?\n";
        cout << "[ 1 ] Hair Stylist\n";
        cout << "[ 2 ] Skincare Specialist\n";
        cout << "[ 3 ] Hair Color Stylist\n";
        cout << "[ 4 ] Nail Technician\n";
        cout << "[ 5 ] Receptionist\n";
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
            cout << RED << "[Error] Invalid position selection. Please enter a number between 1 and 5.\n" << RESET;
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
    //check the id and password same as the database
    int stfidx = findStaffIndex(idStaff);
    if (stfidx != -1 && staffDB[stfidx].passwordStaff == passStaff) {
        cout << GREEN << "\nStaff authentication successful!\n" << RESET;
        cout << GREEN << "Welcome, " << staffDB[stfidx].nameStaff << " (" << staffDB[stfidx].positionStaff << ")!\n" << RESET;
        showStaffUI(idStaff);
    }
    else {
        cout << RED << "\n[Error] Invalid Staff credentials.\n" << RESET;
    }
}

void showStaffUI(const string& username) {
    int choice = 0;
    int stfidx = findStaffIndex(username);
    while (true) {
        cout << "\n************************************************************\n";
        cout << "                STAFF CONTROL PANEL           \n";
        cout << " Staff ID: " << username << " | " << staffDB[stfidx].nameStaff
            << " (" << staffDB[stfidx].positionStaff << ")\n";
        cout << "\n************************************************************\n";
        cout << "[ 1 ] Customer/Member Info Management\n";
        cout << "[ 2 ] Staff Info Management\n";
        cout << "[ 3 ] Service management\n";
        cout << "[ 4 ] Appointment Management\n";
        cout << "[ 5 ] View Payment History\n";
        cout << "[ 6 ] Reporting\n";
        cout << "[ 7 ] Logout\n";
        cout << "Select admin task: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << RED << "[Error] Invalid input.\n" << RESET;
            continue;
        }

        if (choice == 7) {
            cout << "Logging out of Staff Control Panel...\n";
            SaveScheduleToFile();
            break;
        }
        switch (choice) {
        case 1: { //This area is the staff need to enter staff id same as login only can enter customer/member management
            string confirmID;
            cout << "============= STAFF VERIFICATION REQUIRED =============\n";
            cout << "Enter Staff ID to access Member Management: ";
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int confirmIdx = findStaffIndex(confirmID);
            if (confirmIdx != -1 && confirmID == username) {
                cout << RED << "\n[Access Granted] Verified identity: " << RESET << staffDB[confirmIdx].nameStaff << "\n";
                memberManagement();
            }
            else {
                cout << RED << "\n[Access Denied] Invalid or mismatched Staff ID!\n" << RESET;
            }
            break;
        }
        case 2: {//This area is the staff need to enter staff id same as login only can enter staff mangement
            string confirmID;
            cout << "============= STAFF VERIFICATION REQUIRED =============\n";
            cout << "Enter Staff ID to access Staff Management: ";
            cin >> confirmID;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int confirmIdx = findStaffIndex(confirmID);
            if (confirmIdx != -1 && confirmID == username) {
                cout << GREEN << "\n[Access Granted] Verified identity: " << RESET << staffDB[confirmIdx].nameStaff << "\n";
                staffManagement();
            }
            else {
                cout << RED << "\n[Access Denied] Invalid or mismatched Staff ID!\n" << RESET;
            }
            break;
        }
        case 3:
            cout << "\n[System] Service management module selected.\n";
            staffBookingMenu();
            break;
        case 4:
            cout << "\n[System] Appointment management module selected.\n";
            AppointmentStaff();
            break;
        case 5:
            cout << "\n[System] Payment history module selected.\n";
            break;
        case 6:
            cout << "\n[System] Reporting module selected.\n";
            Reporting();
            break;
        default:
            cout << RED << "[Error] Invalid selection.\n" << RESET;
        }
    }
}

void showStaffList() {
    //table staff
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
            cout << RED << "[Error] Invalid input. Please enter a valid number.\n" << RESET;
            continue;
        }

        if (choice == 5) {
            cout << "Returning to Staff Control Panel...\n";
            break;
        }

        string idStaff;
        switch (choice) {
        case 1: {
            //Staff table
            showStaffList();
            break;
        }
        case 2: {
            cout << "\nEnter Staff ID to search: ";
            cin >> idStaff;
            //search staff information by using staff ID
            int stfidx = findStaffIndex(idStaff);
            if (stfidx != -1) {
                cout << "\n[Found] ID: " << staffDB[stfidx].idStaff
                    << " | Name: " << staffDB[stfidx].nameStaff
                    << " | Gender: " << staffDB[stfidx].genderStaff
                    << " | Phone: " << staffDB[stfidx].phoneStaff
                    << " | Email: " << staffDB[stfidx].emailStaff
                    << " | Position: " << staffDB[stfidx].positionStaff << "\n";
            }
            else {
                cout << RED << "\n[Error] Staff ID '" << RESET << idStaff << RED << "' not found.\n" << RESET;
            }
            break;
        }
        case 3: {
            cout << "\nEnter Staff ID to delete: ";
            cin >> idStaff;

            int stfidx = findStaffIndex(idStaff);
            if (stfidx != -1) {
                for (int i = stfidx; i < staffCount - 1; ++i) {
                    staffDB[i] = staffDB[i + 1];
                }
                staffCount--;
                cout << GREEN << "\n[Success] Staff '" << RESET << idStaff << GREEN << "' deleted successfully.\n" << RESET;
            }
            else {
                cout << RED << "\n[Error] Staff ID '" << RESET << idStaff << RED << "' not found. Delete canceled.\n" << RESET;
            }
            break;
        }
        case 4: {
            cout << "\nEnter Staff ID to update: ";
            cin >> idStaff;

            int stfidx = findStaffIndex(idStaff);
            if (stfidx == -1) {
                cout << RED << "\n[Error] Staff ID '" << RESET << idStaff << RED << "' not found. Update canceled.\n" << RESET;
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
                cout << RED << "[Error] Invalid selection. Update canceled.\n" << RESET;
                break;
            }

            switch (updateChoice) {
            case 1: { //change email
                string newEmail;
                while (true) { // change staff email
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << RED << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n" << RESET;
                }
                staffDB[stfidx].emailStaff = newEmail;
                cout << GREEN << "\n[Success] Email updated successfully for Staff ID '" << RESET << idStaff << GREEN << "'!\n" << RESET;
                break;
            }
            case 2: { // change staff phone number
                string newPhone;
                cout << "Enter new Phone Number: ";
                cin >> newPhone;
                staffDB[stfidx].phoneStaff = newPhone;
                cout << GREEN << "\n[Success] Phone number updated successfully for Staff ID '" << RESET << idStaff << GREEN << "'!\n" << RESET;
                break;
            }
            case 3: {
                string newPass;
                while (true) { //change staff password
                    cout << "Enter new Password (min 8 chars, letter & digit): ";
                    cin >> newPass;
                    if (isValidPassword(newPass)) break;
                    cout << RED << "[Error] Password must be at least 8 characters long and contain both letters and digits. Try again.\n" << RESET;
                }
                staffDB[stfidx].passwordStaff = newPass;
                cout << GREEN << "\n[Success] Password updated successfully for Staff ID '" << RESET << idStaff << RED << "'!\n" << RESET;
                break;
            }
            //update staff area
            case 4: { //change position
                int posChoice = 0;
                while (true) {
                    cout << "\nSelect new Hair Salon Position:\n";
                    cout << "[ 1 ] Hair Stylist\n";
                    cout << "[ 2 ] Skincare Specialist\n";
                    cout << "[ 3 ] Hair Color Stylist\n";
                    cout << "[ 4 ] Nail Technician\n";
                    cout << "[ 5 ] Receptionist\n";
                    cout << "Select position (1-5): ";

                    if (cin >> posChoice && posChoice >= 1 && posChoice <= 5) {
                        clearInput();
                        switch (posChoice) {
                        case 1: staffDB[stfidx].positionStaff = "Hair Stylist"; break;
                        case 2: staffDB[stfidx].positionStaff = "Skincare Specialist"; break;
                        case 3: staffDB[stfidx].positionStaff = "Hair Color Stylist"; break;
                        case 4: staffDB[stfidx].positionStaff = "Nail Technician"; break;
                        case 5: staffDB[stfidx].positionStaff = "Receptionist"; break;
                        }
                        cout << GREEN << "\n[Success] Position updated successfully to '"
                            << staffDB[stfidx].positionStaff << "' for Staff ID '"
                            << RESET << idStaff << GREEN << "'!\n" << RESET;
                        break;
                    }
                    else {
                        clearInput();
                        cout << RED << "[Error] Invalid position selection. Please enter a number between 1 and 5.\n" << RESET;
                    }
                }
                break;
            }
            default:
                cout << RED << "\n[Error] Invalid option selected. Update canceled.\n" << RESET; // if does not in option,update cancel
            }
            break;
        }
        default:
            cout << RED << "[Error] Invalid option. Please enter 1 to 5.\n" << RESET;
        }
    }
}
//show customer and member table
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
    //member will be the topper
    for (int i = 0; i < memberCount; ++i) {
        cout << "| " << left << setw(8) << memberDB[i].idMember
            << " | " << setw(22) << memberDB[i].nameMember
            << " | " << setw(8) << memberDB[i].genderMember
            << " | " << setw(14) << memberDB[i].phoneMember
            << " | " << setw(26) << memberDB[i].emailMember
            << " | " << setw(20) << memberDB[i].passwordMember << " |\n";
        cout << border << "\n";
    }
    //customer will be at the buttom
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
            cout << RED << "[Error] Invalid input. Please enter a valid number.\n" << RESET;
            continue;
        }

        if (choice == 5) { // if click 5 will back to staff control panel
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
            //enter customer or mrmber id
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
                    cout << RED << "\n[Error] Member/Customer ID '" << RESET << id << RED << "' not found.\n" << RESET;
                }
            }
            break;
        }
        case 3: {
            cout << "\nEnter Customer/Member ID to delete: ";
            cin >> id;
            //Staff enter Customer or Member ID
            int memIdx = findMemberIndex(id);//if enter member id will find member data
            if (memIdx != -1) {
                for (int i = memIdx; i < memberCount - 1; ++i) {
                    memberDB[i] = memberDB[i + 1];
                }
                memberCount--;
                cout << GREEN << "\n[Success] Member '" << RESET << id << GREEN << "' deleted successfully.\n" << RESET;
            }
            else {
                int custIdx = findCustomerIndex(id);//if enter customer id will find customer data
                if (custIdx != -1) {
                    for (int i = custIdx; i < customerCount - 1; ++i) {
                        customerDB[i] = customerDB[i + 1];
                    }
                    customerCount--;
                    cout << GREEN << "\n[Success] Customer '" << RESET << id << GREEN << "' deleted successfully.\n" << RESET;
                }
                else { //if no found
                    cout << RED << "\n[Error] ID '" << RESET << id << RED << "' not found. Delete canceled.\n" << RESET;
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
                cout << RED << "\n[Error] ID '" << RESET << id << RED << "' not found. Update canceled.\n" << RESET;
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
                cout << RED << "[Error] Invalid selection. Update canceled.\n" << RESET;
                break;
            }
            if (updateChoice == 3) {
                break;
            }

            switch (updateChoice) {
            case 1: {
                string newEmail;
                while (true) { // change email
                    cout << "Enter new Email Address (must end with @gmail.com): ";
                    cin >> newEmail;
                    if (isValidEmail(newEmail)) break;
                    cout << RED << "[Error] Invalid email! Must end with '@gmail.com'. Try again.\n" << RESET;
                }
                if (memIdx != -1) memberDB[memIdx].emailMember = newEmail;
                else customerDB[custIdx].emailCustomer = newEmail;
                cout << GREEN << "\n[Success] Email updated successfully for ID '" << RESET << id << GREEN << "'!\n" << RESET;
                break;
            }
            case 2: { //change new phone number
                string newPhone;
                cout << "Enter new Phone Number (e.g.: xxx-xxxxxxxx): ";
                cin >> newPhone;
                if (memIdx != -1) memberDB[memIdx].phoneMember = newPhone;
                else customerDB[custIdx].phoneCustomer = newPhone;
                cout << GREEN << "\n[Success] Phone number updated successfully for ID '" << RESET << id << RED << "'!\n" << RESET;
                break;
            }

            default:
                cout << RED << "\n[Error] Invalid option selected. Update canceled.\n" << RESET;
            }
            break;
        }
        default:
            cout << RED << "[Error] Invalid option. Please enter 1 to 5.\n" << RESET;
        }
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Ng Jun Sheng
bool validateBooking(const Bookings& booking) {

    // Customer ID cannot be empty
    if (booking.customerID.empty()) {
        return false;
    }

    // Service must exist
    if (findServiceID(booking.serviceID) == -1) {
        return false;
    }

    // Staff must exist
    if (findStaffID(booking.staffID) == -1) {
        return false;
    }

    // Date cannot be empty
    if (booking.date.empty()) {
        return false;
    }

    // Date format
    if (!ValidDate(booking.date)) {
        return false;
    }

    // Time cannot be empty
    if (booking.time.empty()) {
        return false;
    }

    // Time format
    if (!ValidTime(booking.time)) {
        return false;
    }

    // Status cannot be empty
    if (booking.status.empty()) {
        return false;
    }

    return true;
}

// FIND SERVICE
int findServiceID(const string& serviceID) {
        for (int i = 0; i < servicecount; i++) {
        if (servicesDB[i].serviceID == serviceID) {
            return i;
        }
    }
    return -1;
}

// FIND STAFF
int findStaffID(const string& staffID) {

    for (int i = 0; i < staffCount; i++) {
        if (staffDB[i].idStaff == staffID) {
            return i;
        }
    }
    return -1;
}

// FIND BOOKING
int findBookingID(const string& bookingID) {

    for (int i = 0; i < bookingCount; i++) {
        if (bookingDB[i].bookingID == bookingID) {
            return i;
        }
    }
    return -1;
}

//DATE VALIDATION
bool ValidDate(const string& date) {

    // DD/MM/YYYY
    if (date.length() != 10) {
        return false;
    }

    if (date[2] != '/' || date[5] != '/') {
        return false;
    }

    for (int i = 0; i < date.length(); i++) {

        if (i == 2 || i == 5) {
            continue;
        }

        if (!isdigit(date[i])) {
            return false;
        }
    }
    return true;
}

// TIME VALIDATION
bool ValidTime(const string& time) {

    // Hour:Min
    if (time.length() != 5) {
        return false;
    }

    if (time[2] != ':') {
        return false;
    }

    for (int i = 0; i < time.length(); i++) {

        if (i == 2) {
            continue;
        }

        if (!isdigit(time[i])) {
            return false;
        }
    }

    int hour = stoi(time.substr(0, 2));
    int minute = stoi(time.substr(3, 2));

    if (hour < 0 || hour > 23) {
        return false;
    }

    if (minute < 0 || minute > 59) {
        return false;
    }

    return true;
}

bool isDuplicateBooking(const Bookings& newBooking) {
    for (int i = 0; i < bookingCount; i++) {
        // Ignore cancelled bookings
        if (bookingDB[i].status == "Cancelled") {
            continue;
        }

        // Same customer + same date + same time
        if (bookingDB[i].customerID == newBooking.customerID && bookingDB[i].date == newBooking.date && bookingDB[i].time == newBooking.time) {
            cout << "cannot have same booking time, same date and same time\n";
            return true;
        }
    }
    return false;
}

void memberBookingMenu(const string& customerID) {
    int choice = 0;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "          MEMBER BOOKING SYSTEM \n";
        cout << "----------------------------------------\n";
        cout << "1. View Services\n";
        cout << "2. Search Booking\n";
        cout << "3. Add Single Booking\n";
        cout << "4. Add Multiple Bookings\n";
        cout << "5. Edit Booking\n";
        cout << "6. Cancel Booking\n";
        cout << "7. View My Bookings\n";
        cout << "8. Generate Confirmation Slip\n";
        cout << "9. Exit\n";
        cout << "Select option (1-9): ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number from 1 to 9.\n";
            continue;
        }

        switch (choice) {

        case 1:
            viewServices();
            break;

        case 2:
            searchBooking(customerID);
            break;

        case 3:
            addSingleBooking(customerID);
            break;

        case 4:
            addMultipleBooking(customerID);
            break;

        case 5:
            editBooking(customerID);
            break;

        case 6:
            cancelBooking(customerID);
            break;

        case 7:
            viewBooking(customerID);
            break;

        case 8:
            generateBookingSlip(customerID);
            break;

        case 9:
            return;

        default:
            cout << "[Error] Invalid selection.\n";
        }
    }
}

//VIEW SERVICES
void viewServices() {
    cout << "\n========================================\n";
    cout << right << setw(10) << "SERVICES\n";
    cout << "========================================\n";
    for (int i = 0; i < servicecount; i++) {
        cout << "Service ID : " << servicesDB[i].serviceID << "\n";
        cout << "Service    : " << servicesDB[i].servicename << "\n";
        cout << "Price      : RM " << fixed << setprecision(2) << servicesDB[i].price << "\n";
        cout << "Duration   : " << servicesDB[i].duration << " minutes\n";
        cout << "----------------------------------------\n";
    }
}

//SEARCH BOOKING
void searchBooking(const string& customerID) {
    string bookid;
    cout << "\nEnter Booking ID to search: ";
    cin >> bookid;

    int index = findBookingID(bookid);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    if (bookingDB[index].customerID != customerID) {
        cout << "[Error] You do not have permission to view this booking.\n";
        return;
    }

    cout << "\n========== BOOKING FOUND ==========\n";
    cout << "Booking ID : " << bookingDB[index].bookingID << "\n";
    cout << "Customer ID: " << bookingDB[index].customerID << "\n";
    cout << "Service ID : " << bookingDB[index].serviceID << "\n";
    cout << "Staff ID   : " << bookingDB[index].staffID << "\n";
    cout << "Date       : " << bookingDB[index].date << "\n";
    cout << "Time       : " << bookingDB[index].time << "\n";
    cout << "Status     : " << bookingDB[index].status << "\n";
}

// MEMBER - ADD SINGLE BOOKING
void addSingleBooking(const string& customerID) {

    if (bookingCount >= MAX_BOOKINGS) {
        cout << "[Error] Booking database is full.\n";
        return;
    }

    Bookings newBooking;
    newBooking.customerID = customerID;
    newBooking.status = "Booked";
    cout << "\n========== AVAILABLE STAFF ==========\n";
    for (int i = 0; i < staffCount; i++) {
        cout << "[" << i + 1 << "] "
            << staffDB[i].nameStaff
            << " (" << staffDB[i].idStaff << ")"
            << " - " << staffDB[i].positionStaff
            << "\n";
    }
    cout << "\n========== ADD SINGLE BOOKING ==========\n";
    viewServices();
    cout << "Enter Service ID: ";
    cin >> newBooking.serviceID;
    if (findServiceID(newBooking.serviceID) == -1) {
        cout << "[Error] Service ID not found.\n";
        return;
    }

    cout << "Enter Staff ID: ";
    cin >> newBooking.staffID;
    if (findStaffID(newBooking.staffID) == -1) {
        cout << "[Error] Staff ID not found.\n";
        return;
    }

    cout << "Enter Date (DD/MM/YYYY): ";
    cin >> newBooking.date;

    cout << "Enter Time (HH:MM): ";
    cin >> newBooking.time;

    // Check normal validation first
    if (!validateBooking(newBooking)) {
        cout << "[Error] Wrong Input.\n";
        return;
    }

    // Check duplicate booking
    if (isDuplicateBooking(newBooking)) {
        cout << "[Error] You already have a booking on " << newBooking.date << " at " << newBooking.time << ".\n";
        cout << "You cannot make another booking at the same time.\n";
        return;
    }

    newBooking.bookingID = "B" + to_string(bookingCounter++);
    bookingDB[bookingCount] = newBooking;
    bookingCount++;

    cout << "\n[Success] Booking added successfully!\n";
    cout << "Booking ID: " << newBooking.bookingID << "\n";
}

// MEMBER - ADD MULTIPLE BOOKINGS
void addMultipleBooking(const string& customerID) {
    char response;
    cout << "\n========== ADD MULTIPLE BOOKINGS ==========\n";

    do {
        addSingleBooking(customerID);
        cout << "\nAdd another booking? (Y/N): ";
        cin >> response;
        response = toupper(response);
    } while (response == 'Y');
    cout << "\nFinished adding multiple bookings.\n";
}

// MEMBER - EDIT BOOKING
void editBooking(const string& customerID) {
    string editid;
    cout << "\nEnter Booking ID to edit: ";
    cin >> editid;

    int index = findBookingID(editid);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    if (bookingDB[index].customerID != customerID) {
        cout << "[Error] You cannot edit this booking.\n";
        return;
    }

    if (bookingDB[index].status == "Cancelled") {
        cout << "[Error] Cancelled booking cannot be edited.\n";
        return;
    }

    string newDate;
    string newTime;
    cout << "\nEnter new date (DD/MM/YYYY): ";
    cin >> newDate;

    if (!ValidDate(newDate)) {
        cout << "[Error] Invalid date format.\n";
        return;
    }

    cout << "Enter new time (HH:MM): ";
    cin >> newTime;
    if (!ValidTime(newTime)) {
        cout << "[Error] Invalid time format.\n";
        return;
    }

    bookingDB[index].date = newDate;
    bookingDB[index].time = newTime;
    cout << "\n[Success] Booking updated successfully.\n";
}

// MEMBER - CANCEL BOOKING
void cancelBooking(const string& customerID) {
    string cancelid;
    cout << "\nEnter Booking ID to cancel: ";
    cin >> cancelid;

    int index = findBookingID(cancelid);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    if (bookingDB[index].customerID != customerID) {
        cout << "[Error] You cannot cancel this booking.\n";
        return;
    }

    if (bookingDB[index].status == "Cancelled") {
        cout << "[Error] Booking is already cancelled.\n";
        return;
    }

    bookingDB[index].status = "Cancelled";
    cout << "\n[Success] Booking "
        << cancelid
        << " has been cancelled.\n";
}

// MEMBER - VIEW MY BOOKINGS
void viewBooking(const string& customerID) {
    bool found = false;
    cout << "\n========== MY BOOKINGS ==========\n";
    for (int i = 0; i < bookingCount; i++) {
        if (bookingDB[i].customerID == customerID) {
            found = true;
            cout << "\nBooking ID : " << bookingDB[i].bookingID << "\n";
            cout << "Service ID : " << bookingDB[i].serviceID << "\n";
            cout << "Staff ID   : " << bookingDB[i].staffID << "\n";
            cout << "Date       : " << bookingDB[i].date << "\n";
            cout << "Time       : " << bookingDB[i].time << "\n";
            cout << "Status     : " << bookingDB[i].status << "\n";
            cout << "--------------------------------\n";
        }
    }

    if (!found) {
        cout << "No bookings found.\n";
    }
}

// MEMBER - GENERATE BOOKING SLIP
void generateBookingSlip(const string& customerID) {
    string id;
    cout << "\nEnter Booking ID: ";
    cin >> id;

    int index = findBookingID(id);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    if (bookingDB[index].customerID != customerID) {
        cout << "[Error] You cannot access this booking.\n";
        return;
    }

    cout << "\n";
    cout << "========================================\n";
    cout << "       BOOKING CONFIRMATION SLIP        \n";
    cout << "========================================\n";
    cout << "Booking ID : " << bookingDB[index].bookingID << "\n";
    cout << "Customer ID: " << bookingDB[index].customerID << "\n";
    cout << "Service ID : " << bookingDB[index].serviceID << "\n";
    cout << "Staff ID   : " << bookingDB[index].staffID << "\n";
    cout << "Date       : " << bookingDB[index].date << "\n";
    cout << "Time       : " << bookingDB[index].time << "\n";
    cout << "Status     : " << bookingDB[index].status << "\n";
    cout << "========================================\n";
    cout << "       Thank you for your booking!      \n";
    cout << "========================================\n";
}

// STAFF BOOKING MENU
void staffBookingMenu() {
    int choice;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "           STAFF BOOKING SYSTEM\n";
        cout << "----------------------------------------\n";
        cout << "1. Add Services\n";
        cout << "2. View Services\n";
        cout << "3. Delete Services\n";
        cout << "4. Edit Services\n";
        cout << "5. Search Services\n";
        cout << "6. Add Booking\n";
        cout << "7. View Booking\n";
        cout << "8. Reschedule / Cancel Booking\n";
        cout << "9. Edit Booking\n";
        cout << "10. Search Booking\n";
        cout << "11. Exit\n";
        cout << "Select option: ";

        if (!(cin >> choice)) {
            cout << "[Error] Invalid input.\n";
            continue;
        }

        switch (choice) {

        case 1:
            addService();
            break;

        case 2:
            viewServices();
            break;

        case 3:
            deleteService();
            break;

        case 4:
            editService();
            break;

        case 5:
            searchService();
            break;

        case 6:
            staffAddBooking();
            break;

        case 7:
            staffViewBooking();
            break;

        case 8:
            rescheduleCancelBooking();
            break;

        case 9:
            staffEditBooking();
            break;

        case 10:
            staffSearchBooking();
            break;

        case 11:
            return;

        default:
            cout << "[Error] Invalid selection.\n";
        }
    }
}

// STAFF - ADD SERVICES
void addService() {

    if (servicecount >= MAX_SERVICES) {
        cout << "[Error] Service database is full.\n";
        return;
    }

    Services newService;
    newService.serviceID = "SI" + to_string(serviceCounter++);
    cout << "\n========== ADD SERVICE ==========\n";
    cout << "Service ID: " << newService.serviceID << "\n";

    cout << "Enter Service Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newService.servicename);

    cout << "Enter Price: RM ";
    cin >> newService.price;

    cout << "Enter Duration (minutes): ";
    cin >> newService.duration;

    if (newService.servicename.empty() || newService.price <= 0 || newService.duration <= 0) {
        cout << "[Error] Invalid service information.\n";
        return;
    }

    servicesDB[servicecount] = newService;
    servicecount++;

    cout << "\n[Success] Service added successfully.\n";
}

// STAFF - VIEW SERVICES
void viewAllServices() {
    cout << "\n========== ALL SERVICES ==========\n";
    for (int i = 0; i < servicecount; i++) {
        cout << "\nService ID : "
            << servicesDB[i].serviceID << "\n";

        cout << "Name       : "
            << servicesDB[i].servicename << "\n";

        cout << "Price      : RM "
            << fixed << setprecision(2)
            << servicesDB[i].price << "\n";

        cout << "Duration   : "
            << servicesDB[i].duration
            << " minutes\n";
        cout << "----------------------------------\n";
    }
}

// STAFF - DELETE SERVICE
void deleteService() {
    string id;

    cout << "\nEnter Service ID to delete: ";
    cin >> id;

    int index = findServiceID(id);
    if (index == -1) {
        cout << "[Error] Service not found.\n";
        return;
    }

    for (int i = index; i < servicecount - 1; i++) {
        servicesDB[i] = servicesDB[i + 1];
    }

    servicecount--;
    cout << "\n[Success] Service deleted successfully.\n";
}

// STAFF - EDIT SERVICE
void editService() {
    string id;
    cout << "\nEnter Service ID to edit: ";
    cin >> id;

    int index = findServiceID(id);
    if (index == -1) {
        cout << "[Error] Service not found.\n";
        return;
    }

    cout << "\nEnter new service name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, servicesDB[index].servicename);

    cout << "Enter new price: RM ";
    cin >> servicesDB[index].price;

    cout << "Enter new duration: ";
    cin >> servicesDB[index].duration;

    if (servicesDB[index].price <= 0 || servicesDB[index].duration <= 0 || servicesDB[index].servicename.empty()) {
        cout << "[Error] Invalid service information.\n";
        return;
    }

    cout << "\n[Success] Service updated successfully.\n";
}

// STAFF - SEARCH SERVICE   
void searchService() {
    string id;
    cout << "\nEnter Service ID to search: ";
    cin >> id;

    int index = findServiceID(id);
    if (index == -1) {
        cout << "[Error] Service not found.\n";
        return;
    }

    cout << "\n========== SERVICE FOUND ==========\n";
    cout << "Service ID : " << servicesDB[index].serviceID << "\n";
    cout << "Service    : " << servicesDB[index].servicename << "\n";
    cout << "Price      : RM " << fixed << setprecision(2) << servicesDB[index].price << "\n";
    cout << "Duration   : " << servicesDB[index].duration << " minutes\n";
}

// STAFF - ADD BOOKING
void staffAddBooking() {

    if (bookingCount >= MAX_BOOKINGS) {
        cout << "[Error] Booking database is full.\n";
        return;
    }

    Bookings newBooking;
    newBooking.bookingID = "B" + to_string(bookingCounter++);

    cout << "\n========== STAFF ADD BOOKING ==========\n";

    cout << "Generated Booking ID: "
        << newBooking.bookingID << "\n";

    cout << "Enter Customer ID: ";
    cin >> newBooking.customerID;

    viewAllServices();

    cout << "Enter Service ID: ";
    cin >> newBooking.serviceID;
    if (findServiceID(newBooking.serviceID) == -1) {
        cout << "[Error] Service not found.\n";
        return;
    }

    cout << "\nAvailable Staff:\n";
    for (int i = 0; i < staffCount; i++) {
        cout << staffDB[i].idStaff << " - " << staffDB[i].nameStaff << "\n";
    }

    cout << "Enter Staff ID: ";
    cin >> newBooking.staffID;
    if (findStaffID(newBooking.staffID) == -1) {
        cout << "[Error] Staff not found.\n";
        return;
    }

    cout << "Enter Date (DD/MM/YYYY): ";
    cin >> newBooking.date;

    cout << "Enter Time (HH:MM): ";
    cin >> newBooking.time;

    newBooking.status = "Booked";

    if (!validateBooking(newBooking)) {
        cout << "[Error] Booking validation failed.\n";
        return;
    }

    bookingDB[bookingCount] = newBooking;
    bookingCount++;
    cout << "\n[Success] Booking added successfully.\n";
    cout << "Booking ID: "
        << newBooking.bookingID << "\n";
}

// STAFF - VIEW BOOKING

void staffViewBooking() {

    if (bookingCount == 0) {
        cout << "\nNo bookings available.\n";
        return;
    }

    cout << "\n========== ALL BOOKINGS ==========\n";

    for (int i = 0; i < bookingCount; i++) {
        cout << "\nBooking ID : " << bookingDB[i].bookingID << "\n";
        cout << "Customer ID: " << bookingDB[i].customerID << "\n";
        cout << "Service ID : " << bookingDB[i].serviceID << "\n";
        cout << "Staff ID   : " << bookingDB[i].staffID << "\n";
        cout << "Date       : " << bookingDB[i].date << "\n";
        cout << "Time       : " << bookingDB[i].time << "\n";
        cout << "Status     : " << bookingDB[i].status << "\n";
        cout << "----------------------------------\n";
    }
}

// STAFF - RESCHEDULE / CANCEL BOOKING
void rescheduleCancelBooking() {
    string id;
    int choice;
    cout << "\nEnter Booking ID: ";
    cin >> id;

    int index = findBookingID(id);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    cout << "\n1. Reschedule Booking\n";
    cout << "2. Cancel Booking\n";
    cout << "Select option: ";
    cin >> choice;

    if (choice == 1) {
        string newDate;
        string newTime;
        cout << "Enter new date (DD/MM/YYYY): ";
        cin >> newDate;

        if (!ValidDate(newDate)) {
            cout << "[Error] Invalid date format.\n";
            return;
        }

        cout << "Enter new time (HH:MM): ";
        cin >> newTime;

        if (!ValidTime(newTime)) {
            cout << "[Error] Invalid time format.\n";
            return;
        }

        bookingDB[index].date = newDate;
        bookingDB[index].time = newTime;
        bookingDB[index].status = "Booked";
        cout << "\n[Success] Booking rescheduled successfully.\n";
    }

    else if (choice == 2) {

        if (bookingDB[index].status == "Cancelled") {
            cout << "[Error] Booking already cancelled.\n";
            return;
        }

        bookingDB[index].status = "Cancelled";
        cout << "\n[Success] Booking cancelled successfully.\n";
    }

    else {
        cout << "[Error] Invalid selection.\n";
    }
}

// STAFF - EDIT BOOKING
void staffEditBooking() {
    string id;
    cout << "\nEnter Booking ID to edit: ";
    cin >> id;

    int index = findBookingID(id);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    if (bookingDB[index].status == "Cancelled") {
        cout << "[Error] Cancelled booking cannot be edited.\n";
        return;
    }

    cout << "\nCurrent Service ID: " << bookingDB[index].serviceID << "\n";

    viewAllServices();
    cout << "Enter new Service ID: ";
    cin >> bookingDB[index].serviceID;

    if (findServiceID(bookingDB[index].serviceID) == -1) {
        cout << "[Error] Service not found.\n";
        return;
    }

    cout << "\nAvailable Staff:\n";
    for (int i = 0; i < staffCount; i++) {
        cout << staffDB[i].idStaff
            << " - "
            << staffDB[i].nameStaff
            << "\n";
    }

    cout << "Enter new Staff ID: ";
    cin >> bookingDB[index].staffID;

    if (findStaffID(bookingDB[index].staffID) == -1) {
        cout << "[Error] Staff not found.\n";
        return;
    }
    cout << "\n[Success] Booking edited successfully.\n";
}

// STAFF - SEARCH BOOKING
void staffSearchBooking() {

    string id;

    cout << "\nEnter Booking ID to search: ";
    cin >> id;

    int index = findBookingID(id);
    if (index == -1) {
        cout << "[Error] Booking not found.\n";
        return;
    }

    cout << "\n========== BOOKING FOUND ==========\n";
    cout << "Booking ID : " << bookingDB[index].bookingID << "\n";
    cout << "Customer ID: " << bookingDB[index].customerID << "\n";
    cout << "Service ID : " << bookingDB[index].serviceID << "\n";
    cout << "Staff ID   : " << bookingDB[index].staffID << "\n";
    cout << "Date       : " << bookingDB[index].date << "\n";
    cout << "Time       : " << bookingDB[index].time << "\n";
    cout << "Status     : " << bookingDB[index].status << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lee Hao Zheng
//give a clear 31 day with 7 slot timeslot
void inYearlySchedule() {
    for (int month = 0; month < 12; month++) {
        for (int day = 0; day < 31; day++) {
            for (int slot = 0; slot < TOTAL_SLOTS; slot++) {
                schedule[month][day][slot] = defaultDaySlots[slot];
            }
        }
    }
}

void SaveScheduleToFile() {
    //save in schedule.txt
    ofstream outFile("schedule_data.txt");
    if (!outFile) {
        cout << RED << "[Error] Failed to save data to file!" << RESET << endl;
        return;
    }

    //layout
    for (int monthIndex = 0; monthIndex < 12; monthIndex++) {
        for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                //initialize the slot of the day

                outFile << monthIndex << "|"
                    << dayIndex << "|"
                    << slotIndex << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].isBooked << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].appointmentID << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].status << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].staffID << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].staffName << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].customerID << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].customerName << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].service << "|"
                    << schedule[monthIndex][dayIndex][slotIndex].price << "\n";
            }
        }
    }
    outFile.close();
}

//load schedule
void LoadScheduleFromFile() {
    ifstream inFile("schedule_data.txt");
    if (!inFile) {
        // run directly(create file) if didnt exist
        return;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) continue;

        stringstream slotdata(line);
        string item;

        int monthIndex, dayIndex, slotIndex;
        getline(slotdata, item, '|'); monthIndex = stoi(item);
        getline(slotdata, item, '|'); dayIndex = stoi(item);
        getline(slotdata, item, '|'); slotIndex = stoi(item);

        getline(slotdata, item, '|'); schedule[monthIndex][dayIndex][slotIndex].isBooked = (item == "1");
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].appointmentID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].status, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].staffID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].staffName, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].customerID, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].customerName, '|');
        getline(slotdata, schedule[monthIndex][dayIndex][slotIndex].service, '|');
        getline(slotdata, item, '|');
        schedule[monthIndex][dayIndex][slotIndex].price = item.empty() ? 0.0 : stod(item);
    }
    inFile.close();
}

void AppointmentStaff() {

    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);

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
        cout << "7. View Appointment Service" << endl;
        cout << "8. Add Appointment Service" << endl;
        cout << "9. Edit Appointment Service" << endl;
        cout << "10. Delete Appointment Service" << endl;
        cout << "0. Exit\n" << endl;

        cout << "Select option: ";
        cin >> option;


        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << RED << "[Error] Invalid input! Please enter a number from 1 to 6." << RESET << endl;
            cout << "\nPress Enter to return to the menu...";
            cin.get();
            continue;
        }

        switch (option) {
        case 1: {
            int month;
            cout << "Enter month (1 - 12): ";
            cin >> month;
            if (cin.fail() || month < 1 || month > 12) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "[Error] Invalid day! Please enter a day from 1 to 31." << RESET << endl;
                break;
            }

            int monthIndex = month - 1;

            int day;
            int maxDays = daysInMonth[month];
            cout << "Enter Day of the Month (1 - " << maxDays << "): ";
            cin >> day;
            if (cin.fail() || day < 1 || day > 31) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << "[Error] Invalid day! Please enter a day from 1 to 31." << RESET << endl;
                break;
            }

            int dayIndex = day - 1;
            cout << "You selected: View All Appointment for Date:  " << day << "-" << month << "-" << curYear << endl;
            ViewAllAppointment(schedule[monthIndex][dayIndex], TOTAL_SLOTS);
            break;
        }
        case 2:
            cout << "You selected: Create a New Appointment" << endl;
            CreateAppointmentStaff();
            break;
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
            AppointmentMarking();
            break;
        case 7:
            cout << "You slected: View Appointment Service" << endl;
            ViewAppointmentServices();
            break;
        case 8:
            cout << "You slected: Add Appointment Service" << endl;
            AddAppointmentService();
            break;
        case 9:
            cout << "You slected: Edit Appointment Service" << endl;
            EditAppointmentService();
            break;
        case 10:
            cout << "You slected: Delete Appointment Service" << endl;
            DeleteAppointmentService();
            break;
        case 0:
            cout << "Returning to Staff Menu..." << endl;
            return;
        default:
            cout << RED << "[Error] Invalid option. Please select a valid option from the menu." << RESET << endl;
        }

        if (option != 0) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }

    } while (option != 0);
}

void AppointmentCustomer(const string& currentUserId, const string& currentUserName) {

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
            cout << RED << "[Error] Invalid input! Please enter a number from 1 to 3." << RESET << endl;
            cout << "\nPress Enter to return to the menu...";
            cin.get();
            continue;
        }

        switch (option) {
        case 1: 
            cout << "You selected: Create a New Appointment" << endl;
            CreateAppointmentCustomer(currentUserId, currentUserName);
            break;
        case 2: 
            cout << "You selected: Cancel Appointment" << endl;
            CancelAppointment(currentUserId);
            break;
        case 3:
            cout << "You selected: Reschedule Appointment" << endl;
            RescheduleAppointment(currentUserId);
            break;
        case 0:
            cout << "Returning to Customer/Member Menu..." << endl;
            return;
        default:
            cout << RED << "[Error] Invalid option. Please select a valid option from the menu." << RESET << endl;
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
    int w_price = string("Price (RM)").length();

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
        //ostringsteam to compare number value with string value
        string priceStr = schedule[i].isBooked ? (ostringstream() << fixed << setprecision(2) << schedule[i].price).str() : "-";


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
        w_price = max(w_price, (int)priceStr.length());
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
        + "+" + string(w_service + 2, '-') 
        + "+" + string(w_price + 2, '-') + "+";

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
        << "| " << setw(w_service) << "Service" << " "
        << "| " << setw(w_price) << "Price (RM)" << " |\n";

    cout << separator << endl;

    for (int i = 0; i < size; i++) {
        if (!filterStaffID.empty() && schedule[i].staffID != filterStaffID && schedule[i].isBooked) {
            continue;
        }

        //table info width
        string appointmentID = schedule[i].isBooked ? schedule[i].appointmentID : "-";
        string statusAppointment = schedule[i].isBooked ? schedule[i].status : "Available";
        //relate with AppointmentMarking()
        string statuscolor;
        if (!schedule[i].isBooked || schedule[i].status == "Completed") {
            statuscolor = GREEN;
        }
        else if (schedule[i].status == "Pending Payment" || schedule[i].status == "No-Show") {
            statuscolor = YELLOW;
        }
        else {
            statuscolor = RED;
        }
        string staffID = schedule[i].isBooked ? schedule[i].staffID : "-";
        string staffname = schedule[i].isBooked ? schedule[i].staffName : "-";
        string customerID = schedule[i].isBooked ? schedule[i].customerID : "-";
        string customerName = schedule[i].isBooked ? schedule[i].customerName : "-";
        string service = (schedule[i].isBooked && !schedule[i].service.empty()) ? schedule[i].service : "-";
        //ostringsteam to compare number value with string value
        string price = schedule[i].isBooked ? (ostringstream() << fixed << setprecision(2) << schedule[i].price).str() : "-";

        cout << "| " << left << setw(w_num) << schedule[i].num << " "
            << "| " << setw(w_time) << schedule[i].time << " "
            << "| " << setw(w_id) << appointmentID << " "
            << "| " << statuscolor << setw(w_status) << statusAppointment << RESET << " "
            << "| " << setw(w_staffID) << staffID << " "
            << "| " << setw(w_staffName) << staffname << " "
            << "| " << setw(w_custID) << customerID << " "
            << "| " << setw(w_custName) << customerName << " "
            << "| " << setw(w_service) << service << " "
            << "| " << setw(w_price) << price << " "
            << "|" << endl;
    }
    cout << separator << endl;
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

    int monthOption, dayOption;

    //Enter Month
    cout << "Enter Month (1 - 12): ";
    cin >> monthOption;

    if (cin.fail() || monthOption < 1 || monthOption > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid month!" << RESET << endl;
        return;
    }

    int monthIndex = monthOption - 1;

    //Enter day
    int maxDays = daysInMonth[monthIndex];
    cout << "Enter Day of the Month (1 - " << maxDays << "): ";
    cin >> dayOption;

    if (cin.fail() || dayOption < 1 || dayOption > maxDays) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid day for this month!" << RESET << endl;
        return;
    }

    int dayIndex = dayOption - 1;

    //pass day cant book
    if (monthOption < curMonth || (monthOption == curMonth && dayOption < curDay)) {
        cout << RED << "\n[Error] Cannot book appointments for past dates!" << RESET << endl;
        return;
    }

    //open the day customer input

    ViewAllAppointment(schedule[monthIndex][dayIndex], TOTAL_SLOTS);

    //input time
    int Appointment_time;
    cout << "Enter the timeslot you prefer: ";
    cin >> Appointment_time;

    //check timeslot
    if (cin.fail() || Appointment_time < 1 || Appointment_time > TOTAL_SLOTS) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    if (schedule[monthIndex][dayIndex][slotIndex].isBooked) {
        cout << RED << "\n[Sorry] Timeslot is already booked!" << RESET << endl;
        return;
    }

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

    //Appointment Service menu
    for (int i = 0; i < appointmentServiceCount; i++) {
        cout << (i + 1) << ". " << appointmentServiceDB[i].serviceName
            << " (RM " << fixed << setprecision(2) << appointmentServiceDB[i].price << ")\n";
    }

    int Appointmentoption;
    cout << "\nEnter a Service:\n";
    cin >> Appointmentoption;

    if (cin.fail() || (Appointmentoption < 1 || Appointmentoption > appointmentServiceCount)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid service option. Booking canceled." << RESET << endl;
        return;
    }

    int selectedServiceIdx = Appointmentoption - 1;
    schedule[monthIndex][dayIndex][slotIndex].service = appointmentServiceDB[selectedServiceIdx].serviceName;
    schedule[monthIndex][dayIndex][slotIndex].price = appointmentServiceDB[selectedServiceIdx].price;

    //intepret data to timeslot
    int selectedIndex = staffoption - 1;

    schedule[monthIndex][dayIndex][slotIndex].appointmentID = generateAppointmentID();
    schedule[monthIndex][dayIndex][slotIndex].staffID = staffDB[selectedIndex].idStaff;
    schedule[monthIndex][dayIndex][slotIndex].staffName = staffDB[selectedIndex].nameStaff;
    schedule[monthIndex][dayIndex][slotIndex].customerID = customerID;
    schedule[monthIndex][dayIndex][slotIndex].customerName = customerName;
    schedule[monthIndex][dayIndex][slotIndex].status = "Booked";
    schedule[monthIndex][dayIndex][slotIndex].isBooked = true;
    SaveScheduleToFile();

    cout << GREEN << "\n[Success] Appointment successfully created for Timeslot " << schedule[monthIndex][dayIndex][slotIndex].time << "!" << RESET << endl;
    cout << "\n------- Appointment Detail -------" << endl;
    cout << "Date        : " << (dayIndex + 1) << "-" << monthIndex + 1 << "-" << curYear << endl;
    cout << "Time Slot   : " << schedule[monthIndex][dayIndex][slotIndex].time << endl;
    cout << "Customer    : " << schedule[monthIndex][dayIndex][slotIndex].customerName << " (" << schedule[monthIndex][dayIndex][slotIndex].customerID << ")" << endl;
    cout << "Staff       : " << schedule[monthIndex][dayIndex][slotIndex].staffName << " (" << schedule[monthIndex][dayIndex][slotIndex].staffID << ")" << endl;
    cout << "Service     : " << schedule[monthIndex][dayIndex][slotIndex].service << endl;
    cout << "Price       : RM " << fixed << setprecision(2) << schedule[monthIndex][dayIndex][slotIndex].price << endl;
    cout << "----------------------------------" << endl;
    cout << "Your Appointment ID is: " << YELLOW << schedule[monthIndex][dayIndex][slotIndex].appointmentID << RESET << endl;
}

void CreateAppointmentCustomer(const string& customerID, const string& customerName) {

    cout << "\n==========================================" << endl;
    cout << "           CREATE APPOINTMENT             " << endl;
    cout << "==========================================\n" << endl;

    //bring time
    int curYear, curMonth, curDay, curHour;
    getCurrentSystemTime(curYear, curMonth, curDay, curHour);
    cout << "Today is: " << curYear << "-" << curMonth << "-" << curDay << endl;

    int monthOption, dayOption;

    //Enter Month
    cout << "Enter Month (1 - 12): ";
    cin >> monthOption;

    if (cin.fail() || monthOption < 1 || monthOption > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid month!" << RESET << endl;
        return;
    }

    int monthIndex = monthOption - 1;

    //Enter day
    int maxDays = daysInMonth[monthIndex];
    cout << "Enter Day of the Month (1 - " << maxDays << "): ";
    cin >> dayOption;

    if (cin.fail() || dayOption < 1 || dayOption > maxDays) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid day for this month!" << RESET << endl;
        return;
    }

    int dayIndex = dayOption - 1;

    //pass day cant book
    if (monthOption < curMonth || (monthOption == curMonth && dayOption < curDay)) {
        cout << RED << "\n[Error] Cannot book appointments for past dates!" << RESET << endl;
        return;
    }

    //open the day customer input

    ViewAllAppointment(schedule[monthIndex][dayIndex], TOTAL_SLOTS);

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
    if (schedule[monthIndex][dayIndex][slotIndex].isBooked) {
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
        schedule[monthIndex][dayIndex][slotIndex].service = "Wedding Event";
        schedule[monthIndex][dayIndex][slotIndex].price = 500.00;
        break;
    case 2:
        schedule[monthIndex][dayIndex][slotIndex].service = "Hair dressing with make up";
        schedule[monthIndex][dayIndex][slotIndex].price = 150.00;
        break;
    default:
        cout << RED << "[Error] Invalid service option. Booking canceled." << RESET << endl;
        return;
    }

    //intepret data to timeslot
    int selectedIndex = staffOption - 1;
    schedule[monthIndex][dayIndex][slotIndex].appointmentID = generateAppointmentID();
    schedule[monthIndex][dayIndex][slotIndex].staffID = staffDB[selectedIndex].idStaff;
    schedule[monthIndex][dayIndex][slotIndex].staffName = staffDB[selectedIndex].nameStaff;
    schedule[monthIndex][dayIndex][slotIndex].customerID = customerID;
    schedule[monthIndex][dayIndex][slotIndex].customerName = customerName;
    schedule[monthIndex][dayIndex][slotIndex].status = "Booked";
    schedule[monthIndex][dayIndex][slotIndex].isBooked = true;
    SaveScheduleToFile();

    cout << GREEN << "\n[Success] Appointment successfully created for Timeslot " << schedule[monthIndex][dayIndex][slotIndex].time << "!" << RESET << endl;
    cout << "\n------- Appointment Detail -------" << endl;
    cout << "Date        : " << (dayIndex + 1) << "-" << monthIndex + 1 << "-" << curYear << endl;
    cout << "Time Slot   : " << schedule[monthIndex][dayIndex][slotIndex].time << endl;
    cout << "Customer    : " << schedule[monthIndex][dayIndex][slotIndex].customerName << " (" << schedule[monthIndex][dayIndex][slotIndex].customerID << ")" << endl;
    cout << "Staff       : " << schedule[monthIndex][dayIndex][slotIndex].staffName << " (" << schedule[monthIndex][dayIndex][slotIndex].staffID << ")" << endl;
    cout << "Service     : " << schedule[monthIndex][dayIndex][slotIndex].service << endl;
    cout << "Price       : RM " << fixed << setprecision(2) << schedule[monthIndex][dayIndex][slotIndex].price << endl;
    cout << "----------------------------------" << endl;
    cout << "Your Appointment ID is: " << YELLOW << schedule[monthIndex][dayIndex][slotIndex].appointmentID << RESET << endl;
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

    for (int monthIndex = 0; monthIndex < MONTH_IN_YEAR; monthIndex++) {
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

                //check wether is "booked" and have an "id"
                if (schedule[monthIndex][dayIndex][slotIndex].isBooked && schedule[monthIndex][dayIndex][slotIndex].appointmentID == targetID) {
                    found = true;

                    //permission checking
                    if (!currentUserId.empty() && schedule[monthIndex][dayIndex][slotIndex].customerID != currentUserId) {
                        cout << RED << "\n[Error] You do not have permission to cancel another customer's appointment!" << RESET << endl;
                        return;
                    }

                    //print the details let user double check
                    cout << "\n------- Appointment Detail -------" << endl;
                    cout << "Day         : " << (dayIndex + 1) << "-" << (monthIndex + 1) << "-" << curYear << endl;
                    cout << "Time Slot   : " << schedule[monthIndex][dayIndex][slotIndex].time << endl;
                    cout << "Customer    : " << schedule[monthIndex][dayIndex][slotIndex].customerName << " (" << schedule[monthIndex][dayIndex][slotIndex].customerID << ")" << endl;
                    cout << "Staff       : " << schedule[monthIndex][dayIndex][slotIndex].staffName << " (" << schedule[monthIndex][dayIndex][slotIndex].staffID << ")" << endl;
                    cout << "Service     : " << schedule[monthIndex][dayIndex][slotIndex].service << endl;
                    cout << "----------------------------------" << endl;

                    // double confirm
                    char confirm;
                    cout << "Are you sure you want to cancel this appointment? (Y/N): ";
                    cin >> confirm;

                    if (confirm == 'Y' || confirm == 'y') {
                        schedule[monthIndex][dayIndex][slotIndex].isBooked = false;
                        schedule[monthIndex][dayIndex][slotIndex].status = "Available";
                        schedule[monthIndex][dayIndex][slotIndex].appointmentID = "-";
                        schedule[monthIndex][dayIndex][slotIndex].customerID = "-";
                        schedule[monthIndex][dayIndex][slotIndex].customerName = "-";
                        schedule[monthIndex][dayIndex][slotIndex].staffID = "-";
                        schedule[monthIndex][dayIndex][slotIndex].staffName = "-";
                        schedule[monthIndex][dayIndex][slotIndex].service = "-";
                        schedule[monthIndex][dayIndex][slotIndex].price = 0.0;
                        SaveScheduleToFile();

                        cout << GREEN << "\n[Success] Appointment " << targetID << " has been cancelled successfully!" << RESET << endl;
                    }
                    else {
                        cout << RED << "\n[Info] Cancellation aborted." << RESET << endl;
                    }
                    return;
                }
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

    for (int monthIndex = 0; monthIndex < MONTH_IN_YEAR; monthIndex++) {
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

                //check wether is "booked" and have an "id"
                if (schedule[monthIndex][dayIndex][slotIndex].isBooked && schedule[monthIndex][dayIndex][slotIndex].appointmentID == targetID) {
                    found = true;

                    //permission checking
                    if (!currentUserId.empty() && schedule[monthIndex][dayIndex][slotIndex].customerID != currentUserId) {
                        cout << RED << "\n[Error] You do not have permission to reschedule another customer's appointment!" << RESET << endl;
                        return;
                    }

                    //print the details let user double check
                    cout << "\n------- Current Appointment Detail -------" << endl;
                    cout << "Date        : " << (dayIndex + 1) << "-" << monthIndex + 1 << "-" << curYear << endl;
                    cout << "Time Slot   : " << schedule[monthIndex][dayIndex][slotIndex].time << endl;
                    cout << "Customer    : " << schedule[monthIndex][dayIndex][slotIndex].customerName << " (" << schedule[monthIndex][dayIndex][slotIndex].customerID << ")" << endl;
                    cout << "Staff       : " << schedule[monthIndex][dayIndex][slotIndex].staffName << " (" << schedule[monthIndex][dayIndex][slotIndex].staffID << ")" << endl;
                    cout << "Service     : " << schedule[monthIndex][dayIndex][slotIndex].service << endl;
                    cout << "------------------------------------------" << endl;

                    int newMonthOption;
                    cout << "\nEnter New Month (1 - 12): ";
                    cin >> newMonthOption;

                    if (cin.fail() || newMonthOption < 1 || newMonthOption > 12) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << "\n[Error] Invalid month input!" << RESET << endl;
                        return;
                    }

                    int newMonthIndex = newMonthOption - 1;

                    // 1. input new day
                    int maxDays = daysInMonth[newMonthIndex];
                    int newDayOption;
                    cout << "Enter New Day of the Month (1 - " << maxDays << "): ";
                    cin >> newDayOption;

                    // check day
                    if (cin.fail() || newDayOption < 1 || newDayOption > 31) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << "\n[Error] Invalid day input!" << RESET << endl;
                        return;
                    }

                    int newDayIndex = newDayOption - 1;

                    // pass month & day cant book
                    if (newMonthOption < curMonth || (newMonthOption == curMonth && newDayOption < curDay)) {
                        cout << RED << "\n[Error] Cannot reschedule to past dates!" << RESET << endl;
                        return;
                    }

                    // open the day customer input
                    ViewAllAppointment(schedule[newMonthIndex][newDayIndex], TOTAL_SLOTS);

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
                    if (newMonthOption == curMonth && newDayOption == curDay && slotStartHours[newSlotIndex] <= curHour) {
                        cout << RED << "\n[Error] This time slot has already passed for today!" << RESET << endl;
                        return;
                    }

                    // cant book duplicate
                    if (schedule[newMonthIndex][newDayIndex][newSlotIndex].isBooked && (newMonthIndex != monthIndex || newDayIndex != dayIndex || newSlotIndex != slotIndex)) {
                        cout << RED << "\n[Sorry] Selected timeslot is already booked!" << RESET << endl;
                        return;
                    }

                    // 3. transfer data to new slot
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].appointmentID = schedule[monthIndex][dayIndex][slotIndex].appointmentID;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].customerID = schedule[monthIndex][dayIndex][slotIndex].customerID;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].customerName = schedule[monthIndex][dayIndex][slotIndex].customerName;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].staffID = schedule[monthIndex][dayIndex][slotIndex].staffID;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].staffName = schedule[monthIndex][dayIndex][slotIndex].staffName;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].service = schedule[monthIndex][dayIndex][slotIndex].service;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].price = schedule[monthIndex][dayIndex][slotIndex].price;
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].status = "Booked";
                    schedule[newMonthIndex][newDayIndex][newSlotIndex].isBooked = true;
                    SaveScheduleToFile();

                    // 4. reset original slot
                    schedule[monthIndex][dayIndex][slotIndex].isBooked = false;
                    schedule[monthIndex][dayIndex][slotIndex].status = "Available";
                    schedule[monthIndex][dayIndex][slotIndex].appointmentID = "-";
                    schedule[monthIndex][dayIndex][slotIndex].customerID = "-";
                    schedule[monthIndex][dayIndex][slotIndex].customerName = "-";
                    schedule[monthIndex][dayIndex][slotIndex].staffID = "-";
                    schedule[monthIndex][dayIndex][slotIndex].staffName = "-";
                    schedule[monthIndex][dayIndex][slotIndex].service = "-";
                    schedule[monthIndex][dayIndex][slotIndex].price = 0;
                    SaveScheduleToFile();

                    cout << GREEN << "\n[Success] Appointment " << targetID << " has been rescheduled successfully!" << RESET << endl;
                    return;
                }
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

    int monthOption;
    cout << "\nEnter Month (1 - 12): ";
    cin >> monthOption;

    if (cin.fail() || monthOption < 1 || monthOption > 12) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "\n[Error] Invalid month input!" << RESET << endl;
        return;
    }

    int monthIndex = monthOption - 1;

    int maxDays = daysInMonth[monthIndex];
    //choose specific day or all appointment 
    int dayOption;
    cout << "Enter Day of Month (1 - " << maxDays << ", or enter 0 to view ALL days in Month " << monthOption << "): ";
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
        cout << " Full Schedule for: " << GREEN << targetStaffID << " - " << targetStaffName << RESET << " (Month " << monthOption << ")" << endl;
        cout << "===========================================" << endl;

        bool hasBooking = false;

        //header
        int w_day = string("Day").length();
        int w_time = string("Time Slot").length();
        int w_id = string("Appointment ID").length();
        int w_custID = string("Customer ID").length();
        int w_custName = string("Customer Name").length();
        int w_service = string("Service").length();
        int w_price = string("Price (RM)").length();

        //find table width
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                if (schedule[monthIndex][dayIndex][slotIndex].isBooked && schedule[monthIndex][dayIndex][slotIndex].staffID == targetStaffID) {
                    string dayStr = "Day " + to_string(dayIndex + 1);
                    string priceStr = (ostringstream() << fixed << setprecision(2) << schedule[monthIndex][dayIndex][slotIndex].price).str();
                    w_day = max(w_day, (int)dayStr.length());
                    w_time = max(w_time, (int)schedule[monthIndex][dayIndex][slotIndex].time.length());
                    w_id = max(w_id, (int)schedule[monthIndex][dayIndex][slotIndex].appointmentID.length());
                    w_custID = max(w_custID, (int)schedule[monthIndex][dayIndex][slotIndex].customerID.length());
                    w_custName = max(w_custName, (int)schedule[monthIndex][dayIndex][slotIndex].customerName.length());
                    w_service = max(w_service, (int)schedule[monthIndex][dayIndex][slotIndex].service.length());
                    w_price = max(w_price, (int)priceStr.length());
                }
            }
        }

        string separator
            = "+" + string(w_day + 2, '-')
            + "+" + string(w_time + 2, '-')
            + "+" + string(w_id + 2, '-')
            + "+" + string(w_custID + 2, '-')
            + "+" + string(w_custName + 2, '-')
            + "+" + string(w_service + 2, '-')
            + "+" + string(w_price + 2, '-') + "+";

        //header
        cout << separator << endl;
        cout << "| " << left << setw(w_day) << "Day" << " "
            << "| " << setw(w_time) << "Time Slot" << " "
            << "| " << setw(w_id) << "Appointment ID" << " "
            << "| " << setw(w_custID) << "Customer ID" << " "
            << "| " << setw(w_custName) << "Customer Name" << " "
            << "| " << setw(w_service) << "Service" << " "
            << "| " << setw(w_price) << "Price (RM)" << " |\n";
        cout << separator << endl;

        for (int dayIndex = 0; dayIndex < 31; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                if (schedule[monthIndex][dayIndex][slotIndex].isBooked && schedule[monthIndex][dayIndex][slotIndex].staffID == targetStaffID) {
                    hasBooking = true;
                    string dayStr = to_string(dayIndex + 1);
                    //table info width
                    cout << "| " << left << setw(w_day) << dayStr << " "
                        << "| " << setw(w_time) << schedule[monthIndex][dayIndex][slotIndex].time << " "
                        << "| " << setw(w_id) << schedule[monthIndex][dayIndex][slotIndex].appointmentID << " "
                        << "| " << setw(w_custID) << schedule[monthIndex][dayIndex][slotIndex].customerID << " "
                        << "| " << setw(w_custName) << schedule[monthIndex][dayIndex][slotIndex].customerName << " "
                        << "| " << setw(w_service) << schedule[monthIndex][dayIndex][slotIndex].service << " "
                        << "| " << setw(w_price) << schedule[monthIndex][dayIndex][slotIndex].price << " "
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
        ViewAllAppointment(schedule[monthIndex][dayIndex], TOTAL_SLOTS, targetStaffID);
    }
}

void AppointmentMarking() {
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

    for (int monthIndex = 0; monthIndex < MONTH_IN_YEAR; monthIndex++) {
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {

                // check whether is "booked" and have an "id"
                if (schedule[monthIndex][dayIndex][slotIndex].isBooked && schedule[monthIndex][dayIndex][slotIndex].appointmentID == targetID) {
                    found = true;

                    // print current details for confirmation
                    cout << "\n------- Appointment Detail -------" << endl;
                    cout << "Date          : " << (dayIndex + 1) << "-" << monthIndex + 1 << "-" << curYear << endl;
                    cout << "Time Slot     : " << schedule[monthIndex][dayIndex][slotIndex].time << endl;
                    cout << "Customer      : " << schedule[monthIndex][dayIndex][slotIndex].customerName << " (" << schedule[monthIndex][dayIndex][slotIndex].customerID << ")" << endl;
                    cout << "Staff         : " << schedule[monthIndex][dayIndex][slotIndex].staffName << " (" << schedule[monthIndex][dayIndex][slotIndex].staffID << ")" << endl;
                    cout << "Service       : " << schedule[monthIndex][dayIndex][slotIndex].service << endl;
                    cout << "Current Status: " << YELLOW << schedule[monthIndex][dayIndex][slotIndex].status << RESET << endl;
                    cout << "----------------------------------" << endl;

                    // select new status
                    cout << "\nSelect New Status:\n";
                    cout << "1. Completed\n";
                    cout << "2. Pending Payment\n";
                    cout << "3. No-Show\n";
                    cout << "Select status option (1 - 3): ";

                    int markOption;
                    cin >> markOption;

                    if (cin.fail() || markOption < 1 || markOption > 3) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << RED << "\n[Error] Invalid status option!" << RESET << endl;
                        return;
                    }

                    switch (markOption) {
                    case 1:
                        schedule[monthIndex][dayIndex][slotIndex].status = "Completed";
                        break;
                    case 2:
                        schedule[monthIndex][dayIndex][slotIndex].status = "Pending Payment";
                        break;
                    case 3:
                        schedule[monthIndex][dayIndex][slotIndex].status = "No-Show";
                        break;
                    }

                    SaveScheduleToFile();
                    cout << GREEN << "\n[Success] Appointment " << targetID
                        << " status updated to: " << schedule[monthIndex][dayIndex][slotIndex].status << RESET << endl;
                    return;
                }
            }
        }
    }

    // if didn't find
    if (!found) {
        cout << RED << "\n[Error] Appointment ID '" << targetID << "' not found or is already cancelled." << RESET << endl;
    }
}

void ViewAppointmentServices() {
    cout << "\n==============================================================" << endl;
    cout << "                  APPOINTMENT SERVICES LIST                   " << endl;
    cout << "==============================================================" << endl;

    if (appointmentServiceCount == 0) {
        cout << YELLOW << "No appointment services available." << RESET << endl;
        return;
    }

    int w_num = string("No.").length();
    int w_id = string("Service ID").length();
    int w_name = string("Service Name").length();
    int w_price = string("Price (RM)").length();

    for (int i = 0; i < appointmentServiceCount; i++) {

        string priceStream = (ostringstream() << fixed << setprecision(2) << appointmentServiceDB[i].price).str();

        w_num = max(w_num, (int)to_string(i + 1).length());
        w_id = max(w_id, (int)appointmentServiceDB[i].serviceID.length());
        w_name = max(w_name, (int)appointmentServiceDB[i].serviceName.length());
        w_price = max(w_price, (int)priceStream.length());
    }

    string separator 
        = "+" + string(w_num + 2, '-')
        + "+" + string(w_id + 2, '-')
        + "+" + string(w_name + 2, '-')
        + "+" + string(w_price + 2, '-') + "+";

    cout << separator << endl;
    cout << "| " << left << setw(w_num) << "No." << " "
        << "| " << setw(w_id) << "Service ID" << " "
        << "| " << setw(w_name) << "Service Name" << " "
        << "| " << setw(w_price) << "Price (RM)" << " |\n";
    cout << separator << endl;

    for (int i = 0; i < appointmentServiceCount; i++) {
        cout << "| " << left << setw(w_num) << (i + 1) << " "
            << "| " << setw(w_id) << appointmentServiceDB[i].serviceID << " "
            << "| " << setw(w_name) << appointmentServiceDB[i].serviceName << " "
            << "| " << setw(w_price) << fixed << setprecision(2) << appointmentServiceDB[i].price << " "
            << "|" << endl;
    }

    cout << separator << endl;
}

void AddAppointmentService() {
    cout << "\n===========================================" << endl;
    cout << "         ADD NEW APPOINTMENT SERVICE       " << endl;
    cout << "===========================================" << endl;

    if (appointmentServiceCount >= MAX_APPOINTMENT_SERVICES) {
        cout << RED << "[Error] Database full! Cannot add more services." << RESET << endl;
        return;
    }

    string name;
    double price;

    cout << "Enter Service Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    if (name.empty()) {
        cout << RED << "[Error] Service name cannot be empty!" << RESET << endl;
        return;
    }

    cout << "Enter Service Price (RM): ";
    cin >> price;

    if (cin.fail() || price <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid price amount!" << RESET << endl;
        return;
    }

    //generate AppointmentService ID
    string newID = "AS" + to_string(appointmentServiceCounter++);

    appointmentServiceDB[appointmentServiceCount].serviceID = newID;
    appointmentServiceDB[appointmentServiceCount].serviceName = name;
    appointmentServiceDB[appointmentServiceCount].price = price;
    appointmentServiceCount++;

    cout << GREEN << "\n[Success] Service '" << name << "' (" << newID << ") added successfully!" << RESET << endl;
}

void EditAppointmentService() {
    cout << "\n===========================================" << endl;
    cout << "        EDIT APPOINTMENT SERVICE           " << endl;
    cout << "===========================================" << endl;

    ViewAppointmentServices();
    if (appointmentServiceCount == 0) return;

    int option;
    cout << "\nSelect Service No. to edit (1 - " << appointmentServiceCount << "): ";
    cin >> option;

    if (cin.fail() || option < 1 || option > appointmentServiceCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid selection!" << RESET << endl;
        return;
    }

    int index = option - 1;

    cout << "\nEditing Service: " << YELLOW << appointmentServiceDB[index].serviceName << RESET << endl;

    string newName;
    cout << "Enter New Service Name (Press Enter to keep current): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, newName);

    if (!newName.empty()) {
        appointmentServiceDB[index].serviceName = newName;
    }

    double newPrice;
    cout << "Enter New Price (RM) (Enter 0 to keep current RM " << fixed << setprecision(2) << appointmentServiceDB[index].price << "): ";
    cin >> newPrice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid price input! Price kept unchanged." << RESET << endl;
    }
    else if (newPrice > 0) {
        appointmentServiceDB[index].price = newPrice;
    }

    cout << GREEN << "\n[Success] Appointment Service updated successfully!" << RESET << endl;
}

void DeleteAppointmentService() {
    cout << "\n===========================================" << endl;
    cout << "       DELETE APPOINTMENT SERVICE          " << endl;
    cout << "===========================================" << endl;

    ViewAppointmentServices();
    if (appointmentServiceCount == 0) return;

    int option;
    cout << "\nSelect Service No. to delete (1 - " << appointmentServiceCount << "): ";
    cin >> option;

    if (cin.fail() || option < 1 || option > appointmentServiceCount) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << RED << "[Error] Invalid selection!" << RESET << endl;
        return;
    }

    int index = option - 1;
    string deletedName = appointmentServiceDB[index].serviceName;

    //move back the number deleted
    for (int i = index; i < appointmentServiceCount - 1; i++) {
        appointmentServiceDB[i] = appointmentServiceDB[i + 1];
    }
    appointmentServiceCount--;

    cout << GREEN << "\n[Success] Service '" << deletedName << "' has been deleted!" << RESET << endl;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lim Cai Xuan
bool isValidDateRange(int month, int year, int week) {
    if (month < 1 || month > 12) {
        return false;
    }
    if (year < 2000 || year > 2099) {
        return false;
    }
    if (week < 0 || week > 5) {
        return false;
    }
    return true;
}

void loadService() {

    if (bookingCount == 0) {
        cout << "No booking data available for reporting.\n";
        return;
    }

    for (int i = 0; i < bookingCount; i++) {
        const Bookings& booking = bookingDB[i];

        if (booking.status != "Completed" && booking.status != "Booked") {
            continue;
        }

        int serviceIdx = findServiceID(booking.serviceID);
        // Skip if service is not found
        if (serviceIdx == -1) {
            continue;
        }
        // Stop if report array capacity is reached MAX_REPORT_SIZE
        if (Booking_reportCount >= MAX_REPORT_SIZE) {
            cout << "Report data is full.\n";
            return;
        }

        const Services& service = servicesDB[serviceIdx];
        bookingReport[Booking_reportCount].appointmentId = booking.bookingID;

        // Fetch customer name from Customer & Member database
        int custIdx = findCustomerIndex(booking.customerID);
        if (custIdx != -1) {
            bookingReport[Booking_reportCount].customerName = customerDB[custIdx].nameCustomer;
        }
        else {
            int memIdx = findMemberIndex(booking.customerID);
            if (memIdx != -1) {
                bookingReport[Booking_reportCount].customerName = memberDB[memIdx].nameMember;
            }
            else {
                bookingReport[Booking_reportCount].customerName = booking.customerID;
            }
        }
        // Fetch staff name from Staff database
        int staffIdx = findStaffIndex(booking.staffID);
        if (staffIdx != -1) {
            bookingReport[Booking_reportCount].staffName = staffDB[staffIdx].nameStaff;
        }
        else {
            bookingReport[Booking_reportCount].staffName = booking.staffID;
        }
        // Set service details, quantity, and pric
        bookingReport[Booking_reportCount].serviceName = service.servicename;
        bookingReport[Booking_reportCount].quantity = 1;
        bookingReport[Booking_reportCount].price = service.price;

        if (booking.date.length() >= 10) {
            bookingReport[Booking_reportCount].day = stoi(booking.date.substr(0, 2));
            bookingReport[Booking_reportCount].month = stoi(booking.date.substr(3, 2));
            bookingReport[Booking_reportCount].year = stoi(booking.date.substr(6, 4));
        }
        else {
            bookingReport[Booking_reportCount].day = 1;
            bookingReport[Booking_reportCount].month = 8;
            bookingReport[Booking_reportCount].year = 2026;
        }

        bookingReport[Booking_reportCount].timeSlot = booking.time;
        bookingReport[Booking_reportCount].status = booking.status;

        Booking_reportCount++;
    }
}

void loadAppointments() {
    int year, month, currentDay, hour;
    getCurrentSystemTime(year, month, currentDay, hour);

    // ** data created for run only ** //
    for (int monthIndex = 0; monthIndex < MONTH_IN_YEAR; monthIndex++) {
        for (int dayIndex = 0; dayIndex < DAYS_IN_MONTH; dayIndex++) {
            for (int slotIndex = 0; slotIndex < TOTAL_SLOTS; slotIndex++) {
                Timeslot& slot = schedule[monthIndex][dayIndex][slotIndex];
                //only load booked or completed timeslots
                if (!slot.isBooked) {
                    continue;
                }

                if (slot.status != "Completed") {
                    continue;
                }

                if (Booking_reportCount >= MAX_REPORT_SIZE) {
                    cout << "Report data is full.\n";
                    return;
                }

                TotalBooking_Report& report = bookingReport[Booking_reportCount];
                report.appointmentId = slot.appointmentID;
                report.customerName = slot.customerName;
                report.staffName = slot.staffName;
                report.serviceName = slot.service;
                report.price = slot.price;
                report.quantity = 1;
                report.day = dayIndex + 1;
                report.month = monthIndex + 1;
                report.year = year;
                report.timeSlot = slot.time;
                report.status = slot.status;
                Booking_reportCount++;
            }
        }
    }
}

void loadDataFromTeamSystem() {
    Booking_reportCount = 0;
    loadService();
    loadAppointments();
}

void displayBarchart(string reportTitle, int month, int year, int weekFilter, int type, ostream& out) {
    out << "\n=== " << reportTitle << " (BARCHART) ===" << endl;
    out << "------------------------------------" << endl;

    string names[MAX_REPORT_SIZE];
    double values[MAX_REPORT_SIZE] = { 0 };
    int count = 0;

    for (int i = 0; i < Booking_reportCount; i++) {
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (weekFilter == 0) || (currentWeek == weekFilter);

        if ((bookingReport[i].status == "Booked" || bookingReport[i].status == "Completed") &&
            bookingReport[i].month == month &&
            bookingReport[i].year == year && weekMatch)
        {
            string key = (type == 1) ? bookingReport[i].serviceName : bookingReport[i].staffName;
            double val = (type == 1) ? (bookingReport[i].quantity * bookingReport[i].price) : bookingReport[i].quantity;

            bool found = false;
            for (int j = 0; j < count; j++) {
                if (names[j] == key) {
                    values[j] += val;
                    found = true;
                    break;
                }
            }
            if (!found) {
                names[count] = key;
                values[count] = val;
                count++;
            }
        }
    }

    if (count == 0) {
        out << "No records found for this timeframe." << endl;
    }
    else {
        for (int i = 0; i < count; i++) {
            out << left << setw(28) << names[i] << " | ";

            int stars = (type == 1) ? (int)(values[i] / 50) : (int)values[i];
            for (int k = 0; k < stars; k++)
                out << "*";

            if (type == 1) {
                out << "   (RM " << fixed << setprecision(2) << values[i] << ")" << endl;
            }
            else {
                out << "   (" << (int)values[i] << " times)" << endl;
            }
        }
    }
    out << "------------------------------------" << endl;
}

void RevenueReport(ostream& out) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter MM/YYYY/W (week0 is for Monthly): ";

    if (!(cin >> targetMonth >> targetYear >> targetWeek) ||
        !isValidDateRange(targetMonth, targetYear, targetWeek)) {

        // Clear all characters until newline
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nInvalid date range!" << endl;
        return;
    }

    loadDataFromTeamSystem();

    string serviceNames[MAX_REPORT_SIZE];
    int serviceQty[MAX_REPORT_SIZE] = { 0 };
    double serviceUnitPrice[MAX_REPORT_SIZE] = { 0.0 };
    double serviceRevenue[MAX_REPORT_SIZE] = { 0.0 };
    int serviceTypeCount = 0;
    double totalRevenue = 0.0;

    for (int i = 0; i < Booking_reportCount; i++) {
        // Calculate current week number (Week 1 to 5)
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if ((bookingReport[i].status == "Booked" || bookingReport[i].status == "Completed") &&
            bookingReport[i].month == targetMonth &&
            bookingReport[i].year == targetYear &&
            weekMatch) {

            // Check if service already exists in the list
            double amount = bookingReport[i].quantity * bookingReport[i].price;
            bool found = false;
            for (int j = 0; j < serviceTypeCount; j++) {
                if (serviceNames[j] == bookingReport[i].serviceName) {
                    serviceQty[j] += bookingReport[i].quantity;
                    serviceRevenue[j] += amount;
                    found = true;
                    break;
                }
            }
            // Add new service entry if not found in the list
            if (!found) {
                serviceNames[serviceTypeCount] = bookingReport[i].serviceName;
                serviceQty[serviceTypeCount] = bookingReport[i].quantity;
                serviceUnitPrice[serviceTypeCount] = bookingReport[i].price;
                serviceRevenue[serviceTypeCount] = amount;
                serviceTypeCount++;
            }
        }
    }

    out << "\n============================================================================" << endl;
    if (targetWeek > 0)
        out << "                    REVENUE REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
    else
        out << "                    MONTHLY REVENUE REPORT FOR " << targetMonth << "/" << targetYear << endl;
    out << "============================================================================" << endl;
    out << left << setw(28) << "Service Name"
        << right << setw(10) << "Unit Price"
        << setw(12) << "Total Qty"
        << setw(17) << "Total Amount" << endl;
    out << "----------------------------------------------------------------------------" << endl;

    for (int i = 0; i < serviceTypeCount; i++) {
        totalRevenue += serviceRevenue[i];

        out << left << setw(28) << serviceNames[i]
            << right << setw(4) << "RM " << setw(7) << fixed << setprecision(2) << serviceUnitPrice[i]
            << setw(9) << serviceQty[i]
            << setw(11) << "RM " << setw(9) << serviceRevenue[i] << endl;
    }

    out << "----------------------------------------------------------------------------" << endl;
    out << "TOTAL REVENUE GENERATED: RM " << fixed << setprecision(2) << totalRevenue << endl;
    out << "============================================================================" << endl;

    // use bubble sort to find the top service
    if (serviceTypeCount > 0) {
        int topIdx = 0;
        for (int i = 1; i < serviceTypeCount; i++) {
            if (serviceRevenue[i] > serviceRevenue[topIdx]) {
                topIdx = i;
            }
        }
        out << "\n*** TOP SERVICE ***" << endl;
        out << " Highest Revenue Service: " << serviceNames[topIdx]
            << " (Total: RM " << fixed << setprecision(2) << serviceRevenue[topIdx]
            << ", Total Qty: " << serviceQty[topIdx] << ")" << endl;
    }

    string title = (targetWeek > 0) ? "WEEKLY REVENUE" : "MONTHLY REVENUE";
    displayBarchart(title, targetMonth, targetYear, targetWeek, 1, out);
}

// ** Staff Report ** //
void StaffReport(ostream& out) {
    int targetMonth, targetYear, targetWeek;
    cout << "\nEnter MM/YYYY/W (week0 is for Monthly): ";

    if (!(cin >> targetMonth >> targetYear >> targetWeek) ||
        !isValidDateRange(targetMonth, targetYear, targetWeek)) {

        // Clear all characters until newline
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nInvalid date range!" << endl;
        return;
    }

    loadDataFromTeamSystem();

    string staffNames[MAX_REPORT_SIZE];
    int serviceCounts[MAX_REPORT_SIZE] = { 0 };
    int uniqueStaff = 0;
    int totalServicesHandled = 0;

    for (int i = 0; i < Booking_reportCount; i++) {
        // Calculate current week number (Week 1 to 5)
        int currentWeek = (bookingReport[i].day - 1) / 7 + 1;
        bool weekMatch = (targetWeek == 0) || (currentWeek == targetWeek);

        if ((bookingReport[i].status == "Booked" || bookingReport[i].status == "Completed") &&
            bookingReport[i].month == targetMonth &&
            bookingReport[i].year == targetYear && weekMatch)
        {
            bool found = false;
            // Check if service already exists in the list
            for (int j = 0; j < uniqueStaff; j++) {
                if (staffNames[j] == bookingReport[i].staffName) {
                    serviceCounts[j] += bookingReport[i].quantity;
                    found = true;
                    break;
                }
            }
            // Add new staff entry if not found in the list
            if (!found) {
                staffNames[uniqueStaff] = bookingReport[i].staffName;
                serviceCounts[uniqueStaff] = bookingReport[i].quantity;
                uniqueStaff++;
            }
        }
    }

    out << "\n============================================================================" << endl;
    if (targetWeek > 0)
        out << "                 STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear << " (WEEK " << targetWeek << ")" << endl;
    else
        out << "                 MONTHLY STAFF WORKLOAD REPORT FOR " << targetMonth << "/" << targetYear << endl;
    out << "============================================================================" << endl;

    out << left << setw(40) << "Staff Name"
        << right << setw(20) << "Services Handled" << endl;
    out << "----------------------------------------------------------------------------" << endl;

    // print each staff's service count
    for (int j = 0; j < uniqueStaff; j++) {
        totalServicesHandled += serviceCounts[j];
        out << left << setw(40) << staffNames[j]
            << right << setw(20) << serviceCounts[j] << endl;
    }

    out << "----------------------------------------------------------------------------" << endl;
    out << left << setw(40) << "TOTAL SERVICES COMPLETED:"
        << right << setw(20) << totalServicesHandled << endl;
    out << "============================================================================" << endl;

    string title = (targetWeek > 0) ? "WEEKLY STAFF WORKLOAD" : "MONTHLY STAFF WORKLOAD";
    displayBarchart(title, targetMonth, targetYear, targetWeek, 2, out);
}

void ReportExport() {
    int exportChoice;
    cout << "\n=== REPORT EXPORT ===" << endl;
    cout << "1. Export Revenue Report" << endl;
    cout << "2. Export Staff Report" << endl;
    cout << "Please select report type to export: ";
    cin >> exportChoice;

    if (exportChoice != 1 && exportChoice != 2) {
        cout << "Invalid choice." << endl;
        return;
    }

    ofstream outFile("report_export.txt");
    if (!outFile.is_open()) {
        cout << "--> File output error!" << endl;
        return;
    }

    if (exportChoice == 1) {
        RevenueReport(outFile);
    }
    else {
        StaffReport(outFile);
    }

    outFile.close();
    cout << "\n--> Report printed successfully!" << endl;
}

void reportingMenu() {
    cout << "\n========================================" << endl;
    cout << "        REPORTING SYSTEM                " << endl;
    cout << "========================================" << endl;
    cout << "1. Revenue Report (Weekly / Monthly)" << endl;
    cout << "2. Staff Report (Weekly / Monthly)" << endl;
    cout << "3. Report Export" << endl;
    cout << "0. Exit" << endl;
    cout << "Please choose an option: ";
}

void Reporting() {
    int option;
    do {
        reportingMenu();
        cin >> option;

        switch (option) {

        case 1:
            RevenueReport();
            break;
        case 2:
            StaffReport();
            break;
        case 3:
            ReportExport();
            break;
        case 0:
            cout << "\nExiting program." << endl;
            break;
        default:
            cout << "\nInvalid option. Please try again." << endl;
            break;
        }

        if (option >= 1 && option <= 4) {
            cout << "\nPress Enter to return to menu...";
            cin.ignore();
            cin.get();
        }

    } while (option != 0);
}