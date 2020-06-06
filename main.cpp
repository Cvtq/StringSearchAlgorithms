#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include "search.h"
#include "aho-corasick.h"


using std::cout;
using std::endl;


int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Отсчет идет с нуля" << endl;

    {
        char txt[] = "123456789 123456789";
        char pat[] = "56";
        cout << endl << "Текст: " << endl << txt << endl << "Шаблон: " << endl << pat << endl << endl;
        {
            cout << "Алгоритм Рабина-Карпа: " << endl;
            int q = 101; // простое число
            search(pat, txt, q);
            cout << endl;
        }
        {
            cout << "Алгоритм Кнута-Мориса-Прата: " << endl;
            KMPSearch(pat, txt);
            cout << endl;
        }
        {
            cout << "Алгоритм Боуера-Мура: " << endl;
            search(txt, pat);
            cout << endl;
        }
    }

    {
        char txt[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
        char pat[] = "dolor";

        cout << endl << "Текст: " << endl << txt << endl << "Шаблон: " << endl << pat << endl << endl;
        {
            cout << "Алгоритм Рабина-Карпа: " << endl;
            int q = 101; // простое число
            search(pat, txt, q);
            cout << endl;
        }
        {
            cout << "Алгоритм Кнута-Мориса-Прата: " << endl;
            KMPSearch(pat, txt);
            cout << endl;
        }
        {
            cout << "Алгоритм Боуера-Мура: " << endl;
            search(txt, pat);
            cout << endl;
        }
    }

    {
        cout << "Алгоритм Ахо-Корасик: " << endl;
        const char txt[] = "hishers";
        cout << "Текст: " << endl << txt << endl << "Словарь для поиска: " << endl;

        bohr_ini();
        vector<string> dict = { "he", "she", "hers", "his" };

        for (size_t i = 0; i < dict.size(); i++) {
            cout << dict[i] << " ";
            add_string_to_bohr(dict[i]);
        }
        cout << endl;
              
        find_all_pos(txt);
        cout << endl;
    }
}

