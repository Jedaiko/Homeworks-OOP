#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>
#include<algorithm>


using namespace std;

template <typename T>
class Pair1
{
    public:
        T m_first;
        T m_second;
        Pair1(T first, T second)
           :m_first(first), m_second(second){};
        T first()
        {
            return m_first;
        }
        T second()
        {
            return m_second;
        }
};
template <typename T, typename U>
class Pair
{
    public:
        T m_first;
        U m_second;
        Pair(T first, U second)
           :m_first(first), m_second(second){};
        T first()
        {
            return m_first;
        }
        U second()
        {
            return m_second;
        }
};
template <typename P>
class StringValuePair : public Pair<string, P>
{
    public:
        string m_string;
        P m_second;
        StringValuePair(string string1, P second)
           :Pair<string, P>(string1, second){};
};
//Task4 (Class Card, Hand, GenericPlayer)
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
            return value;
        }

};
class Hand : public Card
{
	private:
		vector<Card*> m_Cards;
	public:
		void Add(Card* pCard)
		{
			m_Cards.push_back(pCard);
		}
		void Clear()
		{
			m_Cards.clear();
		}
		int GetTotal()
		{
			int sum_cards = 0;
			for (vector<int>::iterator it = m_Cards.begin();it != m_Cards.end();++it) sum_cards += *it;
			return sum_cards;
		}
	
};
class GenericPlayer : Hand
{
	private:
		string m_name;
	public:
		virtual bool isHitting() const =0;
		bool isBoosted() const 
		{
			int boost;
			bool boost_flag = false;
			boost = GetTotal();
			if (boost >= 21) boost_flag = true;
			else boost_flag = false;
			return boost_flag;
		}
		void Boost() const
		{
			bool flag = false;
			flag = isBoosted();
			if (flag == true) cout << "Hand boost" << endl;
			else cout << "Hand normal" << endl;
			
			
		}
};

void Task1()
{
    cout << "Task1" << endl;

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
void Task2()
{
    cout << "Task2" << endl;

    Pair<int, double> p1(6, 7.8);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    Pair<double, int> p2(3.4, 5);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
}
void Task3()
{
    cout << "Task3" << endl;

    StringValuePair<int> svp("Amazing", 7);
    cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

}

int main()
{
    Task1();
    Task2();
    Task3();

    return 0;
}