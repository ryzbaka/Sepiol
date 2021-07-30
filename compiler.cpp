/*
    The lexer takes a string as input and breaks it up into tokens.
    Each token consists of a token code and some associated metadata.

*/
#include <string>
using std::string;

//---------------------------
//---------LEXER-------------
//---------------------------
enum Token
{
  tok_eof = -1,
  // commands
  tok_def = -2,
  tok_extern = -3,
  // primary
  tok_identifier = -4,
  tok_number = -5
}; // defining possible token values.
//static global functions and variables are for internal linkage (can only be used in the curren source file)
static string IdentifierString; // filled in if tok_identifier
static double NumVal;           // filled in if tok_number
static int gettok()
{
  static int lastChar = ' '; // lastChar stores the last read but unprocessed character.
  while (isspace(lastChar))
  {
    lastChar = getchar();
  } // ignoring all whitespaces.
  if (isalpha(lastChar))
  {
    IdentifierString = lastChar; // acts as character accumulator to check if
    // the alphabetic input is a reserved keyword.
    while (isalnum((lastChar = getchar())))
    {
      IdentifierString += lastChar;
    }

    if (IdentifierString == "def")
    {
      return tok_def;
    }

    if (IdentifierString == "extern")
    {
      return tok_extern;
    }
    return tok_identifier;
  }
  if (isdigit(lastChar))
  {
    string numString;
    do
    {
      numString += lastChar;
      lastChar = getchar();
    } while (isdigit(lastChar) || lastChar == '.');
    NumVal = strtod(numString.c_str(), nullptr); // converting double string to double.
    //.c_str returns a pointer to a null terminated character array.
    return tok_number;
  }
  if (lastChar == '#')
  {
    //handling single line comments, keep skipping letters without processing till \n, \r or EOF.
    do
    {
      lastChar = getchar();
    } while (lastChar != EOF && lastChar != '\n' && lastChar != '\r');
    if (lastChar != EOF)
    {
      //if the file hasn't ended, reset lastChar and run the function again.
      return gettok(); //look this up again.
    }
  }
  if (lastChar == EOF)
  {
    return tok_eof;
  }
  int asciiCode = lastChar;
  lastChar = getchar(); //handling values other than the reserved keywords, comments, EOF, identifiers and numbers.
  return lastChar;      // returns value between 0-255 (ASCII code of character)
}