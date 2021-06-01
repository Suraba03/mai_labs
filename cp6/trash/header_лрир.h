#ifndef structure_h
#define structure_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student_computer{
    char surname[20];
    int number_of_processors;
    char type_of_processors[20];
    int memory_size;
    char type_of_controller[20];
    int video_memory_size;
    char type_of_winchesters[20];
    int number_of_winchesters;
    int capacity_of_winchesters;
    int number_of_integrated_controllers;
    int number_of_external_devices;
    char oc[20];
} student_computer;

void make_dataset()
{
    FILE *f;
    char name[20];

    printf("Please,enter a name of your dataset: ");
    scanf("%s", name);

    if ((f = fopen(name, "w")) == NULL) {
        printf("Error,can't open a file!");
        getchar();
    }
    int number_of_records;

    printf("How much records you want do? ");
    scanf("%d", &number_of_records);

    student_computer pc;
    student_computer *data = &pc;

    for(int i = 0; i < number_of_records; i++) {
        printf("\t\tNEW STUDENT\t\t\n");
        printf("Please,enter surname: ");
        scanf("%s", pc.surname);
        printf("Please,enter number of processors: ");
        scanf("%d", &pc.number_of_processors);
        printf("Please,enter type of processor: ");
        scanf("%s", pc.type_of_processors);
        printf("Please,enter memory size: ");
        scanf("%d", &pc.memory_size);
        printf("Please,enter number of type of controller: ");
        scanf("%s", pc.type_of_controller);
        printf("Please,enter video memory size: ");
        scanf("%d", &pc.video_memory_size);
        printf("Please,enter type of winchesters: ");
        scanf("%s", pc.type_of_winchesters);
        printf("Please,enter number_of_winchesters: ");
        scanf("%d", &pc.number_of_winchesters);
        printf("Please,enter capacity of winchesters: ");
        scanf("%d", &pc.capacity_of_winchesters);
        printf("Please,enter number of integrated controllers: ");
        scanf("%d", &pc.number_of_integrated_controllers);
        printf("Please,enter number of external devices: ");
        scanf("%d", &pc.number_of_external_devices);
        printf("Please,enter name of operation system: ");
        scanf("%s", pc.oc);
        fwrite(data, sizeof(student_computer), 1, f);
    }
    fclose(f);
}
void add_to_dataset()
{
    FILE* f;
    char name[20];

    printf("Please,enter a name of your dataset: ");
    scanf("%s", name);
    
    if ((f = fopen(name, "a")) == NULL) {
        printf("Error,can't open a file!");
        getchar();
    }
    int number_of_records;

    printf("How much records you want do? ");
    scanf("%d", &number_of_records);

    student_computer pc;
    student_computer *data = &pc;
    
    for(int i = 0; i < number_of_records; i++) {
        printf("\t\tNEW STUDENT\t\t\n");
        printf("Please,enter surname: ");
        scanf("%s", pc.surname);
        printf("Please,enter number of processors: ");
        scanf("%d", &pc.number_of_processors);
        printf("Please,enter type of processor: ");
        scanf("%s", pc.type_of_processors);
        printf("Please,enter memory size: ");
        scanf("%d", &pc.memory_size);
        printf("Please,enter number of type of controller: ");
        scanf("%s", pc.type_of_controller);
        printf("Please,enter video memory size: ");
        scanf("%d", &pc.video_memory_size);
        printf("Please,enter type of winchesters: ");
        scanf("%s", pc.type_of_winchesters);
        printf("Please,enter number_of_winchesters: ");
        scanf("%d", &pc.number_of_winchesters);
        printf("Please,enter capacity of winchesters: ");
        scanf("%d", &pc.capacity_of_winchesters);
        printf("Please,enter number of integrated controllers: ");
        scanf("%d", &pc.number_of_integrated_controllers);
        printf("Please,enter number of external devices: ");
        scanf("%d", &pc.number_of_external_devices);
        printf("Please,enter name of operation system: ");
        scanf("%s", pc.oc);
        fwrite(data, sizeof(student_computer), 1, f);
    }
    fclose(f);
}
void print_dataset()
{
    FILE *f;

    printf("Enter a name of dataset which you want print: ");
    
    char name_dataset [20];
    
    scanf("%s", name_dataset);
    
    if ((f = fopen(name_dataset, "r")) == NULL) {
        printf("Error,can't open a file!");
        getchar();
    }
    student_computer pc_2;
    student_computer *data = &pc_2;
    
    int i = 0;
    
    printf("\nUSER SURNAME |N_PROCCE| TYPE_OF_PROCESSORS |MEM_SIZE|TYPE_OF_CONTRO|VID_MEMS|TYPE_OF_WINCES|NUM_WINC|CAP_WINC|NUM_I_CO|NUM_EX_D|TYPE_OS \n");
    
    while(fread(data, sizeof(student_computer), 1, f) != EOF && !feof(f)) {
        printf("%-14s|%-8d|%-20s|%-8d|%-14s|%-8d|%-14s|%-8d|%-8d|%-8d|%-8d|%s\n", pc_2.surname, pc_2.number_of_processors,
        pc_2.type_of_processors, pc_2.memory_size, pc_2.type_of_controller, pc_2.video_memory_size,
        pc_2.type_of_winchesters,pc_2.number_of_winchesters, pc_2.capacity_of_winchesters,
        pc_2.number_of_integrated_controllers, pc_2.number_of_external_devices, pc_2.oc);
    }
    fclose(f);
}
void parametr()
{
    FILE *f;
    char dataset_name[20];
    
    printf("Name of dataset: ");
    scanf("%s",dataset_name);
    
    if ((f = fopen(dataset_name, "r")) == NULL) {
        printf("Error,can't open a file!");
        getchar();
    }
    char type[20];
    
    printf("Name of type os: ");
    scanf("%s", type);
    
    student_computer pc_;
    student_computer *data = &pc_;
    
    printf("\nUSER SURNAME |N_PROCCE| TYPE_OF_PROCESSORS |MEM_SIZE|TYPE_OF_CONTRO|VID_MEMS|TYPE_OF_WINCES|NUM_WINC|CAP_WINC|NUM_I_CO|NUM_EX_D|TYPE_OS \n");
    
    while(fread(data, sizeof(student_computer), 1, f)!= EOF && !feof(f)) {
        if (strcmp(pc_.oc, type)) {
            printf("%-14s|%-8d|%-20s|%-8d|%-14s|%-8d|%-14s|%-8d|%-8d|%-8d|%-8d|%s\n", pc_.surname, pc_.number_of_processors,
            pc_.type_of_processors, pc_.memory_size, pc_.type_of_controller, pc_.video_memory_size,
            pc_.type_of_winchesters,pc_.number_of_winchesters, pc_.capacity_of_winchesters,
            pc_.number_of_integrated_controllers, pc_.number_of_external_devices, pc_.oc);
        }
    }
    fclose(f);
}
void delete_dataset()
{
    char dataset_name[20];
    printf("Name of dataset: ");
    scanf("%s", dataset_name);
    remove(dataset_name);
}
#endif