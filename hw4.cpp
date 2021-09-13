#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>


using namespace std;

class Vector
{
    private:
        int m_length;
        int *m_data;

    public:
        Vector(): m_length(0), m_data(nullptr)
        { }

        Vector(int length):
        m_length(length)
        {
            assert(length >= 0);

            if (length > 0)
                m_data = new int[length];
            else
                m_data = nullptr;
        }

        ~Vector()
        {
            delete[] m_data;
        }
        void erase()
        {
            delete[] m_data;

            m_data = nullptr;
            m_length = 0;
        }
        int getLength() { return m_length; }
        int& operator[](int index)
        {
            assert(index >= 0 && index < m_length);
            return m_data[index];
        }

        void insertBefore(int value, int index)
        {
            assert(index >= 0 && index <= m_length);
            int *data = new int[m_length+1];
            for (int before=0; before < index; ++before)
                data[before] = m_data[before];

            data [index] = value;

            for (int after=index; after < m_length; ++after)
                data[after+1] = m_data[after];

            delete[] m_data;
            m_data = data;
            ++m_length;
        }
        void push_back(int value) { insertBefore(value, m_length); }
        void pop_back()
        {
            int *data = new int[m_length-1];
            for (int before=0; before < (m_length-1); ++before)
                data[before] = m_data[before];

            delete[] m_data;
            m_data = data;
            m_length -= 1;
        }
        void pop_front()
        {
            int *data = new int[m_length];
            for (int before=1; before < m_length; ++before)
                data[before-1] = m_data[before];

            delete[] m_data;
            m_data = data;
            m_length -= 1;
        }
        void print()
        {
            for(int index = 0;index<m_length;index++)
            {
                cout <<m_data[index]<< endl;
            }
        }

};
//Task3 (Class Card, Hand, GenericPlayer)
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
			//for (m_Cards<int>::iterator it = m_Cards.begin();it != m_Cards.end();++it) sum_cards += *it;
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
    Vector vec(10);
    vec.erase();
    cout << "Push vector" << endl;
    vec.push_back(1);
    vec.push_back(12);
    vec.push_back(31);
    vec.push_back(21);
    vec.push_back(11);
    vec.push_back(1);
    vec.push_back(11);
    vec.push_back(12);
    vec.print();
    cout << "PopBack vector" << endl;
    vec.pop_back();
    vec.print();
    cout << "PopFront vector" << endl;
    vec.pop_front();
    vec.print();
    cout << "PopFront vector" << endl;
    vec.pop_front();
    vec.print();

}
void print(vector<int> &v) {
    cout << "The length is: " << v.size() << '\n';

    for (int i=0; i<v.size(); i++)
        cout << v[i] << ' ';

    cout << endl;
}

void Task2()
{
    vector<int> vec_int;
    vec_int.push_back(10);
    vec_int.push_back(30);
    vec_int.push_back(10);
    vec_int.push_back(1);
    vec_int.push_back(10);
    vec_int.push_back(100);
    vec_int.push_back(20);
    vec_int.push_back(50);
    vec_int.push_back(11);
    vec_int.push_back(30);
    vec_int.push_back(13);
    vec_int.push_back(1);
    vec_int.push_back(0);
    sort(vec_int.begin(),vec_int.end());
    print(vec_int);
    int un_mun = 0;
    for(int i = 1; i<=vec_int.size(); ++i)
    {
        if (vec_int[i-1]!=vec_int[i]) un_mun+=1;
    }
    cout << "Different number = " << un_mun << endl;


}


int main()
{
    Task1();
    Task2();


}