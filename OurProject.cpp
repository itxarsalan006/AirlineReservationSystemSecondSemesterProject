#include <iostream>
#include <string>

using namespace std;

class Passenger {
public:
    string name;
    string address;
    string age;
    string passportNumber;
    string contactNumber;
    string cnicNumber;

    void inputPassengerInfo() {
        cin.ignore();
        cout << "\t\tEnter Name: ";
        getline(cin, name);

        cout << "\t\tEnter Age: ";
        getline(cin, age);

        cout << "\t\tEnter Passport Number: ";
        getline(cin, passportNumber);

        cout << "\t\tEnter CNIC Number: ";
        getline(cin, cnicNumber);

        cout << "\t\tEnter Address: ";
        getline(cin, address);

        cout << "\t\tEnter Contact Number: ";
        getline(cin, contactNumber);

        cout << endl;
    }

    void displayPassengerInfo() const {
        cout << "\nPassenger Name: " << name << endl;
        cout << "Passenger Age: " << age << endl;
        cout << "Passenger Passport Number: " << passportNumber << endl;
        cout << "Passenger CNIC Number: " << cnicNumber << endl;
        cout << "Passenger Address: " << address << endl;
        cout << "Passenger Contact Number: " << contactNumber << endl;
    }
};

class Flight {
public:
    string flightName;
    string departure;
    string destination;

    Flight() {}
    Flight(string fn, string dep, string dest) : flightName(fn), departure(dep), destination(dest) {}

    void displayFlightInfo() const {
        cout << "Flight Name: " << flightName << endl;
        cout << "Departure: " << departure << endl;
        cout << "Destination: " << destination << endl;
    }
};

class Reservation {
public:
    Passenger passenger;
    Flight flight;

    void inputReservation(const Flight& selectedFlight) {
        flight = selectedFlight;
        passenger.inputPassengerInfo();
    }

    void displayReservation()  {
        passenger.displayPassengerInfo();
        flight.displayFlightInfo();
    }
};

class AirlineReservationSystem {
    static const int MAX_RESERVATIONS = 10;
    static const int MAX_FLIGHTS = 5;
    Reservation reservations[MAX_RESERVATIONS];
    Flight flights[MAX_FLIGHTS];
    int reservationCount;
    int flightCount;

public:
    AirlineReservationSystem() : reservationCount(0), flightCount(0) {
        // Initializing flights
	    flights[0] = Flight("PK001", "Lahore", "Karachi");
        flights[1] = Flight("PK002", "Peshawar", "Lahore");
        flights[2] = Flight("PK003", "Lahore", "Peshewar");
        flights[3] = Flight("PK004", "Islamabad", "Karachi");
        flights[4] = Flight("PK005", "Islamabad", "Quetta");
        flightCount = 5;
    }
    

    void mainMenu() {
        char choice;
        while (true) {
            cout << "\n\n\n\n\n";
            cout << "\t\t\t\t    _____________________________________________________\n";
            cout << "\t\t\t\t   >                                                     <\n";
            cout << "\t\t\t\t   >                                                     <\n";
            cout << "\t\t\t\t   >         WELCOME TO AIRLINE RESERVATION SYSTEM       <\n";
            cout << "\t\t\t\t   >                                                     <\n";
            cout << "\t\t\t\t   >_____________________________________________________<\n";
            cout << "\t\t <1> Menu\n";
            cout << "\t\t <2> Flight Schedule\n";
            cout << "\t\t <3> Exit\n";
            cout << "\t\t Enter Your Choice: ";
            cin >> choice;
            cout << endl << endl;

            switch (choice) {
                case '1':
                    menu();
                    break;
                case '2':
                    flightSchedule();
                    break;
                case '3':
                    cout << "\t\t\t\t\t Thank you for using our system" << endl;
                    return;
                default:
                    cout << "Invalid choice, try again" << endl;
                    break;
            }
        }
    }

private:
    void menu() {
        char choice;
        while (true) {
            cout<<"\t\t\t\t *****************************************\n";
            cout<<"\t\t\t\t **                                     **\n";
            cout<<"\t\t\t\t **                                     **\n";
            cout<<"\t\t\t\t **            MAIN MENU                **\n";
            cout<<"\t\t\t\t **                                     **\n";
            cout<<"\t\t\t\t **                                     **\n";
            cout<<"\t\t\t\t *****************************************\n";
            cout<<"\t\t <1> Reserve Flight OR Registration\n";
            cout<<"\t\t <2> View All Reservations\n";
            cout<<"\t\t <3> Search Reservation\n";
            cout<<"\t\t <4> Delete Reservation\n";
            cout<<"\t\t <5> Go Back\n";
            cout<<"\t\t Enter Your Choice: ";
            cin>>choice;
            cout<<endl<<endl;

            switch (choice) {
                case '1':
                    reserveFlight();
                    break;
                case '2':
                    viewAllReservations();
                    break;
                case '3':
                    searchReservation();
                    break;
                case '4':
                    deleteReservation();
                    break;
                case '5':
                    return;
                default:
                    cout << "Invalid choice, try again." << endl;
                    break;
            }
        }
    }

