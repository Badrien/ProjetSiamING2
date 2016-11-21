#include "Piece.h"
#include <map>

using namespace std;

Piece::Piece()
{
    //ctor
}

Piece::~Piece()
{
    //dtor
}

unsigned int Piece::getcol()
{
    return this->m_col;
}
char Piece::getrow()
{
    return this->m_row;
}

bool Piece::testSquare(char t_row, char t_col, map<char, std::map<char, Piece> > board )
//renvoir faux si la case est prise et vrai si elle est vide
{
    char emptySquare = 127;
    if(board[t_row][t_col].m_logo == emptySquare)
    {
        return true;
    }
    else if (board[t_row][t_col].m_logo != emptySquare)
    {
        return false;
    }
}

bool Piece::canPut(char t_row, char t_col, map<char, std::map<char, Piece> > board)
//renvoie vrai si l'on peut placer son pion sur les cases extérieurs et faux sinon
{
    char i, a;

    for(i = '1', a = 65; i< '5', a<69; i++, a++ )
    {
    //On test la ligne extérieur des A et des E :
        if( (board[t_row][t_col].m_id == board['A'][i].m_id) || (board[t_row][t_col].m_id == board['E'][i].m_id) )
        {
            return true;
        }
        //On test les colonnes extérieurs 1 et 5
        else if ( (board[t_row][t_col].m_id == board[a]['1'].m_id) || (board[t_row][t_col].m_id == board[a]['5'].m_id) )
        {
            return true;
        }
        else{ return false;}
    }
}

bool Piece::canPush(char t_row, char t_col, char t_dir, map<char, std::map<char, Piece> > board)
//renvoie vrai s'il on peut pousser les pieces dans la bonne direction et faux sinon
{
    int strength = 0;
    int resistor = 0;
  switch(t_dir)
  {
      case 'b':
          strength = this->m_dirDown;
          for(char i = this->m_row; i <= 5 - this->m_row; i++)
          {
              if(!testSquare(i, this->m_col, board))
              {
                  strength = strength + board[i][this->m_col].m_dirDown;
                  resistor = resistor + board[i][this->m_col].m_dirUp;
              }
          }
        break;
      case 'h':
        break;
      case 'g':
        break;
      case 'd':
        break;
  }
}
