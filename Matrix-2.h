#pragma once
#include<iostream>
class Matrix
{
private:
	int size;
	int* elem;
	int det(int* matr, int R);
	void getmatr(int* matr, int* p, int i, int j, int rows);
public:
	Matrix();
	Matrix(const Matrix& matr);
	~Matrix();

	friend std::ostream& operator<<(std::ostream& out, const Matrix& temp);
	friend std::istream& operator>>(std::istream& in, Matrix& temp);
	/*void operator*(Matrix& m1, Matrix& m2);*/
	void input();
	void input(int n);
	/*void multp(const Matrix& temp);*/

	int get_elem(int i, int j) const;
	void print() const;
	int get_size() const;
	int trace() const;

	double det();


	void operator- (const Matrix& temp);
	void operator+= (const Matrix& temp);
	void operator+ (const Matrix& temp);
	void operator-= (const Matrix& temp);
	void operator*(int num);
	void operator- ();
	void operator* (const Matrix& temp);
};
