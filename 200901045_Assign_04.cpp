/*
^^^ FARAZ AHMAD QURESHI ^^^
=== Regno. 200901045 ===
||| Section B - BSCS 01 |||

,----------------------------------------------------,
| [][][][][]  [][][][][]  [][][][]  [][__]  [][][][] |
|                                                    |
|  [][][][][][][][][][][][][][_]    [][][]  [][][][] |
|  [_][][][][][][][][][][][][][ |   [][][]  [][][][] |
| [][_][][][][][][][][][][][][]||     []    [][][][] |
| [__][][][][][][][][][][][][__]    [][][]  [][][]|| |
|   [__][________________][__]              [__][]|| |
`----------------------------------------------------'
*/
#include <iostream>
#include <thread>
#include <string>
using namespace std;
void enterInput(string&);
void reverseInput(string&);
void capitalInput(string);
void shiftInput(string&);

int main(){
    string userString;
    
    //create 4 threads other than main thread.
    thread threadInput(enterInput,ref(userString)); //passing string as reference to input thread
    threadInput.join(); //once input thread is done then we pass string to other threads (and avoid race conditions)
    thread threadReverse(reverseInput,ref(userString)); 
    threadReverse.join();
    thread threadCapital(capitalInput,userString);
    threadCapital.join();
    thread threadShift(shiftInput,ref(userString));
    threadShift.join();
}
void shiftInput(string& str){
    string newString;
    cout << "Shifted String by 2:\t";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')  newString[i] = ' ';
        else    newString[i] = ((unsigned char)str[i])+2;
         cout << newString[i];
            }
}

void capitalInput(string s){
    cout << "Capitalize string:\t";
    for (auto & c: s) c = (char)toupper(c);
    cout  << s << endl;
}

void reverseInput(string& s){
    string reversed(s.rbegin(),s.rend());
    cout << "Reversed string is:\t" << reversed<< "\n" ;
}

void enterInput(string &s)
{
    //we need to take string user input
    cout << "\n>Please enter a sentence:\n";
    getline(cin,s);
}
