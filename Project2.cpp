#include <iostream>
#include <string>
using namespace std;

const string one = "Brokerage"; // Made one constant
const string two = "Retirement"; // Made two constant

int ChangeCustomerChoice(int service) { // Added service as a parameter.
    cout << "Please enter the client's new service (1 = Brokerage, 2 = Retirement)" << endl;
    try { // Use a try catch for user input.

        cin >> service;

        if (service == 1) {
            cout << "You have selected: " << one << '\n' << endl; // Removed unnecessary endline
        }
        else if (service == 2) {
            cout << "You have selected: " << two << '\n' << endl; // Removed unnecessary endline
        }
        else {
            throw 505; // Throws custom error for any input not 1 or 2.
        }

        return service; // Return service for future operations.
    }
    catch (...) {
        std::cin.clear(); //clear bad input flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
        std::cout << "Invalid command; please try again.\n" << endl; // Alert user
    }
    
}

int DisplayInfo(string user, int service, int choice) {
    while (choice != 3) { // Added in sentinel value for while loop.
        try { // Use try catch for user input
            cout << "What would you like to do?" << endl;

            cout << "DISPLAY client name & service (enter 1)" << endl;
            cout << "CHANGE clients choice (enter 2)" << endl;
            cout << "Exit program.. (enter 3)" << endl;

            cin >> choice;

            if (choice == 1) {
                cout << "Client: " << user << endl;
                cout << "Service: ";
                if (service == 0) {
                    cout << "None\n" << endl; // Removed one of the endls
                }
                else if (service == 1) {
                    cout << one << '\n' << endl; // Removed one of the endls   
                }
                else if (service == 2) {
                    cout << two << '\n' << endl; // Removed one of the endls               
                }
                continue;
            }
            else if (choice == 2) {
                service = ChangeCustomerChoice(service);
                continue;
            }
            else if (choice == 3) {
                exit(0);
            }
            else {
                throw 505;
            }
            return service; // Return service for future operations.  
        }
        catch (...) {
            std::cin.clear(); //clear bad input flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
            std::cout << "Invalid command; please try again.\n" << endl; // Alert user
        }
    }
      
}

string CheckUserPermissionAccess(string user, string password, string securityQuestion) {
    while (user != "q" || password != "q" || securityQuestion != "q") { // Loop uses sentinel values
        cout << "You may enter <q> at any time to exit Authentication" << endl;

        cout << "Please enter your username: ";
        cin >> user;
        cout << endl;

        if (user == "q") {
            exit(0);
        }
        else if (!(user == "admin321")) { // Added in conditions for username.
            cout << "Unrecognized user. Please try again\n" << endl;
            continue;
        }
        cout << "Enter password: ";
        cin >> password;
        cout << endl;

        if (password == "q") {
            exit(0);
        }
        else if (password == "$m3llycat") { // Made password more secure.
            cout << "First Authentication Successful\n" << endl;
            
        }
        else {
            cout << "Authentication Unsuccessful. Please try again\n" << endl;
            continue;
        }

        cout << "Enter the name of your first pet: "; // Added in section for security question.
        cin >> securityQuestion;
        cout << endl;

        if (securityQuestion == "q") {
            exit(0);
        }
        else if (securityQuestion == "Chubbers") {
            cout << "Second Authentication Successful\n" << endl;
            break;
        }
        else {
            cout << "Authentication Unsuccessful. Please try again\n" << endl;
            continue;
        }
    }
    return user; // Return user for future operations.

}


int main() {
    string user = ""; // Moved from global to local scope.
    string password = ""; // Moved from global to local scope.
    int choice = 0; // Moved from global to local scope.
    int service = 0; // Moved from global to local scope.
    string securityQuestion = ""; // Created security question for two step verification.

    cout << "Created by John Brungard" << endl;

    cout << "Welcome to SNHU Investment\n" << endl;

    user = CheckUserPermissionAccess(user, password, securityQuestion);

    DisplayInfo(user, service, choice);
}