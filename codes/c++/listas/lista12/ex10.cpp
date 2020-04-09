/*Em uma pesquisa de campo, uma editora solicitou os seguintes dados para os entrevistados: sexo,
idade e quantidade de livros que leu no ano de 2015. Faça um programa que leia os dados digitados
pelo usuário, sendo que deverão ser solicitados dados até que a idade digitada seja zero.
Depois, calcule e imprima:
a.
b.
c.
d.
A quantidade total de livros lidos pelos entrevistados menores de 10 anos.
A quantidade de mulheres que leram 5 livros ou mais.
A média de idade dos homens que leram menos que 5 livros.
O percentual de pessoas que não leram livros.*/

#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ptb");
    char sexo;
    int idade,numPessoas,numHomens, numLivrosLidos = 0;
    bool repeat;


    float respostas[4] = {0,0,0,0};

    while(idade != 0)
    {
        cout << "Sua idade(obs. idades inferiores a 1 serão desconsideradas e as perguntas serão encerradas): ";
        cin >> idade;

        numPessoas++;
        if (idade  != 0)
        {
            while(toupper(sexo) != 'H' || toupper(sexo) != 'M')
            {
                cout << "Sexo, homem(H) ou mulher(M): ";
                cin >> sexo;

                if (toupper(sexo) != 'H' || toupper(sexo) != 'M')
                {
                    cout << "Vc e um E.T.? Isso n e sexo";
                }
                
            }

            cout << "Número de livros que leu em 2015: ";
            cin >> numLivrosLidos;

            if(idade < 10)
            {
                respostas[0]+=numLivrosLidos; 
            }
        
            if(toupper(sexo) == 'M' && numLivrosLidos >=5)
            {
                respostas[1]++;
            }

            if (toupper(sexo) == 'H' && numLivrosLidos < 5)
            {
                respostas[2]+=idade;
                numHomens++;
            }

            if(numLivrosLidos == 0)
            {
                respostas[3]++;
            }
        }
    }

    cout << "Resultados:"<<endl
         << "a) "<<respostas[0]<<endl
         << "b) "<<respostas[1]<<endl
         << "c) "<<respostas[2]/numHomens<<endl
         << "d) "<<respostas[3]/numPessoas<<"%"<<endl; 
    
    return 0;
}