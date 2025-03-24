# L3B_ER_projet_2025

Le but de notre projet est d'équipé le navire "SARL Réunion Formation Plongée" d'un ensemble d’appareils et de capteurs à la norme NMEA2000.


![Projet2025](https://github.com/user-attachments/assets/72c7fcfe-b73f-4beb-ae8a-201ff236c900)


## Description du module et attendu final

Mon module c'est une carte avec un écran monté dessus relier avec un microcontroleur (Atmega328-16AU), un programmateur (HE10_6), une alimentation XL1509-5.0 (ce composant là va me permettre d'adapter le courant d'entré en 5V pour toute la carte), d'un MCP2551 et d'un MCP2515, d'un GX12 (c'est là que va arrivé les informations des capteurs), d'un AMS1117-3.3 (ce composant là c'est pour régulé la tension à 3,3 V pour l'écran), un connecteur embase droite pour voir les trames et enfin des diodes électroluminécantes (XL-3216SURC) pour voir les communications TX, RX et l'alimentation. Le MCP2551 et le MCP2515 vont tout les deux me permettre d'assurer la communication entre le microcontroleur et les capteurs et de garder temporairement les données des capteurs.

Ce qui est attendu au final, c'est que je dois concevoir une carte avec les composants marqués au-dessus, un écran multifonctions qui gère par derrière les trames NMEA2000 des capteurs et qui les affiche en clair sur l'écran.

<ins> **Exemple d'un écran multifonctions avec les relevés des capteurs  :**</ins>

   ![1742833629480](https://github.com/user-attachments/assets/b60f12a4-db35-4a30-a781-8feb58cc535f)


<ins> **Exemple de carte à fabriqué :**</ins>

![image](https://github.com/user-attachments/assets/3d0fb151-628a-4c1c-9304-244347d32c4e)

## Description des grandeurs d'entrée et de sortie 

Ma maquette, ce qu'il fait, c'est qu'il va recevoir les trames NMEA2000 des différents capteurs à l'entrée (Ils vont tous passer par le GX12), ils vont ensuite être filtrés et traités par mes composants MCP2515 et MCP2555. Ensuite, ces mêmes composants vont assurer la passerelle entre le microcontrôleur et les composants (BUS SPI). Ensuite, le microcontrôleur traite les données des différents capteurs et les envoie ensuite sous format de texte les valeurs des différents capteurs sur un écran LCD SPI (Un programme sera mis dans le microcontroleur pour traité les données des capteurs) .

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
 - Possédent l'interface SPI et 2-wire
 - Accepte jusqu'à 32 kbit les prè-programmes
 - Possédent une mémoire EEPROM qui garde l'information jusqu'a 1kbit lorsque la carte est éteint.

Composant "MCP2515" : 

 - Communication : CANH et CANL
 - Alimentation : 2.7 V - 5.5 V
 - Plage de température : -40 °C à + 85 °C
 - Interface SPI cadencé à 10 MHz

Composant "MCP2551" :
 
 - Communication : CANH et CANL
 - Alimentation : 4.5V - 5.5V
 - Tension continue pour CANH et CANL entre : -42 V et + 42 V
 - Plage de température : -55 °C et + 150 °C

Composant "XL1509-5.0" :

 -Tension de sortie régulé à : 5V (valeur typique)
 -Tension d'entré accepté : 4.5V - 40V
 -Oscillateur de fréquence : 150 khz (valeur typique)
 -Limite de courant : 4 A.

Composant "AMS1117-3.3" : 

- Régule la tension jusqu'à 5 V
- La tension d'entré maximun est 18 V
- La plage de température est compris entre -65 °C à 150 °C


Le protocole qui est utilisé c'est le protocole SIMNET et pour la communication c'est le BUS CAN. 

## Les diagrammes 

<ins> **Diagramme de cas d'utilisation :**</ins>

![Diagramme_de_cas_utilisation](https://github.com/user-attachments/assets/1774d671-eae3-4035-bea4-8383dec1db04)

<ins> **Diagramme d'éxigence :**</ins>

![Diagramme_exigence_Jean](https://github.com/user-attachments/assets/60041320-7967-4360-8ec1-09c04f2ef083)

<ins> **Diagramme de bloc interne :**</ins>

![Diagramme_de_bloc_interne](https://github.com/user-attachments/assets/a4674664-38d4-4457-9ef1-f7dfe83a1d50)


 

