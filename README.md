# L3B_ER_projet_2025

- [ ] Description du module et attendu final

Le module que je dois mettre en place c'est l'écran multifonction. Alors les fonction qu'il doit réalisé c'est qu'il doit lire les trames des differents capteurs pour pourvoir affiché les données mesures de l'Anémomètre-girouette, la vitesse de l'eau, la température, le débit et le niveau d'essence du moteur 1 et le régime moteur et totalisateur horaire du moteur 2. 

Exemple de trame pour le module moteur n°2 : 

![image](https://github.com/user-attachments/assets/46cdf7dd-1add-49dd-b231-b170790bfd0d)# L3B_ER_projet_2025 

La partie du projet que j'ai en charge :

![image](https://github.com/user-attachments/assets/17945f1c-a007-461d-bc29-03956196aba0)

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










