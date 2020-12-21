#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char ch = ' ';
    char zap = ' ';

    while (1) {
        //START:
        if (scanf("%c", &ch) != 1)
            break;
            //goto END;

        if (ch == '/') {
            zap = ch;

            if (scanf("%c", &ch) != 1) {
                printf("/");
                break;
                //goto END;
            }

            if (ch == '/') {                       //случай когда это однострочный пробел
                while (1) {                        //идем пока не дойдем до конца строки
                    //KOM:
                    if (scanf("%c", &ch) != 1)     //или до конца документа если конец
                        break;
                        //goto END;                  //документа то идем в конец и завершаем
                    if (ch == '\\'){
                        if (scanf("%c", &ch) != 1)     //или до конца документа если конец
                            break;
                            //goto END;                  //документа то идем в конец и завершаем
                        if (ch == '\n') {
                            printf("\n");
                            //goto KOM;
                        }
                        //else
                        //    goto KOM;
                    }
                    else if (ch == '\n') {              //случай когда коммент закончился
                        printf("\n");              //делаем перенос и идем дальше
                        break;
                        //goto START;                //тп на стартовую позицию
                    }
                }
            }
            else if (ch == '*') {                  //случай когда многострочный коммент
                while (1) {
                    //WH:                            //забыл зачем
                    if (scanf("%c", &ch) != 1)     //если конец документа то ладно
                        break;
                        //goto END;                  //идем домой
                    if (ch == '\n')                //увидели перенос - перенесли
                        printf("\n");
                    else if (ch == '*') {          //опа коммент может закончиться
                        //ZVEZDA:                    //тут запоминаем точку отката

                        if (scanf("%c", &ch) != 1) //если конец документа то ладно
                            break;
                            //goto END;              //идем домой

                        if (ch == '/')             //опа кажется коммент закончился идем в начало
                            break;
                            //goto START;            //

                        else if (ch == '\n')       //снова перенос строки ну ладно
                            printf("\n");          //

                        else if (ch == '*') {        //возможно нас тролят
                            while (ch == '*') {
                                if (scanf("%c", &ch) != 1) //если конец документа то ладно
                                    break;
                                //goto END;              //идем домой

                                if (ch == '/')             //опа кажется коммент закончился идем в начало
                                    break;
                                //goto START;            //

                                else if (ch == '\n')       //снова перенос строки ну ладно
                                    printf("\n");          //
                            }
                            if (ch == '/')             //опа кажется коммент закончился идем в начало
                                break;
                            if (ch == '\0')
                                break;
                        }
                            
                            //goto ZVEZDA;           //
                        //else
                        //    goto WH;               //ну раз ничего такого то коммент идет дальше
                    }
                }
            }
            else {
                printf("%c", zap);                 //дошли до случая когда / не был комментом
                printf("%c", ch);                  //тогда пишем все что не написали и идем на старт
                //goto START;
            }
        }
        else
            printf("%c", ch);                      //а это случай когда вообще начинается не с /
        if (ch = '\0')
            break;
    }
    //END:
    return 0;
}
