#pragma once
#include <SFML/Graphics.hpp>

#include <cmath>
#include <string>

#include "Case.hpp"

#define LONGEUR_SERPENT 1513.f
#define LARGEUR_SERPENT 208.f

#define LONGEUR_ECHELLE 418.f
#define LARGEUR_ECHELLE 134.f

class Chemin {
public:
  enum class Type { serpent, echelle };

  Chemin();
  Chemin(unsigned int caseHaut, unsigned int caseBas, Type type);
  ~Chemin();

  void determinerSuivant(Chemin *suivant);

  Chemin *obtenirSuivant() const;

  unsigned int obtenirCaseHaut() const;
  unsigned int obtenirCaseBas() const;

  Type obtenirType() const;

  void afficher(sf::RenderWindow *window);
  void placerSurCases();

  void calculerOrigine(sf::Vector2f &origine);
  void calculerPosition(sf::Vector2f &positionHaut, sf::Vector2f &positionBas);
  float calculerRotation(const sf::Vector2f &positionHaut,
                         const sf::Vector2f &positionBas, float &c);
  sf::Vector2f calculerScale(const float &c, const float &rotation);

private:
  unsigned int m_caseHaut;
  unsigned int m_caseBas;

  sf::Texture m_texture;
  sf::Sprite m_sprite;

  sf::Vector2f m_offset;

  Type m_type;

  Chemin *m_suivant;

  void chargerSprite();
};
