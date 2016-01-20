void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 11; i++){
    pinMode(i,OUTPUT);
  }
}

char rx_byte = 0;

void loop() {
  if (Serial.available() > 0) {    // is a character available?
    rx_byte = Serial.read();       // get the character
  
  Serial.println(rx_byte);
  
  displayChar(rx_byte);
  

 }

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


