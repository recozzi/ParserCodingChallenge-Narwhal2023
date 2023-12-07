NAME	:=	Parser

CC		:=	c++

FLAGS	:=	-g -Wall -Wextra -Werror -std=c++17 -pedantic

SRCS	:=	main.cpp			\
			Parser.cpp			\
			Base64Decode.cpp	\
			decodeImages.cpp	\
			printBox.cpp

OBJS_DIR	:=	objs/

SRCS_DIR	:=	srcs/

OBJS 		:=	$(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

# COLORS ================================================================= #

RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
WHITE	=	\033[0;97m

# ======================================================================== #

$(OBJS_DIR)%.o:	$(SRCS_DIR)%.cpp
			@mkdir -p $(dir $@)
			@$(CC) $(FLAGS) -c $< -o $@
			@echo "$(GREEN)Compiling:$(WHITE) $<"

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "$(YELLOW)- Program Name: $(WHITE)${NAME}"
	@echo "$(YELLOW)- Compiler: $(WHITE)${CC}"
	@echo "$(YELLOW)- Flags: $(WHITE)${FLAGS}"

clean:
	@rm $(NAME)
	@rm -rf $(OBJS_DIR)
	@rm -rf ../images
	@echo "$(RED)All object files removed.$(WHITE)"

re:	fclean all

.PHONY:	all clean fclean re

.SILENT:
