#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

using namespace std;

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mousePosition)
{
    mousePosition = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, mousePosition);
            break;
        default:
            break;
        }
    }
}

void setPlayerScale(sf::Sprite &player, float widthMultiplier, float heightMultiplier)
{
    sf::Vector2f targetSize(sf::VideoMode::getDesktopMode().height / 16, sf::VideoMode::getDesktopMode().height / 16);
    player.setScale(
        targetSize.x / player.getLocalBounds().width * widthMultiplier,
        targetSize.y / player.getLocalBounds().height * heightMultiplier);
}

void updatePosition(const sf::Vector2f &mousePosition, sf::Sprite &player, float dt)
{
    const sf::Vector2f delta = mousePosition - player.getPosition();

    const float deltaLength = std::sqrt(delta.x * delta.x + delta.y * delta.y);
    if (deltaLength != 0)
    {
        const sf::Vector2f direction = {delta.x / deltaLength, delta.y / deltaLength};
        const float speed = 20.0f;
        player.move(direction * speed * dt);
    }
    if (delta.x >= 0)
    {
        setPlayerScale(player, 1, 1);
    }
    else
    {
        setPlayerScale(player, -1, 1);
    }
}

void update(const sf::Vector2f &mousePosition, sf::Sprite &player, sf::Clock &clock, sf::Sprite &pointer)
{
    const float dt = clock.restart().asSeconds();
    pointer.setPosition(mousePosition);
    updatePosition(mousePosition, player, dt);
}

void redrawFrame(sf::RenderWindow &window, sf::Sprite &player, sf::Sprite &pointer)
{
    window.clear(sf::Color::White);
    window.draw(player);
    window.draw(pointer);
    window.display();
}

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode::getDesktopMode(),
        "cat ^^", sf::Style::Fullscreen, settings);

    sf::Vector2f mousePosition;
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("cat1.png"))
    {
        wcerr << L"Ошибочька загрузки картиночьки" << endl;
        exit(1);
    }

    sf::Texture pointerTexture;
    if (!pointerTexture.loadFromFile("red_pointer.png"))
    {
        wcerr << L"Ошибка загрузки спрайта указки" << endl;
        exit(1);
    }

    sf::Sprite pointer(pointerTexture);
    pointer.setOrigin(pointer.getLocalBounds().width / 2, pointer.getLocalBounds().height / 2);
    setPlayerScale(pointer, 1, 1);

    sf::Sprite player(playerTexture);
    player.setOrigin(player.getLocalBounds().width / 2, player.getLocalBounds().height / 2);
    setPlayerScale(player, 1, 1);

    player.setPosition(
        sf::VideoMode::getDesktopMode().width / 2,
        sf::VideoMode::getDesktopMode().height / 2);

    sf::Clock clock;

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, player, clock, pointer);
        redrawFrame(window, player, pointer);
    }
}