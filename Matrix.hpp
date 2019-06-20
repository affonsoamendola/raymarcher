#pragma once

class Vector3;

class Matrix33
{
private:
	double m_contents[9];
public:
	Matrix33();
	Matrix33(double contents[9]);

	double get_value(int column, int row);
	void set_value(int column, int row, double value);

	double determinant();

	Matrix33 transpose();

	Matrix33 operator+ (Matrix33& m);
	Matrix33 operator+= (Matrix33& m);

	Matrix33 operator+ (double s);
	Matrix33 operator+= (double s);

	Matrix33 operator* (double s);
	Matrix33 operator*= (double s);

	Matrix33 operator* (Matrix33& m);
	Vector3 operator* (Vector3& v);

	Matrix33 operator/ (double s);
	Matrix33 operator/= (double s);
};