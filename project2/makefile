compile-all:
	g++ -c Driver.cpp Simulation.cpp WorkPay.cpp
	g++ -o Driver.out -Wall Driver.o Simulation.o WorkPay.o
compile-simulation:
	g++ -c Simulation.cpp
compile-workpay:
	g++ -c Workpay.cpp
run:
	./Driver.out
clean:
	rm *.o
