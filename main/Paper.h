#include "Date.h"
#include <vector>
#include <map>
using namespace std;

class Paper
{
private:
    string name;
    Date date;
    string text;
    bool grace;
    vector<string> refrences;
    map<string, int> words;

    void editor_standard();

    void have_three_part();

    void name_is_correct();

    void set_map_worlds();

    void zigma_words__50word();

public:
    Paper(){date=Date();}

    void check_grace();

    void set_grace();

    int persent_simile(Paper b);

    Paper get_in_console();

    void accept();

};

void Paper::accept()
{
    grace = true;
}

// todo show all data
void Paper::check_grace()
{


    if (grace)
    {
        cout << "accept\n";
    }
    else
    {
        cout << "reject\n";
    }


}

Paper Paper::get_in_console()
{
    cout << "enter paper\'s name:";
    cin >> this->name;
    cout << "enter paper\'s create date (like 2021/12/2):";
    string d;
    cin >> d;
    this->date = Date(d);
    cout << "enter paper\'s text: (finished by ~):";
    getline(cin, this->text,'~');
    cout << "enter paper\'s refrences (finished by ~):";
    cin >> d;
    while (d != "~")
    {
        this->refrences.push_back(d);
        cin >> d;
    }
    set_grace();
    return *this;
}

int Paper::persent_simile(Paper b)
{
    // todo
    return 0;
}

void Paper::editor_standard()
{
    bool isKapital = true;
    int p;
    for (int i = 0; i < text.size(); i++)
    {
        if (isKapital)
        {
            if (text[i] < 'A' || text[i] > 'Z')
                throw 402;
            isKapital = false;
        }
        else if (text[i] == '\n'
                || text[i] == '.'
                || text[i] == '?'
                || text[i] == '!'
                || text[i] == ';')
        {
            isKapital = true;
            if (i + 1 < text.size() && text[i] != '\n')
                if (text[i + 1] != ' '
                    || text[i + 1] == '.'
                    || text[i + 1] == '?'
                    || text[i + 1] == '!'
                    || text[i + 1] == ';') throw 402;
        }
        if (text[i] == '(') p++;
        else if (text[i] == ')')p--;
    }
    if (p != 0) throw 402;
}

void Paper::have_three_part()
{
    int ans = 0;
    for(auto &i: text)
    {
        if (i == '\n')
            ans++;
    }
    if (ans < 3) throw 401;
}

void Paper::name_is_correct()
{
    int ans = 1;
    for (int i = 0; i < text.size(); i++)
    {
        if (name[i] == ' ' && i+1 < name.size() && name[i+1] != ' ')
            ans++;
    }
    if (ans > 12) throw 403;
}

void Paper::set_map_worlds()
{
    string b;
    istringstream stream(text);
    while (stream >> b)
    {
        if (b[b.size() - 1] == '\n'
            || b[b.size() - 1] == '?'
            || b[b.size() - 1] == '.'
            || b[b.size() - 1] == '!')
        {
            string c = "";
            for (int i = 0; i < b.size() - 1; i++) c = c + b[i];
            b = c;
        }
        words[b]++;
    }
}

void Paper::zigma_words__50word()
{
    int ans = 0;
    for (auto it = words.begin(); it != words.end(); it++)
    {
        if (it->second > 50)
            throw 405;
        ans += it->second;
    }
    if (ans < 100 || ans > 5000) throw 404;
}

void Paper::set_grace()
{
    editor_standard();
    set_map_worlds();
    have_three_part();
    zigma_words__50word();
    have_three_part();
    this->grace = true;
}
