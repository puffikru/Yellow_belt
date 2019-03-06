#include <iostream>
#include <vector>
#include <memory>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle : public Figure {
public:
    Triangle(const int& a, const int& b, const int& c)
        : a_(a),
          b_(b),
          c_(c),
          name("TRIANGLE") {}

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return a_ + b_ + c_;
    }

    double Area() const override {
        double semi_perimeter = Perimeter() / 2;
        return sqrt(semi_perimeter * (semi_perimeter - a_) * (semi_perimeter - b_) * (semi_perimeter - c_));
    }

private:
    const int a_, b_, c_;
    const string name;
};

class Rect : public Figure {
public:
    Rect(const int& width, const int& height)
        : width_(width),
          height_(height),
          name("RECT") {}

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return (width_ + height_) * 2;
    }

    double Area() const override {
        return width_ * height_;
    }

private:
    const int width_, height_;
    const string name;
};

class Circle : public Figure {
public:
    Circle(const int& r) : r_(r), name("CIRCLE") {}

    string Name() const override {
        return name;
    }

    double Perimeter() const override {
        return 2 * 3.14 * r_;
    }

    double Area() const override {
        return 3.14 * r_ * r_;
    }

private:
    const int r_;
    const string name;
};


shared_ptr<Figure> CreateFigure(istream& s) {
    string name;
    s >> name;
    if (name == "TRIANGLE") {
        int a, b, c;
        s >> a;
        s >> b;
        s >> c;
        return make_shared<Triangle>(a, b, c);
    } else if (name == "RECT") {
        int weight, height;
        s >> weight;
        s >> height;
        return make_shared<Rect>(weight, height);
    } else if (name == "CIRCLE") {
        int r;
        s >> r;
        return make_shared<Circle>(r);
    }
    return shared_ptr<Figure>();
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line);) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}