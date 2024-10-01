#include <iostream>
#include <fstream>
#include <climits>
#include <unistd.h>
#include <cstdlib>
#include <random>
using namespace std;

void rnd(int n, int mat[20][20], int typeOfObject, int &PlayerL, int &PlayerC, int &KillerL, int &KillerC)
{

  int ok = 0;
  while(ok == 0)
    {
      int linie = rand() % n + 1;
      int coloana = rand() % n + 1;

      if(mat[linie][coloana] == 0)
      {
        if(typeOfObject == 3)
        {
          if(mat[linie-1][coloana] == 0 && mat[linie][coloana+1] == 0 && mat[linie-1][coloana+1] == 0 && linie- 1 >= 1 && coloana + 1 <= n)
          {
            ok = 1;
            mat[linie][coloana] = typeOfObject;
            mat[linie-1][coloana] = typeOfObject;
            mat[linie][coloana+1] = typeOfObject;
            mat[linie-1][coloana+1] = typeOfObject;
          }
        }
        else
        {
          ok = 1;
          mat[linie][coloana] = typeOfObject;
        }
        if(typeOfObject == 1)
        {
          PlayerL = linie;
          PlayerC = coloana;
        }
        if(typeOfObject == 4)
          {
            KillerL = linie;
            KillerC = coloana;
          }
          
      }
    }
 } 

void generateMap(int n , int mat[20][20],int &PlayerL, int &PlayerC, int &KillerL, int &KillerC)
{
  // 0 - nimic
  // 1 - player
  // 2 - casa
  // 3 - lac
  // 4 - killer - 🕴
  srand(time(0)); 
  for(int i = 1; i <= 4; ++i)
    rnd(n, mat, i, PlayerL, PlayerC, KillerL, KillerC);
  for(int i = 1; i <= 19; ++i)
    rnd(n, mat, 5, PlayerL, PlayerC, KillerL, KillerC);
  for(int i = 1; i <= 2; ++i)
    rnd(n, mat, 8, PlayerL, PlayerC, KillerL, KillerC);
  for(int i = 1; i <= 7; ++i)
    rnd(n, mat, 7, PlayerL, PlayerC, KillerL, KillerC);
  for(int i = 1; i <= 20; ++i)
    rnd(n, mat, 6, PlayerL, PlayerC, KillerL, KillerC);
  for(int i = 1; i <= 1; ++i)
    rnd(n, mat, 9, PlayerL, PlayerC, KillerL, KillerC);
  
    
}

