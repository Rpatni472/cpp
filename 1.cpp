1. An electricity board charges the following rates to domestic users to discourage
large consumption of energy.
For the first 100 units: - 60 P per unit
For the next 200 units: -80 P per unit
Beyond 300 units: -90 P per unit
All users are charged a minimum of Rs 50 if the total amount is more than Rs 300
then an additional surcharge of 15% is added.
Implement a C++ program to read the names of users and number of units consumed
and display the charges with names.

#include<iostream>
using namespace std;
int main()
{
    int n;
    float charge,scharge;
    string name;
    cout<<"\n enter name and number of units consumed";
    cin>>name;
    cin>>n;
    if(n<=100)
        charge=(0.60*n);
    if(n>100 && n<=300)
    {        
        charge=  100*.6 +(n-100)*0.80;
    }
    if(n>=300)
    {
        charge= 100*.6 + 200*.8 +(n-300)*0.90;
    }
    if(charge<50)
        charge=50;
    if(charge>300)
    {
        scharge=(0.15*charge);
        charge= charge + .15*charge;
    }

    cout<<"electricity bill \n";
    cout<<name<<" : : rs"<<charge;    
    
}

Output:

enter name and number of units consumed
Rohan
250
electricity bill 
Rohan : : rs180


2. Construct a C++ program that removes a specific character from a given string and
return the updated string.
Typical Input: computer science is the future
Typical Output: compuer science is he fuure

#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    string res="";
    char c;

    cout<<"input string "<<endl;
    getline(cin,s);
    cout<<"enter character to remove"<<endl;
    cin>>c;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=c)
        {
            res=res+s[i];
        }
    }
    cout<<"The result string is : "<<res<<endl;
   
}

Output :

input string 
The school is the best school
enter character to remove
t
The result string is : The school is he bes school
 
3. Implement a C++ program to find the non-repeating characters in string. 
Typical Input: graphic era university 
Typical Output: c g h n p s t u v y

#include <iostream>
#include <string>
using namespace std;

int main()
{

    string s;
    cout << "enter string \n";
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        int duplicate = 0;
        for (int j = 0; j < s.size(); j++)
        {

            if (s[i] == s[j] and i != j)
            {
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 0)
        {
            cout << s[i] << " is unique character" << endl;
        }
    }
}


Output :

enter string 
graphic era university
g p h c u n v s t y









4. Implement a C++ program to demonstrate the concept of data abstraction using the concept of Class and Objects


#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
class student
{
private:
    string name;
    int rn, eng, hin;

public:
    void input();
    void disp();
    void total();
};

void student::input()
{
    cout << "Enter name , rn, eng marks, hin marks" << endl;
    cin >> name >> rn >> eng >> hin;
}
void student::disp()
{
    cout << "The details of students are " << endl;
    cout << name << " " << rn << " " << eng << " " << hin << endl;
}

void student::total()
{
    cout << "Total marks of students are" << endl;
    cout << eng + hin << endl;
}

int main()
{
    student obj1, obj2;
    obj1.input();
    obj1.disp();
    obj1.total();

    obj2.input();
    obj2.disp();
    obj2.total();
}

Output :

Enter name , rn, eng marks, hin marks
shivam
122
80
89
The details of students are
shivam 122 80 89
Total marks of students are
169
Enter name , rn, eng marks, hin marks
 
5. Define a class Hotel in C++ with the following specifications Private members • Rno Data member to store room number • Name Data member to store customer name • Tariff Data member to store per day charges • NOD Data member to store number of days of stay • CALC() Function to calculate and return amount as NOD*Tariff ,and if the value of days* Tariff >10000, then total amount is 1.05* days*Tariff. Public members • Checkin() Function to enter the con-tent Rno, Name, Tariff and NOD • Checkout() Function to display Rno, Name, Tariff, NOD and Amount (amount to be displayed by calling function) CALC()


#include<iostream>
using namespace std;

class hotel
{
    private:
        string name;
        int room, nod, tariff;
        float calc();
    public:
        void checkin();
        void checkout();

};

