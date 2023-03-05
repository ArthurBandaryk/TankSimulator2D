#pragma once

#include "bullet.hpp"
#include "entity.hpp"
#include "input-handler.hpp"
#include <vector>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

class Player final : public Entity {
 public:
  Player();
  void update(float timeElapsed) override;
  void render(sf::RenderWindow& window) override;
  void readPressedKey(const sf::Keyboard::Key code);
  void readReleasedKey(const sf::Keyboard::Key code);
  void fire();

 private:
  std::vector<Bullet> m_bullets{};
  KeysHandler m_handler{};
  float chargeTime{0.5f};
  float m_timeElapsedAfterShoot{2.f};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci
