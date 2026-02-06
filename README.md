# S1 | Prog: Workshop

## ⭐ Ne garder que le vert

rouge et bleu à zéro

|                  Avant                  |                  Après                   |
| :-------------------------------------: | :--------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/green.png "Après effet") |

## ⭐ Échanger les canaux

|               Avant Effet               |               Après Effet               |
| :-------------------------------------: | :-------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/swap.png "Après effet") |

## ⭐ Noir & Blanc

|               Avant Effet               |                    Après Effet                     |
| :-------------------------------------: | :------------------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/black_and_white.png "Après effet") |

## ⭐ Négatif

1 - la couleur

|               Avant Effet               |                Après Effet                 |
| :-------------------------------------: | :----------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/negatif.png "Après effet") |

## ⭐ Dégradé

|               Avant Effet               |                 Après Effet                 |
| :-------------------------------------: | :-----------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/gradient.png "Après effet") |

## ⭐ Miroir

|               Avant Effet               |                Après Effet                |
| :-------------------------------------: | :---------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/mirror.png "Après effet") |

## ⭐⭐ Image bruitée

Sans le `if (true_with_probability(0.4f))` _(chance de 40%)_, j'avais du bruit partout j'ai du comprendre comment ajouter de la probabilité (merci la lib)

|               Avant Effet               |               Après Effet                |
| :-------------------------------------: | :--------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/noise.png "Après effet") |

## ⭐ Rotation de 90°

On inverse les dimensions de l'image : la largeur devient la hauteur et vice versa.

|               Avant Effet               |                 Après Effet                 |
| :-------------------------------------: | :-----------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/rotation.png "Après effet") |

## ⭐⭐ Split RGB

On décale le rouge à droite et le bleu à gauche, le vert reste à sa place.

|               Avant Effet               |               Après Effet                |
| :-------------------------------------: | :--------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/split.png "Après effet") |

## ⭐⭐ Luminosité

|               Photo originale                |               Clair                |                Sombre                |
| :------------------------------------------: | :--------------------------------: | :----------------------------------: |
| ![Avant](images/photo.jpg "Image originale") | ![Après](output/clair.png "Clair") | ![Après](output/sombre.png "Sombre") |

## ⭐⭐(⭐) Disque

On regarde la distance des pixels par rapport au centre. Si la distance fait partie du rayon, on colore les pixels en blanc.

|               Disque               |
| :--------------------------------: |
| ![Après](output/disc.png "Disque") |

## ⭐ Cercle

Très similaire au disque sauf qu'on garde que le contour, c'est à dire on garde les pixels dont la distance est proche du rayon.

|                Cercle                |
| :----------------------------------: |
| ![Après](output/circle.png "Cercle") |

## ⭐⭐ Animation

Le disque se déplace vers la gauche à chaque frame de 4 pixels. J'ai décalé la position de départ du disque à -50 pixels pour créer une boucle. _(J'ai acceléré l'animation sur [Ezgif](https://ezgif.com/maker))_

|                 Animation disque                  |
| :-----------------------------------------------: |
| ![Après](output/animatoin-circle.gif "Animation") |

## ⭐⭐⭐ Rosace

J'ajoute à mon algorithme du cercle une boucle qui permet de placer les cercles sur un plus grand cercle (2 PI). Chaque cercle est placé en fonction d'un angle différent mais toujours à la même distance du centre. J'ai redessiné le cercle central ensuite.

|                Rosace                 |
| :-----------------------------------: |
| ![Rosace](output/rosace.png "Rosace") |

## ⭐⭐ Mosaïque

|               Avant Effet               |                 Après Effet                 |
| :-------------------------------------: | :-----------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/mosaique.png "Après effet") |

## ⭐⭐⭐ Glitch

On prend des petits rectangles aléatoires de l'image puis on swap leur position avec d'autres.

|               Avant Effet               |                Après Effet                |
| :-------------------------------------: | :---------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/glitch.png "Après effet") |

## ⭐⭐⭐ Tri de pixels

On choisit une ligne avec sa position et sa taille au hasard. On met la ligne dans un tableau puis on tris les lignes en fonction de leur birghtness.

|               Avant Effet               |               Après Effet               |
| :-------------------------------------: | :-------------------------------------: |
| ![Avant](images/logo.png "Avant effet") | ![Après](output/sort.png "Après effet") |

## ⭐⭐⭐(⭐) Fractale de Mandelbrot

Pour la fractale, il faut convertir les coordonées (x,y) en complexes (parties Imaginaire et Réelle). Pour tracer la fractale, il suffit d'appliquer la formule. Ensuite, je n'avais pas utiliser `static_cast<float>` qui me donnait une image sans nuance de gris, puisque je ne faisais pas la conversion de int vers float.

|                       Mandelbrot                       |
| :----------------------------------------------------: |
| ![Après](output/fractale.png "Fractale de Mandelbrot") |
