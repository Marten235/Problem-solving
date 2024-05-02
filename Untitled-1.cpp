#include <iostream>
using namespace std;


int numberofmoves (int R , int L,int list[8][8])
{
  int numberofmoves = 0;
  for (int i = -2 ; i <=2 ; i++)
  {
    for(int j = -2 ; j<=2 ; j++)
    {
      if (i == 0 || j == 0 || abs(i) == abs(j) )continue;
      if (R+i < 8 && L+j < 8 && R+i >= 0 && L+j >= 0 && list[R+i][L+j]==0)
      {
        numberofmoves++;
      }
    }
  }
  return numberofmoves;
}

void printl(int list[8][8])
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      cout<<list[i][j]<<" ";
    }
    cout<<endl;
  }
  cout<<"-------------------------------------------------------------------"<<endl;
}

int main()
{
  int list[8][8] = {0};
  int R=0,L=0; // Strating point
  list[R][L]=1;
  int oldL=L , oldR=R;




  for (int k = 0; k < 100; k++)
  {
    int minNOM = 10,newR ,newL,NOM ; 
    for (int i = -2 ; i <=2 ; i++)
    {
      for(int j = -2 ; j<=2 ; j++)
      {
        if (i == 0 || j == 0 || abs(i) == abs(j) )continue;
        if (R+i < 8 && L+j < 8 && R+i >= 0 && L+j >= 0 && list[R+i][L+j]==0)
        {
          NOM=numberofmoves(R+i, L+j,list);
          if (NOM < minNOM)
          {
            minNOM = NOM;
            newR = R+i;
            newL = L+j;
          }
        }

      }
    

    }
    oldR = R;
    oldL=L;
    R=newR;
    L=newL;
    list[R][L]=1;
  
      


    printl(list);
    if (minNOM ==0)
    {R=oldR; L=oldL; break;}
    

  }

  


}
