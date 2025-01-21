# L3B_ER_projet_2025 - RÉSEAU POUR NAVIRE DE PLAISANCE 

Ceci est la branche de dépot principal !
Le contenu correspond à la fusion de l'ensemble des branches des étudiants de la section.

## Présentation générale

La SARL *Réunion Formation Plongée* désire équiper son navire support de plongée d’un ensemble d’appareils et de capteurs à la norme NMEA2000.

- NMEA 2000 est une norme (normalisé CEI 61162-3) de communication utilisée pour **connecter** des capteurs marins et des unités d'affichage à bord des navires et des bateaux.
  
  ![image](https://github.com/user-attachments/assets/1a12b45b-7cac-43d6-b560-e73dd437fcb6)
  
- L'ensemble des différentes unités communique sur un **bus série différentiel CAN** (controller area network).

  <!-- Ceci est un commentaire -->
  <!-- ![image](https://github.com/user-attachments/assets/bae5d834-5a40-4ef9-b0d7-cf7c12461673)-->
  <img src="https://github.com/user-attachments/assets/bae5d834-5a40-4ef9-b0d7-cf7c12461673" alt="image" width=75%>
  
- Chaque unité déportée pourra utiliser "localement" des bus de type 1-wire, SPI ou I2C mais les transmissions entre unités repose sur l'association "NMEA2K + CAN".

## Expression du besoin

### Diagramme de Cas d’Utilisation (Use Case Diagram)

<!-- ![image](https://github.com/user-attachments/assets/9d067235-bc27-45e2-9fe4-a5bc436da384) -->
<img src="https://github.com/user-attachments/assets/9d067235-bc27-45e2-9fe4-a5bc436da384" alt="image" width=75%>

### Diagramme d'exigences (Requirement diagram)

![image](https://github.com/user-attachments/assets/48a60c84-8a6c-4cc9-939c-3ee65155acf3)

## Tâches à réaliser par les étudiants

|Etudiant|Programme|Fabrication|Principe|Composants de base|
|---|---|---|---|---|
|ER1|Numérisation signaux capteurs et écriture trame NMEA2000 d’identifiant 09FD02xxh|Module Anémo-girouette|Procédé optique (20 imp/tr), Capteur magnétique (12 bits), bus I2C et CAN| ATmega328 + PR-3000-FSJT-N01 + AS5600 + MCP2515/PCA82C250|
|ER2|Lecture capteur et Ecriture trame NMEA2000 d’identifiant 09F503xxh|Module Vitesse de l’eau|Capteur magnétique à hélice, bus CAN|ATmega328 + YF-S401 + MCP2515/PCA82C250|
|ER3|Lecture capteur et Ecriture trame NMEA2000 d’identifiant 15FD06xxh|Module Température|Capteur numérique, bus 1wire et CAN|ATmega328 + DS18B20 + MCP2515/PCA82C250|
|ER4|Lecture données GPS en NMEA0183 et Ecriture trame NMEA2000 d’identifiant 09F80102h|Module GPS (position)|Géolocalisation par satellites, bus USART et CAN|ATmega328 + GPS Neo6M + MCP2515/PCA82C250|
|ER5|Lecture données GPS en NMEA0183 et Ecriture trame NMEA2000 d’identifiant 09F80202h|Module GPS (déplacement)|Géolocalisation par satellites, bus USART et CAN|ATmega328 + GPS Neo6M + MCP2515/PCA82C250|
|ER6|Lecture données GPS en NMEA0183 et Ecriture trame NMEA2000 d’identifiant 09F11202h|Module GPS (boussole)|Géolocalisation par satellites, bus USART et CAN|ATmega328 + GPS Neo6M + MCP2515/PCA82C250|
|ER7|Lecture données GPS en NMEA0183 et Ecriture trame NMEA2000 d’identifiant 0DF80902h|Module GPS (Heure UTC)|Géolocalisation par satellites, bus USART et CAN|ATmega328 + GPS Neo6M + MCP2515/PCA82C250|
|ER8|Lecture capteur et Ecriture trame NMEA2000 d’identifiant 09F112xxh|Module Boussole magnétique|Capteur magnétique, bus I2C et CAN|ATmega328 + GY-271 + MCP2515/PCA82C250|
|ER9|Numérisation signal capteur et Ecriture trame NMEA2000 d’identifiant 0DF50Bxxh|Module profondimètre|Echolocation Ultra-Son, bus CAN|ATmega328 + HC-SR04P + MCP2515/PCA82C250|
|ER10|Lecture des trames NMEA2000 et affichage données GPS & boussole|Module Combi-Simrad|Ecran OLED, bus CAN|ATmega328 + écran OLED + MCP2515/PCA82C250|
|ER11|Lecture des trames NMEA2000 et affichage données capteurs et moteur|Module Combi-Simrad|Ecran OLED, bus CAN|ATmega328 + écran OLED + MCP2515/PCA82C250|
|ER12|Capteur de débit et niveau d’essence et Ecriture trame NMEA2000 d’identifiant 08F402xxh|Module Moteur 1|ATmega328 + YF-S401 + S3-E750 + MCP2515/PCA82C250|
|ER13|Capteur de régime moteur et totalisateur horaire et Ecriture trame NMEA2000 d’identifiant 08F403xxh|Module Moteur 2|Horloge temps reel, bus CAN|ATmega328 + DS1307 + MCP2515/PCA82C250|
|ER14|Lecture trames NMEA2000 et transmission USB (port COM virtuel)|Module passerelle|Communication bus CAN et USB|ATmega328 + CP2102 + MCP2515/PCA82C250|

![image](https://github.com/user-attachments/assets/cf00ad84-ec59-4f89-91e3-1b145940bdcf)
