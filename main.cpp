/*
 Project 4 - Part 2 / 9
 Video: Chapter 3 Part 6

 Create a branch named Part2

New/This/Pointers/References conclusion

    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.
 
 0) in the blank space below, declare/define an empty struct named 'A' on a single Line. 
     on the lines below it, write a struct named 'HeapA' that correctly shows how to own an instance of 'A' 
         on the heap without leaking, without using smart pointers. 
 */

struct A {};

struct HeapA
{
   A *a = nullptr;
    
    HeapA(){
        a = new A();
    }

    ~HeapA()
    {
        delete a;
    }
};

 /*
 1) Edit your 3 structs so that they own a heap-allocated primitive type without using smart pointers  
         IntType should own a heap-allocated int, for example.
 
 2) give it a constructor that takes the appropriate primitive
    this argument will initialize the owned primitive's value.
         i.e. if you're owning an int on the heap, your ctor argument will initialize that heap-allocated int's value.
 
 3) modify those add/subtract/divide/multiply member functions from chapter 2 on it
         a) make them modify the owned numeric type
         b) set them up so they can be chained together.
             i.e.
             DoubleType dt(3.5);
             dt.add(3.0).multiply(-2.5).divide(7.2); //an example of chaining
 
 4) write add/subtract/divide/multiply member functions for each type that take your 3 UDTs
        These are in addition to your member functions that take primitives
        for example, IntType::divide(const DoubleType& dt);
 
 5) print out the results with some creative couts 
    i.e.
         FloatType ft(0.1f);
         IntType it(3);
         std::cout << "adding 3 and subtracting 'it' from 'ft' results in the following value: " << *ft.add(2.f).subtract( it ).value << std::endl;  //note the dereference of the `value` member of `ft`
 
 6) Don't let your heap-allocated owned type leak!
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */



#include <iostream>

struct FloatType
{
    float* f = nullptr;

    FloatType(){
        f = new float();
    } //

    FloatType(float newFloat) 
    {
        f = new float(newFloat);
    }

    ~FloatType()
    {
        delete f;
    }

    float& add(float rhs)
    {
        *f += rhs;
        return *f;
    }

    float& subtract(float rhs)
    {
        *f -= rhs;
        return *f;
    }

    float& multiply(float rhs)
    {
        *f *= rhs;
        return *f;
    }

    float& divide(float rhs)
    {
        if(rhs == 0.f)
        {
            std::cout << "WARN: dividing by 0." << std::endl;
        }
        *f /= rhs;
        return *f;
    }
};

struct DoubleType
{
    double* d = nullptr;

    DoubleType(){}

    DoubleType(double newDouble)
    {
        d = new double(newDouble);
    }

    ~DoubleType()
    {
        delete d;
    }

    double add(double lhs, double rhs)
    {
        return lhs + rhs;
    }

    double subtract(double lhs, double rhs)
    {
        return lhs - rhs;
    }

    double multiply(double lhs, double rhs)
    {
        return lhs * rhs;
    }

    double divide(double lhs, double rhs)
    {
        if(rhs == 0.0)
        {
            std::cout << "WARN: dividing by 0." << std::endl;
        } 
       return lhs / rhs;
    }
};

struct IntType
{
    int* i = nullptr;

    IntType() {}
    
    IntType(int newInt)
    {
        i = new int(newInt);
    }

    ~IntType()
    {
        delete i;
    }

    int add(int lhs, int rhs)
    {
        return lhs + rhs;
    }

    int subtract(int lhs, int rhs)
    {
        return lhs - rhs;
    }

    int multiply(int lhs, int rhs)
    {
        return lhs * rhs;
    }

    int divide(int lhs, int rhs)
    {
        if( rhs != 0 )
            return lhs / rhs;

        std::cout << "cannot divide by 0" << std::endl;
        return 0;
    }
};

#include <iostream>
int main()
{
    FloatType ft(23.11f);

    std::cout << ft.add(23.90f) << std::endl;
    // auto floatSubtractResult = ft.subtract(924, 12.42f);
    // auto floatMultiplyResult = ft.multiply(12.415f, 2.0f);
    // auto floatDivideResult = ft.divide(2.20f, 21.4f);
    // auto floatDivideByZero = ft.divide(2.20f, 0.0f);

    // std::cout << "float add result: " << floatAddResult << std::endl;
    // std::cout << "float subtract result: " << floatSubtractResult << std::endl;
    // std::cout << "float multiple result: " << floatMultiplyResult << std::endl;
    // std::cout << "float divide result: " << floatDivideResult << std::endl;
    // std::cout << "float divide by zero result: " << floatDivideByZero << std::endl;

    DoubleType dt;
    // auto doubleAddResult = dt.add(2333.90, 969.1245);
    // auto doubleSubtractResult = dt.subtract(924, 12.42);
    // auto doubleMultiplyResult = dt.multiply(122.415, 2.0);
    // auto doubleDivideResult = dt.divide(24.20, 21.4);
    // auto doubleDivideByZero = dt.divide(24.20, 0);

    // std::cout << "double add result: " << doubleAddResult << std::endl;
    // std::cout << "double subtract result: " << doubleSubtractResult << std::endl;
    // std::cout << "double multiple result: " << doubleMultiplyResult << std::endl;
    // std::cout << "double divide result: " << doubleDivideResult << std::endl;
    // std::cout << "double divide by zero result: " << doubleDivideByZero << std::endl;

    IntType it;
    // auto intAddResult = it.add(2333, 969);
    // auto intSubtractResult = it.subtract(924, 12);
    // auto intMultiplyResult = it.multiply(122, 2);
    // auto intDivideResult = it.divide(24, 2);
    // auto intDivideByZero = it.divide(24, 0);

    // std::cout << "int add result: " << intAddResult << std::endl;
    // std::cout << "int subtract result: " << intSubtractResult << std::endl;
    // std::cout << "int multiple result: " << intMultiplyResult << std::endl;
    // std::cout << "int divide result: " << intDivideResult << std::endl;
    // std::cout << "int divide by zero: " << intDivideByZero << std::endl;
}
