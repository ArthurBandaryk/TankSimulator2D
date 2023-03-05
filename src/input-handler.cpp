#include "input-handler.hpp"
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////

namespace arci {

///////////////////////////////////////////////////////////////////////////////

KeysHandler::KeysHandler() {
  keys[0] = Key{sf::Keyboard::W, "Up key"};
  keys[1] = Key{sf::Keyboard::A, "Left key"};
  keys[2] = Key{sf::Keyboard::S, "Down key"};
  keys[3] = Key{sf::Keyboard::D, "Right key"};
  keys[4] = Key{sf::Keyboard::Space, "Space key"};
}

///////////////////////////////////////////////////////////////////////////////

std::optional<std::size_t> KeysHandler::getIndexForKey(
    const sf::Keyboard::Key code) {
  const auto keyIter = std::find_if(
      keys.begin(),
      keys.end(),
      [code](const Key& key) {
        return key.code == code;
      });

  if (keyIter == keys.end()) {
    return {};
  }

  return std::distance(keys.begin(), keyIter);
}

///////////////////////////////////////////////////////////////////////////////

void KeysHandler::pressKey(const sf::Keyboard::Key code) {
  const std::optional<std::size_t> indexNeeded = getIndexForKey(code);
  if (indexNeeded) {
    keys[*indexNeeded].isPressed = true;
    keys[*indexNeeded].isReleased = false;
  }
}

///////////////////////////////////////////////////////////////////////////////

void KeysHandler::releaseKey(const sf::Keyboard::Key code) {
  const std::optional<std::size_t> indexNeeded = getIndexForKey(code);
  if (indexNeeded) {
    keys[*indexNeeded].isPressed = false;
    keys[*indexNeeded].isReleased = true;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace arci

///////////////////////////////////////////////////////////////////////////////
