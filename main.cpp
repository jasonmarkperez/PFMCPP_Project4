#include <iostream>
/*
 Project 4 - Part 1 / 9
 video: Chapter 2 Part 7
 Returning Values tasks 

 Create a branch named Part1
 
 1) write 3 UDTs named FloatType, DoubleType, IntType.
 

 2) give each UDT the following member functions:
        add( lhs, rhs );
        subtract( lhs, rhs );
        multiply( lhs, rhs );
        divide( lhs, rhs );
 
 3) make them return the correct primitive type. e.g. if you're implementing the FloatType::add function, your implementation would start like this:
        float FloatType::add( float lhs, float rhs )
 
 4) declare a few instances of each class in main() and call the member functions with the appropriate arguments.
        FloatType ft;
        auto result = ft.add(3.2f, 23.f );
 
 5) print out those results using std::cout:
        std::cout "result of ft.add(): " << result << std::endl;
 
 6) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.
 */

struct FloatType
{
    float add(float lhs, float rhs)
    {
        return lhs + rhs;
    }

    float subtract(float lhs, float rhs)
    {
        return lhs - rhs;
    }

    float multiply(float lhs,float rhs )
    {
        return lhs * rhs;
    }

    float divide(float lhs,float rhs )
    {

        if(rhs == 0.f)
        {
            std::cout << "WARN: Division by 0 is undefined behavior." << std::endl;
        }
        return lhs / rhs;
    }
};

struct DoubleType
{
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
            std::cout << "WARN: Division by 0 is undefined behavior." << std::endl;
        } 
       return lhs / rhs;
    }
};

struct IntType
{
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

    auto divide(int lhs, int rhs)
    {
        if(rhs == 0)
        {
            return 0;
        }
        return lhs / rhs;
    }
};

#include <iostream>
int main()
{
    FloatType ft;
    auto floatAddResult = ft.add(23.90f, 99.1245f);
    auto floatSubtractResult = ft.subtract(924, 12.42f);
    auto floatMultiplyResult = ft.multiply(12.415f, 2.0f);
    auto floatDivideResult = ft.divide(2.20f, 21.4f);
    auto floatDivideByZero = ft.divide(2.20f, 0.0f);

    std::cout << "float add result: " << floatAddResult << std::endl;
    std::cout << "float subtract result: " << floatSubtractResult << std::endl;
    std::cout << "float multiple result: " << floatMultiplyResult << std::endl;
    std::cout << "float divide result: " << floatDivideResult << std::endl;
    std::cout << "float divide by zero result: " << floatDivideByZero << std::endl;

    DoubleType dt;
    auto doubleAddResult = dt.add(2333.90, 969.1245);
    auto doubleSubtractResult = dt.subtract(924, 12.42);
    auto doubleMultiplyResult = dt.multiply(122.415, 2.0);
    auto doubleDivideResult = dt.divide(24.20, 21.4);
    auto doubleDivideByZero = dt.divide(24.20, 0);

    std::cout << "double add result: " << doubleAddResult << std::endl;
    std::cout << "double subtract result: " << doubleSubtractResult << std::endl;
    std::cout << "double multiple result: " << doubleMultiplyResult << std::endl;
    std::cout << "double divide result: " << doubleDivideResult << std::endl;
    std::cout << "double divide by zero result: " << doubleDivideByZero << std::endl;

    IntType it;
    auto intAddResult = it.add(2333, 969);
    auto intSubtractResult = it.subtract(924, 12);
    auto intMultiplyResult = it.multiply(122, 2);
    auto intDivideResult = it.divide(24, 2);
    auto intDivideByZero = it.divide(24, 0);

    std::cout << "int add result: " << intAddResult << std::endl;
    std::cout << "int subtract result: " << intSubtractResult << std::endl;
    std::cout << "int multiple result: " << intMultiplyResult << std::endl;
    std::cout << "int divide result: " << intDivideResult << std::endl;
    std::cout << "int divide by zero: " << intDivideByZero << std::endl;
}