void displayMap(int n, int mat[20][20])
{
  for(int i = 1; i <= n + 1; ++i)
    cout << "__";
  cout << "\n";
  for(int i = 1; i <= n; ++i)
    {
      for(int j = 0; j <= n+1; ++j)
        if(j == 0 || j == n + 1)
          cout << "|";
        else
        {
          if(mat[i][j] == 1)
            cout << "👨";
          else if(mat[i][j] == 2)
            cout << "🏠";
          else if(mat[i][j] == 3)
            cout << "💧";
          else if(mat[i][j] == 4)
            cout << "🤡";
          else if(mat[i][j] == 5)
            cout << "🌲";
          else if(mat[i][j] == 6)
            cout << "🌳";
          else if(mat[i][j] == 7)
            cout << "🍄";
          else if(mat[i][j] == 8)
            cout << "🪓";
          else if(mat[i][j] == 9)
            cout << "🚗";
          else 
            cout << "  ";
        }
        cout << "\n";
    }
  for(int i = 1; i <= n + 1; ++i)
    cout << "--";
  cout << "\n";
}
void KillerMove(int n, int mat[20][20], int &KillerL, int &KillerC, int &PlayerL, int &PlayerC, int &PlayerMove)
{

  srand(time(NULL));
  int ok = 0;
  while(ok == 0)
  {
      int alegere = rand() % 3;
    if(alegere != 2)
    {
      int move = rand() % 8 + 1;
      if(move == 1 && KillerL - 1 >= 1 && mat[KillerL - 1][KillerC] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL - 1][KillerC] = 4;
        KillerL = KillerL - 1;
        ok = 1;
        }
      if(move == 2 && KillerL + 1 <= n && mat[KillerL + 1][KillerC] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL + 1][KillerC] = 4;
        KillerL = KillerL + 1;
        ok = 1;
        }  
      if(move == 3 && KillerC - 1 >= 1 && mat[KillerL][KillerC - 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL][KillerC - 1] = 4;
        KillerC = KillerC - 1;
        ok = 1;
        }
      if(move == 4 && KillerC + 1 <= n && mat[KillerL][KillerC + 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL][KillerC + 1] = 4;
        KillerC = KillerC + 1;
        ok = 1;
        }
      if(move == 5 && KillerC - 1 >= 1 && KillerL - 1 >= 1 && mat[KillerL - 1][KillerC - 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL - 1][KillerC - 1] = 4;
        KillerC = KillerC - 1;
        KillerL = KillerL - 1;
        ok = 1;
        }
      if(move == 6 && KillerC + 1 <= n && KillerL - 1 >= 1 && mat[KillerL - 1][KillerC + 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL - 1][KillerC + 1] = 4;
        KillerC = KillerC + 1;
        KillerL = KillerL - 1;
        ok = 1;
        }
      if(move == 7 && KillerC + 1 <= n && KillerL + 1 <= n && mat[KillerL + 1][KillerC + 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL + 1][KillerC + 1] = 4;
        KillerC = KillerC + 1;
        KillerL = KillerL + 1;
        ok = 1;
        }
      if(move == 8 && KillerC - 1 >= 1 && KillerL + 1 <= n && mat[KillerL + 1][KillerC - 1] == 0)
        {
        mat[KillerL][KillerC] = 0;
        mat[KillerL + 1][KillerC - 1] = 4;
        KillerC = KillerC - 1;
        KillerL = KillerL + 1;
        ok = 1;
        }
    }
    else
    {
      // incercam sa luam metoda buna
      // trebuie sa trecem prin cele 8 pozitii, sa vedem care sunt libere si sa le adaugam in vector
      // int pozitii[9];
      int dx[9] = {-1, -1, -1, 0,1,1,1,0};
      int dy[9] = {-1, 0, 1, 1, 1, 0, -1, -1};
      int dmin = INT_MAX;
      int vecin_salvat;
      for(int v = 0; v <= 7; ++v)
        {
         int l_urm = KillerL + dx[v];
         int c_urm = KillerC + dy[v];
          int dist = abs(l_urm - PlayerL) + abs(c_urm - PlayerC);
          if(dist < dmin && mat[l_urm][c_urm] == 0)
          {
            dmin = dist;
            vecin_salvat = v;
          }
        }
      // stim in ce vecin mergem adica in vecinul vecin_salvat
      mat[KillerL][KillerC] = 0;
      mat[KillerL + dx[vecin_salvat]][KillerC  + dy[vecin_salvat]] = 4;
      KillerC = KillerC  + dy[vecin_salvat];
      KillerL = KillerL + dx[vecin_salvat];
      ok = 1;
    }
  }
}

