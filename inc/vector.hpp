#pragma once

#include <iomanip>
#include <fstream>
#include <iostream>
#include <cmath>
#include "size.hpp"
#include <list>
#include <memory>
#include <unistd.h>
#include <math.h>
#include <string>
#include <sstream>
#include "lacze_do_gnuplota.hh"

#define MIN_DIFF 0.0000001

/*!
 * \file  vector.hh
 *  
 *  Plik zawiera klasę Vector ~ wektor oraz
 *  jest ojcem dla wszystkich bibliotek wbudowanych.
 *  
 */

/*!
  * \brief Zestaw dla klasy Vector
  *
  * Klasa posiada konstruktory, metody oraz
  * wartości typu szablonowego.
  */
template<typename T, unsigned int SIZE>
class Vector{
    
    T size[SIZE];     //Tablica wektora

    static int Aktywne_vektory;

    static int Ogolnie_vektory;

public:
    
// Konstruktory

    Vector();

    Vector(const Vector<T, SIZE> &second);

    Vector(T tmp[SIZE]);

    Vector(T x, T y, T z );

    ~Vector();

// Metodyc

    Vector operator + (const Vector &tmp);

    Vector operator - (const Vector &tmp);

    Vector operator * (const T &tmp);

    Vector operator * (const Vector &tmp) const;

    bool operator == (const Vector &tmp) const;

    Vector operator = (const Vector &v);

    const T &operator [] (unsigned int index) const;

    T &operator [] (unsigned int index);
    
    void Load_vector(); 

    static int zwroc_aktywna_ilosc_wektorow() {return Aktywne_vektory;};

    static int zwroc_ogolna_ilosc_wektorow() {return Ogolnie_vektory;};

};

template <typename T, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<T, SIZE> &tmp);

template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &out, Vector<T, SIZE> const &tmp);

template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ofstream &out, Vector<T, SIZE> const &tmp);

/*!
 * Przeciazenie operatora wypisywania do pliku.
 * \param[in] out - strumien wyjsciowy do pliku, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie wypisywana na
 *                      wyjscie.
 * 
 */
template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ofstream &out, Vector<T, SIZE> const &tmp){
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << std::fixed << std::setprecision(10) << tmp[i] << ' ';
    }
    return out;
}

/*!
 * Przeciazenie operatora wypisywania.
 * \param[in] out - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie wypisywana na
 *                      wyjscie.
 * 
 */
template <typename T, unsigned int SIZE>
std::ostream& operator << (std::ostream &out, Vector<T, SIZE> const &tmp)
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "[ " << tmp[i] << " ] ";
    }
    return out;
}

/*!
 * Przeciazenie operatora wpisywania.
 * \param[in] in - strumien wejsciowy, z ktorego maja zostac wypisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie przyjmowac dane
 *                      z wejscia.
 * 
 */
template <typename T, unsigned int SIZE>
std::istream &operator >> (std::istream &in, Vector<T, SIZE> &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        in >> tmp[i];
    }

    return in;
}

/*!
 * Konstruktor dla zerowego wektora.
 *
 * 
 * 
 */
template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(){
    for (unsigned int i = 0; i < SIZE; ++i){
        this->size[i] = T();
    }
}


/*!
 * Konstruktor macierzy.
 * \param[in] tmp - nazwa wektora do wpisania jego wartości do klasy.
 * 
 * 
 */
template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T tmp[SIZE]){
    for (unsigned int i = 0; i < SIZE; ++i) {
        this->size[i] = tmp[i];
    }   
}

/*!
 * Konstruktor macierzy.
 * \param[in] x - wartość typu szablonu do wpisania wartości x wektora. 
 * \param[in] y - wartość typu szablonu do wpisania wartości y wektora. 
 * \param[in] z - wartość typu szablonu do wpisania wartości z wektora. 
 */
template<typename T, unsigned int SIZE>
Vector<T, SIZE>::Vector(T x, T y, T z ){
    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;
}


template<typename T, unsigned int SIZE>
int Vector<T,SIZE>::Aktywne_vektory = 0;

template<typename T, unsigned int SIZE>
int Vector<T,SIZE>::Ogolnie_vektory = 0;

/*!
 * Przeciążenie operatora - dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik odejmowania.
 */
template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator - (const Vector &tmp){
    Vector<T, SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] - tmp[i];
    }
    return result;
}



/*!
 * Przeciążenie operatora + dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik dodawania.
 */
template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator + (const Vector &tmp){
    Vector result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] + tmp[i];
    }
    return result;
}

/*!
 * Przeciążenie operatora * dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik mnożenia.
 */
template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (const T &tmp){
    Vector<T, SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] * tmp;
    }
    return result;
}

/*!
 * Przeciążenie operatora * dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik mnożenia.
 */
template <typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator * (const Vector &tmp) const{
    Vector<T, SIZE> result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] * tmp[i];
    }
    return result;
}

/*!
 * Realizuje porownanie dwoch wektorow ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa wektora sprawdzanego z wektorem zawartym wewnatrz klasy
 * 
 * \retval true - gdy oba sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
template <typename T, unsigned int SIZE>
bool Vector<T, SIZE>::operator == (const Vector &tmp) const{
    if((std::abs(this->size[0] - tmp.size[0]) <= MIN_DIFF ) && (std::abs(this->size[1] - tmp.size[1]) <= MIN_DIFF ) && (std::abs(this->size[2] - tmp.size[2]) <= MIN_DIFF )){
        return true;
    }
    return false;
}

template<typename T, unsigned int SIZE>
Vector<T, SIZE> Vector<T, SIZE>::operator = (const Vector<T, SIZE> &v){
    for(unsigned int i = 0; i < SIZE; ++i){
        size[i] = v[i];
    }
    return *this;
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych wektora.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <typename T, unsigned int SIZE>
const T &Vector<T, SIZE>::operator [] (unsigned int index) const{
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/*!
 * Przeciazenie operatora [] dla danych chronionych wektora.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */ 
template <typename T, unsigned int SIZE>
T &Vector<T, SIZE>::operator [] (unsigned int index){
    if (index < 0 || index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/*!
 * Metoda do szybkiego zapisu danych do wektora przydatne w testowaniu.
 *
 *                       
 */
template <typename T, unsigned int SIZE>
void Vector<T, SIZE>::Load_vector(){

    T x,y,z;
    std::cout<<"Proszę podać wektor przesunięcia przykład: 10 2 3 <---> x y z"<<std::endl;
    std::cin>>x;
    std::cin>>y;
    std::cin>>z;

    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;
}   
