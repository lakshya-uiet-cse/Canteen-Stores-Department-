#include <iostream>
#include<cstdio>
#include <bits/stdc++.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<vector>
#include<ctime>
using namespace std;


int flag;
char HSPACE[20]="\t\t\t\t\t\t\t\t\t\t";
char hspace[20]="\t\t\t\t\t\t";
class Admin                                                           //CLASS ADMIN
{
     protected:
         char Product_Id[50];                             
         char Product_Name[50];
         float Price;
         char Cust_Id[50];
         char Cust_Name[50];
         char Cust_Add[50];
         char Cust_Mob[50];
         float sum_of_elems;
         vector<char*>pnam;                                //FOR STORING NAME OF BUYED PRODUCTS
         vector<char*>pid;                                 //FOR STORING ID OF BUYED PRODUCTS
         vector<float>subtotal;                            //FOR STORING SUBTOTAL PRICE OF BUYED PRODUCTS
         vector<float>quant;                               //FOR STORING QUANTITY OF BUYED PRODUCTS
         vector<float>price;                               //FOR STORING PRICE OF BUYED PRODUCTS       
         float gst;                            
     public:
        void pgetdata(void);                                //ADD PRODUCT DETAILS
        void pputdata(void);                                //PUT PRODUCT DETAILS
        void cgetdata(void);                                //ADD CUSTOMER DETAILS
        void cputdata(void);                                //PUT CUSTOMER DETAILS
        void showprod(void);                                //SHOW PRODUCT LIST
        void showcust(void);                                //SHOW CUSTOMER LIST
        void searchcust(void);                              //SHOW PRODUCT LIST ALREADY SAVED
        void controlAdmin(void);                            //MAIN CONTROL OF ADMIN CLASS
        void controlAdmin1(void);                           //EXTRA OPTIONS FOR PRODUCT MENU
        void controlAdmin2(void);                           //EXTRA OPTIONS FOR PRODUCT MENU
        void buy(void);                                     // buying products
        void showprod(int);                                 //SHOW PRODUCT LIST(FUNCTION OVERLOADED)
        void showcust(int);                                 //SHOW CUSTOMER LIST(FUNCTION OVERLOADED)
        void bill(void);                                    //BUYING PRODUCTS
        int date();                                         //FOR CURRENT DATE AND TIME
};
class Order:public Admin                                              // CLASS ORDER
{
public:
    void controlOrder(void);                                          //place order function
};
class Login:public Order                                              //CLASS LOGIN
    {
    private:
      vector<string> Login_Id;
      vector<string>Password;
    public:
        void Design(void);                                              //design of first page
        void control(void);                                             //main control of login class
        void password(void);                                            //login function
        void cantdetails(void);                                         //canteen details
    };
