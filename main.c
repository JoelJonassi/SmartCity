/**
 * Atulamente Serve Para Debug
 * @file funcoes.c
 * @author Joel Jonassi
 * @brief Smart City - main
 * @version 0.1
 * @date 2021-12-16
 * @copyright Copyright (c) 2021
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"
#include <locale.h>

int main()
{
    MeioEletrico v[10];
    Pedido  pedido[10];
    int tot = ler_meio_Transporte("C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\2-TipoTransporte.txt", v);
    int tot2 = ler_pedidos("C:\\Users\\Asus\\CLionProjects\\ESI_PI_19698 - REPO\\pi_repository\\1-Pedidos.txt", pedido);
    viewFileFirst(v, tot);
    //viewFileSecond(pedido,tot2);
    float a;
    a = custUtiliz(v ,pedido, 4, 7);
    int  b = removerPedido(pedido, 1, tot2);
    printf("Sucesso -> %.3f", a);
    //viewFileSecond(pedido,tot2);


}


