/* 
 * File:    main.cpp
 * Author:  Danielle F
 * Created: 04-13-23 @5PM
 * Purpose:  survey project v2
 * 
 * v1:
 * Admin inherits User
 * Added admin readBin(), wrtAdminTxt() & wrtAdminBin()
 * Fixed bug: Admin is crashing. Added a cout inside ~Admin().
 * Added 3 constructors for User. 
 * Added recSize & begnFile variables to Admin so it could  
 * hold their info when handling a binary record.
 * Admin can rewrite the value for hiScore in userData.dat when 
 * it uses findByEmail() to set records size & beginning file location.
 * Admin can rewrite one full binary record instead of just hiScoore.
 * Copied this folder to yahtzee_v15
 * Added getMenu() so I can focus on my survey.
 *  Rewrites 1 record in usrdata.txt after it rewrites binary.
 * 
 * 
 v2:
 * I copied my Admin & User classes from yahtzee_v21 to here.
 * Created string array with 1 question and 3 possible answers.
 * Created a loop to mimic 5 people answering this 1 question
 * Created counters for each question's possible answer and
   reassigned int qAns[] with the the counters some answered the question.
 * Passed the questions and answers arrays to a print function.
 * Created prntChart() that displays the voting results as well as a histogram 
   with stars to represent each vote.
 * 
 * 
 To Do: 
 
 * Make getAllUsr() print outside of its function
  
 * Destroy double ptr in Yahtzee class & in Admin class?
 
 * Make readInput() read inputs from file again
 
 * Add a bool variable to Admin as a flag for deleted records?
 
 * DRY. Clean up repetitive code.
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <iomanip> // setw()
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype> // toupper()
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "User.h"
#include "Admin.h"
#include "Question.h"

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void getMenu();
void prntChart(string [], int []);


//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));
    //rand()%90+10;//2 digit numbers
    
    //getMenu();

    unsigned short count1, count2, count3, ansSum, ans, count;
    count1 = count2 = count3 = ansSum = ans = count = 0;
    
    unsigned short size = 4;
    string qStr[] = {"Which series do you like the most?", "Star Wars", "Harry Potter", "The Simpsons"};
    
     
    // Create array to hold question 1's how many votes each option
    // received & total sum of all votes for this question
    int qAns[size];    
    
    // Initialize array 
    for(int i=0; i < size; i++){    
        qAns[i] = 0;
    }
    
    // Mimic 5 different people answering this question
    while(count < 3){
        
        cout<<"\nCount: " << count << endl;
        
        do {
            cout<<endl
                << qStr[0] << "\n"
                << "1: " << qStr[1] << "\n"
                << "2: " << qStr[2] << "\n"
                << "3: " << qStr[3] << "\n";
            cin >> ans;
            
            if(!( ans >= 1 && ans <= 3 )) { cout<<"Invalid input. Try again...\n"; }
            
        } while (!( ans >= 1 && ans <= 3 ));

        cout<<"Answer: " << ans << endl;

        switch(ans){
            case 1: 
            { 
                qAns[0] +=1; //count1++; 
                qAns[3] +=1; //ansSum++;
                break; 
            }
            case 2: 
            { 
                qAns[1]+=1; //count2++; 
                qAns[3]+=1; //ansSum++;
                break; 
            }
            case 3: 
            { 
                qAns[2]+=1; //count3++; 
                qAns[3]+=1; //ansSum++; 
                break; 
            }
            default:  { cout << "Invalid answer.\n"; }
        }
        
 
//        // Reassign array with the voting results for this question
//        for(int i=0; i < size; i++){    
//
//            if(i==0){ qAns[i] = count1; }//5;}//for testing purposes
//
//            else if(i==1){ qAns[i] = count2; }//3;}// 
//
//            else if(i==2){ qAns[i] = count3; }//1;} //
//
//            else { qAns[3] = ansSum; }//9;} //
//        } 
   
        count++;        
    }
    cout<<endl<<endl;
    
    prntChart(qStr,qAns);    
     
    return 0;
}

/**********  Function Definitions  **************/
void prntChart(string qqStr[], int quesAns[]){    
  
    int indx = 1;
    
    cout << "\n\tQuestion " << indx  << " results\n";
    cout << qqStr[0] << endl << endl;
    
    for(int i = 0; i < 4; i++){
        
        if(i==3){ cout <<setw(13)<< "Total " << setw(4) << quesAns[i] << " votes  "; }
        
        else {
            cout <<setw(12)<< qqStr[i+1] << "  " << setw(3) << quesAns[i] << " votes  ";
        } 
        
        for(int j = 0; j < quesAns[i]; j++){
            cout<<"*";  
        }      
        cout<<endl;
    }
}

void getMenu(){
    
    int choice = 0;
    
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: Take Survey as a guest\n"
        <<"5: ReadInputFile()\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            case 1: // Admin login
            {
                Admin admin;
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
                User user1;
                user1.signUp();                 
                //user1.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                Admin admin1;
                if(admin1.isUsrLogin()){
                    
                    cout<<"\n\nUser login was successful.\n"; 
                    //cout<<"\n inside main()";
                    //admin.printAdUsr();                    
                    
                    
                    // Create new User & copy admin values to user
                    User user2;
                    admin1.copy2Usr(user2);    
                    cout << "\nWelcome " << user2.getName();
                    user2.printUsr(); 
                    
                                                                     
                }
                break;
            }             
            case 4: // Play Yahtzee as a guest
            {          
                User guest("Guest");    
               
                break;
            }
            case 5: // Read inputs to fill User binary with records
            {
                User user5;
                user5.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }
}