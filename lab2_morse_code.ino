#define DOT 500
#define DASH 1500
#define LETTER_GAP 1500 // 3 * DASH
#define WORD_GAP 3500 //7 * DOT
#define FREQUENCY 260
#define END_LINE 10

#define PIEZO_PIN 9

char incomingChar;
int morseCode = 0;
int message[30]; 
int timePattern[350];

void setup() {
  Serial.begin(9600);
}

void loop() {
  int numChar = 0;
  int index;
  int pattern = 0;
  int numElement = 0;

  //message read, morse code encoding & decoding 
  while(Serial.available()>=0){

    
    incomingChar = Serial.read(); //read a letter coming in 
    morseCode = morseLookup(incomingChar); //look up its morse code 

    if((int)incomingChar != -1){
      message[numChar] = morseCode; //put morse code corresponding to the message in array message[]
      
      if(incomingChar != END_LINE){ 
        pattern = morseCode; 
        
//        Serial.print("I received: ");
//        Serial.print(incomingChar, DEC);
//        Serial.print("     Morse Code: ");
//        Serial.println(morseCode);

        //decoding 
        while(pattern>0){
          int remainder = pattern % 10; //get the rightmost digit of pattern 
          pattern /= 10; //divide pattern by 10, making the previous second rightmost digit the rightmost digit 

          int singlePattern;

          switch(remainder){ //encoding --> duration 
            case 1: singlePattern = DOT; Serial.print("DOT "); break;
            case 2: singlePattern = DASH; Serial.print("DASH "); break; 
            case 3: singlePattern = WORD_GAP; Serial.print("WORD_GAP "); break;
          }

          timePattern[numElement] = remainder; //add duration to timePattern[]
          numElement++; //increment the number of elements
          timePattern[numElement] = 4; //4 --> gap between letters 
          numElement++;
        }
        
      }else{
        //end of input message
        Serial.println("Done");
        break;
      }

      numChar++;
    }
  }
}

int morseLookup(char letter){
  //1 - dot, 2 - dash, 3 - word gap
  //read form right to left 
  
  switch(letter){
    case 'a':
    case 'A': return 21; //A
    case 'b':
    case 'B': return 1112;//B
    case 'c':
    case 'C': return 1212;//C
    case 'd':
    case 'D': return 112;//D
    case 'e':
    case 'E': return 1; //E
    case 'f':
    case 'F': return 1211;//F
    case 'g':
    case 'G': return 122;//G
    case 'h':
    case 'H': return 1111;//H
    case 'i':
    case 'I': return 11; //I
    case 'j':
    case 'J': return 2221;//J
    case 'k':
    case 'K': return 212;//K
    case 'l':
    case 'L': return 1121;//L
    case 'm':
    case 'M': return 22; //M
    case 'n':
    case 'N': return 12;//N
    case 'o':
    case 'O': return 222;//O
    case 'p':
    case 'P': return 1221;//P
    case 'q':
    case 'Q': return 2122; //Q
    case 'r':
    case 'R': return 121;//R
    case 's':
    case 'S': return 111;//S
    case 't':
    case 'T': return 2;//T
    case 'u':
    case 'U': return 211; //U
    case 'v':
    case 'V': return 2111;//V
    case 'w':
    case 'W': return 221;//W
    case 'x':
    case 'X': return 2112;//X
    case 'y':
    case 'Y': return 2212; //Y
    case 'z':
    case 'Z': return 1122;//Z
    case ' ': return 3; //
  }
  
  return 0;
}

