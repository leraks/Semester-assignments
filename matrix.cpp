#include <iostream>

class Matrix
{
private:
    int n,m;
    double ** data;
public:
    Matrix(int newM = 0, int newN = 0)
        : n(newN), m(newM)
    {
        data = new double*[m];
        for (int i = 0; i<m; i++)
        {
            data[i] = new double[n];
            for (int j = 0; j < n; j++){
                data[i][j] = 0;
            }
        }
    }   
    ~Matrix() 
    {
        for (int i=0; i<m; i++)
        {
            delete data[i];
        }
        delete data;
    }
    void operator= (const Matrix& D);
    friend std::ostream& operator<< (std::ostream &out,  const Matrix &m);
    friend std::istream& operator>> (std::istream &in, const Matrix &m);
};
    
std::ostream& operator<< (std::ostream &out,  const Matrix &mtr)
    {
        out << "Matrix(" << mtr.n << "," << mtr.m << ")" << "\n";
        for (int i = 0; i < mtr.m; i++){
            for (int j = 0; j < mtr.n; j++) {
                out << mtr.data[i][j] << " ";
            }
            out << "\n";
        }
        return out;
    }

std::istream& operator>> (std::istream &in, const Matrix &mtr)
{
    for (int i = 0; i < mtr.m; i++){
        for (int j = 0; j < mtr.n; j++){
            in >> mtr.data[i][j];
        }
    }
    return in;
}

void Matrix::operator= (const Matrix& D){
    for (int i = 0; i < m; i++){
        delete data[i];
    }
    delete data;

    m = D.m;
    n = D.n;

    data = new double*[m];
    for (int i = 0; i < m; i++){
        data[i] = new double[n];
        for (int j = 0; j < n; j++){
            data[i][j] = D.data[i][j];
        }
    }
}

int main()
{
    Matrix mtr(2,3), mtr2(3, 3);
 
    std::cout << mtr;
    std::cin >> mtr;
    std::cout << mtr;
    std::cout << mtr2;
    std::cin >> mtr2;
    std::cout << mtr2;
    mtr = mtr2;
    std::cout << mtr;
    return 0;
}