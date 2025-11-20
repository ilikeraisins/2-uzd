#include "main.h"

int main() {
    string pasirinkimas;
    cout << "Duomenis skaityti, generuoti ar demonstruoti ,,Rule of three\"? (S/G/D)" << endl;
    cin >> pasirinkimas;

    if (pasirinkimas == "S") {
        vector<studentas> grupe;
        cout << "Ar duomenis gauti is failo? (T/N) " << endl;
        cin >> pasirinkimas;

        if (pasirinkimas == "T") {
            cout << endl << "Be to, kad studentai rusiuojami pagal varda ir galutini pazymi, pagal ka dar rusiuoti? " << endl;
            cout << "(G - galutini pazymi, P - pavarde, V - varda)" << endl;
            cin >> pasirinkimas;

            timer tv;
            string eil;

            timer t;
            std::stringstream buffer = failo_skaitimas("100000studentai.txt");
            cout << "Failo nuskaitymas: " << t.elapsed() << endl;

            std::getline(buffer, eil);

            t.reset();
            while (buffer) {
                if (!buffer.eof()) {
                    std::getline(buffer, eil);
                    studentas laikinas = studentas_uzpildimas(eil);
                    grupe.push_back(laikinas);
                }
                else break;
            };

            int dydis = grupe.size();
            vector<studentas> blogi(dydis);
            copy_if(grupe.begin(), grupe.end(), blogi.begin(), [](studentas x) {return x.getGalutinisVidurkis() < 5.0; });
            grupe.erase(std::remove_if(grupe.begin(), grupe.end(), [](studentas x) {return x.getGalutinisVidurkis() < 5.0; }), grupe.end());
            blogi.resize(dydis - grupe.size());

            if (pasirinkimas == "V") {
                std::sort(blogi.begin(), blogi.end(), palyginti_vardas);
                std::sort(grupe.begin(), grupe.end(), palyginti_vardas);
            }
            else if (pasirinkimas == "P") {
                std::sort(blogi.begin(), blogi.end(), palyginti_pavarde);
                std::sort(grupe.begin(), grupe.end(), palyginti_pavarde);

            }
            else if (pasirinkimas == "G") {
                std::sort(blogi.begin(), blogi.end(), palyginti_galutinis);
                std::sort(grupe.begin(), grupe.end(), palyginti_galutinis);
            }


            cout << "Duomenu rusiavimas: " << t.elapsed() << endl;

            t.reset();
            rasymas_i_faila(grupe, "GeraiBesimokantys.txt");
            //rasymas_i_faila(geri, "GeraiBesimokantys.txt");
            rasymas_i_faila(blogi, "BlogaiBesimokantys.txt");

            cout << "Failu isvedimas: " << t.elapsed() << endl << endl;
            cout << "Viso: " << tv.elapsed() << endl << endl;
        } 
        else {
            int n;
            cout << "Studentu skaicius: ";
            cin >> n;

            for (int i = 0; i < n; i++) {
                studentas laikinas;
                cout << "Studentas nr. " << i + 1 << endl;
                cout << "Vardas: ";
                string vard;
                cin >> vard;
                laikinas.setVardas(vard);
                cout << "Pavarde: ";
                cin >> vard;
                laikinas.setPavarde(vard);

                cout << "Pazymius ivedami ar generuojami? (V/G) " << endl;
                cin >> pasirinkimas;

                if (pasirinkimas == "G") {
                    int sk;

                    std::random_device seed;
                    std::mt19937 gen{ seed() };
                    std::uniform_int_distribution<> dist(1, 10);

                    cout << "Pazymiu skaicius: ";
                    cin >> sk;

                    vector<int> lv;
                    for (int j = 0; j < sk; j++) {
                        lv.push_back(dist(gen));
                    }
                    laikinas.setPazymiai(lv);
                    laikinas.setEgzaminas(dist(gen));
                }
                else {
                    int pazymis = 1;
                    cout << "Veskite pazymius (0 jeigu norite nustoti vesti): " << endl;

                    vector<int> lv;
                    while (pazymis) {
                        cin >> pazymis;
                        if (pazymis != 0) {
                            lv.push_back(pazymis);
                        }
                    }
                    laikinas.setPazymiai(lv);

                    int paz = 0;
                    cout << "Egzamino pazymis: ";
                    cin >> paz;
                    laikinas.setEgzaminas(paz);
                }
                laikinas.setGalutinis();
                grupe.push_back(laikinas);
            }

            cout << "Vesti lentele su vidurkiu, mediana arba abeim? (V/M/A): ";
            cin >> pasirinkimas;
            lentele(grupe, pasirinkimas);
        }
    }
    else if (pasirinkimas == "D") {
        cout << "Iveskite varda, pavarde, pazymius (0 kai baigiate vesti): " << endl;
        studentas orginalas;
        cin >> orginalas;

        cout << "Studento duomenys: " << orginalas;
        
        studentas kopija;
        kopija = orginalas;

        cout << "Kopija: " << kopija;
        }
    else {
        //generuoti_failus(1000, 5, "1000studentai.txt");
        //generuoti_failus(10000, 5, "10000studentai.txt");
        generuoti_failus(100000, 5, "100000studentai.txt");
        //generuoti_failus(1000000, 5, "1000000studentai.txt");
        //generuoti_failus(10000000, 5, "10000000studentai.txt");
    }
}
