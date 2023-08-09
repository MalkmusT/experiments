#include <iostream>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"
#include "neural_netwok.hh"


int main ( int argc, char** argv )
{
    Matrix<double> m(2,4);
    for( std::size_t i=0;i<2;++i)
        for(std::size_t j=0;j<4;++j)
            m[i][j] = i+j;

    std::cout << m << std::endl;

    sigmoid(m);
    std::cout << m << std::endl;

    return 0;
}
