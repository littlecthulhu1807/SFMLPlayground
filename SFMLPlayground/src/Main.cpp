#include<iostream>

#include<SFML/Graphics.hpp>

int main() {
	unsigned int width{ 1280 };
	unsigned int height{ 720 };

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ width, height }), "Tutorials");
	window->setFramerateLimit(60);

	while (window->isOpen()) {
		while (const std::optional event = window->pollEvent()) {
			if (event->is<sf::Event::Closed>()) {
				window->close();
			}
			else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
				if (keyPressed->scancode == sf::Keyboard::Scancode::Escape) {
					window->close();
				}
			}
		}


		//Render
		window->clear();

		//Drawing

		window->display();
	}

	delete window;

	return 0;
}