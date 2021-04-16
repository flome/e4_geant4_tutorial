
aFirstGeant4App: build/aFirstGeant4App
	cp build/aFirstGeant4App .

build/aFirstGeant4App: src/* include/* build/Makefile
	cd build; make

build/Makefile: CMakeLists.txt build
	cd build ; cmake ..

build:
	mkdir build

clean:
	rm -fr build ./aFirstGeant4App ./G4History.macro

.PHONY: clean run
