#include "world.hpp"
#include "entity.hpp"
#include "player.hpp"

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
  initBackground();
  initWalls();
  initPlayer();
}

///////////////////////////////////////////////////////////////////////////////

void World::initPlayer() {
  m_player = std::make_unique<Player>();
  m_player->setScale(sf::Vector2f{3.f, 3.f});
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
                (windowSize.y - 2 * ms_scale.y * wallTextureHeight + 2)
                  / ms_scale.y
                ),
      /* clang-format on */
  };

  // Calculate screen position of all walls.
  // Scale factor (Wall::ms_scale) should not be ignored too.
  const sf::Vector2f leftWallPosition{
      0.f,
      wallTextureHeight * ms_scale.y};
  const sf::Vector2f topWallPosition{0.f, 0.f};
  const sf::Vector2f rightWallPosition{
      windowSize.x - wallTextureWidth * ms_scale.x,
      wallTextureHeight * ms_scale.y};
  const sf::Vector2f bottomWallPosition{
      0.f,
      windowSize.y - wallTextureHeight * ms_scale.y};

  auto leftWall = std::make_unique<MapEntity>(
      wallTexture,
      rectOfRepeatedTextureHeight,
      leftWallPosition);

  auto rightWall = std::make_unique<MapEntity>(
      wallTexture,
      rectOfRepeatedTextureHeight,
      rightWallPosition);

  auto topWall = std::make_unique<MapEntity>(
      wallTexture,
      rectOfRepeatedTextureWidth,
      topWallPosition);

  auto bottomWall = std::make_unique<MapEntity>(
      wallTexture,
      rectOfRepeatedTextureWidth,
      bottomWallPosition);

  leftWall->setScale(ms_scale);
  topWall->setScale(ms_scale);
  bottomWall->setScale(ms_scale);
  rightWall->setScale(ms_scale);

  // Add all walls to the vector of all entities.
  m_entities.push_back(std::move(topWall));
  m_entities.push_back(std::move(leftWall));
  m_entities.push_back(std::move(bottomWall));
  m_entities.push_back(std::move(rightWall));
}

///////////////////////////////////////////////////////////////////////////////

void World::initBackground() {
  // Grab start position and the size of `Tank` texture
  // using 'pixspy' program.
  // https://pixspy.com/
  const sf::IntRect backgroundRectangleTexture{
      /*left*/ 144,
      /*top*/ 48,
      /*width*/ 16,
      /*height*/ 16,
  };

  const auto windowSize = m_window.getSize();

  // Huge rectangle of repeated `background` textures.
  const sf::IntRect rectOfRepeatedBackgroundTextures{
      /*left*/ 0,
      /*top*/ 0,
      /*width*/ static_cast<int>(windowSize.x),
      /*height*/ static_cast<int>(windowSize.y),
  };

  auto backGround = std::make_unique<MapEntity>(
      backgroundRectangleTexture,
      rectOfRepeatedBackgroundTextures,
      sf::Vector2f{0.f, 0.f});

  backGround->setScale(sf::Vector2f{4.f, 4.f});

  m_entities.push_back(std::move(backGround));
}

///////////////////////////////////////////////////////////////////////////////

void World::gameLoop() {
  static sf::Clock clock{};
  while (!m_isGameOver) {
    processInput();
    update(clock.restart().asSeconds());
    render();
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::processInput() {
  sf::Event event{};
  while (m_window.pollEvent(event)) {
    switch (event.type) {
      case sf::Event::Closed:
        m_window.close();
        m_isGameOver = true;
        break;

      case sf::Event::KeyReleased:
        m_player->readReleasedKey(event.key.code);
        break;
    }
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
    m_window.close();
    m_isGameOver = true;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
    m_player->readPressedKey(sf::Keyboard::Space);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    m_player->readPressedKey(sf::Keyboard::W);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
    m_player->readPressedKey(sf::Keyboard::A);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    m_player->readPressedKey(sf::Keyboard::S);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
    m_player->readPressedKey(sf::Keyboard::D);
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::update(float timeElapsed) {
  if (!m_isGameOver) {
    m_player->update(timeElapsed);
  }
}

///////////////////////////////////////////////////////////////////////////////

void World::render() {
  if (!m_isGameOver) {
    m_window.clear();
    for (const auto& entity : m_entities) {
      entity->render(m_window);
    }
    m_player->render(m_window);
    m_window.display();
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
