#include <iostream>
#include <iomanip>
#include <string>
#include <stdexcept>

int ** fill(unsigned int rows, unsigned int columns)
{
	int ** matrix = new int * [rows]();
	for (unsigned int i = 0; i < rows; ++i)
	{
		matrix[i] = new int[rows](); //columns
	}


	int el = 1, row_ = 0, _row = rows - 1, column_ = columns - 1, _column = 0;;

	if (rows != 1 && columns != 1)
	{
		while (row_ < _row && _column < column_)
			{
			
				for (unsigned int j = _column; j <= column_; ++j)	// -->
					matrix[row_][j] = el++;
				row_++;
			
				for (unsigned int i = row_; i <= _row; ++i)			// |
					matrix[i][column_] = el++;						// |
				column_--;											// V

				for (int j = column_; j > _column - 1; --j)			// <--
					matrix[_row][j] = el++;
				_row--;

				for (int i = _row; i > row_ - 1; --i)				// ^
					matrix[i][_column] = el++;						// |
				_column++;											// |
			}
		if (row_ == _row && _column <= column_)
		{
			for (unsigned int j = _column; j <= column_; ++j)	// -->
				matrix[row_][j] = el++;
			row_++;
		}
		if (row_ <= _row && _column == column_)
		{
			for (unsigned int i = row_; i <= _row; ++i)			// |
				matrix[i][column_] = el++;						// |
			column_--;											// V
		}
	}
	else
	{
		if (rows == 1)
		{
			for (unsigned int j = _column; j <= column_; ++j)
				matrix[row_][j] = el++;
			row_++;
		}
		else
		{
			for (unsigned int i = row_; i <= _row; ++i)
				matrix[i][column_] = el++;
			column_--;
		}
	}
	return matrix;
}


int main()
{
	int ** matrix;
	int rows = 0, columns = 0;
	std::string s, s1, s2;
	std::size_t a;

	std::cout << "Enter the number of rows and columns in the format: rows, columns" << std::endl;
	std::getline(std::cin, s);
	a = s.find(",");
	s1 = s.substr(0, a);
	s2 = s.substr(a + 2);
	rows = stoi(s1);
	columns = stoi(s2);

	if (rows < 0 || columns < 0 || a == 0 || a > s.size())
		throw std::logic_error("ERROR");

	matrix = fill(rows, columns);
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < columns; ++i) //++j
		{
			std::cout << std::setw(4) << matrix[i][j];
		}
		std::cout << std::endl << std::endl;
	}
	return 0;
}
