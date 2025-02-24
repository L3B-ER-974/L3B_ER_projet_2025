# L3B_ER_projet_2025

> **Description du module et attendu final**
> RÉSEAU POUR NAVIRE DE PLAISANCE - NMEA2000
- Présentation générale du système supportant le projet :
  
![image](https://github.com/user-attachments/assets/eb1aaab5-a327-41bb-a704-3360e9b9ff27)

Le module que je dois concevoir est un système GPS permettant la géolocalisation de la longitude et de la latitude par satellites. Il reçoit les données satellites en NMEA0183 sur USART (trame GPGLL ou GPGGA) et transmet les informations sous forme de trames NMEA2000 sur le bus CAN.

Ce qui est attendu au final, c'est la conception d'une carte fonctionnelle qui permet de recevoir, traiter et afficher ces données de positionnement avec précision.(la vitesse du vent ainsi que sa direction), la température, le débit et le niveau d'essence pour le moteur 1, le régime moteur et totalisateur horaire du moteur 2 et enfin la vitesse relative sur l'eau.

> **Description des grandeurs d'entrée et de sortie :**
   
Plage de variation attendue :

- Longitude : +/- 0 à 180° (Est = positif, Ouest = négatif)
- Latitude : +/- 0 à 90° (Nord = positif, Sud = négatif)

Précision attendue :

- Résolution : 0,1 µ°

- Résultat attendu :

- Réception des données satellites en NMEA0183 sur USART (trame GPGLL ou GPGGA).
Ecriture de la trame NMEA2000 d’identifiant 09F80102h sur bus CAN

> **Description des composants constitutifs de l'unité :**
  
 Microcontrôleur ATmega328 :

- Alimentation : 1.8 - 5.5 V
- Plage de fréquence : 0 - 20 MHz
- Programmable en série via USART
- Nombre de broches : 32
- Limitation courant : 200 mA

Module GPS Neo6M :

- Protocole de communication : NMEA0183
- Données envoyées : Latitude et Longitude
- Interface : USART
- Alimentation : 2.7V - 3.6V

Contrôleur de bus CAN MCP2515 :

- Communication : CANH et CANL
- Alimentation : 2.7 V - 5.5 V
- Interface : SPI avec microcontrôleur
- Interface bus CAN PCA82C250 :
- Communication : CANH et CANL
- Alimentation : 4.5V - 5.5V

Convertisseur de tension XL1509-5.0 :

- Tension de sortie régulée : 5V (valeur typique)
- Tension d'entrée : 4.5V - 40V
- Oscillateur de fréquence : 150 kHz (valeur typique)
- Limite de courant : 4 A
- Protocole de communication
- Protocole utilisé : SIMNET
- Bus de communication : CAN

Format de trame NMEA2000 (Identifiant 09F80102h) :

- DATA1 : Longitude (MSB)
- DATA2 : Longitude
- DATA3 : Longitude
- DATA4 : Longitude (LSB)
- DATA5 : Latitude (MSB)
- DATA6 : Latitude
- DATA7 : Latitude
- DATA8 : Latitude (LSB)

# Mise à jour des documentations techniques essentielles (extraits utiles)

> **Diagramme d'exigence**

> **Diagramme de bloc interne**

> **Diagramme de cas d'utilisation**

![image](https://github.com/user-attachments/assets/57e4b718-a6c9-4e45-8e93-19d325f6bf5b)

> **Schématique P-CAD**

- Partie 1
![image](https://github.com/user-attachments/assets/e85184da-400b-4dba-9602-42e66f87f6fe)

- Partie 2
![image](https://github.com/user-attachments/assets/74fd0438-d3c1-4b25-9147-296a4d46cacd)

> **PCB**

- Carte finale

![image](https://github.com/user-attachments/assets/966c1315-90a3-4627-be64-985fafd6dd77)

> **GERBER**

![image](https://github.com/user-attachments/assets/69ebc5a3-acfc-4c2a-8c3d-78ba277ca216)



