#ifndef SIMULATION_H
#define SIMULATION_H

class Simulation {
  public:
    void runOneGame();

  private:
    void moveTortoise(unsigned int *ptrTurtle);
    void moveHare(unsigned int *ptrHare);
};

#endif
