#include <iostream>
#include <fstream>
#include <string>
#include "NameList.h"

using namespace std;

int main(int argc, char* argv[]){
    nameList NL;

    ifstream file;
    file.open(argv[1]);
    if(!file.is_open()){
        cout << "Error opening file" << endl;
    }
    string word;
    while(file >> word){
        NL.insertName(word);
    }
    file.close();
    // NL.bubbleSort();
    bool sorted = false;
    bool quit = false;
    while(!quit){
        cout << "======Main Menu======" << endl;
        cout << "1. Print List" << endl;
        cout << "2. Print x most common names" << endl;
        cout << "3. Print x least common names" << endl;
        cout << "4. Print number of times name is found" << endl;
        cout << "5. Insert name" << endl;
        cout << "6. Delete name" << endl;
        cout << "7. Print all names that occur a certain number of times" << endl;
        cout << "8. Sort List (Bubble or Merge)" << endl;
        cout << "9. Quit" << endl;

        string response;
        getline(cin, response);
        if(response == "1"){
            NL.printList(NL.headReturner());
        }
        else if(response == "2"){
            cout << "How many names to print?" << endl;
            getline(cin, response);
            NL.printTopNames(stoi(response));
        }
        else if(response == "3"){
            cout << "How many names to print?" << endl;
            getline(cin, response);
            NL.printBottomNames(stoi(response));
        }
        else if(response == "4"){
            cout << "Name?" << endl;
            getline(cin, response);
            NL.nameOccurrence(response);
        }
        else if(response == "5"){
            cout << "What is the name to be inserted." << endl;
            getline(cin, response);
            NL.insertName(response);
            sorted = false;
        }
        else if(response == "6"){
            cout << "Name to be deleted?" << endl;
            getline(cin, response);
            NL.deleteName(response);
        }
        else if(response == "7"){
            cout << "What occurance do you wish to check?" << endl;
            getline(cin, response);
            NL.nameOccurrence(response);
        }
        else if(response == "8"){
            cout << "Do you wish to sort using bubble (1) or merge (2)?" << endl;
            getline(cin, response);
            if(response == "1")
            {
                NL.bubbleSort();
                sorted = true;
            }
            else if(response == "2")
            {
               Name* sortedList = NL.mergeSort(NL.headReturner());            
               NL.setHead(sortedList);
               sorted = true;
            }
            else
            {
                cout << "Incorrect command." << endl;
            }

            NL.printList(NL.headReturner());
        }
        else if(response == "9")
        {
            quit = true;
        }
    }
    cout << "Goodbye!" << endl;
}