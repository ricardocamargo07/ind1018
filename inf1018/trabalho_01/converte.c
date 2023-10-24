/* Ricardo Stuckert - 1713112 -  3wa */
#include <stdio.h>
#include "converte.h"

int utf2varint(FILE *arq_entrada, FILE *arq_saida){
    unsigned char byte;
    unsigned char byteVarint;
    unsigned int unicode;
    int experado = 0;
    unicode = 0;

    while(fread(&byte,sizeof(byte),1,arq_entrada) == 1){
        if(experado == 0){
            if((byte & 0x80) == 0){
                //se for 0
                unicode =byte;
            }else if((byte & 0xE0) == 192){
                //se for 110
                experado = 1;
                unicode = (byte & 0x1F);
            }else if((byte & 0xF0) == 0xE0){
                //se for 1110
                experado = 2;
                unicode =(byte & 0x0F);
            }else if((byte & 0xF8) == 0xF0){
                //se for 11110
                experado =3;
                unicode = (byte & 0x07);
            }else{
                fprintf(stderr,"Erro na hora de codificar em UFT8\n");
                return -1;
            }
        }else{
            if((byte & 0xC0) == 0x80){
                //se o byte de cotinuacao for valido
                unicode = (unicode << 6) | (byte & 0x3F);
                experado--;
            }else{
                fprintf(stderr,"Erro na hora de codificar em UFT8\n");
                return -1;
            }
        }
        if (experado == 0){
            //escreve no arquivo saida
            while(unicode >= 128){
                byteVarint = (unicode & 0x7F)| 0x80;
                fwrite(&byteVarint,sizeof(byteVarint),1,arq_saida);
                unicode >>= 7;
            }
            byteVarint = unicode;
            fwrite(&byteVarint,sizeof(byteVarint),1,arq_saida);
        }
    }

    if(experado !=0){
        fprintf(stderr,"Erro na hora de codificar em UFT8\n");
        return -1;
    }

    return 0;
    
}

int varint2utf(FILE *arq_entrada, FILE *arq_saida){
    int bytes = 0;
    unsigned char byteVarint;
    unsigned char byteUft[4];
    unsigned int unicode =0;
    int shift = 0;

    while(fread(&byteVarint,sizeof(byteVarint),1,arq_entrada) == 1){
        unicode |= (byteVarint & 0x7F) << shift;
        if(!(byteVarint & 0x80)){
            if(unicode <= 0x7F){
                byteUft[0] = unicode & 0x7F;
                bytes =1;
            }else if(unicode <= 0x7FF){
                byteUft[0] = ((unicode >> 6) & 0X1F) | 0xC0;
                byteUft[1] = (unicode & 0x3F) | 0x80;
                bytes = 2;
            }else if(unicode <= 0xFFFF){
                byteUft[0] = ((unicode >> 12) & 0x0F )| 0xE0;
                byteUft[1] = ((unicode >> 6) & 0X3F) | 0x80;
                byteUft[2] = (unicode & 0x3F) | 0x80;
                bytes = 3;
            }else if (unicode <= 0x10FFFF){
                byteUft[0] = ((unicode >> 18) & 0x07 )| 0xF0;
                byteUft[1] = ((unicode >> 12) & 0x3F )| 0x80;
                byteUft[2] = ((unicode >> 6) & 0X3F )| 0x80;
                byteUft[3] = (unicode & 0x3F) | 0x80;
                bytes = 4;
            }
            //escreve no aquivo
            fwrite(byteUft,sizeof(byteUft),bytes,arq_saida);
            //volta as variaveis para o valor inicial
            unicode = 0;
            shift =0;
        }
        else{
            shift+=7;
        }
    }
    return 0;
}