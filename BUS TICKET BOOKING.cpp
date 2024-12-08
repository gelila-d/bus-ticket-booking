
#include <iostream>
#include <string>

using namespace std;

class Bus {
public:
    static const int MAX_CAPACITY = 100;
    static const int START_BUS_NO = 1;

    int currentCapacity;
    int busNo;

    Bus() : currentCapacity(0), busNo(START_BUS_NO) {
        for (int i = 0; i < MAX_CAPACITY; ++i) {
            passengerNames[i] = "";
        }
    }

    void bookTicket(int numTickets, const string& name, const string& destination) {
        int remainingTickets = numTickets;
        bool firstPassenger = true;

        while (remainingTickets > 0) {
            int availableSeats = MAX_CAPACITY - currentCapacity;

            if (availableSeats > 0) {
                int ticketsToBook = min(remainingTickets, availableSeats);

                for (int i = 0; i < ticketsToBook; ++i) {
                    if (firstPassenger) {
                        passengerNames[currentCapacity] = name;
                        firstPassenger = false;
                    } else {
                        cout << "Passenger " << currentCapacity + 1 << " name: ";
                        string passenger;
                        getline(cin, passenger);
                        passengerNames[currentCapacity] = passenger;
                    }
                    currentCapacity++;
                }

                remainingTickets -= ticketsToBook;

                if (remainingTickets == 0) {
                    cout << "Ticket(s) booked successfully!\n\n";
                    cout << "\t\t================= Hope you have a great trip to " << destination << "! =================\n";
                }
            } else {
                busNo++;
                currentCapacity = 0;
                cout << "Sorry, no more seats available on bus number " << busNo - 1 << ". Moving to bus number " << busNo << ".\n";
            }
        }
    }

    int getAvailableSeats() const {
        return MAX_CAPACITY - currentCapacity;
    }

private:
    string passengerNames[MAX_CAPACITY];
};

int main() {
    Bus bus;

    while (true) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Book Ticket\n";
        cout << "2. Check Available Seats\n";
        cout << "3. Check Bus Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            break;
        }

        switch (choice) {
            case 1: {
                int numTickets;
                string name, destination;

                cout << "Enter the number of tickets to be booked: ";
                if (!(cin >> numTickets)) {
                    cout << "Invalid input. Please enter a number.\n";
                    cin.clear();
                    while (cin.get() != '\n');
                    continue;
                }

                while (cin.get() != '\n');

                cout << "Enter your name: ";
                getline(cin, name);

                cout << "Enter the destination: ";
                getline(cin, destination);

                bus.bookTicket(numTickets, name, destination);
                break;
            }
            case 2:
                cout << "Available Seats: " << bus.getAvailableSeats() << "\n";
                break;
            case 3:
                cout << "Bus Number: " << bus.busNo << "\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }

    return 0;
}

