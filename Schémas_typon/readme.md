# Description des composants utilisés

- [x] Réalisation du schéma structurel
   - Justification du choix des composants principaux

ATMEGA328-16AU : Nous avons choisir de prendre un ATMEGA328-16AU car la fréquence que fournit le composant (fournir jusqu'à 20 MHz) permet de faire tourner tout les autres composants. De plus, le composant est capable de gérer le BUS SPI.

XL1509-5.0 : Nous avons choisir ce régulateur de tensions là car la plage qu'on peut fournir à l'entré du composant s'éléve jusqu'à 40 V ce qui est plus convenable. De plus, le composant est capable de réguler la tension jusqu'à 5 V ce qui est convenable pour nos composant qui nécessite justement une plage compris entre 1 V et 5 V. 

AMS1117-3.3 : Nous avons choisir ce régulateur tensions pour l'écran LCD. En effet, nous avons choisir ce régulateur tensions car la tensions nécessaire au fonctionnement de l'écran LCD nécessite une tension de 3,3 V.Donc, aprés que le régulateur XL1509-5.0 est finir de régulé la tensions à 5 V, c'est au tour du composant AMS1117-3.3 de régulé à nouveau la tension à 3.3 V pour l'écran LCD qui ne peut encore là que accepter une tension de 3.3 V. 

MCP2551 : Nous avons choisir ce composant là car il va servir de passerelle entre le contrôleur CAN et le bus CAN, il va convertir les signaux logiques en signaux électriques pour adapter au BUS CAN.   

MCP2515 : Nous avons choisir ce composant là car il va gérer la gestion des messages CAN, filtrer les messages et il communiquera ces messages avec le microcontroleur en SPI. 

LCD3.5 UNO : Alors sur le schéma sctructurel nous avons prévues d'utiliser un écran LCD 2.4 pouces mais nous avons anticipé sur un écran LCD plus grand un 3.5 pouces. Pourquoi on a fait ça ? On a fait ça au cas ou si nous voulons un écran LCD plus grande. Nous avons choisir un LCD 2.4 pouces pour affiché les valeurs des capteurs sur un écran LCD (il va servir d'écran multifonctions). 
   
- [x] Réalisation du typon en double face
  
   - Contraintes de réalisation (dimension, largeur des pistes...)

Les contraintes de réalisation sont : 

  - Les pistes pour les composants d'alimentations qui fournit des tensions haute doivent faire 20mil sinon ils vont brûlé la carte (GX12, XL1509-5.0, les condensateurs et les inductances qui sont relier à ces alimentations ).
  - Les pistes pour le microcontroleur ATMEGA328-16AU doivent avoir une épaisseur de 15mil au maximun.
  - Les pistes doivent pas se croisé.
  - Limiter au maximun les trous sur les cartes (Les Vias).
  - Respecté un espacement entre les pastiles et les pistes qui passent entre les deux.
  - Priorisé les pistes du microcontroleurs en premier et les composants d'alimentations en dernier.
  - Ajouter deux plan de masse un au-dessus et un en-dessous de la carte.
  - Renseigné que la référence des composants (Exemple : R10, C15,U1) et pas le type ou les valeurs des composants (exemple : XL1509-5.0, 150 µF...)  car ce qui est important c'est qu'on voir la référence des composants quand la carte est finir (Voir image ci-dessous).
  - La référence des composants doivent être bien lisible et doivent avoir la même orientation exemple : "si une référence d'un composant est positionné horizontalement alors tout les autres références doivent être positionné pareillement pour facilité la visibilité ".  
  - Mettre les connecteurs au bord de la carte (Salea logic, GX12, ISP-PROG)


<ins>Carte de projet croix de pharmacie :</ins> 

![IMG_20241212_101554](https://github.com/user-attachments/assets/411e6ba1-8b71-4161-bf2d-6e143ad115e8)


- [x] Édition des fichiers de constructions Gerber

L'édition qu'il y a eu sont : 
 
 - Les pistes que je devais reposiotionné. (déjà fait)
 - Les références des composants que je devais tous bien orientés. (déjà fait)
 - Les ajouts des plans de masses sur la partie au-dessus et en-dessous de la carte. (déjà fait)

