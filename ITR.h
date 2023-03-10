/*
Student Author: Min Htut Myat
Student Number: 7058949

Assignment 1
*/
#include <vector>
#include <string>
#ifndef ITR_h_INCLUDED
#define ITR_h_INCLUDED
using namespace std;

// variables, structs and containers to be used in the program
struct parts
{
    string partcode;
    string partname;
    int partmin;
    int partmax;
    int partcomplexity;
};

struct customer
{
    string custname;
    string projname;
    string partlist;
    vector<char> projpartlist;
};

struct builder
{
    string name;
    int ability;
    int variability;
};

inline int ccount = 0;
inline vector<parts> partslist;
inline vector<customer> cust_list;
inline vector<builder> builder_list;

// function prototypes
inline vector<parts> readfile1(string partfile, vector<parts> list);
inline vector<customer> readfile2(string partfile, vector<customer> list2);
inline vector<builder> readfile3(string partfile, vector<builder> list3);
inline vector<customer> getprojpartlist(vector<customer> clist);
inline void processorder(vector<customer> clist, vector<builder> blist);

#endif 