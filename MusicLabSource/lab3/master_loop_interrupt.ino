#define  C0 16.35
#define Db0 17.32
#define D0  18.35
#define Eb0 19.45
#define E0  20.60
#define F0  21.83
#define Gb0 23.12
#define G0  24.50
#define Ab0 25.96
#define LA0 27.50
#define Bb0 29.14
#define B0  30.87
#define C1  32.70
#define Db1 34.65
#define D1  36.71
#define Eb1 38.89
#define E1  41.20
#define F1  43.65
#define Gb1 46.25
#define G1  49.00
#define Ab1 51.91
#define LA1 55.00
#define Bb1 58.27
#define B1  61.74
#define C2  65.41
#define Db2 69.30
#define D2  73.42
#define Eb2 77.78
#define E2  82.41
#define F2  87.31
#define Gb2 92.50
#define G2  98.00
#define Ab2 103.83
#define LA2 110.00
#define Bb2 116.54
#define B2  123.47
#define C3  130.81
#define Db3 138.59
#define D3  146.83
#define Eb3 155.56
#define E3  164.81
#define F3  174.61
#define Gb3 185.00
#define G3  196.00
#define Ab3 207.65
#define LA3 220.00
#define Bb3 233.08
#define B3  246.94
#define C4  261.63
#define Db4 277.18
#define D4  293.66
#define Eb4 311.13
#define E4  329.63
#define F4  349.23
#define Gb4 369.99
#define G4  392.00
#define Ab4 415.30
#define LA4 440.00
#define Bb4 466.16
#define B4  493.88
#define C5  523.25
#define Db5 554.37
#define D5  587.33
#define Eb5 622.25
#define E5  659.26
#define F5  698.46
#define Gb5 739.99
#define G5  783.99
#define Ab5 830.61
#define LA5 880.00
#define Bb5 932.33
#define B5  987.77
#define C6  1046.50
#define Db6 1108.73
#define D6  1174.66
#define Eb6 1244.51
#define E6  1318.51
#define F6  1396.91
#define Gb6 1479.98
#define G6  1567.98
#define Ab6 1661.22
#define LA6 1760.00
#define Bb6 1864.66
#define B6  1975.53
#define C7  2093.00
#define Db7 2217.46
#define D7  2349.32
#define Eb7 2489.02
#define E7  2637.02
#define F7  2793.83
#define Gb7 2959.96
#define G7  3135.96
#define Ab7 3322.44
#define LA7 3520.01
#define Bb7 3729.31
#define B7  3951.07
#define C8  4186.01
#define Db8 4434.92
#define D8  4698.64
#define Eb8 4978.03
// DURATION OF THE NOTES 
#define BPM 300  
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

#include <math.h>
#include <Servo.h>

int notes1[] = {E4, E4, E4, E4, E4, E4,
                E4, G4, C4, D4, E4,
                F4, F4, F4, F4, F4,
                E4, E4, E4,
                E4, D4, D4, E4, D4, G4,
                E4, E4, E4, E4, E4, E4,
                E4, G4, C4, D4, E4,
                F4, F4, F4, F4,
                F4, E4, E4, E4, E4,
                G4, G4, F4, D4, C4
               };

int beats1[] = {Q, Q, H, Q, Q, H,
                Q, Q, Q + E, E, W,
                Q, Q, Q + E, E, Q,
                Q, Q, Q,
                Q, Q, Q, Q, H, H,
                Q, Q, H, Q, Q, H,
                Q, Q, Q + E, E, W,
                Q, Q, Q, Q,
                Q, Q, Q, E, E,
                Q, Q, Q, Q, W
               };

int notes2[] = {LA4, B4, C5, B4, LA4,
                B4, B4, G4,
                LA4, B4, C5, B4, LA4,
                Eb5, D5, C5,
                LA4, B4, C5, B4, LA4,
                B4, B4, D5,
                LA4, B4, C5, B4, LA4, LA4,
                B4, Db5, D5, C5, B4,
                Db5, Db5, LA4,
                B4, Db5, D5, C5, B4,
                F5, E5, D5,
                B4, Db5, D5, C5, B4,
                Db5, Db5, E5,
                B4, Db5, D5, C5, B4,
                B4, B4
               };

int beats2[] = {E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q, W,
                E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q,
                Q + E, Q, Q + E,
                E, E, E, E, Q,
                W, W
               };

int notes3[] = {E4, D4, E4, F4,
                LA3, D4, E4, F4,
                E4, D4, E4, F4,
                LA3, D4, E4, F4,
                E4, D4, E4, F4,
                LA3, D4, E4, F4,
                E4, D4, E4, F4,
                LA3, D4, E4, F4,
                LA4, G4, LA4, Bb4,
                D4, G4, LA4, B4,
                LA4, G4, LA4, B4,
                D4, G4, LA4, B4,
                LA4, G4, LA4, Bb4,
                D4, G4, LA4, B4,
                LA4, G4, LA4, B4,
                D4, G4, LA4, B4
               };