void Admin::controlAdmin(void)                                        //main control function of admin class defined
{
      Login L1;                                                      //OBJECT DECLARED OF CLASS LOGIN
      int option1;
      int option2;
      int option3;
                  cout << HSPACE << "1.PRODUCT MENU " << endl;
                  cout << HSPACE << "2.CUSTOMER MENU" << endl;
                  cout << HSPACE << "3.BACK       " << endl;
                  cout << endl;
                  cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                  cin >> option1;
                  cout << endl;
               switch(option1)
                {
                 case 1:                                                                 //product menu
                      cout << HSPACE << "1.ADD PRODUCT" << endl;
                      cout << HSPACE << "2.SHOW PRODUCT LIST" << endl; 
                      cout << HSPACE << "3.BACK TO MAIN MENU       " << endl;
                      cout << endl;
                      cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                      cin >> option2;
                      cout << endl;
                         switch(option2)
                         {
                             case 1:
                                {
                                    Admin F1;                                          //OBJECT DECLARED OF CLASS ADMIN
                                        fstream inoutfile;                             //OBJECT FOR OPENING FILE
                                        inoutfile.open("ABC.txt", ios::ate | ios::in | ios::out | ios::binary);
                                        F1.pgetdata();
                                        char ch1;
                                        cin.get(ch1);
                                        inoutfile.write((char *) & F1,sizeof F1);
                                    inoutfile.close();
                                controlAdmin();
                                }
                                break;
                            case 2:
                            {
                                showprod();
                            }
                            break;
                         default:
                         {
                         cout << HSPACE << "INVALID INPUT" << endl; cout<<endl;
                         controlAdmin();
                         }
                         break;
                         }
                 break;
                 case 2:   
                 {                                                     //customer menu
                         cout << HSPACE << "1.ADD NEW CUSTOMER" << endl;
                         cout << HSPACE << "2.SHOW CUSTOMER LIST" << endl;
                         cout << HSPACE << "3.SEARCH CUSTOMER" << endl;
                         cout << HSPACE << "4.BACK TO MAIN MENU      " << endl;
                         cout << endl;
                         cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                         cin >> option2;
                         cout << endl;
                        switch(option2)
                         {
                         case 1:    
                         {
                                        Admin F2;                                           //OBJECT DECLARED OF CLASS ADMIN
                                        fstream inoutfile1;                                 //OBJECT FOR OPENING FILE
                                        inoutfile1.open("XYZ.txt", ios::ate | ios::in | ios::out | ios::binary);
                                        F2.cgetdata();
                                        char ch2;
                                        cin.get(ch2);
                                        inoutfile1.write((char *) & F2,sizeof F2);
                                        inoutfile1.close();
                         }
                         break;
                         case 2:
                         {
                           showcust();
                           controlAdmin();
                         }
                         break;
                         case 3:
                         {
                              searchcust();
                              controlAdmin();
                         }
                         break;
                         default:
                         {
                         cout << HSPACE << "INVALID INPUT" << endl;
                         controlAdmin();
                         }
                         break;
                         }
                 }
                 case 3:
                       L1.control();
                    break;
                }
}
void Admin::pgetdata(void)                                            //getting product detail's function defined
{   
    cout << HSPACE << "Product Id : ";
    cin >> Product_Id;
    cin.ignore(50,'\n');
    cout << HSPACE << "Product Name : ";
    cin.getline(Product_Name,50);
    cout << HSPACE << "Price : ";
    cin >> Price;
}
void Admin::pputdata(void)                                            //displaying product details's function defined
{      
        cout << "\t\t\t\t\t\t\t\t\t";
        cout.setf(ios::left ,ios::adjustfield );
        cout << setw(15) << Product_Id 
        << setw(22) << Product_Name 
        <<"Rs." << setw(21)  << Price 
        << endl;
}
void Admin::cgetdata(void)                                            //getting customer detail's function defined
{ 
    cout << HSPACE << "Customer Id : " ;
    cin >> Cust_Id;
    cin.ignore(50,'\n');                                             
    cout << HSPACE << "Customer Name : ";
    cin.getline(Cust_Name,50);
    cout << HSPACE << "Customer Address : ";
    cin.getline(Cust_Add,50);
    cout << HSPACE << "Mobile No. : ";
    cin >> Cust_Mob;
    if(Cust_Mob>"9999999999")
    {
         cout << HSPACE << "Invalid mobile no." << endl;
         cout << HSPACE <<"Please Re-enter" << endl;
         cout << HSPACE << "Mobile No. : ";
         cin >> Cust_Mob;
    }
}
void Admin::cputdata(void)                                            //displaying customer detail's function defined
{  
   cout << "\t\t\t\t\t\t";
   cout.setf(ios::left ,ios::adjustfield );
   cout<< setw(16) << Cust_Id
   << setw(25) << Cust_Name
   << setw(35) << Cust_Add
   << setw(28) << Cust_Mob
   << endl;   
}
void Admin::controlAdmin1(void)                                       //extra options for product menu
{
                                    int option3;
                                    cout << HSPACE << "1.MODIFY A PRODUCT DETAILS" << endl;
                                    cout << HSPACE << "2.DELETE A PRODUCT" << endl;          
                                    cout << HSPACE << "3.BACK TO MAIN MENU      " << endl;
                                    cout << endl;
                                    cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                                    cin >> option3;
                                    cout << endl;
                                    switch(option3)
                                    {
                                        case 1:
                                        {
                                            Admin F1;                                           //OBJECT DECLARED OF CLASS ADMIN
                                            fstream inoutfile;                                  //OBJECT FOR OPENING FILE
                                            inoutfile.open("ABC.txt",ios::ate | ios::in | ios::out | ios::binary | ios::trunc);
                                            int object;
                                            char ch;
                                            char c;
                                            int n;
                                            cout << HSPACE << "Enter Item No. To be Modified:  ";
                                            cin >> object;
                                            cin.get(ch);
                                            int location=(object-1) * sizeof (F1);
                                            if(inoutfile.eof())
                                            {
                                            inoutfile.clear();
                                            }
                                            inoutfile.seekp(location);
                                            cout << endl;
                                            cout << HSPACE << "Enter new Data:" << endl;
                                            cout << endl;
                                            F1.pgetdata();
                                            cin.get(ch);
                                            inoutfile.write((char *) & F1, sizeof F1) << flush;
                                            inoutfile.close();
                                            controlAdmin();
                                        }
                                        break;
                                        case 2:
                                        
                                        break;
                                        case 3:
                                        {
                                           controlAdmin();
                                        }
                                        break;
                                        default:
                                        cout << endl;
                                        cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
                                        cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
                                        cout << endl;
                                        controlAdmin1();
                                        break;
                                    }


}
void Admin::controlAdmin2()
{
     int option3;
                                    cout << HSPACE << "1.MODIFY A CUSTOMER'S DETAILS" << endl;
                                    cout << HSPACE << "2.DELETE A CUSTOMER'S RECORD" << endl;          
                                    cout << HSPACE << "3.BACK TO MAIN MENU      " << endl;
                                    cout << endl;
                                    cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                                    cin >> option3;
                                    cout << endl;
                                    switch(option3)
                                    {
                                        case 1:
                                        {
                                            Admin F2;                                       //OBJECT DECLARED OF CLASS ADMIN
                                            fstream inoutfile1;                             //OBJECT FOR OPENING FILE
                                            inoutfile1.open("XYZ.txt",ios::ate | ios::in | ios::out | ios::binary);
                                            int object;
                                            char ch;
                                            cout << HSPACE << "Enter Customer No. To be Modified:  ";
                                            cin >> object;
                                            cin.get(ch);
                                            int location=(object-1) * sizeof (F2);
                                            if(inoutfile1.eof())
                                            {
                                            inoutfile1.clear();
                                            }
                                            inoutfile1.seekp(location);
                                            cout << endl;
                                            cout << HSPACE << "Enter new Data:" << endl;
                                            cout << endl;
                                            F2.cgetdata();
                                            cin.get(ch);
                                            inoutfile1.write((char *) & F2, sizeof F2) << flush;
                                            controlAdmin();
                                        }
                                        break;
                                        case 2:
                                        
                                        break;
                                        case 3:
                                        {
                                           controlAdmin();
                                        }
                                        break;
                                        default:
                                        cout << endl;
                                        cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
                                        cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
                                        cout << endl;
                                        controlAdmin1();
                                        break;
                                    }
}
void Admin::showprod(int)                                             //product's list's function defined (function overloaded)
                   {   
                                int option4;
                                Admin F1;                                           //OBJECT DECLARED OF CLASS ADMIN
                                fstream inoutfile;                                  //OBJECT FOR OPENING FILE
                                inoutfile.open("ABC.txt",ios::ate | ios::in | ios::out | ios::binary);
                                inoutfile.seekg(0);
                                cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;
                                cout << "\t\t\t\t\t\t\t\t\t";
                                cout.setf(ios::left ,ios::adjustfield );
                                cout << setw(15) << "Product Id"
                                << setw(22) << "Product Name"
                                << setw(21) << "Price" 
                                << endl;  
                                cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;    
                                while(inoutfile.read((char *) & F1, sizeof F1))
                                    {
                                        F1.pputdata();
                                    }
                                    cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;
                                    cout << endl;
                                    inoutfile.clear();
                                    inoutfile.close();
                                    }
