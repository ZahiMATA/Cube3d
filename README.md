# cub3D

cub3D est un projet graphique réalisé dans le cadre de l’École 42.
L’objectif est de créer un moteur de rendu 3D en raycasting, inspiré de Wolfenstein 3D, en utilisant la MiniLibX.

Ce projet permet de travailler sur :
- la gestion d’une fenêtre graphique
- le rendu 3D en temps réel
- la gestion des événements clavier
- la lecture et la validation de fichiers de configuration
- les bases mathématiques du raycasting

--------------------------------------------------

COMPILATION

make

Version bonus :
make bonus

--------------------------------------------------

EXECUTION

./cub3D test_files/maps/map_3.cub

Version bonus (avec collisions) :
./cub3D_bonus test_files/maps/map_3.cub

--------------------------------------------------

COMMANDES

Déplacements :
- Z ou flèche haut : avancer
- S ou flèche bas : reculer
- Q : déplacement gauche
- D : déplacement droite

Rotation :
- flèche gauche : tourner à gauche
- flèche droite : tourner à droite

--------------------------------------------------

FICHIER .cub

Le fichier .cub contient :
- les chemins des textures (Nord, Sud, Est, Ouest)
- les couleurs du sol et du plafond
- la carte du jeu

La carte doit être valide et entièrement fermée par des murs.

--------------------------------------------------

DEPENDANCES (LINUX)

Le projet utilise la MiniLibX et nécessite les bibliothèques X11.

Sur Debian / Ubuntu :

sudo apt update
sudo apt install -y libx11-dev libxext-dev libbsd-dev

--------------------------------------------------

CONTRAINTES

- Langage : C
- Respect de la norme de l’École 42
- Aucune fuite mémoire
- Gestion propre des erreurs
- Pas d’allocation dynamique inutile

--------------------------------------------------

AUTEUR

Zahi Mata
École 42
