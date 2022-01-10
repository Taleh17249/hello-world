#pragma once
class Matrix2
{
private:
	int col;
	int row;
	int* element;

public:

	Matrix2();
	Matrix2(int i, int j);
	Matrix2(int i, int j, const int* arr);

	~Matrix2();

	Matrix2(const Matrix2& orig);

	void sum(int row, int col, const int* arr);
	bool sum(Matrix2 second);

	bool mult(int row, int col, const int* arr);
	bool mult(Matrix2 second);

	void input(int i, int j, bool flag);
	void input(int i, int j, const int* arr);

	void print();
};



