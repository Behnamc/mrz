using namespace std;

class Date
{
public:
	int year;
	int month;
	int day;

    Date(){}

	Date(int year, int month, int day);

	Date(string s);

	friend ostream& operator<<(ostream& os, Date const& d)
	{
		return os << d.year << '/' << d.month << '/' << d.day << '\n';
	}

};

Date::Date(int year, int month, int day)
{
	this->year = year;
	this->month = month;
	this->day = day;
}

Date::Date(string a)
{
    int n = 0;
    for (auto &i: a)
    {
        if (i == '/') n++;
        else if ('0' > i || i > '9') throw 300;
    }
    if (n != 2)
        throw 300;
    n = 0;
    int m[3] = {0,0,0};
    for(auto &i: a)
    {
        if (i != '/')
        {
            m[n] *= 10;
            m[n] += i - '0';
        }
        else
            n++;

    }
    this->year = m[0];
    this->month = m[1];
    this->day = m[2];
}
