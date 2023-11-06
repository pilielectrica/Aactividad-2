#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
///Punto de entrada a la aplicación///
using namespace std;
Sprite puntorojo1;
Sprite puntorojo2;
Sprite puntorojo3;
Sprite puntorojo4;
Sprite cursor;

Texture TextureCursor;
Texture texture;
int main() {
	Event evt;

	texture.loadFromFile("rcircle.png");
	TextureCursor.loadFromFile("cursor.png");

	puntorojo1.setTexture(texture);
	puntorojo2.setTexture(texture);
	puntorojo3.setTexture(texture);
	puntorojo4.setTexture(texture);
	cursor.setTexture(TextureCursor);

	cursor.setPosition(0, 0);
	puntorojo2.setPosition(675, 0);
	puntorojo3.setPosition(675, 480);
	puntorojo4.setPosition(0, 480);	
	cursor.setScale(0.1f, 0.1f);


	bool colision = false;
	bool colision1 = false;
	bool colision2 = false;
	bool colision3 = false;

	sf::RenderWindow App(sf::VideoMode(800, 600, 32),
		"Que ventana horrible");
	App.setMouseCursorVisible(false);

	// Loop principal
	while (App.isOpen()) {
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type) {
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;
			case sf::Event::MouseMoved:
				/////Actualizamos la posición del sprite con/////
				/////la informacion del evento del mouse/////
				cursor.setPosition(evt.mouseMove.x, evt.mouseMove.y);

			}
			Vector2i cursorPosition = Mouse::getPosition(App);		


			if (puntorojo1.getGlobalBounds().contains(cursorPosition.x, cursorPosition.y))
			{
				if (evt.type == Event::MouseButtonPressed)
				{
					colision = true;
				}
			}

			if (colision)
			{
				if (evt.type == Event::MouseMoved) 
				{
					puntorojo1.setPosition(evt.mouseMove.x - 40, evt.mouseMove.y - 40);
				}
			}

			if (evt.type == Event::MouseButtonReleased) 
			{
				colision = false;
			}
			//punto rojo 2
			if (puntorojo2.getGlobalBounds().contains(cursorPosition.x, cursorPosition.y))
			{
				if (evt.type == Event::MouseButtonPressed)
				{
					colision1 = true;
				}
			}

			if (colision1)
			{
				if (evt.type == Event::MouseMoved)
				{
					puntorojo2.setPosition(evt.mouseMove.x - 40, evt.mouseMove.y - 40);
				}
			}

			if (evt.type == Event::MouseButtonReleased)
			{
				colision1 = false;
			}
			//punto rojo 3
			if (puntorojo3.getGlobalBounds().contains(cursorPosition.x, cursorPosition.y))
			{
				if (evt.type == Event::MouseButtonPressed)
				{
					colision2 = true;
				}
			}

			if (colision2)
			{
				if (evt.type == Event::MouseMoved)
				{
					puntorojo3.setPosition(evt.mouseMove.x - 40, evt.mouseMove.y - 40);
				}
			}

			if (evt.type == Event::MouseButtonReleased)
			{
				colision2 = false;
			}
			//punto rojo 4
			if (puntorojo4.getGlobalBounds().contains(cursorPosition.x, cursorPosition.y))
			{
				if (evt.type == Event::MouseButtonPressed)
				{
					colision3 = true;
				}
			}

			if (colision3)
			{
				if (evt.type == Event::MouseMoved)
				{
					puntorojo4.setPosition(evt.mouseMove.x - 40, evt.mouseMove.y - 40);
				}
			}

			if (evt.type == Event::MouseButtonReleased)
			{
				colision3 = false;
			}

		}
		// Limpiamos la ventana
		App.clear();
		// Dibujamos la escena

		App.draw(puntorojo1);
		App.draw(puntorojo2);
		App.draw(puntorojo3);
		App.draw(puntorojo4);
		App.draw(cursor);
		// Mostramos la ventana
		App.display();
	}

	return 0;
}
