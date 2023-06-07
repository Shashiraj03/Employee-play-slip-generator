#include <bits/stdc++.h>

using namespace std;

int id=100;

class Employee
{   
    public:

        string Name,Gender,Location,Department,Employee_Type,Band;
        long long int PF_Number,Acc_Number,CTC;
        int Employee_ID;

        string Door_Number,Street,Area,City;
        long long int pin;

        Employee(string Name,string Gender,string Location,string Department,string Employee_Type,string Band,long long int PF_Number,long long int Acc_Number,double CTC, int EmployeeID,string Door_Number,string Street, string Area, string City,long long int pin)
        {
            this->Name=Name;
            this->Gender=Gender;
            this->Location=Location;
            this->Department=Department;
            this->Employee_Type=Employee_Type;
            this->Band=Band;
            this->PF_Number=PF_Number;
            this->Acc_Number=Acc_Number;
            this->CTC=CTC;
            this->Door_Number=Door_Number;
            this->Street=Street;
            this->Area=Area;
            this->City=City;
            this->pin=pin;
            Employee_ID=id++;
        }
};

vector<Employee> e1=
{
    {Employee("shashi","Male","Smg","Admin","Full_Time","GT",26517281,1234567890123,2500000,0,"s101","barroad","Holebelagelu","smg",577227)},
    {Employee("shashi","Male","Smg","Admin","Full_Time","GT",26517281,1234567890123,100000,0,"s101","barroad","Holebelagelu","smg",577227)}
};
// int main()
// {
//     Salary_slip s;

//     for(int i=0;i<e1.size();i++)
//     {
//         cout<<e1[i].Name<<" "<<e1[i].Gender<<" "<<e1[i].Employee_ID;
//         cout<<e1[i].Door_Number<<" "<<e1[i].Street<<" "<<e1[i].Area;
//         cout<<e1[i].City<<" "<<e1[i].pin;
//     }

//     return 0;
// }