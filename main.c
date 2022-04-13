#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Vytvoř strukturu User, která obsahuje alespoň jeden dynamický prvek (ukazatel na později mallocované pole) - například známky. Do tohoto pole ulož libovolné prvky. Následně napiš program (funkci) která zkopíruje instanci usera do nové instance user2, avšak ne jako referenci! Tzn, že když po kopii změním prvek pole u jednoho z userů, změna se neprovede u obou!

typedef struct User {
    char name[100];
    int *marks;
} User;

void copy(User *from, User *to, int arr_size) {
    to->marks = (int*)malloc(arr_size * sizeof(int));
    strcpy(from->name, to->name);
    memcpy(to->marks, from->marks, arr_size * sizeof(int*));
}

int main(void) {
    User user1;
    User user2;

    //strcpy(user1.name, "test");

    user1.marks = (int*)malloc(5 * sizeof(int));

    for (int i = 0; i <= 5; i++) {
        user1.marks[i] = i + 1;
    }

    printf("u1: %d %d\n", user1.marks[0], user1.marks[1]);

    copy(&user1, &user2, 5);

    printf("u2: %d %d\n", user2.marks[0], user2.marks[1]);

    user2.marks[1] = 5;

    printf("u1: %d %d\n", user1.marks[0], user1.marks[1]);
    printf("u2: %d %d\n", user2.marks[0], user2.marks[1]);

    free(user1.marks);
    free(user2.marks);

    return 0;
}
