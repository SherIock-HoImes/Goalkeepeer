#include <SFML/Graphics.hpp>
#include <windows.h>

using namespace sf;

int main()
{
	ContextSettings settings;
	settings.antialiasingLevel = 64;

	RenderWindow window(VideoMode(800, 606), "Goalkeepeer", Style::Default, settings);

	Texture football_goal;
	football_goal.loadFromFile("img/football_goal.jpg");
	
	Sprite background;
	background.setTexture(football_goal);

	Texture goalkeepeer;
	goalkeepeer.loadFromFile("img/goalkeepeer.png");

	Sprite character;
	character.setTexture(goalkeepeer);
	character.scale(0.25, 0.25);
	character.setPosition(250, 200);

	Texture ball;
	ball.loadFromFile("img/ball.png");

	Sprite ball2;
	ball2.setTexture(ball);
	ball2.scale(0.1, 0.1);
	ball2.setPosition(0, 650);

	int i = 0;
	int j = 0;

	while (window.isOpen())
	{
		Sleep(10);

		window.draw(background);

		if ((i == 0) && (character.getPosition().x < 500))
			character.move(2.f, 0.f);
		else
			i = 1;
		if ((i == 1) && (character.getPosition().x > 0))
			character.move(-2.f, 0.f);
		else
			i = 0;
		window.draw(character);

		if ((j == 0) && (ball2.getPosition().y > 300))
			ball2.move(12.f, -8.f);
		else
			j = 1;
		if ((j == 1) && (ball2.getPosition().y < 650))
			ball2.move(12.f, 8.f);
		else
			j = 0;
		window.draw(ball2);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.display();
	}
	return 0;
}