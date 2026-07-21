#include <iostream>
#include <iomanip>
using namespace std;

// Logo
int main() {
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
	// Menu
	cout << "Welcome to the Appointment Scheduler!\n" << endl;
	cout << "Please select an option from the menu below:" << endl;
	cout << "1. View All Appointment" << endl;
	cout << "2. Create a New Appointment" << endl;
	cout << "3. Cancel Appointment" << endl;
	cout << "4. Reschedule Appointment" << endl;
	cout << "5. View Staff Schedule" << endl;
	cout << "6. Exit\n" << endl;

	// Get user input
	int option;
	cin >> option;

	switch (option) {
	case 1:
		cout << "You selected: View All Appointment" << endl;
		for (int i = 0; i < 5; i++) {
			cout << "Appointment " << i + 1 << ": [Details of appointment]" << endl;

		}
		break;
	case 2:
		cout << "You selected: Create a New Appointment" << endl;
		break;
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
		cout << "Exiting the program. Goodbye!" << endl;
		break;
	default:
		cout << "Invalid option. Please select a valid option from the menu." << endl;
	}

    return 0;
}