# NEMESIS-9
Un chatbot IA accompagné de son doigt d'honneur favori

## Dépendances:
Python et les librairies suivantes:
serial, time, threading, pyautogui, pytesseract, requests, numpy
Ainsi que [Arduino IDE](https://www.arduino.cc/en/software) bien sur et la librairie Peggy 2 [téléchargeable ici](https://github.com/evil-mad/peggy/archive/refs/tags/v1.0.zip)

## Le cablâge pour le panneau LED et la main articulée:
https://i.imgur.com/OMbhO9b.jpeg

## Initialisation Arduino
Avant de téléverser du code, deplacer temporairement le cable braché sur le pin 2 de l'arduino vers le 5V de l'arduino en enlevant le cable du servomoteur.
Dans l'arduino IDE, aller dans `File -> Examples -> ArduinoISP -> ArduinoISP`, et téléverser ce code vers la carte arduino.

Ensuite éditer le fichier `final-fuck.ino` pour remplacer ces deux lignes par votre chemin d'accès pour la librairie Peggy 2:

`#include "C:\Users\utilisateur\Documents\Arduino\fuck-peggy\peggy\arduinolib\Peggy2\Peggy2.h"`

`#include "C:\Users\utilisateur\Documents\Arduino\fuck-peggy\peggy\arduinolib\Peggy2\Peggy2.cpp"`

Pour téléverser ce code dans le panneau LED: `Sketch -> Upload Using Programmer`
Ensuite, vous pouvez recabler l'arduino comme au départ, c'est à dire reprendre le fil déplacé précédemment, le remettre sur le Pin 2 de l'Arduino, reprendre aussi le fil débranché du servomoteur et le remettre sur le 5V de l'arduino.

Ensuite ouvrez le fichier send_on_off.ino et téléversez-le sur l'Arduino.

Pour vérifier que tout marche, vous pouvez ouvrir le moniteur série dans l'IDE Arduino et taper `HTTP ON` pour lever le doigt et `HTTP OFF` pour le baisser. Si tout fonctionne, on peut passer au script python, sinon reprenez tout depuis le début...

## Partie python
Installez les différentes librairies python nécéssaires cités au début de ce README.
Vous aurez probablement besoin d'installer Tesseract-OCR manuellement, faites-le et modifiez cette ligne du fichier `sendfuck.py` pour donner votre chemin vers le .exe de Tesseract:

`pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'`

Une fois que c'est fait, d'abord lancer le script `fuck.py` puis lancer `sendfuck.py` en parallèle.

Pour ordonner au doigt de se lever, il suffit d'aller à l'addresse http://localhost:8000 sur le pc qui héberge les scripts.
Vous pouvez aussi lancer le doigt avec votre téléphone (connecté au même réseau wifi) en allant sur l'IPv4 de votre pc avec :8000 à la fin. Pour trouver votre IPv4 publique tapez `ipconfig` dans votre cmd, dans les dernieres lignes affichées vous devriez trouver votre IPv4.

## Le ChatBot !
On a réalisé ce ChatBot sur le site [Shapes, Inc](https://shapes.inc/), sur ce site vous pourrez donner à votre chatbot la mémoire, la personnalité et le comportement que vous désirez, je vous laisse créer le votre.

Une fois que c'est fait allez à l'adresse https://shapes.inc/VotreUrlDeChatBot/chat et parlez avec lui sur la machine qui héberge les scripts. La main devrait se lever à chaque réponse du ChatBot

## Bonus
Vous pouvez créer vos propres animations sur l'écran LED en modifiant les variables qui stockent les coordonnées des LED à allumer à chaque frame dans le code `final-fuck.ino`
