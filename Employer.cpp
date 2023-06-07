#include <bits/stdc++.h>

#include "Employee.h"

using namespace std;

class Employer
{
    public:
        string cname;
        string clocation;
        string cbands[10];
        string cdept[10];
        
        void company_Details()
        {
            cout<<"Enter Comapany Name\n";
            getline(cin,cname);
            cout<<"Eneter Company Location\n";
            getline(cin,clocation);
            cout<<"How many Bands you want to enter\n";
            int n;
            cin>>n;
            cout<<"Enter Bands Names\n";
            for(int i=0;i<n;i++)
            {
                cin>>cbands[i];
            }
            cout<<"How many Departements you want to enetr\n";
            int x;
            cin>>x;
            cout<<"Enter Department Names\n";
            getline(cin,cdept[0]);
            for(int i=0;i<x;i++)
            {
                getline(cin,cdept[i]);
            }
        }

        void main_manu();
        void Add_employee();
        void Modify_employee(int);
        void Remove_employee(int);
        void Search_employee(int);
        void Print_all_employee();
        void Generate_Play_Slip(int,string,int);

        int incom_tax(double ctc)  
        {
            if(ctc>=500000 && ctc<=1000000)
            {
                return(0.05*ctc);
            }
            if(ctc>=1010000 && ctc<=1500000)
            {
                return(0.1*ctc);
            }
            if(ctc>=1510000 && ctc<2000000)
            {
                return(0.15*ctc);
            }
            if(ctc>=2010000)
            {
                return(0.2*ctc);
            }
            return 0;
        } 
        
};

void Employer :: main_manu()
{
    int choice;
   
    sta:cout<<endl;
    cout<<" 1. Add Employee\n 2. Modify Employee\n 3. Remove Employee\n 4. Search Employee\n 5. Print All Employees\n 6. Generate Play Slip\n 7.Exit\n";
    cout<<"\n\n Enter Your Choice\n";
    cin>>choice;
    int emp_id,mess;
    string m;
    switch(choice)
    {
        case 1:
                Add_employee();
                break;
        case 2:
                cout<<"Eneter Employee Id, which employee details you want to Modify\n";
                cin>>emp_id;
                Modify_employee(emp_id);
                break;
        case 3:
                cout<<"Eneter Employee Id, which employee you want to Remove \n";
                cin>>emp_id;
                Remove_employee(emp_id);
                break;
        case 4:
                cout<<"Eneter Employee Id, which employee you want to Remove \n";
                cin>>emp_id;
                Search_employee(emp_id);
                break;
        case 5:
                Print_all_employee();
                break;
        case 6:
                cout<<"Enter Pay Month MM-YYYY\n";
                cin>>m;
                cout<<"Enter Employee ID to Generate Play Slip\n";
                cin>>emp_id;
                cout<<"Enter Mess Bill\n";
                cin>>mess;
                Generate_Play_Slip(emp_id,m,mess);
                break;
        case 7: exit(0);
        default:
                cout<<"Envaild Choice\n";
                cout<<"Try Again\n";
                goto sta;
    }
}

void Employer :: Add_employee()
{
    string Name,Gender,Location,Department,Employee_Type,Band;
    long long int PF_Number,Acc_Number,CTC;
    int EmployeeID=0;

    string Door_Number,Street,Area,City;
    long long int pin;

    cout<<"Enter Employee Name\n";
    cin>>Name;
    cout<<"Enter Employee Gender\n";
    cin>>Gender;
    cout<<"Enter Employee Base Location\n";
    cin>>Location;
    cout<<"Enter Employee Department Name\n";
    cin>>Department;
    cout<<"Enter Employee Type(Permanent,Part_Time,Contract)\n";
    cin>>Employee_Type;
    cout<<"Enter Employee Band\n";
    cin>>Band;
    cout<<"Enter Employee PF Number\n";
    cin>>PF_Number;
    cout<<"Enter Employee Accounter Number\n";
    cin>>Acc_Number;
    cout<<"Enter Employee CTC\n";
    cin>>CTC;

    cout<<"\t\t\t Employee Address\n";
    cout<<"Door Number----->\t";
    cin>>Door_Number;
    cout<<"Street--------->\t";
    cin>>Street;
    cout<<"Area----------->\t";
    cin>>Area;
    cout<<"City------------->\t";
    cin>>City;
    cout<<"Pin Code---------->\t";
    cin>>pin;
    e1.push_back({Employee(Name,Gender,Location,Department,Employee_Type,Band,PF_Number,Acc_Number,CTC,EmployeeID,Door_Number,Street,Area,City,pin)});

    cout<<"Employee Details Added Succesfully\n\n";
    main_manu();
}

