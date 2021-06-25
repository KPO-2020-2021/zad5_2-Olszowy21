#include "drone.hpp"



void Drone::inicjalizuj_drona(std::string anime_files[], std::string name_oryginal_cuboid, std::string name_oryginal_prism, Vector3D &polozenie, double kat, PzG::LaczeDoGNUPlota &Lacze){
    
    this->Korpus.set_filename_anime(anime_files[0]);
    this->Rotor[0].set_filename_anime(anime_files[1]);
    this->Rotor[1].set_filename_anime(anime_files[2]);
    this->Rotor[2].set_filename_anime(anime_files[3]);
    this->Rotor[3].set_filename_anime(anime_files[4]);
    
    this->Polozenie = polozenie;

    kat_do_globalnego = kat;

    Vector3D Pozycja_korpusu(0, 0, 2);

    Vector3D Pozycja_rotora0(4, 2, 4.5);
    Vector3D Pozycja_rotora1(4, -2, 4.5);
    Vector3D Pozycja_rotora2(-4, 2, 4.5);
    Vector3D Pozycja_rotora3(-4, -2, 4.5);

    Vector3D skala_cuboida(12, 6, 4);
    Vector3D skala_prisma(4, 4, 1);


    Korpus.inicjuj_cuboida(name_oryginal_cuboid, skala_cuboida, Pozycja_korpusu);

    Rotor[0].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora0);
    Rotor[1].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora1);
    Rotor[2].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora2);
    Rotor[3].inicjuj_prism(name_oryginal_prism, skala_prisma, Pozycja_rotora3);


    Lacze.DodajNazwePliku(anime_files[0].c_str());
    Lacze.DodajNazwePliku(anime_files[1].c_str());
    Lacze.DodajNazwePliku(anime_files[2].c_str());
    Lacze.DodajNazwePliku(anime_files[3].c_str());
    Lacze.DodajNazwePliku(anime_files[4].c_str());

    zmlucenie_drona_do_animacji();

}

bool Drone::up_down(double wysokosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    
    zmlucenie_drona_do_animacji();

    double step;
    wysokosc_lotu > 0 ? step = 2 : step = -2;
    Vector3D step_brother(0, 0, step);

    for(int i = 0; i < abs(wysokosc_lotu); i+=2){
    
        Rotor[0].Miotaj(10);
        Rotor[1].Miotaj(-10);
        Rotor[2].Miotaj(10);
        Rotor[3].Miotaj(-10);
        Polozenie = Polozenie + step_brother;
        zmlucenie_drona_do_animacji();
        usleep(100000);
        Lacze.Rysuj();
    }
    return 1;
    
}

void Drone::forward_backward(double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){

    double step;
    kat_obrotu > 0 ? step = 5 : step = -5;
    
    double droga = abs(kat_obrotu);

    for(int i = 0; i < droga ; i+=5){

        if(((i - droga) >= MIN_DIFF) && ((( i+5 ) >= droga) >= MIN_DIFF )){
            droga = droga - i;
        
            Rotor[0].Miotaj(10);
            Rotor[1].Miotaj(-10);
            Rotor[2].Miotaj(10);
            Rotor[3].Miotaj(-10);

            kat_obrotu > 0 ? kat_do_globalnego += droga : kat_do_globalnego -= droga;
            
            zmlucenie_drona_do_animacji();
            usleep(100000);
            Lacze.Rysuj();

            i = droga;
        }
        else{

            Rotor[0].Miotaj(10);
            Rotor[1].Miotaj(-10);
            Rotor[2].Miotaj(10);
            Rotor[3].Miotaj(-10);

            kat_do_globalnego += step;

            zmlucenie_drona_do_animacji();
            usleep(100000);
            Lacze.Rysuj();
        }
    }

    double kaciwo = kat_do_globalnego * M_PI / 180;
    Vector3D kierunek(cos(kaciwo) * 2, sin(kaciwo) * 2, 0);


    droga = abs(dlugosc_lotu);

    for(int j = 0; j < droga; j+=2){

        if(((j - droga) >= MIN_DIFF) && ((( j+2 ) - droga) >= MIN_DIFF )){

            dlugosc_lotu > 0 ? droga = droga - j : droga = j - droga;
            
            Vector3D dokladka(cos(kaciwo) * droga, sin(kaciwo) * droga, 0);

            Rotor[0].Miotaj(10);
            Rotor[1].Miotaj(-10);
            Rotor[2].Miotaj(10);
            Rotor[3].Miotaj(-10);

            Polozenie = Polozenie + dokladka;

            zmlucenie_drona_do_animacji();
            usleep(100000);
            Lacze.Rysuj();

            j = droga;

        }
        else{

            Rotor[0].Miotaj(10);
            Rotor[1].Miotaj(-10);
            Rotor[2].Miotaj(10);
            Rotor[3].Miotaj(-10);

            Polozenie = Polozenie + kierunek;

            zmlucenie_drona_do_animacji();
            usleep(100000);
            Lacze.Rysuj();
        }
    }
}

