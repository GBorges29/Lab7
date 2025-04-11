default:
	gcc -Wall -o prog main.c input.c vector3d.c -lm
debug:
	gcc -Wall -o prog -g main.c input.c vector3d.c -lm
clean:
	rm -f prog
