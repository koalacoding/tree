#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    char* key;
    struct node *left;
    struct node *right;
} node;

void printkey(node mynode) {
  printf("%s\n", mynode.key);
}

void list_keys(node racine) {
  if (racine.left != NULL) {
    list_keys( *(racine.left) );
  }

  printkey(racine);

  if (racine.right != NULL) {
    list_keys( *(racine.right) );
  }
}

/*
void list_keys_by_ptr(node* racine) {
  if (racine->left != NULL) {
    list_keys( racine->left );
  }
}
*/

int main(int argc, char *argv[]) {
  node avion = {"avion", NULL, NULL};
  node bateau = {"bateau", &avion, NULL};
  node train = {"train", NULL, NULL};
  node fusee = {"fusee", NULL, NULL};
  node voiture = {"voiture", &train, NULL};
  node moto = {"moto", &fusee, &voiture};
  node camion = {"camion", &bateau, &moto};

  list_keys(camion);

  return 0;
}
