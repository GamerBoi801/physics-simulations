#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define NUM_PARTICLES 1

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

// global particle array
Particle particles[NUM_PARTICLES];

// Prints all the particles' position to the console
void print_particles() {
    for (int i = 0; i < NUM_PARTICLES; i++) {
        Particle *particle = &particles[i];
        // particle, x-cord, y-cord
        printf("Particle[%i] (%.2f, %.2f)\n", i, particle->position.x, particle->position.y);
    }
}

// Initializes all particles with random positions, zero velocities, and a 1kg mass
void init_particles() {
    srand(time(NULL));  // Seed the random number generator
    for (int i = 0; i < NUM_PARTICLES; i++) {
        // Initializes a random position to the particle in a 50x50 2D grid
        particles[i].position = (Vector2){(float)rand() / RAND_MAX * 50, (float)rand() / RAND_MAX * 50};
        // Initializes the velocity to zero
        particles[i].velocity = (Vector2){0, 0};
        particles[i].mass = 1.0f;
    }
}

// f(x) that applies g (mass * gravity acceleration * 9.81)
Vector2 ComputeForce(Particle *particle) {
    return (Vector2){0, particle->mass * -9.81};
    // -ive sign with 9.81 indicates that the weight is acting downwards
}

void RunSimulation() {
    float totalSimulationTime = 10; // simulation will run for 10secs
    float CurrentTime = 0; // current time && accumulates the time has passed
    float dt = 1; // each step takes one second
    
    while (CurrentTime < totalSimulationTime) {
        sleep(dt);
        printf("\nTime: %.0f seconds\n", CurrentTime + 1);
        
        for (int i = 0; i < NUM_PARTICLES; i++) {
            Particle *particle = &particles[i];
            
            // Calculates the force
            Vector2 force = ComputeForce(particle);
            
            // acceleration = force / mass using Newton's second law
            // F = m * a => a = F / m
            Vector2 acceleration = (Vector2){force.x / particle->mass, force.y / particle->mass};
            
            // Update the velocity
            particle->velocity.x += acceleration.x * dt;
            particle->velocity.y += acceleration.y * dt;

            particle->position.x += particle->velocity.x * dt;
            particle->position.y += particle->velocity.y * dt;

        }
        print_particles(); // print the particles' position after each second
        CurrentTime += dt;
    }
}

int main(void) {
    init_particles();
    RunSimulation();
    return 0;
}