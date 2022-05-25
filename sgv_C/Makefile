FLAGS = -w -g -Wall -ansi -D_GNU_SOURCE
PKG = `pkg-config --cflags --libs glib-2.0`
COMPILER = gcc
INCLUDES= includes
SRC = src
OBJ = obj

all:
	make produto
	make produtos
	make cliente
	make clientes
	make venda
	make factAux
	make fact
	make factTotal
	make auxStructs
	make auxStructsFact
	make auxStructsVendaFilial
	make auxFilial
	make filial
	make vendaFilial
	make queries
	make auxQuery10
	make auxQuery11
	make query11
	make query10
	make auxQuery12
	make query12
	make sgv
	make interface
	make main
	make leitura

produto: $(SRC)/produto.c $(INCLUDES)/produto.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/produto.o $(PKG) -c $(SRC)/produto.c

produtos: $(SRC)/produtos.c $(INCLUDES)/produtos.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/produtos.o $(PKG) -c $(SRC)/produtos.c

cliente: $(SRC)/cliente.c $(INCLUDES)/cliente.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/cliente.o $(PKG) -c $(SRC)/cliente.c

clientes: $(SRC)/clientes.c $(INCLUDES)/clientes.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/clientes.o $(PKG) -c $(SRC)/clientes.c

venda: $(SRC)/venda.c $(INCLUDES)/venda.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/venda.o $(PKG) -c $(SRC)/venda.c

factAux: $(SRC)/factAux.c $(INCLUDES)/factAux.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/factAux.o $(PKG) -c $(SRC)/factAux.c

fact: $(SRC)/fact.c $(INCLUDES)/fact.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/fact.o $(PKG) -c $(SRC)/fact.c

factTotal: $(SRC)/factTotal.c $(INCLUDES)/factTotal.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/factTotal.o $(PKG) -c $(SRC)/factTotal.c

vendaFilial: $(SRC)/vendaFilial.c $(INCLUDES)/vendaFilial.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/vendaFilial.o $(PKG) -c $(SRC)/vendaFilial.c

auxFilial: $(SRC)/auxFilial.c $(INCLUDES)/auxFilial.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxFilial.o $(PKG) -c $(SRC)/auxFilial.c

filial: $(SRC)/filial.c $(INCLUDES)/filial.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/filial.o $(PKG) -c $(SRC)/filial.c

auxQuery10: $(SRC)/auxQuery10.c $(INCLUDES)/auxQuery10.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxQuery10.o $(PKG) -c $(SRC)/auxQuery10.c

auxQuery11: $(SRC)/auxQuery11.c $(INCLUDES)/auxQuery11.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxQuery11.o $(PKG) -c $(SRC)/auxQuery11.c

query11: $(SRC)/query11.c $(OBJ)/queries.o $(OBJ)/auxQuery11.o
	$(COMPILER) $(FLAGS) -o $(OBJ)/query11.o $(PKG) -c $(SRC)/query11.c	

query10: $(SRC)/query10.c $(OBJ)/queries.o $(OBJ)/auxQuery10.o
	$(COMPILER) $(FLAGS) -o $(OBJ)/query10.o $(PKG) -c $(SRC)/query10.c

auxQuery12: $(SRC)/auxQuery12.c $(INCLUDES)/auxQuery12.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxQuery12.o $(PKG) -c $(SRC)/auxQuery12.c

query12: $(SRC)/query12.c $(OBJ)/queries.o $(OBJ)/auxQuery12.o
	$(COMPILER) $(FLAGS) -o $(OBJ)/query12.o $(PKG) -c $(SRC)/query12.c

auxStructs: $(SRC)/auxStructs.c $(INCLUDES)/auxStructs.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxStructs.o $(PKG) -c $(SRC)/auxStructs.c

auxStructsFact: $(SRC)/auxStructsFact.c $(INCLUDES)/auxStructsFact.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxStructsFact.o $(PKG) -c $(SRC)/auxStructsFact.c

auxStructsVendaFilial: $(SRC)/auxStructsVendaFilial.c $(INCLUDES)/auxStructsVendaFilial.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/auxStructsVendaFilial.o $(PKG) -c $(SRC)/auxStructsVendaFilial.c

sgv: $(SRC)/sgv.c $(INCLUDES)/sgv.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/sgv.o $(PKG) -c $(SRC)/sgv.c

interface: $(SRC)/interface.c $(INCLUDES)/interface.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/interface.o $(PKG) -c $(SRC)/interface.c

queries: $(SRC)/queries.c $(OBJ)/clientes.o $(OBJ)/produtos.o $(OBJ)/factTotal.o $(OBJ)/auxStructs.o
	$(COMPILER) $(FLAGS) -o $(OBJ)/queries.o $(PKG) -c $(SRC)/queries.c	

main: $(SRC)/main.c $(OBJ)/clientes.o $(OBJ)/produtos.o $(OBJ)/factTotal.o $(OBJ)/auxStructs.o
	$(COMPILER) $(FLAGS) -o $(OBJ)/main.o $(PKG) -c $(SRC)/main.c	

leitura: $(SRC)/main.c $(OBJ)/main.o $(OBJ)/queries.o $(OBJ)/query10.o $(OBJ)/auxQuery10.o $(OBJ)/query11.o $(OBJ)/auxQuery11.o $(OBJ)/query12.o $(OBJ)/auxQuery12.o $(OBJ)/auxStructs.o $(OBJ)/auxStructsFact.o $(OBJ)/auxStructsVendaFilial.o $(OBJ)/produto.o $(OBJ)/produtos.o $(OBJ)/cliente.o $(OBJ)/clientes.o $(OBJ)/venda.o $(OBJ)/factAux.o $(OBJ)/fact.o $(OBJ)/factTotal.o $(OBJ)/auxFilial.o $(OBJ)/vendaFilial.o $(OBJ)/filial.o $(OBJ)/sgv.o $(OBJ)/interface.o
	$(COMPILER) $(FLAGS) $(OBJ)/queries.o $(OBJ)/query10.o $(OBJ)/auxQuery10.o $(OBJ)/query11.o $(OBJ)/auxQuery11.o $(OBJ)/query12.o $(OBJ)/auxQuery12.o $(OBJ)/auxStructs.o $(OBJ)/auxStructsFact.o $(OBJ)/auxStructsVendaFilial.o $(OBJ)/produto.o $(OBJ)/produtos.o $(OBJ)/cliente.o $(OBJ)/clientes.o $(OBJ)/venda.o $(OBJ)/factAux.o $(OBJ)/fact.o $(OBJ)/factTotal.o $(OBJ)/auxFilial.o $(OBJ)/vendaFilial.o $(OBJ)/filial.o $(OBJ)/sgv.o $(OBJ)/interface.o $(OBJ)/main.o $(PKG) -o prog

memcheck: 
	valgrind --leak-check=yes ./prog 1

clean:
	rm -rf $(OBJ)/*.o prog
