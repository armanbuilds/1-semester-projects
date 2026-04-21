#include<iostream>
#include<conio.h>
#include<string>
using namespace std;

main(){
 
     // data structures for buses//
     int bookingCount =0;  // total booking
     int totalbuses = 5;

    string routes_name[100] = {"muree", "lahore", "karachi", "faisalabad", "multan"};   // routes of bus //
    int fare[100] = {1000, 1500, 3000, 2500, 2000};         // fare of buse//
    int seats[100] = {30, 30, 30, 30, 30};

    // booking system data//

    string names[100];    // store names//
    int ids[100];        // store ids //
    string bookedRoute[100];  //store route//
    int bookedSeats[100];     // store booked seats//

      while(true){

       // INTRO HEADER//

        system("cls");
        cout << "-------------------------------------------------------------" << endl;
        cout << "------------------BUSES MANAGEMENT SYSTEM--------------------" << endl;
        cout << "-------------------------------------------------------------" << endl;
        
        // MAIN HEADER//

        cout << " **********************USER MENU******************** " << endl;
        cout << "1. Admin menu" << endl;
        cout << "2. Passenger menu " << endl;
        cout << "3. Exit " << endl;
        cout << "Choose any option ";

        int user_option;
        cin>>user_option;
        cout<<" You choose "<<user_option<<endl;
        
    if(user_option == 1){

         //ADMIN CODE//

         system("cls");
         string admin_pasword ="admin1234";
         string input_pasword;

         cout<<" ENTER THE ADMIN PASWORD : ";
         cin>>input_pasword;

         if(input_pasword == admin_pasword)   // for successful login//
         {
            cout<<" succesfully logged in "<<endl;

            cout<<"press any key to continue ";
            getch();

            int choice =0;

            while(choice != 5)    // 2nd while loop//
            {
                system("cls");
                    cout << " =======ADMN MENU=======" << endl;
                    cout << "1. View bookings" << endl;
                    cout << "2. Search booking by id" << endl;
                    cout << "3. Add Bus" << endl;
                    cout << "4. Edit buses" << endl;
                    cout << "5. Exit" << endl;
                    cout << "Enter your choice ";
                    cin >> choice;

                  if(choice == 1)  // view booking//
                {

                    system("cls");
                    if(bookingCount == 0)
                    {
                          cout << "No bookings yet" << endl;
                          cout << "Press B to go back";
                    }
                    else{
                        cout << "BOOKING NO\tNAME\t\tID\tROUTE\t\tSEATS" << endl;
                          cout << "--------------------------------------------------------" << endl;

                          for(int x =0; x < bookingCount ; x++)
                          {
                             cout << x + 1 << "\t\t" << names[x] << "\t\t" << ids[x] << "\t" << bookedRoute[x] << "\t\t" << bookedSeats[x] << endl;
                          }
                    }
                    getch();
                }
                else if(choice ==2)  // serach booking//
                {
                    system("cls");

                    int searchId;
                    cout<<"Enter ID to serach : ";
                    cin>>searchId;

                    int found= 0;
                    for(int x =0;x < bookingCount ; x++ )
                    {
                        if(ids[x] == searchId)
                        {
                           cout << "Booking Found: " << endl;
                           cout << "Name: " << names[x] << endl;
                           cout << "ID: " << ids[x] << endl;
                           cout << "Route: " << bookedRoute[x] << endl;
                           cout << "Seats: " << bookedSeats[x] << endl;

                           found = 1;
                           break;
                        }
                    }
                     
                    if(found == 0){
                        cout<<" No booking found with this id "<<endl;
                        cout<<" press enter key to go back...";
                    }
                    getch();
                }
                else if( choice == 3)    //add bus//
                {
                     system("cls");
                     if(totalbuses < 100)
                     {
                        cout<<" Enter Route : ";
                        cin>>routes_name[totalbuses];

                        cout<<" enter the fare for your route : ";
                        cin>>fare[totalbuses];

                        cout<<" Enter seats : ";
                        cin>>seats[totalbuses];

                        totalbuses++;

                        cout <<"Bus added successfully!" << endl;
                        cout<<"press any key to continue"<<endl;
                     }
                     else{
                        cout<<" Maximum limit reached "<<endl;
                     }
                     getch();
                }
                else if(choice == 4)  // edit bus //
                {

                    system("cls");
                     string searchRoute;
                     cout << "Enter the route you want to edit: ";
                     cin >> searchRoute;

                        int index = -1;

                        // SEARCH ROUTE//

                         for (int i = 0; i < totalbuses; i++)
                        {
                            if (routes_name[i] == searchRoute)
                            {
                                index = i;
                                break;
                            }
                        }

                        // IF NOT FOUND//   

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
                            cout<<"4. exit"<<endl;
                            cout << "Enter choice: ";

                            int editChoice;
                            cin>>editChoice;

                            // UPDATE SEATS//

                            if (editChoice == 1)
                            {
                                cout << "Enter new seats: ";
                                cin >> seats[index];

                                cout << "Seats updated successfully!" << endl;
                            }

                            //UPDATE FARE//

                        else if (editChoice == 2)
                        {
                            cout<<"Enter new fare";
                            cin>>fare[index];

                            cout<<" Fare updated successfully !"<<endl;
                        }

                        // DELETE ROUTE//
                        
                        else if(editChoice == 3)
                        {
                             for (int i = index; i < totalbuses - 1; i++){
                             routes_name[i] = routes_name[i + 1];
                             fare[i] = fare[i + 1];
                             seats[i] = seats[i + 1];
                        }

                        totalbuses--;
                        cout<<"Route deleted successfully!"<<endl;
                    } 
                    else if (editChoice == 4)
                    {
                        break;
                    }
                    
                 }
                getch();

             }      // end of 2nd while loop//
         }
      }
      else{
               cout << "Wrong pasword !. please enter the correct pasword" << endl;
                cout << " To login again click continue  " << endl;
      }
      getch();
    }
    else if(user_option == 2)    //passenger menu //
{
  // passenger code//
  system("cls");
  cout << "=======PASSENGER MENU=========" << endl;

  // ROUTES AVAILABLE//

        cout << "\t" << " Availabe routes" << "\t" << endl;
        for (int i = 0; i < totalbuses; i++)
        {
            cout << routes_name[i] << endl;
        }

        cout << "To check fares click on  1  " << endl; // to check fare//
        cout << "To book tickets click 2 " << endl;     // to book tickets//
        cout<< " To print ticket click on 3"<<endl;     // for printing ticket
        cout << " choose your option : ";

         int option;
         cin>>option;

          if (option == 1)
        {
            // ================= FARE CHECK =================

            system("cls");

            cout << "City\t\t\tFare" << endl;
            for (int i = 0; i < totalbuses; i++)
            {
                cout << routes_name[i] << "\t\t\t" << fare[i] << endl;
            }
            cout << " press any key to go to the menu " << endl;
            getch();
        }
        else if (option == 2)
        {                                   // ================= BOOKING =================
            system("cls");
            cout << "---------------BOOKING------------------" << endl;
            cout << " These are the available buses " << endl;
            
            for(int i =0; i<totalbuses; i++){
                cout<<i+1<<"\t"<<routes_name[i]<<endl;
            }

            cout << "Check the routes available for your route and press any kess to further process" << endl;
            getch();

              system("cls");


            string city;
            cout << "Enter route: ";
            cin >> city;

            int index = -1;

            for (int i = 0; i < totalbuses; i++){
            
                      if (city == routes_name[i])
                      {
                         index = i;
                         break;
                      }

                       int tickets;
                cout << "Enter tickets: ";
                cin >> tickets;

                if (tickets <= seats[index])
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
                cout << "Not enough seats!"<<endl;
                cout<<"please book on the next day! "<<endl;
                cout<<"press enter key to go back";
            }
             getch();
              }
            }

             // TICKET PRINTING//
              else if(option == 3){

            system("cls");
            int searchId;
            cout<<" Enter your id to print ticket : ";
            cin>>searchId;

            int found = -1;
             for (int i= 0; i<bookingCount; i++){
                if(ids[i] == searchId){
                    found = i;
                    break;
                }
             }
              if(found==-1){
                cout<<" No booking found with thi id "<<endl;
             } 
             else{
                cout<<"======================================"<<endl;
                cout<<"              BUS TICKET              "<<endl;
                cout<<"NAME : "<<names[found]<<endl;
                cout<<"ID : "<<ids[found]<<endl;
                cout<<"ROUTE : "<<bookedRoute[found]<<endl;
                cout<<"SEATS : "<<bookedSeats[found]<<endl;

                 cout<<" press any key to exit ";
             }
             getch();
            }
        }
        
        //END OF PASSENGER CODE//
         else if (user_option == 3)
        {
            break;
        }
        else
        {
            cout << " You entered the wrong option " << endl;
            getch();
        }    // end of main while loop// 

  cout<<" Thanks for using this software "<<endl;

}  }