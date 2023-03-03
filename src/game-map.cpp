#include "game-map.hpp"

//////////////////////////////////////////////////////////////////////////////

namespace arci {

//////////////////////////////////////////////////////////////////////////////

MapEntity::MapEntity(
    const sf::IntRect& subRectOfTexture,
    const sf::IntRect& rectOfRepeatedTexture,
    const sf::Vector2f& screenPosition) {
  setTextureAndSprite(subRectOfTexture, /*texture is repeated*/ true);
  m_sprite->setTextureRect(rectOfRepeatedTexture);
  m_sprite->setPosition(screenPosition);
}

//////////////////////////////////////////////////////////////////////////////

void MapEntity::update(float timeElapsed) {
  /* It's a map entity, do nothing for now */
}

//////////////////////////////////////////////////////////////////////////////

} // namespace arci

//////////////////////////////////////////////////////////////////////////////
