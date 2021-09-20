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

class Date
{
    private:
        int m_day;
        int m_month;
        int m_year;
    public:
        Date(int day, int month, int year)
            :m_day(day), m_month(month), m_year(year){}

        int getDay(){return m_day;}
        void setDay(int d) {m_day = d;}
        int getMonth(){return m_month;}        
        void setMonth(int m) {m_month = m;} 
        int getYear(){return m_year;}        
        void setYear(int y) {m_year = y;} 

        void print()
        {
            cout << "Date: " << m_day << ". " << m_month << ". " << m_year << endl;
        } 
  
        
        friend ostream& operator<< (ostream &out, const Date &date);
};

ostream& operator<< (ostream &out, const Date &date)
{
    out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
    return out;
}
template<typename T>
class Today
{
    public:
        Today(T* today)
        {
            this->today = today;
        }
        ~Today()
        {
            delete today;
        }

        T& operator*()
        {
            return *today;
        }
        T* operator->() {return today;}
    private:
        T* today;
};
template<typename Y>
class Date_s
{
    public:
        Date_s(Y* date)
        {
            this->date = date;
        }
        ~Date_s()
        {
            delete date;
        }

        Y& operator*()
        {
            return *date;
        }
        Y* operator->()
        {
            return date;
        }
    private:
        Y* date;
};
void Task1()
{
    Today<int> day = new int(20);
    Today<int> month = new int(9);
    Today<int> year = new int(2021);
    int d_;
    int m_;
    int y_;
    Date d(1,2,2001);
    cout << d;
    d.setDay(*day);
    d_ = d.getDay();
    d.setMonth(*month);
    m_ = d.getMonth();
    d.setYear(*year);
    y_=d.getYear();
    cout << d;
    Date_s<int> day_s = &d_;
    Date_s<int> month_s = &m_;
    Date_s<int> year_s = &y_;
    d.setDay(*day_s);
    d.setMonth(*month_s);
    d.setYear(*year_s);
    cout << d;
} 

template<typename Q>
class Date1
{
    public:
        Date1(Q* date)
        {
            this->date = date;
        }
        ~Date1()
        {
            delete date;
        }

        Q& operator*()
        {
            return *date;
        }
        Q* operator->()
        {
            return date;
        }
    private:
        Q* date;
};
template<typename R>
class Date2
{
    public:
        Date2(R* date)
        {
            this->date = date;
        }
        ~Date2()
        {
            delete date;
        }

        R& operator*()
        {
            return *date;
        }
        R* operator->()
        {
            return date;
        }
    private:
        R* date;
};

void Task2()
{
    int day1, day2, month1, month2, year1, year2;
    cout << "Input first date" << endl;
    cin >> day1;
    cin >> month1;
    cin >> year1;
    cout << "Input second date" << endl;
    cin >> day2;
    cin >> month2;
    cin >> year2;   
    //var1 заданы пользователем
    Date1<int> day = &day1;
    Date1<int> month = &month1;
    Date1<int> year = &year1;
    Date2<int> day_s = &day2;
    Date2<int> month_s = &month2;
    Date2<int> year_s = &year2;
    //var2 заданы в программе
    /*Date1<int> day = new int(10);
    Date1<int> month = new int(9);
    Date1<int> year = new int(2021);
    Date2<int> day_s = new int(20);
    Date2<int> month_s = new int(9);
    Date2<int> year_s = new int(2021);*/
    Date d1(*day, *month, *year);
    Date d2(*day_s, *month_s, *year_s);
    int d_1, d_2;
    int m_1, m_2;
    int y_1, y_2;
    d_1 = d1.getDay();
    m_1 = d1.getMonth();
    y_1 = d1.getYear();
    d_2 = d2.getDay();
    m_2 = d2.getMonth();
    y_2 = d2.getYear();
    if(y_1==y_2)
    {
        if(m_1==m_2)
        {
            if(d_1==d_2) cout << "Даты одинаковы" << endl;
            else
            {
                if(d_1>d_2){d1.print();}
                else d2.print();
            }
        }
        else
        {
            if(m_1>m_2){d1.print();}
            else d2.print();
        }
    }
    else
    {
        if(y_1>y_2){d1.print();}
        else d2.print();
    }

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
class Deck : public Hand
{
public:
    Deck()
    {
        m_Cards.reserve(52);
        Populate();
    };
    
    virtual ~Deck();

    void Populate()
    {
        Clear();

        for (int s = Card::CLUBS; s <= Card::SPADES; ++s)
        {
            for (int r = Card::ACE; r <= Card::KING; ++r)
            {
                Add(new Card(static_cast<Card::rank>(r),
                            static_cast<Card::suit>(s)));
            }
        }
    }

    void Shuffle()
    {
        random_shuffle(m_Cards.begin(), m_Cards.end());
    }

    void Deal(Hand& aHand)
    {
        if (!m_Cards.empty())
        {
            aHand.Add(m_Cards.back());
            m_Cards.pop_back();
        }
        else
        {
            cout << "Out of cards. Unable to deal.";
        }
    }

    void AdditionalCards(GenericPlayer& aGenericPlayer)
    {
        cout << endl;

        while (!(aGenericPlayer.IsBusted()) && aGenericPlayer.IsHitting())
        {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;
            
            if (aGenericPlayer.IsBusted())
            {
                aGenericPlayer.Bust();
            }
        }
    }

};
class Game
{
public:
    Game(const vector<string>& names)
    {
        vector<string>::const_iterator pName;
        for (pName = names.begin(); pName != names.end(); ++pName)
        {
            m_Players.push_back(Player(*pName));
        }

        srand(static_cast<unsigned int>(time(0)));
        m_Deck.Populate();
        m_Deck.Shuffle();
    };
    
    ~Game();
    void Play()
    {
        vector<Player>::iterator pPlayer;
        for (int i = 0; i < 2; ++i)
        {
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            {
                m_Deck.Deal(*pPlayer);
            }
            m_Deck.Deal(m_House);
        }
        
        m_House.FlipFirstCard();
        
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            cout << *pPlayer << endl;
        }
        cout << m_House << endl;
        
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            m_Deck.AdditionalCards(*pPlayer);
        }
        
        m_House.FlipFirstCard();
        cout << endl << m_House;
        
        m_Deck.AdditionalCards(m_House);
        
        if (m_House.IsBusted())
        {
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
            {
                if (!(pPlayer->IsBusted()))
                {
                    pPlayer->Win();
                }
            }
        }
        else
        {
            for (pPlayer = m_Players.begin(); pPlayer != m_Players.end();
                ++pPlayer)
            {
                if (!(pPlayer->IsBusted()))
                {
                    if (pPlayer->GetTotal() > m_House.GetTotal())
                    {
                        pPlayer->Win();
                    }
                    else if (pPlayer->GetTotal() < m_House.GetTotal())
                    {
                        pPlayer->Lose();
                    }
                    else
                    {
                        pPlayer->Push();
                    }
                }
            }
            
        }
        
        for (pPlayer = m_Players.begin(); pPlayer != m_Players.end(); ++pPlayer)
        {
            pPlayer->Clear();
        }
        m_House.Clear();
    }

    
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
};



int main()
{
   // Task1();
    Task2();
    return 0;
}