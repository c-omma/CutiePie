#include "level_state.h"

LevelState::LevelState(const sf::RenderWindow &window, unsigned int level) : level(window, level) {}

GameAction LevelState::update(sf::Event &e) {
    level.update(e);
    return NONE;
}

void LevelState::draw(sf::RenderWindow &window) {
    level.draw(window);
}
