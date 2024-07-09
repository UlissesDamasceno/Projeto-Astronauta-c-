# Compilador C++ (ajuste conforme necessário)
CC = g++ 

# Opções de compilação (ajuste conforme necessário)
CFLAGS = -Wall -g

# Nome do executável final
TARGET = Projeto_Astronauta.exe

# Lista de arquivos de origem
SRCS = main.cpp Astronauta.cpp voo.cpp Atribuir_astronauta.cpp Cadastro_de_Astronautas.cpp Desatribuir_Astronauta.cpp Explodir.cpp gerenciador.cpp Lancar_voo.cpp 

# Lista de arquivos objeto (gerados a partir dos arquivos de origem)
OBJS = $(SRCS:.cpp=.o)

# Regra padrão: compila todos os arquivos e gera o executável
all: $(TARGET)

# Regra para gerar o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra genérica para compilar arquivos objeto
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Regra para limpar os arquivos objeto e o executávelmain.cpp Astronauta.cpp voo.cpp Atribuir_astronauta.cpp Cadastro_de_Astronautas.cpp Desatribuir_Astronauta.cpp Explodir.cpp gerenciador.cpp Lancar_voo.cpp 

clean:
	del $(OBJS) $(TARGET)