void Admin::showprod(void)                                            //product's list's function defined
{                               int option4;
                                Admin F1;                               //OBJECT DECLARED OF CLASS ADMIN
                                fstream inoutfile;                      //OBJECT FOR OPENING FILE
                                inoutfile.open("ABC.txt",ios::ate | ios::in | ios::out | ios::binary);
                                inoutfile.seekg(0);
                                cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;
                                cout << "\t\t\t\t\t\t\t\t\t";
                                cout.setf(ios::left ,ios::adjustfield );
                                cout << setw(15) << "Product Id"
                                << setw(22) << "Product Name"
                                << setw(21) << "Price" 
                                << endl;
                                cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;     
                                while(inoutfile.read((char *) & F1, sizeof F1))
                                    {
                                        F1.pputdata();      
                                    }
                                    cout << "\t\t\t\t\t\t\t\t" << "   ------------------------------------------------------" << endl;
                                    cout << endl;
                                    inoutfile.clear();
                                    inoutfile.close();
                                    cout << HSPACE << "1.MORE OPTIONS" << endl;
                                    cout << HSPACE << "2.BACK TO MAIN MENU      " << endl;
                                    cout << endl;
                                    cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                                    cin >> option4;
                                    cout << endl;
                                    switch (option4)
                                    {
                                    case 1:
                                     controlAdmin1();
                                    break;
                                    case 2:
                                     controlAdmin();
                                    break;
                                    default:
                                        cout << endl;
                                        cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
                                        cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
                                        cout << endl;
                                     controlAdmin();
                                    break;
                                    }
}
void Admin::showcust(void)                                            //customer's list's function defined
{
                                int option4;
                                Admin F2;                                       //OBJECT DECLARED OF CLASS ADMIN
                                fstream inoutfile1;                             //OBJECT FOR OPENING FILE
                                inoutfile1.open("XYZ.txt",ios::ate | ios::in | ios::out | ios::binary);
                                inoutfile1.seekg(0);
                                cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;
                                cout << "\t\t\t\t\t\t";
                                cout.setf(ios::left ,ios::adjustfield );
                                cout << setw(16) << "Customer Id"  
                                << setw(25) << "Customer Name" 
                                << setw(35) << "Customer Address" 
                                << setw(28) << "Mobile No." << endl;  
                                cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;                           
                                   while(inoutfile1.read((char *) & F2, sizeof F2))
                                    {
                                       F2.cputdata();
                                    }
                                    cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;
                                    cout << endl;
                                    inoutfile1.clear();
                                    inoutfile1.close();
                                    cout << HSPACE << "1.MORE OPTIONS" << endl;
                                    cout << HSPACE << "2.BACK TO MAIN MENU      " << endl;
                                    cout << endl;
                                    cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                                    cin >> option4;
                                    switch(option4)
                                    {
                                        case 1:
                                          controlAdmin2();
                                        break;
                                        case 2:
                                          controlAdmin();
                                          break;
                                    }
                                    
}
void Admin::showcust(int)
{
     int option4;
                                Admin F2;                                       //OBJECT DECLARED OF CLASS ADMIN
                                fstream inoutfile1;                             //OBJECT FOR OPENING FILE
                                inoutfile1.open("XYZ.txt",ios::ate | ios::in | ios::out | ios::binary);
                                inoutfile1.seekg(0);
                                cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;
                                cout << "\t\t\t\t\t\t";
                                cout.setf(ios::left ,ios::adjustfield );
                                cout << setw(16) << "Customer Id"  
                                << setw(25) << "Customer Name" 
                                << setw(35) << "Customer Address" 
                                << setw(28) << "Mobile No." << endl;  
                                cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;                           
                                   while(inoutfile1.read((char *) & F2, sizeof F2))
                                    {
                                       F2.cputdata();
                                    }
                                    cout << "\t\t\t\t\t    -------------------------------------------------------------------------------------------------" << endl;
                                    cout << endl;
                                    inoutfile1.clear();
                                    inoutfile1.close();
}
void Admin::searchcust(void)                                          //for displaying customer's details on bill
{
                                            Admin F2;                       //OBJECT DECLARED OF CLASS ADMIN
                                            fstream inoutfile1;             //OBJECT FOR OPENING FILE
                                            inoutfile1.open("XYZ.txt",ios::ate | ios::in | ios::out | ios::binary);
                                            int object;
                                            cout <<  "\t\t\t\t\t\t"<< "Customer number : ";
                                            cin >> object;
                                            int location=(object-1) * sizeof (F2);
                                            if(inoutfile1.eof())
                                            {
                                            inoutfile1.clear();
                                            }
                                            inoutfile1.seekg(location);
                                            inoutfile1.read((char *) &F2 , sizeof(F2));
                                            cout <<  "\t\t\t\t\t\t"<< "Customer Id:  " <<  F2.Cust_Id << endl;
                                            cout <<  "\t\t\t\t\t\t"<< "Customer Name:  " << F2.Cust_Name << endl;;
                                            cout <<  "\t\t\t\t\t\t"<< "Mobile No.:  " << F2.Cust_Mob << endl;
                                            cout <<  "\t\t\t\t\t\t"<< "Customer Address:  "  << F2.Cust_Add << endl;
                                            inoutfile1.close();
                                            
}
void Admin::buy(void)                                                 //for searching a particular object's price
{    
     showprod(7);     
                    Login l;                                                
                                            float p1;
                                            Admin F1;                                   //OBJECT DECLARED OF CLASS ADMIN
                                            fstream inoutfile;                          //OBJECT FOR OPENING FILE
                                            inoutfile.open("ABC.txt",ios::ate | ios::in | ios::out | ios::binary);
                                            int object;
                                            cout << HSPACE << "Enter Item No. To be bought:  ";
                                            cin >> object;
                                            int location=(object-1) * sizeof (F1);
                                            if(inoutfile.eof())
                                            {
                                            inoutfile.clear();
                                            }
                                            inoutfile.seekg(location);
                                            inoutfile.read((char *) & F1, sizeof F1);    
                                            
                                             cout << endl << HSPACE << "Quantity:  ";
                                             int q;
                                             cin >> q;
                                             quant.push_back(q);
                                              float s;                                            
                                              s=q*F1.Price; 
                                              subtotal.push_back(s);                                                                
                                            pnam.push_back(F1.Product_Name); 
                                            pid.push_back(F1.Product_Id);
                                            price.push_back(F1.Price);
                                            cout << HSPACE << "Want to buy more ?" << endl;    
                                            cout << HSPACE << "1.YES" << endl;
                                            cout << HSPACE << "2.NO" << endl;
                                            cout << endl;
                                            cout << HSPACE << "PLEASE ENTER YOUR CHOICE:   ";
                                             int num;
                                            cin>>num;
                                            cout << endl;
                                             if(num==1)
                                             {       
                                                buy();
                                             } 
                                             else if(num==2)
                                            {
                                                cout << "\t\t\t\t\t\t\t\t" <<"!!!!!......YOU ENTERED NO SO LETS PROCEED TO BILL......!!!!!" << endl;
                                                cout << endl;
                                                showcust(7);
                                                cout << endl;
                                                cout << "\t\t\t\t\t\t\t\t\t" << "CHOOSE CUSTOMER DETAILS AND PRINT THE BILL" << endl;
                                                cout << endl;
                                                 bill();
                                                 cout << "\t\t\t\t\t\t";
                                                 cout.setf(ios::left ,ios::adjustfield );
                                                 cout << setw(10) << "S.no." 
                                                 << setw(15) << "Product Id"
                                                 << setw(20) << "Product Name"
                                                 << setw(15) << "Price" 
                                                 << setw(10) << "quantity" 
                                                 << setw(15) << "sub total" << endl;
                                                 cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
                                             for(int ic=0;ic<pnam.size();ic++)
                                            {
                                               cout << "\t\t\t\t\t\t" ;
                                               cout.setf(ios::left ,ios::adjustfield );
                                               cout << setw(10) << ic+1 
                                               << setw(15) << pid[ic]
                                               << setw(20) << pnam[ic]
                                               << setw(15) << price[ic] 
                                               << setw(10) <<quant[ic]
                                               << setw(15) <<subtotal[ic] <<endl;
                                            }
                                            for(vector<float>::iterator it = subtotal.begin(); it != subtotal.end(); ++it)
                                            {
                                            sum_of_elems += *it;
                                            }
                                            gst = (18*sum_of_elems)/100;
                                            sum_of_elems +=gst;
                         
                      cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
                      cout << HSPACE << "\t\t\t" <<"        TOTAL = INR. "<<accumulate(subtotal.begin(), subtotal.end(), 0.00)<<endl;    
                      cout << "\t\t\t\t\t\t";
                      cout << "Applicable GST(18% of total):" ;
                      cout << "\t\t\t\t\t" << "      = INR. " << gst << endl;
                      cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------";
                      cout << HSPACE << "\t\t\t" <<"              GRAND TOTAL = INR. " << sum_of_elems << endl;
                      cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------";
                      l.cantdetails();
                       cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
                       cout << endl;
                       cout << endl;
                      controlAdmin();                                                              
    }
    else
    {
     cout << endl;
         cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
         cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
         cout << endl;
    }
}
int Admin::date()                                                     //date and time functiond defined
{
     time_t tmNow;
    tmNow = time(NULL);
    struct tm t = *localtime(&tmNow);
    int mon;
    cout << HSPACE << "\t\t\t\t\t" <<"Date: "<<t.tm_mday<<" ";
    mon = t.tm_mon+1;
    switch(mon)
    {
        case 1:
            cout<<"Jan, ";
            break;
        case 2:
            cout<<"Feb, ";
            break;
        case 3:
            cout<<"Mar, ";
            break;
        case 4:
            cout<<"Apr, ";
            break;
        case 5:
            cout<<"May, ";
            break;
        case 6:
            cout<<"June, ";
            break;
        case 7:
            cout<<"July, ";
            break;
        case 8:
            cout<<"Aug, ";
            break;
        case 9:
            cout<<"Sept, ";
            break;
        case 10:
            cout<<"Oct, ";
            break;
        case 11:
            cout<<"Nov, ";
            break;
        case 12:
            cout<<"Dec, ";
            break;
    }
    cout<<t.tm_year+1900 << endl;
    cout<< HSPACE << "\t\t\t\t\t" <<"Time: ";
    if(t.tm_hour>=12)
    {
        if(t.tm_hour==12)
            cout<<"12";
        else
            cout<<t.tm_hour-12;
        cout<<":"<<t.tm_min<<":"<<t.tm_sec<<" PM";
    }
    else
        cout<<t.tm_hour<<":"<<t.tm_min<<":"<<t.tm_sec<<" AM";
    cout<<endl;
    return 0;
}
void Admin::bill(void)                                                //bill function defined
{  
   cout << "\t\t\t\t\t\t\t\t\t\t" << "  HERE IS YOUR BILL" << endl;
   cout << "\t\t\t\t\t      --------------------------------------------------------------------------------------------------" << "\n\n";
   cout << "\t\t\t\t\t\t\t\t\t" << "|" << " !!!!.....CANTEEN STORE DEPARTMENT.....!!!! " << "|" << endl;
   cout << HSPACE  << "CHANDIMANDIR(WESTERN COMMAND)" << "\n" <<endl;
   cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
   date();
   searchcust();
   cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
   cout << endl;
}
void Order::controlOrder(void)                                        //main control of order class
{
    Login L2;                                                           //OBJECT DECLARED OF CLASS LOGIN
    int option1;
    int option2;
    cout << endl;
    cout << HSPACE << "1.NEW CUSTOMER " << endl;
    cout << HSPACE << "2.SHOW CUSTOMER LIST " << endl;
    cout << HSPACE << "3.PROCEED TO BUY " << endl;
    cout << HSPACE << "4.BACK      " << endl;
    cout << endl;
    cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
    cin >> option1;
    cout << endl;
    switch(option1)
    {
    case 1:
            {
                                        Admin F2;                                 //OBJECT DECLARED OF CLASS ADMIN
                                        fstream inoutfile1;                       //OBJECT FOR OPENING FILE
                                        inoutfile1.open("XYZ.txt", ios::ate | ios::in | ios::out | ios::binary);
                                        F2.cgetdata();
                                        char ch2;
                                        cin.get(ch2);
                                        inoutfile1.write((char *) & F2,sizeof F2);
                                        inoutfile1.close();
                                        cout << endl;
                                        buy();
            }
          break;
    case 2:
    {
       showcust();
       cout << endl;
       controlOrder();
    }
        break;
    case 3:
    {
        cout << HSPACE << "1.SHOW PRODUCT LIST" << endl;
        cout << HSPACE << "2.BUY" << endl;
         cout << endl;
        cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
        cin >> option2;
        cout << endl;
        switch(option2)
        {
        case 1:
        {
           buy();
        }
        break;
        case 2:
        {   
           buy();                             
        }
        break;
        }
    }
    break;
    case 4:
        L2.control();
        break;
    default:
         cout << endl;
         cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
         cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
         cout << endl;
    break;  
    }


}
void Login::Design(void)                                              //design function defined of class login
    {
        int d=35;
        for(int g=0;g<d;g++)
        {
        cout << "  *****     ";
        }
        cout << endl;
        cout << "                  ---------------------------------------------------------------------------------------------------------------------------------------------------------------------"<< "\n\n\n";
        cout << hspace << "\t\t\t\t*****    *****   ***" << endl;
        cout << hspace << "\t\t\t\t*        *       *   *"<< endl;
        cout << hspace << "\t\t\t\t*        *****   *    *" << endl;
        cout << hspace << "\t\t\t\t*            *   *   *" <<endl;
        cout << hspace << "\t\t\t\t*****    *****   ***" << endl;
        cout << hspace << "\t\t\t\tSERVICE BEFORE SELF...!!!!" <<"\n\n\n";


        cout << hspace << "\t\t\t\t" << "\tWELCOME TO"<< endl;
        cout << hspace << "\t" <<"|-:-|-:-|-:-|-:-|\tCANTEEN STORES DEPARTMENT\t|-:-|-:-|-:-|-:-|" << endl ;
        cout << hspace << "\t\t\t\tCHANDIMANDIR (WESTERN COMMAND)"<< "\n\n\n";
        cout << "                 ---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        for(int g=0;g<d;g++)
        {
        cout << "  *****     ";
        }
        cout << endl;
    }
