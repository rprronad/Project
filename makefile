OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
Steganography.exe: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o *.exe
