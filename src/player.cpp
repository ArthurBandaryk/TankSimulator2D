#include "player.hpp"
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

Player::Player() {
  // Grab start position and the size of `Tank` texture
  // using 'pixspy' program.
  // https://pixspy.com/
  const sf::IntRect tankRectangle{
      /*left*/ 1,
      /*top*/ 48,
      /*width*/ 14,
      /*height*/ 16,
  };

  setTextureAndSprite(tankRectangle);
  m_sprite->setPosition(100.f, 100.f);
  m_sprite->setOrigin(
      m_sprite->getLocalBounds().height / 2,
      m_sprite->getLocalBounds().width / 2);
  m_sprite->setScale(3.f, 3.f);
  m_sprite->setRotation(0);
  m_isMovingObject = true;
  m_speed = 150.f;
  m_bullets.reserve(20);
}

///////////////////////////////////////////////////////////////////////////////

void Player::readPressedKey(const sf::Keyboard::Key code) {
  m_handler.pressKey(code);
}

///////////////////////////////////////////////////////////////////////////////

void Player::readReleasedKey(const sf::Keyboard::Key code) {
  m_handler.releaseKey(code);
}

///////////////////////////////////////////////////////////////////////////////

void Player::update(float timeElapsed) {
  for (const auto& key : m_handler.keys) {
    if (key.isPressed) {
      switch (key.code) {
        case sf::Keyboard::Space:
          fire();
          break;
        case sf::Keyboard::W:
          m_sprite->setRotation(360);
          m_sprite->move(0.f, -m_speed * timeElapsed);
          break;
        case sf::Keyboard::S:
          m_sprite->setRotation(180);
          m_sprite->move(0.f, m_speed * timeElapsed);
          break;
        case sf::Keyboard::A:
          m_sprite->setRotation(270);
          m_sprite->move(-m_speed * timeElapsed, 0.f);
          break;
        case sf::Keyboard::D:
          m_sprite->setRotation(90);
          m_sprite->move(m_speed * timeElapsed, 0.f);
          break;
      }
    }
  }

  std::for_each(
      m_bullets.begin(),
      m_bullets.end(),
      [timeElapsed](Bullet& bullet) {
        if (bullet.isVisible()) {
          bullet.update(timeElapsed);
        }
      });

  // Remove all non relevant bullets.
  m_bullets.erase(
      std::remove_if(
          m_bullets.begin(),
          m_bullets.end(),
          [](const auto& bullet) {
            return !bullet.isVisible();
          }),
      m_bullets.end());
}

///////////////////////////////////////////////////////////////////////////////

void Player::render(sf::RenderWindow& window) {
  window.draw(*m_sprite);

  for (auto& bullet : m_bullets) {
    if (bullet.isVisible()) {
      bullet.render(window);
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

void Player::fire() {
  // Create clock which will measure time elapsed after any shoot.
  // Therefore user should wait in order to make the next shoot.
  static sf::Clock fireClock;
  static float timeElapsedAfterShoot = m_chargeTime * 2;

  timeElapsedAfterShoot += fireClock.restart().asSeconds();

  // Oops, too early to make shoot.
  if (timeElapsedAfterShoot < m_chargeTime)
    return;
  timeElapsedAfterShoot = 0.f;
  m_bullets.push_back(Bullet{
      m_sprite->getGlobalBounds(),
      static_cast<int>(m_sprite->getRotation())});
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci
