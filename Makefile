CLIENT = client
SERVER = server
BONUS_CLIENT = client_bonus
BONUS_SERVER = server_bonus
CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_client.c ft_utile_minitalk.c
SRC1 = ft_server.c ft_utile_minitalk.c
SRC_CLIENT_BONUS = ft_client_bonus.c ft_utile_minitalk_bonus.c
SRC_SERVER_BONUS = ft_server_bonus.c ft_utile_minitalk_bonus.c
OBJECTS = $(SRC:.c=.o)
OBJECTS1 = $(SRC1:.c=.o)
OBJECTS_bonus_client = $(SRC_CLIENT_BONUS:.c=.o)
OBJECTS_bonus_server = $(SRC_SERVER_BONUS:.c=.o)
INCLUDES = minitalk.h\

all: $(CLIENT) $(SERVER)
bonus: $(BONUS_CLIENT) $(BONUS_SERVER)

client:	$(OBJECTS) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(CLIENT)
server:$(OBJECTS1) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS1) -o $(SERVER)

client_bonus:$(OBJECTS_bonus_client) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS_bonus_client) -o $(BONUS_CLIENT)
server_bonus:$(OBJECTS_bonus_server) $(INCLUDES)
	$(CC) $(CFLAGS) $(OBJECTS_bonus_server) -o $(BONUS_SERVER)

%.o : %.c $(INCLUDES)
	$(CC) $(CFLAGS) -o $@ -c $<
clean:
	rm -rf $(OBJECTS) $(OBJECTS1) $(OBJECTS_bonus_server) $(OBJECTS_bonus_client)

fclean:clean
	rm -rf $(CLIENT) $(SERVER)  $(BONUS_CLIENT) $(BONUS_SERVER)

re: fclean all
