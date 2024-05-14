#include <stdio.h>
#include "circle.h"
#include "square.h"
#include "rectangle.h"


int main() {
    float radius = 5.0;
    float side = 4.0;
    float length = 6.0;
    float breadth = 3.0;

    printf("Area of Circle: %f\n", areaOfCircle(radius));
    printf("Area of Square: %f\n", areaOfSquare(side));
    printf("Area of Rectangle: %f\n", areaOfRectangle(length, breadth));

    return 0;
}
