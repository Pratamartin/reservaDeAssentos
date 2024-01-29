
# Reserva de Assento 

Este programa em C implementa um sistema simples de reservas de assentos em geral. O programa é composto por uma limitaçao de 5 fileiras (A-E) e 10 assentos em cada fileira (1-10). Os assentos podem ser reservados ou liberados através de um menu interativo. 

## Compilação

```bash
  gcc -o reserva_assentos reserva_assentos.c

  .\reserva_assentos ou .\"reserva_assentos.exe"  
```
    
## Funcionalidades

1. Exibir Assentos: Mostra o layout atual dos assentos no teatro.

2. Reservar Assento: Permite ao usuário reservar um assento escolhendo a fileira (A-E) e o número do assento (1-10).

3. Liberar Assento: Permite ao usuário liberar um assento previamente reservado escolhendo a fileira (A-E) e o número do assento (1-10).

4. Sair: Encerra o programa.

## Utilização

Ao iniciar o programa, todos os assentos estarão marcados como disponíveis (O).

O usuário pode escolher as opções do menu digitando o número correspondente.

Ao reservar um assento, ele será marcado como ocupado (X).

Ao liberar um assento, ele será marcado como disponível (O).

O programa continua em execução até que o usuário escolha a opção "Sair".

## Notas

As entradas do usuário são validadas para garantir que estejam dentro dos limites aceitáveis.
O programa utiliza uma matriz para representar os assentos, onde 'O' representa um assento disponível e 'X' representa um assento ocupado.

## Autores

- [@GustavoCorrea15](https://github.com/GustavoCorrea15)
- [@Pratamartin](https://github.com/Pratamartin)
