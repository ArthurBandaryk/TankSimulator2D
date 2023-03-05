#pragma once

#include "entity.hpp"

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

class Bullet final : public Entity {
 public:
  Bullet(
      const sf::FloatRect& tankGlobalRectangle,
      const int directionAngle);
  void update(float timeElapsed) override;
  void render(sf::RenderWindow& window) override;
  void setDirection(int angle) noexcept;
  void setStartPosition(const sf::Vector2f& startPosition) noexcept;
  bool isVisible() const noexcept;

 private:
  int m_directionAngle{};
  bool m_isVisible{true};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
