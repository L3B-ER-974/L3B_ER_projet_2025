# L3B_ER_projet_2025

Le but de notre projet est d'équipé le navire "SARL Réunion Formation Plongée" d'un ensemble d’appareils et de capteurs à la norme NMEA2000.

![Projet2025](https://github.com/user-attachments/assets/72c7fcfe-b73f-4beb-ae8a-201ff236c900)

## Description du module et attendu final

Le module que je dois concevoir c'est un écran multifonction qui affiche les mesures de l'anémomètre-girouette (la vitesse du vent ainsi que sa direction), la température, le débit et le niveau d'essence pour le moteur 1, le régime moteur et totalisateur horaire du moteur 2 et enfin la vitesse relative sur l'eau.

Ce qui est attendu au final c'est que je dois concevoir une carte fonctionnel qui affiche les mesures que j'ai cité au-dessus. 

<ins> **Exemple d'écran multifonction avec d'autre mesure  :**</ins>

![image](https://github.com/user-attachments/assets/1524843b-de97-47d4-b072-d8c7a151ef04)
 
<ins> ** Exemple de carte à fabriqué : **</ins>

![image](https://github.com/user-attachments/assets/d10485e7-7799-4566-b702-df0929d8225d)

## Description des grandeurs d'entrée et de sortie 

Alors notre maquette va recevoir à l'entré le bus de données CAN, ensuite, ces données vont être traité par le microcontroleur puis ils vont être affiché par l'afficheur LCD 2.4pouces en bus SPI. 


## Description des composants constitutifs de l'unité 

Ecran LCD "SKU MAR2406 driver ILI9341" : 
 
 - Taille écran : 2.4 pouces (6,096 cm en diagonal )
 - Résolution : 320*240 pixel
 - Couleur : RGB 65k color
 - Communication : BUS SPI

Microprocesseur "Atmega328": 
 
 - Alimentation : 1.8 - 5.5 V
 - Plage de fréquence : 0 - 20 MHz
 - programmable en série USART
 - Possédent 32 broches au total
 - Limitation courant : 200 mA

Composant "MCP2515" : 

 - Communication : CANH et CANL
 - Alimentation : 2.7 V - 5.5 V

Composant "MCP2551" :
 
 - Communication : CANH et CANL
 - Alimentation : 4.5V - 5.5V

Composant "XL1509-5.0" :

 -Tension de sortie régulé à : 5V (valeur typique)
 -Tension entré : 4.5V - 40V
 -Oscillateur de fréquence : 150 khz (valeur typique)
 -Limite de courant : 4 A.

Le protocole qui est utilisé c'est le protocole SIMNET et pour la communication c'est le BUS CAN. 

## Mise à jour des documentations techniques essentielles 

<ins> ** Diagramme de cas d'utilisation : **</ins>

![Diagramme_de_cas_utilisation](https://github.com/user-attachments/assets/1774d671-eae3-4035-bea4-8383dec1db04)

<ins> ** Diagramme de cas d'éxigence : **</ins>

![Diagramme_exigence_Jean](https://github.com/user-attachments/assets/60041320-7967-4360-8ec1-09c04f2ef083)

<ins> ** Diagramme de bloc interne : **</ins>

![Diagramme_de_bloc_interne](https://github.com/user-attachments/assets/a4674664-38d4-4457-9ef1-f7dfe83a1d50)


 

