#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

struct Rectangle
{
    sf::Vector2f coordinates[4];
    sf::Vector2f rotation_centre;
    float current_angle = 0;

    Rectangle() = default;
    Rectangle(sf::Vector2f coordinates_[4], sf::Vector2f rotation_centre_)
        : coordinates{coordinates_[0], coordinates_[1], coordinates_[2], coordinates_[3]},
          rotation_centre{rotation_centre_} {};

    void rotate(float angle) // Rotates rectangle around the centre point rotation_centre by angle in radians
    {
        current_angle += angle;
        float cos_angle = cos(angle);
        float sin_angle = sin(angle);

        for (int i = 0; i < 4; i++)
        {
            sf::Vector2f coord = coordinates[i];

            coordinates[i] = {(coord.x - rotation_centre.x) * cos_angle - sin_angle * (coord.y - rotation_centre.y) + rotation_centre.x, (coord.x - rotation_centre.x) * sin_angle + cos_angle * (coord.y - rotation_centre.y) + rotation_centre.y};
        }
    }

    void move(sf::Vector2f direction)
    {
        rotation_centre += direction;
        // for (sf::Vector2f &coord : coordinates)
        // {
        //     coord += direction;
        // }
    }

    void print()
    {
        for (auto coord : coordinates)
        {
            std::cout << coord.x << ", " << coord.y << std::endl;
        }
    }

    void draw(sf::RenderTarget &target, sf::RectangleShape rectangle)
    {
        sf::Angle angle = sf::radians(current_angle);
        rectangle.setPosition(rotation_centre);
        rectangle.setRotation(angle);
        rectangle.setOutlineColor(sf::Color::Black);
        target.draw(rectangle);
    }
};