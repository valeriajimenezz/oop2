#include <iostream>
#include <memory>
#include "FieldZone.h"
#include "Drone.h"
#include "FieldManager.h"
#include "IrrigationRec.h"
#include "FertilizerRec.h"

int main() {
    try {
        // 1. Creat Zones
        FieldZone zone1("Z-01", ___, ___);  // insert values for nutrients and moisturize 
        FieldZone zone2("Z-02", ___, ___);

        // 2. Drone & Scanner
        Drone drone("D-01", "4K");
        drone.scanZone(zone1);
        drone.scanZone(zone2);
        drone.displayLog();

        // 3. Manager & Zones 
        FieldManager manager;
        manager.addZone(zone1);
        manager.addZone(zone2);

        // Recommendations
        manager.addRecommendation(std::make_unique<IrrigationRec>("Z-01", ___, ___));
        manager.addRecommendation(std::make_unique<FertilizerRec>("Z-02", ___, ___));

        // 5. Execution 
        std::cout << "\n Recommendations \n";
        manager.runAll();
        std::cout << "\n Details \n";
        manager.displayAll();

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
