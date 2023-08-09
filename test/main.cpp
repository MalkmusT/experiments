#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"

#include "neural_network.hh"
#include "neural_network_io.hh"



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

void vector_test ( Vector<double> &v )
{
  Vector<double> v_copy(v);
  assert( v_copy.size() == v.size() );
  double d = v * v_copy;

  v_copy.resize( 1 );
  assert( v_copy.size() != v.size() );

  std::stringstream file;
  file << v;
  file >> v_copy;
}

void sigmoid_test ( double a, const Vector< double> &va, const Matrix< double> &ma)
{
  double a_copy(a);
  Vector< double > v_copy(va);
  Matrix< double > m_copy(ma);
  sigmoid( a_copy );
  sigmoid( v_copy );
  sigmoid( m_copy );

  sig_prime( a_copy );
  sig_prime( v_copy );
  sig_prime( m_copy );
}

void test_nn ( NNetwork< double > &nn )
{
  std::size_t rows = 16, cols = 5;
    nn.resize(rows,cols);
    NN_Initializor< double > initializor(rows,cols);
    nn.init(initializor);
    Vector< double> arg(cols), dest(rows);
    nn( arg, dest );
    nn.feedForward( arg, dest );

    NN_Random_Init<double> initRand(rows,cols, 42);
    nn.init( initRand );
}



int main ( int argc, char** argv )
{
    Matrix<double> m(2,4);
    for(std::size_t i=0;i<2;++i)
        for(std::size_t j=0;j<4;++j)
            m[i][j] = i+j;
    matrix_test( m );

    Vector<double> v(15);
    for(std::size_t i=0;i<15;++i)
      v[i] = i;
    vector_test(v);

    double a =123;
    sigmoid_test( a, v, m );

    NNetwork< double > nn(4,2);
    test_nn(nn);

    return 0;
}
