#pragma once
#include "vector.hpp"

/*!
 * \file  vector3d.hh
 *  
 *  Plik zawiera instancję klasy vector dla 3D.
 *  
 */

/*!
 * Instancja dla vectora 3D
 *
 *                       
 */
typedef Vector<double, 3>  Vector3D;

template <>
std::ostream& operator << (std::ostream &out, Vector3D const &tmp);

template <>
std::istream &operator >> (std::istream &in, Vector3D &tmp);

template <>
Vector3D::Vector();

template <>
Vector3D::Vector(const Vector &second);

template <>
Vector3D::Vector(double tmp[SIZE]);

template <> 
Vector3D::Vector(double x, double y, double z );

template <> 
Vector3D::~Vector();

template <>
Vector3D Vector3D::operator - (const Vector &tmp);

template <>
Vector3D Vector3D::operator + (const Vector &tmp);

template <>
Vector3D Vector3D::operator * (const double &tmp);

template <>
Vector3D Vector3D::operator * (const Vector &tmp) const;

template <>
bool Vector3D::operator == (const Vector &tmp) const;

template <>
const double &Vector3D::operator [] (unsigned int index) const;

template <>
double &Vector3D::operator [] (unsigned int index);

template <>
void Vector3D::Load_vector();
