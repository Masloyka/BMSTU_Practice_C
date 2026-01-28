#include <stdio.h>
#include <string.h>
struct Person {
    char name[50];
    int age;
    float height;
};

int main(){
    struct Person student;
    student.age = 20;
    student.height = 1.78;
    strcpy(student.name, "Alice");

    struct Person p2 ={
        "Antron",
        22,
        162.1
    };
    struct Person group[3] ={
        {"Alice", 30, 156.0},
        {"Bob", 23, 178.1},
        {"Dm", 21, 765.1}
    };
    
    printf(
        "%s - %d years old\n",
        group[1].name,
        group[1].age
    );

    struct Person* p = &student;
    printf(
        "%s - %d years old\n",
        p->name,
        p->age
    );
    return 0;
}