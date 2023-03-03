#pragma once

#include "entity.hpp"
#include "game-map.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

class World final {
 public:
  void gameLoop();
  void initWorld();

 private:
  // Load all textures.
  void initGameEntities();
  void initBackground();
  void initPlayer();
  void initWalls();

  void processInput();
  void update(float timeElapsed);
  void render();

  inline static sf::Vector2f ms_scale{2.f, 2.f};

  // Main window.
  sf::RenderWindow m_window{};

  // Player entity.
  std::unique_ptr<Player> m_player{nullptr};

  // All entities (except player) on the scene.
  std::vector<std::unique_ptr<Entity>> m_entities{};

  bool m_isGameOver{false};
};

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
