
// local headers to include
#include "ActionInitializations.hh"
#include "PrimaryGenerator.hh"

// classes to include from the Geant4 framework
#include "G4VUserActionInitialization.hh"

ActionInitializations::ActionInitializations()
: G4VUserActionInitialization()
{}

ActionInitializations::~ActionInitializations()
{}

void ActionInitializations::Build() const
{
  SetUserAction(new PrimaryGenerator);
}
