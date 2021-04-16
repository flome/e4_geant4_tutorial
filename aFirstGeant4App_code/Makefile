
build/aFirstGeant4App: $(BASE)/src/* $(BASE)/include/* build/Makefile
	cd build; make

build/Makefile: $(BASE)/CMakeLists.txt build
	cd build ; cmake ..

build:
	mkdir build

clean:
	rm -fr build ./aFirstGeant4App ./G4History.macro

.PHONY: clean run
