#include "game.h"

Game::Game() : state(new MenuState()), level(0) {
    window.create(sf::VideoMode({1920, 1080}), "CutiePie", sf::Style::Close | sf::Style::Titlebar);
}

Game::~Game() {
    delete state;
}

bool Game::isRunning() const {
    return !exit;
}

void Game::update() {
    sf::Event e;
    while (window.pollEvent(e)) {
        if (e.type == sf::Event::Closed) {
            this->quit();
            return;
        }

        state->update(e);
    }
}

void Game::draw() {
    window.clear();
    state->draw(this->window);
    window.display();
}

void Game::quit() {
    exit = true;
    this->window.close();
}
