#include <iostream>
#include <string>
#include <cmath>

using namespace std; 

class Figure
{
    protected:
        
        
        const float m_pi = 3.14;
       
    public:
        
    virtual void area() = 0;
};
class Parallelogramm : public Figure
{
    protected:
        int m_a;
        int m_b;
        int m_angle;
    public:

        int S = m_a*m_b*sin(m_angle*m_pi/180); 
        Parallelogramm (int a, int b, int angle)
            :m_a(a), m_b(b), m_angle(angle) {}
        
        virtual void area()
        {
            cout << "area parallelogramm: " << S << endl;
        } 

};
class Circle : public Figure
{
    protected:
    int m_r;
    public:

        float S = m_pi*pow(m_r,2); 
        Circle (int r)
            :m_r(r) {}
        
        virtual void area()
        {
            cout << "area circle: " << S << endl;
        } 
};
class Rectangle : public Parallelogramm
{
    public:

        int S = m_a*m_b; 
        Rectangle (int a, int b, int angle)
            :Parallelogramm(a, b, angle){}
        
        virtual void area()
        {
            cout << "area rectangle: " << S << endl;
        } 

};
class Square : public Parallelogramm
{
    public:    
        int S = pow(m_a,2); 
        Square (int a, int b, int angle)
            :Parallelogramm(a, b, angle){}
        
        virtual void area()
        {
            cout << "area square: " << S << endl;
        } 
};
class Rhombus : public Parallelogramm
{
    public:    
        int S = pow(m_a,2)*sin(m_angle*m_pi/180); 
        Rhombus (int a, int b, int angle)
            :Parallelogramm(a, b, angle){}
        
        virtual void area()
        {
            cout << "area rhombus: " << S << endl;
        } 
};
class Car
{
    private:
        string m_company;
        string m_model;
    public:
        Car (string company, string model)
            :m_company(company), m_model(model)
            {
                cout <<"1) " <<company << ", " << model << endl;
            }
};
class PassengersCar : virtual public Car
{
    public:
        PassengersCar (string company, string model)
            :Car(company, model)
            {
                cout << "2) " << company << ", " << model << endl;
            }
};
class Bus : virtual public Car
{
    public:
        Bus (string company, string model)
                :Car(company, model)
                {
                   cout << "3) " << company << ", " << model << endl;
                }
};
class Minivan : public PassengersCar, public Bus
{
    public:
        Minivan(string company, string model)
            :PassengersCar(company, model), Bus(company, model),Car(company, model)
            {
               cout <<"4) " <<company << ", " << model << endl;
                
            }
};
class Fraction
{

