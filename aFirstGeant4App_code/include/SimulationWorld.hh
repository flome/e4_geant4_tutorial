
#ifndef SimulationWorld_h
#define SimulationWorld_h 1

// classes to include from the Geant4 framework
#include "G4VUserDetectorConstruction.hh"

class SimulationWorld : public G4VUserDetectorConstruction
{
  public:
    SimulationWorld();
    virtual ~SimulationWorld();

    // this is called, when run is initialized
    // it should return the "simulation world"
    virtual G4VPhysicalVolume* Construct();
    void ConstructSDandField();
    void DefineMaterials();

};

#endif
