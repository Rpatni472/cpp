Question 17. Create a Base class that consists of private, protected and public data members and member functions. Try using different access modifiers for inheriting Base class to the Derived class and create a table that summarizes the above three modes (when derived in public, protected and private modes) and shows the access specifier of the members of base class in the Derived class.

#include <iostream>

class Base {
private:
    int privateMember;   // Private member
protected:
    int protectedMember; // Protected member
public:
    int publicMember;    // Public member

    Base(int privateVal, int protectedVal, int publicVal)
        : privateMember(privateVal), protectedMember(protectedVal), publicMember(publicVal) {}

    void display() {
        std::cout << "Private: " << privateMember << ", Protected: " << protectedMember
                  << ", Public: " << publicMember << std::endl;
    }
};

class DerivedPublic : public Base {
public:
    // Inherited members maintain their access specifiers
    DerivedPublic(int privateVal, int protectedVal, int publicVal) : Base(privateVal, protectedVal, publicVal) {}
};

class DerivedProtected : protected Base {
public:
    // Inherited members become protected
    DerivedProtected(int privateVal, int protectedVal, int publicVal) : Base(privateVal, protectedVal, publicVal) {}
};

class DerivedPrivate : private Base {
public:
    // Inherited members become private
    DerivedPrivate(int privateVal, int protectedVal, int publicVal) : Base(privateVal, protectedVal, publicVal) {}
};

int main() {
    // Creating objects
    DerivedPublic objPublic(1, 2, 3);
    DerivedProtected objProtected(4, 5, 6);
    DerivedPrivate objPrivate(7, 8, 9);

    // Accessing members using the derived class objects
    // For DerivedPublic, all members are accessible
    std::cout << "DerivedPublic: ";
    objPublic.display();

    // For DerivedProtected and DerivedPrivate, only public members are accessible
    std::cout << "DerivedProtected: ";
    // objProtected.display();  // This would result in a compilation error due to protected access
    std::cout << "DerivedPrivate: ";
    // objPrivate.display();    // This would result in a compilation error due to private access

    return 0;
}
Question 18. You are given three classes A, B and C. All three classes implement their own version of func. In class A, func multiplies the value passed as a parameter by 2. In class B, func multiplies the value passed as a parameter by 3. In class C, func multiplies the value passed as a parameter by 5.You are given class D such that You need to modify the class D and implement the function update_val which sets D's val to new_val by manipulating the value by only calling the func defined in classes A, B and C.It is guaranteed that new_val has only 2, 3 and 5 as its prime factors. Implement class D's function update_val. This function should update D's val only by calling A, B and C's func. Sample Input new_val = 30 Sample Output A's func called 1 times B's func called 1 times C's func called 1 times.
#include <iostream>

class A {
public:
    void func(int &val) {
        val *= 2;
        std::cout << "A's func called 1 times" << std::endl;
    }
};

class B {
public:
    void func(int &val) {
        val *= 3;
        std::cout << "B's func called 1 times" << std::endl;
    }
};

class C {
public:
    void func(int &val) {
        val *= 5;
        std::cout << "C's func called 1 times" << std::endl;
    }
};

class D : public A, public B, public C {
public:
    void update_val(int new_val) {
        // Initialize val with the new_val
        int val = new_val;

        // Call A's func as long as val is divisible by 2
        while (val % 2 == 0) {
            A::func(val);
        }

        // Call B's func as long as val is divisible by 3
        while (val % 3 == 0) {
            B::func(val);
        }

        // Call C's func as long as val is divisible by 5
        while (val % 5 == 0) {
            C::func(val);
        }

        // The updated value is now stored in val
        // You can use it as needed or store it in a member variable.
    }
};

int main() {
    D objD;
    objD.update_val(30);

    return 0;
}
Question 19. Create a class called Student that contains the data members like age, name, enroll_no, marks. Create another class called Faculty that contains data members like facultyName, facultyCode, salary,deptt, age, experience, gender. Create the function display() in both the classes to display the respective information. The derived Class Person demonstrates multiple inheritance. The program should be able to call both the base classes and displays their information. Remove the ambiguity (When we have exactly same variables or same methods in both the base classes, which one will becalled?) by proper mechanism.
#include <iostream>
#include <string>

// Base class for Student
class Student {
public:
    int age;
    std::string name;
    int enroll_no;
    float marks;

    Student(int _age, const std::string& _name, int _enroll_no, float _marks)
        : age(_age), name(_name), enroll_no(_enroll_no), marks(_marks) {}

    void display() {
        std::cout << "Student Information:" << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Enrollment Number: " << enroll_no << std::endl;
        std::cout << "Marks: " << marks << std::endl;
    }
};

// Base class for Faculty
class Faculty {
public:
    std::string facultyName;
    std::string facultyCode;
    float salary;
    std::string deptt;
    int age;
    int experience;
    char gender;

    Faculty(const std::string& _facultyName, const std::string& _facultyCode, float _salary,
            const std::string& _deptt, int _age, int _experience, char _gender)
        : facultyName(_facultyName), facultyCode(_facultyCode), salary(_salary),
          deptt(_deptt), age(_age), experience(_experience), gender(_gender) {}

