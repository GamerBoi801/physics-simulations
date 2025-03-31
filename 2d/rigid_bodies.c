#define NUM_RIGID_BODIES 1

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


typedef strcut {
    float width;
    float height;
    float mass;
    float moment_of_inertia;
} BoxShape;

//calc inertia of a boc shape and stores it in moment_of_inertia var
void CalculateInertia(BoxShape *BoxShape) {
    float m = BoxShape->mass;
    float w = BoxShape->width;
    float h = BoxShape->height;

    // moment of inertial for a cuboid about is central axis  I = m(w^2 + h^2) / 12
    BoxShape->moment_of_inertia = (m * (w * w + h * h)) / 12;

}

//2d rigid body
typedef struct {
    Vector2 position;
    Vector2 linearVelocity;
    float angle;
    float angularVelocity;
    Vector2 force;
    float torque;
    BoxShape shape;
} RigidBody;

RigidBody rigidBodies[NUM_RIGID_BODIES];

// Prints the position and angle of each body on the output.
void PrintRigidBodies() {
    for (int i = 0; i < NUM_RIGID_BODIES; ++i) {
        RigidBody *rigidBody = &rigidBodies[i];
        printf("body[%i] p = (%.2f, %.2f), a = %.2f\n", i, rigidBody->position.x, rigidBody->position.y, rigidBody->angle);
    }
}

// TODO