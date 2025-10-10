# logboek

## 7/11/2024 

*1)* afspraken gemaakt *2)* logboek aangemaakt *3)* alles op laptop gezet *4)* esp32s3 firmware proberen builden

## 18/11/2024 

*1)* code van 6 if's naar 1 for *2)* datasheet esp32c3 chip lezen *3)* pcb basis schema gemaakt 

## 21/11/2024 

*1)* pcb basis schema afgewerkt *2)* kicad downloaden *3)* lezen over werking en design buck converters

## 25/11/2024 

*1)* basis buck converter genomen https://webench.ti.com/power-designer/switching-regulator/simulate/1 *2)* lijst met componenten beginnen opstellen *3)* lezen datasheet chip voor buck converter https://www.ti.com/lit/ds/symlink/tps62933f.pdf?ts=1732541289749&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FTPS62933F 

## 28/11/2024 

*1)* buck converter schema opstellen

## 1/12/2024 

*1)* buck converter schema verder opstellen *2)* weerstanden berekenen voor Vstart en vstop

## 6/1/2025
Pc deed raar => avontuur met ict

## 9/1/2025
Schema op pc zetten.
## 14/1/2025
Geen school wegens staking.
## 16/1/2025
Afwezig wegens ziek.
## 20/1/2025
*1)* Schema afgewerkt.
*2)* Bestanden voor pcb op github zetten.
*3)* Beginnen aan pcb layout (footprints toevoegen)
## 23/1/2025
*1)* Footprints maken
*2)* Footprints toewijzen
*3)* Excel bestand met alle nodige onderdelen
## 27/1/2025
*1)* pcb layout
## 30/1/2025
*1)* pcb layout
## 3/2/2025
leerlingencontacten
## 6/2/2025
Afwezig wegens ziekte
## 10/2/2025
*1)* pcb layout afwerken
*2)* routing van de pcb
## 17/2/2025
*1)* nakijken schema pcb
## 20/2/2025
*1)* bedradingsschema pcb maken
*2)* alle bestanden op github zetten
## 24/2/2025
*1)* documentatie pcb schrijven in .readme file
*2)* esptool installeren, pip bijwerken
*3)* commando's voor het programmeren van de esp32-c3 op word bestand gezet

## 27/2/2025
*1)* firmware uploaden op esp32-c3 (moeilijker dan het leek)
*2)* readme, software installatie aanpassen
*3)* Lezen over hoe pcb's te maken voor industriële aplicaties.

## 10/3/2025
*1)* Kleine aanpassingen maken aan pcb (verplaatsen componenten).
*2)* Verder aan excel bestand gewerkt met onderdelen in.

## 13/3/2025
*1)* Excel bestand afgewerkt met onderdelen.
*2)* Excel bestand in github gezet.
*3)* Documentatie aangepast (verwijzing naar excel bestand voor mensen die het willen maken).

## 17/3/2025, 20/3/2025, 24/3/2025

Aan vluchtcontroller werken (wegens geen tijd om dit project af te ronden thuis).

Project is afgerond en getest (maar voor finale versie nog geen geld)

# Nieuw: Vluchtcontroller
De hersenen van een drone: een kleine pcb met 20x20 mouting pattern waarop BetaFlight staat. Een eerste versie is al gemaakt (standaard), maar nu wil ik een 2e versie maken. De tweede versie heeft een ingebouwde ELRS ontvanger, zodat we deze niet meer ergens moeten proppen en het gewoon mooi in elkaar past. 

## 24/4/2025
Wifi antenne elrs receiver (esp32c3 chip) design.

## 28/4/2025
Silcksreen design

## 5/5/2025
Usb-c ipv micro usb
## 12/5/2025
Hulp aan Mulan met laser cutter
## 15/5/2025
1) verder usb-c installatie (beseft dat het niet ging passen op de bestaande lay out)
2) layout helemaal opnieuw begonnen
3) toevoegen van 3d modellen aan de pcb render
## 19/5/2025
1) Layout van pcb verder afwerken (nog veel werk aan), je moet alle onderdelen op een klein oppervlak zien te puzzelen.

