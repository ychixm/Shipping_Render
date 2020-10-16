#include "Routes.h"

#include <utility>

const std::list<Place> &Routes::getPoints() const {
    return m_points;
}

void Routes::setPoints(const std::list<Place> &points) {
    Routes::m_points = points;
}

const sf::Color &Routes::getColor() const {
    return m_color;
}

void Routes::setColor(const sf::Color &color) {
    Routes::m_color = color;
}

const sf::ConvexShape &Routes::getShape() const {
    return m_shape;
}

void Routes::setShape(const sf::ConvexShape &shape) {
    Routes::m_shape = shape;
}

Routes::Routes(std::list<Place> points,sf::Color c):m_points(std::move(points)),m_color(c){
    makeShape();
}

void Routes::makeShape() {
    std::cout << "here " << std::endl;
    m_shape.setPointCount(m_points.size());
    int i = 0;
    for(const auto& e : m_points){
        std::cout << "here 1" << std::endl;
        m_shape.setPoint(i,sf::Vector2f(e.getX()+20,e.getY()+10));
        //m_shape.setOrigin(5,5);
        i++;
    }
    std::cout << "here 2" << std::endl;
    m_shape.setOutlineColor(m_color);
    std::cout << "here 3" << std::endl;
    m_shape.setOutlineThickness(5);
    m_shape.setFillColor(sf::Color::Transparent);
}
