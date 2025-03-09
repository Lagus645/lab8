#include <iostream>
#include <clocale>
#include <fstream>
#include <string>
#include <Windows.h>
#define T << '\n' <<

using namespace std;

int n;

struct Patient
{
    string FIO;
    string address;
    int num_card;
    int num_pol;
};

// Заполнение файла первоначальными данными
void n_print()
{
    ofstream output("Patient.dat", ios::binary);
    cout << "Введите номер медкарты человека, которого хотите удалить: ";
    cin >> n;
    Patient h1, h2, h3;
    h1.FIO = "Иванов Семен Сергеевич";
    h1.address = "Чернышевского, 17А";
    h1.num_card = 96669;
    h1.num_pol = 748980;

    h2.FIO = "Мамонтов Алексей Геннадьевич";
    h2.address = "Мамонтова, 777";
    h2.num_card = 97779;
    h2.num_pol = 748988;

    h3.FIO = "Морозов Павел Трофимович";
    h3.address = "Герасимовка, 13";
    h3.num_card = 96131;
    h3.num_pol = 748913;
    output << 3 << '\n';
    output << h1.FIO T h1.address T h1.num_card T h1.num_pol << '\n';
    output << h2.FIO T h2.address T h2.num_card T h2.num_pol << '\n';
    output << h3.FIO T h3.address T h3.num_card T h3.num_pol << '\n';
    output.close();
    return;
}

// Ручное написание двух новых людей
void w_humans()
{
    ofstream output2("Patient2.dat", ios::binary);
    cout << "Введите данные двух новых пациентов\n\n";
    for (int i = 1; i < 3; i++)
    {
        cout << i << "\nФИО: ";
        Patient H;
        ws(cin);
        getline(cin, H.FIO);
        output2.write(H.FIO.c_str(), H.FIO.size());
        output2 << '\n';
        cout << "Домашний адрес: ";
        getline(cin, H.address);
        output2.write(H.address.c_str(), H.address.size());
        output2 << '\n';
        cout << "Номер медицинской карты: ";
        cin >> H.num_card;
        output2 << H.num_card << '\n';
        cout << "Номер полиса: ";
        cin >> H.num_pol;
        cout << '\n';
        output2 << H.num_pol << '\n';
    }
    output2.close();
    return;
}

// Удаление
void d_human()
{
    ifstream input("Patient.dat", ios::binary);
    ofstream output2("Patient2.dat", ios::binary | ios::app);

    if (input.is_open())
    {
        int t;
        input >> t;
        while (t)
        {
            Patient H;
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
            getline(input >> ws, H.FIO);
            getline(input, H.address);
            input >> H.num_card;
            input >> H.num_pol;
            if (n != H.num_card)
            {
                output2.write(H.FIO.c_str(), H.FIO.size());
                output2 << '\n';
                output2.write(H.address.c_str(), H.address.size());
                output2 << '\n';
                output2 << H.num_card T H.num_pol << '\n';
            }
            t--;
        }
        input.close();
    }
    else cerr << "Файл не открылся";
    output2.close();
    return;
}

int main()
{
    setlocale(LC_ALL, "russian");

    w_humans();
    n_print();
    d_human();

    return 0;
}