    public:
        int m_numerator;
        int m_denomerator;
        Fraction (int numerator, int denomerator)
            : m_numerator(numerator), m_denomerator(denomerator){}
        void display() 
        {
            if(m_denomerator!=0)
            {
                if(m_numerator==0)
                {
                    cout << "0" << endl;
                }
                else
                {
                    cout << m_numerator << "/" << m_denomerator << endl;
                }
            }
            else cout << "error" << endl;
            
            
        }
        
};
Fraction operator+ (Fraction frac1, Fraction frac2)
{
    int frac_num_sum1 = frac1.m_numerator+frac2.m_numerator;
    int frac_num_sum2 = frac1.m_numerator*frac2.m_denomerator+frac2.m_numerator*frac1.m_denomerator;
    int frac_prod_denom = frac1.m_denomerator*frac2.m_denomerator;
    if ((frac1.m_denomerator!=0)&&(frac2.m_denomerator!=0))
    {
        if(frac1.m_denomerator == frac2.m_denomerator)
        {
            return Fraction(frac_num_sum1,frac2.m_denomerator);
        }
        else
        {
            return Fraction(frac_num_sum2,frac_prod_denom);
        }
    }
}
Fraction operator- (Fraction frac1, Fraction frac2)
{
    int frac_num_dif1 = frac1.m_numerator-frac2.m_numerator;
    int frac_num_dif2 = frac1.m_numerator*frac2.m_denomerator-frac2.m_numerator*frac1.m_denomerator;
    int frac_denom_dif = frac1.m_denomerator-frac2.m_denomerator;
    int frac_prod_denom = frac1.m_denomerator*frac2.m_denomerator;
    if ((frac1.m_denomerator!=0)&&(frac2.m_denomerator!=0))
    {
        if(frac1.m_denomerator == frac2.m_denomerator)
        {
            return Fraction(frac_num_dif1,frac2.m_denomerator);
        }
        else
        {
            return Fraction(frac_num_dif2,frac_prod_denom);
        }
    }
}
Fraction operator* (Fraction frac1, Fraction frac2)
{
    int frac_num_prod = frac1.m_numerator*frac2.m_numerator;
    int frac_denom_prod = frac1.m_denomerator*frac2.m_denomerator;
    if ((frac1.m_denomerator!=0)&&(frac2.m_denomerator!=0))
    {
        return Fraction(frac_num_prod,frac_denom_prod);
    }
}
Fraction operator/ (Fraction frac1, Fraction frac2)
{
    int frac_num_prod = frac1.m_numerator*frac2.m_denomerator;
    int frac_denom_prod = frac1.m_denomerator*frac2.m_numerator;
    if ((frac1.m_denomerator!=0)&&(frac2.m_denomerator!=0)&&(frac_denom_prod!=0))
    {
        return Fraction(frac_num_prod,frac_denom_prod);
    }
}
bool operator== (Fraction frac1, Fraction frac2)
{
        return ((frac1.m_numerator==frac2.m_numerator)&&(frac1.m_denomerator==frac2.m_denomerator));
}
bool operator!= (Fraction frac1, Fraction frac2)
{
        return (((frac1.m_numerator==frac2.m_numerator)&&(frac1.m_denomerator!=frac2.m_denomerator))||
                ((frac1.m_numerator!=frac2.m_numerator)&&(frac1.m_denomerator==frac2.m_denomerator))||
                ((frac1.m_numerator!=frac2.m_numerator)&&(frac1.m_denomerator!=frac2.m_denomerator)));
}
bool operator > (Fraction frac1, Fraction frac2)
{
        return (frac1.m_numerator*frac2.m_denomerator>frac2.m_numerator*frac1.m_denomerator);
}
bool operator >= (Fraction frac1, Fraction frac2)
{
        return (frac1.m_numerator*frac2.m_denomerator>=frac2.m_numerator*frac1.m_denomerator);
}
bool operator <= (Fraction frac1, Fraction frac2)
{
        return (frac1.m_numerator*frac2.m_denomerator<=frac2.m_numerator*frac1.m_denomerator);
}
bool operator < (Fraction frac1, Fraction frac2)
{
        return (frac1.m_numerator*frac2.m_denomerator<frac2.m_numerator*frac1.m_denomerator);
}
//task4
class Card
{
    private:
        enum Suit
        {
        SUIT_SPADES,
        SUIT_HEARTS,
        SUIT_DIAMONDS,
        SUIT_CLUBS,
        };
        enum Value
        {
        VALUE_ACE_MIN = 1,
        VALUE_TWO,
        VALUE_THREE,
        VALUE_FOUR,
        VALUE_FIVE,
        VALUE_SIX,
        VALUE_SEVEN,
        VALUE_EIGHT,
        VALUE_NINE,
        VALUE_TEN,
        VALUE_JACK=10,
        VALUE_QUENN=10,
        VALUE_KING=10,
        VALUE_ACE_MAX,
        };
        bool position=true;
    public:
       
        bool Flip ()
        {
            if(position==true)
            {
                position = false;
                return position;
            }
            else
            {
                position = true;
                return position;
            }
            
        }
        int getValue(int value)
        {
            if(value == VALUE_ACE_MIN)
            {
                return value;
            }
        }

};

void Task1()
{
    cout << "Task1" << endl; 
    Parallelogramm par(10,5,50);
    Circle circle(6);
    Rectangle rect(10,4,30);
    Square square(20,3,30);
    Rhombus rhombus(6,1,40);

    par.area();
    circle.area();
    rect.area();
    square.area();
    rhombus.area();
}
void Task2()
{
    cout << "Task2" << endl;
    PassengersCar Pascar("VW", "Polo");
    Bus bus("Mercedes", "Contigo");
    Minivan Minivan("VW", "Multivan");
}
void Task3()
{
    Fraction frac_1(1,3);
    Fraction frac_2(1,3);

    Fraction fsum = frac_1 + frac_2;
    Fraction fdif = frac_1 - frac_2;
    Fraction fprod= frac_1*frac_2;
    Fraction fdiv = frac_1/frac_2;
    bool b1 = frac_1 == frac_2;
    bool b2 = frac_1 != frac_2;
    bool b3 = frac_1 > frac_2;
    bool b4 = frac_1 >= frac_2;
    bool b5 = frac_1 <= frac_2;
    bool b6 = frac_1 < frac_2;
    fsum.display();
    fdif.display();
    fprod.display();
    fdiv.display();
    cout << b1 << endl;
    cout << b2 << endl;
    cout << b3 << endl;
    cout << b4 << endl;
    cout << b5 << endl;
    cout << b6 << endl;
    
}
void Task4()
{
    Card card;
    bool b = card.Flip();
    cout << b <<endl;
}

int main()
{
    Task1();
    Task2();
    Task3();
    Task4();
}