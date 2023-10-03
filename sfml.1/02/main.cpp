#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main () {
    sf::RenderWindow window(sf::VideoMode({800,400}), "title");
    window.clear();


    sf::RectangleShape L1;
    L1.setPosition({10, 10});
    L1.setSize({30,210});
    L1.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(L1);
    sf::RectangleShape L2;
    L2.setPosition({10, 190});
    L2.setSize({180,30});
    L2.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(L2);

    sf::RectangleShape D1;
    D1.setPosition({230, 10});
    D1.setSize({30,210});    
    D1.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(D1);
    sf::RectangleShape D2;
    D2.setPosition({250, 180});
    D2.setSize({140,30});    
    D2.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(D2);
    sf::RectangleShape D3;
    D3.setPosition({250, 20});
    D3.setSize({140,30});    
    D3.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(D3);
    sf::RectangleShape D4;
    D4.setPosition({360, 40});
    D4.setSize({30,170});    
    D4.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(D4);

    sf::RectangleShape A1;
    A1.setPosition({430, 10});
    A1.setSize({30,210});    
    A1.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(A1);
    sf::RectangleShape A2;
    A2.setPosition({450, 10});
    A2.setSize({140,30});    
    A2.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(A2);
    sf::RectangleShape A3;
    A3.setPosition({560, 10});
    A3.setSize({30,210});    
    A3.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(A3);
    sf::RectangleShape A4;
    A4.setPosition({450, 100});
    A4.setSize({140,30});    
    A4.setFillColor(sf::Color(0xAF, 0xAF, 0xAF));
    window.draw(A4);


    window.display();
    sf::sleep(sf::seconds(5));
}
