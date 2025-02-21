#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

struct Rectangle
{
    sf::Vector2f coordinates[4];
    sf::Vector2f rotation_centre;

    Rectangle() = default;
    Rectangle(sf::Vector2f coordinates_[4], sf::Vector2f rotation_centre_)
        : coordinates{coordinates_[0], coordinates_[1], coordinates_[2], coordinates_[3]},
          rotation_centre{rotation_centre_} {};

    void rotate(float angle) // Rotates rectangle around the centre point rotation_centre by angle in radians
    {
        float cos_angle = cos(angle);
        float sin_angle = sin(angle);

        for (int i = 0; i < 4; i++)
        {
            sf::Vector2f coord = coordinates[i];

            coordinates[i] = {(coord.x - rotation_centre.x) * cos_angle - sin_angle * (coord.y - rotation_centre.y) + rotation_centre.x, (coord.x - rotation_centre.x) * sin_angle + cos_angle * (coord.y - rotation_centre.y) + rotation_centre.y};
        }
    }

    void print()
    {
        for (auto coord : coordinates)
        {
            std::cout << coord.x << ", " << coord.y << std::endl;
        }
    }
};