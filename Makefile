make: obj/be6502.o obj/mos6502.o obj/mos65c22.o bin/rom
	g++ -Wall -o bin/be6502 obj/be6502.o obj/mos6502.o obj/mos65c22.o

obj/be6502.o: src/be6502.cc
	g++ -Wall -o obj/be6502.o -c src/be6502.cc

obj/mos6502.o: src/mos6502.cc src/mos6502.h
	g++ -Wall -o obj/mos6502.o -c src/mos6502.cc

obj/mos65c22.o: src/mos65c22.cc src/mos65c22.h
	g++ -Wall -o obj/mos65c22.o -c src/mos65c22.cc

bin/rom: src/*.s
	vasm6502_oldstyle -Fbin -dotdir src/*.s -o bin/rom

clean:
	rm -f obj/* bin/*