int beats3[] = {S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S,
                S, S, S, S
               };

int notes4[] = {E3, D3, C3, D3,
                E3, E3, E3,
                D3, D3, D3,
                E3, E3, E3,
                E3, D3, C3, D3,
                E3, E3, E3,
                D3, D3, E3, D3, C3
               };

int beats4[] = {E + S, S, E, E,
                E, E, Q,
                E, E, Q,
                E, E, Q,
                E + S, S, E, E,
                E, E, Q,
                E, E, S + E, S, H
               };

/*
int notes3[] = {LA3, LA3, F3, C4,
                LA3, F3, C4, LA3,
                E4, E4, E4, F4, C4,
                Ab3, F3, C4, LA3,
                LA4, LA3, LA3, LA4, Ab4, G4,
                Gb4, E4, F4, Bb3, Eb4, D4, Db4,
                C4, B3, C4, F3, Ab3, F3, LA3,
                C4, LA3, C4, E4,
                LA4, LA3, LA3, LA4, Ab4, G4,
                Gb4, E4, F4, Bb3, Eb4, D4, Db4,
                C4, B3, C4, F3, Ab3, F3, C4,
                LA3, F3, C4, LA3
               };

int beats3[] = {Q, Q, E + S, S,
                Q, E + S, S, H,
                Q, Q, Q, E + S, S,
                Q, E + S, S, H,
                Q, E + S, S, Q, E + S, S,
                S, S, E, E, Q, E + S, S,
                S, S, E, E, Q, E + S, S,
                Q, E + S, S, H,
                Q, E + S, S, Q, E + S, S,
                S, S, E, E, Q, E + S, S,
                S, S, E, E, Q, E + S, S,
                Q, E + S, S, H
               };

int notes4[] = {C4, C4, G4, G4, LA4, LA4, G4,
                F4, F4, E4, E4, D4, D4, C4,
                G4, G4, F4, F4, E4, E4, D4,
                G4, G4, F4, F4, E4, E4, D4,
                C4, C4, G4, G4, LA4, LA4, G4,
                F4, F4, E4, E4, D4, D4, C4
               };

int beats4[] = {Q, Q, Q, Q, Q, Q, H,
                Q, Q, Q, Q, Q, Q, H,
                Q, Q, Q, Q, Q, Q, H,
                Q, Q, Q, Q, Q, Q, H,
                Q, Q, Q, Q, Q, Q, H,
                Q, Q, Q, Q, Q, Q, H
               };
*/

// Initialize Servo library
Servo servo1;
Servo servo2;

// Global Control Commands
int start_playing = 0;
int track_number = 0;

// Variables for storing the sensor data.
// Read potentialmeter value
int volume = 0;
int volume_mod = 0;
// Detect glass cups
bool has_glass = true;
// Read illuminance levels, connect light sensor to A0
float lux = 0;
// Glass distance
long distance = 0;
// Control commands from the Slave side
bool system_pause = false;
bool motor_pause = false;

void illuminance_read()
{
  int raw_lux = analogRead(0);
  lux = (float)(1023-raw_lux)*10/raw_lux;

  if (lux < 200) {
    track_number = 1;
  } else if (lux < 400) {
    track_number = 4;
  } else if (lux < 600) {
    track_number = 2;
  } else {
    track_number = 3;
  }

  Serial.print("Level of illuminance:");
  Serial.print(lux);
  Serial.println();

  /*
  if(lux < 400) {
    is_day = false;
    Serial.print("Level of illuminance is dark. its night");
    Serial.print(lux);
    Serial.println();
  } else {
    is_day = true;
    Serial.print("Its day");
    Serial.print(lux);
    Serial.println();
  }*/
}

void volume_read()
{
  volume = analogRead(3);
  volume_mod = map(volume, 0, 1020, 20, 100);

  Serial.print("Current buzzer volume:");
  Serial.print(volume_mod);
  Serial.println();
}

