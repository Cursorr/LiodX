exec =  liodx.exe
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

test:
	echo Dir: $(USERNAME)

install:
	make
	copy .\liodx.exe C:\Users\$(USERNAME)\AppData\Local\Microsoft\WindowsApps

clean:
	rm *.exe
	rm *.o
	rm src\*.o