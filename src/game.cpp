#include "game.hpp"

#include <iostream>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

Game::Game() {
  InitGame();
  Run();
}

///////////////////////////////////////////////////////////////////////////////

void Game::InitGame() {
  // Init window.
  m_window.create(sf::VideoMode{800, 800}, "Tank2D", sf::Style::Close);
  const auto desktop = sf::VideoMode::getDesktopMode();
  m_window.setPosition(sf::Vector2i{
      static_cast<int>(desktop.width / 2 - m_window.getSize().x / 2),
      static_cast<int>(desktop.height / 2 - m_window.getSize().y / 2)});
  m_window.setVerticalSyncEnabled(true);
}

///////////////////////////////////////////////////////////////////////////////

void Game::Run() {
  while (m_window.isOpen()) {
    sf::Event event;
    while (m_window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        m_window.close();
    }

    m_window.clear();
    m_window.display();
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
