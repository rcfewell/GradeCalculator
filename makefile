P2.out : Date.o Grade.o Project2.o
	g++ -o P2.out Date.o Grade.o Project2.o

Date.o : Date.h Date.cpp
	g++ -g -c Date.cpp

Grade.o : Date.h Grade.h Grade.cpp
	g++ -g -c Grade.cpp

Project2.o : Date.h Grade.h Project2.cpp
	g++ -g -c Project2.cpp

clean :
	rm *.o P2.out

run : ./P2.out
	clear
	./P2.out ../p2.input ../p2.output
	more ../p2.output

submit : Project2.cpp Grade.h Grade.cpp Date.h Date.cpp makefile
	rm -rf fewellP2
	mkdir fewellP2
	cp Project2.cpp fewellP2
	cp Grade.h fewellP2
	cp Grade.cpp fewellP2
	cp Date.h fewellP2
	cp Date.cpp fewellP2
	cp makefile fewellP2/makefile
	cp README.txt fewellP2
	tar cfvz fewellP2.tgz fewellP2
	cp fewellP2.tgz ~tiawatts/cs215drop