    void display() {
        std::cout << "Faculty Information:" << std::endl;
        std::cout << "Name: " << facultyName << std::endl;
        std::cout << "Code: " << facultyCode << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Department: " << deptt << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Experience: " << experience << " years" << std::endl;
        std::cout << "Gender: " << gender << std::endl;
    }
};

// Derived class Person demonstrating multiple inheritance
class Person : public Student, public Faculty {
public:
    Person(int _age, const std::string& _name, int _enroll_no, float _marks,
           const std::string& _facultyName, const std::string& _facultyCode, float _salary,
           const std::string& _deptt, int _facultyAge, int _experience, char _gender)
        : Student(_age, _name, _enroll_no, _marks),
          Faculty(_facultyName, _facultyCode, _salary, _deptt, _facultyAge, _experience, _gender) {}

    // Override the display function to avoid ambiguity
    void display() {
        Student::display(); // Call the display function from Student
        std::cout << std::endl;
        Faculty::display(); // Call the display function from Faculty
    }
};

int main() {
    Person person(20, "John", 123, 85.5, "Dr. Smith", "F001", 60000.0, "Computer Science", 35, 10, 'M');
    person.display();

    return 0;
}
Question 20. Implement a real case scenario by a proper C++ code to provide the solution to Diamond Problem in C++
#include <iostream>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "Animal is eating." << std::endl;
    }
};

// Intermediate classes inheriting from Animal
class Mammal : virtual public Animal {
public:
    void breathe() {
        std::cout << "Mammal is breathing." << std::endl;
    }
};

class Bird : virtual public Animal {
public:
    void fly() {
        std::cout << "Bird is flying." << std::endl;
    }
};

// Diamond Problem arises here
class Bat : public Mammal, public Bird {
public:
    void display() {
        std::cout << "Bat can do multiple things:" << std::endl;
        eat();      // Ambiguity due to multiple base classes
        breathe();  // Ambiguity due to multiple base classes
        fly();      // Ambiguity due to multiple base classes
    }
};

int main() {
    Bat bat;
    bat.display();

    return 0;
}
Question 21. Create a base class called shape. Use this class to store two double type values that could be used to compute the area of figures. Derive two specific classes called triangle and rectangle from base shape. Add to the base class, a member function get_data() to initialize base class data members and another member function display_area() to compute and display the area of figures. Make display_area() as a virtual function and redefine this function in the derived class to suit their requirements. Using these three classes, design a program that will accept dimensions of a triangle or a rectangle interactively and display the area. Remember the two values given as input will be treated as lengths of two sides in the case of rectangles and as base and height in the case of triangle and used as follows: Area of rectangle = x * y Area of triangle = ½ *x*y.
#include <iostream>

// Base class
class Shape {
protected:
    double side1;
    double side2;

public:
    // Member function to initialize base class data members
    void get_data() {
        std::cout << "Enter the dimensions of the shape:" << std::endl;
        std::cout << "Side 1: ";
        std::cin >> side1;
        std::cout << "Side 2: ";
        std::cin >> side2;
    }

    // Virtual function to compute and display the area of the shape
    virtual void display_area() const {
        std::cout << "Area of the shape: ";
    }
};

// Derived class for Triangle
class Triangle : public Shape {
public:
    // Redefine the display_area() function for Triangle
    void display_area() const override {
        Shape::display_area();
        double area = 0.5 * side1 * side2;
        std::cout << area << std::endl;
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
public:
    // Redefine the display_area() function for Rectangle
    void display_area() const override {
        Shape::display_area();
        double area = side1 * side2;
        std::cout << area << std::endl;
    }
};

int main() {
    Shape* shapePtr; // Pointer to the base class

    int choice;
    std::cout << "Enter the shape (1 for Triangle, 2 for Rectangle): ";
    std::cin >> choice;

    if (choice == 1) {
        Triangle triangle;
        shapePtr = &triangle;
    } else if (choice == 2) {
        Rectangle rectangle;
        shapePtr = &rectangle;
    } else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    // Get data and display area
    shapePtr->get_data();
    shapePtr->display_area();

    return 0;
}
Question 22. Create a base class called CAL_AREA(Abstract). Use this class to store float type values that could be used to compute the volume of figures. Derive two specific classes called cone, hemisphere and cylinder from the base CAL_AREA. Add to the base class, a member function getdata ( ) to initialize base class data members and another member function display volume( ) to compute and display the volume of figures. Make display volume ( ) as a pure virtual function and redefine this function in the derived classes to suit their requirements. Using these three classes, design a program that will accept dimensions of a cone, cylinder and hemisphere interactively and display the volumes. Remember values given as input will be and used as follows: Volume of cone = (1/3)πr2h Volume of hemisphere = (2/3)πr3 Volume of cylinder = πr2h.
#include <iostream>
#include <cmath>

// Abstract base class
class CAL_AREA {
protected:
    float radius;
    float height;

public:
    // Pure virtual function to compute and display the volume
    virtual void display_volume() const = 0;

