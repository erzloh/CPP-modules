NAME		= RPN
CXX			= c++
CXXFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS 		= $(wildcard $(SRCS_DIR)/*.cpp)
OBJS 		= $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))

INCL		= incl

# Farbdefinitionen
GREEN		= \033[0;32m
RED			= \033[0;31m
CYAN		= \033[0;36m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)Compilation completed successfully!$(RESET)"
	@echo "To run the program, use: ./$(NAME) <RPN expression>"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCL)
	@echo "$(CYAN)Compiled:$(RESET) $<"

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED)Objects removed.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Executable removed.$(RESET)"

re: fclean all

debug: CXXFLAGS += -D DEBUG
debug: re
	@echo "$(RED)DEBUG MODE"

.PHONY: all clean fclean re
