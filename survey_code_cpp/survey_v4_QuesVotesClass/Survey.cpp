//#include <string>
//#include <array>
//#include <iostream> // cout
//#include <fstream> // fstream
//#include <iomanip> // setw()
//#include "Survey.h"
//#include "Question.h"
//using namespace std;
//
//
////*********************************************************
////              Default Constructor
////*********************************************************
//Question::Question(){
//    
//    cout<<"\n Hit Question Default Constructor\n";
//
//    size = 4;
//    qusAns = new string[size];
//    votes = new int[size];
//     
//    // Read 1 question and answers from file    
//    fstream in;
//    in.open("surveyQA.txt", ios::in);
//    if(in.fail()){ cout<<"\nError opening survey.txt\n"; exit(0); }
//        
//    for(int j=0; j < size; j++){            
//        getline(in, qusAns[j]);
//        votes[j] = 0;
//        cout<<votes[j]<< " ";
//        cout<<qusAns[j]<<endl;
//    }
//  
//    in.close();
//}
//
//
////*********************************************************
////                   Constructor #2
////*********************************************************
//Question::Question(string q, string a, string b, string c){ 
//    
//    //cout<<"\n Hit Question Constructor #2\n";
//
//    size = 4;
//    
//    qusAns = new string[size];     
//    votes = new int[size];
//    
//    qusAns[0] = q;
//    qusAns[1] = a;
//    qusAns[2] = b;
//    qusAns[3] = c;    
//    
//    for(int j=0; j < size; j++){ 
//        votes[j] = 0;
//    }
//}
//
//
////*********************************************************
////              Destructor
////*********************************************************
//Question::~Question(){
//    delete [] qusAns;
//    delete [] votes;
//}
//
//
////*********************************************************
////
////*********************************************************
//
//void Question::setQA(string q, string a, string b, string c){
//    
//    
//}
//
//
////*********************************************************
////
////*********************************************************
//void Question::getSurvey(){
//    
//    unsigned short count1, count2, count3, ansSum, ans, count;
//    count1 = count2 = count3 = ansSum = ans = count = 0;
//          
//        do {
//            cout<<endl
//                << qusAns[0] << "\n"
//                << "1: " << qusAns[1] << "\n"
//                << "2: " << qusAns[2] << "\n"
//                << "3: " << qusAns[3] << "\n"
//                <<"Enter a number:  ";
//            cin >> ans;
//            
//            if(!( ans >= 1 && ans <= 3 )) { cout<<"Invalid input. Try again...\n"; }
//            
//        } while (!( ans >= 1 && ans <= 3 ));
//
//
//        switch(ans){
//            case 1: 
//            { 
//                votes[0] +=1; //count1++; 
//                votes[3] +=1; //ansSum++;
//                break; 
//            }
//            case 2: 
//            { 
//                votes[1]+=1; //count2++; 
//                votes[3]+=1; //ansSum++;
//                break; 
//            }
//            case 3: 
//            { 
//                votes[2]+=1; //count3++; 
//                votes[3]+=1; //ansSum++; 
//                break; 
//            }
//            default:  { cout << "Invalid answer.\n"; }
//        }
//        
// 
//       // Reassign array with the voting results for this question
//////        for(int i=0; i < size; i++){    
//
//////            if(i==0){ votes[i] = count1; }//5;}//for testing purposes
//
//////            else if(i==1){ votes[i] = count2; }//3;}// 
//
//////            else if(i==2){ votes[i] = count3; }//1;} //
//
//////            else { votes[3] = ansSum; }//9;} //
//////        }   
//}
//
//
////*********************************************************
////
////*********************************************************
////void prntChart(Question &q){
//void Question::prntChart(){    
//  
//    static int count = 1;
//    
//    cout << "\n\tQuestion " << count  << " results\n";
//    cout << qusAns[0] << endl << endl;
//    
//    for(int i = 0; i < 4; i++){
//        
//        if(i==3){ cout<<setw(17)<<"Total "<<setw(4)<<votes[i]<<" votes  "; }
//        
//        else { cout<<setw(16)<<qusAns[i+1]<<"  "<<setw(3)<<votes[i]<<" votes  "; } 
//        
//        for(int j = 0; j < votes[i]; j++){
//            cout<<"*";  
//        }      
//        cout<<endl;
//    }
//    
//    count++;
//}
//
//
////*********************************************************
////
////*********************************************************
