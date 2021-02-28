#include <iostream>
#include <vector>

using namespace std;

void print(vector <vector <char>>& ar)
{
	for (int i = 0; i < ar.size(); i++) {
		for (int j = 0; j < ar.size(); j++) {
			cout << ar[i][j] << " ";
		}
		cout << "\n";
	}
}

enum DIRECTION {
    UP, RIGHT, DOWN, LEFT
}

class Robot {
private:
	int x;
	int y;
	int direction;

public:
	Robot(int x = 0, int y = 0, int direction = UP) {
		this->x = x;
		this->y = y;
		this->direction = direction;
	}

	void move() {
        switch(direction) {
            case UP: x--;
            break;
            case RIGHT: y++;
            break;
            case DOWN: x++;
            break;
            case LEFT: y--;
            break;
            default: break;
        }
	}

	void rotate_right() {
		direction++;
	}

	void rotate_left() {
		direction--;
	}

    int get_x() {
		return x;
	}

    int get_y() { 
		return y;
	}
};

int main() {
    cout << "Введите размер поля: ";
	int field_size;
	cin >> field_size;
	if (n < 2) n = 2;
	int** field = new int*[field_size];
    // вывод поля:
    cout << "Before:\n";
    for (int i = 0; i < field_size; i++) {
        field[i] = new int[field_size];
        for (int j = 0; j < field_size; j++) {
            field[i][j] = 0;
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
	Robot robot();
    field[robot.get_x()][robot.get_y()] = 1;
	robot.rotate_right();

    // красим главную диагональ
	for (int i = 1; i < field_size; i++) {
		robot.rotate_right();
		robot.move_forward();
		robot.rotate_left();
		robot.move_forward();
		field[robot.get_x()][robot.get_y()] = 1;
	}

    // идем к побочной диагонали
	robot.rotate_left();
	for (int i = field_size - 1; i > 0; i--) {
		robot.move_forward();
	}
	field[robot.get_x()][robot.get_y()] = 1;
	robot.rotate_left();

    // красим побочную диагональ
	for (int i = 1; i < n; i++) {
		robot.move_forward();
		robot.rotate_left();
		robot.move_forward();
		field[robot.get_x()][robot.get_y()] = 1;
		robot.rotate_right();
	}

    // вывод поля:
    cout << "After:"
	for (int i = 0; i < field_size; i++) {
        field[i] = new int[field_size];
        for (int j = 0; j < field_size; j++) {
            cout << field[i][j] << " ";
        }
        cout << endl;
    }
}