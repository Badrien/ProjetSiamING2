#ifndef PIECE_H
#define PIECE_H
#include <map>

using namespace std;

class Piece
{
    //PUBLIC
    public:
        Piece();
        virtual~Piece();
        //toPut pour placer la piece
        virtual void toPut() const;
        //toMove pour d�placer la piece
        virtual void toMove() const;
        //Orientation
        virtual void toOrient() const;
        //Pour pousser les autres pieces
        virtual void toPush() const; // PERTINENT ? pareil que move?
        //Test si la case est vide
        bool testSquare(char t_row, char t_col, map<char, std::map<char, Piece> > board);
        //test les cases ext�rieurs
        bool canPut(char t_row, char t_col, map<char, std::map<char, Piece> > board);
        bool canPush(char t_row, char t_col, char t_dir, map<char, std::map<char, Piece> > board);
        //accesseurs int�ressantS
        char getrow();
        unsigned int getcol();

        //PROT�G�
    protected:
        // direction et r�sistance de la pouss�e
        int m_id;
        unsigned int m_dirDown;
        unsigned int m_dirUp;
        unsigned int m_dirLeft;
        unsigned int m_dirRight;

        //coordonn�es sur le plateau
        char m_row;
        char m_col;

        //coordonn�es de d�placement PERTINENT ?
        char m_drow;
        int m_dcol;

        //le caract�re ASCII associ� et couleur
        char m_logo;
        unsigned int m_color;

        //PRIV�
    private:
};

#endif // PIECE_H
