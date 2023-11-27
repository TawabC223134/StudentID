#include<iostream>
#include<fstream>
#include<bits/stdc++.h>
using namespace std;

int ID;
struct Student{
    int id,semester;
    string name,department;

};
void insertStudentData()
{
    Student student;
    cout << "Enter Student Name : " ;
    cin.get();
    getline(cin,student.name);
    cout << endl;
    cout << "Enter Student Department : ";
    cin >> student.department;
    cout << endl;
    cout << "Enter Student Semester : ";
    cin >> student.semester;
    cout << endl;
    ID++;

    ofstream write;
    write.open("student.txt",ios::app);
    write << ID << endl;
    write << student.name << endl;
    write << student.department << endl;
    write << student.semester << endl;
    write.close();
    write.open("id.txt");
    write << ID;
    write.close();
    cout << "Data Saved" << endl << endl;


}

void print(Student s)
{
    cout << "Student Data - " << endl;
    cout << "ID : " << s.id << endl;
    cout << "Name : " << s.name << endl;;
    cout << "Department : " << s.department << endl;;
    cout << "Semester : " << s.semester << endl << endl;;

}

void displayStudentData()
{
    Student student;
    ifstream read;
    read.open("student.txt");
    while(!read.eof())
    {
     print(student);
     read >> student.id;
     read.ignore();
     getline(read,student.name);
     read >> student.department;
     read >> student.semester;

    }

    read.close();
}

int searchStudentData()
{
   int id;
   cout << "Enter Student ID : " ;
   cin >> id;
   cout << endl;
    Student student;
    ifstream read;
    read.open("student.txt");
          read >> student.id;
     read.ignore();
     getline(read,student.name);
     read >> student.department;
     read >> student.semester;

     while(!read.eof())
     {
         if(student.id==id)
         {
             print(student);
             return id;

         }
         read >> student.id;
     read.ignore();
     getline(read,student.name);
     read >> student.department;
     read >> student.semester;
     }
}

void deleteStudentData()
{
    int id = searchStudentData();
    cout << "Delete this Student's information ?" << endl;
    cout << "1.Yes" << endl;
    cout << "2.No" << endl;
    cout << "Enter your option : ";
    int option;
    cin >> option;
    if(option == 1)
    {
        Student student;
       ofstream temp;
       temp.open("temp.txt");
       ifstream read;
       read.open("student.txt");
       read >> student.id;
       read.ignore();
     getline(read,student.name);
     read >> student.department;
     read >> student.semester;

     while(!read.eof())
     {
         if(student.id!=id)
         {

            temp << student.id << endl;
            temp << student.name << endl;
            temp << student.department << endl;
            temp << student.semester << endl;


         }
              read >> student.id;
     read.ignore();
     getline(read,student.name);
     read >> student.department;
     read >> student.semester;
    }
    read.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt","student.txt");
    cout << "Tnformation Deleted!!!" << endl;
    }
    else
    {
        cout << "Information not deleted." << endl;
    }

}
void exitStudentData()
{
    cout << "Do you want to exit ?" << endl;
    cout << "1.Yes " << endl;
    cout << "2.No " << endl;
    cout << "Choose Option : ";
    int option;
    cin >> option;
    if(option == 1)
    {
        exit(0);
    }
    else
    {
       cout << "Not exited!" << endl;
    }
}
int main()
{
       ifstream read;
    read.open("id.txt");
    if(!read.fail())
    {
        read >> ID;
    }
    else
    {
        ID=0;
    }
    read.close();

    while(true)
    {

        cout << "1.Add Student Data." << endl;
        cout << "2.Read Student Data." << endl;
        cout << "3.Search Student Data." << endl;
        cout << "4.Delete Student Data." << endl;
        cout << "5.Exit" << endl;
        cout << "Choose Option: ";
        int option;
        cin >> option;
        switch(option)
        {
        case 1:
            insertStudentData();
            break;
        case 2:
            displayStudentData();
            break;
        case 3:
            searchStudentData();
            break;
        case 4:
            deleteStudentData();
            break;
        case 5:
            exitStudentData();
            break;
        }
    }

}
