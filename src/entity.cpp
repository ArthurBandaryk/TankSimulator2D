#include "entity.hpp"
#include <cassert>
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

Entity::Entity()
  : m_texture{std::make_unique<sf::Texture>()},
    m_sprite{std::make_unique<sf::Sprite>()} {
}

///////////////////////////////////////////////////////////////////////////////

void Entity::setTextureAndSprite(const sf::IntRect& rect, bool repeated) {
  if (!m_texture->loadFromFile(ms_texturePath, rect)) {
    throw std::runtime_error{
        "Error on loading texture for the path: " + ms_texturePath};
  }

  m_texture->setSmooth(true);
  if (repeated) {
    m_texture->setRepeated(true);
  }
  m_sprite->setTexture(*m_texture.get());
}

///////////////////////////////////////////////////////////////////////////////

sf::Sprite& Entity::getSprite() {
  if (!m_sprite) {
    throw std::logic_error{"Invalid state for sprite"};
  }
  return *m_sprite.get();
}

///////////////////////////////////////////////////////////////////////////////

Player::Player() {
  // Grab player's tank rectangle from the whole texture set.
  const sf::IntRect tankRectangle{
      /*left*/ 1,
      /*top*/ 48,
      /*width*/ 14,
      /*height*/ 16,
  };

  setTextureAndSprite(tankRectangle);
  m_sprite->setScale(ms_scale);
  m_sprite->setPosition(100.f, 100.f);
  m_sprite->rotate(90.f);
  m_isMovingObject = true;
}

///////////////////////////////////////////////////////////////////////////////

void Player::update() {
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
