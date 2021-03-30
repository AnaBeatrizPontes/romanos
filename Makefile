IDIR =./include
EDIR =./src
CC=g++
CFLAGS=-g -I$(IDIR) 

ODIR=obj

_DEPS = romano.hpp
_SOURCES = testa_romano
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romano.o testa_romano.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o 

exec: 
	./romano 

cppcheck:
	cppcheck $(IDIR)/romano.hpp $(EDIR)/romano.cpp $(EDIR)/testa_romano.cpp --enable=warning

valgrind:
	valgrind --leak-check=full ./romano

cpplint:
	cpplint $(IDIR)/romano.hpp $(EDIR)/romano.cpp $(EDIR)/testa_romano.cpp