#include <iostream>
#include <memory>
#include "FieldZone.h"
#include "Drone.h"
#include "FieldManager.h"
#include "IrrigationRec.h"
#include "FertilizerRec.h"

int main() {
    try {
        // 1. Create Zones
        FieldZone zone1("Z-01", 20.0, 45.0);  
        FieldZone zone2("Z-02", 75.0, 15.0);  

        // 2. Drone & Scanner
        Drone drone("D-01", "4K");
        drone.scanZone(zone1);
        drone.scanZone(zone2);
        drone.displayLog();

        // 3. Manager & Zones
        FieldManager manager;
        manager.addZone(zone1);
        manager.addZone(zone2);

        // 4. Recommendations
        // 4. Recommendations
		manager.addRecommendation(std::unique_ptr<IrrigationRec>(new IrrigationRec("Z-01", 3, 50.0)));
		manager.addRecommendation(std::unique_ptr<FertilizerRec>(new FertilizerRec("Z-02", 2, 12.5)));

        // 5. Execution
        std::cout << "\n--- Recommendations ---\n";
        manager.runAll();
        std::cout << "\n--- Details ---\n";
        manager.displayAll();

    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
