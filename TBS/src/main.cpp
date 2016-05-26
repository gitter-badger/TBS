#include <SFML/Window.hpp>

#include "game.hpp"
#include "header.hpp"
#include "input.hpp"

int main()
{
	// Create a window
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8; // Enable anti-aliasing
	sf::RenderWindow window(sf::VideoMode(800, 600), GAME_NAME, 7U, settings);

	// Create an instance of a game
	IGame game(window);
	game.Initialize();

	// Clock used to get the delta-time
	sf::Clock clock;

	// Start the gameloop
	while (window.isOpen())
	{
		// Get delta-time in seconds
		const float deltaSeconds = clock.restart().asSeconds();

		// Poll triggered events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Switch event type
			switch (event.type)
			{
			case sf::Event::Closed:
				// Close the window properly
				window.close();
				break;

			case sf::Event::KeyPressed:
				// Trigger actions bound to the current key code
				InputListener::ActionPress(event.key.code);
				break;

			case sf::Event::KeyReleased:
				InputListener::ActionRelease(event.key.code);
				break;

			case sf::Event::MouseMoved:
				game.MouseMove(event.mouseMove.x, event.mouseMove.y);
				break;

			case sf::Event::MouseButtonPressed:
				game.MouseDown(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;

			case sf::Event::MouseButtonReleased:
				game.MouseUp(event.mouseButton.button, event.mouseButton.x, event.mouseButton.y);
				break;

			case sf::Event::MouseWheelMoved:
				game.MouseWheelScrolled(event.mouseWheel.delta);
				break;
			}// switch event.type
		} // while window.pollEvent

		// Rotate the shape
		game.Tick(deltaSeconds);

		// Redraw the screen
		window.clear();
		game.Render();
		window.display();
	}

	// Close the console
	return EXIT_SUCCESS;
} // int main
