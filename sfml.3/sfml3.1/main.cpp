#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <algorithm>

void init(sf::ConvexShape& pointer) {
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians) {
    return float(double(radians) * 180 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = sf::Vector2f(float(event.x), float(event.y));
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition) {
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
                onMouseMove(event.mouseMove, mousePosition);
                break;
            default:
                break;
        }
    }
}

void update(const sf::Vector2f& mousePosition, sf::ConvexShape& pointer, sf::Clock& clock) {
    sf::Vector2f delta = mousePosition - pointer.getPosition();
    float angle = std::atan2(delta.y, delta.x);
    float targetRotation = toDegrees(angle);
    
    float currentRotation = pointer.getRotation();
    float maxRotationSpeed = 15.0f;
    float elapsedSeconds = clock.restart().asSeconds();
    float rotationDiff = targetRotation - currentRotation;
    
    if (rotationDiff > 180.0f) {
        rotationDiff -= 360.0f;
    } else if (rotationDiff < -180.0f) {
        rotationDiff += 360.0f;
    }
    
    float maxRotationChange = maxRotationSpeed * elapsedSeconds;
    float rotationChange = std::clamp(rotationDiff, -maxRotationChange, maxRotationChange);
    float newRotation = currentRotation + rotationChange;
    
    pointer.setRotation(newRotation);
}

void redrawFrame(sf::RenderWindow& window, sf::ConvexShape& pointer) {
    window.clear();
    window.draw(pointer);
    window.display();
}

int main() {
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    sf::Clock clock;

    init(pointer);

    while (window.isOpen()) {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }

    return 0;
}
