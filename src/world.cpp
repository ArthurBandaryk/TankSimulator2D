#include "world.hpp"

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

void World::initWorld() {
  // Init window.
  m_window.create(sf::VideoMode{800, 800}, "Tank2D", sf::Style::Close);
  const auto desktop = sf::VideoMode::getDesktopMode();
  m_window.setPosition(sf::Vector2i{
      static_cast<int>(desktop.width / 2 - m_window.getSize().x / 2),
      static_cast<int>(desktop.height / 2 - m_window.getSize().y / 2)});
  m_window.setVerticalSyncEnabled(true);
}

///////////////////////////////////////////////////////////////////////////////

void World::gameLoop() {
  while (!m_isGameOver) {
    processInput();
    update();
    render();
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::processInput() {
  sf::Event event{};
  while (m_window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      m_window.close();
      m_isGameOver = true;
      break;
    }
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::update() {
  if (!m_isGameOver) { /*For now do nothing.*/
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::render() {
  if (!m_isGameOver) {
    m_window.clear();
    m_window.display();
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
