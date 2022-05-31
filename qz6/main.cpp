#include <iostream>
#include <string>

using namespace std;

class Clock{
    protected:
    int hour;
    int minute;
    int second;
    string meridian;
    public:
    Clock(int x, int y, int z, string s) {
        hour = x;
        minute = y;
        second = z;
        meridian = s;
    };
    void display() {
            cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
        }
};    
class StandardClock : Clock {
    public:
    StandardClock(int x, int y, int z, string s) : Clock(x, y, z, s) {
        hour = x;
        minute = y;
        second = z;
        meridian = s;
        };
    void display() {
            if(meridian == "AM") {
            meridian = "上午";
            cout << meridian << hour << ":" << minute << ":" << second << endl;
            }else{
            meridian = "下午";
            cout << meridian << hour << ":" << minute << ":" << second << endl;
        }    
    }
};

class MilitaryClock : Clock {
    public:
    MilitaryClock(int x, int y, int z, string s) : Clock(x, y, z, s) {
        minute = y;
        second = z;
        meridian = s;
        if (s == "PM") {
            hour += 12;
        }
    };
    void display() {
        cout << hour << ":" << minute << ":" << second << endl;
    }
};

int main() {
    Clock cc(10, 25, 43, "AM");
    StandardClock sc(10, 25, 43, "AM");
    MilitaryClock mc(10, 25, 43, "PM");
    cc.display();
    sc.display();
    mc.display();
    return 0;
}
