##
## EPITECH PROJECT, 2019
## PSU_2019_malloc
## File description:
## Makefile
##


CXX			=	g++

SRC			=	main.cpp	\
				Circuit.cpp \
				Arguments.cpp \
				Factory.cpp \
				Parser.cpp \
				Simulator.cpp \
				TerminalInput.cpp \
				Component/AChipset.cpp \
				Component/Pins.cpp \
				Component/Component2716/Component2716.cpp \
				Component/Component4001/Component4001.cpp \
				Component/Component4008/Component4008.cpp \
				Component/Component4011/Component4011.cpp \
				Component/Component4013/Component4013.cpp \
				Component/Component4017/Component4017.cpp \
				Component/Component4030/Component4030.cpp \
				Component/Component4040/Component4040.cpp \
				Component/Component4069/Component4069.cpp \
				Component/Component4071/Component4071.cpp \
				Component/Component4081/Component4081.cpp \
				Component/Component4094/Component4094.cpp \
				Component/Component4514/Component4514.cpp \
				Component/Component4801/Component4801.cpp \
				Component/SimpleComponent/ComponentClock.cpp \
				Component/SimpleComponent/ComponentFalse.cpp \
				Component/SimpleComponent/ComponentInput.cpp \
				Component/SimpleComponent/ComponentOutput.cpp \
				Component/SimpleComponent/ComponentTrue.cpp \
				Error/DoesNotExistException.cpp \
				Error/NotFoundException.cpp \

OBJ			=	$(SRC:.cpp=.o)

NAME		=	nanotekspice

CP			=	cp

RM			=	rm -f

CXXFLAGS		=	-Wall -Wextra -g3

CPPFLAGS	=	-IComponent -IError -IComponent/Component2716 -IComponent/Component4001 -IComponent/Component4011 -IComponent/Component4017 -IComponent/Component4030 -IComponent/Component4040 -IComponent/Component4071 -IComponent/Component4008 -IComponent/Component4013 -IComponent/Component4069 -IComponent/Component4081 -IComponent/Component4094 -IComponent/Component4514 -IComponent/Component4801 -IComponent/SimpleComponent

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CXX) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
