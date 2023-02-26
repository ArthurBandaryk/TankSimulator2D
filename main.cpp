#include <SFML/Graphics.hpp>
#include <iostream>

int main(int /*argc*/, char** /*argv*/) {
  constexpr unsigned int kScreenWidth{800}, kScreenHeight{800};
  sf::RenderWindow window(
      sf::VideoMode(kScreenWidth, kScreenHeight),
      "Tank2D");

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(shape);
    window.display();
  }
  return 0;
}
