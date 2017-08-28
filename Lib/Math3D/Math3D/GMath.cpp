#include "GMath.h"

//---------------------- GVector3 ----------------------//

GVector3::GVector3(float x, float y, float z)
{
	V[0] = x;
	V[1] = y;
	V[2] = z;
}

GVector3::GVector3(const GVector3 & copy)
{
	V[0] = copy.V[0];
	V[1] = copy.V[1];
	V[2] = copy.V[2];
}

GVector3 & GVector3::operator=(const GVector3 & rhs)
{
	V[0] = rhs.V[0];
	V[1] = rhs.V[1];
	V[2] = rhs.V[2];

	return *this;
}

GVector3 &GVector3::operator +=(const GVector3 &rhs)
{
	V[0] += rhs.V[0];
	V[1] += rhs.V[1];
	V[2] += rhs.V[2];
	return *this;
}

GVector3 &GVector3::operator -=(const GVector3 &rhs)
{
	V[0] -= rhs.V[0];
	V[1] -= rhs.V[1];
	V[2] -= rhs.V[2];
	return *this;
}

GVector3 &GVector3::operator *=(const float &s)
{
	V[0] *= s;
	V[1] *= s;
	V[2] *= s;
	return *this;
}

GVector3 &GVector3::operator /=(const float &s)
{
	V[0] /= s;
	V[1] /= s;
	V[2] /= s;
	return *this;
}

GVector3 &GVector3::operator ^=(const GVector3 &rhs)
{
	float x = V[0], y = V[1], z = V[2];
	V[0] = y * rhs.V[2] - z * rhs.V[1];
	V[1] = z * rhs.V[0] - x * rhs.V[2];
	V[2] = x * rhs.V[1] - y * rhs.V[0];
	return *this;
}

bool GVector3::operator ==(const GVector3 &rhs) const
{
	return !((*this) != rhs);
}

bool GVector3::operator !=(const GVector3 &rhs) const
{
	return (!EQ(V[0], rhs.V[0], PRECISION) || !EQ(V[1], rhs.V[1], PRECISION) || !EQ(V[2], rhs.V[2], PRECISION));
}

GVector3 GVector3::operator+(const GVector3 & rhs) const
{
	return GVector3(V[0] + rhs.V[0], V[1] + rhs.V[1], V[2] + rhs.V[2]);
}

GVector3 GVector3::operator-(const GVector3 & rhs) const
{
	return GVector3(V[0] - rhs.V[0], V[1] - rhs.V[1], V[2] - rhs.V[2]);
}

float norm(const GVector3& v)
{
	return SQRT(v.V[0] * v.V[0] + v.V[1] * v.V[1] + v.V[2] * v.V[2]);
}

GVector3& GVector3::normalize()
{
	float len = norm(*this);
	if (len > PRECISION)
	{
		V[0] /= len;
		V[1] /= len;
		V[2] /= len;
	}
	return *this;
}


float GVector3::operator*(const GVector3 & rhs) const
{
	return (V[0] * rhs.V[0] + V[1] * rhs.V[1] + V[2] * rhs.V[2]);
}

GVector3 operator*(const GVector3 & lhs, const float & k)
{
	return GVector3(lhs.V[0] * k, lhs.V[1] * k, lhs.V[2] * k);	
}

GVector3 operator*(const float & k, const GVector3 & rhs)
{
	return GVector3(rhs.V[0] * k, rhs.V[1] * k, rhs.V[2] * k);
}

GVector3 operator/(const GVector3 & lhs, const float & k)
{
	return GVector3(lhs.V[0] / k, lhs.V[1] / k, lhs.V[2] / k);
}

GVector3 GVector3::operator ^(const GVector3& rhs) const
{
	return GVector3(V[1] * rhs.V[2] - V[2] * rhs.V[1], V[2] * rhs.V[0] - V[0] * rhs.V[2], V[0] * rhs.V[1] - V[1] * rhs.V[0]);
}


GVector3 proj(const GVector3 & v, const GVector3 & w)
{
		return (v*w / SQR(norm(w)))*w;
}

GVector3 perp(const GVector3 & v, const GVector3 & w)
{
	return v - proj(v, w);
}

ostream & operator<<(ostream & os, const GVector3 & v)
{
	os << "[" << setw(10) << v.V[0] << ", " << setw(10) << v.V[1] << ", " << setw(10) << v.V[2] << "]";
	return os;
}

float &GVector3::operator [](const int &idx)
{
	return V[idx];
}

const float &GVector3::operator [](const int &idx) const
{
	return V[idx];
}