void hotel::checkin()
{
    cout<<"Enter name, room#, no of days, tariff"<<endl;
    cin>>name>>room>>nod>>tariff;
}
void hotel::checkout()
{
    cout<<"Details are as follows: \n";
    cout<<name<<" "<<room<<" "<<nod<<" "<<tariff<<endl;
    cout<<"The total amount is "<<calc()<<endl;;
}
float hotel::calc()
{
    
    if(nod*tariff>10000)
    {
        return nod*tariff*1.05;
    }
    else
    { 
        return nod*tariff;
    }
}
int main()
{
    int choice;
    hotel obj;
    while(1)
    {
        obj.checkin();
        obj.checkout();

        cout<<"press 0 to exit any other key to continue:"<<endl;
        cin>>choice;
        if (choice==0)
            break;
    }
    
}


Output :

Enter name, room#, no of days, tariff
shivam
12
35
500
Details are as follows: 
shivam 12 35 500
The total amount is 18375
press 0 to exit any other key to continue:
 
6. Implement a Program in C++ by defining a class to represent a bank account. Include the following:  Data Members 
● Name of the depositor 
● Account number 
● Type of account (Saving, Current etc.) 
● Balance amount in the account Member Functions 
● To assign initial values 
● To deposit an amount
● To withdraw an amount after checking the balance 
● To display name and balance


#include <iostream>
using namespace std;

class bank
{
private:
    string name, type;
    int account;
    float balance;

public:
    void input();
    void disp();
    void deposit(float amount);
    void withdraw(float amount);
};

void bank::input()
{
    cout << "Enter name , type, acc#, initial balance" << endl;
    cin >> name >> type >> account >> balance;
}
void bank::disp()
{
    cout << "The details are \n";
    cout << name << " " << type << " " << account << " " << balance << endl;
}

void bank::deposit(float amount)
{
    balance = balance + amount;
    cout << "Amount deposited successfully\n";
}
void bank::withdraw(float amount)
{
    if (balance == 0 or amount > balance)
    {
        cout << "Can't Withdraw. Check Balance\n";
    }
    else
    {
        balance = balance - amount;
    }
}
int main()
{
    bank obj;
    cout << "Object created. What operations do you want to per-fornm\n";

    int choice;
    float amount;
    while (1)
    {
        cout << "\n\n 1. To input values\n 2. To display values\n 3. To Deposit balance\n 4. To withdraw balance\n 5. To Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.input();
            break;
        case 2:
            obj.disp();
            break;
        case 3:

            cout << "enter amount to deposit\n";
            cin >> amount;
            obj.deposit(amount);
            break;
        case 4:

            cout << "enter amount to withdraw\n";
            cin >> amount;
            obj.withdraw(amount);
            break;

        case 5:
            return 0;
        }
    }
}

Output :

Object created. What operations do you want to perfornm


 1. To input values
 2. To display values
 3. To Deposit balance
 4. To withdraw balance
 5. To Exit
1
Enter name , type, acc#, initial balance
shivam
current
699
50000


 1. To input values
 2. To display values
 3. To Deposit balance
 4. To withdraw balance
 5. To Exit
4
enter amount to withdraw
6500


 1. To input values
 2. To display values
 3. To Deposit balance
 4. To withdraw balance
 5. To Exit
3
enter amount to deposit
1567
Amount deposited successfully


 1. To input values
 2. To display values
 3. To Deposit balance
 4. To withdraw balance
 5. To Exit
2
The details are
shivam current 699 45067


 1. To input values
 2. To display values
 3. To Deposit balance
 4. To withdraw balance
 5. To Exit

7. Anna is a contender for valedictorian of her high school. She wants to know how many stu-dents (if any) have scored higher than her in the exams given during this semester. 
Create a class named Student with the following specifications: 
➢ An instance variable named scores holds a student's 5 exam scores. 
➢ A void input () function reads 5 integers and saves them to scores. 
➢ An int calculateTotalScore() function that returns the sum of the student's scores. 

Input Format

In the void Student::input() function, you must read 5 scores from standard input and save them to your scores instance variable. 

Output Format 

In the int Student::calculateTotalScore() function, you must return the student's total grade (the sum of the values in scores). The code in the editor will determine how many scores are larger than Anna’s and print that number to the console. 

Sample Input 

The first line contains n, the number of students in Anna’s class. The n subsequent lines contain each student's 5 exam grades for this semester. 
3 
30 40 45 10 10 
40 40 40 10 10 
50 20 30 10 10 
Sample Output 
1


#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int marks[5];

