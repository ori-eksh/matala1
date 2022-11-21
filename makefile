LIBLOOP = basicClassification.o advancedClassificationLoop.o
LIBREC = basicClassification.o advancedClassificationRecursion.o

all: loops recursives recursived loopd mains maindloop maindrec

loops: libclassloops.a

libclassloops.a: $(LIBLOOP)
	ar -rcs libclassloops.a $(LIBLOOP)

basicClassification.o: basicClassification.c NumClass.h
	gcc -Wall -g -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	gcc -Wall -g -c advancedClassificationLoop.c

recursives: libclassrec.a

libclassrec.a: $(LIBREC)
	ar rcs libclassrec.a $(LIBREC)

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	gcc -Wall -g -c advancedClassificationRecursion.c

recursived: libclassrec.so

libclassrec.so: $(LIBREC)
	gcc -fPIC -shared -o libclassrec.so $(LIBREC)

loopd: libclassloops.so

libclassloops.so: $(LIBLOOP)
	gcc -fPIC -shared -o libclassloops.so $(LIBLOOP)

mains: main.o libclassrec.a
	gcc -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	gcc -Wall -g -o maindloop main.o ./libclassloops.so

maindrec: main.o libclassrec.so
	gcc -Wall -g -o maindrec main.o ./libclassrec.so



main.o: main.c NumClass.h
	gcc -Wall -g -c main.c
clean:
	rm -f  *.o *.a *.so mains maindloop maindrec