// Detect the glass using ultrasonic sensor. Return true if the glass is present.
bool glass_detect()
{
  long duration = 0;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(0, LOW);
  delayMicroseconds(5);
  digitalWrite(0, HIGH);
  delayMicroseconds(10);
  digitalWrite(0, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(1, HIGH);
 
  // Convert the time into a distance in cm.
  // See the datasheet for more details.
  distance = (duration / 58.2);

  Serial.print(distance);
  Serial.print("cm");
  Serial.println();

  // A distance shorter than 10cm is considered to be an obstacle.
  if (distance <= 10) {
    return true;
  } else {
    return false;
  }
}

// Write current sensor status to the file
void status_write()
{
  FILE *pFile = NULL;
  
  pFile = fopen("/home/root/status.txt", "w");
  if (!pFile) {
    Serial.println("Unable to open the file!");
  }

  // The file contains two numbers separated by a space in a single line: start_playing and track_number.
  fprintf(pFile, "%d %d %d %d %d %d %f\n", start_playing, system_pause, motor_pause, track_number, volume_mod, distance, lux);

  fclose(pFile);
  
}

// Read control commands from the file
void commands_read()
{  
  FILE *pFile = NULL;
  
  pFile = fopen("/home/root/control.txt", "r");
  if (!pFile) {
    Serial.println("Unable to open the file!");
  }

  // The file contains two numbers separated by a space in a single line: start_playing and track_number.
  //fscanf(pFile, "%d %d", &start_playing, &track_number);
  fscanf(pFile, "%d ", &start_playing);

  fclose(pFile);
}

// Drive the servo to beat the glass cups
void servo_beat(int duration)
{
  //Serial.print("Duration:");
  //Serial.print(duration, DEC);
  //Serial.print("\n");
 
  servo1.write(20);
  servo2.write(20);
  delay(100);

  servo1.write(0);
  servo2.write(0);

  delay(duration-100);
}

void setup() 
{ 
  //Initialize serial and wait for port to open:
  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  // Initialize control pins
  pinMode(4, INPUT);
  pinMode(8, OUTPUT); // LSB
  pinMode(9, OUTPUT); // MSB
  pinMode(10, OUTPUT); // Ready - out
  pinMode(11, INPUT);  // Ready - in
  pinMode(12, INPUT); // Pause signal
  //pinMode(13, OUTPUT); // Pause signal

  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(13, LOW);

  // Initialize ultrasonic pins
  // Define inputs and outputs
  pinMode(0, OUTPUT); // Trigger
  pinMode(1, INPUT); // Echo

  digitalWrite(0, LOW);

  // Initialize servo control
  servo1.attach(5);
  servo2.attach(6);

  // Reset the servo to its initial position
  servo1.write(0);
  servo2.write(0);
  delay(100);

  // Slow down the track 3 by 2 times
  for (int i=0; i<sizeof(beats3)/sizeof(int); i++) {
    beats3[i] *= 2;
  }
  // Slow down the track 4 by 2 times
  for (int i=0; i<sizeof(beats4)/sizeof(int); i++) {
    beats4[i] *= 2;
  }
} 
 
void loop() 
{ 
  int current_track = 0;
  int length = 0;
  int *beats = 0;

  // Read control commands from the file
  while (start_playing == 0) {
    commands_read();
  }

  //Serial.print("Start playing? ");
  //Serial.println(start_playing, DEC);
  //Serial.print("Track number: ");
  //Serial.println(track_number, DEC);

  // Select track number
  switch(track_number) {
    case 1:
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      current_track = 1;
      length = sizeof(beats1)/sizeof(int);
      beats = beats1;
      break;
    case 2:
      digitalWrite(8, HIGH);
      digitalWrite(9, LOW);
      current_track = 2;
      length = sizeof(beats2)/sizeof(int);
      beats = beats2;
      break;
    case 3:
      digitalWrite(8, LOW);
      digitalWrite(9, HIGH);
      current_track = 3;
      length = sizeof(beats3)/sizeof(int);
      beats = beats3;
      break;
    case 4:
      digitalWrite(8, HIGH);
      digitalWrite(9, HIGH);
      current_track = 4;
      length = sizeof(beats4)/sizeof(int);
      beats = beats4;
      break;
    default:
      digitalWrite(8, LOW);
      digitalWrite(9, LOW);
      current_track = 1;
      length = sizeof(beats1)/sizeof(int);
      beats = beats1;
      break;
  }

  // Tell the slave device that the Master is standing-by.
  digitalWrite(10, HIGH);
  delay(500);
  
  // Wait till the Slave device responds a ready signal
  while (digitalRead(11) == LOW) {
    Serial.println("Waiting for the reply from the slave...");
  }

  // Loop through each tone in the track
  for (int i=0; i<length; i++) {
    // Record down current sensor status
    status_write();

    // Read control commands from the file again.
    commands_read();
    illuminance_read();
    if (start_playing == 0) {
      break;
    }
    if (current_track != track_number) {
      break;
    }

    // System pause when pin 12 remains HIGH
    while ((system_pause = digitalRead(12)) == HIGH) {
      status_write();
      Serial.println("Waiting for the pin 12 to be LOW from the slave...");
    }
    //digitalWrite(13, LOW);

    // Read potential meter value
    volume_read();
    
    // Play the servo only when the glass is there.
    has_glass = glass_detect();
    //has_glass = true;
    if (has_glass && (motor_pause = digitalRead(4)) == LOW) {
      servo_beat(beats[i]);
    } else {
      delay(beats[i]);
    }

    //servo_beat(beats[i]);
    delay(1 + beats[i]);
    
    //Serial.print("Delay: ");
    //Serial.println(beats[i], DEC);
  }

  start_playing = 0;
  digitalWrite(10, LOW);

  delay(2 * H);
}
