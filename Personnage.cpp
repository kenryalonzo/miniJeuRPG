#include <iostream>
#include "Personnage.hpp"

using namespace std;

Personnage::Personnage() : m_arme(nullptr), m_vie(100), m_mana(100) 
{
    m_arme = new Arme();
}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nullptr)
{
    m_arme = new Arme(nomArme, degatsArme);    
}

Personnage :: Personnage(Personnage const& personnageAcopier) : m_vie(personnageAcopier.m_vie), m_mana(personnageAcopier.m_mana), m_arme(nullptr)
{
    m_arme = new Arme(*(personnageAcopier.m_arme));
}

Personnage::~Personnage()
{
    delete m_arme;
}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme->getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100)
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme->changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant()
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Personnage::afficherEtat()
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme->afficher();
}

Personnage& Personnage::operator=(Personnage const& personnageACopier) 
{
    if(this != &personnageACopier)
    //On vérifie que l'objet n'est pas le même que celui reçu en argument
    {
        m_vie = personnageACopier.m_vie; //On copie tous les champs
        m_mana = personnageACopier.m_mana;
	delete m_arme;
        m_arme = new Arme(*(personnageACopier.m_arme));
    }
    return *this; //On renvoie l'objet lui-même
}