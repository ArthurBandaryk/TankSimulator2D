#include "game.hpp"

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

Game::Game() {
  world.initWorld();
}

///////////////////////////////////////////////////////////////////////////////

void Game::run() {
  world.gameLoop();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
