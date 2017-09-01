#ifndef CALC
#define CALC

#include <cctype>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <algorithm>

enum TokenValue : char {
  NUMBER, END, PLUS='+', MINUS='-', MUL='*', DIV='/', LP='(', RP=')'
};

enum NumberValue : char {
  NUM0='0', NUM1='1', NUM2='2',
  NUM3='3', NUM4='4', NUM5='5',
  NUM6='6', NUM7='7', NUM8='8',
  NUM9='9', NUMP='.', NUMC=',',
};

TokenValue currTok = END;   // last return of getToken()
double numberValue = 0;     // literal
int errorsNum = 0;          // counter of errors

double expr(std::istringstream& input, bool);

// Increments errors counter
double error(const std::string& errorMsg) {
  ++errorsNum;
  std::cerr << "error: " << errorMsg << std::endl;
  return 1;
}

// Self numbers processing because it can have '.' or ',' as num delimeter
TokenValue getNumberToken(std::istringstream& input) {
  char ch;
  std::stringstream s;
  short fraction = 0; // counter of numders after delimiter

  do
  {
      if(!input.get(ch)) break;

      if ( (ch == '.') || (ch == ',') )
      {
          if ( fraction == 0 )
          {
            s.put('.');
            ++fraction;
          }
          else
            error("Multiple delimiters");
      }

      if ( ((ch >= '0') && (ch <= '9')) )
      {
          s.put(ch);

          if ( fraction != 0 )
              ++fraction;
      }
  }
  while ( ((ch >= '0') && (ch <= '9')) || (ch == '.') || (ch == ',') );
  input.putback(ch);

  if ( fraction > 3 )
      error("Extra precision");

  s >> numberValue;

  return NUMBER;
}

TokenValue getToken(std::istringstream& input) {
  char ch;

  do { // skip all spaces
    if (!input.get(ch)) {
      return currTok = END; // End work
    }
  } while (ch != '\n' && isspace(ch));

  switch (ch) {
    case 0:
    case '\n':
      return currTok = END;
    case MUL:
    case DIV:
    case PLUS:
    case MINUS:
    case LP:
    case RP:
      return currTok = TokenValue(ch); // Приведение к целому и возврат.
    case NUM0: case NUM1: case NUM2: case NUM3: case NUM4:
    case NUM5: case NUM6: case NUM7: case NUM8: case NUM9:
    case NUMP: case NUMC:
      input.putback(ch); // putback in stream and...
      return currTok = getNumberToken(input); // get whole token
    default:
      error("Bad Token");
      return currTok = END;
  }
}

// Process primary expressions
double prim(std::istringstream& input, bool get) {
  if (get) {
    getToken(input);
  }

  switch (currTok) {
    case NUMBER: {
      double v = numberValue;
      getToken(input);
      return v;
    }
    case MINUS:
      return -prim(input, true);
    case LP: {
      double e = expr(input, true);
      if (currTok != RP) {
          return error("')' expected");
      }
      getToken(input);
      return e;
    }
    default:
      return error("primary expected");
  }
}

// Process multiplication and division
double term(std::istringstream& input, bool get) {
  double left = prim(input, get);

  for ( ; ; ) {
    switch (currTok) {
      case MUL:
        left *= prim(input, true);
        break;
      case DIV:
        if (double d = prim(input, true)) {
            left /= d;
            break;
        }
        return error("Divide by 0");
      default:
          return left;
    }
  }
}

// Process addition and extraction
double expr(std::istringstream& input, bool get) {
  double left = term(input, get);

  for ( ; ; ) {
    switch (currTok) {
      case PLUS:
        left += term(input, true);
        break;
      case MINUS:
        left -= term(input, true);
        break;
      default:
        return left;
    }
  }
}

double calc(std::istringstream& input)
{
    getToken(input);
    if (currTok == END)
        return 0;

    return expr(input, false);
}

#endif // CALC

