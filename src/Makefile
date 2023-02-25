OBJS= uimain.o tokenizer.o

# compiler flags.  -g for debug, -03 for optimization
CFLAGS=-g -O3

#first target is built ddefault
all:tokenizer

tokenizer.o: tokenizer.h
uimain.o: tokenizer.h 

tokenizer: $(OBJS)
	cc -o tokenizer $(CFLAGS) $(OBJS)

clean:
	rm -f *.o tokenizer

run:tokenizer
	./tokenizer
