#include <stdio.h>
#include <iostream>
#include<windows.h>
#include<conio.h>
//#include<conio2.h>
//#include<codefun.h>

#define L 10
#define C 20

using namespace std;


int main()
{
    int option, quit = 1, moption, mp1 = 1, mp2 = 1, mp3 = 1;
    int map1win = 0, map2win = 0, map3win = 0;

    while ( quit != 2){

        cout << " *MENU* " << endl << endl; //Índice
        cout << "1- Play" << endl;          // avança para a seleção de mapas
        cout << "2- Instructions" << endl;  // apresenta as instruções
        cout << "3- Demo" << endl;          //demonstração
        cout << "4- Exit" << endl;          //sair
        cout << "5- Credits" << endl;       //creditos
        cout << endl << "Times you finished the map: " << endl << "Map 1: " << map1win << endl;
        cout << "Map 2: " << map2win << endl;
        cout << "Map 3: " << map3win << endl; // contador de vitórias
        cout << endl << "Enter the referent number: ";   //seleção no menu
        cin >> option;

       system("CLS");

       switch ( option ){

            case 4: // sair
                quit = 2;
                break;

            case 5:
                cout << "Produced by: Joao Paulo Kraisch, Bruno Jaciel and Ian Almeida"; //créditos

                Sleep(1200);
                cout << ".";
                Sleep(1200);
                cout << " .";
                Sleep (1200);
                cout << " .";
                system("CLS");
                break;

            case 1:
                cout << "There's three maps available" <<endl << endl; //seleção de mapas
                cout << "1- Mini Cosmus (2)" << endl;
                cout << "2- Mini Cosmus (5)" << endl;
                cout << "3- Mini Cosmus (16)"<< endl << endl;
                cout << "Enter the referent number of the map wanted (1,2 or 3): ";
                cin >> moption;
                cout << endl;



                switch ( moption){

                    case 1: //seleção do primeiro mapa
                       {

                        cout << " Map one selected, loading ";
                        Sleep(900);
                        cout << ".";
                        Sleep(900);
                        cout << " .";
                        Sleep (1200);
                        cout << " .";
                        system("CLS");

                        ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
                        //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
                        CONSOLE_CURSOR_INFO     cursorInfo;
                        GetConsoleCursorInfo(out, &cursorInfo);
                        cursorInfo.bVisible = false; // set the cursor visibility
                        SetConsoleCursorInfo(out, &cursorInfo);
                        //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                        //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                        short int CX=0, CY=0;
                        COORD coord;
                        coord.X = CX;
                        coord.Y = CY;
                        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                        ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


                        char T=219;
                        char tecla;
                        char person = '#';
                        int x=6,y=2;        ///Posicao inicial do personagem
                        char caixa='@';
                        char win='x';
                        char win2='x';
                        char mapa1[9][8]={' ',' ',T,T,T,T,T,' ',     // impressão do mapa 1
                                          T,T,T,' ',' ',' ',T,' ',
                                          T,' ','@',' ',T,' ',T,T,
                                          T,' ',T,' ',' ','x',' ',T,
                                          T,' ',' ',' ',' ',T,' ',T,
                                          T,T,'@',T,'x',' ',' ',T,
                                          ' ',T,' ',' ',' ',T,T,T,
                                          ' ',T,T,T,T,T,' ',' '};

                            int i,j;


                        while(mp1 !=2){
                                mapa1[x][y]=person;
                                for(i=0;i<9;i++){
                                    for(j=0;j<8;j++){

                                        if((caixa != mapa1[3][5]) and (person != mapa1[3][5])){ ///reimpressao dos objetivos, para nao sumir do mapa
                                          mapa1[3][5] = win;
                                       }
                                       if ((caixa != mapa1[5][4]) and (person != mapa1[5][4])){
                                       mapa1[5][4] = win;
                                       }
                                       cout << mapa1[i][j];
                                    }
                                    cout <<endl;
                                }
                                if ((mapa1[3][5]==caixa) and (mapa1[5][4]==caixa)){ ///condicao para vencer
                                                map1win++;
                                                system("CLS");
                                                cout << "You won!!!" << endl; ///comando para o jogo parar caso o objeto chegue no objetivo
                                                Sleep(900);
                                                cout << ".";
                                                Sleep(900);
                                                cout << " .";
                                                Sleep (1200);
                                                cout << " .";
                                                system("CLS");

                                                break;

                            } if( _kbhit() ){
                            tecla = getch();
                                switch(tecla){
                            case 'w': // para cima
                                if (mapa1[x-1][y]==T){
                                            break;
                                          }if(mapa1[x-1][y]== caixa){ ///para nao subir nas caixas
                                            if(mapa1[x-2][y] == caixa || mapa1[x-2][y] == T){ ///para nao subir nas paredes
                                              break;
                                            }
                                            mapa1[x-2][y] = caixa; ///para nao deixar subir duas caixas
                                          }
                                          mapa1[x][y] = ' '; ///para limpe a posicao anterior

                                          x--; ///movimentacao
                                break;
                                case 'a': // esquerda
                                if (mapa1[x][y-1]==T){
                                            break;
                                          }if(mapa1[x][y-1]== caixa){
                                            if(mapa1[x][y-2] == caixa || mapa1[x][y-2] == T){
                                              break;
                                            }
                                            mapa1[x][y-2] = caixa;
                                          }
                                          mapa1[x][y] = ' ';
                                          y--;
                                break;
                                case 's': // para baixo
                                    if (mapa1[x+1][y]==T){
                                            break;
                                          }if(mapa1[x+1][y]== caixa){
                                            if(mapa1[x+2][y] == caixa || mapa1[x+2][y] == T){
                                              break;
                                            }
                                            mapa1[x+2][y] = caixa;
                                          }
                                          mapa1[x][y] = ' ';
                                          x++;
                                break;
                                case 'd': //direita
                                if (mapa1[x][y+1]==T){
                                            break;
                                          }if(mapa1[x][y+1]== caixa){
                                            if(mapa1[x][y+2] == caixa || mapa1[x][y+2] == T){
                                              break;
                                            }
                                            mapa1[x][y+2] = caixa;
                                          }
                                          mapa1[x][y] = ' ';
                                          y++;
                                break;

                                case 'r': // reset
                                    mp1 = 2;
                                    system("CLS");

                                }
                                }


                            /*
                                Recoloca o mapa no inicio da tela,
                                isso faz com que o jogo seja escrito sempre no mesmo lugar.
                                se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
                            */
                            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                        }
                       }

                    break;

                    case 2:
                       {

                        cout << " Map two selected, loading ";

                        Sleep(900);
                        cout << ".";
                        Sleep(900);
                        cout << " .";
                        Sleep (1200);
                        cout << " .";
                        system("CLS");

                        ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
                        //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
                        CONSOLE_CURSOR_INFO     cursorInfo;
                        GetConsoleCursorInfo(out, &cursorInfo);
                        cursorInfo.bVisible = false; // set the cursor visibility
                        SetConsoleCursorInfo(out, &cursorInfo);
                        //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                        //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                        short int CX=0, CY=0;
                        COORD coord;
                        coord.X = CX;
                        coord.Y = CY;
                        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                            ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


                            char T=219;
                            char tecla;
                            char person = '#';
                            int x=6,y=2;
                            char caixa='@';
                            char win='x';
                            char win2='x';
                            char mapa2[9][8]={' ',' ',' ',' ',T,T,T,T,  // impressão do mapa 2
                                              T,T,T,T,T,' ',' ',T,
                                              T,' ',' ',' ','@',' ',' ',T,
                                              T,' ','@','x',T,' ',' ',T,
                                              T,T,' ',T,T,' ',T,T,
                                              T,' ',' ',' ',' ',' ',' ',T,
                                              T,' ',' ',T,' ',' ',' ',T,
                                              T,' ',' ',T,T,T,T,T,
                                              T,T,T,T,' ',' ',' ',' '};

                                int i,j;


                            while(mp2!=2){
                                    mapa2[x][y]=person;
                                    for(i=0;i<9;i++){
                                        for(j=0;j<8;j++){

                                            if((caixa != mapa2[3][2]) and (person != mapa2[3][2])){
                                              mapa2[3][2] = win;
                                           }
                                           if ((caixa != mapa2[3][3]) and (person != mapa2[3][3])){
                                           mapa2[3][3] = win;
                                           }
                                           cout << mapa2[i][j];
                                        }
                                        cout <<endl;
                                    }
                                    if ((mapa2[3][3]==caixa) and (mapa2[3][2]==caixa)){
                                                    map2win++;
                                                    system("CLS");
                                                    cout << "You won!!!" << endl;
                                                    Sleep(900);
                                                    cout << ".";
                                                    Sleep(900);
                                                    cout << " .";
                                                    Sleep (1200);
                                                    cout << " .";
                                                    system("CLS");

                                                    break;

                                } if( _kbhit() ){
                                tecla = getch();
                                    switch(tecla){
                                case 'w': // para cima
                                    if (mapa2[x-1][y]==T){
                                                break;
                                              }if(mapa2[x-1][y]== caixa){
                                                if(mapa2[x-2][y] == caixa || mapa2[x-2][y] == T){
                                                  break;
                                                }
                                                mapa2[x-2][y] = caixa;
                                              }
                                              mapa2[x][y] = ' ';
                                              x--;
                                    break;
                                    case 'a': // esquerda
                                    if (mapa2[x][y-1]==T){
                                                break;
                                              }if(mapa2[x][y-1]== caixa){
                                                if(mapa2[x][y-2] == caixa || mapa2[x][y-2] == T){
                                                  break;
                                                }
                                                mapa2[x][y-2] = caixa;
                                              }
                                              mapa2[x][y] = ' ';
                                              y--;
                                    break;
                                    case 's': //para baixo
                                        if (mapa2[x+1][y]==T){
                                                break;
                                              }if(mapa2[x+1][y]== caixa){
                                                if(mapa2[x+2][y] == caixa || mapa2[x+2][y] == T){
                                                  break;
                                                }
                                                mapa2[x+2][y] = caixa;
                                              }
                                              mapa2[x][y] = ' ';
                                              x++;
                                        break;
                                    case 'd': // direito
                                    if (mapa2[x][y+1]==T){
                                                break;
                                              }if(mapa2[x][y+1]== caixa){
                                                if(mapa2[x][y+2] == caixa || mapa2[x][y+2] == T){
                                                  break;
                                                }
                                                mapa2[x][y+2] = caixa;
                                              }
                                              mapa2[x][y] = ' ';
                                              y++;
                                    break;

                                    case 'r': //reset
                                        mp2 = 2;
                                        system("CLS");
                                    }
                                    }


                                /*
                                    Recoloca o mapa no inicio da tela,
                                    isso faz com que o jogo seja escrito sempre no mesmo lugar.
                                    se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
                                */
                                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                            }

                     }


                break;

            case 3:
                {

                cout << " Map three selected, loading ";

                Sleep(900);
                cout << ".";
                Sleep(900);
                cout << " .";
                Sleep (1200);
                cout << " .";
                system("CLS");

                ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
                //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
                CONSOLE_CURSOR_INFO     cursorInfo;
                GetConsoleCursorInfo(out, &cursorInfo);
                cursorInfo.bVisible = false; // set the cursor visibility
                SetConsoleCursorInfo(out, &cursorInfo);
                //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
                //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                short int CX=0, CY=0;
                COORD coord;
                coord.X = CX;
                coord.Y = CY;
                //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
                ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


                char T=219;
                char tecla;
                char person = '#';
                int x=5,y=2;
                char caixa='@';
                char win='x';
                char win2='x';
                char win3='x';
                char mapa3[9][8]={' ',' ',' ',T,T,T,T,' ',      // impressão do mapa 3
                                  T,T,T,T,' ',' ',T,' ',
                                  T,' ','@',' ','@',' ',T,' ',
                                  T,' ',' ','x',T,' ',T,T,
                                  T,T,' ',T,'x',' ',' ',T,
                                  T,' ',' ',' ',' ','@',' ',T,
                                  T,'x',' ',' ',T,T,T,T,
                                  T,T,T,T,T,' ',' ',' '};

                    int i,j;


                while(mp3!=2){
                        mapa3[x][y]=person;
                        for(i=0;i<9;i++){
                            for(j=0;j<8;j++){

                                if((caixa != mapa3[3][3]) and (person != mapa3[3][3])){
                                  mapa3[3][3] = win;
                               }
                               if ((caixa != mapa3[4][4]) and (person != mapa3[4][4])){
                               mapa3[4][4] = win;
                               }
                               if ((caixa != mapa3[6][1]) and (person != mapa3[6][1])){
                               mapa3[6][1] = win;
                               }
                               cout << mapa3[i][j];
                            }
                            cout <<endl;
                        }
                        if ((mapa3[3][3]==caixa) and (mapa3[4][4]==caixa) and (mapa3[6][1]==caixa)){
                                        map3win++;
                                        system("CLS");
                                        cout << "You won!!!" << endl;
                                        Sleep(900);
                                        cout << ".";
                                        Sleep(900);
                                        cout << " .";
                                        Sleep (1200);
                                        cout << " .";
                                        system("CLS");

                                        break;

                    } if( _kbhit() ){
                    tecla = getch();
                        switch(tecla){
                    case 'w': //para cima
                        if (mapa3[x-1][y]==T){
                                    break;
                                  }if(mapa3[x-1][y]== caixa){
                                    if(mapa3[x-2][y] == caixa || mapa3[x-2][y] == T){
                                      break;
                                    }
                                    mapa3[x-2][y] = caixa;
                                  }
                                  mapa3[x][y] = ' ';
                                  x--;
                        break;
                        case 'a': //esquerda
                        if (mapa3[x][y-1]==T){
                                    break;
                                  }if(mapa3[x][y-1]== caixa){
                                    if(mapa3[x][y-2] == caixa || mapa3[x][y-2] == T){
                                      break;
                                    }
                                    mapa3[x][y-2] = caixa;
                                  }
                                  mapa3[x][y] = ' ';
                                  y--;
                        break;
                        case 's': // para baixo
                            if (mapa3[x+1][y]==T){
                                    break;
                                  }if(mapa3[x+1][y]== caixa){
                                    if(mapa3[x+2][y] == caixa || mapa3[x+2][y] == T){
                                      break;
                                    }
                                    mapa3[x+2][y] = caixa;
                                  }
                                  mapa3[x][y] = ' ';
                                  x++;
                            break;
                        case 'd': //direita
                        if (mapa3[x][y+1]==T){
                                    break;
                                  }if(mapa3[x][y+1]== caixa){
                                    if(mapa3[x][y+2] == caixa || mapa3[x][y+2] == T){
                                      break;
                                    }
                                    mapa3[x][y+2] = caixa;
                                  }
                                  mapa3[x][y] = ' ';
                                  y++;
                        break;

                        case 'r': //reset
                            mp3 = 2;
                            system("CLS");
                        }
                        }


                    /*
                        Recoloca o mapa no inicio da tela,
                        isso faz com que o jogo seja escrito sempre no mesmo lugar.
                        se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
                    */
                    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
                }

            }
        }



            case 2: // instrucoes
                if (mp1 == 2 or mp2 == 2 or mp3 == 2){
                    mp1--;
                    mp2--;
                    mp3--;
                    break;
                }else if (map1win !=0 or map2win !=0 or map3win != 0){
                    break;
                }

                cout << " Your objective is to push the boxes to the needed point, ";
                cout << "if there is more than one box, repeat and put all boxes at the ";
                cout << "right places." << endl << endl;

                Sleep(900);
                cout << ".";
                Sleep(900);
                cout << " .";
                Sleep (1200);
                cout << " .";
                system("CLS");
                break;
            case 3: // sokoban de demonstracao


    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, A SEGUIR.
        //INICIO: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO     cursorInfo;
        GetConsoleCursorInfo(out, &cursorInfo);
        cursorInfo.bVisible = false; // set the cursor visibility
        SetConsoleCursorInfo(out, &cursorInfo);
        //FIM: COMANDOS PARA QUE O CURSOR NÃO FIQUE PISCANDO NA TELA
        //INÍCIO: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
        short int CX=0, CY=0;
        COORD coord;
        coord.X = CX;
        coord.Y = CY;
        //FIM: COMANDOS PARA REPOSICIONAR O CURSOR NO INÍCIO DA TELA
    ///ALERTA: NÃO MODIFICAR O TRECHO DE CÓDIGO, ACIMA.


    //Posição inicial do personagem no console
    int x=3, y=3, x2=5, y2=5, x3=7, y3=16;
    //Variável para recla precionada
    char tecla;
    //Coordenadas para impressão na tela
    int i,j,i2,j2,i3,j3;
    while(1){

        ///Imprime o jogo: mapa e personagem.
        i=0;
        i2=0;
        i3=0;
        while (i<L) {
            j=0;
            j2=0;
            j3=0;
            while (j<C) {
                if (x==i and y==j){
                    cout<<"0";      ///personagem
                } else if (x2==i2 and y2==j2){
                    cout<<"x";      ///caixa - Ian         (printf("%c", 254) criaria uma caixa da tabela ascii) - Joao
                } else if (x3==i3 and y3==j3){
                    cout << "O";    ///objetivo - Ian
                } else if (i==0 or i==L-1 or j==0 or j==C-1){
                    cout<<"°";      ///barreira
                } else {
                    cout<<" ";      ///parte em branco do mapa
                }
                j++;
                j2++;
                j3++;
            }

        cout<<"\n";
        i++;
        i2++;
        i3++;
        }

            if ( x2 == x3 and y2 == y3){
                            system("CLS");
                            cout << "You won!!!" << endl; ///comando para o jogo parar caso o objeto chegue no objetivo - Joao
                            Sleep(900);
                            cout << ".";
                            Sleep(900);
                            cout << " .";
                            Sleep (1200);
                            cout << " .";
                            system("CLS");
                            break;


            } else if ( _kbhit() ){
                tecla = getch();
                switch(tecla)
                {

                    case 'w': ///cima
                        if (x!=1){
                            x--;
                        }   if (x==x2 and y==y2 and x2==1){ ///nao deixa o personagem entrar na caixa (se repete em outras direcoes) - Ian
                                x++;
                            }
                        if ( x==x2 and y==y2 and x2!=1){  ///colisao com a caixa e com o mapa (se repete em outras direcoes) - Joao
                                x2--;
                        }
                    break;
                    case 's': ///baixo
                        if(x != 8 ){
                            x++;
                        }   if (x==x2 and y==y2 and x2==8){
                                x--;
                            }
                        if ( x==x2 and y==y2 and x2!=8){
                                x2++;
                        }
                    break;
                    case 'a': ///esquerda
                        if ( y != 1){
                            y--;
                        }
                            if(x==x2 and y==y2 and y2==1){
                                y++;
                            }


                        if ( x==x2 and y==y2 and y2!=1){
                                y2--;
                        }
                    break;

                    case 'd': ///direita
                        if ( y != 18){
                            y++;
                            if(x==x2 and y==y2 and y2==18){
                                y--;
                            }
                        }
                        if ( x==x2 and y==y2 and y2!=18){
                                y2++;
                        }
                    break;


                }
            }

        /*
            Recoloca o mapa no inicio da tela,
            isso faz com que o jogo seja escrito sempre no mesmo lugar.
            se remover essa linha ele fica imprimindo sempre embaixo do mapa anterior
        */
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }



    }


    }



    return 0;
}
