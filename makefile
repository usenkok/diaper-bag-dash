#makefile for kelly usenko final project

CXX = g++

# Compiler flags

CXXFLAGS = -std=gnu++11
#CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

final: main.o game.o space.o patio.o mainfloor.o parentsroom.o kitchen.o kidsroom.o finaltesting.o livingroom.o bathroom.o helpers.o player.o item.o
	${CXX} ${CXXFLAGS} main.o game.o space.o patio.o mainfloor.o parentsroom.o kitchen.o kidsroom.o finaltesting.o livingroom.o bathroom.o helpers.o player.o item.o -o final

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

space.o: space.cpp space.hpp
	${CXX} ${CXXFLAGS} -c space.cpp

patio.o: patio.cpp patio.hpp	
	${CXX} ${CXXFLAGS} -c patio.cpp

game.o: game.cpp game.hpp
	${CXX} ${CXXFLAGS} -c game.cpp

parentsroom.o: parentsroom.cpp parentsroom.hpp
	${CXX} ${CXXFLAGS} -c parentsroom.cpp

kitchen.o: kitchen.cpp kitchen.hpp
	${CXX} ${CXXFLAGS} -c kitchen.cpp

kidsroom.o: kidsroom.cpp kidsroom.hpp
	${CXX} ${CXXFLAGS} -c kidsroom.cpp

finaltesting.o: finaltesting.cpp finaltesting.hpp
	${CXX} ${CXXFLAGS} -c finaltesting.cpp

livingroom.o: livingroom.cpp livingroom.hpp
	${CXX} ${CXXFLAGS} -c livingroom.cpp

mainfloor.o: mainfloor.cpp mainfloor.hpp
	${CXX} ${CXXFLAGS} -c mainfloor.cpp

bathroom.o: bathroom.cpp bathroom.hpp
	${CXX} ${CXXFLAGS} -c bathroom.cpp

helpers.o: helpers.cpp helpers.hpp
	${CXX} ${CXXFLAGS} -c helpers.cpp

player.o: player.cpp player.hpp
	${CXX} ${CXXFLAGS} -c player.cpp

item.o: item.cpp item.hpp
	${CXX} ${CXXFLAGS} -c item.cpp

clean:
	rm *.o final -f
