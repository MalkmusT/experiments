#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "lexer.hh"


int main ( int argc, char** argv )
{
  // AlphaLexer
    std::string alpha_test_str = "uf 123 nawnnv48qwawoieh";
    for ( auto e : alpha_test_str)
      if( e != AlphaLexer::backward( AlphaLexer::forward(e) ) )
        std::cout<< e << "!=" << AlphaLexer::backward( AlphaLexer::forward(e) ) << std::endl;
    std::string alpha_res = AlphaLexer::backward( AlphaLexer::forward( alpha_test_str ) );

  // HexLexer
    std::string hex_test_str = "1234567890abcdef";
    for ( auto e : hex_test_str)
      if ( e != HexLexer::backward( HexLexer::forward(e) ) ) 
        std::cout<< e <<"!="<<HexLexer::backward( HexLexer::forward(e) ) <<std::endl ; 
    std::string hex_res = HexLexer::backward( HexLexer::forward( alpha_test_str ) );

  // HashLexer
  
    return 0;
}