void Employer :: Print_all_employee()
{
    cout<<"******************Welcome to "<<cname<<" PayRoll Management***************\n\n\n";
    cout<<"Here is the Employee Details\n";

    for(int i=0;i<e1.size();i++)
    {
        cout<<"\n Employee "<<i+1<<" Details\n\n";
        cout<<"Employee Id:-\t"<<e1[i].Employee_ID<<"\n";
        cout<<"Employee Name:-\t"<<e1[i].Name<<"\n";        
        cout<<"Employee Gender:-\t"<<e1[i].Gender<<"\n";
        cout<<"Employee Location:-\t"<<e1[i].Location<<"\n";
        cout<<"Employee Department:-\t"<<e1[i].Department<<"\n";
        cout<<"Employee Employe Type:-\t"<<e1[i].Employee_Type<<"\n";
        cout<<"Employee Band:-\t"<<e1[i].Band<<"\n";
        cout<<"Employee PF Number:-\t"<<e1[i].PF_Number<<"\n";
        cout<<"Employee Accounter Number:-\t"<<e1[i].Acc_Number<<"\n\n";
        cout<<"Employee CTC:-\t"<<e1[i].CTC<<"\n\n";
        cout<<"**************Employee Address****************\n";
        cout<<"Employee Door Number:-\t"<<e1[i].Door_Number<<"\n";
        cout<<"Employee Street:-\t"<<e1[i].Street<<"\n";
        cout<<"Employee Area:-\t"<<e1[i].Area<<"\n";
        cout<<"Employee City:-\t"<<e1[i].City<<"\n";
        cout<<"Employee Pin Code:-\t"<<e1[i].pin<<"\n";
        cout<<endl<<endl<<endl<<endl;
    }
    main_manu();    
}

void Employer :: Modify_employee(int emp_id)
{
    int flag=0;
    for(int i=0;i<e1.size();i++)
    {
        if(e1[i].Employee_ID==emp_id)
        {
            flag=1;
            int n;
        start:cout<<"*************Welcome to "<<emp_id<<" Modification Section**************\n";
            cout<<"Choose to modify"<<endl;
            cout<<"1. Name"<<endl;
            cout<<"2. City"<<endl;
            cout<<"3. Location "<<endl;
            cout<<"4. Department "<<endl;
            cout<<"5. Employe type "<<endl;
            cout<<"6. Band"<<endl;
            cout<<"7. Account number "<<endl;
            cout<<"8. CTC"<<endl;
            cout<<"9. EXIT"<<endl;
            cout<<"enter your choice"<<endl;
            cin>>n;
            string a;
            long long int accno;
            double ctc;
            switch(n)
            {
                case 1:
                        cout<<"Enter the new name"<<endl;
                        cin>>a;
                        e1[i].Name=a;
                        cout<<"Modified"<<endl;
                        break;
                case 2:
                        cout<<"Enter the new "<<endl;
                        cin>>a;
                        e1[i].City=a;
                        cout<<"Modified"<<endl;
                        break;
                case 3:
                        cout<<"Enter the new Location"<<endl;
                        cin>>a;
                        e1[i].Location=a;
                        cout<<"Modified"<<endl;
                        break;
                case 4:
                        cout<<"Enter the new Department"<<endl;
                        cin>>a;
                        e1[i].Department=a;
                        cout<<"Modified"<<endl;
                        break;
                case 5:
                        cout<<"Enter the new Employee Type"<<endl;
                        cin>>a;
                        e1[i].Employee_Type=a;
                        cout<<"Modified"<<endl;
                        break;
                case 6:
                        cout<<"Enter the new Band"<<endl;
                        cin>>a;
                        e1[i].Band=a;
                        cout<<"Modified"<<endl;
                        break;
                case 7:
                        cout<<"Enter the new Account Number"<<endl;
                        cin>>accno;
                        e1[i].Acc_Number=accno;    
                        cout<<"Modified"<<endl;
                        break;
                case 8:
                        cout<<"Enter the new CTC "<<endl;
                        cin>>ctc;
                        e1[i].CTC=ctc;
                        cout<<"Modified"<<endl;
                        break;
                case 9:
                        goto manus;
                default:
                        cout<<"Choose Correct Option\n";
            }
            goto start;
        }
    }
    if(flag==0)
    {
        cout<<"Employee Does Not exixt\n";
        goto manus;
    }
    manus: main_manu();
}

