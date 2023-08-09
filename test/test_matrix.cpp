#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"

#include "neural_network.hh"
#include "neural_network_io.hh"

#include "lexer.hh"



void matrix_test ( Matrix<double> &m )
{
  Matrix<double> mcopy(m);

  assert( ( m.size() == mcopy.size() ) );
  assert( m.rows() == mcopy.rows() );
  assert( m.cols() == mcopy.cols() );
  mcopy.resize(2,1);

  assert( m.rows() != mcopy.rows() );
  assert( m.cols() != mcopy.cols() );

  Vector<double> v1, v2;
  v1.resize( m.cols() );
  m(v1, v2);

  std::cout<<m <<std::endl;
  std::stringstream file;
  file << m ;
  file >> mcopy;

  std::cout<<mcopy <<std::endl;
}

int main ( int argc, char** argv )
{
    Matrix<double> m(2,4);
    for(std::size_t i=0;i<2;++i)
        for(std::size_t j=0;j<4;++j)
            m[i][j] = i+j;
    matrix_test( m );

    return 0;
}
