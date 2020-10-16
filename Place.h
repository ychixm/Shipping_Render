#ifndef SHIPPING_RENDER_PLACE_H
#define SHIPPING_RENDER_PLACE_H

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <iostream>

class Place {

    private:
        sf::CircleShape m_points;
        std::string m_name;
        char type;
        int m_x;
        int m_y;

    public:
        Place(int x, int y, const std::string& name);

        const sf::CircleShape &getPoints() const;

        void setPoints(const sf::CircleShape &points);

        void display(sf::RenderWindow &w);

        const std::string &getName() const;

        void setName(const std::string &Name);

        int getX() const;

        void setX(int x);

        int getY() const;

        void setY(int y);
};

#endif //SHIPPING_RENDER_PLACE_H