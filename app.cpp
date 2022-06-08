#include <iostream>
#include <vector>
#include <sstream>
#include "User.h"
#include "Paper.h"
using namespace std;

vector<User> users;
vector<Paper> papers;
vector< pair<int, int> > user_paper;


void error(int a)
{
    switch (a)
    {
    case 0:
        cout << "enter valid input\n";
        break;
    case 101:
        cout << "your password is too weak\n";
    break; case 102:
        cout << "your password size must be larger than 8 character\n";
    break; case 300:
        cout << "the date is not valid\n";
    break; case 400:
        cout << "your paper id is not valid\n";
    break; case 401:
        cout << "your text have less or equal 3 paragraph\n";
    break; case 402:
        cout << "your text have not editor standard\n";
    break; case 403:
        cout << "your name is latge than 12\n";
    break; case 404:
        cout << "namber of words in text is Unacceptable\n";
    break; case 405:
        cout << "a word in text use more 50 fold\n";
    break;
    }
}

void show_all_users()
{
    if (users.size() == 0)
        cout << "-- have no user!\n";
    for (int i = 0; i < users.size(); i++)
    {
        cout << i << " : " << users[i] << '\n';
    }
}

void check_paper_id()
{
    int t;
    cout << "enter paper id:";
    cin >> t;
    if (t >= papers.size())
    {
        throw 300;
    }
    papers[t].check_grace();
}

void add_new_user()
{
    users.push_back(User().get_in_console());
    cout << "user created successfully !\n";
}

void add_new_paper()
{
    papers.push_back(Paper().get_in_console());
    cout << "enter authors id (finished by -1):";
    int d;
    cin >> d;
    while (d != -1)
    {
        if (d >= users.size()) cout << "we have not this user id\n";
        cin >> d;
        user_paper.push_back({d,papers.size()-1});
    }
    bool accept = true;
    for (int i = 0; i < papers.size() - 1; i++)
    {
        d = papers[papers.size()-1].persent_simile(papers[i]);
        if (d > 50)
        {
            cout << "this has more simile " << d << " percent with paper id: " << i << '\n';
            accept = false;
        }
    }
    if (accept) papers[papers.size()-1].accept();
    cout << "paper created successfully !\n";
}

void menu()
{

    cout << "\n1.new account\n";
    cout << "2.show account\n";
    cout << "3.add new paper\n";
    cout << "4.check grace paper\n";

    cout << "enter your number:";
}

int main()
{
    string tmp;
    while (true)
    {
        menu();
        cin >> tmp;
        if (tmp == "exit")
            break;
        try
        {
            switch (tmp[0])
            {
            case '1':
                add_new_user();
                break;

            case '2':
                show_all_users();
                break;

            case '3':
                add_new_paper();
                break;

            case '4':
                check_paper_id();
                break;

            default:
                throw 0;
            }
        }
        catch (int a)
        {
            error(a);
        }
    }
}

