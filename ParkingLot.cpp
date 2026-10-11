
#include <iostream>
#include <string>
using namespace std;

class Vehicle {
    string regNo;

public:
    Vehicle(string regNo) : regNo(regNo) {}

    string getRegNo() {
        return regNo;
    }
};

class ParkingSpot {
    int spotNo;
    bool isOccupied;
    Vehicle* vehicle;

public:
    ParkingSpot(int spotNo)
        : spotNo(spotNo), isOccupied(false), vehicle(nullptr) {}

    void parkVehicle(Vehicle* v) {
        if (!isOccupied && v != nullptr) {
            vehicle = v;
            isOccupied = true;
            cout << "Vehicle parked in spot "
                 << spotNo << endl;
        } else {
            cout << "Spot is already occupied!" << endl;
        }
    }

    void unparkVehicle() {
        if (isOccupied) {
            cout << "Vehicle "
                 << vehicle->getRegNo()
                 << " removed from spot "
                 << spotNo << endl;

            vehicle = nullptr;
            isOccupied = false;
        } else {
            cout << "Spot is already empty!" << endl;
        }
    }

    bool isSpotOccupied() {
        return isOccupied;
    }
};

class ParkingLot {
    ParkingSpot spot;

public:
    ParkingLot(ParkingSpot s) : spot(s) {}

    void park(Vehicle* v) {
        spot.parkVehicle(v);
    }

    void unpark() {
        spot.unparkVehicle();
    }

    bool isAvailable() {
        return !spot.isSpotOccupied();
    }
};

int main() {
    Vehicle car("UP65AB1234");
    ParkingSpot spot1(1);

    spot1.parkVehicle(&car);

    cout << "Available: "
         << (!spot1.isSpotOccupied() ? "Yes" : "No")
         << endl;

    spot1.unparkVehicle();

    cout << "Available: "
         << (!spot1.isSpotOccupied() ? "Yes" : "No")
         << endl;

    return 0;
}
