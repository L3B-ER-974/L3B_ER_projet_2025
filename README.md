# L3B_ER_projet_2025

## Description du module et attendu final

Le but de notre projet est d'équipé le navire "SARL Réunion Formation Plongée" d'un ensemble d’appareils et de capteurs à la norme NMEA2000.

![Projet2025](https://github.com/user-attachments/assets/72c7fcfe-b73f-4beb-ae8a-201ff236c900)

Le module que je dois concevoir c'est un écran multifonction qui affiche les mesures de l'anémomètre-girouette (la vitesse du vent ainsi que sa direction), la température, le débit et le niveau d'essence pour le moteur 1, le régime moteur et totalisateur horaire du moteur 2 et enfin la vitesse relative sur l'eau.

Ce qui est attendu au final c'est que je dois concevoir une carte fonctionnel qui affiche les mesures que j'ai cité au-dessus. 

Exemple d'aperçu du rendu final : 

![image](https://github.com/user-attachments/assets/1524843b-de97-47d4-b072-d8c7a151ef04)
 
Nous allons fabriqué une carte avec l'écran qui sera par-dessus 

![image](https://github.com/user-attachments/assets/d10485e7-7799-4566-b702-df0929d8225d)


- [ ] Description des grandeurs d'entrée et de sortie :
    - plage de variation attendue
    - précision attendue
    - Résultat attendu

Les résultats qui sont attendus à la fin c'est qu'on doit affiché les valeurs des mesures sur l'écran LCD de façon bien organisé. 

- [ ] Description des composants constitutifs de l'unité : 
 
    - Caractéristique entrée-sortie
      
Les données des capteurs passe par l'atmel328 pour le traitement puis les affiches sur l'écran LCD et cela en BUS SPI. 
Nom de l'afficheur LCD : SKU MAR2406 driver ILI9341

    - plage de variation

Pas de variation.
    
    - précision, résolution, limitation
    
Résolution : 320x240 pixel
Taille écran en diagonal : 6,096 cm

    - Type de bus
    
Communication : BUS CAN
Protocole SIMNET

    - ports utilisés

Pas de ports utilisés 

    - alimentation et consommation
    
Alimentation : 3,3 à 5 V


- [ ] Mise à jour des documentations techniques essentielles (extraits utiles)

Diagramme de cas d'utilisation : 

Je l'ai fait mais j'ai pas pu le mettre 

Diagramme de cas d'exigence : 

![image](https://github.com/user-attachments/assets/6e29507a-380d-4cdf-a1c4-6a16437841bf)

Diagramme de bloc interne : 

![image](https://github.com/user-attachments/assets/0de2050f-efe6-4dd4-805a-20fe3854c0a2)










