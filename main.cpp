#include <iostream>
#include <fstream>
using namespace std;
class Register
{
    string re_passwd;

protected:
    string user_name;
    string password;

public:
    void getdata()                                      //input data to be registered.
    {
        cout << "Enter user name: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;
        cout << "Enter password again: ";
        cin >> re_passwd;
        check();
    }
    void writedata()                                    //writing data to file.
    {
        if (password == re_passwd)
        {
            fstream data;
            data.open("data.dat", ios::app);
            if (!data)
            {
                cout << "There is some error, try again!";
            }
            else
            {
                data << user_name;
                data << endl;
                data << password << endl;
                data.close();
                cout<<"User successfully registered.";
            }
        }
        else
        {
            cout << "Password doesn't match. Enter again!!!" << endl;
            getdata();
        }
    }
    void check()                                        //checking already registered user.
    {
        int count1 = 0;
        fstream data;
        data.open("data.dat", ios::in);
        if (data)
        {
            string user;
            string passwd;

            while (1)
            {
                data >> user;
                data >> passwd;
                if (user == user_name)
                    count1++;
                if (data.eof())
                    break;
            }
            if (count1 != 0)
            {
                cout << "Invalid user name. Please enter another user name! " << endl;
                getdata();
            }
            else
            {
                writedata();
            }
        }
        else
            writedata();

        data.close();
    }
};
class Login : public Register
{
    int count = 0;

public:
    void input()                                        //input user name and password to login.
    {
        cout << "Enter user name: ";
        cin >> user_name;
        cout << "Enter password: ";
        cin >> password;
        readdata();
    }
    void readdata()                                     //read data from file.
    {
        fstream data;
        data.open("data.dat", ios::in);
        if (!data)
        {
            cout << "No such file";
        }
        else
        {
            string user;
            string passwd;

            while (1)
            {
                data >> user;
                data >> passwd;
                if (user_name == user && password == passwd)
                {
                    count++;
                    break;
                }
                if (data.eof())
                    break;
            }
            if (count != 0)
                cout << "login successful " << endl;
            else
            cout<<"Login failed! please check your user name and password.";
        }
        data.close();
    }
};
int main()
{
    int num;
    cout << "1. Regsiter" << endl;
    cout << "2. Login" << endl;
    cout << "Enter your choice(1/2): ";
    cin >> num;
    Login obj;
    switch (num)                                //Enter choise
    {
    case 1:
        obj.getdata();
        break;
    case 2:
        obj.input();
        break;
    default:
        cout << "Invalid Choice!!!" << endl;
        break;
    }
    return 0;
}
