OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Wno-uninitialized -Wno-sign-compare -std=c++11

program.exe: program.o
	g++ -o program.exe *.o $(OPCIONS)
	rm *.o
	
program.o: program.cc Cjt_Especies.hh Taula_de_distancies.hh Especie.hh Cjt_Clusters.hh
	g++ -c *.cc $(OPCIONS)






clean:
	rm *.o
	rm *.exe
	rm *.gch
