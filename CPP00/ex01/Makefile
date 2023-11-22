NAME		= phonebook
CXX			= c++
CXXFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS_DIR	= srcs
OBJS_DIR	= objs

SRCS 		= $(wildcard $(SRCS_DIR)/*.cpp)
OBJS 		= $(patsubst $(SRCS_DIR)/%.cpp,$(OBJS_DIR)/%.o,$(SRCS))

INCL		= incl

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I $(INCL)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re