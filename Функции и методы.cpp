#include <iostream>
#include <cmath>

using namespace std;

// методы класса
class Circle {
private:
	double x;
	double y;
	double radius;
public:
	Circle(double x, double y, double radius) {
		this->x = x;
		this->y = y;
		this->radius = radius;
	}

	double distance_to_origin() {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	double distance_between_circles(Circle& circle) {
		return sqrt(pow(abs(x - circle.get_x()), 2) + pow(abs(y - circle.get_y()), 2));
	}

	double distance_to_x_axis() {
		return max(abs(y) - radius, 0.0);
	}

	double distance_from_circle_to_origin() {
		return max(sqrt(pow(x, 2) + pow(y, 2)) - radius, 0.0);
	}

	bool can_be_inscribed(Circle& circle) {
		return radius < circle.get_radius();
	}

	bool is_crossing(Circle& circle) {
		double distance = distance_between_circles(circle);
		return (distance <= radius + circle.get_radius() && 
                radius + distance >= circle.get_radius() && 
                circle.get_radius() + distance >= radius);
	}

    double get_x() {
        return x;
    }

    double get_y() {
        return y;
    }

    double get_radius() {
        return radius;
    }
};

// функции
double distance_to_origin(Circle& circle) {
	return sqrt(pow(circle.get_x(), 2) + pow(circle.get_y(), 2));
}

double distance_between_circles(Circle& circle1, Circle& circle2) {
	return sqrt(pow(abs(circle1.get_x() - circle2.get_x()), 2) + pow(abs(circle1.get_y() - circle2.get_y()), 2));
}

double distance_to_x_axis(Circle& circle) {
	return max(abs(circle.get_y()) - circle.get_radius(), 0.0);
}

double distance_from_circle_to_origin(Circle& circle) {
	return max(sqrt(pow(circle.get_x(), 2) + pow(circle.get_y(), 2)) - circle.get_radius(), 0.0);
}

bool can_be_inscribed(Circle& circle1, Circle& circle2) {
	return circle1.get_radius() < circle2.get_radius();
}

bool is_crossing(Circle& circle1, ircle& circle2) {
	double distance = distance_between_circles(circle1, circle2);

	return (distance <= circle1.get_radius() + circle2.get_radius() && 
            circle1.get_radius() + dist >= circle2.get_radius() && 
            circle1.get_radius() + dist >= circle2.get_radius());
}

int main() {
    Circle circle1 = Circle(4, 7, 3);
    Circle circle2 = Circle(10, 5, 6);

    // функции
    cout << "Функции:\n";
    cout << distance_to_origin(circle1) << endl;
    cout << distance_between_circles(circle1, circle2) << endl;
    cout << distance_to_x_axis(circle1) << endl;
    cout << distance_from_circle_to_origin(circle1) << endl;
    cout << can_be_inscribed(circle1, circle2) << endl;
    cout << is_crossing(circle1, circle2) << endl;

    // методы
    cout << "Методы:\n";
    cout << circle1.distance_to_origin() << endl;
    cout << circle1.distance_between_circles(circle2) << endl;
    cout << circle1.distance_to_x_axis() << endl;
    cout << circle1.distance_from_circle_to_origin() << endl;
    cout << circle1.can_be_inscribed(circle2) << endl;
    cout << circle1.is_crossing(circle2) << endl;
}