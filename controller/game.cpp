#include "game.h"

Game::Game() : level(0) {
    window.create(sf::VideoMode({1920, 1080}), "CutiePie", sf::Style::Close | sf::Style::Titlebar);
    state = new MenuState(window);
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

        GameAction action = state->update(e);
        switch (action) {
            case NEW_GAME:
                level = 1;
                this->state = new LevelState(window, level);
                return;
            case LOAD_GAME:
                this->state = new LevelState(window, level);
                return;
            case EXIT_GAME:
                this->quit();
                return;
            default:
                break;
        }
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
