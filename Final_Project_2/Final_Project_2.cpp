#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <windows.h>

using namespace std;

struct student
{
    int studentNum = {};

    string name;
    string course;
    string year;
    string ratingMath;
    string ratingScience;
    string ratingProg;

    double gradeMath = {}; 
    double gradeScience = {};
    double gradeProg = {};
    double average = {};
    double gpa = {};

};

void getData(student* stud, int);
void displayAll(student* stud, int);
void rating(student* stud, int);
void assignGPA(student* stud, int);

int nums;

int main()
{
    string conts;
    int in,stdNum,dispChoice;
    student* stud = nullptr;

    do {
        system("cls");
        cout << "=========================" << endl;
        cout << setw(20) << "GRADE CALCULATOR" << endl;
        cout << "=========================" << endl;

        cout << "1. Add Student Info" << endl << "2. Display Student Info" << endl << "3. Exit" << endl << "Choice: ";
        cin >> in;
        cin.ignore();

        switch (in)
        {
        case 1:

            cout << "How many students? ";
            cin >> stdNum;
            cin.ignore();
            nums = stdNum + 1;
            stud = new student[nums];

            getData(stud, nums);
            rating(stud, nums);
            assignGPA(stud, nums);
            break;
        case 2:
            if (stud == nullptr)
            {
                cout << "No Records yet!" << endl;
                break;
            }
            else
            {
                int searchNum;
                cout << "1. Search by Student Number" << endl << "2. Display All" << endl << "Choice: ";
                cin >> dispChoice;
                cin.ignore();
                    
                if (dispChoice == 1) {
                    cout << "Enter student number: ";
                    cin >> searchNum;
                    cin.ignore();
                    for (int i = 0; i < nums; i++)
                    {
                        if (searchNum == stud[i].studentNum)
                        {
                            cout << fixed << setprecision(2) << "Name: " << stud[i].name << endl << "Student Number: " << stud[i].studentNum << endl
                                << "Course and Year: " << stud[i].course << " " << stud[i].year << endl
                                << "Math Grade: " << stud[i].gradeMath << " " << stud[i].ratingMath << endl
                                << "Science Grade: " << stud[i].gradeScience << " " << stud[i].ratingScience << endl
                                << "Programming Grade: " << stud[i].gradeProg << " " << stud[i].ratingProg << endl
                                << "GPA: " <<stud[i].gpa << endl << endl;
                        }
                    }
                }
                else if (dispChoice == 2) {
                    displayAll(stud, nums);
                }
                else 
                { 
                    cout << " INAVALID";
                }
            }
            break;
        case 3: 
            exit(1);
            break;
        default:
            cout << "INVALID!";

            break;
        }

        cout << "Do you want to continue? ";
        getline(cin, conts);
        transform(conts.begin(), conts.end(), conts.begin(), ::toupper);

    } while (conts == "YES" || conts == "Y");
}


void getData(student* stud, int nums) {
    for (int i = 0; i < nums; i++)
    {
        cout << "Enter name " << i + 1 << ": ";
        getline(cin, stud[i].name);
        
        cout << "Enter student number: ";
        cin >> stud[i].studentNum;
        cin.ignore();

        cout << "Enter your course: ";
        getline(cin, stud[i].course);

        cout << "Enter Your Year level: ";
        getline(cin, stud[i].year);

        cout << "Enter your grade in math: ";
        cin >> stud[i].gradeMath;
        cin.ignore();

        cout << "Enter your grade in Science: ";
        cin >> stud[i].gradeScience;
        cin.ignore();

        cout << "Enter your grade in Programming: ";
        cin >> stud[i].gradeProg;
        cin.ignore();
      
    }
}

void displayAll(student* stud, int nums)
{
    for(int i =0; i < nums; i++)
    {
        cout << fixed << setprecision(2)<< "Name: " << stud[i].name << endl << "Student Number: " << stud[i].studentNum << endl
            << "Course and Year: " << stud[i].course << " " << stud[i].year << endl
            << "Math Grade: " << stud[i].gradeMath << " " << stud[i].ratingMath << endl
            << "Science Grade: " << stud[i].gradeScience << " " << stud[i].ratingScience << endl
            << "Programming Grade: " << stud[i].gradeProg << " " << stud[i].ratingProg << endl
            << "GPA: " <<  stud[i].gpa<< endl <<endl;
    }
}

void rating(student* stud, int nums)
{
    for (int i = 0; i < nums; i++)
    {
        if (stud[i].gradeMath >= 70)
        {
            stud[i].ratingMath = "PASS";
        }
        else { stud[i].ratingMath = "FAIL"; }

        if (stud[i].gradeScience >= 70)
        {
            stud[i].ratingScience = "PASS";
        }
        else { stud[i].ratingScience = "FAIL"; }

        if (stud[i].gradeProg >= 70)
        {
            stud[i].ratingProg = "PASS";
        }
        else { stud[i].ratingProg = "FAIL"; }
    }
}

void assignGPA(student* stud,int nums)
{
    double gpa=0;
    for (int i = 0; i < nums; i++) {
       
        stud[i].average = (stud[i].gradeMath + stud[i].gradeScience + stud[i].gradeProg) / 3;
        
        if (stud[i].average >= 97 && stud[i].average <=100)
        {
            stud[i].gpa = 4.0;
        }
        else if (stud[i].average >= 93 && stud[i].average <= 96)
        {
            stud[i].gpa = 3.5;
        }
        else if (stud[i].average >= 89 && stud[i].average <= 92)
        {
            stud[i].gpa = 3.0;
        }
        else if (stud[i].average >= 85 && stud[i].average <= 88)
        {
            stud[i].gpa = 2.5;
        }
        else if (stud[i].average >= 80 && stud[i].average <= 84)
        {
            stud[i].gpa = 2.0;
        }
        else if (stud[i].average >= 75 && stud[i].average <= 79)
        {
            stud[i].gpa = 1.5;
        }
        else if(stud[i].average >= 70 && stud[i].average <= 74)
        {
            stud[i].gpa = 1.0;
        }
        else if (stud[i].average <=69)
        {
            stud[i].gpa = 0.5;
        }
    }


    
}


