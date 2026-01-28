#include <stdio.h>

typedef struct {
    char name[50];
    int age;
    float height;
} Person;

static void PrintPerson(const Person* self){
    printf(
        "Name: %s\nAge: %d\nHeight: %.2f\n",
         self->name,
         self->age,
         self->height
    );
}

int GetAge(const Person* self){
    return self->age;
}

void SetAge(Person* self, int age){
    self->age = age;
}

int main(){
    Person p = {"Alice", 20, 178.2};
    PrintPerson(&p);
    SetAge(&p, GetAge(&p)+1);
    PrintPerson(&p);
    return 0;
}
