#include "entity.hpp"
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

sf::Sprite& Entity::getSprite() {
  if (!m_sprite) {
    throw std::logic_error{"Invalid state for sprite"};
  }
  return *m_sprite.get();
}

///////////////////////////////////////////////////////////////////////////////

Player::Player() {
  m_texture = std::make_unique<sf::Texture>();

  // Grab player's tank rectangle from the whole texture set.
  const sf::IntRect tankRectangle{
      /*leftRect*/ 0,
      /*leftRect*/ 47,
      /*width*/ 15,
      /*height*/ 17,
  };

  const std::string texture_path = "resources/components.png";

  if (!m_texture->loadFromFile(texture_path, tankRectangle)) {
    throw std::runtime_error{
        "Error on loading texture for the path: " + texture_path};
  }

  m_texture->setSmooth(true);

  m_sprite = std::make_unique<sf::Sprite>();
  m_sprite->setTexture(*m_texture.get());
  m_sprite->setScale(3.f, 3.f);
  m_sprite->setPosition(100.f, 100.f);
  m_sprite->rotate(90.f);
}

///////////////////////////////////////////////////////////////////////////////

void Player::update() {
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
