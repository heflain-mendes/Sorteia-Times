ifeq ($(OS),Windows_NT)
    uname_S := Windows
else
    uname_S := $(shell uname -s)
endif

ifeq ($(uname_S), Windows)
    TIPOSISTEMA := win
endif
ifeq ($(uname_S), Linux)
    TIPOSISTEMA := lin
endif

CC := gcc -o 

CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -pedantic

CAMINHO := ./source/$(TIPOSISTEMA)

RM := rm -rf 

all: programa clean
 
programa: main.o Time.o Lista.o sys.o
	@ echo 'Gerando o programa...'
	$(CC) programa $(CAMINHO)/main.o $(CAMINHO)/Time.o $(CAMINHO)/Lista.o $(CAMINHO)/sys.o
 
main.o: $(CAMINHO)/main.c $(CAMINHO)/Time.h $(CAMINHO)/Lista.h $(CAMINHO)/sys.h
	@ echo 'Gerando main.o...'
	$(CC) $(CAMINHO)/main.o $(CAMINHO)/main.c $(CC_FLAGS)
 
Time.o: $(CAMINHO)/Time.c $(CAMINHO)/Time.h
	@ echo 'Gerando Time.o...'
	$(CC) $(CAMINHO)/Time.o $(CAMINHO)/Time.c $(CC_FLAGS)

Lista.o: $(CAMINHO)/Lista.c $(CAMINHO)/Lista.h
	@ echo 'Gerando Lista.o...'
	$(CC) $(CAMINHO)/Lista.o $(CAMINHO)/Lista.c $(CC_FLAGS)

sys.o: $(CAMINHO)/sys.c $(CAMINHO)/sys.h
	@ echo 'Gerando sys.o...'
	$(CC) $(CAMINHO)/sys.o $(CAMINHO)/sys.c $(CC_FLAGS)
 
clean:
	@echo 'Limpando arquivos...'
	@$(RM) $(CAMINHO)/*.o