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

struct IntType;
struct DoubleType;

struct FloatType
{
    float* value = nullptr;

    FloatType(){
        value = new float();
    } //default constructor when no initial value passed.

    FloatType(float newFloat)
    {
        value = new float(newFloat);
    }

    ~FloatType()
    {
        delete value;
    }

    FloatType& add(float rhs);
    FloatType& add(const FloatType& rhs);
    FloatType& add(const DoubleType& rhs);
    FloatType& add(const IntType& rhs);
    
    FloatType& subtract(float rhs);
    FloatType& subtract(const FloatType& rhs);
    FloatType& subtract(const DoubleType& rhs);
    FloatType& subtract(const IntType& rhs);
    
    FloatType& multiply(float rhs);
    FloatType& multiply(const FloatType& rhs);
    FloatType& multiply(const DoubleType& rhs);
    FloatType& multiply(const IntType& rhs);
    
    FloatType& divide(float rhs);
    FloatType& divide(const FloatType& rhs);
    FloatType& divide(const DoubleType& rhs);
    FloatType& divide(const IntType& rhs);
};

struct DoubleType
{
    double* value = nullptr;

    DoubleType(){
        value = new double();
    }

    DoubleType(double newDouble)
    {
        value = new double(newDouble);
    }

    ~DoubleType()
    {
        delete value;
    }

    DoubleType& add(double rhs);
    DoubleType& add(const DoubleType& rhs);
    DoubleType& add(const FloatType& rhs);
    DoubleType& add(const IntType& rhs);
    
    DoubleType& subtract(double rhs);
    DoubleType& subtract(const DoubleType& rhs);
    DoubleType& subtract(const FloatType& rhs);
    DoubleType& subtract(const IntType& rhs);
    
    DoubleType& multiply(double rhs);
    DoubleType& multiply(const DoubleType& rhs);
    DoubleType& multiply(const FloatType& rhs);
    DoubleType& multiply(const IntType& rhs);
    
    DoubleType& divide(double rhs);
    DoubleType& divide(const DoubleType& rhs);
    DoubleType& divide(const FloatType& rhs);
    DoubleType& divide(const IntType& rhs);
};

struct IntType
{
    int* value = nullptr;

    IntType() {
        value = new int();
    }
    
    IntType(int newInt)
    {
        value = new int(newInt);
    }

    ~IntType()
    {
        delete value;
    }

    IntType& add(int rhs);
    IntType& add(const IntType& rhs);
    IntType& add(const DoubleType& rhs);
    IntType& add(const FloatType& rhs);
    
    IntType& subtract(int rhs);
    IntType& subtract(const IntType& rhs);
    IntType& subtract(const DoubleType& rhs);
    IntType& subtract(const FloatType& rhs);
    
    IntType& multiply(int rhs);
    IntType& multiply(const IntType& rhs);
    IntType& multiply(const DoubleType& rhs);
    IntType& multiply(const FloatType& rhs);
    
    IntType& divide(int rhs);
    IntType& divide(const IntType& rhs);
    IntType& divide(const DoubleType& rhs);
    IntType& divide(const FloatType& rhs);
};

FloatType& FloatType::add(float rhs)
{
    *value += rhs;
    return *this;
}

FloatType& FloatType::add(const FloatType& rhs)
{
    *value += *rhs.value;
    return *this;
}

FloatType& FloatType::add(const DoubleType& rhs)
{
    *value += *rhs.value;
    return *this;
}

FloatType& FloatType::add(const IntType& rhs)
{
    *value += *rhs.value;
    return *this;
}

FloatType& FloatType::subtract(float rhs)
{
    *value -= rhs;
    return *this;
}

