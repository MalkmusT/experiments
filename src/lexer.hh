#ifndef LEXER_HH
#define LEXER_HH


// convert [abc..012..9 ] to e in R^37

struct AlphaLexer
{
  
  static constexpr std::size_t size() { return 37; }
  static constexpr char backward ( std::size_t i ) { return vals_[i]; }

  static std::size_t forward ( char in ) {
    for( std::size_t i = 0; i < size(); ++i )
      if ( vals_[i] == in ) return i;
    return 0;
  }

  static std::vector<char> backward ( const std::vector<std::size_t> &is )
  {
    std::vector<char> ret(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = AlphaLexer::backward( is[i] );
    return ret;
  }

  static std::vector<std::size_t > forward ( const std::vector<char> &is )
  {
    std::vector<std::size_t> ret(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = AlphaLexer::forward( is[i] );
    return ret;
  }

  static constexpr char* vals_ = "0123456789abcdefghijklmnopqrstuvwxyz ";
};


struct HexLexer
{
  static constexpr std::size_t size() { return 16; }
  static constexpr char backward (std::size_t i) { return vals_[i]; } 
  static std::size_t forward (char in )
  {
    for( std::size_t i = 0; i < size(); ++i )
      if ( vals_[i] == in ) return i;
    return 0;
  }

  static std::vector<char> backward ( const std::vector<std::size_t> &is )
  {
    std::vector<char> ret(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = HexLexer::backward( is[i] );
    return ret;
  }

  static std::vector<std::size_t > forward ( const std::vector<char> &is )
  {
    std::vector<std::size_t> ret(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = HexLexer::forward( is[i] );
    return ret;
  }

  static constexpr char* vals_ = "0123456789abcdef";
};

#endif // #ifndef LEXER_HH 
