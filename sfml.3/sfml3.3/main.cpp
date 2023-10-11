#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Eye Tracking");
    window.setFramerateLimit(60);
    window.clear(sf::Color::Black);

    sf::CircleShape leftEye(60, 40);
    leftEye.setFillColor(sf::Color::White);
    leftEye.setOutlineThickness(5);
    leftEye.setOutlineColor(sf::Color::Black);
    leftEye.setPosition(300, 250);

    sf::CircleShape rightEye(60, 40);
    rightEye.setFillColor(sf::Color::White);
    rightEye.setOutlineThickness(5);
    rightEye.setOutlineColor(sf::Color::Black);
    rightEye.setPosition(500, 250);

    sf::CircleShape leftPupil(30);
    leftPupil.setFillColor(sf::Color::Black);
    leftPupil.setOrigin(-30, -30);

    sf::CircleShape rightPupil(30);
    rightPupil.setFillColor(sf::Color::Black);
    rightPupil.setOrigin(-30, -30);

    sf::Vector2f pupilMouseDiff(60.f, 60.f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sf::Vector2f leftEyePosition = leftEye.getPosition();
        sf::Vector2f leftPupilPosition = leftEyePosition;

        sf::Vector2f rightEyePosition = rightEye.getPosition();
        sf::Vector2f rightPupilPosition = rightEyePosition;

        sf::Vector2f leftDirection = sf::Vector2f(mousePosition.x, mousePosition.y) - leftEyePosition - pupilMouseDiff;
        float leftAngle = std::atan2(leftDirection.y, leftDirection.x);
        float leftDistance = std::min(30.f, std::max(0.f, std::sqrt(leftDirection.x * leftDirection.x + leftDirection.y * leftDirection.y)));

        sf::Vector2f rightDirection = sf::Vector2f(mousePosition.x, mousePosition.y) - rightEyePosition - pupilMouseDiff;
        float rightAngle = std::atan2(rightDirection.y, rightDirection.x);
        float rightDistance = std::min(30.f, std::max(0.f, std::sqrt(rightDirection.x * rightDirection.x + rightDirection.y * rightDirection.y)));

        leftPupilPosition += sf::Vector2f(std::cos(leftAngle) * leftDistance, std::sin(leftAngle) * leftDistance);
        rightPupilPosition += sf::Vector2f(std::cos(rightAngle) * rightDistance, std::sin(rightAngle) * rightDistance);

        leftPupil.setPosition(leftPupilPosition);
        rightPupil.setPosition(rightPupilPosition);

        window.clear(sf::Color::Black);
        window.draw(leftEye);
        window.draw(rightEye);
        window.draw(leftPupil);
        window.draw(rightPupil);
        window.display();
    }

    return 0;
}
