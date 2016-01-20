// 1: dot
// 2: dash 
// 3: gap between words 
// 4: gap between characters 
// 5: gap between elements 
 
 #define DOT 500
 #define DASH 1500
 #define SILENCE 500
 #define LETTER_GAP 1000 // 2 * DASH
 #define WORD_GAP 2000 //4 * DOT
 #define FREQUENCY 500
 #define END_LINE 10
 
 #define PIEZO_PIN 6
 
 char incomingChar;
 int morseCode = 0;
 char message[30]; 
 int timePattern[350];
 
 void setup() {
   //pinMode(PIEZO_PIN, OUTPUT);
   Serial.begin(9600);
   pinMode(2, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(4, OUTPUT);
   pinMode(5, OUTPUT);
   pinMode(7, OUTPUT);
   pinMode(8, OUTPUT);
   pinMode(9, OUTPUT);
   pinMode(10, OUTPUT);
 }
 
 void loop() {
   int numChar = 0;
   int index;
   int pattern = 0;
   int numElement = 0;
   int counter = 0;
 
   //message read, morse code encoding & decoding 
   while(Serial.available()>=0){
 
     
     incomingChar = Serial.read(); //read a letter coming in 
     morseCode = morseLookup(incomingChar); //look up its morse code 
 
     if((int)incomingChar != -1 && (morseCode != -1||incomingChar==END_LINE)){
       message[numChar] = incomingChar; //put morse code corresponding to the message in array message[]
       
       if(incomingChar != END_LINE){ 
         pattern = morseCode; 
         
         //decoding 
         while(pattern>0){
           int remainder = pattern % 10; //get the rightmost digit of pattern 
           pattern /= 10; //divide pattern by 10, making the previous second rightmost digit the rightmost digit 
 
           timePattern[numElement] = remainder; //add duration to timePattern[]
           numElement++; //increment the number of elements
           if(morseCode!=3 && pattern != 0){
            timePattern[numElement] = 5; //5 --> gap between elements 
            numElement++;
           }
         }

         if(morseCode!=3){
           timePattern[numElement] = 4; //4 --> gap between characters
           numElement++;
         }
         
       }else{
         //end of input message
         Serial.println("Done");
         for(index = 0; index<numElement; index++){
          int time;
          Serial.print(timePattern[index]);
          Serial.print(" ");

          switch(timePattern[index]){
            case 1: time = DOT; break;
            case 2: time = DASH; break;
            case 3: time = WORD_GAP; break;
            case 4: time = LETTER_GAP; break;
            case 5: time = SILENCE; break;
            default: time = 0; break;
          }
          //Serial.print(time);
          Serial.print(" ");
          
          if(timePattern[index]==3){
            displayChar(message[counter]);
            Serial.print(message[counter]);
            counter++;
          }
          
//          if(timePattern[index]==1 || timePattern[index]==2){ //if element is a DOT or a DASH, play the tune 
//            tone(PIEZO_PIN, FREQUENCY);
//            delay(time);
//          }
//          else{ //if element is not a DOT or a DASH, then it is a gap
//            noTone(PIEZO_PIN);
//            delay(time);
//          }
          
         }
         Serial.println("");
         Serial.println(numChar);
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
     case '.': return 212121; //full stop
     case ',': return 221122; //comma 
     case ':': return 111222; //colon
     case '-': return 211112; //hyphen or dash 
     default: return -1; //mark as invalid
   }
   
   return 0;
 }

 void displayChar(char c){
    switch(c){
    case 'A': led(1,1,1,0,1,1,1);
    break;
    case 'B': led(0,0,1,1,1,1,1);
    break;
    case 'C': led(1,0,0,1,1,1,0);
    break;
    case 'D': led(0,1,1,1,1,0,1);
    break;
    case 'E': led(1,0,0,1,1,1,1);
    break;
    case 'F': led(1,0,0,0,1,1,1);
    break;
    case 'G': led(1,1,1,1,0,1,1);
    break;
    case 'H': led(0,1,1,0,1,1,1);
    break;
    case 'I': led(0,0,0,0,1,1,0);
    break;
    case 'J': led(0,1,1,1,1,0,0);
    break;
    case 'K': led(0,1,1,0,1,1,1);
    break;
    case 'L': led(0,0,0,1,1,1,0);
    break;
    case 'M': led(1,0,1,0,1,0,0);
    break;
    case 'N': led(0,0,1,0,1,0,1);break;
    case 'O': led(1,1,1,1,1,1,0);break;
    case 'P': led(1,1,1,0,0,1,1);break;
    case 'Q': led(1,1,1,0,0,1,1);break;
    case 'R': led(0,0,0,0,1,0,1);break;
    case 'S': led(1,0,1,1,0,1,1);break;
    case 'T': led(0,0,0,1,1,1,1);break;
    case 'U': led(0,1,1,1,1,1,0);break;
    case 'V': led(0,0,1,1,1,0,0);break;
    case 'W': led(0,1,0,1,0,1,0);break;
    case 'X': led(0,1,1,0,1,1,1);break;
    case 'Y': led(0,1,1,1,0,1,1);break;
    case 'Z': led(1,1,0,1,1,0,1);break;
   //lower case
    case 'a': led(1,1,1,0,1,1,1);break;
    case 'b': led(0,0,1,1,1,1,1);break;
    case 'c': led(1,0,0,1,1,1,0);break;
    case 'd': led(0,1,1,1,1,0,1);break;
    case 'e': led(1,0,0,1,1,1,1);break;
    case 'f': led(1,0,0,0,1,1,1);break;
    case 'g': led(1,1,1,1,0,1,1);break;
    case 'h': led(0,1,1,0,1,1,1);break;
    case 'i': led(0,0,0,0,1,1,0);break;
    case 'j': led(0,1,1,1,1,0,0);break;
    case 'k': led(0,1,1,0,1,1,1);break;
    case 'l': led(0,0,0,1,1,1,0);break;
    case 'm': led(1,0,1,0,1,0,0);break;
    case 'n': led(0,0,1,0,1,0,1);break;
    case 'o': led(1,1,1,1,1,1,0);break;
    case 'p': led(1,1,1,0,0,1,1);break;
    case 'q': led(1,1,1,0,0,1,1);break;
    case 'r': led(0,0,0,0,1,0,1);break;
    case 's': led(1,0,1,1,0,1,1);break;
    case 't': led(0,0,0,1,1,1,1);break;
    case 'u': led(0,1,1,1,1,1,0);break;
    case 'v': led(0,0,1,1,1,0,0);break;
    case 'w': led(0,1,0,1,0,1,0);break;
    case 'x': led(0,1,1,0,1,1,1);break;
    case 'y': led(0,1,1,1,0,1,1);break;
    case 'z': led(1,1,0,1,1,0,1);break;
    //numbers
    case '0':led(1,1,1,1,1,1,0);break;
    case '1':led(0,1,1,0,0,0,0);break;
    case '2':led(1,1,0,1,1,0,1);break;
    case '3':led(1,1,1,1,0,0,1);break;
    case '4':led(0,1,1,0,0,1,1);break;
    case '5':led(1,0,1,1,0,1,1);break;
    case '6':led(1,0,1,1,1,1,1);break;
    case '7':led(1,1,1,0,0,0,0);break;
    case '8':led(1,1,1,1,1,1,1);break;
    case '9':led(1,1,1,1,0,1,1);break;
    //symbols
    case '.':period();break;
    case ' ':led(0,0,0,0,0,0,0);break;
    default: led(1,1,1,1,1,1,1);break;
    }
}

void period(){
  digitalWrite(7,0);
  digitalWrite(10, 1);
  digitalWrite(9, 1);
  digitalWrite(8, 1);
  digitalWrite(4, 1);
  digitalWrite(5, 1);
  digitalWrite(3, 1);
  digitalWrite(2, 1);
}
void led(int a, int b, int c, int d, int e, int f, int g){
  a = 1-a;
  b = 1-b;
  c = 1-c;
  d = 1-d;
  e = 1-e;
  f = 1-f; 
  g = 1-g;
  digitalWrite(10, a);
  digitalWrite(9, b);
  digitalWrite(8, c);
  digitalWrite(4, e);
  digitalWrite(5, d);
  digitalWrite(3, g);
  digitalWrite(2, f);
  digitalWrite(7, 1);
  delay(500);
}
 
