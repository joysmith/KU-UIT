| feature                           | feature                  |
| --------------------------------- | ------------------------ |
| 1. [Getting Started with C++](#1) | 4. [Decision Making](#4) |
| 2. [Basics feature](#2)           | 5. [Loops](#5)           |
| 3. [Fundamental Data Types](#3)   | 6. [Functions](#6)       |

---

## C++ <a id="1"></a>

1.  [Getting Started with C++](#01)
2.  [Introduction to C++](#02)
3.  [Popular IDEs](#03)
4.  [Your First C++ Program](#04)
5.  [Compiling and Running a C++ Program](#05)
6.  [Changing the Theme](#06)

---

## Basic <a id="2"></a>

7.  [Basics Introduction](#07)<a id="2"></a>
8.  [Variables](#08)
9.  [Constants](#09)
10. [Naming Conventions](#010)
11. [Mathematical Expressions](#011)
12. [Order of Operators](#012)
13. [Writing Output to the Console](#013)
14. [Reading from the Console](#014)
15. [Working with the Standard Library](#015)
16. [Comments](#016)

---

## Data Types <a id="3"></a>

17. [Fundamental Data Types Introduction](#017)<a id="3"></a>
18. [Fundamental Data Types](#018)
19. [Initializing Variables](#019)
20. [Working with Numbers](#020)
21. [Narrowing](#021)
22. [Generating Random Numbers](#022)
23. [Formatting Output](#023)
24. [Data Types Size and Limits](#024)
25. [Working with Booleans](#025)
26. [Working with Characters and Strings](#026)
27. [Working with Arrays](#027)
28. [Type Conversion](#028)

---

## Decision Making <a id="4"></a>

29. [Decision Making Introduction](#029)<a id="4"></a>
30. [Comparison Operators](#030)
31. [Logical Operators](#031)
32. [Order of Logical Operators](#032)
33. [If Statements](#033)
34. [Nested If Statements](#034)
35. [The Conditional Operator](#035)
36. [The Switch Statement](#036)

---

## Loops <a id="5"></a>

37. [Loops Introduction](#037)<a id="5"></a>
38. [The for Loop](#038)
39. [Range-based for Loops](#039)
40. [While Loops](#040)
41. [Do-while Loops](#041)
42. [Break and Continue Statements](#042)
43. [Nested Loops](#043)

---

## Functions <a id="6"></a>

44. [Functions Introduction](#044)<a id="6"></a>
45. [Defining and Calling Functions](#045)
46. [Parameters with a Default Value](#046)
47. [Overloading Functions](#047)
48. [Passing Arguments by Value or Reference](#048)
49. [Local vs Global Variables](#049)
50. [Declaring Functions](#050)
51. [Organizing Functions in Files](#051)
52. [Using Namespaces](#052)
53. [Debugging C++ Programs](#053)

---

### 1. Getting Started with C++<a id="01"></a>

### 2. Introduction to C++<a id="02"></a>

Application of C++:

1. High performance applications
1. Video games
1. Device drivers
1. Web Browsers
1. Servers
1. Operating Systems

General info:

- Every 3 year new version comes up the latest version this time is 2023

- Other language influenced by C++ : C#, Java, JS, TS, Dart

To master C++ you need to master two things:

- C++ language: means syntax the grammar of this language.
- C++ standard library: collection of pre-written code.

### 3. Popular IDEs<a id="03"></a>

- [Clion](https://www.jetbrains.com/clion/)
- [Visual Studio Community edition](https://visualstudio.microsoft.com/vs/community/)
- [Vs code](https://code.visualstudio.com/download)
- [Eclipse](https://www.eclipse.org/downloads/)

Compiler for Vs-code

- [Gnu compiler](https://sourceforge.net/projects/mingw/)
- [Clang compiler](https://releases.llvm.org/download.html)

### 4. Your First C++ Program<a id="04"></a>

Open Clion-> New Project-> C++ executable

- specify project location name it "HelloWorld"
- language standard: C++20
- click green play button to run code.

```cpp
#include <iostream>

int main() {
    // statement terminated with semicolon
    std::cout << "Hello, World!" << std::endl;

    // tells OS that or program executed successfully
    return 0;
}


/* output
Hello, World!
*/
```

cout: character out  
cin: character in

### 5. Compiling and Running a C++ Program<a id="05"></a>

To run code first we compile source code into machine code, that can be run by the computer OS

The machine code is basically the native language that a computer Operating system understand and its different from Operating system to another  
which means window, Mac, linux has different executable

### 6. Changing the Theme<a id="06"></a>

Go to File ->settings -> Appearance & Behavior -> appearance -> Theme -> get more theme => Monokai Pro

### 7. Summary

- C++ is one of the oldest yet most popular programming languages in the world due to
  its performance and efficiency.
- It’s often used in building performance-critical applications, video games (especially
  with Unreal Engine), servers, operating systems, etc.
- To learn C++, you need to learn the syntax (grammar) of the language as well as C++
  Standard Library, which is a collection of pre-written C++ code for solving common
  problems.
- To write C++ applications, we often use an Integrated Development Environment
  (IDE). The most popular IDEs are MS Visual Studio, XCode, and CLion.
- To run C++ applications, first we have to compile our C++ code to machine code.
  -The main() function is the starting point of a C++ program.

---

# The Basics feature

### 1. Introduction<a id="07">

Objectives

- variable and constant
- naming conventions
- mathematical expressions
- writing to and reading from the console
- working with the standard library
- comments

### 2. Variables<a id="08"></a>

<img src="notes/assignment.jpg" width="700">

We use variable to temporarily store data in computer memory, technically a variable is name of location in the memory where we store some value because some value can change we refer to this location as variable.

information: store, access, modify

```cpp
#include <iostream>
using namespace std;

int main() {
    // approach 1: declaring variable then initializing
    int audio_file_size;
    audio_file_size = 100;

    // approach 2: combine two statements in single line -declaration & initialization
    int image_file_size = 5;

    cout << image_file_size;
    return 0;
}
```

### 3. Constants<a id="09"></a>

When we don't want value of variable to change we use constant

```cpp
#include <iostream>
using namespace std;

int main() {
    // How to use constant
    const double pi = 3.14;

    cout << pi;
    return 0;
}
```

### 4. Naming Conventions<a id="010"></a>

```cpp
#include <iostream>
using namespace std;

int main() {

    // Camel Case
    int myFileSize = 12;

    // Snake Case
    int my_file_size = 14;

    // Pascal Case
    int MyFileSize = 13;

    return 0;
}
```

### 5. Mathematical Expressions<a id="011"></a>

<img src="notes/arthimetic.jpg" width="700">

Example 1:

```cpp
#include <iostream>
using namespace std;

int main() {

    int x = 5;
    int y = 10;

    // operator +, -, /, *
    // operands x y on which we are performing operations using operator
    int z = x + y;

    cout << z;

    return 0;
}

```

---

Example 2:

```cpp
#include <iostream>
using namespace std;

int main() {

    double x = 10;
    double y = 3;

    // operator +, -, /, *
    // operands x y
    double z = x / y;

    cout << z;

    return 0;
}
```

---

Postfix

```cpp
#include <iostream>
using namespace std;

int main() {

    int x = 10;
// first store x value in y then increment by 1
    int y = x ++;
    cout << "x: " << x << endl;
    cout << "y: " << y ;
    return 0;
}

/* output
x: 11
y: 10
*/

```

---

Prefix

```cpp
#include <iostream>
using namespace std;

int main() {

    int x = 10;
// first increment x by 1 then store value in y
    int y = ++x;
    cout << "x: " << x << endl;
    cout << "y: " << y ;
    return 0;
}

/* output
x: 11
y: 11
*/

```

### 6. Order of Operators<a id="012"></a>

```cpp
#include <iostream>
using namespace std;

int main() {
// PEMDAS math rule
// priority: (), * and /, + and  -
    double x = 1 + 2 * 5;
    cout << "X: " << x;

    return 0;
}

/* output
X: 11
*/
```

---

using () parenthesis to change priority

```cpp
#include <iostream>
using namespace std;

int main() {
// priority: (), * and /, + and  -
    double x = 10;
    double y = 5;
    double z = (x + 10) / (3 * y);

    cout << "z: " << z;

    return 0;
}

/* output
z: 1.33333
*/
```

### 7. Writing Output to the Console<a id="013"></a>

"<<" stream insertion operator: It is an operator for inserting something to our output stream

"cout" is an object that represent standard output stream

In programming a stream represent sequence of character.

The standard output is our console or terminal window, so using cout we can write a sequence of character on standard output which is our standard window or terminal

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;

// single statement
    cout << x;

// combining statement into single statement by chaining multiple string insertion operators
    cout << "x: " << x;

    return 0;
}

/* output
10x: 10
*/
```

---

endl: end of line

```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int y = 20;

// How to move in next line using "endl" manipulator
    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}

/* output
x: 10
y: 20
*/
```

### 8. Reading from the Console<a id="014"></a>

">>" string extraction operator

cin: reading data from console.

```cpp

#include <iostream>
using namespace std;

int main() {
    cout << "Enter a value: ";
    int value;

// ">>" string extractor operator
// reading data from console and putting it in value variable
    cin >> value;

// How to move in next line using "endl" manipulator
    cout << "value: " << value << endl;

    return 0;
}

/* output
Enter a value: 7
value: 7
*/
```

---

Example to read float/decimal value from console

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Enter a value for x and y: " << endl;
    double x;
    double y;

    cin >> x;
    cin >> y;

    cout << "sum is: " << x + y;

    return 0;
}

/* output
Enter a value for x and y:
55
22
sum is: 77
*/

```

---

Chaining string extraction operator

```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Enter a value for x and y: " << endl;
    double x;
    double y;

// chaining string extraction operator
    cin >> x >> y;

    cout << "sum is: " << x + y;

    return 0;
}

/* output
Enter a value for x and y:
2
5
sum is: 7
*/
```

### 9. Working with the Standard Library<a id="015"></a>

math library i.e cmath

[floor function usage ref](https://cplusplus.com/reference/cmath/floor/)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
// the floor() function takes 1 args/input
// the floor() function return double
    double result = floor(1.3);

    cout << "result: " <<result;

    return 0;
}

/* output
result: 1
*/
```

---

[pow function usage ref](https://cplusplus.com/reference/cmath/pow/)

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
// 2^3: 2 to the power of 3
// 2 x 2 x 2 = 8
// the pow() function takes 2 args/inputs: one is the base and another one as exponent/power
    double result = pow(2, 3);

    cout << "result: " <<result;

    return 0;
}

/* output
result: 8
*/
```

### 10. Comments<a id="016"></a>

Comment: To clarify our code, To make code more understandable, they are ignored by compiler which means they are not compiled by compiler

comment always Why & How, not what

```cpp
#include <iostream>

using namespace std;

int main() {
// Single line comment

/*
M
u
l
t
i
l
i
n
e

c
o
m
m
e
n
t
*/

// ❌ (What)  declaring and initialing x with value 7
    int x = 7;
    return 0;
}
```

<br>

# Fundamental Data Types

### 11. Introduction<a id="017"></a>

Objectives

- Built-in type
- numbers
- boolean values
- character and strings
- arrays

### 12. Fundamental Data Types<a id="018"></a>

c++ is statically typed language:  
When we declare a variable we need to specify its type and this type could not change, through the lifetime of our program  
other language resemble same feature: c++, java, C#, Type script

Dynamically typed language:  
Python, Javascript, Ruby: These language we don't have to give our variable a particular type like int, boolean, string, bool etc, The type will be determined based on the value that we will assign to this variable and that type can change throughout the life time of out program

> Whole number

| Type      | Bytes |           range |
| :-------- | :---: | --------------: |
| short     |   2   | -32768 to 32767 |
| int       |   4   |       -2B to 2B |
| long      |   4   |       -2B to 2B |
| long long |   8   |                 |

---

<br>

> Decimal number

| Type        | Bytes |                range |
| :---------- | :---: | -------------------: |
| float       |   4   |                      |
| double      |   8   |  -1.7E308 to 1.7E308 |
| long double |   8   | -3.4E932 to 1.7E4832 |

---

| Type | Bytes |      range |
| :--- | :---: | ---------: |
| bool |   1   | true/false |
| char |   1   |      ascii |

### 13. Initializing Variables<a id="019"></a>

Why we write f/F or l/L after value as suffix ?  
To force compiler to take as long or float, we write f/F or l/L at the end of value in uppercase or lowercase

```cpp

#include <iostream>

using namespace std;

int main() {
    float interestRate = 3.67f;
    float newInterestRate = 3.67F;
    double price = 99.9;
    long movieSize = 1'000'000l;
    long audioSize = 1000000L;
    bool isGameOVer = false;

    return 0;
}

```

---

auto keyword: using auto keyword compiler know data type because of f/F, l/L, false, "c" etc otherwise it will set type in default like int, double

```cpp
#include <iostream>

using namespace std;

int main() {
// compile will take type as float
    auto interestRate = 3.67f;
    auto newInterestRate = 3.67F;

// compile will take type as double
    auto price = 99.9;

// compile will take type as long
    auto movieSize = 1000000l;
    auto audioSize = 1000000L;

// compile will take type as bool
    auto isGameOVer = false;

// compile will take type as char
    auto letter = "j";

    return 0;
}
```

---

{} brace initializer: this will set value to 0 when empty, instead of any garbage value

```cpp
#include <iostream>

using namespace std;

int main() {
// brace initialized when empty, default value will be 0
    int number {};

// brace initialized with value
    int number2 {7};

    cout << "default value: "<< number << endl;
    cout << "initialize value: "<< number2;

    return 0;
}


/* output
default value: 0
initialize value: 7
*/
```

### 14. Working with Numbers<a id="020"></a>

| System                |  Digits  | Example |
| :-------------------- | :------: | ------: |
| Decimal (Base 10)     |   0-9    |     255 |
| Binary (Base 2)       |   0-1    |  111111 |
| Hexadecimal (Base 16) | 0-9, A-F |      FF |

```cpp
#include <iostream>

using namespace std;

int main() {
// decimal number system
    int number = 255;

// binary number system
    int numberBinary = 0b11111111;

// hexadecimal number system
    int numberHexa = 0xff;

    cout << "number: "<< number << endl;
    cout << "numberBinary: "<< numberBinary << endl;
    cout << "numberHexa: "<< numberHexa << endl;

    return 0;
}


/* output
number: 255
numberBinary: 255
numberHexa: 255
*/

```

### 15. Narrowing<a id="021"></a>

Narrowing : when we initialize variable of smaller type using a larger type  
int is larger type --> short is smaller type

```cpp

#include <iostream>

using namespace std;

int main() {
    int number = 1'000'000;
// narrowing conversion cause data loss
    short another = number;

    cout << "another: "<< another << endl;

    return 0;
}



/* output
number: 16960
*/
```

### 16. Generating Random Numbers<a id="022"></a>

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    long elapsedSeconds = time(0);
    srand(elapsedSeconds);
    // 10 is set as upper-limit
    // you can change to 100 to get value from 1-99
    int number = rand() % 10;
    cout << number;

    return 0;
}


/* output
9
*/
```

### 17. Formatting Output<a id="023"></a>

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout << "Spring" << "Nice" << endl
         << "Summer" << "Hot"  << endl;

    // How to organize data in form of column and right align(default)
    cout << setw(10) << "Spring" << setw(10) << "Nice" << endl
         << setw(10) << "Summer" << setw(10) << "Hot" << endl;

    // 1 Approach: How to organize data in form of column and left align
    cout << left << setw(10) << "Spring" << setw(10) << "Nice" << endl
                 << setw(10) << "Summer" << setw(10) << "Hot" << endl;

    // 2 Approach: How to organize data in form of column and left align
    cout << left;
    cout << setw(10) << "Spring" << setw(10) << "Nice" << endl
         << setw(10) << "Summer" << setw(10) << "Hot" << endl;


    // How to print number in fixed point notation
    cout << fixed << 12.34567 << endl;

    // How to print number in fixed point notation with 2 digit precision
    cout << fixed << setprecision(2)<< 12.34567 << endl;

    // trailing zeroes
    cout << fixed << setprecision(10)<< 12.34567 << endl;

    //

    return 0;
}


/* output
SpringNice
SummerHot
    Spring      Nice
    Summer       Hot
Spring    Nice
Summer    Hot
Spring    Nice
Summer    Hot
12.345670
12.35
12.3456700000
*/

```

### 18. Data Types Size and Limits<a id="024"></a>

Data type size in bytes on your machine

```cpp
#include <iostream>

using namespace std;

int main() {

    // size in bytes of data type in this machine
    cout << "short " << sizeof(short) << endl;
    cout << "int " << sizeof(int) << endl;
    cout << "long " << sizeof(long) << endl;

    cout << "float " << sizeof(float) << endl;
    cout << "double " << sizeof(double) << endl;

    cout << "char " << sizeof(char) << endl;
    cout << "bool " << sizeof(bool) << endl;

    cout << "unsigned short " << sizeof(unsigned short) << endl;
    cout << "unsigned int " << sizeof(unsigned int) << endl;
    cout << "unsigned long " << sizeof(unsigned long) << endl;
    cout << "unsigned char " << sizeof(unsigned char) << endl;
    return 0;
}


/* output
short 2
int 4
long 4
float 4
double 8
char 1
bool 1
unsigned short 2
unsigned int 4
unsigned long 4
unsigned char 1
*/

```

---

How to get maximum and minimum limit a data type can store

```cpp
#include <iostream>
#include <limits>

using namespace std;

int main()
{
    cout << "short lowest: " << numeric_limits<short>::lowest() << endl
         << "short min: " << numeric_limits<short>::min() << endl
         << "short max: " << numeric_limits<short>::max() << endl;

    cout << "int lowest: " << numeric_limits<int>::lowest() << endl
         << "int min: " << numeric_limits<int>::min() << endl
         << "int max: " << numeric_limits<int>::max() << endl;

    cout << "long lowest: " << numeric_limits<long>::lowest() << endl
         << "long min: " << numeric_limits<long>::min() << endl
         << "long max: " << numeric_limits<long>::max() << endl;

    cout << "float lowest: " << numeric_limits<float>::lowest() << endl
         << "float min: " << numeric_limits<float>::min() << endl
         << "float max: " << numeric_limits<float>::max() << endl;

    cout << "double lowest: " << numeric_limits<double>::lowest() << endl
         << "double min: " << numeric_limits<double>::min() << endl
         << "double max: " << numeric_limits<double>::max() << endl;

    cout << "bool lowest: " << numeric_limits<bool>::lowest() << endl
         << "bool min: " << numeric_limits<bool>::min() << endl
         << "bool max: " << numeric_limits<bool>::max() << endl;

    cout << "char lowest: " << numeric_limits<char>::lowest() << endl
         << "char min: " << numeric_limits<char>::min() << endl
         << "char max: " << numeric_limits<char>::max() << endl;

    cout << "unsigned char lowest: " << numeric_limits<unsigned char>::lowest() << endl
         << "unsigned char min: " << numeric_limits<unsigned char>::min() << endl
         << "unsigned char max: " << numeric_limits<unsigned char>::max() << endl;

}

/* output
short lowest: -32768
short min: -32768
short max: 32767
int lowest: -2147483648
int min: -2147483648
int max: 2147483647
long lowest: -2147483648
long min: -2147483648
long max: 2147483647
float lowest: -3.40282e+38
float min: 1.17549e-38
float max: 3.40282e+38
double lowest: -1.79769e+308
double min: 2.22507e-308
double max: 1.79769e+308
bool lowest: 0
bool min: 0
bool max: 1
char lowest: Ç
char min: Ç
char max: ⌂
unsigned char lowest:
unsigned char min:
unsigned char max:  
*/
```

---

Overflowing: if a value do not store in a type and too large for the type then the value will wrap around its minimum type this is called overflowing

```cpp
#include <iostream>

using namespace std;

#include <limits>

int main()
{
    // storing maximum number, integer can hold
    int number = numeric_limits<int>::max();
    // increasing number by one, which will cause integer overflowing
    number++;
    cout << number;
}

/* output
-2147483648
*/

```

---

Integer overflow Vs Integer underflow

```cpp
#include <iostream>

using namespace std;

#include <limits>

int main()
{
    // integer overflow
    int numberMax = numeric_limits<int>::max();
    numberMax++;
    cout << "Integer overflow " << numberMax << endl;

    // integer underflow
    int numberMin = numeric_limits<int>::min();
    numberMin--;
    cout << "Integer underflow " << numberMin << endl;
}

/* output
Integer overflow -2147483648
Integer underflow 2147483647
*/

```

### 19. Working with Booleans<a id="025"></a>

sticky manipulator: once you applied you will receive all value of the same type for instance boolalpha gives you false

```cpp
#include <iostream>

using namespace std;

int main() {
    bool isNewUser = false;
    cout << "isNewUser: " << isNewUser << endl;

// using sticky string boolalpha manipulator
// after this all boolean value display as false instead of 0
    cout << boolalpha << "isNewUser: " << isNewUser;

    return 0;
}



/* output
isNewUser: 0
isNewUser: false
*/
```

### 20. Working with Characters and Strings<a id="026"></a>

Example Character

```cpp
#include <iostream>

using namespace std;

int main() {
    char ch = 'a';

// dispaly character
    cout << ch << endl;

// How to display ascii character code
    cout << +ch << endl;

// ❌BAD practise: using ascii code for initialization
    char newch = 98;
    cout << ch;

    return 0;
}



/* output
a
97
a
*/
```

---

1. Example String

```cpp
#include <iostream>

using namespace std;

int main() {
    string movie = "Spider Man";
    cout << movie << endl;

// reading string from terminal without space
    string name;
    cout << "Enter your full name with space: ";
    cin >> name;
    cout << "Hi " << name;

    return 0;
}


/* output
Spider Man
Enter your full name with space: Gta san andreas
Hi Gta
*/
```

---

2. Example String

```cpp
#include <iostream>

using namespace std;

int main() {

// reading string from terminal with space
    string name;
    cout << "Enter your full name with space: ";
    getline(cin, name);
    cout << "Hi " << name;

    return 0;
}



/* output
Enter your full name with space: Tony stark
Hi Tony stark
*/
```

### 21. Working with Arrays<a id="027"></a>

```cpp
#include <iostream>

using namespace std;

int main()
{
    int numbers[5];
    // print address of numbers array
    cout << numbers << endl;

    // print element exist in index of 0
    cout << numbers[0] << endl;

    // print element exist in index of 1
    cout << numbers[1] << endl;

    // how to change value of array
    numbers[1] = 10;
    cout << numbers[1] << endl;

    // How to initalize array using braces
    string  names[5] = {"joy", "smith", "james", "jenny"};
    cout << names[1] << endl;

    return 0;
}

/* output
0x26b63ffb40
753532928
32759
10
smith
*/

```

### 22. Type Conversion<a id="028"></a>

Implicit or automatic conversion of data by compiler

```cpp
#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    double y = 2.2;
    // the compiler will automatically convert int into double
    double z = x + y;
    cout << z << endl;

    return 0;
}

/* output
3.2
*/

```

---

Explicit/Manually conversion of data by compiler

```cpp
#include <iostream>

using namespace std;

int main()
{
    int x = 1;
    double y = 2.26987;
    // 1 Approach C style casting
    // the compiler will manually convert double into int
    // explicit/manually conversion
    int z = x +  (int) y;
    cout << z << endl;


    int p = 1;
    double q = 5.7854492;
    // 2 Approach C++ style casting
    // the compiler will manually convert double into int
    // explicit/manually conversion
    int r = p +  static_cast<int>(q);
    cout << r << endl;

    return 0;
}

/* output
3
6
*/

```

<br>

# Decision Making

### 23. Introduction<a id="029"></a>

Objectives

- comparison operator
- logical operator
- if statement
- switch statement
- conditional operator

### 24. Comparison Operators<a id="030"></a>

<img src="notes/comparisonORrelational.png" width="700">

We use comparison operator for comparing values

boolean expression: a piece of code that produce boolean value

```cpp
#include <iostream>

using namespace std;

int main() {

    int x = 10;

// boolean expression:  a piece of code that produce boolean value

    bool result = x != 5;
    cout << boolalpha << result;
    return 0;
}



/* output
Enter your full name with space: Tony stark
Hi Tony stark
*/

```

---

Comparison of two value of different type int vs double.  
The compiler automatically cast or convert int into double so it can perform the comparison.  
The compiler will automatically convert value from small precise type to big precise type.

```cpp
#include <iostream>

using namespace std;

int main() {

    int x = 10;
    double y = 5;

// boolean expression:  a piece of code that produce boolean value
    bool result = x == y;

    cout << boolalpha << result;
    return 0;
}


/* output
false
*/

```

---

Example Character comparison

```cpp
#include <iostream>

using namespace std;

int main() {

    char first = 'j';
    char second = 'J';

    bool result = first == second;

    cout << boolalpha << result;
    return 0;
}


/* output
false
*/

```

### 25. Logical Operators<a id="031"></a>

<img src="notes/logical.jpg" width="700">

We use logical operator for combining two or more boolean expression for condition

```cpp
#include <iostream>

using namespace std;

int main() {

    int age = 20;
    bool isEligible = age > 18 && age << 65;
// bool isEligible = age > 18 || age << 65;

    cout << boolalpha << isEligible;
// cout << boolalpha << !isEligible;

    return 0;
}


/* output
true
*/
```

---

Using () for readability

```cpp
#include <iostream>

using namespace std;

int main() {

    int age = 20;
    int salary = 50'000;


    bool isEligible = (age > 18 && age << 65) && (salary > 3000);
// bool isEligible = (age > 18 && age << 65) || (salary > 3000);

    cout << boolalpha << isEligible;

    return 0;
}



/* output
true
*/
```

### 26. Order of Logical Operators<a id="032"></a>

```cpp
#include <iostream>

using namespace std;

int main() {

// priority: (),  !,  &&,  ||
    bool a = true;
    bool b = false;
    bool c = false;

// first ! will evaluate
// then && will evaluate
    bool result = b && !a;

    cout << boolalpha << result;

    return 0;
}


/* output
false
*/
```

---

2 Example

```cpp
#include <iostream>

using namespace std;

int main() {

// priority: (),  !,  &&,  ||
    bool a = true;
    bool b = false;
    bool c = false;

// first && will evaluate
// then || will evaluate
    bool result = a || b && c;

    cout << boolalpha << result;

    return 0;
}


/* output
true
*/
```

---

using parenthesis for better readability and changing priority

```cpp
#include <iostream>

using namespace std;

int main() {

// priority: (),  !,  &&,  ||
    bool a = true;
    bool b = false;
    bool c = false;

// first () will evaluate
// then && will evaluate
    bool result = (a || b) && c;

    cout << boolalpha << result;

    return 0;
}


/* output
false
*/
```

### 27. If Statements<a id="033"></a>

we use if statement to control logic of our program

```cpp
#include <iostream>

using namespace std;

int main() {

    int temperature = 70;

    if(temperature < 60){
        cout << "cold";
        cout << "wear warm cloth";
    }else if(temperature < 90){
        cout << "Nice";
    }else{
        cout << "Hot";
    }

    return 0;
}


/* output
Nice
*/
```

### 28. Nested If Statements<a id="034"></a>

when we code one if statement in another if statement this is called nested if statements

```cpp
#include <iostream>

using namespace std;

int main() {

    short tuition = 0;
    bool isCitizen = true;
    bool InResident = true;

    if(isCitizen){

        // inner/nested if statement
        if(InResident)
            tuition = 0;
        else
            tuition = 1000;
    }
    else
        tuition = 3000;

    return 0;
}



```

### 29. The Conditional Operator<a id="035"></a>

We have conditional operator

```cpp
#include <iostream>

using namespace std;

int main() {

// 1 approach: using conditional operator
    int sales = 11'000;
    double commission = (sales > 10'000)? 0.11 : 0.05 ;


// 2 approach:  using if statement
    if(sales > 10'000)
        commission = 0.11;
    else
        commission = 0.05;

    cout << commission;

    return 0;
}


/* output
0.11
*/
```

### 30. The Switch Statement<a id="036"></a>

Implementation using if statement

```cpp
#include <iostream>

using namespace std;

int main() {

    cout  << "1 - Create account" << endl
          << "2 - Change password" << endl
          << "3 - Quit" << endl
          << "select an option: " << endl;


    short input;
    cin >> input;

    if(input == 1)
        cout << "You selected 1";
    else if (input == 2)
        cout << "You selected 2";
    else
        cout << "Goodbye!!!";

    return 0;
}


/* output
1 - Create account
2 - Change password
3 - Quit
select an option:
1
You selected 1
*/
```

---

Implementation using switch statement

```cpp
#include <iostream>

using namespace std;

int main() {

    cout  << "1 - Create account" << endl
          << "2 - Change password" << endl
          << "3 - Quit" << endl
          << "select an option: " << endl;


    short input;
    cin >> input;

    switch(input){
        case 1:
            cout << "You selected 1";
            break;
        case 2:
            cout << "You selected 2";
            break;
        default:
            cout << "Goodbye";
    }

    return 0;
}



/* output
1 - Create account
2 - Change password
3 - Quit
select an option:
2
You selected 2
*/
```

<br>

# Loops

### 31. Introduction<a id="037"></a>

Objectives

- for loops
- ranged based for loop
- while loop
- do-while loop
- break & continue statements

### 32. The for Loop<a id="038"></a>

Example simple for loop

```cpp
#include <iostream>

using namespace std;

int main() {

    for(int i = 0; i <= 5; i++){
        cout << i << endl;
    }

    return 0;
}


/* output
0
1
2
3
4
5
*/

```

---

Example for loop with logic

```cpp
#include <iostream>

using namespace std;

int main() {

    for(int i = 5; i > 0; i--){
        if(i%2 !=0)
            cout << i << endl;
    }

    return 0;
}


/* output
5
3
1
*/
```

### 33. Range-based for Loops<a id="039"></a>

Example simple for loop on array

```cpp
#include <iostream>

using namespace std;

int main() {

    int numbers[] = {1, 2, 3};

// size of numbers: 16 bytes
// size of int: 4 bytes

    for(int i = 0; i < sizeof(numbers)/sizeof(int); i++){
        cout << numbers[i] << endl;
    }

    return 0;
}


/* output
1
2
3
*/
```

---

Example Ranged based for loop on array

```cpp
#include <iostream>

using namespace std;

int main() {

    int numbers[] = {1, 2, 3};

// size of numbers: 16 bytes
// size of int: 4 bytes

    for(int number : numbers){
        cout << number << endl;
    }

    return 0;
}


/* output
1
2
3
*/
```

---

Example Ranged based for loop on string

```cpp
#include <iostream>

using namespace std;

int main() {

    string name = "joy peter";

    for(char ch:name)
        cout << ch << endl;

    return 0;
}


/* output
j
o
y

p
e
t
e
r

*/
```

### 34. While Loops<a id="040"></a>

Example simple for loop

- when we know how many times we want to repeat, we use for loop.

```cpp
#include <iostream>

using namespace std;

int main() {


    for(int i = 1; i <= 5; i++)
        cout << i << endl;

    return 0;
}


/* output
1
2
3
4
5
*/
```

---

Example while loop

- when we don't know how many times we want to repeat ahead of times

```cpp
#include <iostream>

using namespace std;

int main() {

    int i = 1;
    while(i < 5){
        cout << i << endl;
        i++;
    }

    return 0;
}



/* output
1
2
3
4
*/
```

---

2 Example

```cpp
#include <iostream>

using namespace std;

int main() {

    int number  = 0;

    while(number < 1 || number > 5){
        cout << "Number: ";
        cin >> number;

        if(number < 1 || number > 5){
            cout << "Enter a number between 1-5 to get exit from loop" << endl;
        }
    }

    return 0;
}



/* output
Number:7
 Enter a number between 1-5 to get exit from loop
Number:8
 Enter a number between 1-5 to get exit from loop
Number:32
3
4
*/
```

### 35. Do-while Loops<a id="041"></a>

```cpp
#include <iostream>

using namespace std;

int main() {

    int number;

    do{
        cout << "Number: ";
        cin >> number;
    }// enter number 1-5 to terminate program
    while(number < 1 || number > 5);

    return 0;
}



/* output
 Number:0
 Number:9
 Number:15
 Number:3
*/




/* output
Number:2
*/

```

### 36. Break and Continue Statements<a id="042"></a>

loops tool-  
break: to break out of a loop
continue: to skip an iteration

```cpp
#include <iostream>

using namespace std;

int main() {

    for(int i=1; i<=5; i++){
        if(i%3==0)
            continue;
        // break:
        cout << i << endl;
    }

    return 0;
}

```

### 37. Nested Loops<a id="043"></a>

<br>

# Functions

### 38. Introduction<a id="044"></a>

Objectives

- Define and call function
- Assign parameters a default value
- Overload functions
- Pass arguments by value or reference
- Local vs global variables
- Organize functions in different files

### 39. Defining and Calling Functions<a id="045"></a>

1. Function without input

```cpp
#include <iostream>
using namespace std;

// Defining function
void greet(){
    cout << "Hello World" << endl;
}

int main() {
// Calling -invoking -executing function
    greet();

    cout << "Done!!!";
    return 0;
}



/* output
Hello World
Done!!!
*/
```

### 40. Parameters with a Default Value<a id="046"></a>

2. Function with input

difference b/w parameter vs argument

```cpp
#include <iostream>
using namespace std;

// when defining a function we  declare parameter
void greet(string firstName, string lastName){
    cout << "Hello " << firstName << " " << lastName << endl;
}

int main() {
// Calling -invoking -executing function
// when calling a function we pass arguments
    greet("Sam", "Altman");

    cout << "Done!!!";
    return 0;
}


/* output
Hello Sam Altman
Done!!!
*/
```

---

3. Function with output aka return type

```cpp
#include <iostream>
using namespace std;

// defining return type function aka function with output
string fullName(string firstName, string lastName){
// concatenating or combining string using '+' operator
    return firstName + " " + lastName;
}

int main() {
// calling function then, storing info in name variable
    string name = fullName("Joy", "Peter");
    cout << name << endl;

    cout << "Done!!!";
    return 0;
}



/* output
Joy Peter
Done!!!
*/
```

---

Parameter with default value

```cpp
#include <iostream>
using namespace std;

// default tax rate is set to 20%
double claculateTax(double income, double taxRate = .2){
    return income * taxRate;
}

int main() {
// tax rate 20%
    double tax = claculateTax(10000);

// tax rate 30%
// note the 2nd args will override the default parameter value
    double tax2 = claculateTax(10000, .3);

    cout << tax << endl;
    cout << tax2 << endl;


    cout << "Done!!!";
    return 0;
}



/* output
2000
3000
Done!!!
*/
```

note-
parameter with default comes after the parameter without default value.
calculateTax(10000, .3:comes after default)

### 41. Overloading Functions<a id="047"></a>

Signature of function: name of fun + (no. of parameter and type of parameter)

never make same signature function that will cause compiler to make error

Version 1 function signature

- name of function: greet
- no. of parameter: 1
- type of parameter: string

<br>

Version 2 function signature

- name of function: greet
- no. of parameter: 2
- type of parameter: string, string

```cpp
#include <iostream>
using namespace std;

// 1st version
void greet(string name){
    cout << "Hello " << name << endl;
}

// 2nd version
void greet(string title, string name){
    cout << "Hello " << title << " " << name;
}


int main() {
    greet("Joy");
    greet("Mr", "Joy");

    return 0;
}


/* output
Hello Joy
Hello Mr Joy
*/
```

### 42. Passing Arguments by Value or Reference<a id="048"></a>

Passing Arguments by Value

```cpp
#include <iostream>
using namespace std;

double increasePrice(double price){
    price = price * 1.2;
// price *= 1.2;
    return price;
}


int main() {
    double price = 100;

// copy of price-value is passed to function which would use memory
    price = increasePrice(price);
    cout << price;
    return 0;
}


/* output
120
*/

```

---

Passing Arguments by Reference

When we have large no. of data for processing, copy by value is bit expensive in term of memory so we pass by reference i.e location of memory

```cpp

#include <iostream>
using namespace std;

// &: a reference or address operator
void increasePrice(double& price){
    price = price * 1.2;
// price *= 1.2;
}


int main() {
    double price = 100;

// ref of price-value is passed to function which won't use memory
    increasePrice(price);
    cout << price;
    return 0;
}


/* output
120
*/
```

---

Second example passing arguments by Reference

```cpp
#include <iostream>
using namespace std;

// &: a reference or address operator
void greet(string& name){
    cout << "Hello " << name;
}


int main() {
    string name = "Joy";
// passing address or references
    greet(name);

    return 0;
}



/* output
Hello Joy
*/
```

### 43. Local vs Global Variables<a id="049"></a>

```cpp
#include <iostream>
using namespace std;

// Global variable (global scope)
double taxRate = .2;


double calculateTax(int sales){
// accessing global variable
    return sales * taxRate;
}


int main() {
// local variable (local scope)
    int sales = 10000;

    double tax = calculateTax(sales);
    cout << tax;

    return 0;
}


/* output
2000
*/
```

### 44. Declaring Functions<a id="050"></a>

1. We always define our function before main function
1. In case we need to define our custom function after main function, then we declare the function before then main function.
1. This tell the compiler there is function that exist and is somewhere else
1. we tell compiler there is a greet function with datatype string, with name parameter, and it is somewhere else.

```cpp
#include <iostream>
using namespace std;

// function declaration or function prototype
void greet(string name);

int main() {
    greet("joy");

    return 0;
}

// function definition or implementation
void greet(string name){
    cout << "Hello " << name;
}


/* output
Hello joy
*/
```

### 45. Organizing Functions in Files<a id="051"></a>

Benefits:

- Making big files small and easier to maintain.
- Once we have functionality in diff file we can reuse that functionality in diff project.

<br>

Process:

- we need to create two files
- one is header file, where we add our function declaration
- another one is source/implementation file, where we add our function definition.

---

Steps

1. create a folder name it "utils"
1. In utils-folder create file greet.cpp and write simple function
1. this file will act as source/implementation file

```cpp
#include <iostream>
using namespace std;

void greet(string name){
  cout << "Hello " << name;
}
```

---

1. In utils-folder create file greet.hpp or greet.h
1. preferable style is greet.hpp -use convention
1. i'm gonna work with .h extension

```cpp
#include <string>

// function declaration
void greet(std::string name);

```

or

for adv learner (optional)

```cpp
// if UTILS_GREET constant which is written in uppercase, followed by foldername then function name is not defined
#ifndef UTILS_GREET

// then define UTILS_GREET constant which is written in uppercase, followed by foldername then function name
#define UTILS_GREET

#include <string>

// function declaration
void greet(std::string name);


// end
#endif
```

---

1. In main.cpp bring header file and use them

```cpp
#include <iostream>
#include "utils/greet.h"

using namespace std;

int main() {
// this greet function is called from another file
greet("joy");

return 0;
}
```

---

#### For Clion

Open CMakeList.txt and edit

```cpp
cmake_minimum_required(VERSION 3.26)
project(untitled3)

set(CMAKE_CXX_STANDARD 23)

# 👇 remove /debug/ add header files like written below format
add_executable(untitled3 main.cpp
        utils/greet.cpp)
```

---

#### VS code

1. because the vs-code run extension does not support linker feature, we have to perform build process manually.
1. Open project location
1. run cmd in vscode terminal to generate exe file
1. run cmd to execute exe file

```sh

g++ -o main.exe main.cpp utils/greet.cpp

To run code
./main.exe
```

### 46. Using Namespaces<a id="052"></a>

A namespace is like a bucket where we put our function inside and with this we prevent name conflict

We have std namespace for all the function and classes define in the standard template library

In standard library we've got string class etc

1. From previous project
1. In greet.h file wrap function declaration inside messaging namespace

```cpp
#ifndef UTILS_GREET
#define UTILS_GREET

#include <string>

// wrapping function declaration in messaging namespace
namespace messaging{
  // function declaration
  void greet(std::string name);
}

#endif
```

---

1. In greet.cpp file wrap function definition inside messaging namespace

```cpp
#include <iostream>
using namespace std;

// wrapping function definition in messaging namespace
namespace messaging{
  void greet(string name){
    cout << "Hello " << name;
  }
}
```

---

1. In main.cpp

```cpp
#include <iostream>
#include "utils/greet.h"

using namespace std;

int main() {
// how to access greet function using messaging namespace
messaging::greet("joy");

return 0;
}

```

---

> Other ways to use namespace

- bringing entire namespace, same way like std namespace
- but there is a problem in this approach, if have greet() function in both namespace then there will be name conflict

```cpp
#include <iostream>
#include "utils/greet.h"

using namespace std;
using namespace messaging;

int main() {
greet("joy");

return 0;
}

```

---

Bringing specific function from namespace

```cpp
#include <iostream>
#include "utils/greet.h"

// bringing specific cin, cout object from std-namespace
using std::cout, std::cin;
// bringing specific greet function from messaging-namespace
using  messaging::greet ;

int main() {
greet("joy");

return 0;
}
```

### 47. Debugging C++ Programs<a id="053"></a>
