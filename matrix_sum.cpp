#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
      rows = 0;
      columns = 0;
    }

    Matrix(int num_rows, int num_cols) {
      Reset(num_rows, num_cols);
    }

    void Reset(int new_rows, int new_cols) {
      if(new_rows < 0){
        throw out_of_range("num_rows must be >= 0");
      }

      if(new_cols < 0){
        throw out_of_range("num_cols must be >= 0");
      }

      rows = new_rows;
      columns = new_cols;

      matrix.assign(rows, vector<int>(columns));
    }

    int& At(int rows, int cols) {
      return matrix.at(rows).at(cols);
    }

    int At(int rows, int cols) const {
      return matrix.at(rows).at(cols);
    }

    int GetNumRows() const {
      return rows;
    }

    int GetNumColumns() const {
      return columns;
    }

private:
    int rows;
    int columns;

    vector<vector<int>> matrix;
};

ostream& operator<<(ostream& stream, const Matrix& matrix) {
  int rows = matrix.GetNumRows();
  int columns = matrix.GetNumColumns();
  stream << rows << " " << columns << endl;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      if(j == columns - 1){
        stream << matrix.At(i, j);
      }else{
        stream << matrix.At(i, j) << " ";
      }
    }
    stream << endl;
  }
  return stream;
}

istream& operator>>(istream& stream, Matrix& matrix) {
  int row;
  int column;

  stream >> row >> column;
  matrix.Reset(row, column);

  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < column; ++j) {
      stream >> matrix.At(i, j);
    }
  }

  return stream;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
  if (lhs.GetNumRows() == rhs.GetNumRows() &&
      lhs.GetNumColumns() == rhs.GetNumColumns()) {
    for (int i = 0; i < lhs.GetNumRows(); ++i){
      for (int j = 0; j < lhs.GetNumColumns(); ++j){
        if(lhs.At(i, j) != rhs.At(i, j)){
          return false;
        }
      }
    }
  }else{
    return false;
  }
  return true;
}

Matrix operator+(const Matrix& lhs, const Matrix& rhs) {

  if (lhs.GetNumRows() != rhs.GetNumRows()) {
    throw invalid_argument("Number of rows are not equal");
  }

  if(lhs.GetNumColumns() != rhs.GetNumColumns()){
    throw invalid_argument("Number of columns are not equal");
  }

  Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

  for (int i = 0; i < result.GetNumRows(); ++i){
    for (int j = 0; j < result.GetNumColumns(); ++j){
      result.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
    }
  }

  return result;
}

int main() {
  Matrix one;
  Matrix two;
  try {
    cin >> one >> two;
    cout << one + two << endl;
  }catch (out_of_range& oor){
    cout << oor.what() << endl;
  }catch (invalid_argument& ia){
    cout << ia.what() << endl;
  }
  return 0;
}
