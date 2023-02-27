#pragma once

#include "entity.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

class World {
 public:
  void gameLoop();
  void initWorld();

 private:
  // Load all textures.
  void initGameEntities();

  void processInput();
  void update();
  void render();

  // Main window.
  sf::RenderWindow m_window{};

  // Player entity.
  std::unique_ptr<Player> m_player{nullptr};

  // All entities that can move on the scene.
  std::vector<Entity*> m_movingEntities{};

  bool m_isGameOver{false};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
