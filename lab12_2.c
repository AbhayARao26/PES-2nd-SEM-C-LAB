#include <stdio.h>

typedef enum
{
    Circle,
    Triangle,
    Rectangle
} ShapeType;

typedef union
{
    int numSides;     // Triangle
    double radius;    // Circle
    struct {
        double base;
        double length;
    } rectangle;      // Rectangle
} Shape;

typedef struct
{
    ShapeType type;
    Shape shape;
} ShapeInfo;

void printShapeInfo(ShapeInfo shapeInfo)
{
    switch (shapeInfo.type)
    {
        case Circle:
            printf("Shape: Circle\nRadius: %.2f\n", shapeInfo.shape.radius);
            break;
        case Triangle:
            printf("Shape: Triangle\nNumber of Sides: %d\n", shapeInfo.shape.numSides);
            break;
        case Rectangle:
            printf("Shape: Rectangle\nBase: %.2f\nLength: %.2f\n", shapeInfo.shape.rectangle.base, shapeInfo.shape.rectangle.length);
            break;
        default:
            printf("Invalid shape type.\n");
    }
}

int main()
{
    ShapeInfo shape1, shape2, shape3;

    // Shape 1
    shape1.type = Circle;
    shape1.shape.radius = 5.00;

    // Shape 2
    shape2.type = Triangle;
    shape2.shape.numSides = 3;

    // Shape 3
    shape3.type = Rectangle;
    shape3.shape.rectangle.base = 6.00;
    shape3.shape.rectangle.length = 6.00;

    // Print shape information
    printShapeInfo(shape1);
    printShapeInfo(shape2);
    printShapeInfo(shape3);

    return 0;
}

