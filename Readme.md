# Arbre d'objet

L'objectif de cet exemple est de mettre en évidence le fonctionne de l'arbre d'objet et de l'inversion de contrôle.

## Analyse

Une instance automatique `i1` est créée. Elle n'a pas de parent. Elle sera détruite automatiquement à la sortie du *scope*.

Une instance automatique `i2` est créée. Elle a un parent `a`. Elle sera détruite automatiquement à la sortie du *scope*.

Une instance automatique `i3` est créée. Elle a `i2` pour parent. Elle sera détruite automatiquement à la sortie du *scope*.

Une instance automatique `i4` est créée. Elle a `i1` pour parent. Elle sera détruite automatiquement à la sortie du *scope*.

Une instance dynamique `i5` est créée. Elle a pour parent `a`. Elle sera détruite par son parent ou explicitement (opérateur `delete`).

Une instance dynamique `i6` est créée. Elle a pour parent `i5`. Elle sera détruite par son parent ou explicitement (opérateur `delete`).

Une instance dynamique `i7` est créée. Elle n'a pas de parent. Elle ne sera détruite par son parent ni explicitement (opérateur `delete`).

A la fin de la fonction `main()`, l'arbre d'objet est le suivant :

```

a
|- i2
    |- i3
|- i5
    |- i6

i1 
|- i4

i7

```

L'ordre de destruction des instances est le suivant :

`i4` car c'est une instance automatique déclarée dans un *scope*. Arrivé au `}`, l'instance est automatiquement détruite.

`i3` car c'est l'enfant de `i2`.

`i2` car c'est l'enfant de `a`.

`a` car c'est la première instance automatique créée.

`i1` car c'est l'instance automatique suivante. `i1` est censée détruire ses enfants, mais `i4` a déjà été détruite.

`i5` car elle a pour parent `a` qui vient d'être détruite.

`i6` car elle a pour parent `i5`.