FloatType& FloatType::subtract(const FloatType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

FloatType& FloatType::subtract(const DoubleType& rhs)
{
     *value -= *rhs.value;
    return *this;
}

FloatType& FloatType::subtract(const IntType& rhs)
{
     *value -= *rhs.value;
    return *this;
}

FloatType& FloatType::multiply(float rhs)
{
    *value *= rhs;
    return *this;
}

FloatType& FloatType::multiply(const FloatType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

FloatType& FloatType::multiply(const DoubleType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

FloatType& FloatType::multiply(const IntType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

FloatType& FloatType::divide(float rhs)
{
    if(rhs == 0.f)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
    *value /= rhs;
    return *this;
}


FloatType& FloatType::divide(const FloatType& rhs)
{
    if(*rhs.value == 0.f)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
    *value /= *rhs.value;
    return *this;
}

FloatType& FloatType::divide(const IntType& rhs)
{
    if(*rhs.value == 0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= *rhs.value;
   return *this;
}

FloatType& FloatType::divide(const DoubleType& rhs)
{
    if(*rhs.value == 0.0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= *rhs.value;
   return *this;
}

DoubleType& DoubleType::add(double rhs)
{
    *value += rhs;
    return *this;
}

DoubleType& DoubleType::add(const DoubleType& rhs)
{
    *value += *rhs.value;
    return *this;
}

DoubleType& DoubleType::add(const FloatType& rhs)
{
    *value += *rhs.value;
    return *this;
}

DoubleType& DoubleType::add(const IntType& rhs)
{
    *value += *rhs.value;
    return *this;
}

DoubleType& DoubleType::subtract(double rhs)
{
    *value -= rhs;
    return *this;
}

DoubleType& DoubleType::subtract(const DoubleType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

DoubleType& DoubleType::subtract(const FloatType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

DoubleType& DoubleType::subtract(const IntType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

DoubleType& DoubleType::multiply(double rhs)
{
    *value *= rhs;
    return *this;
}

DoubleType& DoubleType::multiply(const DoubleType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

DoubleType& DoubleType::multiply(const FloatType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

DoubleType& DoubleType::multiply(const IntType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

DoubleType& DoubleType::divide(double rhs)
{
    if(rhs == 0.0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= rhs;
   return *this;
}

DoubleType& DoubleType::divide(const DoubleType& rhs)
{
    if(*rhs.value == 0.0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= *rhs.value;
   return *this;
}

DoubleType& DoubleType::divide(const FloatType& rhs)
{
    if(*rhs.value == 0.0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= *rhs.value;
   return *this;
}

DoubleType& DoubleType::divide(const IntType& rhs)
{
    if(*rhs.value == 0.0)
    {
        std::cout << "WARN: dividing by 0." << std::endl;
    }
   *value /= *rhs.value;
   return *this;
}

IntType& IntType::add(int rhs)
{
    *value += rhs;
    return *this;
}

IntType& IntType::add(const IntType& rhs)
{
    *value += *rhs.value;
    return *this;
}

IntType& IntType::add(const FloatType& rhs)
{
    *value += *rhs.value;
    return *this;
}

IntType& IntType::add(const DoubleType& rhs)
{
    *value += *rhs.value;
    return *this;
}

IntType& IntType::subtract(int rhs)
{
    *value -= rhs;
    return *this;
}

IntType& IntType::subtract(const IntType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

IntType& IntType::subtract(const DoubleType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

IntType& IntType::subtract(const FloatType& rhs)
{
    *value -= *rhs.value;
    return *this;
}

IntType& IntType::multiply(int rhs)
{
    *value *= rhs;
    return *this;
}

IntType& IntType::multiply(const IntType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

IntType& IntType::multiply(const FloatType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

IntType& IntType::multiply(const DoubleType& rhs)
{
    *value *= *rhs.value;
    return *this;
}

IntType& IntType::divide(int rhs)
{
    if( rhs != 0 )
        *value /= rhs;

    std::cout << "cannot divide by 0" << std::endl;
    return *this;
}

IntType& IntType::divide(const IntType& rhs)
{
    if( *rhs.value != 0 )
        *value /= *rhs.value;

    std::cout << "cannot divide by 0" << std::endl;
    return *this;
}

IntType& IntType::divide(const FloatType& rhs)
{
    if( *rhs.value != 0.f )
        *value /= *rhs.value;

    std::cout << "cannot divide by 0" << std::endl;
    return *this;
}

IntType& IntType::divide(const DoubleType& rhs)
{
    if( *rhs.value != 0. )
        *value /= *rhs.value;

    std::cout << "cannot divide by 0" << std::endl;
    return *this;
}

#include <iostream>
int main()
{
    FloatType ft(23.11f);
    DoubleType dt(23.21);
    IntType it(113);

    std::cout << "take our float, and add another float value, add our double type variable, multiple by the integer variable: ";

    std::cout << *ft.add(23.24f).add(dt).multiply(it).value << std::endl;

    std::cout << "---" << std::endl;

    std::cout << "take our double, multiply it by our integer variable, add our floating integer, and divide it by the integer variable: ";

    std::cout << *dt.multiply(it).add(ft).divide(it).value << std::endl;
}
