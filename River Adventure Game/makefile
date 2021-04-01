main: main.o GamePlay.o Map.o Space.o BaitShop.o HikingTrail1.o FishingHole1.o HikingTrail2.o Truffles.o TrailOut.o Fisherman.o FishStringer.o Validate.o
	g++ -std=c++0x main.o GamePlay.o Map.o Space.o BaitShop.o HikingTrail1.o FishingHole1.o HikingTrail2.o Truffles.o TrailOut.o Fisherman.o FishStringer.o Validate.o -o main

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

GamePlay.o: GamePlay.cpp GamePlay.hpp
	g++ -std=c++0x -c GamePlay.cpp

Map.o: Map.cpp Map.hpp
	g++ -std=c++0x -c Map.cpp

Space.o: Space.cpp Space.hpp
	g++ -std=c++0x -c Space.cpp

BaitShop.o: BaitShop.cpp BaitShop.hpp
	g++ -std=c++0x -c BaitShop.cpp

HikingTrail1.o: HikingTrail1.cpp HikingTrail1.hpp
	g++ -std=c++0x -c HikingTrail1.cpp

FishingHole1.o: FishingHole1.cpp FishingHole1.hpp
	g++ -std=c++0x -c FishingHole1.cpp

HikingTrail2.o: HikingTrail2.cpp HikingTrail2.hpp
	g++ -std=c++0x -c HikingTrail2.cpp

Truffles.o: Truffles.cpp Truffles.hpp
	g++ -std=c++0x -c Truffles.cpp

TrailOut.o: TrailOut.cpp TrailOut.hpp
	g++ -std=c++0x -c TrailOut.cpp

Fisherman.o: Fisherman.cpp Fisherman.hpp
	g++ -std=c++0x -c Fisherman.cpp

FishStringer.o: FishStringer.cpp FishStringer.hpp
	g++ -std=c++0x -c FishStringer.cpp

Validate.o: Validate.cpp Validate.hpp
	g++ -std=c++0x -c Validate.cpp

clean:
	rm *.o main