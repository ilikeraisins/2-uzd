\# Objektinis-programavimas



Releasai:



1\. v.pradine - sudaro, tik rankinis studentų duomenų įvedimas main.cpp faile;

2\. v.pradine2 - pridėta galimybė generuoti atsitiktinius pažymius kiekvienam įvedamam studentui;

3\. v0.1 - pridėta galimybė skaityti duomenis iš failo;

4\. v0.2 - projektas išskaidytas į main.cpp, mylib.cpp ir main.h failus, pridėta galimybė generuoti failus, o skaitant iš failo studentus suskirstyti į dvi grupes, bei juo išrikiuoti pagal pasirinkta parametrą;

5\. v0.3 - testuotas ir README.md faile aprašytas programos veikimas naudojant std::vector ir std::list konteinerius;

6\. v1.0 - testuotas ir README.md faile aprašytas programos veikimas pagal 3 studentų suskirstymo į dvi grupes strategijas;

7\. v1.1 - struktūra studentas pakeista klase studentas, programa perdaryta atitinkamai;

8\. v1.2 - klasei strudentas pritaikyta atitikti ,,Rule of three", pridėti išvesties ir įvesties operatoriai.





Diegimo ir paleidimo instrukcija:



1\. Būtinos sąlygos:

&nbsp;	1) turėti c++ kompiliatorių ir cmake programą (versija nemažesnė nei 3.20) įdiegta;

&nbsp;	2) aplanke ,,1-uzd" turėtų būti aplankai ,,src", ,,Include" ir tekstinis failas ,,CMakeLists.txt";

2\. Diegimo žingniai:

&nbsp;	1) aplanką 1-uzd atidaryti terminale;

&nbsp;	2) paleisti komandą ,,cmake .\\CMakeLists.txt";

&nbsp;	3) paleisti komandą ,,cmake --install .";

&nbsp;	4) paleisti komandą ,,cmake --build .";

3\. Paleidimas pirmas variantas:

&nbsp;	1) per terminala atidaryti ,,1-uzd" aplanke atsiradusi aplanką ,,Debug" paleidžiant komandą ,,cd .\\Debug\\";

&nbsp;	2) paleisti komandą ,,.\\1-uzd.exe";

4\. Paleidimas antras variantas:

&nbsp;	1) atidaryti ,,1-uzd" aplanke atsiradusi aplanką ,,Debug" naudojant failų naršyklę;

&nbsp;	2) paleisti programą "1-uzd";	



Naudojimo instrukcija:


1\. Paleisti programa;

2\. Pasirinkti ar duomenis skaityti ar generuoti failus su duomenimis:

&nbsp;	1) įvedus S pasirenkama skaityti duomenis;

&nbsp;		3. Pasirinkti ar duomenis skaityti iš failo ar įvesti juo ranka:

&nbsp;			1) įvedus T pasirenkama skaityti duomenis iš failo, kurie bus apdoroti ir išvedami į du skirtingus failus pagal studento galutini pažymį:,,GeraiBesimokantis" ir ,,BlogaiBesimokantys";

&nbsp;				4. Pasirinkti pagal kokį parametrą bus surūšiuoti duomenis išvedus juos į du skirtingus failus:

&nbsp;					1) įvedus G duomenys bus surūšiuoti pagal studentų galutinius pažymius;

&nbsp;					2) įvedus V duomenys bus surūšiuoti pagal studentų vardus;

&nbsp;					3) įvedus P duomenys bus surūšiuoti pagal studentų pavardes;

&nbsp;				5. Ekrane pasirodo programos veikimo etapų trukmės ir yra sukuriami failai ,,GeraiBesimokantis" ir ,,BlogaiBesimokantys";

&nbsp;			2) įvedus N pasirenkama duomenis vesti ranka;

&nbsp;				4. Įvedamas skaičius studentų, kurių duomenis norima įvesti;

&nbsp;				5. Kartojama įvesto studentų skaičiaus kartų:

&nbsp;				6. įvesti studento vardas;

&nbsp;				7. įvesti studento pavardė;

