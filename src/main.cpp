#include "gplot++.h"
#include "Rectangle.h"

void displayMenu();
void rotateRectangleUsingDegreeAnimation(Rectangle & rect, Gnuplot & plt, double degree);

int main(void) {
    double degree, amountOfRotation;
    char c = ' ';
    Vector translation;

    Vector v1(1, 1);
    Vector v2(11, 1);
    Vector v3(11, 6);
    Vector v4(1, 6);
    Rectangle rect(v1, v2, v3, v4);

    Gnuplot plt{};
    plt.plot(std::get<0>(rect.getCordinates()), std::get<1>(rect.getCordinates()));

    plt.set_xrange(-20, 20);
    plt.set_yrange(-20, 20);
    plt.show();

    displayMenu();
    while(c != 'k'){
        if(!(std::cin >> c)){
            throw std::exception();
        }
        switch (c) {
            case 'm':
                displayMenu();
                break;
            case 'o':
                std::cout << "Angle by degree:\n";
                std::cin >> degree;
                std::cout << "Amount of rotation:\n";
                std::cin >> amountOfRotation;
                degree *= amountOfRotation;
                rotateRectangleUsingDegreeAnimation(rect, plt, degree);
                break;
            case 'p':
                std::cin >> translation;
                rect.translationByVector(translation);
                plt.plot(std::get<0>(rect.getCordinates()), std::get<1>(rect.getCordinates()));
                plt.set_xrange(-20, 20);
                plt.set_yrange(-20, 20);
                plt.show();
                break;
            case 'w':
                std::cout << rect;
                break;
            case 'k':
                return 0;
            default:
                std::cout << "Unknow commands !\n";
                break;
        }
    }
}

void displayMenu(){
    std::cout << "o - Rotate by angle in degree\n";
    std::cout << "p - Translate by vector\n";
    std::cout << "w - Display coordinates of ertices\n";
    std::cout << "m - Display menu\n";
    std::cout << "k - Close program\n";
}


void rotateRectangleUsingDegreeAnimation(Rectangle & rect, Gnuplot & plt, double degree) {
    Rectangle animate = rect;
    double singleDegree = 0;
    while (std::abs(singleDegree) < std::abs(degree)){
        singleDegree += 2;
        if(degree >= 0){
            animate.rotationUsingDegrees(2);
        } else {
            animate.rotationUsingDegrees(-2);
        }
        usleep(100000);
        plt.plot(std::get<0>(animate.getCordinates()), std::get<1>(animate.getCordinates()));
        plt.set_xrange(-20, 20);
        plt.set_yrange(-20, 20);
        plt.show();
    }
    rect.rotationUsingDegrees(degree);
    plt.plot(std::get<0>(rect.getCordinates()), std::get<1>(rect.getCordinates()));
    plt.set_xrange(-20, 20);
    plt.set_yrange(-20, 20);
    plt.show();
}