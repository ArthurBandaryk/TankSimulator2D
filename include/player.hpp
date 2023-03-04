#pragma once

#include "bullet.hpp"
#include "entity.hpp"
#include <vector>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

enum class Command {
  MoveUp,
  MoveDown,
  MoveLeft,
  MoveRight,
  Fire,
  DoNothing,
};

///////////////////////////////////////////////////////////////////////////////

class Player final : public Entity {
 public:
  Player();
  void update(float timeElapsed) override;
  void render(sf::RenderWindow& window) override;
  void handleInput(Command command) noexcept;
  void move(float timeElapsed);
  void fire();
  void renderBullet();

 private:
  std::vector<Bullet> m_bullets{};
  Command m_command{Command::DoNothing};
  float chargeTime{0.5f};
  float m_timeElapsedAfterShoot{2.f};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci
