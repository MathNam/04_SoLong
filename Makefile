#______________________________________________________________________________#
############################### Target Names ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Name
NAME	= ./so_long
PROJECT_NAME = So_long

#______________________________________________________________________________#
############################### Compiler #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Compiler	
CC = cc

# Compiler Flags
CFLAGS = -Wall -Wextra -Werror

#______________________________________________________________________________#
############################### Libraries ######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Libft
LIB_DIR		= ./libft
LIBFT		= $(LIB_DIR)/libft.a
LDFLAGS 	+= -L $(LIB_DIR) -lft

# MinilibX
MLX_DIR		= ./MinilibX
MLX			= $(MLX_DIR)/libmlx.a
LDFLAGS 	+= -L $(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

#______________________________________________________________________________#
############################### Print Variables ################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

# Reset
NC = \033[0m

# Colors
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RED = \033[0;31m
PURPLE = \033[0;35m
CYAN = \033[0;36m
BLACK = \033[0;30
WHITE = \033[0;37m

# Colors
BYELLOW = \033[1;33m
BGREEN = \033[1;32m
BBLUE = \033[1;34m
BRED = \033[1;31m
BPURPLE = \033[1;35m
BCYAN = \033[1;36m
BBLACK = \033[1;30m
BWHITE = \033[1;37m

# One Line Output
OL =\e[1A\r\033[K

#______________________________________________________________________________#
############################### Includes #######################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

INC_DIR = ./inc
INCLUDES += -I $(INC_DIR)
INCLUDES += -I $(LIB_DIR)/inc
INCLUDES += -I $(MLX_DIR)

#______________________________________________________________________________#
############################### Headers ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

HEADER += so_long.h
HEADER += mlx.h

vpath %.h $(INC_DIR)

#______________________________________________________________________________#
############################### Path Sources ###################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS_DIR = ./srcs

#______________________________________________________________________________#
############################### Sources ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

SRCS += error.c
SRCS += exit_ft.c
SRCS += so_long_utils.c
SRCS += map_error.c
SRCS += map_graphics.c
SRCS += init_player.c
SRCS += init_game.c
SRCS += render.c
SRCS += move_count.c
SRCS += animation.c
SRCS += play.c
SRCS += move.c
SRCS += menu.c
SRCS += so_long.c

#______________________________________________________________________________#
############################### Attribution ####################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

vpath %.c $(SRCS_DIR)

#______________________________________________________________________________#
############################### Objects ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

OBJS_DIR = ./objs
OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(SRCS))
CHK_OBJS = $(patsubst %.c, $(OBJS_DIR)/%.o, $(CHK_SRCS))

#______________________________________________________________________________#
############################### Counter ########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

TOTAL	= $(words $(SRCS) $(CHK_SRCS))
COUNT	= 0

#______________________________________________________________________________#
############################### Rules ##########################################
#‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾#

#_____Build_____#
all: $(MLX) $(LIBFT) $(NAME)
	@echo "--▶ $(BGREEN)all\t$(GREEN)done ✅$(NC)"
	@echo "--------------------------------------------------"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ $(LDFLAGS) $(INCLUDES) -o $@
    #-----Output-----#
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)All files compiled$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT)
	@echo "▶$(BGREEN)$(NAME)\t$(GREEN)Executable created 🆗\n$(NC)"

$(OBJS): $(OBJS_DIR)/%.o: %.c | $(LIBFT) $(OBJS_DIR) where
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
    #-----Output-----#
	@if [ $(COUNT) = 0 ]; then echo ""; fi
	@$(eval COUNT=$(shell echo $$(($(COUNT)+1))))
	@$(eval PERCENT:=$(shell echo $$((100*$(COUNT)/$(TOTAL)))))
	@printf "$(OL)$(BCYAN)[%2d/%2d] %3d%%\t$(CYAN)Compiling %s$(NC)\n" $(COUNT) $(TOTAL) $(PERCENT) $<

# Libraries
$(LIBFT):
	@make --no-print-directory all -C $(LIB_DIR)

$(MLX):
	@printf "$(OL)$(BCYAN)Compiling MinilibX...$(NC)\n"
	@make -s -C $(MLX_DIR)
	@printf "$(BGREEN)MinilibX\t$(GREEN) ready! ✅$(NC)\n"

# Directories
$(OBJS_DIR):
	@mkdir $@

bonus: all

#_____Clean_____#
clean: lclean where_c
	@rm -rf $(OBJS_DIR)
    #-----Output-----#
	@echo "▶ $(BYELLOW)clean $(YELLOW)Object files removed from $(PROJECT_NAME) ⭕$(NC)"
	@echo "--▶ $(BYELLOW)clean$(YELLOW) done ✅$(NC)"

# Libraries Clean
lclean:
	@make --no-print-directory clean -C $(LIB_DIR)
	@make --no-print-directory clean -sC $(MLX_DIR)

fclean: clean
	@rm -f $(LIBFT)
	@rm -f $(MLX)
	@rm -f $(NAME)
    #-----Output-----#
	@echo "▶ $(BRED)fclean $(RED)libft.a removed ❌$(NC)"
	@echo "▶ $(BRED)fclean $(RED)libmlx.a removed ❌$(NC)"
	@echo "\t$(RED)$(NAME) removed ❌$(NC)"
	@echo "--▶ $(BRED)fclean$(RED) done ✅$(NC)"

# Current Make
where_c:
	@echo "$(BBLACK)>$(PROJECT_NAME)$(NC)"

where:
	@echo "$(BBLACK)>$(PROJECT_NAME)$(NC)"

re: fclean all

.PHONY: all clean fclean re
