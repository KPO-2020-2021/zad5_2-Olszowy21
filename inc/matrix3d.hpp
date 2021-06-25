#pragma once

#include "matrix.hpp"
#include "vector3d.hpp"

/*!
 * \file  matrix3d.hh
 *  
 *  Plik zawiera instancję klasy matrix.
 *  
 */

/*!
 * Instancja dla macierzy 3D
 *
 *                       
 */
typedef Matrix<double, 3>  Matrix3D;

template <>
Matrix3D::Matrix();

template <>
Matrix3D::Matrix(double tmp[SIZE][SIZE]);

template <>
void Matrix3D::set_degree_axis();

template <>
void Matrix3D::obrot_x(double kat);

template <>
void Matrix3D::obrot_y(double kat);

template <>
void Matrix3D::obrot_z(double kat);

template  <>
void Matrix3D::obrotmacierzy();

template  <>
bool Matrix3D::operator == (const Matrix3D tmp) const;

template <>
double &Matrix3D::operator [] (unsigned int index);

template <>
const double &Matrix3D::operator [] (unsigned int index) const;

template <>
Vector3D Matrix3D::operator * (const Vector3D &tmp) const;

template <>
double &Matrix3D::operator () (unsigned int row, unsigned int column);

template <>
const double &Matrix3D::operator () (unsigned int row, unsigned int column) const;

template <>
Matrix3D Matrix3D::operator + (Matrix3D tmp);

template <>
std::istream &operator >> (std::istream &in, Matrix3D &tmp);

template <>
std::ostream &operator << (std::ostream &out, const Matrix3D &tmp);