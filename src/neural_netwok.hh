#ifndef NEURAL_NETWORK_HH
#define NEURAL_NETWORK_HH

#include <vector>
#include <array>

#include "vector.hh"
#include "sigmoid.hh"
#include "matrix.hh"

// forward definition
//template< class T, std::size_t L >
//class NNetwork;



template< class T >
class NNetwork< T >
{
    typedef NNetwork<T> ThisType;
    public:
    typedef Vector<T> ArgumentType;
    typedef Vector<T> ObjectType;
    typedef Matrix<T> DataType;
    
    NNetwork () {}

    NNetwork ( std::size_t rows, std::size_t cols )
    {
        this->resize( rows, cols );
    }

    template< class Lambda >
    void init ( Lambda l ) 
    {
        for(std::size_t j = 0; j <  weights_.columns(); ++j ) 
        {           
            biases_[i][j] = l(0)(j);
            for(std::size_t k = 0; k <  weights_.rows(); ++k )
                weights_[k][j] = l(0)(k,j);            
        }
    }


    void resize ( std::size_t rows, std::size_t cols ) 
    {
        weights_.resize( rows, cols );
        biases_.resize( rows );
    }

    void operator() ( const ArgumentType &arg, ArgumentType &dest ) const 
    {
        weights_( arg, dest );
        dest -= biases_;
        sigmoid(dest);
    }

    void feedForward ( const ArgumentType &arg, ObjectType &dest ) const
    {
        this->operator()( arg, dest );
    }

    // compute new weights an biases using MQF 
    void feedBackward ( const ArgumentType &arg, const ObjectType &dest )    
    {
        ObjectType help(dest);
        weights_(arg, help);
        help -= biases_;
        weights_ -= alpha * (sigmoid( help) * sig_prime( help)) 
    }

    private:
    DataType weights_;
    ObjectType biases_;
};





/**
template< class T, std::size_t L>
class NNetwork
{
    typedef NNetwork<T,L> ThisType;
    public:
    typedef Vector<T> ArgumentType;
    typedef Vector<T> ObjectType;
    typedef Matrix<T> DataType;
    
    NNetwork () {}

    NNetwork ( std::array< std::tuple<std::size_t, std::size_t>, L> dimensions )
    {
        this->resize( dimensions );
    }

    template< class Lambda >
    void init ( Lambda l ) 
    {
        for( std::size_t i =0; i< L; ++i )
            for(std::size_t j = 0; j <  weights_[i].columns(); ++j ) 
            {           
                biases_[i][j] = l(i)(j);
                for(std::size_t k = 0; k <  weights_[i].rows(); ++k )
                    weights_[i][k][j] = l(i)(k,j);            
            }
    }


    void resize ( std::array< std::tuple<std::size_t, std::size_t>, L> dimensions )
    {
        for( std::size_t i =0; i< L; ++i )
        {
            weights_[i].resize( dimensions[i][0], dimensions[i][1] );
            biases_[i].resize( dimensions[i][1] );
        }
    }

    void operator() ( const ArgumentType &arg, ArgumentType &dest ) const 
    {
        ArgumentType tmp(arg);
        for( std::size_t i =0; i< L; ++i )
        {
            weights_[i] ( tmp, dest );
            dest -= biases_[i];
            sigmoid(dest);
            tmp = dest;
        }
    }

    void feedForward ( const ArgumentType &arg, ObjectType &dest ) const
    {
        this->operator()( arg, dest );
    }

    // compute new weights an biases using MQF 
    void feedBackward ( const ObjectType &y, const ObjectType &z )
    {
    }

    private:
    std::array< DataType, L > weights_;
    std::array< ObjectType, L > biases_;
};
**/

#endif // #ifndef NEURAL_NETWORK_HH
