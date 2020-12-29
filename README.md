# 2-Uzduotis-
Pirmos uzduoties tesinys
#1.1V
Pirmoje antrosios užduoties versijoje **struct Studentas** buvo pakeista į **class Studentas**
Studentai šioje versijoje skirstomi pagal 1-ąją strategiją: kiekvienas studentas yra ir pagrindiniame std::vector<Student> Students konteineryje, ir viename iš suskaidytų konteinerių (std::vector<Studentas> Kvaili arba std::vector<Studentas> Protingi.
**Duomenų skirstymo ir spausdinimo spartos analizė**
 
  **Naudojant Struct Studentas**
 | 1000 |  10000 |  100000 | 1000000  |  10000000 |
 |-----:|:------:|:-------:|:--------:|----------:|
 |24 ms | 219  ms| 2508 ms | 24191 ms |492473  ms |
 

  **Naudojant Class Studentas**
   | 1000 |  10000 |  100000 | 1000000  |      10000000      |
   |-----:|:------:|:-------:|:--------:|-------------------:|
   |40 ms | 398  ms| 5004 ms | 43914 ms | neuzteko atminties |
   
  
  Taigi, naudojant **Class Studentas** skirstymas ir spausdinimas užtruko šiek tiek ilgiau. 
  **Spartos analizė naudojant Flag'us O1, O2, O3**
   |Flag| 1000 |  10000 |  100000 | 1000000  |      10000000      | 
   |----|-----:|:------:|:-------:|:--------:|:------------------:|
   | O1 |39 ms | 416  ms| 4289 ms | 44563 ms | neuzteko atminties |
   | O2 |41 ms | 399  ms| 5124 ms | 47393 ms | neuzteko atminties |
   | O3 |39 ms | 402  ms| 4924 ms | 45495 ms | neuzteko atminties |
