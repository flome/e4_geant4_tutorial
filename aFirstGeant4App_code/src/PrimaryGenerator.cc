
// classes to include from the Geant4 framework
#include "G4GeneralParticleSource.hh"
#include "G4Event.hh"

// user defined classes to include
#include "PrimaryGenerator.hh"

// call parent constructor and empty initialize the particle source
// using the initializer list
PrimaryGenerator::PrimaryGenerator()
  : G4VUserPrimaryGeneratorAction(),
    gps(new G4GeneralParticleSource())
{}

// free the allocated memory
PrimaryGenerator::~PrimaryGenerator()
{
  delete gps;
}

// this is what happens when "BeamOn" is called
// simply tell the general particle source to generate the GeneratePrimaryVertex
void PrimaryGenerator::GeneratePrimaries(G4Event* anEvent){
  gps->GeneratePrimaryVertex(anEvent);
}
