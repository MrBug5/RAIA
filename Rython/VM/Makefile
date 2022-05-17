CC = g++
CFLAGS = -c -g
LDFLAGS = -g
SRC = ${wildcard src/*.cpp}
TEST_SRC = ${wildcard test-files/*.cpp}
HDR = ${wildcard include/*.hpp}
OBJ = ${SRC:.cpp=.o}
TEST_OBJ = ${TEST_SRC:.cpp=.o}
EXEC = rython
TEST_EXEC = rython-test

all: ${SRC} ${OBJ} ${EXEC}

testing: ${TEST_SRC} ${TEST_OBJ} ${TEST_EXEC}

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o: %.cpp ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm src/*.o ${EXEC}
	