&nbsp;				8. pasirinkti ar studento pažymius vesti vienas po kito ar generuoti:

&nbsp;					1) įvedus V pasirenkama vesti pažymius vienas po kito:

&nbsp;						9. įvedinėjami pažymiai, įvedus 0 nustojama vesti;

&nbsp;						10. įvesti studento egzamino pažymį;

&nbsp;					2) įvedus G pasirenkama generuoti atsitiktinius pažymius;

&nbsp;				11. žingsniai 6-10 kartojami įvesto studentų skaičiau kartų;

&nbsp;				12. pasirinkti ar studentų suvestinės lentelėje bus studentų galutinis rezultatas skaičiuojamas pagal pažymių vidurkį, medianą ar abu;

&nbsp;					1) įvedus V lentelėje pasirodys rezultatas pagal vidurkį;

&nbsp;					2) įvedus M lentelėje pasirodys rezultatas pagal medianą;

&nbsp;					3) įvedus A lentelėje pasirodys rezultatai pagal abu skaičius;

&nbsp;				12. Išvedama studentų suvestinė su studentų vardais, pavardėmis ir pasirinktų galutiniu pažymiu; 

&nbsp;	2) įvedus G pasirenkama generuoti failus su duomenimis;

&nbsp;		3. Sugeneruojami failai su 1000, 10000, 100000, 1000000 ir 10000000 studentų duomenimis;

&nbsp;	3) įvedus D pasirenkama bandyti klasės studentas įvedimo, išvedimo ir priskirimo operatoriu.



Perspėjimas: prieš skaitant duomenys iš failo, juos reikia sugeneruoti;





Testavimo sistemos parametrai:



\* Intel(R) Core(TM) i5-9300HF CPU @ 2.40GHz (2.40 GHz);

\* 8 GB RAM;

\* SSD.





Testavimas:



1 strategija: Bendro konteinerio skaidymas į du to paties tipo konteinerius:



1\) Naudojant std::vector konteinerį trukmės vidurkiai:







|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



|1000           | 0.0022406               | 0.0054886                               | 0.0034225                       | 0.0140551     |



|10000          | 0.0050740               | 0.0399008                               | 0.0222786                       | 0.0706234     |



|100000         | 0.0321228               | 0.3813338                               | 0.193823                        | 0.6098418     |



|1000000        | 0.295096                | 3.952282                                | 1.989768                        | 6.239384      |



|10000000       | 3.094174                | 41.4041                                 | 23.45312                        | 67.95634      |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



Pazydžiai:



1000 irašų:



<img width="1178" height="447" alt="vector 1000-1" src="https://github.com/user-attachments/assets/ea386d32-21cf-4fe3-81b0-642aa1384ec1" />



10000000 irašų:



<img width="1175" height="474" alt="vecctor 10000000" src="https://github.com/user-attachments/assets/b6163ef0-777e-49f4-b211-c2f98698793e" />











2)Naudojant std::list konteinerį trukmės vidurkiai:







|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



|1000           | 0.0007699               | 0.0140059                               | 0.0056209                       | 0.0235656     |



|10000          | 0.0058724               | 0.1150582                               | 0.0315591                       | 0.154809      |



|100000         | 0.0339609               | 1.423548                                | 0.3196396                       | 1.779332      |



|1000000        | 0.3819712               | 17.5977                                 | 3.336886                        | 21.31868      |



|10000000       | 3.112888                | 249.0134                                | 58.9834                         | 311.1538      |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|





Pavyzdžiai:



1000 irašų:



<img width="1165" height="474" alt="list 1000" src="https://github.com/user-attachments/assets/167ed565-c5b3-4909-b242-9b1e8aced9b9" />



10000000 irašų:



<img width="1182" height="478" alt="list 10000000" src="https://github.com/user-attachments/assets/d0a59e69-aae6-4dba-ac6b-3b78b3cf9517" />









2 strategija:



1\) Naudojant std::vector konteinerį trukmės vidurkiai:





|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



|1000           | 0.0046651               | 0.0061392                               | 0.0036483                       | 0.0178417     |



