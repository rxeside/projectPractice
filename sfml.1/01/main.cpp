    #include <SFML/Graphics.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>

    int main () {
        sf::RenderWindow window(sf::VideoMode({140,320}), "title");
        window.clear();


        sf::RectangleShape shape0;
        shape0.setPosition({10, 10});
        shape0.setSize({120,310});
        shape0.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
        window.draw(shape0);

        sf::CircleShape shape1(40);
        shape1.setPosition({30, 20});
        shape1.setFillColor(sf::Color(0xFF, 0x0, 0x0));
        window.draw(shape1);

        sf::CircleShape shape2(40);
        shape2.setPosition({30, 120});
        shape2.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
        window.draw(shape2);

        sf::CircleShape shape3(40);
        shape3.setPosition({30, 220});
        shape3.setFillColor(sf::Color(0x0, 0xFF, 0x0));
        window.draw(shape3);



        window.display();
        sf::sleep(sf::seconds(5));
    }
