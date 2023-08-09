#ifndef SIGMOID_HH
#define SIGMOID_HH

#include <math.h>

#include "vector.hh"
#include "matrix.hh"


// Scalar version of sigmoid and derivative
// ----------------------------------------

void sigmoid ( double &i )
{
    i = 1.0 / ( 1.0 + std::exp( -1.0 * i )); 
}


// derivative

void sig_prime ( double &i )
{
  sigmoid(i);
  i = i * ( 1.0 - i );
}

// general version of sigmoid and derivative
// ----------------------------------------


template<class T>
void sigmoid ( T &e )
{
    for( std::size_t i = 0; i < e.size(); ++i )
        sigmoid(e[i]);
}

template<class T>
void sig_prime ( T &e )
{
    for( std::size_t i = 0; i < e.size(); ++i )
        sig_prime(e[i]);
}



// Vector version of sigmoid and derivative
// ----------------------------------------

template<class T>
T sigmoid ( const T &i )
{
    T ret(i);
    sigmoid( ret );
    return ret;
}

template<class T>
T sig_prime( const T &i)
{
    T ret( i );
    sig_prime( ret );
    return ret;
}


#endif // SIGMOID_HH
