// PK3-projekt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <iostream>
#include<memory>
#include "Lista.h"
#include "Node.h"
#include "Przelaczniki.h"
#include "Pojazdy.h"
#include "Osoby.h"

using namespace std;
int main(int argc, char** argv)
{{
    LinkedList<int> llist{};
   
    llist.insert_head(10);
    llist.insert_head(20);
    llist.insert_head(30);
    
    llist.insert_tail(1);
    llist.insert_tail(2);

    llist.insert(0, 111);
    llist.insert(30, 222); 
    llist.insert(6, 333);

    int value1 = 20, value2 = 200;
    cout << "Element1 = " << llist.search(value1) << endl;
    cout << "Element2 = " << llist.search(value2) << endl;

    llist.show();
    //cout << llist;
    int counter = llist.size();

    llist.sortUp(counter);
    llist.show();
    cout << "Remove " << endl;
    llist.remove_head();
    llist.remove_head();
    llist.show();
    cout << "Number of elements: " << llist.size() << endl;

    llist.remove_tail();
    llist.remove_tail();
    llist.show();
    cout << "Number of elements: " << llist.size() << endl;

    llist.remove(1);
    llist.show();
    cout << "Number of elements: " << llist.size() << endl;

    //llist.getData("p.bin");
    //llist.throwData("p.bin");
    llist.show();
    // recznie robione
    string fileName = "Osoby.txt";
    LinkedList<Person> listO;
    //Vehicle p( "Mati", "G", 1020);
    //listO.insert_head(p);
    //listO.insert_head(p);
    //listO.insert_head(p);
    listO.getData(fileName);
    listO.throwData("nowy2.bin");
    //listO.getData("nowy2.bin");
    //listO.throwData("nowy2.bin");
    listO.show();
    //Person person;
    //cout << "podaj";
    //cin >> person.pesel >> person.name >> person.surname >> person.gender;
    //cout<< listO.search(person);
    //przelaczniki
    string plikWejsciowy, plikWyjsciowy;
    if (odczytajPrzelaczniki(argc, argv, plikWejsciowy, plikWyjsciowy))
    {

        LinkedList<Person> lista;


        lista.getData(plikWejsciowy);


        int work = true;
        int number;

        while (work) {
            cout << endl;
            cout << "MENU:" << endl;
            cout << "1.Dodaj element na poczatek" << endl;
            cout << "2.Dodaj element na koniec" << endl;
            cout << "3.Dodaj element w wybrane miejsce" << endl;
            cout << "4.Usun pierwszy element" << endl;
            cout << "5.Usun ostatni element" << endl;
            cout << "6.Usun wybrany element" << endl;
            cout << "7.Szukaj pozycji elementu" << endl;
            cout << "8.Zwroc ilosc elementow listy" << endl;
            cout << "9.Pokaz zawartosc listy" << endl;
            cout << "10.Posortuj liste rosnaco" << endl;
            cout << "11.Posortuj liste malejaco" << endl;
            cout << "12.Zapisz w pliku wyjsciowym." << endl;
            cout << "13.Koniec programu" << endl;
            cin >> number;
            switch (number)
            {
            case 1:
            {
                cout << "Podaj zawartosc tego elementu: " << endl;
                Person person;
                cout << " pesel: ";
                cin >> person.pesel;
                cout << " imie: ";
                cin >> person.name;
                cout << " nazwisko: ";
                cin >> person.surname;
                cout << " plec(k/m): ";
                cin >> person.gender;
                lista.insert_head(person);
                break;
            }
            case 2:
            {
                cout << "Podaj zawartosc tego elementu: " << endl;
                Person person;
                cout << " pesel: ";
                cin >> person.pesel;
                cout << " imie: ";
                cin >> person.name;
                cout << " nazwisko: ";
                cin >> person.surname;
                cout << " plec(k/m): ";
                cin >> person.gender;
                lista.insert_tail(person);
                break;
            }
            case 3:
            {
                cout << "Podaj zawartosc tego elementu: " << endl;
                Person person;
                cout << " pesel: ";
                cin >> person.pesel;
                cout << " imie: ";
                cin >> person.name;
                cout << " nazwisko: ";
                cin >> person.surname;
                cout << " plec(k/m): ";
                cin >> person.gender;
                cout << "Podaj nr indeksu, gdzie chcesz wstawic: ";
                int indeks;
                cin >> indeks;
                lista.insert(indeks, person);
                break;
            }
            case 4:
            {
                lista.remove_head();
                break;
            }
            case 5:
            {
                lista.remove_tail();
                break;
            }
            case 6:
            {
                int indeks;
                cout << "Podaj indeks elementu do usuniecia: ";
                cin >> indeks;
                lista.remove(indeks);
                break;
            }
            case 7:
            {
                cout << "Podaj zawartosc tego elementu: " << endl;
                Person person;
                cout << " pesel: ";
                cin >> person.pesel;
                cout << " imie: ";
                cin >> person.name;
                cout << " nazwisko: ";
                cin >> person.surname;
                cout << " plec(k/m): ";
                cin >> person.gender;
                cout << "Element znajduje sie na pozycji: ";
                cout << lista.search(person);
                break;
            }
            case 8:
            {
                cout << "Ilosc elementow w liscie: " << lista.size();
                break;
            }
            case 9:
            {
                lista.show();
                break;
            }
            case 10:
            {
                int counter;
                counter = lista.size();
                lista.sortUp(counter);
                break;
            }
            case 11:
            {
                int counter;
                counter = lista.size();
                lista.sortDown(counter);
                break;
            }
            case 12:
            {
                lista.throwData(plikWyjsciowy);
                break;
            }
            case 13:
                cout << "Koniec programu " << endl;
                work = false;
                break;
            }
        }
    }
    
}
    _CrtDumpMemoryLeaks();
    
    return 0;
}

