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

Place::Place(int x, int y, const std::string& name,sf::Color color):m_x(x),m_y(y){
    m_points.setRadius(5.f);
    m_points.setPosition(float(x)+22,float(y)+15);
    m_points.setOrigin(m_points.getRadius(),m_points.getRadius());
    m_name = name;
    m_points.setFillColor(color);
    m_points.setOutlineColor(color);
/*
    m_points.setFillColor(sf::Color(255,255*ratio,int(255*ratio)));
    m_points.setOutlineColor(sf::Color(255,255*ratio,int(255*ratio)));*/
}

Place::Place(int x, int y, const std::string& name,double ratio):m_x(x),m_y(y){
    m_points.setRadius(5.f);
    m_points.setPosition(float(x)+22,float(y)+15);
    m_points.setOrigin(m_points.getRadius(),m_points.getRadius());
    m_name = name;
    m_points.setFillColor(sf::Color(255,255*ratio,int(255*ratio)));
    m_points.setOutlineColor(sf::Color(255,255*ratio,int(255*ratio)));
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