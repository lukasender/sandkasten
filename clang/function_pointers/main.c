#include <stdio.h>

// PREFACE:
//
// I'm perfectly aware that the code below does not make any sense and
// is way to complicate for such a simple task. But it should explain how to use
// function pointers.
//
// Here, a simple function which achieves the same thing:
/*
void DriveTesla(char* model, double speed) {
    printf("Driving a Model %s with %f km/h\n", model, speed);
}
*/

/* the function pointer */
typedef void (*fp)(double);

/**
The various implementations
*/

void DriveTeslaModelS(double speed) {
    printf("Driving a Model S with %f km/h\n", speed);
}

void DriveTeslaModelE(double speed) {
    printf("The Model E has just been announced. It isn't ready yet :(\n");
}

void DriveTeslaModelX(double speed) {
    printf("Driving a Model X with %f km/h\n", speed);
}

void UnknownModel(double speed) {
    printf("Sorry! The requested model has not yet been developed.\n");
}

/**
 * Decide which implementation should be used.
 * Return the function as a function pointer ('fp')
 */
fp DriveTesla(char model) {
    if (model == 'S') {
        return (*DriveTeslaModelS);
    }
    if (model == 'E') {
        return (*DriveTeslaModelE);
    }
    if (model == 'X') {
        return (*DriveTeslaModelX);
    }
    return (*UnknownModel);
}

int main(void) {
    // DriveTesla returns a function pointer. So, simply invoke it :)
    DriveTesla('S')(200.0);
    DriveTesla('E')(-1.0);
    DriveTesla('X')(180.0);
    DriveTesla('Y')(-1.0);
    // That's it. Easy, huh?
}
