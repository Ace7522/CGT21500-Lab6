#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

int main() {
    // Initialize image paths
    string background = "images/backgrounds/winter.png";
    string foreground = "images/characters/yoda.png";

    // Load in Background Texture
    Texture backgroundTex;
    if (!backgroundTex.loadFromFile(background))
    {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Image backgroundImage;
    backgroundImage = backgroundTex.copyToImage();

    // Load in Foreground Texture
    Texture foregroundTex;
    if (!foregroundTex.loadFromFile(foreground)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Image foregroundImage;
    foregroundImage = foregroundTex.copyToImage();

    // Iterate through every pixel in the dimensions
    Vector2u sz = backgroundImage.getSize();
    for (int y = 0; y < sz.y; y++)
    {
        for (int x = 0; x < sz.x; x++)
        {
            // If a pixel of foregroundImage is the given green color, replace 
            // it with the pixel at that coord of the backgroundImage
            if (foregroundImage.getPixel(Vector2u(x, y)) == Color(32, 214, 23, 255))
            {
                foregroundImage.setPixel(Vector2u(x, y), backgroundImage.getPixel(Vector2u(x, y)));
            }
        }
    }

    // Create RenderWindow
    RenderWindow window(VideoMode({1024, 768}), "Here's the output");

    // Load the image into the new texture
    Texture resultTexture;
    if (!resultTexture.loadFromImage(foregroundImage)) {
        cout << "Couldn't Load Image" << endl;
        exit(1);
    }
    Sprite resultSprite(resultTexture);

    // Clear screen and display result
    window.clear();
    window.draw(resultSprite);
    window.display();

    // Keep Window open
    while(true);
}