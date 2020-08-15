#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class MyStr
{
    private:
        int id;
        char* name;
    public:
        MyStr():id(0), name(NULL){}
        //1.
        MyStr(int _id, char* _name)
        {
            cout << "constructor" << endl;
            id = _id;
            name = new char[strlen(_name) + 1];
            //strcpy_s(name, strlen(_name) + 1, _name);
            strcpy(name, _name);
        }
        //2.
        MyStr(const MyStr& str)
        {
            cout<< "copy constructor" << endl;
            id = str.id;
            name = new char[strlen(str.name)+1];
            //strcpy_s(name, strlen(str.name)+1, str.name);
            strcpy(name, str.name);
        }
        //3.
        MyStr& operator =(const MyStr& str)
        {
            cout<< "operator" << endl;
            if(this != &str)
            {
                if(name != NULL)
                {
                  delete []name;
                }
                this->id = str.id;
                name = new char[strlen(str.name)+1];
                //strcpy_s(name, strlen(str.name)+1, str.name);
                strcpy(name, str.name);
            }
            return *this;
        }
        ~MyStr()
        {
          delete[] name;
        }
};

int main() {
  std::cout << "test cpp class -01\n";
  MyStr str1(1, "hahaha");
  MyStr str2;
  str2 = str1;
  MyStr str3 = str2;
}