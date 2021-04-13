BASE  = aFirstGeant4App_code
BUILD = $(BASE)/build


aFirstGeant4App: $(BUILD)/aFirstGeant4App macros
	cp $(BUILD)/aFirstGeant4App .

run: aFirstGeant4App
		./aFirstGeant4App

macros: $(BASE)/macros/*.mac
	cp -r $(BASE)/macros .

$(BUILD)/aFirstGeant4App: $(BASE)/src/* $(BASE)/include/* $(BUILD)/Makefile
	cd $(BUILD); make

$(BUILD)/Makefile: $(BASE)/CMakeLists.txt $(BUILD)
	cd $(BUILD) ; cmake ..

$(BUILD):
	mkdir $(BUILD)

clean:
	rm -fr $(BUILD) macros ./aFirstGeant4App ./G4History.macro

.PHONY: clean run 
