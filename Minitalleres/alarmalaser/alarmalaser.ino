int brillo;
int speakerPin = 8;

void setup ()
{
   pinMode (7, OUTPUT); // define the digital output interface 7 feet
   pinMode (8, OUTPUT); // define the digital output interface 7 feet
   Serial.begin(9600);
   
}
void loop () {
   
   brillo = analogRead(A5);
   Serial.println(brillo);
   digitalWrite (7, HIGH); // open the laser head

   if (brillo < 500) {
    digitalWrite(speakerPin, HIGH);
   }
   else{
    digitalWrite (speakerPin, LOW);
   }
}
