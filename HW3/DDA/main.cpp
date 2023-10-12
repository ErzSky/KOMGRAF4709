#include <iostream>
#include <cmath>

using namespace std;

void titikBerikut(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float xIncrement = static_cast<float>(dx) / static_cast<float>(steps);
    float yIncrement = static_cast<float>(dy) / static_cast<float>(steps);

    float x = static_cast<float>(x1);
    float y = static_cast<float>(y1);

    for (int i = 0; i <= steps; i++) {
        cout << "Pixel(" << static_cast<int>(x + 0.5) << ", " << static_cast<int>(y + 0.5) << ")" << endl;
        x += xIncrement;
        y += yIncrement;
    }
}

int main() {
    int x1, y1, x2, y2;

    cout << "Masukkan koordinat x1: ";
    cin >> x1;
    cout << "Masukkan koordinat y1: ";
    cin >> y1;
    cout << "Masukkan koordinat x2: ";
    cin >> x2;
    cout << "Masukkan koordinat y2: ";
    cin >> y2;

    titikBerikut(x1, y1, x2, y2);

    return 0;
}

