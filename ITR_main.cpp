/*
Student Author: Min Htut Myat
Student Number: 7058949

Assignment 1
*/
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "ITR.cpp"
using namespace std;

int main(int argc, char *argv[])
{

    // string is an object of class string
    // get arguments from run command of assignment
    string file1(argv[1]);

    string file2(argv[2]);

    string file3(argv[3]);

    partslist = readfile1(file1,partslist);
    cust_list = readfile2(file2,cust_list);
    builder_list = readfile3(file3,builder_list);
    
    cust_list = getprojpartlist(cust_list);
        
    
    // format the output
    cout << endl;
    cout << endl;

    cout << "===============================================" << endl;
    cout << "====== WELCOME TO ILLAWARRA TOY ROBOTICS ======" << endl;
    cout << "================================= ~ Gh0u1Ss ===" << endl;
    cout << endl;
    cout << endl;
    
    cout << "Parts list: " << endl;
    cout << "PartCode   | " << " Name     | " << "Min  | " << "Max  | " << "Complexity" << endl;
    for (parts p: partslist)
    {
        cout << p.partcode << setw(17) << p.partname << setw(9) << p.partmin << setw(6) << p.partmax  << setw(9) << p.partcomplexity << endl;
    }

    cout << endl;

    cout << "Customer list: " << endl;
    cout << "Customer Name         | " << "Project Name        | " << "Part List  " << endl;
    for (customer c: cust_list)
    {
        cout << c.custname << setw(27) << c.projname << setw(22) << c.partlist;
    }

    cout << endl;
    cout << endl;
    
    
    cout << "Builder list: " << endl;
    cout << "Builder Name         | " << "Builder Ability  | " << "Builder Variability  " << endl;
    for (builder b: builder_list)
    {
        cout << b.name << setw(17) << b.ability << setw(17) << b.variability << endl;
    }

    /* Debug statement: check each instance of struct inside vector of struct (passed)
    for (customer c: cust_list)
    {
        for (const char &character : c.projpartlist)
        {
            cout << character << endl;
        }
        cout << endl;
    }
    */

    cout << endl;
    cout << endl;
    cout << "===== Processing Order =====";
    cout << endl;
    cout << endl;

    processorder(cust_list,builder_list);
    
    return 0;
}