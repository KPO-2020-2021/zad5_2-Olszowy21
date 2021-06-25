#include "vector3d.hpp"

/*!
 * Przeciazenie operatora wypisywania do piku.
 * \param[in] out - strumien wyjsciowy, do ktorego maja zostac zapisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Vektor ktora bedzie wypisywana na
 *                      wyjscie.
 * 
 */
template <>
std::ostream& operator << (std::ofstream &out, Vector3D const &tmp)
{
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
template <>
std::ostream& operator << (std::ostream &out, Vector3D const &tmp)
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
template <>
std::istream &operator >> (std::istream &in, Vector3D &tmp) {
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
template <>
Vector3D::Vector(){

    for (unsigned int i = 0; i < SIZE; ++i){
        this->size[i] = double();
    }
    ++Ogolnie_vektory;
    ++Aktywne_vektory;
}

template <>
Vector3D::Vector(const Vector3D &second){

    for (unsigned int i = 0; i < SIZE; ++i){
        this->size[i] = second[i];
    }

    ++Ogolnie_vektory;
    ++Aktywne_vektory;

}


/*!
 * Konstruktor macierzy.
 * \param[in] tmp - nazwa wektora do wpisania jego wartości do klasy.
 * 
 * 
 */
template <>
Vector3D::Vector(double tmp[SIZE]){
    for (unsigned int i = 0; i < SIZE; ++i) {
        this->size[i] = tmp[i];
    }
    ++Ogolnie_vektory;
    ++Aktywne_vektory;
}

/*!
 * Konstruktor macierzy.
 * \param[in] x - wartość typu szablonu do wpisania wartości x wektora. 
 * \param[in] y - wartość typu szablonu do wpisania wartości y wektora. 
 * \param[in] z - wartość typu szablonu do wpisania wartości z wektora. 
 */
template <> 
Vector3D::Vector(double x, double y, double z ){
    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;

    ++Ogolnie_vektory;
    ++Aktywne_vektory;
}

/*!
 * Destruktor Vectora3D, odejmuje ilość aktywnych wektorów;
 */
template <> 
Vector3D::~Vector(){
   
    --Aktywne_vektory;

}


/*!
 * Przeciążenie operatora - dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik odejmowania.
 */
template <>
Vector3D Vector3D::operator - (const Vector &tmp){
    Vector3D result;
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
template <>
Vector3D Vector3D::operator + (const Vector &tmp){
    Vector3D result;
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
template <>
Vector3D Vector3D::operator * (const double &tmp){
    Vector3D result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        result[i] = size[i] *= tmp;
    }
    return result;
}

/*!
 * Przeciążenie operatora * dla klasy wektor.
 * \param[in] tmp - nazwa wektora zmieniający wartosc klasy.
 * 
 * \retval Wynik mnożenia.
 */
template <>
Vector3D Vector3D::operator * (const Vector &tmp) const{
    Vector3D result;
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
template <>
bool Vector3D::operator == (const Vector &tmp) const{
    if((std::abs(this->size[0] - tmp.size[0]) <= MIN_DIFF ) && (std::abs(this->size[1] - tmp.size[1]) <= MIN_DIFF ) && (std::abs(this->size[2] - tmp.size[2]) <= MIN_DIFF )){
        return true;
    }
    return false;
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych wektora.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <>
const double &Vector3D::operator [] (unsigned int index) const{
    if (index >= SIZE) {
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
template <>
double &Vector3D::operator [] (unsigned int index){
    if (index >= SIZE) {
        std::cerr << "Error: Wektor jest poza zasiegiem!" << std::endl;
    }
    return size[index];
}

/*!
 * Metoda do szybkiego zapisu danych do wektora przydatne w testowaniu.
 *
 *                       
 */
template <>
void Vector3D::Load_vector(){

    double x,y,z;
    std::cout<<"Proszę podać wektor przesunięcia przykład: 10 2 3 <---> x y z"<<std::endl;
    std::cin>>x;
    std::cin>>y;
    std::cin>>z;

    this->size[0] = x;
    this->size[1] = y;
    this->size[2] = z;
}


