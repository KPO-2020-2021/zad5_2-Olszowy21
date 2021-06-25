#include "matrix3d.hpp"


/*!
 * Konstruktor instancji macierzy3D.
 * 
 * 
 */
template <>
Matrix3D::Matrix() {

    value[0][0] = 1;
    value[0][1] = 0;
    value[0][2] = 0;
    value[1][0] = 0;
    value[1][1] = 1;
    value[1][2] = 0;
    value[2][0] = 0;
    value[2][1] = 0;
    value[2][2] = 1;

    for (int k = 0; k < 30; ++k) {
        axis[k] = ' ';
    }
    for (int l = 0; l < 30; ++l) {
        degrees[l] = 0;
    }
}


/*!
 * Konstruktor macierzy.
 * \param[in] tmp - nazwa macierzy do wpisania jej wartości do klasy.
 * 
 * 
 */
template <>
Matrix3D::Matrix(double tmp[SIZE][SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
    for (int k = 0; k < 10; ++k) {
        axis[k] = ' ';
    }
    for (int l = 0; l < 10; ++l) {
        degrees[l] = 0;
    }
}

/*!
 * Realizuje ustawianie przez użytkownika kątów i osi obrótów. 
 *
 * 
 * 
 */
template <>
void Matrix3D::set_degree_axis(){

    std::cout << "Proszę podać oś oraz kąt obrotu wokół niej w postaci >x 30 lub y 23< " << std::endl;
    for(int i = 0; i < 30; ++i){
        std::cin >> axis[i];
        if(axis[i] != '.'){
            std::cin >> degrees[i];
        }
        char tmp;
        tmp = axis[i];
        switch(tmp)
        {
        case 'x':
            //std::cout << "Wczytano do osi x " << std::endl;
            std::cin.ignore(10000, '\n');
            break;

        case 'y':
            //std::cout << "Wczytano do osi y " << std::endl;
            std::cin.ignore(10000, '\n');
            break;

        case 'z':
            //std::cout << "Wczytano do osi z " << std::endl;
            std::cin.ignore(10000, '\n');
            break;

        case '.':
            //std::cout << "Skończono wczytywanie osi " << std::endl;
            degrees[i] = 0;
            i = 30;
            std::cin.ignore(10000, '\n');
            break;

        default:
            axis[i] = ' ';
            degrees[i] = 0;
            --i;
            std::cout << "Podano niepoprawną oś możliwe to: x, y, z " << std::endl;
            std::cin.ignore(10000, '\n');
            break;
        }
    }
}

/*!
 * Realizuje obrot macierzy względem osi x.
 *
 * 
 * 
 */
template <>
void Matrix3D::obrot_z(double kat){
    double rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = cos(rad);
        value[0][1] = -sin(rad);
        value[0][2] = 0;
        value[1][0] = sin(rad);
        value[1][1] = cos(rad);
        value[1][2] = 0;
        value[2][0] = 0;
        value[2][1] = 0;
        value[2][2] = 1;

    }
    else{
        std::cout << "Do not except that yet" << std::endl;
    }
}

/*!
 * Realizuje obrot macierzy względem osi y.
 *
 * 
 * 
 */
template <>
void Matrix3D::obrot_y(double kat){
    double rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = cos(rad);
        value[0][1] = 0;
        value[0][2] = sin(rad);
        value[1][0] = 0;
        value[1][1] = 1;
        value[1][2] = 0;
        value[2][0] = -sin(rad);
        value[2][1] = 0;
        value[2][2] = cos(rad);
    }
    else{
        std::cout << "Do not except that yet" << std::endl;
    }
}

/*!
 * Realizuje obrot macierzy względem osi z.
 *
 * 
 * 
 */
template <>
void Matrix3D::obrot_x(double kat){
    double rad = kat * M_PI / 180;
    
    if(SIZE == 3){
        value[0][0] = 1;
        value[0][1] = 0;
        value[0][2] = 0;
        value[1][0] = 0;
        value[1][1] = cos(rad);
        value[1][2] = -sin(rad);
        value[2][0] = 0;
        value[2][1] = sin(rad);
        value[2][2] = cos(rad);
    }
    else{
        std::cout << "Do not except that yet" << std::endl;
    }
}

/*!
 * Realizuje obrot macierzy o zadany kat.
 *
 * 
 * 
 */