    void reserveFlight() {
        if (reservationCount < MAX_RESERVATIONS) {
            string departure, destination;
            cout << "Enter Departure: ";
            cin.ignore();
            getline(cin, departure);
            cout << "Enter Destination: ";
            getline(cin, destination);

            int selectedFlightIndex = -1;
            for (int i = 0; i < flightCount; i++) {
                if (flights[i].departure == departure && flights[i].destination == destination) {
                    selectedFlightIndex = i;
                    break;
                }
            }

            if (selectedFlightIndex != -1) {
                reservations[reservationCount].inputReservation(flights[selectedFlightIndex]);
                reservationCount++;
                cout << "Flight reserved successfully!" << endl;
            } else {
                cout << "No flights available for the selected route." << endl;
            }
        } else {
            cout << "All reservations are full!" << endl;
        }
    }

    void viewAllReservations() {
        cout << "\t\t   ________________________\n";
        cout << "\t\t **                        **\n";
        cout << "\t\t ** ALL RESERVATIONS SEATS **\n";
        cout << "\t\t **________________________**\n";

        for (int i = 0; i < reservationCount; i++) {
            reservations[i].displayReservation();
        }
    }

    void searchReservation() {
        cout << "\t\t\t   _______________________\n";
        cout << "\t\t\t **                       **\n";
        cout << "\t\t\t **  SEARCH RESERVATION   **\n";
        cout << "\t\t\t **_______________________**\n";

        string name;
        cout << "Enter the passenger name: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < reservationCount; i++) {
            if (reservations[i].passenger.name == name) {
                reservations[i].displayReservation();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "No reservation found with this name: " << name << endl;
        }
    }

    void deleteReservation() {
        cout << "\t\t\t   ________________________\n";
        cout << "\t\t\t **                        **\n";
        cout << "\t\t\t **   DELETE RESERVATION   **\n";
        cout << "\t\t\t **________________________**\n";

        string name;
        cout << "Enter the passenger name to delete: ";
        cin.ignore();
        getline(cin, name);

        bool found = false;
        for (int i = 0; i < reservationCount; i++) {
            if (reservations[i].passenger.name == name) {
                for (int j = i; j < reservationCount - 1; j++) {
                    reservations[j] = reservations[j + 1];
                }
                reservationCount--;
                found = true;
                cout << "Reservation deleted successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "No reservation found with this name: " << name << endl;
        }
    }

    void flightSchedule() {
        cout << "\n\n\n\n\n\t\t\t\t\tWELCOME TO THE AIRLINE FLIGHT SCHEDULE\n\n";
        cout << "\t\t\t\t\t _____________________________________________________________________________\n";
        cout << "\t\t\t\t\t| Read The Schedule Carefully Before Reserving Your Seat                      |\n";
        cout << "\t\t\t\t\t|_____________________________________________________________________________|\n";
        cout << "\t\t\t\t\t| S.NO| FLIGHT NAME  |     DEPARTURE     |     DESTINATION      |   COST      |\n";
        cout << "\t\t\t\t\t| 01  |   PK001      |  Lahore           |     Karachi          |   15k       |\n";
	    cout << "\t\t\t\t\t| 02  |   PK002      |  Peshawar         |     Lahore           |   20k       |\n";
	    cout << "\t\t\t\t\t| 03  |   PK003      |  Lahore           |     Peshawar         |   18k       |\n";
	    cout << "\t\t\t\t\t| 04  |   PK004      |  Islamabad        |     Karachi          |   25k       |\n";
	    cout << "\t\t\t\t\t| 05  |   PK005      |  Islamabad        |     Quetta           |   22k       |\n";
	    cout << "\t\t\t\t\t|_____|_____________ |___________________|______________________|_____________|\n";

    
    }

public:
    void run() {
        mainMenu();
    }
};

int main() {
    AirlineReservationSystem ars;
    ars.run();
    return 0;
}

