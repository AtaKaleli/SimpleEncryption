#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int main(){


int op;
char secretCode='A';//has a default value of 'A'
//these b1-b8 represents an 8 bit integer. It is equivalent the binary equivalent of 'A',which is 65

int b8=0,b7=1,b6=0,b5=0,b4=0,b3=0,b2=0,b1=1;//these values can be modified If the user selects option1 and changes the secret code.
int ecB8=0,ecB7=0,ecB6=0,ecB5=0,ecB4=0,ecB3=0,ecB2=0,ecB1=0;//ecB stands for "encrypted bit"
int hexToB8=0,hexToB7=1,hexToB6=0,hexToB5=0,hexToB4=0,hexToB3=0,hexToB2=0,hexToB1=1;//hexToB stands for "hexadecimal to binary bit. This is used in option2-base16"
int base;//this variable used in the 2nd option as a base choice.


do{
    printf("\nHappy Encryption!\n");
    printf("(1)Change the secret code\n");
    printf("(2)Encrypt text\n");
    printf("(3)Quit\n");
    printf("You choose: ");
    scanf("%d",&op);
    while(op<1 || op>3){
        fflush(stdin);
        printf("Please enter an option between 1-3!\n");
        printf("You choose: ");
        scanf("%d",&op);
    }

    switch(op){

case 1:

    fflush(stdin);//clean the buffer before requesting for character input
    printf("You have chosen option 1!\n");
    printf("Which secret code will you use? ");//keep in mind that you must only enter a single character
    scanf("%c",&secretCode);
    while((secretCode<48||secretCode>57) && (secretCode<65||secretCode>90) && (secretCode<97||secretCode>122)){
        fflush(stdin);//clean the buffer before requesting for character input
        printf("\nERROR! Secret code can be either:\n");
        printf("A digit between 0-9\n");
        printf("Uppercase letters\n");
        printf("Lowercase characters\n\n");
        printf("Which secret code will you use? ");
        scanf("%c",&secretCode);
    }

    int rem;//this variable is the remainder when we take modulus 2 of the number
    int number=secretCode;//this hold the integer value of the secret code
    int binaryNumber=0;// this is our final conversion result
    int mult=1;//this is for multiplier
    int count=0;//this is the count of binary number elements

    while(number>0){
        rem=number%2;
        binaryNumber=binaryNumber+(rem*mult);
        mult*=10;
        number/=2;
        count++;
    }

    //as we cant use arrays, I will modify every bit till the number becomes zero

    //this means that the bit8 must remains zero, and I need to modify the bit1 to bit7
    if(count==7){

        b1=binaryNumber%10;
        binaryNumber/=10;
        b2=binaryNumber%10;
        binaryNumber/=10;
        b3=binaryNumber%10;
        binaryNumber/=10;
        b4=binaryNumber%10;
        binaryNumber/=10;
        b5=binaryNumber%10;
        binaryNumber/=10;
        b6=binaryNumber%10;
        binaryNumber/=10;
        b7=binaryNumber%10;
        binaryNumber/=10;
        b8=0;
    }
    //this means that the bit7 and 8 must remains zero, and I need to modify the bit1 to bit6
    else{

        b1=binaryNumber%10;
        binaryNumber/=10;
        b2=binaryNumber%10;
        binaryNumber/=10;
        b3=binaryNumber%10;
        binaryNumber/=10;
        b4=binaryNumber%10;
        binaryNumber/=10;
        b5=binaryNumber%10;
        binaryNumber/=10;
        b6=binaryNumber%10;
        binaryNumber/=10;
        b7=0;
        b8=0;

    }

    //printing the binary equivalent of the secret code.
    printf("Binary equivalent of the chosen code is ");
    printf("%d%d%d%d%d%d%d%d",b8,b7,b6,b5,b4,b3,b2,b1);
    break;

case 2:

    fflush(stdin);
    printf("You have chosen option 2!\n");
    printf("Which base will you use to enter text (base 16/2)? ");
    scanf("%d",&base);
    while(base!=2 && base!=16){
        fflush(stdin);
        printf("Please enter base either 2 or 16! ");
        scanf("%d",&base);
    }

    if(base==2){
        char ch;
        int errorFlag=0,errorBinaryFlag=0;//if error flag equals 1, then user need to enter the text again.
        int asciiValue,lengthCount=0;//length is initialized as -1 as I dont count the enter as a bit.


        while(!errorFlag){
            printf("Please enter the text to encrypt: ");
            fflush(stdin);
            do{

                scanf("%c",&ch);
                asciiValue=ch;


                if(asciiValue!=48&&asciiValue!=49&&asciiValue!=10){//checking whether entered character is either 0 or 1.

                    errorBinaryFlag=1;
                    break;

                }
                if(asciiValue!=10){// I will not count the enter as a character

                    lengthCount++;

                    //applying XOR operation to every bit.
                    if(lengthCount%8==0){
                        if(b1!=asciiValue-48){

                            ecB1=1;
                        }
                        else{

                            ecB1=0;
                        }
                        int encodedText;//this is the decimal value of encoded Text.
                        encodedText=ecB8*pow(2,7)+ecB7*pow(2,6)+ecB6*pow(2,5)+ecB5*pow(2,4)+ecB4*pow(2,3)+ecB3*pow(2,2)+ecB2*pow(2,1)+ecB1*pow(2,0);

                        printf("%c",encodedText);//printing the encoded text
                    }
                    else if(lengthCount%8==7){
                        if(b2!=asciiValue-48){

                            ecB2=1;
                        }
                        else{

                            ecB2=0;
                        }
                    }
                    else if(lengthCount%8==6){
                        if(b3!=asciiValue-48){

                            ecB3=1;
                        }
                        else{
                            ecB3=0;
                        }
                    }
                    else if(lengthCount%8==5){
                        if(b4!=asciiValue-48){

                            ecB4=1;
                        }
                        else{
                            ecB4=0;
                        }
                    }
                    else if(lengthCount%8==4){
                        if(b5!=asciiValue-48){

                            ecB5=1;
                        }
                        else{
                            ecB5=0;
                        }
                    }
                    else if(lengthCount%8==3){
                        if(b6!=asciiValue-48){

                            ecB6=1;
                        }
                        else{
                            ecB6=0;
                        }
                    }
                    else if(lengthCount%8==2){
                        if(b7!=asciiValue-48){

                            ecB7=1;
                        }
                        else{
                            ecB7=0;
                        }
                    }
                    else if(lengthCount%8==1){
                        if(b8!=asciiValue-48){

                            ecB8=1;
                        }
                        else{
                            ecB8=0;
                        }



                    }
                }




            }while(ch!=10);

            //these are error conditions, If there is any, the loop will continue.
            if(errorBinaryFlag==1){
                    printf("Please enter only digits 0 and 1! ");
                    errorBinaryFlag=0;
                    lengthCount=0;
                    continue;
            }
            else{
                if(lengthCount<8){
                    printf("Please enter at least 8 bits for the text! ");
                    lengthCount=0;
                    continue;
                }
                else{
                    errorFlag=1;
                }

            }

        }




    }
    else if(base==16){
                char ch;
                int errorFlag=0,errorHexFlag=0;
                int asciiValue,lengthCount=0;

                printf("Please enter the text to encrypt: ");
                while(!errorFlag){


                fflush(stdin);
                do{

                    scanf("%c",&ch);
                    asciiValue=ch;
                    //the entered character must be between 0-9 or A-F
                    if((asciiValue<48||asciiValue>57)&&(asciiValue<65||asciiValue>70)&&(asciiValue!=10)){

                        errorHexFlag=1;
                        break;

                    }

                    if(asciiValue!=10){
                        lengthCount++;
                    }

                    //here, I declared 0 or 1 to every bit based on the entered charachter from the user
                    if(lengthCount%2==1){
                        switch(ch){
                            case '0':
                                hexToB8=0;
                                hexToB7=0;
                                hexToB6=0;
                                hexToB5=0;
                                break;
                            case '1':
                                hexToB8=0;
                                hexToB7=0;
                                hexToB6=0;
                                hexToB5=1;
                                break;
                            case '2':
                                hexToB8=0;
                                hexToB7=0;
                                hexToB6=1;
                                hexToB5=0;
                                break;
                            case '3':
                                hexToB8=0;
                                hexToB7=0;
                                hexToB6=1;
                                hexToB5=1;
                                break;
                            case '4':
                                hexToB8=0;
                                hexToB7=1;
                                hexToB6=0;
                                hexToB5=0;
                                break;
                            case '5':
                                hexToB8=0;
                                hexToB7=1;
                                hexToB6=0;
                                hexToB5=1;
                                break;
                            case '6':
                                hexToB8=0;
                                hexToB7=1;
                                hexToB6=1;
                                hexToB5=0;
                                break;
                            case '7':
                                hexToB8=0;
                                hexToB7=1;
                                hexToB6=1;
                                hexToB5=1;
                                break;
                            case '8':
                                hexToB8=1;
                                hexToB7=0;
                                hexToB6=0;
                                hexToB5=0;
                                break;
                            case '9':
                                hexToB8=1;
                                hexToB7=0;
                                hexToB6=0;
                                hexToB5=1;
                                break;
                            case 'A':
                                hexToB8=1;
                                hexToB7=0;
                                hexToB6=1;
                                hexToB5=0;
                                break;
                            case 'B':
                                hexToB8=1;
                                hexToB7=0;
                                hexToB6=1;
                                hexToB5=1;
                                break;
                            case 'C':
                                hexToB8=1;
                                hexToB7=1;
                                hexToB6=0;
                                hexToB5=0;
                                break;
                            case 'D':
                                hexToB8=1;
                                hexToB7=1;
                                hexToB6=0;
                                hexToB5=1;
                                break;
                            case 'E':
                                hexToB8=1;
                                hexToB7=1;
                                hexToB6=1;
                                hexToB5=0;
                                break;
                            case 'F':
                                hexToB8=1;
                                hexToB7=1;
                                hexToB6=1;
                                hexToB5=1;
                                break;

                        }
                    }
                    else{
                        switch(ch){
                            case '0':
                                hexToB4=0;
                                hexToB3=0;
                                hexToB2=0;
                                hexToB1=0;
                                break;
                            case '1':
                                hexToB4=0;
                                hexToB3=0;
                                hexToB2=0;
                                hexToB1=1;
                                break;
                            case '2':
                                hexToB4=0;
                                hexToB3=0;
                                hexToB2=1;
                                hexToB1=0;
                                break;
                            case '3':

                                hexToB4=0;
                                hexToB3=0;
                                hexToB2=1;
                                hexToB1=1;
                                break;
                            case '4':
                                hexToB4=0;
                                hexToB3=1;
                                hexToB2=0;
                                hexToB1=0;
                                break;
                            case '5':
                                hexToB4=0;
                                hexToB3=1;
                                hexToB2=0;
                                hexToB1=1;
                                break;
                            case '6':
                                hexToB4=0;
                                hexToB3=1;
                                hexToB2=1;
                                hexToB1=0;
                                break;
                            case '7':
                                hexToB4=0;
                                hexToB3=1;
                                hexToB2=1;
                                hexToB1=1;
                                break;
                            case '8':
                                hexToB4=1;
                                hexToB3=0;
                                hexToB2=0;
                                hexToB1=0;
                                break;
                            case '9':
                                hexToB4=1;
                                hexToB3=0;
                                hexToB2=0;
                                hexToB1=1;
                                break;
                            case 'A':
                                hexToB4=1;
                                hexToB3=0;
                                hexToB2=1;
                                hexToB1=0;
                                break;
                            case 'B':
                                hexToB4=1;
                                hexToB3=0;
                                hexToB2=1;
                                hexToB1=1;
                                break;
                            case 'C':
                                hexToB4=1;
                                hexToB3=1;
                                hexToB2=0;
                                hexToB1=0;
                                break;
                            case 'D':
                                hexToB4=1;
                                hexToB3=1;
                                hexToB2=0;
                                hexToB1=1;
                                break;
                            case 'E':

                                hexToB4=1;
                                hexToB3=1;
                                hexToB2=1;
                                hexToB1=0;
                                break;
                            case 'F':
                                hexToB4=1;
                                hexToB3=1;
                                hexToB2=1;
                                hexToB1=1;
                                break;
                        }
                    if(ch!=10){


                        //If no problem, I will declared encrypted text bits.
                        if(b1!=hexToB1){

                            ecB1=1;
                        }
                        else{

                            ecB1=0;
                        }





                        if(b2!=hexToB2){

                            ecB2=1;
                        }
                        else{

                            ecB2=0;
                        }


                        if(b3!=hexToB3){

                            ecB3=1;
                        }
                        else{
                            ecB3=0;
                        }


                        if(b4!=hexToB4){

                            ecB4=1;
                        }
                        else{
                            ecB4=0;
                        }


                        if(b5!=hexToB5){

                            ecB5=1;
                        }
                        else{
                            ecB5=0;
                        }


                        if(b6!=hexToB6){

                            ecB6=1;
                        }
                        else{
                            ecB6=0;
                        }


                        if(b7!=hexToB7){

                            ecB7=1;
                        }
                        else{
                            ecB7=0;
                        }


                        if(b8!=hexToB8){

                            ecB8=1;
                        }
                        else{
                            ecB8=0;
                        }

                        int encodedText;
                        encodedText=ecB8*pow(2,7)+ecB7*pow(2,6)+ecB6*pow(2,5)+ecB5*pow(2,4)+ecB4*pow(2,3)+ecB3*pow(2,2)+ecB2*pow(2,1)+ecB1*pow(2,0);
                        //printing encoded text
                        printf("%c",encodedText);

                    }


                    }
                }while(ch!=10);


                //these are error conditions, If there is any, the loop will continue.
                if(errorHexFlag==1){
                    printf("Please enter only 0-9 or A-f ");
                    errorHexFlag=0;
                    lengthCount=0;
                    continue;
                }
                else{
                    if(lengthCount<2){
                        printf("Please enter at least 2 bits for the text! ");
                        lengthCount=0;
                        continue;
                    }
                    else{
                        errorFlag=1;
                    }

                }

        }
    }


    break;

    case 3:
        printf("See You!\n");
        break;


}


}while(op!=3);



return 0;

}