void run(int n, int mat[20][20], int &PlayerL, int &PlayerC, int &KillerL, int &KillerC, int &PlayerMove)
{
  int life = 1;
  while(life != 0)
{
  if(mat[PlayerL][PlayerC + 1] == 4|| mat[PlayerL - 1][PlayerC] == 4|| mat[PlayerL + 1][PlayerC] == 4|| mat[PlayerL][PlayerC - 1] == 4|| mat[PlayerL + 1][PlayerC + 1] == 4|| mat[PlayerL + 1][PlayerC + - 1] == 4|| mat[PlayerL - 1][PlayerC + 1] == 4|| mat[PlayerL - 1][PlayerC - 1] == 4)
    life = 0;
  else
{
  char pmove;
  cin >> pmove;
  switch(pmove)
  {
      case 'w':
        if(mat[PlayerL - 1][PlayerC] == 0)
        {
          PlayerMove = 1;
          mat[PlayerL][PlayerC] = 0;
          mat[PlayerL - 1][PlayerC] = 1;
          PlayerL = PlayerL - 1;
        }
      break;
    
      case 'a':
        if(mat[PlayerL][PlayerC - 1] == 0)
          {
            PlayerMove = 2;
            mat[PlayerL][PlayerC] = 0;
            mat[PlayerL][PlayerC - 1] = 1;
            PlayerC = PlayerC - 1;
          }
      break;
      case 's':
          if(mat[PlayerL + 1][PlayerC] == 0)
            {
              PlayerMove = 3;
              mat[PlayerL][PlayerC] = 0;
              mat[PlayerL + 1][PlayerC] = 1;
              PlayerL = PlayerL + 1;
            }
          break;
      case 'd':
            if(mat[PlayerL][PlayerC + 1] == 0)
              {
                PlayerMove = 4;
                mat[PlayerL][PlayerC] = 0;
                mat[PlayerL][PlayerC + 1] = 1;
                PlayerC = PlayerC + 1;
              }
         break;
  }
  for(int i = 1; i <= 75; ++i)
    cout << "\n";
    KillerMove(n, mat, KillerL, KillerC, PlayerL, PlayerC, PlayerMove);
    displayMap(n, mat);
  cout << "\n";
    }
  }
}
// sa facem sa alegem de a bea apa sau a manca, | sau sa mergem si noi incepem cu 5 apa si 5 hunger, iar noi daca avem 0 apa sau hunger o sa murim, si ne intreaba "vrei sa muti caracterul?" sau "vrei sa mananci/ sa bei apa?", 
void show_inventory(int &banane, int &sandwich, int &apple, int &waterbottle, int &mushroom, int &topor)
{
  cout << "INVENTAR:\n";
  if(waterbottle > 1)
  cout << "Ai " << waterbottle << "sticle de apa" << endl;
  else if(waterbottle == 1)
    cout << "Ai o sticla de apa." << endl;
  else if(waterbottle == 0)
    cout << "Nu mai ai apa, du-te la lac si umple-ti sticlele !" << endl;
  if(apple == 1)
    cout << "Ai un mar." << endl;
  else if(apple == 0)
    cout << "Nu mai ai mere." << endl;
  if(banane == 1)
    cout << "Ai o banana." << endl;
  if(banane == 0)
    cout << "Nu mai ai banane." << endl;
  if(mushroom == 1)
    cout << "Ai o ciuperca." << endl;
  if(mushroom == 0)
    cout << "Nu mai ai ciuperci." << endl;
  if(mushroom > 1)
    cout << "Ai " << mushroom << "ciuperci." << endl;
  if(topor == 0)
    cout << "Nu ai niciun topor.";
  if(topor == 1)
    cout << "Ai un topor, poate poti face ceva cu el.";
  if(topor == 1)
    cout << "Ai " << topor << "topoare, poate poti face ceva cu el.";
  
}


int mat[20][20];
int main(){
    int n = 20, PlayerL, PlayerC, KillerL, KillerC, PlayerMove, waterbottle = 2, thirst = 5, hunger = 5, sandwich = 2, apple = 1, banana = 2, mushroom = 0, topor = 0;
    generateMap(n, mat, PlayerL, PlayerC, KillerL, KillerC);
    displayMap(n, mat);
    run(n, mat, PlayerL, PlayerC, KillerL, KillerC, PlayerMove);
    return 0;

}
/*
Idee:
Daca avem un topor, putem sa il folosim in felul urmator:
Daca killerul este langa noi, nu ne omoara, si ne un da un avantaj de 5 pozitii sa ne indepartam de el, killerul stand pe loc in acest timp. Dupa acest timp, killerul poate sa se mute, noi am folosit toporul. Trebuie sa facem rost de altul. Ca sa facem rost de altul, trbeuie sa gasesti celalat topor. 

Cum castigam? -> Barca ni s-a stricat, dar in padure exista o masina abandonata, care are cheile in CASA.


Daca intram intram in casa, sa se afiseze o matrice mai mica care( sa ne arate ce este in casa, de unde putem procura lucruri(mancare, .. )Dar nu vom mai putea avea detalii despre killer(deci este risc mare).




*/