void Login::cantdetails(void)
{   
    cout << HSPACE << "\t\t\t\t\t" <<"CANTEEN DETAILS" << endl;
     cout << "\t\t\t\t\t      -------------------------------------------------------------------------------------------------" << endl;
    cout << hspace << "#TIMINGs:";
    cout << "\t\t\t\t" << "#CANTEEN WILL BE CLOSED ON TUESDAY AND SUNDAY" << endl;
    cout << hspace << "11 AM TO 02 PM" ;
    cout << "\t\t\t\t" << "#GOODS ONCE SOLD WILL NOT BE EXCHANGED/REPLACED" << endl;
    cout << hspace << "03 PM TO 05 PM" ;
    cout << "\t\t\t\t" << "#TAKE YOUR SMART CARD WITH YOU FOR CASHLESS TRANSACTIONS" << endl;
    cout << HSPACE << "\t" << "#COLLECT YOUR SMART CARD & BILL AFTER PAYMENT" <<endl;
    cout << HSPACE << "\t" << "#DO NOT BREAK ANY CANTEEN ITEMS" << endl;
}
void Login::control(void)                                             //PLACE ORDER ,ADMIN ,exit
    {
        int option;


                  cout << endl;
                  cout << HSPACE << "1.PLACE ORDER " << endl;
                  cout << HSPACE << "2.ADMIN" << endl;
                  cout << HSPACE << "3.LOG OUT" << endl;
                  cout << endl;
                  cout << HSPACE << "PLEASE ENTER YOUR CHOICE:  ";
                  cin >> option;
                  cout << endl; 
                switch(option)
                {
                    case 1:
                    cout << HSPACE <<"PLEASE PLACE YOUR ORDER" << endl;
                    controlOrder();
                    break;
                    case 2:
                    cout << HSPACE << "Dear Admin Welcome\n";
                    controlAdmin();
                 case 3:
                    password();
                    break;
                    default:
                                        cout << endl;
                                        cout << HSPACE << "!!!...INVALID INPUT...!!!" << endl;
                                        cout << HSPACE << "!!!...PLEASE TRY AGAIN...!!!" << endl;
                                        cout << endl;
                    control();
                    break;
                }
    }