public:
    void input();
    void disp();
    int total();
};
void student::input()
{
    cout << "Enter name and marks of 5 subjects\n";
    cin >> name;
    for (int i = 0; i < 5; i++)
    {
        cin >> marks[i];
    }
}
void student::disp()
{
    cout << "Displaying name and marks in 5 subjects\n";
    cout << name << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << marks[i] << " ";
    }
}
int student::total()
{
    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += marks[i];
    }
    return sum;
}

int main()
{
    int n, val;
    cout << "Enter the marks of valedictorian\n";
    cin >> val;
    cout << "Enter the number of students\n";
    cin >> n;

    student ar[n];

    for (int i = 0; i < n; i++)
    {
        ar[i].input();
    }

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (ar[i].total() > val)
        {
            count++;
        }
    }
    cout << "The number of students having more marks is : " << count << endl;
}


Output :

Enter the marks of valedictorian
500
Enter the number of students
3
Enter name and marks of 5 subjects
shivam
30 
40 
45 
10 
10
Enter name and marks of 5 subjects
40
40
40
10
10
Enter name and marks of 5 subjects
manu
50
20
30
10
10
The number of students having more marks is : 0
 
8. Construct a Program in C++ to show the working of function overloading(compile time polymorphism) by using a function named calculate Area () to calculate area of square, rectangle and triangle using different signatures as required.


#include <iostream>
#include <cmath>
using namespace std;

void area(int x)
{
    cout << "Area of square is " << x * x << endl;
}

void area(int x, int y)
{
    cout << "Area of rectangle is " << x * y << endl;
}

void area(int x, int y, int z)
{
    float s = (float)(x + y + z) / 2;
    float area = sqrt(s * (s - x) * (s - y) * (s - z));
    cout << "Area=" << area << endl;
}

int main()
{

    int choice, x, y, z;
    while (1)
    {
        cout << "1. For square\n 2. For rectangle\n 3. For trian-gle\n 4. To exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter side: \n";
            cin >> x;
            area(x);
            break;
        case 2:
            cout << "Enter len and breadth \n";
            cin >> x >> y;
            area(x, y);
            break;
        case 3:
            cout << "Enter s1, s2, s3 \n";
            cin >> x >> y >> z;
            area(x, y, z);
            break;
        case 4:
            return 0;
        }
    }
}


Output :

1. For square
 2. For rectangle
 3. For triangle
 4. To exit
3
Enter s1, s2, s3 
34
23
12
Area=66.809
1. For square
 2. For rectangle
 3. For triangle
 4. To exit
1
enter side:
45
Area of square is 2025
1. For square
 2. For rectangle
 3. For triangle
 4. To exit
 
9. Create a class called Invoice that a hardware store might use to represent an invoice for an item sold at the store. An Invoice should include four pieces of information as instance. 
Data Members ‐ 
• partNumber (type String) 
• partDescription (type String) 
• quantity of the item being purchased (type int) 
• price_per_item (type double) 
Your class should have a constructor that initializes the four instance variables. Provide a set and a get method for each instance variable. In addition, provide a method named getInvoiceA-mount() that calculates the invoice amount (i.e., multiplies the quantity by the price per item), then returns the amount as a double value. If the quantity is not positive, it should be set to 0. If the price per item is not positive,it should be set to0.0. Write a test application named in-voiceTest that demonstrates class Invoice’s capabilities


#include <iostream>
using namespace std;

class invoice
{
    int part_no, qty, price;
    string desc;

public:
    invoice()
    {
        part_no = 0;
        desc = "";
        qty = 0;
        price = 0;
    }
    void input()
    {
        cout << "Enter the values part no, description, qty, price \n";
        cin >> part_no >> desc >> qty >> price;
        if (qty < 0)
            qty = 0;
        if (price < 0)
            price = 0;
    }
    void disp()
    {
        cout << "Entered details are \n";
        cout << part_no << " " << desc << " " << qty << " " << price << endl;
    }
    double getInvoiceAmount()
    {
        double amount = qty * price;
        return amount;
    }
};
int main()
{
    invoice obj;
    int choice;
    while (1)
    {
        cout << "\n\n****************************\n";
        cout << "Enter choice 1. Input     2. Display    3. Total amount       4. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            obj.input();
            break;
        case 2:
            obj.disp();
            break;
        case 3:
            cout << obj.getInvoiceAmount();
            break;
        case 4:
            return 0;
        }
    }

    return 0;
}


Output :

