#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
int main()
{
    // data structures for buses//

    int bookingCount = 0; // total bookings //
    int totalbuses = 5;
    int maxbuses = 10;

    const int MAX_BUSES = 10;
    const int MAX_SEATS = 30;
    const int MAX_BOOKINGS = MAX_BUSES * MAX_SEATS;

    string routes_name[MAX_BUSES] = {"muree", "lahore", "karachi", "faisalabad", "multan"}; // routes of bus
    int fare[MAX_BUSES] = {1000, 1500, 3000, 2500, 2000};                                   // fare of buse//
    int totalSeats[MAX_BUSES] = {30, 30, 30, 30, 30};
    int seats[MAX_BUSES] = {30, 30, 30, 30, 30};

    // booking system data //

    string names[MAX_BOOKINGS];       // store names
    int ids[MAX_BOOKINGS];            // store IDs
    string bookedRoute[MAX_BOOKINGS]; // store route
    int bookedSeats[MAX_BOOKINGS];    // store number of tickets

    while (true)
    {
        // INTRO HEADER//

        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "------------------BUSES MANAGEMENT SYSTEM--------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;

        // main header//
        cout << " **********************USER MENU******************** " << endl;
        cout << "1. Admin menu" << endl;
        cout << "2. Passenger menu " << endl;
        cout << "3. Exit " << endl;
        cout << "Choose any option : ";

        int user_option;
        cin >> user_option;
        cout << "You choose : " << user_option << endl;

        if (user_option == 1)
        {
            // admin code//

            bool exitadmin = false;
            for (int i = 0; i < 3 && !exitadmin; i++) // pasword checking
            {
                system("cls");
                string admin_pasword = "admin1234";
                string input_pasword;
                cout << "\n"
                     << "loggin attemt" << i + 1 << endl;
                cout << " ENTER THE ADMIN PASWORD : ";

                cin >> input_pasword;

                if (input_pasword == admin_pasword) // for successfull login//
                {
                    cout << " successfully loged in " << endl;

                    cout << "press any key to continue";
                    getch();

                    int choice = 0;

                    while (choice != 6) // while loop//
                    {
                        system("cls");
                        cout << " =======ADMN MENU=======" << endl;
                        cout << "1. View bookings" << endl;
                        cout << "2. Search booking by id" << endl;
                        cout << "3. Add Bus" << endl;
                        cout << "4. Edit buses" << endl;
                        cout << "5. View buses" << endl;
                        cout << "6. Exit" << endl;
                        cout << "Enter your choice ";
                        cin >> choice;

                        if (choice == 1) // view booking//
                        {

                            system("cls");
                            if (bookingCount == 0)
                            {
                                cout << "No bookings yet" << endl;
                                cout << "Press B to go back";
                            }
                            else
                            {
                                cout << "BOOKING NO\tNAME\t\tID\tROUTE\t\tSEATS" << endl;
                                cout << "--------------------------------------------------------" << endl;
                                ;

                                for (int x = 0; x < bookingCount; x++)
                                {
                                    cout << x + 1 << "\t\t" << names[x] << "\t\t" << ids[x] << "\t" << bookedRoute[x] << "\t\t" << bookedSeats[x] << endl;
                                }
                            }

                            getch();
                        }
                        else if (choice == 2)
                        {
                            system("cls");

                            int searchID;
                            cout << "Enter ID to search: ";
                            cin >> searchID;

                            if (cin.fail())
                            {
                                cin.clear();
                                cin.ignore(1000, '\n');
                                cout << "Invalid input! Please enter numbers only." << endl;
                                getch();
                            }
                            else
                            {
                                bool found = false;
                                for (int x = 0; x < bookingCount; x++)
                                {
                                    if (ids[x] == searchID)
                                    {
                                        found = true;
                                        cout << "Booking Found!" << endl;
                                        cout << "Name:  " << names[x] << endl;
                                        cout << "ID:    " << ids[x] << endl;
                                        cout << "Route: " << bookedRoute[x] << endl;
                                        cout << "Seats: " << bookedSeats[x] << endl;
                                        break;
                                    }
                                }

                                if (!found)
                                {
                                    cout << "No booking found with this ID" << endl;
                                    cout << "Press any key to go back";
                                }
                                getch();
                            }
                        }
                        else if (choice == 3) // add bus//
                        {

                            system("cls");
                            if (totalbuses < maxbuses)
                            {
                                cout << "Enter Route: ";
                                cin >> routes_name[totalbuses];

                                cout << " Enter the fare for your route : ";
                                cin >> fare[totalbuses];

                                cout << "Enter Seats: ";
                                cin >> seats[totalbuses];

                                totalbuses++;

                                cout << "Bus added successfully!" << endl;
                                cout << " press any key to continue " << endl;
                            }
                            else
                            {
                                cout << " Maximum limit reached" << endl;
                            }
                            getch();
                        }
                        else if (choice == 4) // edit bus//
                        {

                            system("cls");

                            string searchRoute;
                            cout << "Enter the route you want to edit: ";
                            cin >> searchRoute;

                            int index = -1;

                            // Search route//

                            for (int i = 0; i < totalbuses; i++)
                            {
                                if (routes_name[i] == searchRoute)
                                {
                                    index = i;
                                    break;
                                }
                            }

                            //  IF NOT FOUND//

                            if (index == -1)
                            {
                                cout << "This route is not present in the system!" << endl;
                            }
                            else
                            {
                                cout << "Route Found: " << routes_name[index] << endl;
                                cout << "Current Seats: " << seats[index] << endl;
                                cout << "Current Fare: " << fare[index] << endl;

                                cout << "What do you want to edit?" << endl;
                                cout << "1. Update Seats" << endl;
                                cout << "2. Update Fare" << endl;
                                cout << "3. Delete Route" << endl;
                                cout << "Enter choice: ";

                                int editChoice;
                                cin >> editChoice;

                                // STEP 3: UPDATE SEATS//

                                if (editChoice == 1)
                                {
                                    cout << "Enter new seats: ";
                                    cin >> totalSeats[index];
                                    seats[index] = totalSeats[index];
                                    cout << "Seats updated successfully!" << endl;
                                }

                                //  UPDATE FARE//

                                else if (editChoice == 2)
                                {
                                    cout << "Enter new fare: ";
                                    cin >> fare[index];

                                    cout << "Fare updated successfully!" << endl;
                                }

                                // DELETE ROUTE//

                                else if (editChoice == 3)
                                {
                                    for (int i = index; i < totalbuses - 1; i++)
                                    {
                                        routes_name[i] = routes_name[i + 1];
                                        fare[i] = fare[i + 1];
                                        seats[i] = seats[i + 1];
                                        totalSeats[i] = totalSeats[i + 1];
                                    }

                                    totalbuses--;

                                    cout << "Route deleted successfully!" << endl;
                                }
                            }
                            getch();
                        }
                        else if (choice == 5) // VIEW ALL BUSES
                        {
                            system("cls");

                            if (totalbuses == 0)
                            {
                                cout << "No buses available!" << endl;
                            }
                            else
                            {
                                cout << "=========== ALL BUSES ===========" << endl;
                                cout << "No\tRoute\t\tFare\tTotal\tBooked\tAvailable" << endl;
                                cout << "-------------------------------------------------------------" << endl;

                                for (int i = 0; i < totalbuses; i++)
                                {
                                    int booked = totalSeats[i] - seats[i];
                                    seats[totalbuses] = totalSeats[totalbuses];
                                    cout << i + 1 << "\t"
                                         << routes_name[i] << "\t\t"
                                         << fare[i] << "\t"
                                         << totalSeats[i] << "\t"
                                         << booked << "\t"
                                         << seats[i] << endl;
                                }
                            }

                            cout << "Press any key to go back...";
                            getch();
                        }
                        else if (choice == 6)
                        {
                            exitadmin = true;
                            cout << " To exit admin menu press any key " << endl;
                            break;
                        }
                        else
                        {
                            cout << "invalid option" << endl;
                            cout << " press any key to continue..." << endl;
                            getch();
                        }
                    }
                }
                else
                {
                    cout << "Wrong pasword !. please enter the correct pasword" << endl;
                    cout << " To login again click continue  " << endl;
                }
                getch();
            }
        }

        else if (user_option == 2) // passenger menu//
        {
            // passenger code//
            int option = 0;

            while (option != 4)
            {
                system("cls");
                cout << "=======PASSENGER MENU=========" << endl;

                // routes avilable//

                cout << "\t" << " Availabe routes" << "\t" << endl;
                for (int i = 0; i < totalbuses; i++)
                {
                    cout << routes_name[i] << endl;
                }

                cout << "1. VIEW FARES " << endl;   
                cout << "2. BOOK TICKETS " << endl;  
                cout << "3. PRINT TICKETS " << endl; 
                cout<<"4. EXIT"<<endl;
                cout << " choose your option : ";

                int option;
                cin >> option;
                if (option == 1)
                {
                    // ================= FARE CHECK =================

                    system("cls");

                    cout << "Route\t\t\tFare" << endl;
                    for (int i = 0; i < totalbuses; i++)
                    {
                        cout << routes_name[i] << "\t\t\t" << fare[i] << endl;
                    }
                    cout << " press any key to go to the menu " << endl;
                    getch();
                }
                else if (option == 2)
                {
                    system("cls");
                    cout << "---------------BOOKING------------------" << endl;
                    cout << " These are the available buses " << endl;

                    for (int i = 0; i < totalbuses; i++)
                    {
                        cout << i + 1 << "\t" << routes_name[i] << endl;
                    }

                    cout << "Check the routes available for you and press any kess for further process" << endl;
                    getch();
                    // ================= BOOKING =================

                    system("cls");

                    string city;
                    cout << "Enter route: ";
                    cin >> city;

                    int index = -1;

                    for (int i = 0; i < totalbuses; i++)
                    {
                        if (city == routes_name[i])
                        {
                            index = i;
                            break;
                        }
                    }

                    if (index == -1)
                    {
                        cout << "Invalid route!";
                        getch();
                    }
                    else
                    {
                        cout << "Route selected: " << routes_name[index] << endl;
                        cout << "Available seats: " << seats[index] << endl;

                        int tickets;
                        cout << "Enter tickets: ";
                        cin >> tickets;

                        if (tickets <= seats[index] && tickets > 0)
                        {
                            system("cls");
                            cout << " seats are available " << endl;

                            string name;
                            cout << "Enter name: ";
                            cin >> name;
                            int id;
                            cout << "Enter ID: ";
                            cin >> id;
                            int total = tickets * fare[index];

                            cout << "Total Fare: " << total << endl;

                            seats[index] -= tickets;

                            // STORE DATA//

                            names[bookingCount] = name;
                            ids[bookingCount] = id;
                            bookedRoute[bookingCount] = routes_name[index];
                            bookedSeats[bookingCount] = tickets;

                            bookingCount++;

                            cout << "Booking successful!" << endl; // booking done
                            cout << "Remaining seats: " << seats[index] << endl;
                            cout << " press any key to continue" << endl;
                        }
                        else
                        {
                            cout << "Not enough seats!";
                            cout<<" press any key to go back"<<endl;
                        }
                        getch();
                    }
                }
                // ticket printing//
                else if (option == 3)
                {

                    system("cls");
                    int searchId;
                    cout << " Enter your id to print ticket : ";
                    cin >> searchId;

                    bool found = false;

                    string routeList[MAX_BUSES];
                    int seatList[MAX_BUSES] = {0};
                    int fareList[MAX_BUSES] = {0};
                    int routeCount = 0;

                    int grandTotal = 0;
                    for (int i = 0; i < bookingCount; i++)
                    {
                        if (ids[i] == searchId)
                        {
                            found = true;

                            bool routefound = false;
                            for (int j = 0; j < routeCount; j++)
                            {
                                if (routeList[j] == bookedRoute[i])
                                {
                                    seatList[j] += bookedSeats[i];
                                    routefound = true;
                                    break;
                                }
                            }

                            if (!routefound)
                            {
                                routeList[routeCount] = bookedRoute[i];
                                seatList[routeCount] = bookedSeats[i];

                                for (int k = 0; k < totalbuses; k++)
                                {
                                    if (routes_name[k] == bookedRoute[i])
                                    {
                                        fareList[routeCount] = fare[k];
                                        break;
                                    }
                                }
                                routeCount++;
                            }
                        }
                    }
                    if (!found)
                    {
                        cout << " No booking found with thi id " << endl;
                    }
                    else
                    {
                        cout << "==========================================" << endl;
                        cout << "              BUS TICKET                  " << endl;
                        cout << "==========================================" << endl;
                        cout << "ID: " << searchId << endl;
                        cout << "------------------------------------------" << endl;

                        for (int i = 0; i < routeCount; i++)
                        {
                            int total = seatList[i] * fareList[i];
                            grandTotal += total;

                            cout << "Route: " << routeList[i] << endl;
                            cout << "Seats: " << seatList[i] << endl;
                            cout << "Fare per seat: " << fareList[i] << endl;
                            cout << "Total for this route: " << total << endl;
                            cout << "------------------------------------------" << endl;
                        }

                        cout << "GRAND TOTAL: " << grandTotal << endl;
                        cout << "==========================================" << endl;
                    }

                    cout << "Press any key to continue...";
                    getch();
                }else if(option == 4 ){
                    cout<<" press backspace key to exit"<<endl;
                    getch();
                }else{
                    cout<<"invalid option!"<<endl;
                }
            }
        }

        // end of  passenger code//

        else if (user_option == 3)
        {
            break;
        }
        else
        {
            cout << " You entered the wrong option " << endl;
            getch();
        }
    }
    // end of main while loop//

    cout << " Thanks for using this software " << endl;
    return 0;
}
