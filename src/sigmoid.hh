#ifndef SIGMOID_HH
#define SIGMOID_HH

#include <math.h>


// Sigmoid
// -------

struct Sigmoid 
{
    void operator() ( double &t ) const
    { 
        t = 1.0 / ( 1.0 + std::exp( -1.0 * t ));
    }

    template< class T >
    void operator() ( T &e ) const
    { 
        for( std::size_t i = 0; i < e.size(); ++i ) 
            (*this)(e[i]);
    }

    template<class T>
    T operator() ( const T &t ) const
    {
        T ret(t);
        (*this)(ret);
        return ret;
    }

    struct Derivativ
    {
        void operator() ( double &t ) const
        { 
            t = 1.0 / ( 1.0 + std::exp( -1.0 * t ));
            t = t * ( 1.0 - t );
        }
        template< class T >
        void operator() ( T &e ) const
        { 
            for( std::size_t i = 0; i < e.size(); ++i ) 
                (*this)(e[i]);;
        }
        
        template<class T>
        T operator() ( const T &t ) const
        {
            T ret(t);
            (*this)(ret);
            return ret;
        }
    };
    
};

#endif // SIGMOID_HH
