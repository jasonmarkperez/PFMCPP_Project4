/*
 Project 4 - Part 3 / 9
 Video: Chapter 4 Part 3 
 Casting

 Create a branch named Part3
 
    Build/Run often with this task to make sure you're not breaking the code with each step.
    I recommend committing after you get each step working so you can revert to a working version easily if needed.

 1) remove your functions that accepted a User-Defined Type
 
 2) remove any getValue() functions if you added them
 
 3) move all of your add/subtract/multiply/divide implementations out of the class.
  
 4) add user-defined conversion functions that convert to the numeric type your object holds.
        i.e. if your type holds an int, you'll need an operator int() function.
 
 5) make your member variable private.
         this conversion function should be the ONLY WAY to access the held value.
 
 6) clean up any forward declaration that you might have.
 
 7) make sure it compiles & runs without errors.
 
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
