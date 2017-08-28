#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// class GVector3

#define PRECISION		0.0000001
#define SQRT(X)			sqrt((X))
#define SQR(X)			((X) * (X))
#define EQ(X, Y, EPS)	(ABS((X) - (Y)) < EPS)
#define ABS(X)			(((X) > 0.0) ? (X) : (-(X)))

class GVector3
{
public:

	GVector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	GVector3(const GVector3 &copy);

	// Assignment operator overloading
	GVector3& operator =(const GVector3& rhs);

	// Compound assignment operator overloading
	GVector3 &operator +=(const GVector3 &rhs);
	GVector3 &operator -=(const GVector3 &rhs);
	GVector3 &operator *=(const float &s);
	GVector3 &operator /=(const float &s);
	GVector3 &operator ^=(const GVector3 &rhs);
	
	// Equality and inequality operator overloading
	bool operator ==(const GVector3 &rhs) const;
	bool operator !=(const GVector3 &rhs) const;

	// The addition and subtraction of vectors
	GVector3 operator +(const GVector3& rhs) const; // u + v
	GVector3 operator -(const GVector3& rhs) const; // u - v

	// The inner product of vectors
	float operator *(const GVector3& rhs) const; // u * v
	// The outer product of vectors
	GVector3 operator ^(const GVector3& rhs) const; // u ^ v 

	// The norm and direction of vectors
	friend float norm(const GVector3& v);
	GVector3& normalize();

	// The projection of vectors
	friend GVector3 proj(const GVector3& v, const GVector3& w); // proj 
	friend GVector3 perp(const GVector3& v, const GVector3& w); // prep

	// The output of vectors
	friend ostream& operator <<(ostream &os, const GVector3& v);

	// Subscript operator overloading
	float &operator [](const int &idx);
	const float &operator [](const int &idx) const;

	// The multiplication of vectors and scalars
	friend GVector3 operator *(const GVector3& lhs, const float& k); // k * u
	friend GVector3 operator *(const float& k, const GVector3& rhs); // u * k
	friend GVector3 operator /(const GVector3& lhs, const float& k); // u / k

private:
	float V[3];

};