#include "cuboid.hpp"



/*!
 * Konstruktor dla prostopadłościanu z przypadkowymi wartościami.
 *
 * 
 * 
 */
Cuboid::Cuboid(){

    kat_do_globalnego = 0;
    
    skala = Vector3D(1, 1, 1);

}

/*!
 * Przeciazenie operatora [] dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
Vector<double, SIZE>& Cuboid::operator [] (unsigned int index){
    return top[index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych prostokata.
 * \param[in] index - pomocniczy unsidned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wiechrzolkow.
 * 
 */
const Vector<double, SIZE>& Cuboid::operator [] (unsigned int index) const{
    return top[index];
}

void Cuboid::inicjuj_cuboida(std::string Filename_oryginal , Vector3D &skala, Vector3D &Polozenie ){
    
    Vector3D broker;

    std::ifstream oryginal;

    this->Polozenie = Polozenie;

    set_skala(skala);

    oryginal.open(Filename_oryginal, std::ios::in );

    if(oryginal.is_open()){
        int licznik = 1;                        // zmienna pomagająca poprawnie dodać dane do wiechrzołków
        for(int j = 0; j < 4; ++j){
            oryginal >> broker;
            if (oryginal.eof()) return;
            broker = skaluj(broker);
            top[0] = broker;

            for(int i = 0; i < 2; ++i){
                oryginal >> broker;
                broker = skaluj(broker);
                top[licznik] = broker;
                ++licznik;
            }

            oryginal >> broker;
            broker = skaluj(broker);
            top[9] = broker;
        }
    }

    oryginal.close();

}



/*!
 * Metoda sprawdzania dlugosci przeciwleglych bokow aktualnej figury
 * znajdujacej sie w klasie cuboid ( prostopadłościanu ).
 *  
 * \retval pozytywne lub negatywne emotki z wiadomością o długościach boków.                
 */
void Cuboid::length_of_the_sides(int index){
    


    double side1;   //
                    //
    double side2;   //                                  side7                 
                    //          top7 ---> *------------------------------* <--- top5                ----|          
    double side3;   //                    |                              |                              |
                    //                   ||                             ||                              |  
    double side4;   //                  | | <--- side9                 | |                              | <--- side12 
                    //      side4 ---> |  |                side3 ---> |  |                              |
    double side5;   //                |   |           side5          |   |                              |
                    //         top1 -|--> *-------------------------|----* <--- top3                ----|
    double side6;   //              |    |        side8            |    |                             
                    //   top8 ---> *----|-------------------------* <--|- top6                      ----|
    double side7;   //             |   | <--- side1               |   | <--- side2                      |
                    // side10 ---> |  |                           |  |                                  | <--- side11
    double side8;   //             | |                            | |                                   |
                    //             ||                             ||                                    |
    double side9;   //   top2 ---> *------------------------------* <--- top4                       ----|
                    //                          side6
    double side10;  //
                    //
    double side11;  //
                    //
    double side12;  //

    std::cout << index; // TYLKO DLA UNIKNIĘCIA BŁĘDU UNUSED

    side1 = sqrt( pow( std::abs(top[1][0] - top[0][0]),2)  +  pow( std::abs(top[1][1] - top[0][1]),2) + pow( std::abs(top[1][2] - top[0][2]),2));

    side2 = sqrt( pow( std::abs(top[3][0] - top[2][0]),2)  +  pow( std::abs(top[3][1] - top[2][1]),2) + pow( std::abs(top[3][2] - top[2][2]),2));

    side3 = sqrt( pow( std::abs(top[5][0] - top[4][0]),2)  +  pow( std::abs(top[5][1] - top[4][1]),2) + pow( std::abs(top[5][2] - top[4][2]),2));

    side4 = sqrt( pow( std::abs(top[7][0] - top[6][0]),2)  +  pow( std::abs(top[7][1] - top[6][1]),2) + pow( std::abs(top[7][2] - top[6][2]),2));

    side5 = sqrt( pow( std::abs(top[2][0] - top[0][0]),2)  +  pow( std::abs(top[2][1] - top[0][1]),2) + pow( std::abs(top[2][2] - top[0][2]),2));

    side6 = sqrt( pow( std::abs(top[3][0] - top[1][0]),2)  +  pow( std::abs(top[3][1] - top[1][1]),2) + pow( std::abs(top[3][2] - top[1][2]),2));

    side7 = sqrt( pow( std::abs(top[6][0] - top[4][0]),2)  +  pow( std::abs(top[6][1] - top[4][1]),2) + pow( std::abs(top[6][2] - top[4][2]),2));

    side8 = sqrt( pow( std::abs(top[7][0] - top[5][0]),2)  +  pow( std::abs(top[7][1] - top[5][1]),2) + pow( std::abs(top[7][2] - top[5][2]),2));

    side9 = sqrt( pow( std::abs(top[6][0] - top[0][0]),2)  +  pow( std::abs(top[6][1] - top[0][1]),2) + pow( std::abs(top[6][2] - top[0][2]),2));

    side10 = sqrt( pow( std::abs(top[7][0] - top[1][0]),2)  +  pow( std::abs(top[7][1] - top[1][1]),2) + pow( std::abs(top[7][2] - top[1][2]),2));

    side11 = sqrt( pow( std::abs(top[5][0] - top[3][0]),2)  +  pow( std::abs(top[5][1] - top[3][1]),2) + pow( std::abs(top[5][2] - top[3][2]),2));

    side12 = sqrt( pow( std::abs(top[4][0] - top[2][0]),2)  +  pow( std::abs(top[4][1] - top[2][1]),2) + pow( std::abs(top[4][2] - top[2][2]),2));


    if((std::abs(side5 - side8) <= MIN_DIFF) && (std::abs(side6 - side7) <= MIN_DIFF)){
        std::cout <<"\n :)  Krotsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side8 << std::endl;
    }
    else{
        std::cout <<"\n :/  Krotsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side5 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side6 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side7 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side8 << std::endl;
    }

    if((std::abs(side1 - side3) <= MIN_DIFF) && (std::abs(side2 - side4) <= MIN_DIFF)){
        std::cout <<"\n :)  Poprzeczne przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << std::setw(16) << std::fixed << std::setprecision(10) << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< std::setw(16) << std::fixed << std::setprecision(10) << side4 << std::endl;
    }
    else{
        std::cout <<"\n :/   Poprzeczne przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side1 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side2 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side3 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side4 << std::endl;
    }

    if((std::abs(side9 - side11) <= MIN_DIFF) && (std::abs(side10 - side12) <= MIN_DIFF)){
        std::cout <<"\n :)  Dluzsze przeciwlegle boki sa sobie rowne" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }
    else{
        std::cout <<"\n :/  Dluzsze przeciwlegle boki nie sa sobie rowne!!!" << std::endl;
        std::cout <<"Dlugosc pierwszego boku: " << side9 << std::endl;
        std::cout <<"Dlugosc drugiego boku: " << side10 << std::endl;
        std::cout <<"Dlugosc trzeciego boku: " << side11 << std::endl;
        std::cout <<"Dlugosc czwartego boku: "<< side12 << std::endl;
    }
}