***************************
Enter choice 1. Input     2. Display    3. Total amount       4. Exit
1
Enter the values part no, description, qty, price 
23
defected
45
678


****************************
Enter choice 1. Input     2. Display    3. Total amount       4. Exit
2
Entered details are 
23 defected 45 678


****************************
Enter choice 1. Input     2. Display    3. Total amount       4. Exit
 
10. Imagine a tollbooth with a class called TollBooth. The two data items are of type unsigned int and double to hold the total number of cars and total amount of money collected. A constructor initializes both of these data members to 0. A member function called payingCar( )increments the car total and adds 0.5 to the cash total. Another function called nonPayCar( ) increments the car total but adds nothing to the cash total. Finally a member function called display( )shows the two totals. Include a program to test this class. This program should allow the user to push one key to count a paying car and another to count a non paying car. Pushing the ESC key should cause the program to print out the total number of cars and total cash and then exit


#include <iostream>
using namespace std;

class toll
{
private:
    int count = 0;
    float total = 0;

public:
    void payingCar()
    {
        cout << "Paying car passed\n";
        count++;
        total += .5;
    }
    void nonpayingCar()
    {
        cout << "Non Paying car passed\n";
        count++;
    }
    void display()
    {
        cout << "The total count of cars is " << count << endl;
        cout << "The total amount is " << total << endl;
    }
};
int main()
{
    toll obj;
    int choice;

    while (1)
    {
        cout << "\n\n****************************\n";
        cout << "Enter choice 1. paying car     2. Non paying car    3. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            obj.payingCar();
            break;
        case 2:
            obj.nonpayingCar();
            break;
        case 3:
            obj.display();
            return 0;
        }
    }
    return 0;
}


Output :

****************************
Enter choice 1. paying car     2. Non paying car    3. Exit
1
Paying car passed

****************************
Enter choice 1. paying car     2. Non paying car    3. Exit
2
Non Paying car passed

****************************
Enter choice 1. paying car     2. Non paying car    3. Exit
3
The total count of cars is 2
The total amount is 0.5
 
11. Create a class called Time that has separate int member data for hours, minutes and seconds. One constructor should initialize this data to 0, and another should initialize it to fixed values. A member function should display it in 11:59:59 format. A member function named add() should add two objects of type time passed as arguments. A main ( ) program should create two initial-ized values together, leaving the result in the third time variable. Finally it should display the value of this third variable


#include <iostream>
using namespace std;

class mytime
{
    int min, hr, sec;

public:
    mytime()
    {
        min = hr = sec = 0;
    }
    mytime(int x, int y, int z)
    {
        hr = x;
        min = y;
        sec = z;
    }
    void input()
    {
        cout << "Enter min, sec, hr values of time\n";
        cin >> hr >> min >> sec;
    }
    void disp()
    {
        cout << "Displaying time :" << endl;
        cout << hr << ":" << min << ":" << sec << endl;
    }
    mytime add(mytime obj2)
    {
        mytime obj3;
        obj3.hr = hr + obj2.hr;
        obj3.min = min + obj2.min;
        obj3.sec = sec + obj2.sec;

        if (obj3.sec > 59)
        {
            obj3.min = obj3.min + obj3.sec / 60;
            obj3.sec = obj3.sec % 60;
        }

        if (obj3.min > 59)
        {
            obj3.hr = obj3.hr + obj3.min / 60;
            obj3.min = obj3.min % 60;
        }

        if (obj3.hr > 11)
        {
            obj3.hr = obj3.hr % 12;
        }

        return obj3;
    }
};
int main()
{
    mytime obj1(5, 35, 15), obj2, obj3;
    obj2.input();

    obj3 = obj1.add(obj2);
    obj3.disp();

    return 0;
}


Output :

Enter min, sec, hr values of time
4
45
23
Displaying time :
10:20:38
 
12. Create class SavingsAccount. Use a static variable annualInterestRate to store the annual interest rate for all account holders. Each object of the class contains a private instance variable savingsBalance indicating the amount the saver currently has on deposit. Provide method calcu-lateMonthlyInterest() to calculate the monthly interest by multiplying the savingsBalance by an-nualInterestRate divided by 12.This interest should be added tosavingsBalance. Provide a static method modifyInterestRate() that sets the annualInterestRate to a new value. Write a program to test class SavingsAccount. Instantiate two savingsAccount objects, saver1 and saver2, with balances of Rs2000.00 and Rs3000.00, respectively. Set annualInterestRate to 4%, then calculate the monthly interest and print the new balances for both savers. Then set the annualInterestRate to 5%, calculate the next month’s interest and print the new balances for both 
Savers.


