#include<iostream>
#include<string>

using namespace std;

class Rectangle {

private:
    double height;
    double width;

public:
    Rectangle() { width = height = 0; }
    Rectangle(double w, double h) { width = w; height = h; }
    ~Rectangle() {}

    double getWidth() const { return width; }

    double getHeight() const { return height; }



    void setWidth(double w) {
        if(w < 0) {
            return;
        }
        width = w;

    }

    void setHeight(double h) {
        if (h < 0) {
            return;
        }
        height = h;
    }
    double Area() {
       double area = height * width;
        return area;
    }

    double Perimeter() const {
        return 2 * (height + width);
    }

    string toString() const {
        return "Rectangle (height = " + to_string(height) +
            ", width = " + to_string(width) + ", area = " + to_string(height*width) + ")";
    }

    bool operator>=(Rectangle& rect) {
        return Area() >= rect.Area();
    }

    bool operator<(Rectangle& rect) {
        return !(*this >= rect);
    }

    void operator-=(double n) {
        if (min(height, width) < n) {
            return;
        }
        height -= n;
        width -= n;
    }


};


void insertionSort(Rectangle arr[], int n) {

    for (int i = 1; i < n; i++) {
        Rectangle key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].Area() < key.Area()) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    Rectangle* rectangles = new Rectangle[n];
    for (int i = 0; i < n; i++) {
        cout << "Rectangle " << i + 1 << endl;
        int height, width;
        cout << "Enter height: ";
        cin >> height;
        cout << "Enter width: ";
        cin >> width;

        rectangles[i] = Rectangle(height, width);
    }

    cout << endl << "Rectangles before sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << rectangles[i].toString() << endl;
    }

    insertionSort(rectangles, n);
    cout << endl << "Rectangles after sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << rectangles[i].toString() << endl;
    }

    double value;
    cout << endl << "Enter number that you want to remove from both sides of each rectangle: ";
    cin >> value;
    for (int i = 0; i < n; i++) {
        rectangles[i] -= value;
    }

    cout << endl << "Rectangles before sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << rectangles[i].toString() << endl;
    }

    insertionSort(rectangles, n);
    cout << endl << "Rectangles after sort: " << endl;
    for (int i = 0; i < n; i++) {
        cout << rectangles[i].toString() << endl;
    }

    return 0;
}
