#ifndef VECTOR_HH
#define VECTOR_HH

#include <ostream>
#include <vector>

template<class T>
class Vector 
{
    typedef Vector< T > ThisType;
    typedef T DataType;
public:
    Vector () {}

    Vector ( std::size_t n ) :
        data_( n )
    {}

    Vector ( const ThisType &other ) :
        data_( other.data_ )
    {}

    Vector ( std::size_t n, const T &t ) :
        data_(n, t)
    {}

    void resize (std::size_t n, const T &t = T(0) )
    { 
        data_.clear(); 
        data_.resize(n, t); 
    }
    
    void clear ()
    {
        for( auto & e : data_)
            e = T(0);
    }

    std::size_t size() const { return data_.size(); }

    T& operator[] (std::size_t i) { return data_[i]; }
    const T& operator[] (std::size_t i) const { return data_[i]; }

    DataType operator* ( const ThisType & o) const
    {
        DataType ret(0);
        for( std::size_t i=0; i < data_.size(); ++i )
            ret += data_[i] * o[i];
        return ret;
    }

    void operator* ( const DataType &t ) 
    {
        for( std::size_t i=0; i < data_.size(); ++i )
            data_[i] *= t;
    }

    void operator/ ( const DataType &t ) 
    {
        for( std::size_t i=0; i < data_.size(); ++i )
            data_[i] /= t;
    }

    ThisType operator+ ( const ThisType &other) const 
    {
        ThisType ret( data_.size(), DataType(0) );
        for( std::size_t i=0; i < data_.size(); ++i )
            ret[i] = data_[i] + other[i];
        return ret;
    }

    ThisType operator- ( const ThisType &other) const 
    {
        ThisType ret( data_.size(), DataType(0) );
        for( std::size_t i=0; i < data_.size(); ++i )
            ret[i] = data_[i] - other[i];
        return ret;
    }

    ThisType& operator-= ( const ThisType &other) 
    {
        for( std::size_t i=0; i < data_.size(); ++i )
            data_[i] -= other[i];
        return *this;
    }

    ThisType& operator+= ( const ThisType &other) 
    {
        for( std::size_t i=0; i < data_.size(); ++i )
            data_[i] += other[i];
        return *this;
    }

    private:
    std::vector<T> data_;
};



template<class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &input)
{
    for (std::size_t i = 0; i < input.size(); ++i) {
        os << input[i] << " ";
    }
    return os;
}

#endif // VECTOR_HH