#include <iostream>
using namespace std;

class savingAccount
{
    static int rate;
    float balance;

public:
    void input()
    {
        cout << "Enter balance \n";
        cin >> balance;
    }
    void calMonthlyInterest()
    {
        float interest = (balance * rate) / 12.0;
        balance = balance + interest;
    }
    void disp()
    {
        cout << "The balance is : " << balance << endl;
    }
    static void modifyInterest(int x)
    {
        rate = x;
    }
};
int savingAccount ::rate = 4;

int main()
{
    savingAccount saver1, saver2;
    saver1.input();
    saver2.input();

    cout << "Current Rate of interest is 4%\n";
    saver1.calMonthlyInterest();
    saver1.disp();

    saver2.calMonthlyInterest();
    saver2.disp();

    cout << "Setting new interest rate at 5%\n";
    savingAccount::modifyInterest(5);

    cout << "After setting the interest rate at 5%\n";
    saver1.calMonthlyInterest();
    saver1.disp();

    saver2.calMonthlyInterest();
    saver2.disp();

    return 0;
}

Output :

Enter balance 
45000
Enter balance 
23000
Current Rate of interest is 4%
The balance is : 60000
The balance is : 30666.7
Setting new interest rate at 5%
After setting the interest rate at 5%
The balance is : 85000
The balance is : 43444.4
 
13. Create a class Complex having two int type variable named real & img denoting real and imaginary part respectively of a complex number. Overload +, - , == operator to add, to subtract and to compare two complex numbers being denoted by the two complex type objects


#include <iostream>
using namespace std;

class complex
{

    int real, img;

public:
    void input();
    void disp();
    complex operator+(complex obj2);
    complex operator-(complex obj2);
    bool operator==(complex obj2);
};
void complex::input()
{
    cout << "Enter real and img part\n";
    cin >> real >> img;
}

void complex::disp()
{
    cout << "The details of obj are\n";
    cout << "real : " << real << " img: " << img << endl;
}
complex complex::operator+(complex obj2)
{
    complex obj3;
    obj3.real = real + obj2.real;
    obj3.img = img + obj2.img;
    return obj3;
}

complex complex::operator-(complex obj2)
{
    complex obj3;
    obj3.real = real - obj2.real;
    obj3.img = img - obj2.img;
    return obj3;
}

bool complex::operator==(complex obj2)
{
    if (real == obj2.real and img == obj2.img)
    {
        cout << real << obj2.real << img << obj2.img << endl;
        return true;
    }
    else
        return false;
}

int main()
{
    complex obj1, obj2, obj3;
    cout << "Demonstration of +, - and == \n";

    obj1.input();
    obj2.input();

    cout << "Adding objects\n";
    obj3 = obj1 + obj2;
    obj3.disp();

    cout << "Subtracting objects\n";
    obj3 = obj1 - obj2;
    obj3.disp();

    cout << "comparing objects\n";
    if (obj1 == obj2)
    {
        cout << "Objects are equal\n";
    }

    else
    {
        cout << "objects are not equal\n";
    }

    return 0;
}


Output :

Demonstration of +, - and == 
Enter real and img part
56 78
Enter real and img part
12 23
Adding objects
The details of obj are
real : 68 img: 101
Subtracting objects
The details of obj are
real : 44 img: 55
comparing objects
objects are not equal
 
14. Using the concept of operator overloading. Implement a program to overload the following: 
a. Unary – 
b. Unary ++ preincrement, postincrement 
c. Unary -- predecrement, postdecrement


#include <iostream>
using namespace std;

class complex
{

    int real, img;

public:
    void input();
    void disp();

    complex operator-(complex obj2);
    complex operator++();
    complex operator++(int x);
    complex operator--();
    complex operator--(int x);
};
void complex::input()
{
    cout << "Enter real and img part\n";
    cin >> real >> img;
}

void complex::disp()
{
    cout << "The details of obj are\n";
    cout << "real : " << real << " img: " << img << endl;
}

