
ENERGIES := 100 200 300 400 500
UNIT := MeV

results: $(foreach energy,$(ENERGIES), output/run_$(energy)_$(UNIT).csv)

output/run_%_$(UNIT).csv: macros/run_%_$(UNIT).mac output ./aFirstGeant4App
	./aFirstGeant4App $<

output:
	mkdir output

macros/run_%_$(UNIT).mac: macros/placeholder.mac
	sed "s|ENERGY|$* $(UNIT)|g; s|FILENAME|$*_$(UNIT)|g;" $< > $@

.PHONY: results
