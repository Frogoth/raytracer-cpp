##
## EPITECH PROJECT, 2024
## B-OOP-400-STG-4-1-raytracer-tom.rudolf
## File description:
## Makefile
##

SRC		=	main.cpp \
			src/Config/ConfigParser.cpp \
			src/Lights/Ambient.cpp \
			src/Lights/Diffuse.cpp \
			src/Lights/Point.cpp \
			src/Math/Vector3D.cpp \
			src/Primitives/Sphere.cpp \
			src/Primitives/Plane.cpp \
			src/RayTracer/Camera.cpp \
			src/RayTracer/Color.cpp \
			src/RayTracer/Ray.cpp \
			src/RayTracer/Scene.cpp

NAME	=	raytracer

CPPFLAGS	=	-std=c++20 -lconfig++

OBJ		=	$(SRC:.cpp=.o)

CC		=	g++

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CPPFLAGS)

debug:	CPPFLAGS+=-Werror -g -Wall -Wextra
debug:	all

clean:
	rm -f vgcore.*
	rm -f *~
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
