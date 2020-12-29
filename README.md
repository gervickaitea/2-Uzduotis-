# 2-Uzduotis-
Pirmos uzduoties tesinys
# 1.1V

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
# 1.2V
Antroje užduoties versijoje paprašyta realizuoti `Class Studentas` reikiamus ir tinkančius (turinčius prasmę) operatorius.
Realizuoti išvesties, įvesties bei lyginimo operatoriai `class Studentas` objektams lyginti. 

# 1.5V
Šios užduoties versijoje klasė `class Studentas` buvo išskaidyta į dvi klases - `Class Person` (*Base klasė*) ir `Class Studentas` (*Derived klasė*)

# 2.0V
Paskutinei versijai buvo prašoma naudoti **Doxygen** dokumentaciją, tačiau jos įgyvendinti nepavyko. 

**Unit Test'ai** buvo atlikti naudojant Catch2 framework'ą.
```ruby
TEST_CASE("GP") {

	REQUIRE(GP(5.1, 7) == 6.24);
	REQUIRE(GP(4.1, 10) == 7.64);
	REQUIRE(GP(9.2, 4) == 6.08);
	REQUIRE(GP(8.5, 9) == 8.8);
	REQUIRE(GP(8.5, 3) == 5.2);

}

TEST_CASE("Protingi") {

	REQUIRE(IfProtingi(9) == true);
	REQUIRE(IfProtingi(4) == false);
	REQUIRE(IfProtingi(10) == true);
	REQUIRE(IfProtingi(7) == true);
	REQUIRE(IfProtingi(5) == true);

}
TEST_CASE("Kvaili") {

	REQUIRE(IfKvaili(7) == false);
	REQUIRE(IfKvaili(5) == false);
	REQUIRE(IfKvaili(4) == true);
	REQUIRE(IfKvaili(1) == true);
	REQUIRE(IfKvaili(3) == true);



}
```
