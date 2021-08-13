/*
 * Bandung Indonesia
 */


/* Use software serial for the PZEM
 * Pin 5 Rx (Connects to the Tx pin on the PZEM)
 * Pin 4 Tx (Connects to the Rx pin on the PZEM)
*/
#include <PZEM004Tv30.h>
//PZEM004Tv30 pzem(D4,D5);
PZEM004Tv30 pzem(D5, D6);
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
    float voltage = pzem.voltage();
    float current = pzem.current();
    float power = pzem.power();
    float energy = pzem.energy();
    float frequency = pzem.frequency();
    float pf = pzem.pf();
    if( !isnan(voltage)||!isnan(current)||!isnan(power)||!isnan(energy)){
        Serial.print("Voltage: ");
        Serial.print(voltage);
        Serial.println("V");
        Serial.print("Current: ");
        Serial.print(current+2);
        Serial.println("A");
        Serial.print("Power: ");
        Serial.print(power);
        Serial.println("W");
        Serial.print("Energy: ");
        Serial.print(energy,3);
        Serial.println("kWh");
    } else {
        Serial.println("Sensor Tidak Terbaca pak bosq");
    }
    delay(2000);
}
