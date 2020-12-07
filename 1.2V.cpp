#include "biblioteka.h"

int main()
{
    std::vector<Studentas> studentas;
    Studentas Stud;
    std::string Entry;
    int EntryChoice;
    std::string::size_type IlgiausiasVardas = 0,
        IlgiausiaPavarde = 0;

    EntryChoice = Pasirinkimas();


    if (EntryChoice == 1)
    {
        std::string vardas_,
            pavarde_,
            Egzaminas,
            EntryLine;

        std::ifstream ReadFile("kursiokai.txt");

        try
        {
            if (!ReadFile.good() || ReadFile.peek() == std::ifstream::traits_type::eof())
                throw "Toks failas neegzistuoja";
        }
        catch (const char* Message)
        {
            std::cout << Message << std::endl;
        }
        std::cout << std::endl;

        while (std::getline(ReadFile, EntryLine))
        {
            std::istringstream ReadLine(EntryLine);
            ReadLine >> vardas_ >> pavarde_ >> Egzaminas;

            if (Raides(vardas_) && Raides(pavarde_) && Skaiciai(Egzaminas))
            {
                DidRaid(vardas_);
                DidRaid(pavarde_);
                IlgiausiasVardas = std::max(IlgiausiasVardas, vardas_.length());
                IlgiausiaPavarde = std::max(IlgiausiaPavarde, pavarde_.length());
                Stud.setStudentas(vardas_, pavarde_, Egzaminas);

                if (ReadLine)
                {
                    Stud.EmptyND();
                    while (ReadLine >> Entry)
                    {
                        if (Skaiciai(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 && Mark < 11)
                                Stud.SetND(Mark);
                        }
                    }
                    studentas.push_back(Stud);
                    ReadLine.clear();
                }
                ReadLine.end;
            }
            else
                std::cout << Error << std::endl;

            ReadFile.clear();
        }
        ReadFile.end;

        std::sort(studentas.begin(), studentas.end(), Lyginimas);
        SpausdintiLentele(std::cout, IlgiausiasVardas, IlgiausiaPavarde);
        Spausdinti(std::cout, studentas, IlgiausiasVardas, IlgiausiaPavarde);
    }

    else if (EntryChoice == 2)
    {
        std::cout << "\nKKaip norite apskaiciuoti studentu galutini pazimi?\nSpauskite:"
            "\n1. Jei norite, jog butu naudojamas studento namu darbu rezultatu vidurkis."
            "\n2. Jei norite, jog butu naudojama mediana. " << std::endl;
        int FMChoice;

        while (std::cin >> Entry)
        {
            if (Entry == "1")
            {
                FMChoice = 1;
                break;
            }
            else if (Entry == "2")
            {
                FMChoice = 2;
                break;
            }
            else
                std::cout << Error << std::endl;
        }
        std::cin.ignore();

        while (true)
        {
            std::cout << "\nIveskite " << studentas.size() + 1 << " studento varda, pavarde bei egzamino rezultata"
                "\nnuo 1 iki 10. Baige paspauskite 'ENTER'." << std::endl;
            std::getline(std::cin, Entry);

            if (!Entry.empty())
            {
                std::string vardas_,
                    pavarde_,
                    Egzaminas;
                std::istringstream ReadLine(Entry);
                ReadLine >> vardas_ >> pavarde_ >> Egzaminas;

                if (Raides(vardas_) && Raides(pavarde_) && Skaiciai(Egzaminas) && std::stoi(Egzaminas) > 0 && std::stoi(Egzaminas) < 11)
                {
                    DidRaid(vardas_);
                    DidRaid(pavarde_);
                    IlgiausiasVardas = std::max(IlgiausiasVardas, vardas_.length());
                    IlgiausiaPavarde = std::max(IlgiausiaPavarde, pavarde_.length());
                    Stud.setStudentas(vardas_, pavarde_, Egzaminas);

                    std::cout << "\nKaip bus pateikiami studento namu darbu rezultatai?\nSpauskite:"
                        "\n1. Jei rezultatus ivesti Jus."
                        "\n2. Jei norite, jog duomenys butu sugeneruoti atsitiktinai." << std::endl;

                    while (std::cin >> Entry)
                    {
                        if (Entry == "1")
                        {
                            Stud.EmptyND();
                            std::cout << "\nVeskite skaicius nuo 1-o iki 10-ies."
                                "\nNoredami baigti vedima, iveskite bet koki kita skaiciu." << std::endl;
                            while (std::cin >> Entry)
                            {
                                if (Skaiciai(Entry) == true)
                                {
                                    int Mark = std::stoi(Entry);

                                    if (Mark > 0 && Mark < 11)
                                        Stud.SetND(Mark);
                                    else
                                    {
                                        if (Stud.getDydis() != 0)
                                            break;
                                        else
                                            std::cout << "Iveskite skaiciu." << std::endl;
                                    }
                                }
                                else
                                    std::cout << Error << std::endl;
                            }
                            break;
                        }
                        else if (Entry == "2")
                        {
                            Stud.EmptyND();
                            std::cout << "\nKiek skaiciu generuoti?" << std::endl;

                            while (std::cin >> Entry)
                            {
                                if (Skaiciai(Entry) == true)
                                {
                                    int Mark = std::stoi(Entry);
                                    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
                                    std::default_random_engine eng(seed);
                                    std::uniform_int_distribution <int> dist(1, 10);

                                    if (Mark > 0)
                                    {
                                        for (int i = 0; i < Mark; i++)
                                            Stud.SetND(dist(eng));
                                        break;
                                    }
                                    else
                                    {
                                        if (Stud.getDydis() != 0)
                                            break;
                                        else
                                            std::cout << "Truksta duomenu." << std::endl;
                                    }
                                }
                                else
                                    std::cout << Error << std::endl;
                            }
                            break;
                        }
                        else
                        {
                            std::cin.ignore();
                            std::cin.clear();
                            std::cout << Error << std::endl;
                        }
                    }
                    studentas.push_back(Stud);

                    std::sort(studentas.begin(), studentas.end(), Lyginimas);

                    std::cin.ignore();
                    std::cin.clear();
                }
                else
                    std::cout << Error << std::endl;
            }
            else
            {
                if (studentas.size() == 0)
                    std::cout << "Iveskite bent vieno studento duomenis." << std::endl;
                else
                {
                    if (FMChoice == 1)
                        SpaudintiVidurki(IlgiausiasVardas, IlgiausiaPavarde);
                    else
                        SpausdintiMediana(IlgiausiasVardas, IlgiausiaPavarde);

                    for (std::vector<Studentas>::iterator IT = studentas.begin(); IT != studentas.end(); IT++)
                    {
                        std::cout << (*IT).getVardas() << std::string(IlgiausiasVardas + 1 - (*IT).getVardas().size(), ' ');
                        std::cout << (*IT).getPavarde() << std::string(IlgiausiaPavarde + 1 - (*IT).getPavarde().size(), ' ');

                        std::streamsize prec = std::cout.precision();
                        if (FMChoice == 1)
                            std::cout << std::fixed << std::setprecision(2) << (*IT).GP(Vidurkis) << std::setprecision(prec) << std::endl;
                        else
                            std::cout << std::fixed << std::setprecision(2) << (*IT).GP(Mediana) << std::setprecision(prec) << std::endl;
                    }
                    break;
                }
            }
        }
    }

    else if (EntryChoice == 3)
    {
        int a;
        std::cout << "Jeigu norite naudoti jau sugeneruotus failus spauskite 1, bet jei norite generuoti is naujo spauskite 0\n";
    label: std::cin >> a;
        if (a == 0) for (std::size_t i = 1000; i != 100000000; i *= 10)
        {
            studentas.clear();
            Generavimas(i);
        }
        else if (a != 0 and a != 1) { std::cout << Error; goto label; }
        for (std::size_t i = 1000; i != 100000000; i *= 10)
        {

            std::string vardas_,
                pavarde_,
                Egzaminas,
                EntryLine;

            std::ifstream ReadFile("Studentai_" + std::to_string(i) + ".txt");

            try
            {
                if (!ReadFile.good() || ReadFile.peek() == std::ifstream::traits_type::eof())
                    throw "Toks failas neegzistuoja arba yra tuscias.";
            }
            catch (const char* Message)
            {
                std::cout << Message << std::endl;
            }

            while (std::getline(ReadFile, EntryLine))
            {
                std::istringstream ReadLine(EntryLine);
                ReadLine >> vardas_ >> pavarde_ >> Egzaminas;

                DidRaid(vardas_);
                DidRaid(pavarde_);
                IlgiausiasVardas = std::max(IlgiausiasVardas, vardas_.length());
                IlgiausiaPavarde = std::max(IlgiausiaPavarde, pavarde_.length());
                Stud.setStudentas(vardas_, pavarde_, Egzaminas);

                if (ReadLine)
                {
                    Stud.EmptyND();
                    while (ReadLine >> Entry)
                    {
                        if (Skaiciai(Entry))
                        {
                            int Mark = stoi(Entry);

                            if (Mark > 0 && Mark < 11)
                                Stud.SetND(Mark);
                        }
                    }
                    studentas.push_back(Stud);
                    ReadLine.clear();
                }
                ReadLine.end;
                ReadFile.clear();
            }
            ReadFile.end;

            auto StartSorting = std::chrono::high_resolution_clock::now();

            std::vector<Studentas> Kvaili, Protingi;
            std::vector<Studentas>::iterator IT = studentas.begin();

            while (IT != studentas.end())
            {
                if ((*IT).GP(Vidurkis) < 5 && (*IT).GP(Mediana) < 5)
                    Kvaili.push_back(*IT);
                else
                    Protingi.push_back(*IT);
                IT++;
            }

            std::ofstream IrasymasKvaili;
            IrasymasKvaili.open("Kvaili.txt", std::ios::app);
            Spausdinti(IrasymasKvaili, Kvaili, IlgiausiasVardas, IlgiausiaPavarde);
            IrasymasKvaili.close();

            
            std::ofstream IrasymasProtingi;
            IrasymasProtingi.open("Protingi.txt", std::ios::app);
            Spausdinti(IrasymasProtingi, Protingi, IlgiausiasVardas, IlgiausiaPavarde);
            IrasymasProtingi.close();

            auto EndSorting = std::chrono::high_resolution_clock::now();
            std::cout << "Studentu skirstymas ir isvedimas uztruko " << std::chrono::duration_cast<std::chrono::milliseconds>(EndSorting - StartSorting).count() << " ms." << std::endl;
        }
    }
    return 0;
}
