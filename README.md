# cub3D

cub3D est un projet graphique réalisé dans le cadre de l’École 42.
Il consiste à développer un moteur de rendu 3D en raycasting, inspiré de Wolfenstein 3D, en utilisant la MiniLibX.

Ce projet met l’accent sur la compréhension des bases d’un moteur graphique, la gestion d’événements en temps réel et le développement en langage C proche du système.

--------------------------------------------------

OBJECTIFS DU PROJET

- Création d’une fenêtre graphique sous Linux
- Rendu 3D en temps réel par raycasting
- Gestion des entrées clavier
- Lecture, parsing et validation d’un fichier de configuration (.cub)
- Implémentation de bases mathématiques liées à la projection 3D
- Gestion rigoureuse de la mémoire et des erreurs

--------------------------------------------------

COMPILATION

Version standard :
make

Version bonus :
make bonus

--------------------------------------------------

EXECUTION

Version standard :
./cub3D test_files/maps/map_3.cub

Version bonus (collisions activées) :
./cub3D_bonus test_files/maps/map_3.cub

--------------------------------------------------

CONTROLES

Déplacements :
- Z ou Flèche haut : avancer
- S ou Flèche bas : reculer
- Q : déplacement à gauche
- D : déplacement à droite

Rotation :
- Flèche gauche : tourner à gauche
- Flèche droite : tourner à droite

--------------------------------------------------

FICHIER .cub

Le fichier de configuration .cub définit :
- Les chemins des textures (Nord, Sud, Est, Ouest)
- Les couleurs du sol et du plafond
- La carte du jeu

Contraintes :
- La carte doit être entièrement fermée par des murs
- Une seule position de départ est autorisée
- Le fichier est validé avant tout lancement du jeu

--------------------------------------------------

DEPENDANCES (LINUX)

Le projet utilise la MiniLibX et nécessite les bibliothèques X11.

Debian / Ubuntu :
sudo apt update
sudo apt install -y libx11-dev libxext-dev libbsd-dev

--------------------------------------------------

CONTRAINTES TECHNIQUES

- Langage : C
- Respect strict de la norme de l’École 42
- Aucune fuite mémoire (vérifiée avec valgrind)
- Gestion propre des erreurs
- Code lisible et structuré
- Pas d’allocation dynamique inutile

--------------------------------------------------

AUTEUR

Zahi Mata
Étudiant à l’École 42
Projet réalisé en équipe
