#include <iostream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"

#include "neural_netwok.hh"


template< class T >
struct NN_Initializor 
{
    T operator() ( std::size_t i ) const { return T(i); }
    T operator() ( std::size_t i, std::size_t j ) const { return T(i+j); }
};


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
}

void vector_test ( Vector<double> &v )
{
  Vector<double> v_copy(v);
  assert( v_copy.size() == v.size() );
  double d = v * v_copy;

  v_copy.resize( 1 );
  assert( v_copy.size() != v.size() );
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
    nn.resize(16,5);
    NN_Initializor< double > initializor;
    nn.init(initializor);
    Vector< double> arg(15), dest(15);
    nn( arg, dest );
    nn.feedForward( arg, dest );
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
