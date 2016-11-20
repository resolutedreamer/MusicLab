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

#define BPM 300
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define E Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

// Define music tracks
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

int g1;
int len1;

int g2;
int len2;

int g3;
int len3;

int g4;
int len4;

int track = 1;

// Pin definition
int soundpin = 3;
int vibpin1 = 12;
int vibpin2 = 13;
int onOroff = 7;
int msb = 6;
int lsb = 5;
int reply = 4;

void detect_track() {
    if (digitalRead(msb) == LOW && digitalRead(lsb) == LOW) {
      track = 1;
    } else if (digitalRead(msb) == LOW && digitalRead(lsb) == HIGH) {
      track = 2;
    } else if (digitalRead(msb) == HIGH && digitalRead(lsb) == LOW) {
      track = 3;
    } else if (digitalRead(msb) == HIGH && digitalRead(lsb) == HIGH) {
      track = 4;
    }
}

void setup() {
  Serial.begin(9600);
  
  g1 = sizeof(beats1);
  len1 = g1 / 4;
  g2 = sizeof(beats2);
  len2 = g2 / 4;
  g3 = sizeof(beats3);
  len3 = g3 / 4;
  g4 = sizeof(beats4);
  len4 = g4 / 4;

  pinMode(soundpin, OUTPUT);

  pinMode(vibpin1, OUTPUT);
  pinMode(vibpin2, OUTPUT);

  pinMode(reply, OUTPUT);

  pinMode(onOroff, INPUT);
  pinMode(msb, INPUT);
  pinMode(lsb, INPUT);
}

void loop() {
  int current_track = 0;
  
  while (digitalRead(onOroff) == LOW) {
    Serial.println("Waiting for the onOroff signal to be HIGH...");
  }

  //if (digitalRead(onOroff) == HIGH) {
    
    detect_track();
    current_track = track;
    Serial.print("Current Track: ");
    Serial.println(track, DEC);
    
    delay(500);
    digitalWrite(reply, HIGH);
    
    int i = 0;
    if (track == 1) {
      while (i < len1 && digitalRead(onOroff) == HIGH && current_track == track) {
        detect_track();
        tone(soundpin, notes1[i], beats1[i]);
        if(i%2 == 0){
          digitalWrite(vibpin2, HIGH);
        } else {
          digitalWrite(vibpin1, HIGH);
        }
        delay(1 + beats1[i]);
        digitalWrite(vibpin1,LOW);
        digitalWrite(vibpin2,LOW);
        i = i + 1;
      }
    } else if (track == 2) {
      while (i < len2 && digitalRead(onOroff) == HIGH && current_track == track) {
        detect_track();
        tone(soundpin, notes2[i], beats2[i]);
        if(i%2 == 0){
          digitalWrite(vibpin2, HIGH);
        } else {
          digitalWrite(vibpin1, HIGH);
        }
        delay(1 + beats2[i]);
        digitalWrite(vibpin1,LOW);
        digitalWrite(vibpin2,LOW);
        i = i + 1;
      }
    } else if (track == 3) {
      while (i < len3 && digitalRead(onOroff) == HIGH && current_track == track) {
        detect_track();
        tone(soundpin, notes3[i], beats3[i]*2);
        if(i%2 == 0){
          digitalWrite(vibpin2, HIGH);
        } else {
          digitalWrite(vibpin1, HIGH);
        }
        delay(1 + beats3[i]);
        digitalWrite(vibpin1,LOW);
        digitalWrite(vibpin2,LOW);
        i = i + 1;
      }
    } else if (track == 4) {
      while (i < len4 && digitalRead(onOroff) == HIGH && current_track == track) {
        detect_track();
        tone(soundpin, notes4[i], beats4[i]*2);
        if(i%2 == 0){
          digitalWrite(vibpin2, HIGH);
        } else {
          digitalWrite(vibpin1, HIGH);
        }
        delay(1 + beats4[i]);
        digitalWrite(vibpin1,LOW);
        digitalWrite(vibpin2,LOW);
        i = i + 1;
      }
    }
    
    track = 0;
    digitalWrite(reply, LOW);

    delay(2 * H);
   
  //}
}
