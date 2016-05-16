CXX = g++
CXXFLAGS = -Wall -MMD
EXEC = a4q3
OBJECTS = main.o allcaps.o count.o doublewords.o dropfirst.o echo.o textprocess.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