|10000          | 0.003715                | 0.043608                                | 0.0163485                       | 0.0661079     |



|100000         | 0.0342964               | 0.4261878                               | 0.1408882                       | 0.603858      |



|1000000        | 0.2983952               | 4.44801                                 | 1.489304                        | 6.238178      |



|10000000       | 3.10823                 | 48.75358                                | 15.88736                        | 67.75258      |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|







&nbsp;2)Naudojant std::list konteinerį trukmės vidurkiai:







|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



|1000           | 0.0007948               | 0.0143083                               | 0.0047713                       | 0.0221834     |



|10000          | 0.0039097               | 0.132647                                | 0.0243090                       | 0.1628828     |



|100000         | 0.0331337               | 1.676214                                | 0.238072                        | 1.949878      |



|1000000        | 0.298025                | 21.57356                                | 2.515094                        | 24,3888       |



|10000000       | 3.094384                | 259.643                                 | 34.89186                        | 297.65        |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|







3 strategija naudojant tik std::vector konteinerį:





|Įrašų skaičius | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



|1000           | 0.0007766               | 0.0045559                               | 0.0110817                       | 0,0181108     |



|10000          | 0.0042033               | 0.0369678                               | 0.0299963                       | 0.0584091     |



|100000         | 0.0305568               | 0.3589148                               | 0.1392758                       | 0.5306948     |



|1000000        | 0.3037752               | 3.949376                                | 1.413016                        | 5.6665        |



|10000000       | 3.247136                | 42.29478                                | 15.86184                        | 61.40678      |



|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|





Testavimo išvados:



1\. Programa veikia sparčiau naudojant std::vector konteinerį negu std::list;

2\. 3 strategija, kai naudojami tam tikri konteinerių metodai, šiek tiek spartesnė už kitas strategijas;

3\. 1 ir 2 strategijų spartos žymiai nesiskiria.





Struktūros ir klasės palyginimas:



1. 100000 įrašų:





|               | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

| Vector        | 0.0305568               | 0.3589148                               | 0.1392758                       | 0.5306948     |

| Class         | 0.0347979               | 0.409172                                | 0.1381337                       | 0.584442      |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|



2\. 1000000 įrašų:



|               | Failo nuskaitymo trukmė | Duomenų surūšiavimo į dvi grupes trukmė | Duomenų įrašymo į failus trukmė | Viso          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|

| Vector        | 0.3037752               | 03.949376                               | 1.413016                        | 5.6665        |

| Class         | 0.3048956               | 4.0238566                               | 1.366703                        | 5.6976033     |

|---------------|-------------------------|-----------------------------------------|---------------------------------|---------------|





Optimizacijos flag'ų palyginimas:



* 100000 įrašų trukmė:



|               | 01                      | 02                                      | 03                              |

|---------------|-------------------------|-----------------------------------------|---------------------------------|

| Vector        | 8.1994                  | 8.1226966                               | 8.298563                        | 

| Class         | 7.8614366               | 7.9394733                               | 7.936456                        | 

|---------------|-------------------------|-----------------------------------------|---------------------------------|



* Dydis:



|               | 01                      | 02                                      | 03                              |

|---------------|-------------------------|-----------------------------------------|---------------------------------|

| Vector        | 252 KB                  | 252 KB                                  | 252 KB                          |

| Class         | 252 KB                  | 252 KB                                  | 252 KB                          |

|---------------|-------------------------|-----------------------------------------|---------------------------------|

Perdengti metodai:

&nbsp;	1) Operatoriai:

&nbsp;	    1. << - naudonat cout leidžia išvesti studento objekto vardą, pavardę ir galutinius pažymius į ekraną, o naudojant std:: ofstream, į failą.

&nbsp;	    2. >> naudojant cin leidžia įvesti objekto studento vardą, pavardę, pažymius (paskutinis pažymis - egzaminas) ranka, o naudojant std::stringstream iš failo;

&nbsp;	    3. = vieno objekto atributai tampa priskiriamo objekto atributais.









&nbsp;	