void Drone::Maluj_rozklad_lotu(Vector3D sciezka_lotu[], std::string nazwa_pliku[], double kat_obrotu, double dlugosc_lotu, PzG::LaczeDoGNUPlota &Lacze){
    
    double kaciwo = (kat_obrotu + kat_do_globalnego) * M_PI / 180;
    Vector3D wysokosc(0, 0, 50);
    Vector3D kierunek(cos(kaciwo) * dlugosc_lotu, sin(kaciwo) * dlugosc_lotu, 0);

    for(int i =0; i < 4; ++i){

        sciezka_lotu[i] = Vector3D(0, 0, 0);

    }

    sciezka_lotu[0] = Polozenie;
    sciezka_lotu[1] = Polozenie + wysokosc;
    sciezka_lotu[2] = Polozenie + wysokosc + kierunek;
    sciezka_lotu[3] = Polozenie + kierunek;
    
    std::ofstream File_lot;
    File_lot.open(nazwa_pliku[5].c_str() , std::ios::trunc );
    Lacze.DodajNazwePliku(nazwa_pliku[5].c_str());

    if(File_lot.is_open()){
        for(int i =0; i < 4; ++i){
            File_lot << sciezka_lotu[i] << std::endl;
            usleep(100000);
            Lacze.Rysuj();
        }
        File_lot.close();
    }
    else{
        throw std::runtime_error("Plik nie istnieje / błąd pliku");
    }


}



Vector3D Drone::Skrobanie_do_rodzica(const Vector3D & top) const{
    
    Vector3D Wynik;
    Matrix3D macierz;

    macierz.obrot_z(kat_do_globalnego);

    Wynik = macierz * top;
    Wynik = Wynik + Polozenie;

    return Wynik;
}

void Drone::zmlucenie_drona_do_animacji(){
   
    ze_wzora_cuboida_do_animatora();
    ze_wzora_rotora_do_animatora(Rotor[0]);
    ze_wzora_rotora_do_animatora(Rotor[1]);
    ze_wzora_rotora_do_animatora(Rotor[2]);
    ze_wzora_rotora_do_animatora(Rotor[3]);

}


void Drone::ze_wzora_rotora_do_animatora( const Prism &rotorek ){
      
    Vector3D broker;

    std::ofstream anime;
    int Licznik = 1;

    if(rotorek.Otworz_Plik_animowany(anime)){
        for(int i = 0; i < 6; ++i){
            broker = rotorek[0];
            broker = rotorek.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = rotorek[Licznik];
                broker = rotorek.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
                ++Licznik;
            }
            broker = rotorek[13];
            broker = rotorek.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = rotorek[0];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[1];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[2];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = rotorek[13];
        broker = rotorek.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        rotorek.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("Plik nie istnieje / błąd pliku2");
    }
}



void Drone::ze_wzora_cuboida_do_animatora(){

    Vector3D broker;

    std::ofstream anime;
    int Licznik = 1;
    
    if(Korpus.Otworz_Plik_animowany(anime)){
        
        for(int i = 0; i < 4; ++i){
            broker = Korpus[0];
            broker = Korpus.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = Korpus[Licznik];
                broker = Korpus.Skrobanie_do_rodzica(broker);
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
                ++Licznik;
            }
            broker = Korpus[9];
            broker = Korpus.Skrobanie_do_rodzica(broker);
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = Korpus[0];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[1];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[2];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = Korpus[9];
        broker = Korpus.Skrobanie_do_rodzica(broker);
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        Korpus.Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku1");
    }
}