RED			= 	\e[31;5;118m
GREEN		=	\e[38;5;118m
RESET		=	\e[0m
_SUCCESS	=	$(GREEN)SUCCESS$(RESET)
REMOV		=	$(RED)REMOVED$(RESET)

NAME = Btc

src =  BitcoinExchange.cpp main.cpp

HDR = BitcoinExchange.hpp

CXX = c++

CFLAGS = -Wall -Werror -Wextra -std=c++98

obj = $(src:.cpp=.o)

%.o : %.cpp ${HDR}
	@${CXX} ${CFLAGS} -c $< -o $@

all : $(NAME)

$(NAME) : $(obj)
	@${CXX} ${CFLAGS} $(obj) -o $(NAME)
	@printf "$(_SUCCESS) $(NAME) is ready!.\n"

clean :
	@rm -f $(obj)

fclean : clean
	@rm -f $(NAME)
	@printf "$(REMOV) $(NAME) is Removed!.\n"

re : fclean all