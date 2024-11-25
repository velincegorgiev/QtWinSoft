#include <iostream>
#include "complex1.h"

using namespace std;


Complex::Complex(double r, double i)
   : real(r), imaginary(i) { }

Complex Complex::operator+(const Complex &operand2) const {
   return Complex(real + operand2.real, imaginary + operand2.imaginary);
}

Complex Complex::operator-(const Complex &operand2) const {
   return Complex(real - operand2.real, imaginary - operand2.imaginary);
}

Complex Complex::operator*(const Complex &operand2) const {
   double newReal = real * operand2.real - imaginary * operand2.imaginary;
   double newImaginary = real * operand2.imaginary + imaginary * operand2.real;
   return Complex(newReal, newImaginary);
}

Complex Complex::operator*(int n) const {
   return Complex(real * n, imaginary * n);
}

Complex Complex::operator*(double n) const {
   return Complex(real * n, imaginary * n);
}

bool Complex::operator==(const Complex &operand2) const {
   return (real == operand2.real && imaginary == operand2.imaginary);
}

bool Complex::operator!=(const Complex &operand2) const {
   return !(*this == operand2);
}

Complex& Complex::operator+=(const Complex &operand2) {
   real += operand2.real;
   imaginary += operand2.imaginary;
   return *this;
}

Complex& Complex::operator-=(const Complex &operand2) {
   real -= operand2.real;
   imaginary -= operand2.imaginary;
   return *this;
}

Complex& Complex::operator*=(const Complex &operand2) {
   *this = *this * operand2;
   return *this;
}

Complex& Complex::operator*=(int n) {
   *this = *this * n;
   return *this;
}

Complex& Complex::operator*=(double n) {
   *this = *this * n;
   return *this;
}

ostream& operator<<(ostream &out, const Complex &c) {
   out << c.real;
   if (c.imaginary >= 0)
      out << " + " << c.imaginary << "i";
   else
      out << " - " << -c.imaginary << "i";
   return out;
}

istream& operator>>(istream &in, Complex &c) {
   in >> c.real >> c.imaginary;
   return in;
}
