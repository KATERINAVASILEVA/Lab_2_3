#include <iostream>

class String
{
    char* m_str;
    size_t m_size;

public:
    String(const char* s) //Конструктор
    {
        m_size = strlen(s) + 1;
        m_str = new char[m_size];
        std::copy(s, s + m_size, m_str);
    }

    //Конструктор по умолчанию 
    String() {
        m_size = 0;
        m_str = new char[m_size];
    }

    //Конструктор копирования
    String(const String& other) //: String(other.m_str)
    {
        m_size = other.m_size;
        m_str = new char[m_size];
        std::copy(other.m_str, other.m_str + m_size, m_str); 
    }

    //Оператор присваивания копиованием
    String& operator=(const String& other)
    {
        delete[] m_str;
        m_size = other.m_size;
        m_str = new char[m_size];
        std::copy(other.m_str, other.m_str + m_size, m_str);
        return *this;
    }

    void Print() const
    {
        std::cout << m_str << std::endl;
    }
    //Деструктор
    ~String()
    {
        delete[] m_str;
    }
};

int main()
{
    String s1("mew");
    String s3("meow");

    String words[5];

    String s2 = s1;      //Конструктор копирования
    s2.Print();

    s1 = s2 = s3;        //Оператор присваивания копированием

    s1.Print();
    s3.Print();
    /*
    for (int i = 0; i < 5; i++)
    {

    }*/
}

