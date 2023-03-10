/*
Student Author: Min Htut Myat
Student Number: 7058949

Assignment 1
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
#include "ITR.h"
using namespace std;

// read, process and store information required for assignment
inline vector<parts> readfile1(string partfile, vector<parts> list)
{
    string line;
    int count = 0;
    ifstream file1(partfile);

    // reading from file means everything will be in string
    // do conversions later
    string gpartcode;
    string gpartname;
    string gpartmin;
    string gpartmax;
    string gpartcomplexity;

    // error checking mechanism
    if(file1.eof())
    {
        cerr << " End of file reached " << endl;
        exit(-1);
    }
    else if(file1.fail())
    {
        cerr << " File contains invalid data" << endl;
        exit(-1);
    }
    else if(file1.bad())
    {
        cerr << " Read and write error in program logic " << endl;
        exit(-1);
    }

    // get number of lines in a file first
    while(getline(file1,line))
    {
        count++;
    }

    // set size of vector of parts
    list.resize(count);
    file1.close();

    int i = 0;
    file1.open(partfile);
    while(getline(file1,line) && i < count)
    {
        stringstream ss(line);

        // do datatype conversions here
        // all three files have the same delimiter :
        getline(ss,gpartcode,':');
        list[i].partcode = gpartcode;
        getline(ss,gpartname,':');
        list[i].partname = gpartname;
        getline(ss,gpartmin,':');
        list[i].partmin = stoi(gpartmin);
        getline(ss,gpartmax,':');
        list[i].partmax = stoi(gpartmax);
        getline(ss,gpartcomplexity,':');
        list[i].partcomplexity = stoi(gpartcomplexity);
         
        /* cout << gpartcode << endl; Debug statements (passed)
        cout << list[i].partcode << endl;
        cout << list[i].partname << endl;
        cout << list[i].partmin << endl;
        cout << list[i].partmax << endl;
        cout << list[i].partcomplexity << endl;
        cout << endl;
        */
       
        i++;
    }

    file1.close();
    
    return list;
}

inline vector<customer> readfile2(string partfile, vector<customer> list2)
{
    string line;
    ifstream file2(partfile);

    // reading from file means everything will be in string
    // do conversions later
    string gcustname;
    string gprojname;
    string gpartlist;

    if(file2.eof())
    {
        cerr << " End of file reached " << endl;
        exit(-1);
    }
    else if(file2.fail())
    {
        cerr << " File contains invalid data" << endl;
        exit(-1);
    }
    else if(file2.bad())
    {
        cerr << " Read and write error in program logic " << endl;
        exit(-1);
    }

    // get number of lines in a file first
    while(getline(file2,line))
    {
        ccount++;
    }

    // set size of vector of parts
    list2.resize(ccount);
    file2.close();

    int i = 0;
    file2.open(partfile);
    while(getline(file2,line,'.') && i < ccount) // remove last character of string (. in Customers.txt file)
    {
        stringstream ss(line);

        // do datatype conversions here
        getline(ss,gcustname,':');
        list2[i].custname = gcustname;
        getline(ss,gprojname,':');
        list2[i].projname = gprojname;
        getline(ss,gpartlist,':');
        list2[i].partlist = gpartlist; 
       
        i++;
    }

    file2.close();
    
    return list2;
}


inline vector<builder> readfile3(string partfile, vector<builder> list3)
{
    string line;
    int count = 0;
    ifstream file3(partfile);

    // reading from file means everything will be in string
    // do conversions later
    string gname;
    string gability;
    string gvariability;

    if(file3.eof())
    {
        cerr << " End of file reached " << endl;
        exit(-1);
    }
    else if(file3.fail())
    {
        cerr << " File contains invalid data" << endl;
        exit(-1);
    }
    else if(file3.bad())
    {
        cerr << " Read and write error in program logic " << endl;
        exit(-1);
    }

    // get number of lines in a file first
    while(getline(file3,line))
    {
        count++;
    }

    // set size of vector of parts
    list3.resize(count);
    file3.close();

    int i = 0;
    file3.open(partfile);
    while(getline(file3,line) && i < count)
    {
        stringstream ss(line);

        // do datatype conversions here
        getline(ss,gname,':');
        list3[i].name = gname;
        getline(ss,gability,':');
        list3[i].ability = stoi(gability);
        getline(ss,gvariability,':');
        list3[i].variability = stoi(gvariability);
       
        i++;
    }

    file3.close();
    
    return list3;
}

