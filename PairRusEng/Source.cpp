#include <string>
#include <iostream>

using namespace std;

class Pair
{
	string rus;
	string eng;
	friend ostream& operator<< (ostream& os, const Pair& obj);

public:
	Pair();
	Pair(string r, string e);

	void Input();
	void Print();

	string GetRus()const;
	string GetEng()const;

	void SetRus(string r);
	void SetEng(string e);
};

class Dictionary
{
	Pair* arr;
	int size;
	friend ostream& operator<< (ostream& os, const Dictionary& obj);

public:

	Dictionary();
	Dictionary(int s);
	Dictionary(const Dictionary& s);

	Dictionary& operator =(const Dictionary& right) 
	{
		if (this == &right)
			return *this;

		if (arr != nullptr)
			delete[] arr;

		arr = new Pair[right.size];
		size = right.size;

		for (int i = 0; i < size; ++i)
			arr[i] = right.arr[i];

		return *this;
	}

	void Input()
	{
		for (int i = 0; i < size; i++)
			arr[i].Input();
	}

	int Search(string text)
	{
		for (int i = 0; i < size; i++)
		{
			if (arr[i].GetEng() == text)
			{
				arr[i].Print();
				return i;
			}
		}
	}

	void Edit(string text)
	{
		int index = Search(text);
		cout << "1 - set eng";
		cout << "2 - set rus";
		int chose;
		cin >> chose;
		string temp;
		switch (chose) 
		{
		case 1:
			cin >> temp;
			arr[index].SetEng(temp);
			break;
		case 2:
			cin >> temp;
			arr[index].SetRus(temp);
			break;
		}
	}

	void Delete(string text)
	{
		int index = Search(text);
		arr[index].~Pair();
	}

	void Replace(string text)
	{
		int index = Search(text);
		arr[index].Input();
	}

	void Output();
	~Dictionary();
};

Pair::Pair()
{
	rus = "0";
	eng = "0";
}

Pair::Pair(string r, string e)
{
	rus = r;
	eng = e;
}

void Pair::Input()
{
	cout << "Enter rus word: " << endl;
	cin >> rus;
	cin.ignore();
	cout << "Enter eng word: " << endl;
	cin >> eng;
}

void Pair::Print()
{
	cout << "Rus: " << rus << "\t Eng: " << eng << endl;
}

string Pair::GetRus() const
{
	return rus;
}

string Pair::GetEng() const
{
	return eng;
}

void Pair::SetRus(string r)
{
	rus = r;
}

void Pair::SetEng(string e)
{
	eng = e;
}


Dictionary::Dictionary()
{
	size = 0;
	arr = nullptr;
}

Dictionary::Dictionary(int s)
{
	size = s;
	arr = new Pair[s];
}

Dictionary::Dictionary(const Dictionary& s)
{
	size = s.size;
	arr = new Pair[size];
	for (int i = 0; i < size; i++)
		arr[i] = s.arr[i];
}

void Dictionary::Output()
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << "\t";

	cout << endl << endl;
}

Dictionary::~Dictionary()
{
	delete[] arr;
}

ostream& operator<< (ostream& os, const Pair& obj)
{
	os << obj.rus << " " << obj.eng;
	return os; 
}

ostream& operator<< (ostream& os, const Dictionary& obj)
{
	for (int i = 0; i < obj.size; i++)
		os << obj.arr[i] << "\t";

	return os;
};




int main()
{
	setlocale(0, "");
	
	int x;
	cout << "Amount words?";
	cin >> x;
	Dictionary obj2(x);

	while(1)
	{
		cout << "1 - Input Words" << endl
			<< "2 - Search Word" << endl
			<< "3 - Edit Word" << endl
			<< "4 - Print Words" << endl << endl;

		int menu;
		cin >> menu;
		string temp;

		if (menu == 2 || menu == 3)
		{
			cout << "Your word?";
			cin >> temp;
		}

		switch (menu)
		{
		case 1:
			obj2.Input();
			break;
		case 2:
			obj2.Search(temp);
			break;
		case 3:
			obj2.Edit(temp);
			break;
		case 4:
			obj2.Output();
			break;
		}
	}
}