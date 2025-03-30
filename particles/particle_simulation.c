#include <stdio.h>
#include <stdlib.h>
#define NUM_PARTICLES = 1

// Two dimensional particle vector
typedef struct {
    float x;
    float y;
 } Vector2;

// Two dimensional particle
typedef struct {
    Vector2 position;
    Vector2 velocity;
    float mass;
} Particle;

//global particle array
Particle particles[NUM_PARTICLES];

//Prints all the particles' position to the console
void print_particles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        Particle *particle = &particles[i];
        // particle, x-cord, y-cord
        printf("Particle[%i] (%.2f, %2f)\n", i, particle->position.x, particle->position.y);
    }
}

// initialises all particles with random positions, zero velocities and a 1kg mass
void init_particles() {
    for (int i =0; i < NUM_PARTICLES; i++) {
        // initializes  a random position to the particle ina 50x50 2d grid
        particles[i].position = (Vector2){arc4random_uniform(50), arc4random_uniform(50)};
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1.0f;
    }
}

// f(x) that applies g (mass * gravity acceleration * 9.81)
Vector2 ComputeForce(Particle *particle) {
    return (Vector2){0, particle->mass * -9.81}
    // -ive sign with 9.81 indicates that the weight is acting downwards
}
void RunSimulation() {
    
}