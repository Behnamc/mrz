#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define GETCON(m) cout<<"enter "<<#m<<":";cin>>m;
#define SETTER(m, s) string m;void set##m(){string w=#m;GETCON(m) if(m.size()>(s))throw string("your "+w+" size must be less than "+to_string((s)));}

using namespace std;

typedef long long ll;


class Stock
{

public:
    Stock() {}
    Stock(string symbol, string longname, ll price, ll bazar)
    {
        this->symbol = symbol;
        this->longname = longname;
        this->price = price;
        this->bazar = bazar;
        this->value = 0;
    }

    friend ostream& operator<<(ostream& os, Stock const& s)
	{
		return os << s.symbol << " | " << s.longname
		<< " | " << s.price << " | " << s.bazar << " | "
		<< "you have " << s.value << " in bascket.\n";
	}


    SETTER(symbol, 5)
    SETTER(longname, 50)
    ll price;
    ll bazar;
    ll value;
};

class User
{
public:
    User()
    {
        password = "";
        shaba = "";
        money = 0;
    }

    void login()
    {
        setusername();
        setpassword();
    }

    void get_console()
    {
        setfullname();
        setnationalcode();
        setshaba();
        if (shaba.size() < 3 || shaba[0] != 'I' || shaba[1] != 'R')
            throw string("shaba must start with 'IR...' ");
        GETCON(money)

    }




    SETTER(username, 10)
    SETTER(password, 20)
    SETTER(fullname, 50)
    SETTER(nationalcode, 10)
    SETTER(shaba, 12)
    ll money;
    ll stocks_value;
    vector<Stock> stocks;

};


User u;
vector<Stock> stocks;

void create_user()
{
    u.login();
}

void change_information()
{
    u.get_console();
}

void withdraw()
{
    ll money;
    cout << "enter money value\n(enter negetive if you want Removal):";
    cin >> money;
    if (money + u.money < 1000 * 1000)
        throw string("you cant Debit greater than 1 milion");
    u.money += money;
}

void buy_stock()
{
    string symbol;
    int value;
    GETCON(symbol)
    GETCON(value)
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].symbol == symbol)
        {
            if (stocks[i].price * value > u.money)
                throw string("you have not enough money to buy this stock");
            u.money -= stocks[i].price * value;
            stocks[i].value += value;
            return;
        }
    }
    throw string("the symbol name is not in stock list");
}

void sell_stock()
{
    string symbol;
    int value;
    GETCON(symbol)
    GETCON(value)
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].symbol == symbol)
        {
            if (stocks[i].value < value)
                throw string("you have not this value from this stock in bascket");
            stocks[i].value -= value;
            u.money += stocks[i].price * value;
            return;
        }
    }
    throw string("the symbol name is not in stock list");
}

void see_bascket()
{
    for (int i = 0; i < stocks.size(); i++)
    {
        if (stocks[i].value > 0)
        {
            cout << stocks[i] << endl;
        }
    }
}

void see_stock_list()
{
    for (int i = 0; i < stocks.size(); i++)
    {
        cout << stocks[i] << endl;
    }
}

void save()
{

}

void load()
{

}

void show_menu()
{
    for (int i = 0; i < 35; i++)
        cout << char(220);
    cout << '\n';
    cout << char(219)<< "              menu               " << char(219) << '\n';
    cout << char(219)<< "1" << char(186) << " create user                   " << char(219) << '\n';
    if (u.nationalcode.size() == 0)
        cout << char(219)<< "2" << char(186) << " set information            " << char(219) << '\n';
    else
        cout << char(219)<< "2" << char(186) << " change information            " << char(219) << '\n';

    cout << char(219)<< "3" << char(186) << " withdraw or charging" << char(219) << '\n';
    for (int i = 0; i < 35; i++)
        cout << char(219);
    cout << '\n';
    cout << char(219)<< "4" << char(186) << " buy stock                     " << char(219) << '\n';
    cout << char(219)<< "5" << char(186) << " sell stock                    " << char(219) << '\n';
    cout << char(219)<< "6" << char(186) << " see my basket                 " << char(219) << '\n';
    cout << char(219)<< "7" << char(186) << " see stock list and price      " << char(219) << '\n';
    cout << char(219)<< "8" << char(186) << " save                          " << char(219) << '\n';
    cout << char(219)<< "9" << char(186) << " save and exit                 " << char(219) << '\n';
    for (int i = 0; i < 35; i++)
        cout << char(223);
    cout << '\n';
    cout <<"enter your number:";
}

void load_csv()
{
    vector<string> row;
    string line, word;

    fstream file ("stock_market_data.csv", ios::in);
    if(file.is_open())
    {
        while(getline(file, line))
        {
            row.clear();

            stringstream str(line);

            while(getline(str, word, ','))
                row.push_back(word);
            cout << "--add " << row[3] << "   " << row[4] << endl;
            //ll a = stof(row[3]);
            //stocks.push_back(Stock(row[1], row[2], stof(row[3]), stoll(row[4])));
        }
    }
    else
        cout<<"Could not open the csv file\n";
}

void solve()
{
    load_csv();
    load();
    string inp;
    while (true)
    {
        show_menu();
        cin >> inp;
        try{
            if (u.password.size() == 0 && inp[0] != '1')
                throw string("you must signup first");
            if (u.shaba.size() == 0 && inp[0] != '2')
                throw string("you must set information first");
            switch (inp[0])
            {
            case '1':
                create_user();
                break;
            case '2':
                change_information();
                break;
            case '3':
                withdraw();
                break;
            case '4':
                buy_stock();
                break;
            case '5':
                sell_stock();
                break;
            case '6':
                see_bascket();
                break;
            case '7':
                see_stock_list();
                break;
            case '8':
                save();
                break;
            case '9':
                save();
                return;
                break;
            default:
                throw string("please enter valid!");
            }
        } catch(string s) {
            cout << char(175) << char(175) << char(175) << "  :  " << s << endl;
        }
    }

}

int main() {
    solve();
    //Stock s = Stock("AAPL", "Apple Inc.", stof("147.11"), stoll("2413545390080"));
}




