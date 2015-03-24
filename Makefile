CFLAGS=-std=c11

hbas: hbas.o tokenizer.o util.o

clean:
	rm -f *.o hbas.exe hbas
