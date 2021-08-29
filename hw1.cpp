#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>

using namespace std;

class Power 
{
    public:
        int num1;
        int num2;
        void SetNumber ()
        {
            number_1 = num1;
            number_2 = num2;
        };
        void Calculate()
        {
            cout << pow(num1,num2);
        };

        
    private:
        int number_1 = 3; 
        int number_2 = 2; 

    
};

class RGBA
{
    private:
        uint8_t m_red = 0;
        uint8_t m_green = 0;
        uint8_t m_blue = 0;
        uint8_t m_alpha = 255;
    public:
        RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
            : m_red(red), m_green(green), m_blue(blue), m_alpha(alpha){}

        void print()
        {
            cout << unsigned(m_red) << ", " << unsigned(m_green) << ", " << unsigned(m_blue) << ", " << unsigned(m_alpha);  
        }
        

};

class Stack
{
    
   private:
        int stack_length;
        int array_num[10];
    public:
        
        void reset()
        {
            stack_length = 0;
            for (int index =0; index<10; ++index)
            {
                array_num[index] = 0;
            }
        }
        bool push(int value)
        {
            if (stack_length==10) return false;
           
            array_num[stack_length++] = value;
            return false;
        }
        int pop()
        {
            assert (stack_length > 0);
            return array_num[--stack_length];
        }
 
        void print()
        {
            cout << "( ";
            for (int i = 0; i < stack_length; ++i)
                cout << array_num[i] << ' ';
            cout << ")\n";
        }

};

int main()
{   
    // Task 1
 //   Power power;
 //   power.num1 = 5;
 //   power.num2 = 3;
 //   power.SetNumber();
 //   power.Calculate();

    //Task2
 //   RGBA rgba(10, 35, 0, 200);
 //   rgba.print();

    //Task3
    Stack stack;
    stack.reset();
 
    stack.print();
 
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
 
    stack.pop();
    stack.print();
 
    stack.pop();
    stack.pop();
 
    stack.print();  

    return 0;
} 