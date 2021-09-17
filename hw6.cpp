#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <iterator>
#include <cassert>
#include<algorithm>
#include<strstream>
#include<fstream>
#include <cstdlib>

using namespace std;


void Task1()
{
     int i;
    cout<<"Введите целое число : ";
    while(!(cin>>i)) 
    {
        cout<<"Неверно !! Введите снова !\n";
        cin.clear(); 
        cin.sync();
        cout<<"Введите целое число : ";
    }
    system("pause");
}

ostream & endll( ostream & os )
{
    os.put( os.widen('\n') );
    os.put( os.widen('\n') );
    os.flush(); 

    return os;
}

void Task2()
{

    int i = 10;
    int j =200;
    int k = 100;
    cout << i << endll;
    cout << k << endll;
    cout << j << endll;
}
//Task3-5 (Class Card, Hand, GenericPlayer)
class Card
{
    
    public:
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
        Card(Value v, Suit s, bool ifu) : m_Value(v), m_Suit(s), m_Position(ifu){}

        private:
        friend ostream& operator<<(ostream& os, const Card& aCard);
        Value m_Value;
        Suit m_Suit;
        bool m_Position;
};
ostream& operator<<(ostream& os, const Card& aCard)
{
    const string VALUE[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "s", "h", "d", "c" };
    
    if (aCard.m_Position)
    {
        os << VALUE[aCard.m_Value] << SUITS[aCard.m_Suit];
    }
    else
    {
        os << "XX";
    }
    
    return os;
}

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
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
	protected:
		string m_name;
	public:
        GenericPlayer(const string& name = "");
        GenericPlayer::GenericPlayer(const string& name) 
               : m_Name(name) {}

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

ostream& operator<<(ostream& os, const GenericPlayer& mGenericPlayer)
{
    os << mGenericPlayer.m_Name << ":\t";
    
    vector<Card*>::const_iterator pCard;
    if (!mGenericPlayer.m_Cards.empty())
    {
        for (pCard = mGenericPlayer.m_Cards.begin();
             pCard != mGenericPlayer.m_Cards.end();
             ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        
        
        if (mGenericPlayer.GetTotal() != 0)
        {
            cout << "(" << mGenericPlayer.GetTotal() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }
    
    return os;
}


class Player : GenericPlayer
{
    public:
        Player(const string& name = "");
        bool isHitting() const
        {
            cout << m_name << ", give you the card? (Y/N): ";
            char choice;
            cin >> choice;
            return (choice == 'y' || choice == 'Y');
        }
        void Win() const
        {
            cout << m_name << " win" << endl;
        }
        void Lose() const
        {
            cout << m_name << " lose" << endl;
        }
        void Push() const
        {
            cout << m_name << " draw" << endl;
        }
};
class House : public GenericPlayer
{
    public:
        House(const string& name = "House");

        bool IsHitting() const
        {
            return (GetTotal() <= 16);
        }
        
        void FlipFirstCard()
        {
            if (!(m_Cards.empty()))
                {
                    m_Cards[0]->Flip();
                }
            else
                {
                    cout << "do not flip the card"<< endl;
                }

        }
};



int main()
{
    
    Task1();
    Task2();
   
    return 0;
}