void Login::password(void)                                            //ENTERING LOGIN ID AND PASSWORD
    { 
        int i=0;
         string li;
         string pass;
         cout << "\n" << HSPACE << "Login_Id:";
        cin>>li;
         Login_Id.push_back(li);
         cout << HSPACE <<"Password:";
         cin>>pass;
        Password.push_back(pass);
         
         cout << endl;   
        if((Login_Id[i]=="CSDCHD" || Login_Id[i]=="csdchd")  && (Password[i]=="!@#$%" || Password[i]=="!@#$%")) 
        {     
             i++; 
             cout << "\t\t\t\t\t\t\t\t\t" << "!!!*!!! LOGIN SUCCESSFUL !!!*!!!" << endl;
             cout << endl;
             Login_Id.clear();
             Password.clear();
             control(); 
        }
        if((Login_Id[i]!="CSDCHD" || Login_Id[i]!="csdchd")  || (Password[i]!="!@#$%" || Password[i]!="!@#$%"))
        {
            cout << HSPACE <<"Login id or Password Incorrect" << endl;
            Login_Id.clear();
            Password.clear();
            Design();
            password();
        }
    }
int main()                                                            //main function
{
    Login L;                                                          //OBJECT DECLARED OF CLASS LOGIN
    L.Design();
    L.password();
}

