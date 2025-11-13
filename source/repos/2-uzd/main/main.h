#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>
#include <chrono>
#include <vector>
#include <list>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::right;
using std::list;
using std::vector;
/*
struct studentas {
    string vardas;
    string pavarde;
    vector<int>pazymiai;
    //list<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
};
*/

class studentas {
private:
    string vardas;
    string pavarde;
    vector<int>pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;
public:
    studentas() : egzaminas(0) {};
    // set
    void setVardas(string v) {
        vardas = v;
    }
    void serPavarde(string p) {
        pavarde = p;
    }
    void setEgzaminas(int e) {
        egzaminas = e;
    }
    // vector
    void setPazymiai(vector<int> paz) {
        pazymiai = paz;
    }
    // Galutinis su mediana ir vidurkiu
    void setGalutinis() {
        if (pazymiai.size() == 0 or egzaminas == 0) {
            cout << "Neįvesti pazymiai arba egzaminas" << endl;
        }
        // Su vidurkiu
        int suma = 0;
        for (int sk : pazymiai) {
            suma = suma + sk;
        }
        galutinis = (double)suma / pazymiai.size();

        //Su mediana
        std::sort(pazymiai.begin(), pazymiai.end());
        size_t n = pazymiai.size();
        if (n % 2 == 0) {
            galutinis_mediana = (double)(pazymiai[(n - 1) / 2] + x[n / 2]) / 2.0;
        }
        else {
            galutinis_mediana = (double) pazymiai[n / 2];
        }
    }
    // Get
    string getVardas() {
        return vardas;
    }
    string getPavarde() {
        return pavarde;
    }
    double getGalutinisVidurkis() {
        return galutinis;
    }
    double getGalutinisMediana() {
        return galutinis_mediana;
    }
    
};


double mediana(vector<int> /*list<int>*/);
double vidurkis(/*list<int>*/ vector<int>);

void lentele(vector<studentas> /*list<studentas>*/, string);
double galutinio_sk(double, int);
void generuoti_failus(int, int, string);
void rasymas_i_faila(vector<studentas> /*list<studentas>*/, string);

bool palyginti(studentas, studentas);
bool palyginti_vardas(studentas, studentas);
bool palyginti_pavarde(studentas, studentas);
bool palyginti_galutinis(studentas, studentas);

std::stringstream failo_skaitimas(string);
studentas studentas_uzpildimas(string);

class timer {
    using hrClock = std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;
private:
    std::chrono::time_point<hrClock> start;
public:
    timer() : start{ hrClock::now() } {}
    void reset() {
        start = hrClock::now();
    }
    double elapsed() const {
        return durationDouble(hrClock::now() - start).count();
    }
};