void Employer :: Remove_employee(int emp_id)
{
    int flag=0;
    for(int i=0;i<e1.size();i++)
    {
        if(e1[i].Employee_ID==emp_id)
        {
            flag=1;
            e1.erase(e1.begin()+i);
            cout<<"Employee Details Removed Successfully\n\n";
            goto manus;
        }
    }
    if(flag==0)
    {
        cout<<"Employee Does Not exixt\n";
        goto manus;
    }
    manus: main_manu();  
}

void Employer :: Search_employee(int emp_id)
{
    int flag=0;
    for(int i=0;i<e1.size();i++)
    {
        if(e1[i].Employee_ID==emp_id)
        {
            flag=1;
            //cout<<"\n Employee "<<i+1<<" Details\n\n";
            cout<<"Employee Id:-\t"<<e1[i].Employee_ID<<"\n";
            cout<<"Employee Name:-\t"<<e1[i].Name<<"\n";        
            cout<<"Employee Gender:-\t"<<e1[i].Gender<<"\n";
            cout<<"Employee Location:-\t"<<e1[i].Location<<"\n";
            cout<<"Employee Department:-\t"<<e1[i].Department<<"\n";
            cout<<"Employee Employe Type:-\t"<<e1[i].Employee_Type<<"\n";
            cout<<"Employee Band:-\t"<<e1[i].Band<<"\n";
            cout<<"Employee PF Number:-\t"<<e1[i].PF_Number<<"\n";
            cout<<"Employee Accounter Number:-\t"<<e1[i].Acc_Number<<"\n\n";
            cout<<"Employee CTC:-\t"<<e1[i].CTC<<"\n\n";
            cout<<"**************Employee Address****************\n";
            cout<<"Employee Door Number:-\t"<<e1[i].Door_Number<<"\n";
            cout<<"Employee Street:-\t"<<e1[i].Street<<"\n";
            cout<<"Employee Area:-\t"<<e1[i].Area<<"\n";
            cout<<"Employee City:-\t"<<e1[i].City<<"\n";
            cout<<"Employee Pin Code:-\t"<<e1[i].pin<<"\n";
            goto manus;
        }
    }
    if(flag==0)
    {
        cout<<"Employee Does Not exixt\n";
        goto manus;
    }
    manus: main_manu();
}

void Employer :: Generate_Play_Slip(int emp_id,string m,int mess)
{
    int flag=0;
    for(int i=0;i<e1.size();i++)
    {
        if(e1[i].Employee_ID==emp_id)
        {
            flag=1;
            long long int bas_sal=0.6*e1[i].CTC;
            long int vpp=0.3*e1[i].CTC;
            long int pf=0.05*e1[i].CTC;
            int ot_al=0.05*e1[i].CTC;
            int tax=incom_tax(e1[i].CTC);
            long int gross=bas_sal+vpp+ot_al+pf;
            long int net_pay=gross-mess-tax;

            cout<<"\n\n========================================"<<endl;
            cout<<m<<endl;
            cout<<"Basic-Salary:"<<bas_sal<<endl;
            cout<<"Variable-Pay:"<<vpp<<endl;
            cout<<"Provident-Fund:"<<pf<<endl;
            cout<<"Income-Tax:"<<tax<<endl;
            cout<<"Mess-Bill:"<<mess<<endl;
            cout<<"Net-Pay:"<<net_pay<<endl;
            cout<<"Gross-pay:"<<gross<<endl;
            cout<<"======================================="<<endl;
            goto manus;
        } 
    }
    if(flag==0)
    {
        cout<<"Employee Does Not exixt\n";
        goto manus;
    }
    manus: main_manu();
}
int main()
{
    Employer ee;
    //ee.company_Details();
    ee.main_manu();
    return 0;
}