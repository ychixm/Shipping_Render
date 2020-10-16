#include <SFML/Window/Window.hpp>
#include "Place.h"

const sf::CircleShape &Place::getPoints() const {
    return m_points;
}

void Place::setPoints(const sf::CircleShape &points) {
    Place::m_points = points;
}


void Place::display(sf::RenderWindow &w) {
    w.draw(m_points);
   // w.draw(m_name);
}

Place::Place(int x, int y, const std::string& name):m_x(x),m_y(y){
    m_points.setRadius(5.f);
    m_points.setPosition(x+20,y+20);
    m_points.setOrigin(m_points.getRadius(),m_points.getRadius());
    m_name = name;
}

const std::string &Place::getName() const {
    return m_name;
}

void Place::setName(const std::string &Name) {
    m_name = Name;
}

int Place::getX() const {
    return m_x;
}

void Place::setX(int x) {
    m_x = x;
}

int Place::getY() const {
    return m_y;
}

void Place::setY(int y) {
    m_y = y;
}
