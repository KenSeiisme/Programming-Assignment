#include <iostream>
#include <iomanip>
#include <string>
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

int main() {

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

	return 0;
}



