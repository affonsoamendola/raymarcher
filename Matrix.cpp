#include "Matrix.hpp"
#include "Vector.hpp"

Matrix33::Matrix33(double contents[9])
{
	for(int i = 0; i < 9; i++)
		this->m_contents[i] = contents[i];
}

Matrix33::Matrix33()
{
	for(int i = 0; i < 9; i++)
		this->m_contents[i] = 0.;
} 

double Matrix33::get_value(int column, int row)
{
		return this->m_contents[column + row * 3];
}

void Matrix33::set_value(int column, int row, double value)
{
		this->m_contents[column + row * 3] = value;
}

double Matrix33::determinant()
{
	return 	this->m_contents[0]*this->m_contents[4]*this->m_contents[8] + 
			this->m_contents[1]*this->m_contents[5]*this->m_contents[6] +
			this->m_contents[2]*this->m_contents[3]*this->m_contents[7] -
			this->m_contents[2]*this->m_contents[4]*this->m_contents[6] -
			this->m_contents[1]*this->m_contents[3]*this->m_contents[8] -
			this->m_contents[0]*this->m_contents[5]*this->m_contents[7];
}

Matrix33 Matrix33::transpose()
{
	Matrix33 transposed(this->m_contents);

	transposed.set_value(1, 0, this->get_value(0,1));
	transposed.set_value(2, 0, this->get_value(0,2));
	transposed.set_value(1, 2, this->get_value(2,1));

	return transposed;
}

Matrix33 Matrix33::operator+(Matrix33& b_matrix)
{
	Matrix33 new_m;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			new_m.set_value(x, y, this->get_value(x, y) + b_matrix.get_value(x, y));
		}
	}

	return new_m;
}

Matrix33 Matrix33::operator+=(Matrix33& b_matrix)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			this->set_value(x, y, this->get_value(x, y) + b_matrix.get_value(x, y));
		}
	}
}

Matrix33 Matrix33::operator+(double s)
{
	Matrix33 new_m;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			new_m.set_value(x, y, this->get_value(x, y) + s);
		}
	}

	return new_m;
}

Matrix33 Matrix33::operator+=(double s)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			this->set_value(x, y, this->get_value(x, y) + s);
		}
	}
}

Matrix33 Matrix33::operator*(double s)
{
	Matrix33 new_m;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			new_m.set_value(x, y, this->get_value(x, y) * s);
		}
	}

	return new_m;
}

Matrix33 Matrix33::operator*=(double s)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			this->set_value(x, y, this->get_value(x, y) * s);
		}
	}
}

Matrix33 Matrix33::operator/(double s)
{
	Matrix33 new_m;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			new_m.set_value(x, y, this->get_value(x, y) / s);
		}
	}

	return new_m;
}

Matrix33 Matrix33::operator/=(double s)
{
	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{
			this->set_value(x, y, this->get_value(x, y) / s);
		}
	}
}

Matrix33 Matrix33::operator*(Matrix33& m)
{
	Matrix33 new_m;

	double value;

	for(int x = 0; x < 3; x++)
	{
		for(int y = 0; y < 3; y++)
		{	
			value = 0.;

			for(int k = 0; k < 3; k++)
			{
				value += this->get_value(k, y) * m.get_value(x, k);
			}

			new_m.set_value(x, y, value);
		}
	}

	return new_m;
}

Vector3 Matrix33::operator*(Vector3& v)
{
	Vector3 new_v;

	double value;

	for(int y = 0; y < 3; y++)
	{	
		value = 0.;

		for(int k = 0; k < 3; k++)
		{
			value += this->get_value(k, y) * v[k];
		}

		new_v[y] = value;
	}

	return new_v;
}