complex complex::operator-(complex obj2)
{
    complex obj3;
    obj3.real = real - obj2.real;
    obj3.img = img - obj2.img;
    return obj3;
}
// preincrement
complex complex::operator++()
{
    real++;
    img++;
    return *this;
}
// post increment
complex complex::operator++(int x)
{
    complex temp;
    temp.real = real;
    temp.img = img;

    real++;
    img++;

    return temp;
}

// pre decrement
complex complex::operator--()
{
    real--;
    img--;
    return *this;
}

// post decrement
complex complex::operator--(int x)
{
    complex temp;
    temp.real = real;
    temp.img = img;

    real--;
    img--;
    return temp;
}

int main()
{
    complex obj1, obj2, obj3;
    cout << "Demonstration of --, pre increment, post increment, pre decrement, post decrement\n";

    obj1.input();
    obj2.input();

    cout << "subtracting objects\n";
    obj3 = obj1 - obj2;
    obj3.disp();

    cout << "Pre Increment objects\n";
    obj3 = ++obj1;
    obj3.disp();

    cout << "Post increment objects\n";
    obj3 = obj1++;
    obj3.disp();

    cout << "Pre decrement objects\n";
    obj3 = --obj1;
    obj3.disp();

    cout << "Post decrement objects\n";
    obj3 = obj1--;
    obj3.disp();

    return 0;
}


Output :

Demonstration of --, pre increment, post increment, pre decrement, post decrement
Enter real and img part
54 67
Enter real and img part
21 32
subtracting objects
The details of obj are
real : 33 img: 35
Pre Increment objects
The details of obj are
real : 55 img: 68
Post increment objects
The details of obj are
real : 55 img: 68
Pre decrement objects
The details of obj are
real : 55 img: 68
Post decrement objects
The details of obj are
real : 55 img: 68







15. Using the concept of operator overloading. Implement a program to overload the following: With the help of friend function 
a. Unary – 
b. Unary ++ preincrement, postincrement
c. Unary -- predecrement, postdecrement


#include <iostream>
using namespace std;

class complex
{

    int real, img;

public:
    void input();
    void disp();

    friend complex operator-(complex obj1, complex obj2);
    friend complex operator++(complex obj1);
    friend complex operator++(complex obj1, int x);
    friend complex operator--(complex obj1);
    friend complex operator--(complex obj1, int x);
};
void complex::input()
{
    cout << "Enter real and img part\n";
    cin >> real >> img;
}

void complex::disp()
{
    cout << "The details of obj are\n";
    cout << "real : " << real << " img: " << img << endl;
}

complex operator-(complex obj1, complex obj2)
{
    complex obj3;
    obj3.real = obj1.real - obj2.real;
    obj3.img = obj1.img - obj2.img;
    return obj3;
}
// preincrement
complex operator++(complex obj1)
{
    obj1.real++;
    obj1.img++;
    return obj1;
}
// post increment
complex operator++(complex obj1, int x)
{
    complex temp;
    temp.real = obj1.real;
    temp.img = obj1.img;

    obj1.real++;
    obj1.img++;

    return temp;
}

// pre decrement
complex operator--(complex obj1)
{
    obj1.real--;
    obj1.img--;
    return obj1;
}

// post decrement
complex operator--(complex obj1, int x)
{
    complex temp;
    temp.real = obj1.real;
    temp.img = obj1.img;

    obj1.real--;
    obj1.img--;
    return temp;
}

int main()
{
    complex obj1, obj2, obj3;
    cout << "Demonstration of --, pre increment, post increment, pre decrement, post decrement\n";

    obj1.input();
    obj2.input();

    cout << "subtracting objects\n";
    obj3 = obj1 - obj2;
    obj3.disp();

    cout << "Pre Increment objects\n";
    obj3 = ++obj1;
    obj3.disp();

    cout << "Post increment objects\n";
    obj3 = obj1++;
    obj3.disp();

    cout << "Pre decrement objects\n";
    obj3 = --obj1;
    obj3.disp();

    cout << "Post decrement objects\n";
    obj3 = obj1--;
    obj3.disp();

    return 0;
}


Output :

Demonstration of --, pre increment, post increment, pre decrement, post decrement
Enter real and img part
98 76
Enter real and img part
21 12
subtracting objects
The details of obj are
real : 77 img: 64
Pre Increment objects
The details of obj are
real : 99 img: 77
Post increment objects
The details of obj are
real : 98 img: 76
Pre decrement objects
The details of obj are
real : 97 img: 75
Post decrement objects
The details of obj are
real : 98 img: 76



