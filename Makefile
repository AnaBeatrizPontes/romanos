IDIR =./
CC=gcc
CFLAGS=-I$(IDIR) 

ODIR=obj

_DEPS = romano.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = romano.o testa_romano.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

romano: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)


clean:
	rm -f $(ODIR)/*.o 

exec: 
	./romano 

cppcheck:
	cppcheck romano.hpp romano.cpp teste_romano.cpp --enable=warning

valgrind:
	valgrind --leak-check=full ./romano

cpplint:
	cpplint romanos.cpp