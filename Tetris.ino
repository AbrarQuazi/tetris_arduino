#include <gamma.h>
#include <RGBmatrixPanel.h>
#include <Adafruit_GFX.h>



// define the wiring of the LED screen
const uint8_t CLK  = 8;
const uint8_t LAT = A3;
const uint8_t OE = 9;
const uint8_t A = A0;
const uint8_t B = A1;
const uint8_t C = A2;



// the following functions are for printing messages
void drawBorder();
void game_over();




// define the wiring of the inputs
const int POTENTIOMETER_PIN_NUMBER = 5;
const int BUTTON_PIN_NUMBER = 10;




// a global variable that represents the LED screen
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);





class Color {
  public:
    int red;
    int green;
    int blue;
    Color() {
      red = 0;
      green = 0;
      blue = 0;
    }
    Color(int r, int g, int b) {
      red = r;
      green = g;
      blue = b;
    }
    uint16_t to_333() const {
      return matrix.Color333(red, green, blue);
    }
};




const Color BLACK(0, 0, 0);
const Color RED(7, 0, 0);
const Color ORANGE(7, 4, 0);
const Color YELLOW(7, 7, 0);
const Color GREEN(0, 7, 0);
const Color BLUE(0, 0, 7);
const Color PURPLE(7, 0, 7);
const Color WHITE(7, 7, 7);
const Color LIME(4, 7, 0);
const Color AQUA(0, 7, 7);




