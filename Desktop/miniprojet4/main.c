#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct etudiant {
    int id;
    char nom[30];
    char prenom[30];
    int age;
    float moyenne;
};

struct cours {
    int code;
    char nom[50];
    int credit;
    float note;
};

struct etudiant etudiants[100];
struct cours courses[10];

int nombreetudiant = 0;
int nombrecours = 0;

void ajouteretudiant() {
    printf("Saisissez l'ID de l'etudiant: ");
    scanf("%d", &etudiants[nombreetudiant].id);
    printf("Saisissez le nom de l'etudiant: ");
    scanf("%s", etudiants[nombreetudiant].nom);
    printf("Saisissez le prenom de l'etudiant: ");
    scanf("%s", etudiants[nombreetudiant].prenom);
    printf("Saisissez l'age de l'etudiant: ");
    scanf("%d", &etudiants[nombreetudiant].age);
    printf("Saisissez la moyenne de l'etudiant: ");
    scanf("%f", &etudiants[nombreetudiant].moyenne);
    nombreetudiant++;
}

void ajoutercours() {
    printf("Code du cours: ");
    scanf("%d", &courses[nombrecours].code);
    printf("Nom du cours: ");
    scanf("%s", courses[nombrecours].nom);
    printf("Credits du cours: ");
    scanf("%d", &courses[nombrecours].credit);
    printf("Note: ");
    scanf("%f", &courses[nombrecours].note);
    nombrecours++;
}

void afficheretudiants() {
    int i
    printf("\nListe des etudiants\n");
    for (i = 0; i < nombreetudiant; i++) {
        printf("ID: %d | Nom: %s | Prenom: %s | Age: %d | Moyenne: %.2f\n",
               etudiants[i].id, etudiants[i].nom, etudiants[i].prenom,
               etudiants[i].age, etudiants[i].moyenne);
    }
}

void affichercours() {
    int i;
    printf("\n--- Liste des cours ---\n");
    for (i = 0; i < nombrecours; i++) {
        printf("Code: %d | Nom: %s | Credits: %d | Note: %.2f\n",
               courses[i].code, courses[i].nom, courses[i].credit, courses[i].note);
    }
}

void rechercheretudiantparsonid() {
    int ID;
    int i;
    printf("Entrez l'ID de l'etudiant: ");
    scanf("%d", &ID);

    for (i = 0; i < nombreetudiant; i++) {
        if (etudiants[i].id == ID) {
            printf("Trouve: %s %s (Age: %d, Moyenne: %.2f)\n",
                   etudiants[i].nom, etudiants[i].prenom,
                   etudiants[i].age, etudiants[i].moyenne);
            return;
        }
    }
    printf("L'etudiant n'est pas enregistre.\n");
}

void modifiernoteducours() {
    int CODE;
    int i;
    printf("Entrez le code du cours: ");
    scanf("%d", &CODE);

    for (i = 0; i < nombrecours; i++) {
        if (courses[i].code == CODE) {
            printf("Nouvelle note pour %s: ", courses[i].nom);
            scanf("%f", &courses[i].note);
            printf("Note modifiee avec succes !\n");
            return;
        }
    }
    printf("Cours non trouve !\n");
}

int main() {
    int choix;
    do {
        printf("\n=== MENU ===\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Ajouter un cours\n");
        printf("3. Afficher les etudiants\n");
        printf("4. Afficher les cours\n");
        printf("5. Rechercher un etudiant par ID\n");
        printf("6. Modifier la note d'un cours\n");
        printf("0. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouteretudiant(); break;
            case 2: ajoutercours(); break;
            case 3: afficheretudiants(); break;
            case 4: affichercours(); break;
            case 5: rechercheretudiantparsonid(); break;
            case 6: modifiernoteducours(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide !\n");
        }
    } while (choix != 0);

    return 0;
}
