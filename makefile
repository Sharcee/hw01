CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic
NAME = hw01

all: $(NAME).x

$(NAME).x:
	$(CC) $(CFLAGS) -o $(NAME).x $(NAME).cpp

run:
	clear
	make
	./$(NAME).x < test > simon_output
	./duan < test > duan_output
	sdiff simon_output duan_output

clean:
	rm -r $(NAME).x
