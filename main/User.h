using namespace std;

class User
{
private:
	string name;
	string password;
	bool is_login;

	void password_is_hard();

public:
	User() {}
	User get_in_console();

	void login(string password);

	void logout();

	friend ostream& operator<<(ostream& os, User const& u)
	{
		return os << u.name << '\n';
	}
};



void User::password_is_hard()
{
	string hard_list = "!@#$%^&*()_+=-`~";

	if (password.size() < 8)
		throw 102;

	for (auto& i : password)
	{
		for (auto& j : hard_list)
		{
			if (i == j) return;
		}
	}
	throw 101;
}

void User::logout()
{
	is_login = false;
}

User User::get_in_console()
{
	cout << "enter your name:";
	cin >> this->name;
	cout << "enter your password:";
	cin >> this->password;
	password_is_hard();
	this->is_login = true;
	return *this;
}
