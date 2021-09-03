#include <iostream>
#include <string>

using namespace std; 
/*
	Создать класс Person (человек) с полями: имя, возраст, пол и вес. Определить методы переназначения имени, изменения возраста и веса. 
	Создать производный класс Student (студент), имеющий поле года обучения. Определить методы переназначения и увеличения этого значения. 
	Создать счетчик количества созданных студентов. В функции main() создать несколько студентов. По запросу вывести определенного человека.
*/
class Person	
{
	private:
		string m_name;
		int m_age;
		string m_gender;
		int m_weight;
		
	public:
		
		Person(string name, int age, string gender, int weight)
		 :m_name(name), m_age(age), m_gender(gender), m_weight(weight){}

		string getName() { return m_name; }
    	void setName(string name)
		{
			m_name=name;
		}
		int getAge() { return m_age; }
		void setAge(int age)
		{
			m_age = age;
		}
		string getGender() { return m_gender; }
    	int getWeight() { return m_weight; }
		void setWeight(int weight)
		{
			m_weight = weight;
		}


};

class Student : public Person
{
	private:
		int m_study_year;
		//static int count;

	public:
		//static void incCount(){count++;}

	 	Student(string name, int age, string gender, int weight, int study_year)
		 :Person(name, age, gender, weight), m_study_year(study_year){}
		 //incCount();

		int getStudyYear() { return m_study_year; }
		void setStudyYear(int study_year)
		{
			m_study_year = study_year;
		}
		


};

class Fruit
{
	protected:
		string name;
		string color;
    public:
		string getName()
		{
			return name;
		}
		string getColor()
		{
			return color;
		}
};
class Apple : public Fruit
{
	public:
		Apple (string m_color)
		{
			color = m_color;
			name = "apple";
		}
        Apple(){}
};
class Banana : public Fruit
{
	public:
		Banana ()
		{
			color = "yellow";
			name = "banana";
		}
};
class GrannySmith : public Apple
{
    public:
        GrannySmith ()
        {
            color = "green";
            name = "Granny Smith apple";
        }
};

void doTask1()
{
	cout << "Task1" << endl;

	Student dan("Dan", 19, "Man", 80, 2);
	Student ann("Ann", 18, "Woman", 65, 1);
	Student phill("Phill", 22, "Man", 90, 5);

	cout << dan.getName() << "," << dan.getAge() << "," <<dan.getGender() <<","<<dan.getWeight()<<","<<dan.getStudyYear()<<endl;
	dan.setName("Alex");
	dan.setAge(30);
	cout << dan.getName() << "," << dan.getAge() << "," <<dan.getGender() <<","<<dan.getWeight()<<","<<dan.getStudyYear()<<endl;
	dan.setStudyYear(7);
	cout << phill.getName() << "," << phill.getAge() << "," <<phill.getGender() <<","<<phill.getWeight()<<","<<phill.getStudyYear()<<endl;

	//cout << Student::count<<endl;
	
}
void doTask2()
{
	cout << "Task2" << endl;
    Apple a("red");
    Banana b;
    GrannySmith c;
    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
}

int main()
{
	doTask1();
	//doTask2();

    return 0;
}

