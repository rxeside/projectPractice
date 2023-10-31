#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Yellow Arrow");

    sf::ConvexShape arrow;
    arrow.setPointCount(7);
    arrow.setPoint(0, sf::Vector2f(-50, 0));
    arrow.setPoint(1, sf::Vector2f(50, -75));
    arrow.setPoint(2, sf::Vector2f(50, -25));
    arrow.setPoint(3, sf::Vector2f(150, -25));
    arrow.setPoint(4, sf::Vector2f(150, 25));
    arrow.setPoint(5, sf::Vector2f(50, 25));
    arrow.setPoint(6, sf::Vector2f(50, 75));

    arrow.setFillColor(sf::Color::Yellow);
    arrow.setOutlineColor(sf::Color::Black);
    arrow.setOutlineThickness(5);

    // Получаем размеры окна
    sf::Vector2u windowSize = window.getSize();

    // Размещаем стрелку по центру окна
    arrow.setPosition(windowSize.x / 2.f, windowSize.y / 2.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
        sf::Vector2f arrowPosition = arrow.getPosition();

        sf::Vector2f direction = sf::Vector2f(mousePosition.x, mousePosition.y) - arrowPosition;

        float angle = std::atan2(direction.y, direction.x);
        float distance = std::min(400.f, std::max(0.f, std::sqrt(direction.x * direction.x + direction.y * direction.y)));
        

        arrowPosition += sf::Vector2f(std::cos(angle) * distance, std::sin(angle) * distance);
        arrow.setPosition(arrowPosition);
        
        window.clear(sf::Color::White);
        window.draw(arrow);
        window.display();
    }

    return 0;
}