NAME = phonebook 

INC = ./inc
HEADERS = $(INC)/Contact.hpp $(INC)/PhoneBook.hpp 

CC = g++
CFLAGS = -Wall -Werror -Wextra -g -std=c++98

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
NC = \033[0m

SRC_DIR = ./src
OBJ_DIR = ./bin

SRCS = $(SRC_DIR)/main.cpp 
#	$(SRC_DIR)/utils/utils.cpp \
#	$(SRC_DIR)/utils/utils2.cpp

OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)


all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "${YELLOW}Creating object directory $(OBJ_DIR)...${NC}"
	@mkdir -p $(OBJ_DIR)
	@echo "${GREEN}Object directory $(OBJ_DIR) created.${NC}"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

$(NAME): $(OBJS)
	@echo "${YELLOW} Linking $(NAME)...${NC}"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "${GREEN} $(NAME) executable created.${NC}"

clean:
	@echo "${YELLOW}Removing object files...${NC}"
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Object files removed.${NC}"

fclean:
	@echo "${YELLOW}Removing object files...${NC}"
	@rm -rf $(OBJ_DIR)
	@echo "${GREEN}Object files removed.${NC}"
	@echo "${YELLOW}Removing $(Name) executable...${NC}"
	@rm -f $(NAME)
	@echo "${GREEN}$(NAME) executable removed.${NC}"

re: fclean all

.PHONY: all clean fclean re phonebook
