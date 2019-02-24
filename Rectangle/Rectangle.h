//
// Created by Igor Bulakh on 2019-02-24.
//

#ifndef YELLOW_RECTANGLE_H
#define YELLOW_RECTANGLE_H

#pragma once

class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;
    int GetPerimeter() const;
    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;
};

#endif //YELLOW_RECTANGLE_H
