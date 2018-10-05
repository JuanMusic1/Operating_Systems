all: hilo hilo2 hilo3

hilo: 
	gcc -o hilo hilos.c -lpthread

hilo2: 
	gcc -o hilo2 hilos2.c -lpthread

hilo3: 
	gcc -o factPH factoresPHilos.c -lpthread
	
clean:
	rm -f hilo hilo2 factPH

debug:
	gcc -g hilos.c

debug2:
	gcc -g hilos2.c

debug3:
	gcc -g factoresPHilos.c