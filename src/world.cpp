#include "world.hpp"
#include "entity.hpp"

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

  // Init game entities.
  initGameEntities();
}

///////////////////////////////////////////////////////////////////////////////

void World::initGameEntities() {
  initPlayer();
  initWalls();
}

///////////////////////////////////////////////////////////////////////////////

void World::initPlayer() {
  m_player = std::make_unique<Player>();
}

///////////////////////////////////////////////////////////////////////////////

void World::initWalls() {
  const auto windowSize = m_window.getSize();

  // Grab start position and the size of `Wall` texture
  // using 'pixspy' program.
  // https://pixspy.com/
  const int startWallTextureX{112};
  const int startWallTextureY{128};
  const int wallTextureWidth{16};
  const int wallTextureHeight{16};

  // Set scale for walls.
  Wall::ms_scale.x = 2.f;
  Wall::ms_scale.y = 2.f;

  const sf::IntRect wallTexture{
      /*left*/ startWallTextureX,
      /*top*/ startWallTextureY,
      /*width*/ wallTextureWidth,
      /*height*/ wallTextureHeight,
  };

  // Huge rectangle of repeated `Wall` textures for bottom and top walls.
  const sf::IntRect rectOfRepeatedTextureWidth{
      /*left*/ 0,
      /*top*/ 0,
      /*width*/ static_cast<int>(windowSize.x),
      /*height*/ wallTextureHeight,
  };

  // Huge rectangle of repeated `Wall` textures for left and right walls.
  // Scale factor (Wall::ms_scale) should not be ignored.
  const sf::IntRect rectOfRepeatedTextureHeight{
      /*left*/ 0,
      /*top*/ 0,
      /*width*/ static_cast<int>(wallTextureWidth),
      /* clang-format off */
      /*height*/ static_cast<int>(
                  (windowSize.y - 2 * Wall::ms_scale.y * wallTextureHeight) 
                  / Wall::ms_scale.y
                ),
      /* clang-format on */
  };

  // Calculate screen position of all walls.
  // Scale factor (Wall::ms_scale) should not be ignored too.
  const sf::Vector2f leftWallPosition{
      0.f,
      wallTextureHeight * Wall::ms_scale.y};
  const sf::Vector2f topWallPosition{0.f, 0.f};
  const sf::Vector2f rightWallPosition{
      windowSize.x - wallTextureWidth * Wall::ms_scale.x,
      wallTextureHeight * Wall::ms_scale.y};
  const sf::Vector2f bottomWallPosition{
      0.f,
      windowSize.y - wallTextureHeight * Wall::ms_scale.y};

  // Add all walls to the vector of all entities.
  m_entities.emplace_back(std::make_unique<Wall>(
      wallTexture,
      rectOfRepeatedTextureWidth,
      topWallPosition));

  m_entities.emplace_back(std::make_unique<Wall>(
      wallTexture,
      rectOfRepeatedTextureHeight,
      leftWallPosition));

  m_entities.emplace_back(std::make_unique<Wall>(
      wallTexture,
      rectOfRepeatedTextureWidth,
      bottomWallPosition));

  m_entities.emplace_back(std::make_unique<Wall>(
      wallTexture,
      rectOfRepeatedTextureHeight,
      rightWallPosition));
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
    m_window.draw(m_player->getSprite());
    for (const auto& entity : m_entities) {
      m_window.draw(entity->getSprite());
    }
    m_window.display();
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
