all: hilo hilo2 hilo3

hilo: 
	gcc -o hilo hilos.c -lpthread

hilo2: 
	gcc -o hilo2 hilos2.c -lpthread

hilo3: 
	gcc -o factPH factoresPHilos.c -lpthread 

hilo3g: 
	gcc -o factPHG factoresPHG.c -lpthread -lm -lgmp

hilo4: 
	gcc -o factPHG fPrimosHilosGmp.c -lpthread -lm -lgmp
	
clean:
	rm -f hilo hilo2 factPH

debug:
	gcc -g hilos.c -lpthread

debug2:
	gcc -g hilos2.c -lpthread

debug3:
	gcc -g factoresPHilos.c -lpthread

debug4:
	gcc -g factoresPHG.c -lpthread -lgmp -lm