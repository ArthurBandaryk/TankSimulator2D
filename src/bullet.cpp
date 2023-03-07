#include "bullet.hpp"
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

Bullet::Bullet(
    const sf::FloatRect& tankGlobalRectangle,
    const int directionAngle) {
  // Grab start position and the size of `Bullet` texture
  // using 'pixspy' program.
  // https://pixspy.com/
  const sf::IntRect bulletRectangle{
      /*left*/ 70,
      /*top*/ 101,
      /*width*/ 4,
      /*height*/ 6,
  };

  setTextureAndSprite(bulletRectangle);
  m_sprite->setScale(3.f, 3.f);
  m_isMovingObject = true;
  m_speed = 300.f;

  float bulletX{}, bulletY{};
  auto bulletWidth = m_sprite->getGlobalBounds().width;
  auto bulletHeight = m_sprite->getGlobalBounds().height;

  switch (directionAngle) {
    case 0:
      bulletX = tankGlobalRectangle.left + tankGlobalRectangle.width / 2
          - bulletWidth / 2;
      bulletY = tankGlobalRectangle.top - bulletHeight;
      m_sprite->setPosition(bulletX, bulletY);
      break;
    case 360:
      bulletX = tankGlobalRectangle.left + tankGlobalRectangle.width / 2
          - bulletWidth / 2;
      bulletY = tankGlobalRectangle.top - bulletHeight;
      m_sprite->setPosition(bulletX, bulletY);
      break;
    case 90:
      m_sprite->setRotation(90);
      bulletWidth = m_sprite->getGlobalBounds().width;
      bulletHeight = m_sprite->getGlobalBounds().height;
      bulletX = tankGlobalRectangle.left + tankGlobalRectangle.width
          + bulletWidth / 2;
      bulletY = tankGlobalRectangle.top + tankGlobalRectangle.height / 2 - bulletHeight / 2;
      m_sprite->setPosition(bulletX, bulletY);
      break;
    case 180:
      m_sprite->setRotation(180);
      bulletWidth = m_sprite->getGlobalBounds().width;
      bulletHeight = m_sprite->getGlobalBounds().height;
      bulletX = tankGlobalRectangle.left + tankGlobalRectangle.width / 2
          + bulletWidth / 2;
      bulletY = tankGlobalRectangle.top + tankGlobalRectangle.height + bulletHeight;
      m_sprite->setPosition(bulletX, bulletY);
      break;
    case 270:
      m_sprite->setRotation(270);
      bulletWidth = m_sprite->getGlobalBounds().width;
      bulletHeight = m_sprite->getGlobalBounds().height;
      bulletX = tankGlobalRectangle.left - bulletWidth;
      bulletY = tankGlobalRectangle.top + tankGlobalRectangle.height / 2 + bulletHeight / 2;
      m_sprite->setPosition(bulletX, bulletY);
      break;
  }

  m_directionAngle = directionAngle;
}

///////////////////////////////////////////////////////////////////////////////

bool Bullet::isVisible() const noexcept {
  return m_isVisible;
}

///////////////////////////////////////////////////////////////////////////////

void Bullet::setDirection(int angle) noexcept {
  m_directionAngle = angle;
}

///////////////////////////////////////////////////////////////////////////////

void Bullet::setStartPosition(
    const sf::Vector2f& startPosition) noexcept {
  m_sprite->setPosition(startPosition);
}

///////////////////////////////////////////////////////////////////////////////

void Bullet::update(float timeElapsed) {
  switch (m_directionAngle) {
    case 0:
      m_sprite->move(0.f, -m_speed * timeElapsed);
      break;
    case 90:
      m_sprite->move(m_speed * timeElapsed, 0.f);
      break;
    case 180:
      m_sprite->move(0.f, m_speed * timeElapsed);
      break;
    case 270:
      m_sprite->move(-m_speed * timeElapsed, 0.f);
      break;
    case 360:
      m_sprite->move(0.f, -m_speed * timeElapsed);
      break;
    default:
      throw std::logic_error{"Incorrect bullet direction"};
  }

  // TODO(artur): make bullet invisible and delete it from vector
  // if it's gone from the screen bounds or any collision happened.
}

//////////////////////////////////////////////////////////////////////////////

void Bullet::render(sf::RenderWindow& window) {
  window.draw(*m_sprite);
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
