//
// Created by luise on 23/07/22.
//

#include "Apocalypse.h"

Apocalypse::Apocalypse() {
    this->initVariables();
    this->initWindow();
}

Apocalypse::~Apocalypse() {
    delete this->window;
}

void Apocalypse::initVariables() {
    this->running = true;
}

void Apocalypse::initWindow() {
    this->videoMode.width = 800;
    this->videoMode.height = 600;

    this->window = new sf::RenderWindow(this->videoMode, "MPI-Zombie-Apocalypse",
                                        sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}


void Apocalypse::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                this->running = false;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                    this->running = false;
                }
                break;
            default:
                break;
        }
    }
}

void Apocalypse::update() {
    this->pollEvents();
}

void Apocalypse::render() {
    this->window->clear(sf::Color::White);


    this->window->display();
}

bool Apocalypse::isRunning() const {
    return this->running;
}

