#include "De.hpp"

De::De() {
  m_randomEngine = std::mt19937(m_randomDevice());
  m_distribution = std::uniform_int_distribution<>(1, 6);
}

De::~De() {}

unsigned int De::brasser() { return m_distribution(m_randomEngine); }