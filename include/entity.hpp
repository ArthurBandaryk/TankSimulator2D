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
  virtual ~Entity() = default;
  virtual void update() = 0;
  void setTextureAndSprite(const sf::IntRect& rect,
                           /*texture is repeated*/ bool repeated = false);
  void setScale(const sf::Vector2f& scale);
  sf::Sprite& getSprite();

 protected:
  inline static const std::string ms_texturePath{"resources/components.png"};

  std::unique_ptr<sf::Texture> m_texture{nullptr};
  std::unique_ptr<sf::Sprite> m_sprite{nullptr};

  bool m_isMovingObject{false};
};

///////////////////////////////////////////////////////////////////////////////

class Player final : public Entity {
 public:
  Player();
  void update() override;

 private:
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