template  <>
void Matrix3D::obrotmacierzy(){
    char tmp;
    double Kaciwo;
    for(int j=0; j < 30; ++j){  
        tmp = axis[j];
        switch(tmp)
        {
        case 'x':
            Kaciwo = degrees[j];
            obrot_x(Kaciwo);
            std::cout << "Zmlucono os x " << std::endl;
            //Miotator.throwing_Cuboid(this->value);
            break;

        case 'y':
            Kaciwo = degrees[j];
            obrot_y(Kaciwo);
            std::cout << "Zmlucono os y " << std::endl;
            //Miotator.throwing_Cuboid(this->value);
            break;

        case 'z':
            Kaciwo = degrees[j];
            obrot_z(Kaciwo);
            std::cout << "Zmlucono os z " << std::endl;
            //Miotator.throwing_Cuboid(this->value);
            break;

        case '.':
            std::cout << "Skończono mlucenie " << std::endl;
            j = 30;
            break;

        default:
            axis[j] = ' ';
            degrees[j] = 0;
            --j;
            std::cout << "UNEXCPECTED VIRUS OR MY PROGRAMMING " << std::endl;
            break;
        }
    }
}

/*!
 * Realizuje porownanie dwoch macierzy ze soba dopuszczajac margines bledu.
 * \param[in] tmp - nazwa macierzy sprawdzanej z macierza zawarta wewnatrz klasy
 * 
 * \retval true - gdy obie sa sobie rowne.
 * \retval false - w przypadku przeciwnym.
 */
template  <>
bool Matrix3D::operator == (const Matrix3D tmp) const{
    
    for(unsigned int i = 0; i < SIZE; i++){
        for(unsigned int j = 0; j < SIZE; j++){
            if(std::abs(this->value[i][j] - tmp.value[i][j]) > MIN_DIFF ){
                return false;
            }
        }
    }
    return true;
}

/*!
 * Przeciazenie operatora [] dla danych chronionych macierzy.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <>
double &Matrix3D::operator [] (unsigned int index){
if ( index >= SIZE*2 ) {
        std::cerr << "Error: Macierz jest poza zasiegiem!" << std::endl;
} // lepiej byłoby rzucić wyjątkiem stdexcept

return value[index][index];
}

/*!
 * Przeciazenie operatora [] const dla danych chronionych macierzy.
 * \param[in] index - pomocniczy unsigned int ktory zwroci odpowiedni dla
 *                      liczby czesc tablicy wspolrzednych.
 * 
 */
template <>
const double &Matrix3D::operator [] (unsigned int index) const{
    return value[index][index];
}


/*!
 * Przeciążenie operatora * const dla klasy macierzy.
 * \param[in] tmp - nazwa macierzy sprawdzanej z macierza zawarta wewnatrz klasy
 * 
 * \retval Wynik mnożenia.
 */
template <>
Vector3D Matrix3D::operator * (const Vector3D &tmp) const{
    Vector3D result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            if(value[i][j] != 0){
                result[i] += value[i][j] * tmp[j];
            }
        }
    }
    return result;
}

/*!
 * Przeciazenie operatora () dla danych chronionych macierzy.
 * \param[in] row - Zmienna do wyłuskania wiersza
 * 
 * \param[in] column - Zmienna do wyłuskania kolumny
 * 
 * \retval wyłuskaną z chronionej części macierzy wartość typu T.
 */
template <>
double &Matrix3D::operator () (unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cout << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/*!
 * Przeciazenie operatora () const dla danych chronionych macierzy.
 * \param[in] row - Zmienna do wyłuskania wiersza
 * 
 * \param[in] column - Zmienna do wyłuskania kolumny
 * 
 * \retval wyłuskaną z chronionej części macierzy wartość typu T.
 */
template <>
const double &Matrix3D::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        std::cerr << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    if (column >= SIZE) {
        std::cerr << "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej byłoby rzucić wyjątkiem stdexcept
    }

    return value[row][column];
}


/*!
 * Przeciążenie operatora + const dla klasy macierzy.
 * \param[in] tmp - nazwa macierzy sprawdzanej z macierza zawarta wewnatrz klasy
 * 
 * \retval Wynik dodawania.
 */
template <>
Matrix3D Matrix3D::operator + (Matrix3D tmp){
    Matrix3D result;
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/*!
 * Przeciazenie operatora wypisywania na ekran.
 * \param[in] in - strumien wejsciowy, do ktorego maja zostac wpisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Matrix do ktorej bedzie wypisywane
 *                     wspolrzedne na ekran.
 * 
 */
template <>
std::istream &operator >> (std::istream &in, Matrix3D &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        for (unsigned int j = 0; j < SIZE; ++j) {
            in >> tmp(i, j);
        }
    }
    return in;
}


/*!
 * Przeciazenie operatora wypisywania na ekran.
 * \param[in] out - strumien wyjsciowy, z ktorego maja zostac wpisane
 *                     kolejne wspolrzedne.
 * \param[in] tmp - skladowa klasy Matrix z ktorej bedzie wypisywane
 *                     wspolrzedne na ekran.
 * 
 */
template <>
std::ostream &operator << (std::ostream &out, const Matrix3D &tmp) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        out << "| ";
        for (unsigned int j = 0; j < SIZE; ++j) {
            out << tmp(i, j) << ' '; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        out << "|";
        std::cout << std::endl;
    }
    return out;
}