class Sshape {
  public :
  Sshape (){
     x = 0;
     y = 0;
     j = 0;
     cl=PURPLE.to_333();
  }
  Sshape(int x_arg, int y_arg){
   x = x_arg;
   y = y_arg;
   j = 0;
   cl = PURPLE.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg;
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  int get_j() const {
    return j;
  }
  void set_x(int x_arg){
    x = x_arg;
  }


  void erase(){
    draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(PURPLE);       
  }
  void move(){
    y = y + 1;
  }
  void move_up(){
    y = y - 1;
  }
  uint16_t get_color(){
    return cl;
  }
void rotate(int rotates){
  // only values 0 and 1 are valid
  j = rotates % 2;
  }
private:
  int x;
  int y;
  uint16_t cl;

//draws the shape in correct orientation
  int j; 
  void draw_with_rgb(Color color){
   switch(j) {
  case(0): matrix.drawPixel(y-1, x, color.to_333());
        matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
  matrix.drawPixel(y+1, x-1, color.to_333());
break;
  case(1): matrix.drawPixel(y+1, x, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
  matrix.drawPixel(y, x-2, color.to_333());
break;
   }
  }
 };


class Cube {
  public :
  Cube (){
     x = 0;
     y = 0;
     j = 0;
     cl = YELLOW.to_333();
  }
  Cube(int x_arg, int y_arg){
   x = x_arg;
   y = y_arg;
   cl = YELLOW.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg;
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  void set_x(int x_arg){
    x = x_arg;
  }


  void erase(){
    draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(YELLOW);
  }
  void move(){
    y = y + 1;
  
  }
  void move_up(){
    y = y - 1;
  }
  void rotate(int rotates){
    // only values between 0 and 3 are valid
    j = rotates % 4;  
  }
  uint16_t get_color(){
    return cl;
  }
  int get_j(){
    return j;
  }
private:
  int x;
  int y;
  int j;
  uint16_t cl;
//draws the shape in correct orientation
  void draw_with_rgb(Color color){
        matrix.drawPixel(y, x, color.to_333());
        matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
  matrix.drawPixel(y+1, x, color.to_333());
}
  
};
class Jshape {
  public :
  Jshape (){
     x = 0;
     y = 0;
     j = 0;
     cl = BLUE.to_333();
  }
  Jshape(int x_arg, int y_arg){
   x = x_arg;
   y = y_arg;
   j = 0;
   cl = BLUE.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg;
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  void set_x(int x_arg){
    x = x_arg;
  }


  void erase(){
    draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(BLUE);
  }
  void move(){
    y++;
  }
  void move_up(){
    y = y - 1;
  }
  void rotate(int rotates){
    j = rotates % 4;
  }
  int get_j() const {
    return j;
   }
  uint16_t get_color(){
    return cl;
  }
private:
  int x;
  int y;
  int j;
  uint16_t cl;
  //draws the shape in correct orientation
  void draw_with_rgb(Color color){
    switch(j){
     case(0): matrix.drawPixel(y, x, color.to_333());
        matrix.drawPixel(y+1, x, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
  matrix.drawPixel(y+1, x-2, color.to_333());
break;
  case(1): matrix.drawPixel(y-1, x-1, color.to_333());
      matrix.drawPixel(y-1, x, color.to_333());
      matrix.drawPixel(y, x, color.to_333());
  matrix.drawPixel(y+1, x, color.to_333());
break;
case(2): matrix.drawPixel(y, x, color.to_333());
        matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y, x-2, color.to_333());
  matrix.drawPixel(y+1, x-2, color.to_333());
break;
case(3): matrix.drawPixel(y-1, x-1, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
  matrix.drawPixel(y+1, x, color.to_333());
break;
}
  }
  
};


class Zshape {
  public :
  Zshape (){
    x = 0;
    y = 0;
    j = 0;
    cl = RED.to_333();
  }
  Zshape(int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
    j = 0;
    cl = RED.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  void set_x(int x_arg){
    x = x_arg;
  }
  void erase(){
      draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(RED);    
  }
  void move(){
    y++;
  }
  void move_up(){
    y = y - 1;
  }
  void rotate(int rotates){
    // only values between 0 and 3 are valid
    j = rotates % 2;
  }
  int get_j() const {
    return j;
  }
  uint16_t get_color(){
    return cl;
  }

private:
  int x;
  int y;
  int j;
  uint16_t cl;
  //draws the shape in correct orientation
  void draw_with_rgb(Color color){
      switch(j) {
  case(0): matrix.drawPixel(y-1, x-1, color.to_333());
        matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y, x, color.to_333());
  matrix.drawPixel(y+1, x, color.to_333());
break;
  case(1): matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
  matrix.drawPixel(y+1, x-2, color.to_333());
break;
}
  }
};
class Tshape {
  public :
  Tshape (){
    x = 0;
    y = 0;
    j = 0;
    cl = LIME.to_333();
  }
  Tshape(int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
    j = 0;
    cl = LIME.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  void set_x(int x_arg){
    x = x_arg;
  }

   void erase(){
    draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(LIME);  
  }
  void move(){
    y++;
  }
  void move_up(){
    y = y - 1;
  }
  void rotate(int rotates){
    j = rotates % 4;
  }
  int get_j() const {
    return j;
  }
  uint16_t get_color(){
    return cl;
  }

private:
  int x;
  int y;
  int j;
  uint16_t cl;
//draws the shape in correct orientation
  void draw_with_rgb(Color color) {
    switch(j){
    case(0): matrix.drawPixel(y, x, color.to_333());
          matrix.drawPixel(y+1, x, color.to_333());
          matrix.drawPixel(y+2, x, color.to_333());
          matrix.drawPixel(y+1, x-1, color.to_333());
          break;
    case(1): matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y, x-2, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
      break;
    case(2): matrix.drawPixel(y-1, x-1, color.to_333());
        matrix.drawPixel(y, x-1, color.to_333());
        matrix.drawPixel(y+1, x-1, color.to_333());
        matrix.drawPixel(y, x, color.to_333());
        break;
     case(3): matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
      matrix.drawPixel(y, x-2, color.to_333());
      matrix.drawPixel(y-1, x-1, color.to_333());
      break;
    }
  }
};

class Lshape {
  public :
  Lshape (){
 x = 0;
 y = 0;
  j = 0;
  cl = ORANGE.to_333();
}
  Lshape(int x_arg, int y_arg){
x = x_arg; 
y = y_arg;
j = 0;
cl = ORANGE.to_333();


}
  void initialize (int x_arg, int y_arg){
x = x_arg; 
y = y_arg;

}
  int get_x() const{
  return x;
}
  int get_y() const{
  return y;

}
void set_x(int x_arg){
    x = x_arg;
}

void erase(){
draw_with_rgb(BLACK);
}
  void draw(){
draw_with_rgb(ORANGE);

}
  void move(){
y++;
}
 void move_up(){
    y = y - 1;
}
void rotate(int rotates){
   j = rotates % 4;
}
int get_j() const {
return j;
}

uint16_t get_color(){
  return cl;
}

private:
  int x;
  int y;
int j;
uint16_t cl;

//draws the shape in correct orientation
void draw_with_rgb(Color color) {
 switch(j){
case(0): matrix.drawPixel(y+1, x, color.to_333());
        matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
  matrix.drawPixel(y, x-2, color.to_333());
break;
  case(1): matrix.drawPixel(y-1, x, color.to_333());
      matrix.drawPixel(y-1, x-1, color.to_333());
      matrix.drawPixel(y, x-1, color.to_333());
  matrix.drawPixel(y+1, x-1, color.to_333());
break;
case(2): matrix.drawPixel(y, x-2, color.to_333());
        matrix.drawPixel(y+1, x-2, color.to_333());
      matrix.drawPixel(y+1, x-1, color.to_333());
  matrix.drawPixel(y+1, x, color.to_333());
break;
case(3): matrix.drawPixel(y-1, x, color.to_333());
      matrix.drawPixel(y, x, color.to_333());
      matrix.drawPixel(y+1, x, color.to_333());
  matrix.drawPixel(y+1, x-1, color.to_333());
break;
}
  }
};

class Ishape {
  public :
  Ishape (){
    x = 0;
    y = 0;
    j = 0;
    cl = AQUA.to_333();
  }
  Ishape(int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
    j = 0;
    cl = AQUA.to_333();
  }
  void initialize (int x_arg, int y_arg){
    x = x_arg; 
    y = y_arg;
  }
  int get_x() const{
    return x;
  }
  int get_y() const{
    return y;
  }
  int get_j() const{
    return j;
  }
  void set_x(int x_arg){
    x = x_arg;
  }


  void erase(){
    draw_with_rgb(BLACK);
  }
  void draw(){
    draw_with_rgb(AQUA);
  }
  void move(){
    y++;
  }
  void move_up(){
    y = y - 1;
  }
  void rotate(int rotates){
    j=rotates%2;
   }
   uint16_t get_color(){
    return cl;
   }
  private:
  int x;
  int y;
  int j;
  uint16_t cl;

//draws the shape in correct orientation
  void draw_with_rgb(Color color){
    switch(j){
      case(0):matrix.drawPixel(y-1, x-1, color.to_333());
        matrix.drawPixel(y, x-1, color.to_333());
        matrix.drawPixel(y+1, x-1, color.to_333());
        matrix.drawPixel(y+2, x-1, color.to_333());
        break;
      case(1): matrix.drawPixel(y, x, color.to_333());
         matrix.drawPixel(y, x-1, color.to_333());
         matrix.drawPixel(y, x-2, color.to_333());
         matrix.drawPixel(y, x-3, color.to_333());
         break;
      }
   }
  
};

//sets up the game
class Game {
public: 
void setup() {
  time = 0;
  shapeNum = random(1,8);
  tempShape = 1;
  rotato = 0;
  rowClear = false;
  rowCount = 0;
  linesCleared = 0;
  clearedRow = 0;
  hasShape = false;
  blk=BLACK.to_333();
  for(int i = 0; i < 20; i++){
    for(int j = 0; j < 10; j++){
      boardArray[i][j] = BLACK.to_333();
    }
  }
 }
 int get_lines()const{
  return linesCleared;
 }
 void setup_shape(){
  rotato = 0;
  shapeNum = random(1,8);
  while(tempShape == shapeNum){
    shapeNum = random(1,8);
  }
  if(shapeNum == 1 && time == 0){
    shapeNum=random(1,8);
  }
  tempShape = shapeNum;
 }
 //the main body that plays tetris
void loop(int potentiometer_value, bool button_pressed) {
  drawBorder();
  if(hasShape == false){
    setup_shape();
    rotato=0;
    switch (shapeNum){
      case 1:
        s = { 3,1 };
        s.draw();
        break;
      case 2:
        z = { 3,1 };
        z.draw();
        break;
      case 3:
        t = { 3,0 };
        t.draw();
        break;
      case 4:
        i = { 3,1 };
        i.draw();
        break;
      case 5:
        j = { 3,0 };
        j.draw();
        break;
      case 6: 
        l = {4,0};
        l.draw();
        break;
      case 7:
        c = {5,0};
        c.draw();
        break;
    }
    hasShape = true;
  }
  //moves left
   if(potentiometer_value<=400){
  
    switch (shapeNum){
      case 1:
        if(s.get_x()<9&&s.get_j()==0){
          if(boardArray[s.get_y()-1][s.get_x()+1]==blk&&
            boardArray[s.get_y()][s.get_x()+1]==blk&&
            boardArray[s.get_y()+1][s.get_x()]==blk){
              s.erase();
              s.set_x(s.get_x()+1);
              s.draw();
              delay(200);
            }
        }
        else if(s.get_x()<9&&s.get_j()==1){
          if(boardArray[s.get_y()+1][s.get_x()+1]==blk&&
          boardArray[s.get_y()][s.get_x()]==blk){
           s.erase();
            s.set_x(s.get_x()+1);
            s.draw();
             delay(200);
          }
        }
        break;
      case 2:
        if(z.get_x()<9&&z.get_j()==0){
          if(boardArray[z.get_y()][z.get_x()+1]==blk&&
          boardArray[z.get_y()+1][z.get_x()+1]==blk&&
          boardArray[z.get_y()-1][z.get_x()]==blk){
           z.erase();
           z.set_x(z.get_x()+1);
          z.draw();
          delay(200);
          }
        }
        else if(z.get_x()<9 &&z.get_j()==1){
          if(boardArray[z.get_y()][z.get_x()+1]==blk&&
          boardArray[z.get_y()+1][z.get_x()]==blk){
           z.erase();
           z.set_x(z.get_x()+1);
            z.draw();
            delay(200);
          }
        }
        break;
      case 3:
        if(t.get_x()<9&&t.get_j()==0){
          if(boardArray[t.get_y()][t.get_x()+1]==blk&&
           boardArray[t.get_y()+1][t.get_x()+1]==blk&&
            boardArray[t.get_y()+2][t.get_x()+1]==blk){
              t.erase();
              t.set_x(t.get_x()+1);
              t.draw();
              delay(200);
          }
        }
        else if (t.get_x()<9&&t.get_j()==1){
          if(boardArray[t.get_y()][t.get_x()+1]==blk&&
          boardArray[t.get_y()+1][t.get_x()]==blk){
            t.erase();
            t.set_x(t.get_x()+1);
            t.draw();
            delay(200);
          }
        }
        else if (t.get_x()<9&&t.get_j()==2){
          if(boardArray[t.get_y()][t.get_x()+1]==blk&&
          boardArray[t.get_y()+1][t.get_x()]==blk&&
          boardArray[t.get_y()-1][t.get_x()]==blk){
            t.erase();
            t.set_x(t.get_x()+1);
            t.draw();
            delay(200);
          }
        }
        else if (t.get_x()<9&&t.get_j()==3){
          if(boardArray[t.get_y()][t.get_x()+1]==blk&&
          boardArray[t.get_y()-1][t.get_x()]==blk){
            t.erase();
            t.set_x(t.get_x()+1);
            t.draw();
            delay(200);
          }
        }
        break;
      case 4:
        if(i.get_x()<10&&i.get_j()==0){
          if(boardArray[i.get_y()-1][i.get_x()]==blk&&
          boardArray[i.get_y()][i.get_x()]==blk&&
          boardArray[i.get_y()+1][i.get_x()]==blk&&
          boardArray[i.get_y()+2][i.get_x()]==blk){
            i.erase();
            i.set_x(i.get_x()+1);
            i.draw();
            delay(200);
          }
        }
        else if(i.get_x()<9&&i.get_j()==1){
          if(boardArray[i.get_y()][i.get_x()+1]==blk){
            i.erase();
            i.set_x(i.get_x()+1);
            i.draw();
            delay(200);
          }
        }
        break;
      case 5:
        if(j.get_x()<9&&j.get_j()==0){
          if(boardArray[j.get_y()][j.get_x()+1]==blk&&
          boardArray[j.get_y()+1][j.get_x()+1]==blk){
            j.erase();
            j.set_x(j.get_x()+1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()<9&&j.get_j()==1){
          if(boardArray[j.get_y()-1][j.get_x()+1]==blk&&
          boardArray[j.get_y()][j.get_x()+1]==blk&&
          boardArray[j.get_y()+1][j.get_x()+1]==blk){
            j.erase();
            j.set_x(j.get_x()+1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()<9&&j.get_j()==2){
          if(boardArray[j.get_y()][j.get_x()+1]==blk&&
          boardArray[j.get_y()+1][j.get_x()-1]==blk){
            j.erase();
            j.set_x(j.get_x()+1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()<9&&j.get_j()==3){
          if(boardArray[j.get_y()+1][j.get_x()+1]==blk&&
          boardArray[j.get_y()][j.get_x()]==blk&&
          boardArray[j.get_y()-1][j.get_x()]==blk){
            j.erase();
            j.set_x(j.get_x()+1);
            j.draw();
            delay(200);
          }
        }
        break;
      case 6: 
        if(l.get_x()<9&&l.get_j()==0){
          if(boardArray[l.get_y()+1][l.get_x()+1]==blk&&
           boardArray[l.get_y()][l.get_x()+1]==blk){
            l.erase();
            l.set_x(l.get_x()+1);
            l.draw();
            delay(200);
          }
        }
        else if(l.get_x()<9&&l.get_j()==1){
          if(boardArray[l.get_y()-1][l.get_x()+1]==blk&&
          boardArray[l.get_y()][l.get_x()]==blk&&
          boardArray[l.get_y()+1][l.get_x()]==blk){
            l.erase();
            l.set_x(l.get_x()+1);
            l.draw();
            delay(200);
          }
        }
        else if(l.get_x()<9&&l.get_j()==2){
          if(boardArray[l.get_y()+1][l.get_x()+1]==blk&&
          boardArray[l.get_y()][l.get_x()-1]==blk){
            l.erase();
            l.set_x(l.get_x()+1);
            l.draw();
            delay(200);
          }
        }
        else if(l.get_x()<9&&l.get_j()==3){
          if(boardArray[l.get_y()-1][l.get_x()+1]==blk&&
          boardArray[l.get_y()][l.get_x()+1]==blk&&
          boardArray[l.get_y()+1][l.get_x()+1]==blk){
            l.erase();
            l.set_x(l.get_x()+1);
            l.draw();
            delay(200);
          }
        }
        break;
      case 7:
        if(c.get_x()<9){
          if(boardArray[c.get_y()][c.get_x()+1]==blk&&
          boardArray[c.get_y()+1][c.get_x()+1]==blk){
            c.erase();
            c.set_x(c.get_x()+1);
            c.draw();
            delay(200);
          }
        }
        break;
        }
  }
  //moves right
  else if(potentiometer_value>=680){
      
      switch (shapeNum){
        case 1:
          if(s.get_x()>1&&s.get_j()==0){
            if(boardArray[s.get_y()][s.get_x()-2]==blk&&
            boardArray[s.get_y()+1][s.get_x()-2]==blk&&
            boardArray[s.get_y()-1][s.get_x()-1]==blk){
              s.erase();
              s.set_x(s.get_x()-1);
              s.draw();
              delay(200);
            }
          }
          else if(s.get_x()>2&&s.get_j()==1){
            if(boardArray[s.get_y()][s.get_x()-3]==blk&&
            boardArray[s.get_y()+1][s.get_x()-2]==blk){
              s.erase();
              s.set_x(s.get_x()-1);
              s.draw();
             delay(200);
            }
          }
          break;
        case 2:
          if(z.get_x()>1&&z.get_j()==0){
            if(boardArray[z.get_y()-1][z.get_x()-2]==blk&&
            boardArray[z.get_y()][z.get_x()-2]==blk&&
            boardArray[z.get_y()+1][z.get_x()-1]==blk){
              z.erase();
              z.set_x(z.get_x()-1);
              z.draw();
              delay(200);
            }
          }
          else if(z.get_x()>2&&z.get_j()==1){
            if(boardArray[z.get_y()+1][z.get_x()-3]==blk&&
            boardArray[z.get_y()][z.get_x()-2]==blk){
              z.erase();
              z.set_x(z.get_x()-1);
              z.draw();
              delay(200);
            }
          }
         break;
      case 3:
        if(t.get_x()>1&&t.get_j()==0){
          if(boardArray[t.get_y()+1][t.get_x()-2]==blk&&
          boardArray[t.get_y()+2][t.get_x()-1]==blk&&
          boardArray[t.get_y()][t.get_x()-1]==blk){
            t.erase();
            t.set_x(t.get_x()-1);
            t.draw();
            delay(200);
          }
        }
        else if(t.get_x()>2&&t.get_j()==1){
          if(boardArray[t.get_y()][t.get_x()-3]==blk&&
          boardArray[t.get_y()+1][t.get_x()-2]==blk){
            t.erase();
            t.set_x(t.get_x()-1);
            t.draw();
            delay(200);
          }
        }
        else if(t.get_x()>1&&t.get_j()==2){
          if(boardArray[t.get_y()-1][t.get_x()-2]==blk&&
            boardArray[t.get_y()][t.get_x()-2]==blk&&
            boardArray[t.get_y()+1][t.get_x()-2]==blk){
              t.erase();
              t.set_x(t.get_x()-1);
              t.draw();
              delay(200);
          }
        }
        else if(t.get_x()>2&&t.get_j()==3){
          if(boardArray[t.get_y()][t.get_x()-3]==blk&&
          boardArray[t.get_y()-1][t.get_x()-2]==blk){
            t.erase();
            t.set_x(t.get_x()-1);
            t.draw();
            delay(200);
          }
        }
        break;
      case 4:
        if(i.get_x()>1&&i.get_j()==0){
          if(boardArray[i.get_y()-1][i.get_x()-2]==blk&&
          boardArray[i.get_y()][i.get_x()-2]==blk&&
          boardArray[i.get_y()+1][i.get_x()-2]==blk&&
          boardArray[i.get_y()+2][i.get_x()-2]==blk){
            i.erase();
            i.set_x(i.get_x()-1);
            i.draw();
            delay(200);
          }
        }
        else if(i.get_x()>3&&i.get_j()==1){
          if(boardArray[i.get_y()][i.get_x()-4]==blk){
            i.erase();
            i.set_x(i.get_x()-1);
            i.draw();
            delay(200);
          }
        }
        break;
      case 5:
        if(j.get_x()>2&&j.get_j()==0){
          if(boardArray[j.get_y()+1][j.get_x()-3]==blk&&
          boardArray[j.get_y()][j.get_x()-1]==blk){
            j.erase();
            j.set_x(j.get_x()-1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()>1&&j.get_j()==1){
          if(boardArray[j.get_y()-1][j.get_x()-2]==blk){
            j.erase();
            j.set_x(j.get_x()-1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()>2&&j.get_j()==2){
          if(boardArray[j.get_y()][j.get_x()-3]==blk&&
        boardArray[j.get_y()+1][j.get_x()-3]==blk){
            j.erase();
            j.set_x(j.get_x()-1);
            j.draw();
            delay(200);
          }
        }
        else if(j.get_x()>1&&j.get_j()==3){
          if(boardArray[j.get_y()-1][j.get_x()-2]==blk&&
          boardArray[j.get_y()][j.get_x()-2]==blk&&
          boardArray[j.get_y()+1][j.get_x()-2]==blk){
            j.erase();
            j.set_x(j.get_x()-1);
            j.draw();
            delay(200);
          }
        }
         break;
      case 6: 
        if(l.get_x()>2&&l.get_j()==0){
          if(boardArray[l.get_y()][l.get_x()-3]==blk&&
          boardArray[l.get_y()+1][l.get_x()-1]==blk){
            l.erase();
            l.set_x(l.get_x()-1);
            l.draw();
            delay(200);
          }
        }
        else if(l.get_x()>1&&l.get_j()==1){
          if(boardArray[l.get_y()-1][l.get_x()-2]==blk&&
          boardArray[l.get_y()][l.get_x()-2]==blk&&
          boardArray[l.get_y()+1][l.get_x()-2]==blk){
            l.erase();
            l.set_x(l.get_x()-1);
            l.draw();
            delay(200);
          }
        }
        else if(l.get_x()>2&&l.get_j()==2){
          if(boardArray[l.get_y()][l.get_x()-3]==blk&&
            boardArray[l.get_y()+1][l.get_x()-3]==blk){
              l.erase();
              l.set_x(l.get_x()-1);
              l.draw();
              delay(200);
          }
        }
        else if(l.get_x()>1&&l.get_j()==3){
          if(boardArray[l.get_y()+1][l.get_x()-2]==blk&&
          boardArray[l.get_y()][l.get_x()-1]==blk&&
          boardArray[l.get_y()-1][l.get_x()-1]==blk){
            l.erase();
            l.set_x(l.get_x()-1);
            l.draw();
            delay(200);
          }
        }
        break;
      case 7:
        if(c.get_x()>1){
          if(boardArray[c.get_y()][c.get_x()-2]==blk&&
          boardArray[c.get_y()+1][c.get_x()-2]==blk){
            c.erase();
            c.set_x(c.get_x()-1);
            c.draw();
            delay(200);
          }
          break;
        }
      }
  }
//rotates the shape
  if (button_pressed){
    rotato++;
    switch (shapeNum){
      case 1:
        if (checkRotate()){
         s.erase();
         s.rotate(rotato);
         s.draw();
        }
         delay(200);
         break;
      case 2:
        if (checkRotate() == true){
        z.erase();
        z.rotate(rotato);
        z.draw();
        }
         delay(200);
        break;
      case 3:
          if (checkRotate()){
          t.erase();
          t.rotate(rotato);
          t.draw();
          delay(200);
          }
        break;
      case 4:
        if(checkRotate()){
         i.erase();
         i.rotate(rotato);
         i.draw();
         delay(200);
        }
        break;
      case 5:
        if(checkRotate()){
         j.erase();
         j.rotate(rotato);
         j.draw();
         delay(500);
        }
        break;
      case 6: 
        if(checkRotate()){
        l.erase();
        l.rotate(rotato);
        l.draw();
        delay(500);
        }
        break;
      case 7:
        c.draw();
        delay(500);
        break;
 
      }
    }
 //moves the shapes down
    if((millis()/750)-time>=1){
      time = millis()/750;
      if(hasShape==true){
       switch (shapeNum){
      case 1:
         
         storeShapes();
        break;
      case 2:
        storeShapes();
        break;
      case 3:
        storeShapes();
        break;
      case 4:
        storeShapes();
        break;
      case 5:
        storeShapes();
        break;
      case 6: 
        storeShapes();
        break;
      case 7:
        storeShapes();
        break;
 
      }
    }
   }
   //clears the rows if full
   for(int x=19;x>0;x--){
    for(int i=0;i<10;i++){
      if(boardArray[x][i]!=BLACK.to_333()){
        rowCount++;
        if(rowCount>9){
          rowClear=true;
        }
      }
    }
    rowCount=0;
    if(rowClear==true){
      clear(x);
      linesCleared++;
      rowClear=false;
    }
   }
   for(int i=0;i<10;i++){
    if(boardArray[2][i]!=BLACK.to_333()){
      matrix.fillScreen(BLACK.to_333());
      game_over();
    }
   }
}
 private:
   
   int shapeNum;
   int tempShape;
   int rotato;
   int level;
   int linesCleared;
   int rowCount;
   double time;
   bool hasShape;
   uint16_t boardArray[20][10];
   
   Sshape s;
   Zshape z;
   Tshape t;
   Ishape i;
   Jshape j;
   Lshape l;
   Cube c;
   uint16_t blk;
   int a;
   int b;
   int f;
   int d;
   int e;
   bool rowClear;
   int clearedRow;
   
   
   bool checkRotate (){
switch(shapeNum){
  case 1:
e = s.get_j();
  if (e == 0) {
//checks every point of the new moved x and y variables to see if there are any free spots open 
if(s.get_x()<=1){
  return false;
}
else{
if (boardArray[s.get_y()][s.get_x() - 2] == blk){
        return true;
  }
  else{
    return false;
  }
  }
  }
  else{
    return true;
  }

break;
case 2:
  e=z.get_j();
 if (e == 0) {
if(z.get_x()<=1){
  return false;
}
else{
   if (boardArray[z.get_y() + 1][z.get_x()-2] == blk){
     return true;
  }
  else{
  return false;
  }
}
}
else if (e == 1) {

if(boardArray[z.get_y()-1][z.get_x()-1] == blk){
  if (boardArray[z.get_y()][z.get_x() - 1] == blk){
    if (boardArray[z.get_y()][ z.get_x()] == blk){
      if(boardArray[z.get_y() + 1][z.get_x()] == blk){
        return true;
      }
      }
    } 
  }
  else {
    return false;
  }
}
   
break;
case 3:
e = t.get_j();
  if (e == 0) {
    if(t.get_x() <= 1 || t.get_x() >= 9){
      return false;
    }
    else{
    if(boardArray[t.get_y()][ t.get_x()-2] == blk){
        return true;
      }
else {
return false;
}
}
  }
else if(e==1){
  if(t.get_x() <= 1 || t.get_x() >= 10){
    return false;
  }
  else{
    return true;
  }
}
else if (e == 2) {
if(t.get_x() <= 1 || t.get_x() >= 10){
  return false;
}
else{
if(boardArray[t.get_y()][t.get_x()] ==blk){
  matrix.drawPixel(15,31,RED.to_333());
  if(boardArray[t.get_y()][t.get_x() - 1] ==blk){
    matrix.drawPixel(15,31,BLUE.to_333());
    if(boardArray[t.get_y()][t.get_x() - 2] ==blk){
      matrix.drawPixel(15,31,GREEN.to_333());
      if(boardArray[t.get_y()-1][t.get_x()-1] ==blk){
        return true;
      }
    }
  }
}
else {
return false;
}
}
}
else if(e==3){
  if(t.get_x() <= 1 || t.get_x() >= 9){
    return false;
  }
  else{
    return true;
  }
}
break;
case 4:
  e=i.get_j();
  if(e==0){
    if(i.get_x() <= 2 || i.get_x() >= 10){
      return false;
    }
    else{
    if(boardArray[i.get_y()][i.get_x()-1]==blk&&
    boardArray[i.get_y()][i.get_x()-2]==blk&&
    boardArray[i.get_y()][i.get_x()-3]==blk){
      return true;
    }
    else{
      return false;
    }
    }
  }
    else if(e==1){
      if(i.get_x() <= 1 || i.get_x() >= 10){
        return false;
      }
      else{
        return true;
      }
    }
    break;
  case 5:
    e=j.get_j();
    if(e==1){
      if(j.get_x() <= 1 || j.get_x() >= 9){
        return false;
      }
      else{
      if(boardArray[j.get_y()][j.get_x()-2]==blk&&
      boardArray[j.get_y()+1][j.get_x()-2]==blk){
        return true;
      }
      else{
        return false;
      }
    }
    }
    else if(e==0){
      if(j.get_x() <= 1 || j.get_x() >= 9){
        return false;
      }
      else{
        return true;
      }
    }
    else if(e==2){
      if(j.get_x() <= 1 || j.get_x() >= 10){
        return false;
      }
      else{
        return true;
      }
    }
    else if(e==3){
      if(j.get_x() <= 1 || j.get_x() >= 9){
        return false;
      }
      else{
      if(boardArray[j.get_y()+1][j.get_x()-2]==blk){
        return true;
      }
      else{
        return false;
      }
      }
    }
    break;
   case 6:
    e=l.get_j();
    if(e==1){
      if(l.get_x() <= 1 || l.get_x() >= 9){
        return false;
        }
        else{
      if(boardArray[l.get_y()][l.get_x()-2]==blk&&
      boardArray[l.get_y()+1][l.get_x()-2]==blk){
        return true;
      }
      else{
        return false;
      }
      }
    }
    else if(e==0){
      if(l.get_x() <= 1 || l.get_x() >= 9){
        return false;
      }
      else{
        return true;
      }
    }
    else if(e==2){
      if(l.get_x() <= 1 || l.get_x() >= 10){
        return false;
      }
      else{
        return true;
      }
    }
    else if(e==3){
      if((l.get_x() <= 1 || l.get_x() >= 9)){
        return false;
      }
      else{
      if(boardArray[l.get_y()][l.get_x()-2]==blk){
        return true;
      }
      else{
        return false;
      }
    }
    }
    break;
 }
   }
    
    void clear(int row) {
      for (int i = row ; i > 0; i--){
        for (int j = 9; j >= 0; j--){
          boardArray[i][j]= boardArray[i-1][j];
          matrix.drawPixel(i,j,boardArray[i-1][j]);
        }
      }
    } 


int collide;


void storeShapes() {
collide = 0;
uint16_t cl =BLACK.to_333();
switch(shapeNum){
  
case 1:
s.erase();
s.move();
e = s.get_j();
  if (e == 0) {
//checks every point of the new moved x and y variables to see if there are any free spots open 
if (boardArray[s.get_y() - 1][s.get_x()] != cl || s.get_y()-1 == 20) {
collide++;
}
if (boardArray[s.get_y()][s.get_x()] != cl || s.get_y() == 20) {
collide++;
}
if (boardArray[s.get_y()][s.get_x() - 1] != cl|| s.get_y() == 20){
collide++;
}
if (boardArray[s.get_y() + 1][s.get_x() - 1] != cl || s.get_y()+1 == 20){
collide++;
}
//if there are free spots, it draws the shape
if (collide == 0){
s.draw();
}
//if there are no free spots, it moves the shape back up one, draws it, and stores the shape
else {
s.move_up();
s.draw();
boardArray[s.get_y() - 1][s.get_x()] = s.get_color();
boardArray[s.get_y()][s.get_x()] = s.get_color();
boardArray[s.get_y()][s.get_x() - 1] =s.get_color();
boardArray[s.get_y() + 1][s.get_x() - 1]=s.get_color();
hasShape=false;
}
}
else if (e == 1) {
if (boardArray[s.get_y() + 1][s.get_x()] != cl || s.get_y()+1 == 20){
collide++;
}
if (boardArray[s.get_y() + 1][s.get_x() - 1] != cl || s.get_y()+1 == 20){
collide++;
}
if (boardArray[s.get_y()][s.get_x() - 1] != cl || s.get_y() == 20){
collide++;
}
else if (boardArray[s.get_y()][s.get_x() - 2] !=cl || s.get_y() == 20){
collide++;
}
if (collide == 0){
s.draw();
}
else {
s.move_up();
s.draw();
boardArray[s.get_y() + 1][s.get_x()] = s.get_color();
boardArray[s.get_y() + 1][s.get_x() - 1]=s.get_color();
boardArray[s.get_y()][s.get_x() - 1] =s.get_color();
boardArray[s.get_y()][s.get_x() - 2]=s.get_color();
hasShape=false;
}
}
break;
case 2:
z.erase();
z.move();
e = z.get_j();
 if (e == 0) {




if (boardArray[z.get_y() - 1][z.get_x() - 1] != cl || z.get_y()-1 == 20){
collide++;
}
if (boardArray[z.get_y()][z.get_x() - 1] !=  cl || z.get_y() == 20){
collide++;
}


if (boardArray[z.get_y()][z.get_x()] != cl || z.get_y() == 20){
collide++;
}


if (boardArray[z.get_y() + 1][z.get_x()] != cl || z.get_y()+1 == 20){
collide++;
}
if (collide == 0) {
z.draw();
}
else{
z.move_up();
z.draw();
boardArray[z.get_y() - 1][z.get_x() - 1] = z.get_color();
boardArray[z.get_y()][z.get_x() - 1] = z.get_color();
boardArray[z.get_y()][z.get_x()] = z.get_color();
boardArray[z.get_y() + 1][z.get_x()] = z.get_color();
hasShape=false;
}
}

else if (e == 1) {
a = z.get_x();
b = z.get_y();
if(boardArray[z.get_y()][z.get_x()] != cl || z.get_y() == 20){
collide++;
}

if (boardArray[z.get_y()][z.get_x() - 1] != cl || z.get_y() == 20){
collide++;
}

if (boardArray[z.get_y() + 1][ z.get_x() - 1] != cl || z.get_y()+1 == 20){
collide++;
}

if(boardArray[z.get_y() + 1][z.get_x() - 2] != cl || z.get_y()+1 == 20){
collide++;
}
if (collide == 0){
z.draw();
}
else {
z.move_up();
z.draw();
boardArray[z.get_y()][z.get_x()]= z.get_color();
boardArray[z.get_y()][z.get_x() - 1]=z.get_color();
boardArray[z.get_y() + 1][ z.get_x() - 1] =z.get_color();
boardArray[z.get_y() + 1][z.get_x() - 2]=z.get_color();
hasShape=false;
}
}
break;
case 3:
t.erase();
t.move();


e = t.get_j();
  if (e == 0) {
if(boardArray[t.get_y()][t.get_x()] != cl || t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y() + 1][t.get_x()] !=cl || t.get_y()+1 == 20){
collide++;
}
if(boardArray[t.get_y() + 2][ t.get_x()] !=cl || t.get_y()+2 == 20){
collide++;
}
if(boardArray[t.get_y() + 1][t.get_x() - 1] !=cl || t.get_y()+1 == 20){
collide++;
}
if (collide == 0){
t.draw();
}
else {
t.move_up();
t.draw();
boardArray[t.get_y()][t.get_x()] = t.get_color();
boardArray[t.get_y() + 1][t.get_x()]=t.get_color();
boardArray[t.get_y() + 2][ t.get_x()] =t.get_color();
boardArray[t.get_y() + 1][ t.get_x() - 1]=t.get_color();
hasShape=false;
}
}
else if (e == 1) {
if(boardArray[t.get_y()][t.get_x()] != cl || t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y()][t.get_x() - 1] != cl || t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y()][t.get_x() - 2] != cl || t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y() + 1][ t.get_x() - 1]  != cl || t.get_y()+1 == 20){
collide++;
}
if(collide == 0){
t.draw();
}
else {
t.move_up();
t.draw();
boardArray[t.get_y()][t.get_x()]= t.get_color();
boardArray[t.get_y()][t.get_x() - 1]=t.get_color();
boardArray[t.get_y()][t.get_x() - 2] =t.get_color();
boardArray[t.get_y() + 1][ t.get_x() - 1]=t.get_color();
hasShape=false;
}
}
else if (e == 2) {




if(boardArray[t.get_y() - 1][t.get_x() - 1] != cl || t.get_y()-1 == 20){
collide++;
}
if(boardArray[t.get_y()][t.get_x() - 1] != cl ||t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y() + 1][t.get_x() - 1] != cl || t.get_y()+1 == 20){
collide++;
}

if(boardArray[t.get_y()][t.get_x()] !=cl || t.get_y() == 20){
collide++;

}
if(collide == 0){
t.draw();
}
else {
t.move_up();
t.draw();
boardArray[t.get_y() - 1][t.get_x() - 1] = t.get_color();
boardArray[t.get_y()][t.get_x() - 1] = t.get_color();
boardArray[t.get_y() + 1][t.get_x() - 1] =t.get_color();
boardArray[t.get_y()][t.get_x()]=t.get_color();
hasShape=false;
}
}
else if (e == 3) {
if(boardArray[t.get_y()][t.get_x()] !=cl || t.get_y() == 20){
collide++;
}
if(boardArray[t.get_y()][t.get_x() - 1] != cl|| t.get_y() == 20){
collide++;
}




if(boardArray[t.get_y()][t.get_x() - 2] != cl || t.get_y() == 20){
collide++;
}




if(boardArray[t.get_y() - 1][t.get_x() - 1] != cl || t.get_y()-1 == 20){
collide++;
}




if (collide == 0){
t.draw();
}
else {
t.move_up();
t.draw();
boardArray[t.get_y()][t.get_x()] = t.get_color();
boardArray[t.get_y()][t.get_x() - 1] = t.get_color();
boardArray[t.get_y()][t.get_x() - 2]=t.get_color();
boardArray[t.get_y() - 1][t.get_x() - 1]=t.get_color();
hasShape=false;
}
}
break;
case 6:
l.erase();
l.move();
e = l.get_j();
  if (e == 0) {
if(boardArray[l.get_y() + 1][l.get_x()] !=cl || l.get_y()+1 == 20){
collide++;
}
if(boardArray[l.get_y()][l.get_x()] != cl || l.get_y() == 20){
collide++;
}
if(boardArray[l.get_y()][l.get_x() - 1] != cl || l.get_y() == 20){
collide++;
}
if(boardArray[l.get_y()][l.get_x() - 2] != cl || l.get_y() == 20){
collide++;
}
if (collide == 0){
l.draw();
}
else {
l.move_up();
l.draw();
boardArray[l.get_y() + 1][l.get_x()] = l.get_color();
boardArray[l.get_y()][l.get_x()] = l.get_color();
boardArray[l.get_y()][l.get_x() - 1]=l.get_color();
boardArray[l.get_y()][l.get_x() - 2]=l.get_color();
hasShape=false;
}
}
else if (e == 1) {
if(boardArray[l.get_y() - 1][l.get_x()] != cl || l.get_y()-1 == 20){
collide++;
}
if(boardArray[l.get_y() - 1][l.get_x() - 1] != cl || l.get_y()-1 == 20){
collide++;
}




if(boardArray[l.get_y()][l.get_x() - 1] != cl || l.get_y() == 20){
collide++;
}
if(boardArray[l.get_y() + 1][l.get_x() - 1] != cl || l.get_y()+1 == 20){
collide++;
}
 if(collide == 0){
l.draw();
}
else {
l.move_up();
l.draw();
boardArray[l.get_y() - 1][l.get_x()] = l.get_color();
boardArray[l.get_y() - 1][l.get_x() - 1] = l.get_color();
boardArray[l.get_y()][l.get_x() - 1]=l.get_color();
boardArray[l.get_y() + 1][l.get_x() - 1]=l.get_color();
hasShape=false;
}
}
else if (e == 2) {
if(boardArray[l.get_y()][l.get_x() - 2] != cl || l.get_y() == 20){
collide++;
}
if(boardArray[l.get_y() + 1][l.get_x() - 2] != cl || l.get_y()+1 == 20){
collide++;
}
if(boardArray[ l.get_y() + 1][l.get_x() - 1] != cl || l.get_y()+ 1 == 20){
collide++;
}
if(boardArray[l.get_y() + 1][l.get_x()] !=cl || l.get_y()+1 == 20){
collide++;
}
if (collide == 0){
l.draw();
}
else {
l.move_up();
l.draw();
boardArray[l.get_y()][l.get_x() - 2] = l.get_color();
boardArray[l.get_y() + 1][l.get_x() - 2] = l.get_color();
boardArray[ l.get_y() + 1][l.get_x() - 1]=l.get_color();
boardArray[l.get_y() + 1][l.get_x()]=l.get_color();
hasShape=false;
}
}
else if (e == 3) {
if(boardArray[l.get_y() - 1][l.get_x()] != cl || l.get_y()-1 == 20){
collide++;
}
if(boardArray[ l.get_y()][l.get_x()] != cl || l.get_y() == 20){
collide++;
}
if(boardArray[ l.get_y() + 1][l.get_x()] != cl || l.get_y()+1 == 20){
collide++;
}
if(boardArray[l.get_y() + 1][l.get_x() - 1] != cl || l.get_y()+1 == 20){
collide++;
}
if (collide == 0){
l.draw();
}
else {
l.move_up();
l.draw();
boardArray[l.get_y() - 1][l.get_x()] = l.get_color();
boardArray[ l.get_y()][l.get_x()] = l.get_color();
boardArray[ l.get_y() + 1][l.get_x()]=l.get_color();
boardArray[l.get_y() + 1][l.get_x() - 1]=l.get_color();
hasShape=false;
}
}
break;
case 4:
i.erase();
i.move();
e = i.get_j();
  if (e == 1) {
if(boardArray[ i.get_y()][i.get_x()] != cl || i.get_y() == 20){
collide++;
}




if(boardArray[i.get_y()][ i.get_x() - 1] != cl|| i.get_y() == 20){
collide++;
}
if(boardArray[i.get_y()][ i.get_x() - 2] != cl || i.get_y() == 20){
collide++;
}
if(boardArray[i.get_y()][i.get_x() - 3] !=cl || i.get_y()== 20){
collide++;
}
if (collide == 0){
i.draw();
}
else {
i.move_up();
i.draw();
boardArray[ i.get_y()][i.get_x()] = i.get_color();
boardArray[i.get_y()][ i.get_x() - 1]  = i.get_color();
boardArray[i.get_y()][ i.get_x() - 2]=i.get_color();
boardArray[i.get_y()][i.get_x() - 3]=i.get_color();
hasShape=false;
}
}
else if (e == 0) {

if(boardArray[ i.get_y() - 1][i.get_x() - 1] != cl || i.get_y()-1== 21){
collide++;
}
if(boardArray[i.get_y()][i.get_x() - 1] != cl||i.get_y()==20){
collide++;
}
if(boardArray[i.get_y() + 1][i.get_x() - 1] != cl||i.get_y()==19){
collide++;
}
if(boardArray[i.get_y() + 2][ i.get_x() - 1] != cl||i.get_y()==18){
collide++;
}
if (collide == 0){
i.draw();
}
else {
i.move_up();
i.draw();
boardArray[ i.get_y() - 1][i.get_x() - 1] = i.get_color();
boardArray[i.get_y()][i.get_x() - 1]  = i.get_color();
boardArray[i.get_y() + 1][i.get_x() - 1]=i.get_color();
boardArray[i.get_y() + 2][ i.get_x() - 1]=i.get_color();
hasShape=false;
}
}
break;
case 5:
j.erase();
j.move();




e = j.get_j();
  if (e == 0) {
if(boardArray[j.get_y()][j.get_x()] != cl || j.get_y() == 20){
collide++;
}
if(boardArray[ j.get_y() + 1][j.get_x()] != cl || j.get_y()+1 == 20){
collide++;
}
if(boardArray[j.get_y() + 1][j.get_x() - 1] != cl || j.get_y()+1 == 20){
collide++;
}
if(boardArray[j.get_y() + 1][j.get_x() - 2] != cl || j.get_y()+1 == 20){
collide++;
}
if (collide == 0){
j.draw();
}
else {
j.move_up();
j.draw();
boardArray[j.get_y()][j.get_x()] = j.get_color();
boardArray[ j.get_y() + 1][j.get_x()]  = j.get_color();
boardArray[j.get_y() + 1][j.get_x() - 1]=j.get_color();
boardArray[j.get_y() + 1][j.get_x() - 2]=j.get_color();
hasShape=false;
}
}
else if (e == 1) {
if(boardArray[ j.get_y() - 1][j.get_x() - 1] !=cl || j.get_y()-1 == 20){
collide++;
}
if(boardArray[ j.get_y() - 1][j.get_x()] != cl || j.get_y()-1 == 20){
collide++;
}
if(boardArray[ j.get_y()][j.get_x()] !=cl || j.get_y() == 20){
collide++;
}




if(boardArray[ j.get_y() + 1][ j.get_x()] != cl || j.get_y()+1 == 20){
collide++;
}
if (collide == 0){
j.draw();
}
else {
j.move_up();
j.draw();
boardArray[ j.get_y() - 1][j.get_x() - 1] = j.get_color();
boardArray[ j.get_y() - 1][j.get_x()]  = j.get_color();
boardArray[ j.get_y()][j.get_x()]=j.get_color();
boardArray[ j.get_y() + 1][ j.get_x()]=j.get_color();
hasShape=false;
}
}
else if (e == 2) {
if(boardArray[j.get_y()][j.get_x()] !=cl || j.get_y() == 20){
collide++;
}
if(boardArray[ j.get_y()][j.get_x() - 1] != cl || j.get_y() == 20){
collide++;
}
if(boardArray[j.get_y()][j.get_x() - 2] != cl || j.get_y() == 20){
collide++;
}
if(boardArray[j.get_y() + 1][j.get_x() - 2] != cl || j.get_y()+1 == 200){
collide++;
}
if (collide == 0){
j.draw();
}
else {
j.move_up();
j.draw();
boardArray[j.get_y()][j.get_x()] = j.get_color();
boardArray[ j.get_y()][j.get_x() - 1]  = j.get_color();
boardArray[j.get_y()][j.get_x() - 2]=j.get_color();
boardArray[j.get_y() + 1][j.get_x() - 2] =j.get_color();
hasShape=false;
}
}
else if (e == 3) {
if(boardArray[j.get_y() - 1][j.get_x() - 1] != cl || j.get_y()-1 == 20){
collide++;
}
if(boardArray[j.get_y()][j.get_x() - 1] !=cl || j.get_y() == 20){
collide++;
}




if(boardArray[j.get_y() + 1][ j.get_x() - 1] != cl || j.get_y()+1 == 20){
collide++;
}
if(boardArray[j.get_y() + 1][j.get_x()] !=cl || j.get_y()+1 == 20){
collide++;
}
if (collide == 0){
j.draw();
}
else {
j.move_up();
j.draw();
boardArray[j.get_y() - 1][j.get_x() - 1] = j.get_color();
boardArray[j.get_y()][j.get_x() - 1]  = j.get_color();
boardArray[j.get_y() + 1][ j.get_x() - 1]=j.get_color();
boardArray[j.get_y() + 1][j.get_x()]  =j.get_color();
hasShape=false;
}
}
break;
case 7:
c.erase();
c.move();
e = c.get_j();
  if (e == 0) {
if(boardArray[c.get_y()][ c.get_x()] != cl || c.get_y() == 20){
collide++;
}
if(boardArray[c.get_y()][c.get_x() - 1] != cl || c.get_y() == 20){
collide++;
}
if(boardArray[c.get_y() + 1][c.get_x() - 1] != cl || c.get_y()+1 == 20){
collide++;
}
if(boardArray[c.get_y() + 1][c.get_x()] != cl || c.get_y()+1 == 20){
collide++;
}
if (collide == 0){
c.draw();
}
else {
c.move_up();
c.draw();
boardArray[c.get_y()][ c.get_x()] = c.get_color();
boardArray[c.get_y()][c.get_x() - 1]  = c.get_color();
boardArray[c.get_y() + 1][c.get_x() - 1]=c.get_color();
boardArray[c.get_y() + 1][c.get_x()]  =c.get_color();
hasShape=false;
}
}
}
}
   
};

// a global variable that represents the game Tetris
Game game;

// see http://arduino.cc/en/Reference/Setup
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(12));
  pinMode(BUTTON_PIN_NUMBER, INPUT);
  matrix.begin();
}
// see http://arduino.cc/en/Reference/Loop
void loop() {
  int potentiometer_value = analogRead(POTENTIOMETER_PIN_NUMBER);
  bool button_pressed = (digitalRead(BUTTON_PIN_NUMBER) == HIGH);
  game.loop(potentiometer_value, button_pressed);
}

void game_over() {
  matrix.setCursor(2,0);
  matrix.setTextColor(RED.to_333());
  matrix.print('G');
  matrix.setCursor(10,0);
  matrix.setTextColor(GREEN.to_333());
  matrix.print('A');
  matrix.setCursor(18,0);
  matrix.setTextColor(RED.to_333());
  matrix.print('M');
  matrix.setCursor(26,0);
  matrix.setTextColor(GREEN.to_333());
  matrix.print('E');
  matrix.setCursor(2,8);
  matrix.setTextColor(GREEN.to_333());
  matrix.print('O');
  matrix.setCursor(10,8);
  matrix.setTextColor(RED.to_333());
  matrix.print('V');
  matrix.setCursor(18,8);
  matrix.setTextColor(GREEN.to_333());
  matrix.print('E');
  matrix.setCursor(26,8);
  matrix.setTextColor(RED.to_333());
  matrix.print('R');
  delay(5000);
  matrix.fillScreen(BLACK.to_333());
  matrix.setCursor(0,0);
  matrix.setTextColor(GREEN.to_333());
  matrix.print("Score");
  matrix.setTextColor(RED.to_333());
  matrix.print(game.get_lines());
  delay(100000);
  exit(0);
}
void drawBorder() {
   for (int i = 0; i < 11; i++) {
    for (int j = 20; j < 21; j++) {
      matrix.drawPixel(j, i, WHITE.to_333());
      }
    }
  for (int i = 10; i < 11; i++) {
    for (int j = 0; j < 21; j++) {
      matrix.drawPixel(j, i, WHITE.to_333());
      }
    }
    for (int i = 0; i < 11; i += 2) {
    for (int j = 21; j < 22; j++) {
      matrix.drawPixel(j, i, RED.to_333());
      }
    }
  for (int i = 11; i < 12; i++) {
    for (int j = 0; j < 21; j += 2) {
      matrix.drawPixel(j, i, RED.to_333());
      }
    }
  for (int i = 11; i < 12; i++) {
    for (int j = 0; j < 21; j += 2) {
      matrix.drawPixel(j+1, i, GREEN.to_333());
      }
    }
   for (int i = 0; i < 11; i += 2) {
    for (int j = 21; j < 22; j++) {
      matrix.drawPixel(j, i+1, GREEN.to_333());
      }
    }

  }
