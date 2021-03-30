IDIR =./include
CC=g++
CFLAGS=-I$(IDIR) 

ODIR=obj

_DEPS = romano.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romano.o testa_romano.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f $(ODIR)/*.o 

exec: 
	./romano 

cppcheck:
	cppcheck $(IDIR)/romano.hpp romano.cpp teste_romano.cpp --enable=warning

valgrind:
	valgrind --leak-check=full ./romano

cpplint:
	cpplint $(IDIR)/romano.hpp romano.cpp teste_romano.cpp