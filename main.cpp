#include <SFML/Graphics.hpp>
#include <list>
#include <vector>
#include <tuple>
#include <string>
#include <fstream>
#include "Place.h"
#include "Routes.h"
#include <filesystem>

#define SIZING 8

using namespace std;
namespace fs = std::filesystem;

vector<string> explode(const string& s, const char& c)
{
    string buff;
    vector<string> v;

    for(auto n:s)
    {
        if(n != c) buff+=n; else
        if(n == c && !buff.empty()) { v.push_back(buff); buff = ""; }
    }
    if(!buff.empty()) v.push_back(buff);

    return v;
}

tuple<vector<Routes>,string,string> readTextInput(const string& fileName){
    ifstream file;
    file.open(fileName);
    string line;
    vector<Routes> result;
    getline(file,line);
    vector<string>truck = explode(line,':');
    sf::Color lineColor;
    list<Place> places;
    int j = 0;
    while(truck.at(0)== "truck"){
        places = list<Place>();
        switch(j%6){
            case 0:
                lineColor = sf::Color::Red;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255*ratio,255,255)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
            case 1:
                lineColor = sf::Color::Green;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255, 255*ratio, 255)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
            case 2:
                lineColor = sf::Color::Blue;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255, 255,255*ratio)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
            case 3:
                lineColor = sf::Color::Yellow;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255*ratio, 255*ratio,255)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
            case 4:
                lineColor = sf::Color::Magenta;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255*ratio, 255,255*ratio)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
            case 5:
                lineColor = sf::Color::Cyan;
                for(int i = 2 ; i < truck.size()-1 ; i++){
                    auto ratio = double(double(i-2)/double(truck.size()-3));
                    vector<string> place = explode(truck.at(i),',');
                    places.emplace_back(Place(SIZING*stoi(place.at(1)),SIZING*stoi(place.at(2)),place.at(0),sf::Color(255, 255*ratio,255*ratio)));
                }
                result.emplace_back(Routes(places,lineColor,truck.at(1)));
                break;
        }


        getline(file,line);
        truck = explode(line,':');
        j++;
    }

    return tuple<vector<Routes>,string,string>(result,truck.at(0),truck.at(1));
}


void draw(const string& fileName){
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Shipping render");

    sf::Font font;
    if (!font.loadFromFile("OpenSans-Regular.ttf")){}

    tuple<vector<Routes>, string, string> input = readTextInput(fileName);
    vector<Routes> roads = get<0>(input);

    while (window.isOpen())
    {
        sf::Event event{};
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for(const auto& road :roads) {
            window.draw(road.getShape());

            for (const auto &e : road.getPoints()) {
                window.draw(e.getPoints());
                sf::Text tmp = sf::Text(e.getName(), font, 15);
                tmp.setPosition(e.getPoints().getPosition().x - 10, e .getPoints().getPosition().y - 25);
                window.draw(tmp);
            }
        }
        window.display();
        sf::Texture texture;
        texture.create(window.getSize().x,window.getSize().y);
        texture.update(window);
        texture.copyToImage().saveToFile("../result/"+get<1>(input)+"-"+get<2>(input)+".png");
        window.close();
    }
}


void drawRoad(){
    std::string path = "../textFileInput/";
    for (const auto & entry : fs::directory_iterator(path)){
        draw(entry.path());
    }
}

int main(){
    drawRoad();
}