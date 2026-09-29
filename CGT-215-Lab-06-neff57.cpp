#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
    string background = "images/backgrounds/winter.png";
    string foreground = "images/characters/yoda.png";

    Texture backgroundTex;
    if (!backgroundTex.loadFromFile(background))
    {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }

    Texture foregroundTex;
    if (!foregroundTex.loadFromFile(foreground)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }

    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    Vector2u sz = backgroundImage.getSize();
    for (int y = 0; y < sz.y; y++)
    {
        for (int x = 0; x < sz.x; x++)
        {
            if (foregroundImage.getPixel(Vector2u(x, y)) == Color(32, 214, 23, 255))
            {
                foregroundImage.setPixel(Vector2u(x, y), backgroundImage.getPixel(Vector2u(x, y)));
            }
        }
    }

    RenderWindow window(VideoMode({1024, 768}), "Here's the output");

    Texture resultTexture;
    if (!resultTexture.loadFromImage(foregroundImage)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Sprite resultSprite(resultTexture);
    
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear();
        window.draw(resultSprite);
        window.display();
    }

    /* window.clear();
    window.draw(resultSprite);
    window.display();

    while(true); */
}