// COMP1511 Week 4 Lab: Circle Facts
//
// This program was written by Chloe Toh (z5362296)
// on 12/03/2021
//
// This program prints out facts about a circle given its radius,
// using functions.
//

#include <stdio.h>
#include <math.h>

double area(double radius);
double circumference(double radius);
double diameter(double radius);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    double radius;

    printf("Enter circle radius: ");
    scanf("%lf", &radius);

    printf("Area          = %lf\n", area(radius));
    printf("Circumference = %lf\n", circumference(radius));
    printf("Diameter      = %lf\n", diameter(radius));

    return 0;
}


// Calculate the area of a circle, given its radius.
double area(double radius) {
    //Area of a circle is PI*r^2
    return M_PI * radius * radius;
}

// Calculate the circumference of a circle, given its radius.
double circumference(double radius) {
    //Circumferece of a cirle is 2*r*PI
    return M_PI * 2 * radius; 
}

// Calculate the diameter of a circle, given its radius.
double diameter(double radius) {
    //Diameter of a circle is 2 * r
    return 2 * radius;
}
