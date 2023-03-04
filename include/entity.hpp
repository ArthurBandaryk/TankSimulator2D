#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

class Entity {
 public:
  Entity();
  Entity(Entity&&) = default;
  virtual ~Entity() = default;
  virtual void update(float timeElapsed) = 0;
  virtual void render(sf::RenderWindow& window) = 0;
  void setTextureAndSprite(const sf::IntRect& rect,
                           /*texture is repeated*/ bool repeated = false);
  void setScale(const sf::Vector2f& scale);

 protected:
  inline static const std::string ms_texturePath{"/home/arc1/LestaGamesTask/TankSimulator2D/resources/components.png"};
  std::unique_ptr<sf::Texture> m_texture{nullptr};
  std::unique_ptr<sf::Sprite> m_sprite{nullptr};
  float m_speed{0.f};
  bool m_isMovingObject{false};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