# schooljaar 2025-2026

## (Achtergrond) 

In de vakantie:

Ik heb de pcb van de vluchtcontroller met elrs besteld op jlcpcb en de componenten op lcsc. Deze heb ik dan gesoldeerd, maar hierbij blijken er problemen te zijn met de power supply design van de elrs receiver. De hele vluchtcontroller startte op, buiten de receiver. De receiver werkte wel toen enkel de usb kabel was ingestoken. Hierdoor vermoedded ik dus dat er een probleem was met de PSU, die misschien te onstabiel was. Ik ben reeds aan een nieuw ontwerp met een verbeterde power supply begonnen, maar moet deze nog bestellen. (voor de rest werkte deze versie perfect, ik heb hiermee zelfs gevlogen op het NK droneracen race 2 en met deze fc TQ plaats genomen in de qualifiers) Door dit alles heb ik veel bijgeleerd over pcb design. Hierdoor zie ik veel problemen met mijn vorige ontwerp van de pcb voor de wled controller. Daarom ga ik deze volledig opnieuw maken, met vele verbeteringen.
Enkele verbeteringen:
*usb-c i.p.v. micro-usb (gemakkelijker en EU standaard)
*verkleinde footprint
*verbeterde wifi antenne design
*goedkoper
*(hopelijk kleiner)

## aanmeldingen

### 2/09/2025 
aangemeld bij mevr. De Maeschalk
1) uitleg nieuw design geschreven logboek
2) nieuw design gestart
3) schema opstellen (esp32c3: bootstrap pins, input filtering caps. USB-c, 3.3V PSU )

### 5/09/2025 
aangemeld bij men. Van Hecke
1) schema opstellen (buck converter 3-8s input voltage 5V@5A output LMR14050)
2) schottky diode opzoekwerk over werking
3) gewoon voor mijn eigen om te onthouden: https://www.lcsc.com/product-detail/C22463843.html

### 9/09/2025 
1) schottky diode selectie, footprint, symbool overeen doen komen zodat we deze in het schema kunnen plaatsen

### 12/09/2025 
1) logic level converter 3.3v (esp32c3) => 5V (WS218B leds) schema
2) footprints toewijzen

### 16/09/2025 
aanmelding: Mevr. Claeys afwezig => aan Brian Goethals gevraagd om tegen de studie-leerkracht mij op aanwezig te zetten. (Ik heb de school zelfs niet verlaten, want ik was op de leerlingenraad.)
1) Schema afgewerkt
2) footprint voor spoel gemaakt
3) Edge cuts pcb
4) begin lay-out

### 19/09/2025 
Afwezig wegens ziekte

### 22/09/2025 
aanmelding: Mevr. Claeys afwezig => aan Brian Goethals gevraagd om tegen de studie-leerkracht mij op aanwezig te zetten.
1) Fouten gevonden in schema (load capacitors, connecties voor crystal oscillator niet aanwezig en een paar filtering caps vergeten voor de esp32C3) en deze dan opgelost
2) PCB layout verder

### 26/09/2025
vervangles mevrouw Deleu chemie

### 30/09/2025
1) volledig pcb geroute (koper connecties op plaatje gezet)
2) enkele 3d modellen van onderdelen toegevoegd 

### 03/10/2025
1) uitleg aan meneer Van Hecke

### 07/10/2025
1) routing aanpassen zodat er een hoger oppervlak ground is 
2) threading via's toevoegen
3) silckscreen
4) drc 

### 10/10/2025
1) kleine verandering routing
2) renders maken
3) laptop afgesloten wegens lang gebruikt s'ochtends en batterij bijna plat => overhouden voor andere lessen (ondertussen chemie gedaan)