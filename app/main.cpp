// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include "lacze_do_gnuplota.hh"
#include "exampleConfig.h"
#include <fstream>
#include "scene.hpp"
#include "matrix3d.hpp"
#include "vector3d.hpp"


/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  std::cout << "C++ Boiler Plate v"
          << PROJECT_VERSION_MAJOR
          << "."
          << PROJECT_VERSION_MINOR
          << "."
          << PROJECT_VERSION_PATCH
          << "."
          << PROJECT_VERSION_TWEAK // zartowalem
          << std::endl;
  //std::system("cat ../LICENSE");


  Drone *Wskaznik_na_drona;
  std::ofstream FILE;

  std::string File_name_anime[6];                    // 0 dla korpusu od 1 do 4 dla rotorów oraz 5 dla pliku do rysowania ścieżki lotu
  File_name_anime[0] = "../datasets/cuboid1.dat";
  File_name_anime[1] = "../datasets/rotor1.dat";
  File_name_anime[2] = "../datasets/rotor2.dat";
  File_name_anime[3] = "../datasets/rotor3.dat";
  File_name_anime[4] = "../datasets/rotor4.dat";
  File_name_anime[5] = "../datasets/rozklad_lotu.dat";

  std::string File_name_anime1[6];
  File_name_anime1[0] = "../datasets/cuboid11.dat";
  File_name_anime1[1] = "../datasets/rotor11.dat";
  File_name_anime1[2] = "../datasets/rotor21.dat";
  File_name_anime1[3] = "../datasets/rotor31.dat";
  File_name_anime1[4] = "../datasets/rotor41.dat";
  File_name_anime1[5] = "../datasets/rozklad_lotu.dat";

  std::string Cuboid_oryginal;
  std::string Prism_oryginal;
  Cuboid_oryginal = "../datasets/cuboid_oryginal.dat";
  Prism_oryginal = "../datasets/prism_oryginal.dat";
  
  Vector3D polozenie1(20, 20, 0);
  Vector3D polozenie2(5, 5, 0);

  Vector3D sciezka_lotu[4];

  PzG::LaczeDoGNUPlota  Lacze;        // Ta zmienna jest potrzebna do wizualizacji
                                      // rysunku drona

  Drone dron1, dron2;
  dron1.inicjalizuj_drona(File_name_anime, Cuboid_oryginal, Prism_oryginal, polozenie1, 0 , Lacze);
  dron2.inicjalizuj_drona(File_name_anime1, Cuboid_oryginal, Prism_oryginal, polozenie2, 45 , Lacze);

  Scene Scena;
  Scena.Dodaj_drona(dron1);
  Scena.Dodaj_drona(dron2);

  Wskaznik_na_drona = Scena.use_avtive_drone();

  Lacze.DodajNazwePliku("../datasets/scene.dat");
  Lacze.ZmienTrybRys(PzG::TR_3D);

  Lacze.Inicjalizuj();

  Lacze.UstawZakresX(-100, 100);
  Lacze.UstawZakresY(-100, 100);
  Lacze.UstawZakresZ(0, 100);

  Lacze.Rysuj();

  std::cout<<"\n\t**********************MENU***********************"<<std::endl;
  std::cout<<"\ta - Wybierz aktywnego drona"<<std::endl;
  std::cout<<"\tp - zadaj parametry przelotu"<<std::endl;
  std::cout<<"\tm - wyswietl menu"<<std::endl<<std::endl;

  std::cout<<"\tk - koniec dzialania programu"<<std::endl;

  char x;

  while(x != 'k'){
      double kat;
      double odleglosc;

      std::cout<<"\nPolozenie aktywnego drona " << (*Wskaznik_na_drona).Get_polozeniex() << " " << (*Wskaznik_na_drona).Get_polozeniey() << std::endl << std::endl;

      std::cout<<"\tAktualna ilosc obiektow Wektor3D:"<< Vector3D::zwroc_aktywna_ilosc_wektorow() << std::endl;
      std::cout<<"\t  laczna ilosc obiektow Wektor3D:"<< Vector3D::zwroc_ogolna_ilosc_wektorow() <<  std::endl <<  std::endl;

      std::cout<<"Wybieram : ( m - menu ) > ";
      std::cin>>x;
      switch (x){
      case 'm':
            std::cout<<"\n\t**********************MENU***********************"<<std::endl;
            std::cout<<"\ta - Wybierz aktywnego drona"<<std::endl;
            std::cout<<"\tp - zadaj parametry przelotu"<<std::endl;
            std::cout<<"\tm - wyswietl menu"<<std::endl<<std::endl;

            std::cout<<"\tk - koniec dzialania programu"<<std::endl;

            std::cin.ignore(10000, '\n');
            break;
      case 'a':

            std::cout<<"\tWybór aktywnego drona "<<std::endl;

            std::cout<<"\t1 - Polozenie (x,y): " << dron1.Get_polozeniex() << " " << dron1.Get_polozeniey();
            if( Scena.index_aktywnego_drona() == 0){

              std::cout << " <---- aktywny dron";

            }
            std::cout << std::endl;

            std::cout<<"\t2 - Polozenie (x,y): " << dron2.Get_polozeniex() << " " << dron2.Get_polozeniey();
            if( Scena.index_aktywnego_drona() == 1){

              std::cout << " <---- aktywny dron";

            }
            std::cout << std::endl;

            std::cout << std::endl << "Wprowadź numer aktywnego drona ---> ";
            int index;
            std::cin >> index;

            if(index > 0 && index < 3){
              Scena.avtive_drone(index);
              Wskaznik_na_drona = Scena.use_avtive_drone();
            }
            else{
              std::cout << std::endl << "Wprowadzano zły numer proszę podać poprawny";
              std::cin >> index;
              if(index > 0 && index < 3){
                Scena.avtive_drone(index);
                Wskaznik_na_drona = Scena.use_avtive_drone();
              }
              else{
                std::cout << std::endl << "";
              }
            }

            break;
      case 'p':
            std::cout << "Podaj kierunek lotu (kat w stopniach) > ";
            std::cin >> kat;
            std::cout  << "Podaj długość lotu > ";
            std::cin >> odleglosc;
            std::cout << "Rysuje zaplanowana sciezke lotu ..." << std::endl;
            (*Wskaznik_na_drona).Maluj_rozklad_lotu(sciezka_lotu, File_name_anime, kat, odleglosc, Lacze);

            std::cout << "Realizacja przelotu ..." << std::endl;

            if((*Wskaznik_na_drona).up_down(50, Lacze)){

              (*Wskaznik_na_drona).forward_backward(kat, odleglosc, Lacze);

              if((*Wskaznik_na_drona).up_down(-50, Lacze)){

                std::cout << "Dron wyladował ..." << std::endl << std::endl;

              }

              FILE.open(File_name_anime[5].c_str() , std::ios::trunc );
              FILE.close();
              
            }

            break;
      case 'k':
            std::cout<<" Dziękuję za używanie mojego programu ;)"<<std::endl;

            break;
      default:
            std::cout<<" Niepoprawna operacja, symbol m to MENU"<<std::endl;

            break;
      }
  }
}
