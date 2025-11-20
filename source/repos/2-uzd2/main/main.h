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
using std::vector;

class studentas {
private:
    string vardas;
    string pavarde;
    vector<int> pazymiai;
    int egzaminas;
    double galutinis;
    double galutinis_mediana;

    double vidurkis() {
        int suma = 0;
        for (int sk : pazymiai) {
            suma = suma + sk;
        }
        return (double)suma / pazymiai.size();
    }

    double mediana() {
        std::sort(pazymiai.begin(), pazymiai.end());

        size_t n = pazymiai.size();
        if (n % 2 == 0) {
            return (double)(pazymiai[(n - 1) / 2] + pazymiai[n / 2]) / 2.0;
        }
        return (double)pazymiai[n / 2];
    }
public:
    studentas() : egzaminas(0), pavarde(""), vardas(""), galutinis(0.0), galutinis_mediana(0.0) {};
    // set
    void setVardas(string v) {
        vardas = v;
    }
    void setPavarde(string p) {
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
        galutinis = round((vidurkis() * 0.4 + double(egzaminas) * 0.6) * 100) / 100;
        galutinis_mediana = round((mediana() * 0.4 + double(egzaminas) * 0.6) * 100) / 100;
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
    // Destructor
    ~studentas() {};

    // Copy constructor
    studentas(const studentas& stud)
        : vardas{ stud.vardas }, pavarde{ stud.pavarde }, egzaminas{ stud.egzaminas }, galutinis{ stud.galutinis }, galutinis_mediana{ stud.galutinis_mediana }
    {
        for (int i = 0; i != stud.pazymiai.size(); i++)
            pazymiai[i] = stud.pazymiai[i];
    }
};


void lentele(vector<studentas>, string);
void generuoti_failus(int, int, string);
void rasymas_i_faila(vector<studentas>, string);

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