#include "player.hpp"

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
  m_speed = 100.f;
}

///////////////////////////////////////////////////////////////////////////////

void Player::handleInput(Command command) {
  m_command = command;
}

///////////////////////////////////////////////////////////////////////////////

void Player::update(float timeElapsed) {
  if (m_command != Command::DoNothing) {
    switch (m_command) {
      case Command::MoveUp:
        move(timeElapsed);
        break;
      case Command::MoveDown:
        move(timeElapsed);
        break;
      case Command::MoveLeft:
        move(timeElapsed);
        break;
      case Command::MoveRight:
        move(timeElapsed);
        break;
      case Command::Fire:
        fire();
        break;
      default:
        throw std::logic_error{"Unknown command for player"};
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

void Player::move(float timeElapsed) {
  switch (m_command) {
    case Command::MoveDown:
      m_sprite->setRotation(180);
      m_sprite->move(0.f, m_speed * timeElapsed);
      break;
    case Command::MoveUp:
      m_sprite->setRotation(360);
      m_sprite->move(0.f, -m_speed * timeElapsed);
      break;
    case Command::MoveLeft:
      m_sprite->setRotation(270);
      m_sprite->move(-m_speed * timeElapsed, 0.f);
      break;
    case Command::MoveRight:
      m_sprite->setRotation(90);
      m_sprite->move(m_speed * timeElapsed, 0.f);
      break;
    default:
      throw std::logic_error{"Incorrect move command"};
  }

  m_command = Command::DoNothing;
}

///////////////////////////////////////////////////////////////////////////////

void Player::fire() {}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci
