#include "main.h"

studentas studentas_uzpildimas(string eil) {
    studentas laikinas;
    string zod;
    string vardai;
    std::stringstream dalys(eil);

    dalys >> vardai;
    laikinas.setVardas(vardai);

    dalys >> vardai;
    laikinas.setPavarde(vardai);

    vector<int> lv;
    while (dalys >> zod) {
        lv.push_back(std::stoi(zod));
    }
    laikinas.setEgzaminas(lv.back());
    lv.pop_back();
    laikinas.setPazymiai(lv);
    
    laikinas.setGalutinis();
    return laikinas;
}

std::stringstream failo_skaitimas(string failo_vardas) {
    std::stringstream buffer;
    string eil;
    string zod;

    std::ifstream fl(failo_vardas);
    buffer << fl.rdbuf();
    fl.close();
    return buffer;
}

void rasymas_i_faila(vector<studentas>x , string failo_vardas) {
    string visas;
    string galut_v;
    string galut_m;
    for (studentas laik : x) {
        galut_v = std::to_string(laik.getGalutinisVidurkis()).substr(0, 4);
        galut_m = std::to_string(laik.getGalutinisMediana()).substr(0, 4);
        visas += laik.getVardas() + " " + laik.getPavarde() + " " + galut_v + " " + galut_m + "\n";
    }
    std::ofstream out_f(failo_vardas);
    out_f << visas;
    out_f.close();
}

void lentele(vector<studentas> x, string y) {
 
    std:sort(x.begin(), x.end(), palyginti);
    cout << setw(15) << left << "Vardas" << setw(15) << left << "Pavarde" << setw(15) << right;
    if (y == "V") {
        cout << "Galutinis pazymis(Vid.)" << setw(40) << right << "Objekto saugojimo atmintyje adresas" << endl;
        for (studentas laik : x) {
            cout << setw(15) << left << laik.getVardas() << setw(15) << left << laik.getPavarde() << setw(17) << right << laik.getGalutinisVidurkis() << setw(44) << right << &laik << endl;
        }
    }
    else if (y == "M") {
        cout << "Galutinis pazymis(Median.)" << setw(40) << right << "Objekto saugojimo atmintyje adresas" << endl;
        for (studentas laik : x) {
            cout << setw(15) << left << laik.getVardas() << setw(15) << left << laik.getPavarde() << setw(17) << right << laik.getGalutinisMediana() << setw(44) << right << &laik << endl;
        }
    }
    else if (y == "A") {
        cout << "Galutinis pazymis(Vid.) Galutinis pazymis(Median.)" << setw(40) << right << "Objekto saugojimo atmintyje adresas" << endl;
        for (size_t a = 0; a < 120; a++) {
            cout << "-";
        }
        cout << endl;
        for (studentas laik : x) {
            cout << setw(15) << left << laik.getVardas() << setw(15) << left << laik.getPavarde() << setw(24) << left << laik.getGalutinisVidurkis() << left << laik.getGalutinisMediana() << setw(44) << right << &laik << endl;
        }
    }
}

void generuoti_failus(int studentu_sk, int darbu_sk, string failo_vardas) {
    using hrClock = std::chrono::high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(1, 10);

    string visas;

    for (int i = 1; i <= studentu_sk; i++) {
        string str;
        str += "\n";
        str += "Vardas" + std::to_string(i) + " " + "Pavarde" + std::to_string(i);
        for (int j = 0; j <= darbu_sk; j++) {
            str += " " + std::to_string(dist(mt));
        }
        visas += str;
    }
    std::ofstream file(failo_vardas);
    file << visas;
    file.close();
}


bool palyginti(studentas a,studentas b) {
    if (a.getVardas() != b.getVardas()) {
        return a.getVardas() > b.getVardas();
    }
    return a.getGalutinisVidurkis() > b.getGalutinisVidurkis();
}

bool palyginti_vardas(studentas a, studentas b) {
    return a.getVardas() > b.getVardas();
}

bool palyginti_pavarde(studentas a, studentas b) {
    return a.getPavarde() > b.getPavarde();
}

bool palyginti_galutinis(studentas a, studentas b) {
    return a.getGalutinisVidurkis() > b.getGalutinisVidurkis();
}
