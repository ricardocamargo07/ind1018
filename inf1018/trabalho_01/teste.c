#include <stdio.h>
#include "converte.h"

int main(void){
    
    FILE* arquivoUft8_entrada = fopen("uft8_demo.txt","rb");
    FILE* arquivoVar_saida = fopen("var_demo.txt","wb");
    
    printf("---------------------------- UFT-8 PARA VARINT ----------------------------\n");
    if(arquivoUft8_entrada == NULL){
        fprintf(stderr,"Erro ao abrir o arquivo de entrada!!\n");
        return -1;
    }else{
        printf("Conseguiu ler o arquivo de entrada!\n");
    }

    if(arquivoVar_saida == NULL){
        fprintf(stderr,"Erro ao abrir o arquivo de saida!!\n");
        return -1;
    }else{
        printf("Conseguiu ler o arquivo de saida!\n");
    }
    printf("Fazendo conversao...\n");
    int resultado = utf2varint(arquivoUft8_entrada, arquivoVar_saida);

    
    if (resultado == -1) {
        fprintf(stderr, "Erro durante a conversão UTF-8 para Varint!\n");
    } else {
        printf("Conversão concluída com sucesso! (UTF-8 para Varint)\n");
    }

    fclose(arquivoUft8_entrada);
    fclose(arquivoVar_saida);

    printf("---------------------------- VARINT PARA UFT-8 ----------------------------\n");
    FILE* arquivoVar_entrada = fopen("var_demo.txt","rb");
    FILE* arquivoUft_saida = fopen("uft_demo_traduzido.txt","wb");

     if(arquivoVar_entrada == NULL){
        fprintf(stderr,"Erro ao abrir o arquivo de entrada!!\n");
        return -1;
    }else{
        printf("Conseguiu ler o arquivo de entrada!\n");
    }

    if(arquivoUft_saida == NULL){
        fprintf(stderr,"Erro ao abrir o arquivo de saida!!\n");
        return -1;
    }else{
        printf("Conseguiu ler o arquivo de saida!\n");
    }
    printf("Fazendo conversao...\n");

     int resultado2 = utf2varint(arquivoVar_entrada, arquivoUft_saida);

    
    if (resultado2 == -1) {
        fprintf(stderr, "Erro durante a conversão Varint para UTF-8!\n");
    } else {
        printf("Conversão concluída com sucesso! (Varint para UTF-8)\n");
    }

    fclose(arquivoVar_entrada);
    fclose(arquivoUft_saida);
    return 0;
}