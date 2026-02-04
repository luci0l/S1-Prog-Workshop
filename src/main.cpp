#include <sil/sil.hpp>
#include "random.hpp"



void keep_green(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 0.0f;
            image.pixel(x, y).b = 0.0f;
        }
    }
}


void swap(sil::Image& image)
{
     for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x, y).r, image.pixel(x, y).b);
        }
    }

}

void black_white(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float grey = 0.2126f *image.pixel(x,y).r + 0.7152f* image.pixel(x,y).g + 0.0722f* image.pixel(x,y).b;
            image.pixel(x, y).r = grey;
            image.pixel(x, y).g = grey;
            image.pixel(x, y).b = grey;
        }
    }
}


void negatif(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x, y).r = 1.0f - image.pixel(x, y).r;
            image.pixel(x, y).g = 1.0f - image.pixel(x, y).g;
            image.pixel(x, y).b = 1.0f - image.pixel(x, y).b;
        
        }
    }
}



void gradient(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            image.pixel(x,y).r = x / (image.width()-1.0f);
            image.pixel(x,y).g = x / (image.width()-1.0f);
            image.pixel(x,y).b = x / (image.width()-1.0f); 
        
        }
    }
}



void mirror(sil::Image& image)
{
    for (int x{0}; x <image.width()/2; x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            std::swap(image.pixel(x,y), image.pixel(image.width()-1 -x,y));
    
        }
    }
}


void rotate(sil::Image& image)
{
    int new_width = image.height();
    int new_height = image.width();
    sil::Image new_image{new_width, new_height};
  

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int newX = image.height() - 1 -y;
            int newY = x; 

            new_image.pixel(newX, newY) = image.pixel(x, y);

        }
    }

    image = new_image;
}


void disc(sil::Image& image)
{
    float rayon = 100.0f;

    
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float dx = x - image.width() / 2.0f;
            float dy = y - image.height() / 2.0f;
            float disque = sqrt(dx*dx + dy*dy);

            if (disque <= rayon)
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }
        }
    }
}


void circle(sil::Image& image)
{
    float rayon = 100.0f;
    float thickness = 3.0f;

    
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float dx = x - image.width() / 2.0f;
            float dy = y - image.height() / 2.0f;
            float disque = sqrt(dx*dx + dy*dy);

            if (disque <= rayon + thickness && disque >= rayon - thickness)
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }
        }
    }
}

void animation(sil::Image& image, int frame)
{ 
    float rayon = 50.0f;

    for (int x{0}; x < image.width(); x++)
{
    for (int y{0}; y <image.height(); y++)
    {
        float dx = x - image.width() - 50  + frame * 4.0f;
        float dy = y - image.height() / 2.0f;
        float disque = sqrt(dx*dx + dy*dy);

         if (disque <= rayon)
            {
                image.pixel(x, y).r = 1.0f;
                image.pixel(x, y).g = 1.0f;
                image.pixel(x, y).b = 1.0f;
            }
        }
    }
}


void clair(sil::Image& image)
{
    for (int x{0}; x <image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
        glm::vec3 color;
        color.r =std::pow(image.pixel(x,y).r, 0.5f);
        color.g =std::pow(image.pixel(x,y).g, 0.5f);
        color.b =std::pow(image.pixel(x,y).b, 0.5f);
         image.pixel(x,y) = color;  
        }
    }
}


void sombre(sil::Image& image)
{
    for (int x{0}; x <image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
        glm::vec3 color;
        color.r =std::pow(image.pixel(x,y).r, 2.0f);
        color.g =std::pow(image.pixel(x,y).g, 2.0f);
        color.b =std::pow(image.pixel(x,y).b, 2.0f);
         image.pixel(x,y) = color;  
        }
    }
}


void noise(sil::Image& image)
{
    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            if (true_with_probability(0.4f))
            {
            image.pixel(x,y).r = random_float(0.0f,1.0f);
            image.pixel(x,y).g = random_float(0.0f, 1.0f);
            image.pixel(x,y).b = random_float(0.0f, 1.0f);
            }
        
        } 
    }
}



int main()
{

    // GREEN
    {
        sil::Image image{"images/logo.png"};
        keep_green(image);
        image.save("output/green.png");
        }

    // SWAP
    {
        sil::Image image{"images/logo.png"};
        swap(image);
        image.save("output/swap.png");
        }

    // BLACK AND WHITE
    { 
        sil::Image image{"images/logo.png"};
        black_white(image);
        image.save("output/black_and_white.png");
    }

    // NEGATIF
    {
        sil::Image image{"images/logo.png"};
        negatif(image);
        image.save("output/negatif.png");
    }

    // GRADIENT
    {
        sil::Image image{"images/logo.png"};
        gradient(image);
        image.save("output/gradient.png");
    }

    // MIRROR
    {
        sil::Image image{"images/logo.png"};
        mirror(image);
        image.save("output/mirror.png");
    }

    // ROTATION 
    {
        sil::Image image{"images/logo.png"};
        rotate(image);
        image.save("output/rotation.png");
    }

    // DISC
    {
        sil::Image image{500/*width*/, 500/*height*/};
        disc(image);
        image.save("output/disc.png");
    }

    // CIRCLE
    {
        sil::Image image{500/*widtj*/, 500/*height*/};
        circle(image);
        image.save("output/circle.png");
    }

    //ANIMATION
    { 
        for (int frame{0}; frame <177; frame++)
        {
        sil::Image image{250/*width*/, 250/*height*/};
        animation(image, frame);
        image.save("output/animation/frame_" + std::to_string(frame)+".png");
    }
}

    // LUMINOSITÉ
{
    sil::Image image{"images/photo.jpg"};
    clair(image); 
    image.save("output/clair.png");

}

    // SOMBRE
{
    sil::Image image{"images/photo.jpg"};
    sombre(image); 
    image.save("output/sombre.png");

}

    // NOISE
{ 
    sil::Image image{"images/logo.png"};
    noise(image);
    image.save("output/noise.png");
}
}