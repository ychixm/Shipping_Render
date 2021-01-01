#ifndef SHIPPING_RENDER_ROUTES_H
#define SHIPPING_RENDER_ROUTES_H
#include <list>
#include <utility>
#include "Place.h"

class Routes {
    private:

        std::list<Place> m_points;
        std::string name;
        sf::Color m_color;
        sf::ConvexShape m_shape;
        sf::VertexArray m_road;

    public:
    Routes(std::list<Place> points,sf::Color c,std::string name = "");

    void makeShape();

    const std::list<Place> &getPoints() const;

    void setPoints(const std::list<Place> &points);

    const sf::Color &getColor() const;

    void setColor(const sf::Color &color);

    const sf::ConvexShape &getShape() const;

    void setShape(const sf::ConvexShape &shape);

};


#endif //SHIPPING_RENDER_ROUTES_H