    // Member function to initialize base class data members
    void get_data() {
        std::cout << "Enter the dimensions:" << std::endl;
        std::cout << "Radius: ";
        std::cin >> radius;
        std::cout << "Height: ";
        std::cin >> height;
    }
};

// Derived class for Cone
class Cone : public CAL_AREA {
public:
    // Redefine the display_volume() function for Cone
    void display_volume() const override {
        float volume = (1.0 / 3.0) * M_PI * std::pow(radius, 2) * height;
        std::cout << "Volume of Cone: " << volume << std::endl;
    }
};

// Derived class for Hemisphere
class Hemisphere : public CAL_AREA {
public:
    // Redefine the display_volume() function for Hemisphere
    void display_volume() const override {
        float volume = (2.0 / 3.0) * M_PI * std::pow(radius, 3);
        std::cout << "Volume of Hemisphere: " << volume << std::endl;
    }
};

// Derived class for Cylinder
class Cylinder : public CAL_AREA {
public:
    // Redefine the display_volume() function for Cylinder
    void display_volume() const override {
        float volume = M_PI * std::pow(radius, 2) * height;
        std::cout << "Volume of Cylinder: " << volume << std::endl;
    }
};

int main() {
    CAL_AREA* shapePtr; // Pointer to the base class

    int choice;
    std::cout << "Enter the shape (1 for Cone, 2 for Hemisphere, 3 for Cylinder): ";
    std::cin >> choice;

    if (choice == 1) {
        Cone cone;
        shapePtr = &cone;
    } else if (choice == 2) {
        Hemisphere hemisphere;
        shapePtr = &hemisphere;
    } else if (choice == 3) {
        Cylinder cylinder;
        shapePtr = &cylinder;
    } else {
        std::cout << "Invalid choice!" << std::endl;
        return 1;
    }

    // Get data and display volume
    shapePtr->get_data();
    shapePtr->display_volume();

    return 0;
}
Question 23. The task is to debug the existing code to successfully execute all provided test files. You are required to extend the existing code so that it handles the std::invalid_argument exception properly. More specifically, you have to extend the implementation of the process_input function. It takes integer n as an argument and has to work as follows: 1.It calls function largest_proper_divisor(n). 2.If this call returns a value without raising an exception, it should print in a single line result=d where d is the returned value. 3.Otherwise, if the call raises an invalid_argument exception, it has to print in a single line the string representation of the raised exception, i.e., its message. 4.Finally, no matter if the exception is raised or not, it should print in a single line returning control flow to the caller after any other previously printed output. Input Format The input is read by the provided locked code template. In the only line of the input, there is a single integer n, which is going to be the argument passed to function process input. Output Format The output should be produced by the function process_input as described in the statement. Sample Input 0 Sample Output the largest proper divisor is not defined for n=0 returning control flow to the caller Explanation 1 In the first sample, n = 0, so the call largest_proper_divisor(0) raises an exception. In this case, the function process_input prints two lines. In the first of them, it prints the string representation of the raised exception, and in the second line, it prints returning control flow to the caller. Sample Input 9 Sample Output result=3.
#include <iostream>
#include <stdexcept>

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw std::invalid_argument("the largest proper divisor is not defined for n=0");
    }

    for (int i = n / 2; i > 0; --i) {
        if (n % i == 0) {
            return i;
        }
    }

    return 1; // If n is a prime number
}

void process_input(int n) {
    try {
        int result = largest_proper_divisor(n);
        std::cout << "result=" << result << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cout << e.what() << std::endl;
    } catch (...) {
        // Handle other exceptions if needed
    }

    std::cout << "returning control flow to the caller" << std::endl;
}

int main() {
    int n;
    std::cin >> n;
    process_input(n);

    return 0;
}
Question 24. Templates are the foundation of generic programming, which involves writing code in a way that is independent of any particular type. Write a program that can create a list (create a class list) of given type (int, float, char etc.) and perform insertion and deletion on list object.
#include <iostream>

// Node class to represent each element in the list
template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

// List class using templates
template <typename T>
class List {
private:
    Node<T>* head;

public:
    List() : head(nullptr) {}

    // Function to insert a new element at the end of the list
    void insert(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to delete an element from the list
    void remove(T val) {
        Node<T>* current = head;
        Node<T>* prev = nullptr;

        while (current != nullptr && current->data != val) {
            prev = current;
            current = current->next;
        }

        if (current == nullptr) {
            std::cout << "Element not found in the list." << std::endl;
            return;
        }

        if (prev == nullptr) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
    }

    // Function to display the elements in the list
    void display() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a list of integers
    List<int> intList;
    intList.insert(10);
    intList.insert(20);
    intList.insert(30);
    intList.display();

    // Create a list of characters
    List<char> charList;
    charList.insert('A');
    charList.insert('B');
    charList.insert('C');
    charList.display();

    // Create a list of floats
    List<float> floatList;
    floatList.insert(3.14);
    floatList.insert(6.28);
    floatList.display();

    // Delete an element from the integer list
    intList.remove(20);
    intList.display();

    return 0;
}
s