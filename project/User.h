#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED

#define GETTER(T,member) const T& get##member() const { return member; }
#define SETTER(T,member) void set##member(const T & value) { member = value; }

using namespace std;

class User
{
public:
    //GETCONSOLE(name, 60)

    void get()
    {

    }

    void get_console_name(int max_size)
    {
        cout << "set " + "name" + ":";
        cin >> name;
        if (name.size() > max_size)
            throw string("length of" + "name" + "must be smaller than " + max_size);
    }

private:
    string name;
};



/*

*/


#endif // USER_H_INCLUDED
