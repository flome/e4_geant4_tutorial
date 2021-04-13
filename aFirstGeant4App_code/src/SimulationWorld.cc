
//global files
#include <string>

// local headers to include
#include "SimulationWorld.hh"

// classes to include from the Geant4 framework
#include "G4NistManager.hh"
#include "G4Material.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4VisAttributes.hh"
#include "G4UserLimits.hh"

#include "G4Color.hh"


// a constructor that does nothing except call its parent's constructor
SimulationWorld::SimulationWorld()
: G4VUserDetectorConstruction()
{
  // create the commands of the messenger
  DefineMaterials();
}

// empty destructor
SimulationWorld::~SimulationWorld()
{
}

void SimulationWorld::DefineMaterials()
{
  // the NIST manager is very helpful for material definition
  G4NistManager* nist = G4NistManager::Instance();

  // these are builtin an can be called like this
  // they are then stored in the material data base of the Geant4 engine, we retrieve them later
  nist->FindOrBuildMaterial("G4_AIR");
  nist->FindOrBuildMaterial("G4_WATER");

}


// this method is called when the run is initialized and builds the simulation world
G4VPhysicalVolume* SimulationWorld::Construct()
{

  //////////////////////////////////////////////////////////////////////////
  //////    world setup
  //////////////////////////////////////////////////////////////////////////

  // shape of the world
  // passing a reference name and HALF values of the edges
  // the world will be 10x10x10 m^3
  G4Box* world_shape = new G4Box("World", .5*m, .5*m, .5*m);

  // attach attributes to the world shape
  G4LogicalVolume* world_logic = new G4LogicalVolume(
    world_shape, //its shape
    G4Material::GetMaterial("G4_AIR"), //its material
    "World" //its name
  );
  // world object placed in the simulation
  G4VPhysicalVolume* world = new G4PVPlacement(
    0,                 // no rotation
    G4ThreeVector(),   // at (0,0,0) --> with reference to the mother volume! (in this case global)
    world_logic,       // its logical volume
    "World",  // some reference name
     0,                //its mother volume - aka none
     false,            //no boolean operation - not important here
     0,                //copy number - not important here
     true              //overlaps checking - not important here
   );
   world_logic->SetVisAttributes(G4Color::Grey());

   //////////////////////////////////////////////////////////////////////////
   //////   insert water phantom
   //////////////////////////////////////////////////////////////////////////
   // make water phantom 30x30x30 cm³
   G4Box* phantom_shape = new G4Box("WaterPhantom", 15*cm, 15*cm, 15*cm);

   // attach attributes to the world shape
   G4LogicalVolume* phantom_logic = new G4LogicalVolume(
     phantom_shape, //its shape
     G4Material::GetMaterial("G4_WATER"), //its material
     "WaterPhantom" //its name
   );
   phantom_logic->SetVisAttributes(G4Color(0,0,.8));

   // world object placed in the simulation
   new G4PVPlacement(
     0,                 // no rotation
     G4ThreeVector(),   // at (0,0,0) --> with reference to the mother volume! (in this case global)
     phantom_logic,       // its logical volume
     "WaterPhantom",  // some reference name
      world_logic,                //its mother volume - aka none
      false,            //no boolean operation - not important here
      0,                //copy number - not important here
      true              //overlaps checking - not important here
    );

   // the Construct() method always has to return the world physical volume
   return world;
}

void SimulationWorld::ConstructSDandField(){}
