#include <sil/sil.hpp>
#include "random.hpp"
#include <cmath>
#include <iostream>
#include <algorithm>
#include <complex>




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
            int newX = image.height() - 1 -y; // largeur devient hauteur
            int newY = x; 

            new_image.pixel(newX, newY) = image.pixel(x, y);

        }
    }

    image = new_image;
}


void split(sil::Image& image)
{
    int new_width = image.width();
    int new_height = image.height();
    sil::Image new_image{new_width, new_height};
    int offset = 20;

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            int redX = x + offset;
            int blueX = x - offset;
            
            if (redX >= image.width()) redX = image.width() - 1;
            if (blueX < 0) blueX = 0;
                
            new_image.pixel(x,y).r = image.pixel(redX, y).r;
            new_image.pixel(x,y).g = image.pixel(x, y).g;
            new_image.pixel(x,y).b = image.pixel(blueX,y).b;
            
            
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


void rosace(sil::Image& image)
{
    float rayon = 100.0f;
    float thickness = 2.0f;
    int circles= 6;

    for (int i{0}; i<circles; i++)
    {
        float angle = i * 2.0f * M_PI / circles; //repartition des cercles sur 2 PI (un cercle complet)
        float centre_cercleX= image.width()/2.0f + rayon * cos(angle);
        float centre_cercleY=image.height()/2.0f + rayon * sin(angle);

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float dx = x - centre_cercleX;
            float dy = y - centre_cercleY;
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

//redessiner le cercle original au centre
    for (int x{0}; x < image.width(); x++){
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


void mosaique(sil::Image& image)
{   
    int num_rep = 5;
    int new_width = image.width()/num_rep;
    int new_height = image.height()/num_rep;

    sil::Image new_image{new_width, new_height};

    for (int i{0}; i < num_rep; i++)
    {    
         for (int j{0}; j < num_rep; j++)
        {
            for (int x = 0; x < new_width; x++)
            {   
                for (int y = 0; y < new_height; y++)
                {
                    int finalX = x + i * new_width;
                    int finalY = y + j * new_height;

                    new_image.pixel(finalX, finalY) = image.pixel(x, y);
                }
            }
        }
    }
        
    image = new_image;
}



void glitch(sil::Image& image)
{
    int iterations = 100;
    int size_max = 12;

    for (int i{0}; i < iterations; i++){

        //Taille du rect
        int w = random_int(1, size_max);
        int h = random_int(1, size_max);
        
        //Position du rect1
        int x1 = random_int(0, image.width()-w);
        int y1 = random_int(0, image.height()-h);

        //Position rect2
        int x2= random_int(0, image.width()-w);
        int y2 = random_int(0, image.height()-h);
        

        for (int x{0}; x < image.width(); x++)
        {
            for (int y{0}; y<image.height(); y++)
            {
                if (x >= x1 && x < x1+w && y >= y1 && y < y1+h)
                {
                    std::swap(image.pixel(x, y), image.pixel(x2 + (x-x1), y2 + (y-y1)));
                }
            }
        }

    }

}


float brightness(glm::vec3 const& c)
        {
            float brightness = 0.2126f * c.r + 0.7152f * c.g + 0.0722f * c.b;
            return brightness;
        }


void sort(sil::Image& image)
{
 int iterations = random_int(500, 1000);

 for (int i{0}; i < iterations; i++)
{
    int x_size = random_int(30, 80); //size 
    int x_position = random_int(0, image.width() - x_size); //position

    int y = random_int(0, image.height());

    std::vector<glm::vec3> line;

    for (int x=x_position; x < x_position + x_size; x++)
    {
        //glm::vec3 pixel = image.pixel(x, y);
        line.push_back(image.pixel(x,y));
    }
    
    std::sort(line.begin(), line.end(), [](glm::vec3 const& c1, glm::vec3 const& c2)
    {
       
        return brightness(c1) < brightness(c2);
    });

    for(int x=x_position; x < x_size + x_position; x++)
    { 
        image.pixel(x, y) = line.at(x-x_position);
    }
}
}


void fractale(sil::Image& image)
{
    int max_iterations = 25;

    for (int x{0}; x < image.width(); x++)
    {
        for (int y{0}; y < image.height(); y++)
        {
            float Re = -2.0f + 4.0f *x/image.width();
            float Im = -2.0f +4.0f *y/image.height();

            std::complex<float> c{Re, Im};
            std::complex<float> z{0.0f, 0.0f};

            int iterations = 0;
            
            while (iterations < max_iterations && std::abs(z)<= 2.0f)
            {
                z=z*z+c;
                iterations++;
            }
            
            float intensity = iterations / static_cast<float>(max_iterations); //! static_cast pour eviter la division entière!
            image.pixel(x, y).r = intensity;
            image.pixel(x, y).g = intensity;
            image.pixel(x, y).b = intensity;
                
         }

     }
}




int main()

{

    // GREEN
//     {
//         sil::Image image{"images/logo.png"};
//         keep_green(image);
//         image.save("output/green.png");
//         }

    // SWAP
//     {
//         sil::Image image{"images/logo.png"};
//         swap(image);
//         image.save("output/swap.png");
//         }

    // BLACK AND WHITE
//     { 
//         sil::Image image{"images/logo.png"};
//         black_white(image);
//         image.save("output/black_and_white.png");
//     }

    // NEGATIF
//     {
//         sil::Image image{"images/logo.png"};
//         negatif(image);
//         image.save("output/negatif.png");
//     }

    // GRADIENT
//     {
//         sil::Image image{"images/logo.png"};
//         gradient(image);
//         image.save("output/gradient.png");
//     }

    // MIRROR
//     {
//         sil::Image image{"images/logo.png"};
//         mirror(image);
//         image.save("output/mirror.png");
//     }

    // ROTATION 
//     {
//         sil::Image image{"images/logo.png"};
//         rotate(image);
//         image.save("output/rotation.png");
//     }

    // DISC
//     {
//         sil::Image image{500/*width*/, 500/*height*/};
//         disc(image);
//         image.save("output/disc.png");
//     }

    // CIRCLE
//     {
//         sil::Image image{500/*widtj*/, 500/*height*/};
//         circle(image);
//         image.save("output/circle.png");
//     }

    // ANIMATION
//     { 
//         for (int frame{0}; frame <177; frame++)
//         {
//         sil::Image image{250/*width*/, 250/*height*/};
//         animation(image, frame);
//         image.save("output/animation/frame_" + std::to_string(frame)+".png");
//          }
//     }

    // LUMINOSITÉ
//     {
//         sil::Image image{"images/photo.jpg"};
//         clair(image); 
//         image.save("output/clair.png");
//      }

    // SOMBRE
//     {
//        sil::Image image{"images/photo.jpg"};
//        sombre(image); 
//        image.save("output/sombre.png");
//     }

    // NOISE
//     { 
//        sil::Image image{"images/logo.png"};
//        noise(image);
//        image.save("output/noise.png");
//      }

    // ROSACE
// {
//     sil::Image image{500/*width*/, 500/*height*/};
//     rosace(image);
//     image.save("output/rosace.png");
// }

    // MOSAIQUE
// {
//     sil::Image image{"images/logo.png"};
//     mosaique(image);
//     image.save("output/mosaique.png");
// }


    // SPLIT 
// {
//     sil::Image image{"images/logo.png"};
//     split(image);
//     image.save("output/split.png");
// }

    // GLITCH
// {
//     sil::Image image{"images/logo.png"};
//     glitch(image);
//     image.save("output/glitch.png");
// }

    // SORT
// {
//     sil::Image image{"images/logo.png"};
//     sort(image);
//     image.save("output/sort.png");
// }

    // FRACTALE
    {
        sil::Image image{500/*width*/, 500/*height*/};
        fractale(image);
        image.save("output/fractale.png");
    }
} 