/*!
* \file 
* \brief Definicje metod klasy objects_scene
*/

#include "../inc/obiekt_sceny.hpp"
#include "../inc/plaskowyz.hpp"
#include "../inc/gora_ze_szczytem.hpp"
#include "../inc/gora_z_grania.hpp"
#include "../inc/drone.hpp"



void objects_scene::ze_wzora_do_animatora(){
    Vector3D broker;

    std::ofstream anime;
    int Licznik = 1;
    
    if(Otworz_Plik_animowany(anime)){
        
        for(int i = 0; i < 4; ++i){
            broker = top[0];
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            for(int j = 1; j < 3; ++j){
                broker = top[Licznik];
                broker = Skrobanie_do_rodzica(broker);
                anime << broker;
                anime << std::endl;
                ++Licznik;
            }
            broker = top[9];
            broker = Skrobanie_do_rodzica(broker);
            anime << broker;
            anime << std::endl;
            anime << std::endl;
        }
        broker = top[0];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[1];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[2];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        broker = top[9];
        broker = Skrobanie_do_rodzica(broker);
        anime << broker;
        anime << std::endl;
        anime << std::endl;

        Zamknij_Plik_animowany(anime);

    }
    else{
        throw std::runtime_error("PLik nie istnieje / błąd pliku1");
    }
}