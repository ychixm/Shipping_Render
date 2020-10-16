#include <SFML/Graphics.hpp>
#include <list>
#include "Place.h"
#include "Routes.h"

int main(){
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Shipping render");

    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf")){}

    std::list<Place> places;
    places.emplace_back(Place(0,0,"depot"));
    places.emplace_back(Place(20,40,"one"));
    places.emplace_back(Place(80,10,"two"));
    places.emplace_back(Place(60,150,"three"));
    places.emplace_back(Place(320,100,"four"));
    places.emplace_back(Place(50,200,"five"));

    Routes road(places,sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        window.draw(road.getShape());

        for(const auto& e : places){
            window.draw(e.getPoints());
            sf::Text tmp = sf::Text(e.getName(),font,15);
            tmp.setPosition(e.getPoints().getPosition().x-10,e.getPoints().getPosition().y-25);
            window.draw(tmp);
        }


        window.display();
    }

    return 0;
}