inline vector<customer> getprojpartlist(vector<customer> clist)
{

    for(int i = 0; i < ccount; i++)
    {
        // convert string type partcode from struct parts into type char and p
        // put them into customer member projpartlist of vector of chars
        copy(clist[i].partlist.begin(),clist[i].partlist.end(),back_inserter(clist[i].projpartlist));

        /* Debug statement (passed)
        for (const char &character : c.projpartlist)
        {
            cout << character << endl;
        }
        cout << endl;
        */
    }

    return clist;
}

inline void processorder(vector<customer> clist, vector<builder> blist)
{
    int b_rand = 0;

    ofstream outputfile("output.txt");

    // set seed for rand() function
    srand(time(0));
    for(customer c: clist)
    {
        
        cout << "Customer: " << c.custname << endl;
        cout << "Customer Project : " << c.projname << endl;

        outputfile << "Customer: " << c.custname << endl;
        outputfile << "Customer Project : " << c.projname << endl;

        // generate random value to randomly pick a builder for a customer
        b_rand = rand() % blist.size();
        // cout << b_rand << endl;

        // calculate overall robot complexity and overall 
        int projpartcount = 0;
        int orbtcomp = 22; 
        for(const char& character: c.projpartlist)
        {
            if(character == 'A')
            {
               orbtcomp += 15;
            }
            else if(character == 'B')
            {
               orbtcomp += 5;
            }
            else if(character == 'C')
            {
               orbtcomp += 6;
            }
            else if(character == 'D')
            {
               orbtcomp += 8;
            }
            else if(character == 'E')
            {
               orbtcomp += 2;
            }
            projpartcount++;
        }

        // If the complexity is greater than 100, it should be changed to exactly 100
        if(orbtcomp > 100)
        {
            orbtcomp = 100;
        }

        // cout << orbtcomp << endl;

        // calculate overall robot variability
        int orbtvari = 4;
        for (int i = 0; i < blist.size(); i++)
        {
            // if random value equals the index of the builder in vector of struct builder
            if(i == b_rand)
            {
               cout << "Chosen Builder: " << blist[i].name << endl;
               outputfile << "Builder Name: " << blist[i].name << endl;

               orbtvari += projpartcount + blist[i].variability;

               // keep chosen robots for current customer
               int crbtability = blist[i].ability;
               string chosenrobot = blist[i].name;

               // Builder starts to build robot, use normal distribution
               for(int i = 0; i < 3; i++) // Double check this logic
               {
                    unsigned seed = chrono::steady_clock::now().time_since_epoch().count(); 
                    default_random_engine e (seed);

                    outputfile << "Normal distribution parameters: Mean --> " << crbtability << " Standard Deviation--> " << orbtvari << endl;
                    // cout << chosenrobot << " " << crbtability << " " << orbtvari << endl;
                    normal_distribution<double> normaldist(crbtability,orbtvari); // distN(mean,standard deviation)

                    // select a random value generated by normal distribution 
                    int randselect = rand() % blist.size();
                    double randval;
                    for (int i = 1; i <= blist.size(); i++)
                    {
                        if(i == randselect)
                        {
                            randval = normaldist(e);
                            break;
                        }
                    }   

                    // Check success or failure, if failure try 2 more times
                    // Success move to next customer 
                    // Fail 3 times move to next customer
                    
                    // cout << randval << " " << orbtcomp << endl;
                    outputfile << " Builder random value: " << randval << setprecision(4) << " versus " <<  " Overall robot complexity: " << orbtcomp << setprecision(4) << endl;
                    if(randval >= orbtcomp)
                    {
                            cout << "Attempt " << i + 1 << " build successful" << endl; 
                            outputfile << "Attempt " << i + 1 << " build successful" << endl;
                            break;
                    }
                    else
                    {
						    randval += 5;
                            cout << "Attempt " << i + 1 << " build failed" << endl; 
                            outputfile << "Attempt " << i + 1 << " build failed" << endl;
                            if (i == 2)
                            {
								randval += 10;
                                cout << endl;
                                cout << "Build failed, moving to next customer" << endl;
                                outputfile << "Build failed, moving to next customer" << endl;
                            }
                            continue; 
                    }
                    // normaldist.reset(); // testing
                }
                // testing
            }
            continue;
        }

        cout << endl;
        outputfile << endl;
        // cout << orbtvari << endl;
        // cout << "reached here" << endl;
        
    }
    
}

