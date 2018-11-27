#include <iostream>

#include "../SparseMatrix/SparseMatrix/Node.hpp"
#include "../SparseMatrix/SparseMatrix/AvlTree.hpp"
#include "../SparseMatrix/SparseMatrix/Line.hpp"
#include "../SparseMatrix/SparseMatrix/SparseMatrix.hpp"
#include "Graph.hpp"

#include <string>

using namespace std;

int main()
{
    Graph* graph = new Graph();

    for (;;)
    {
        system("cls");
        cout << "Grafo" << endl;
        cout << "Comandos disponiveis: " << endl << endl;
        cout << "1 - Inserir vertice" << endl;
        cout << "2 - Deletar vertice" << endl;
        cout << "3 - Inserir aresta" << endl;
        cout << "4 - Deletar aresta" << endl;
        cout << "5 - Printar" << endl;
        cout << "6 - Sair" << endl << endl;
        cout << "Digite uma opcao: ";

        int option;
        cin >> option;

        string v1, v2;
        int weight;
        
        system("cls");
        switch (option)
        {
            case 1:
                cout << "Digite o nome do vertice a ser adicionado: ";
                cin >> v1;

                graph->addVertex(v1);

                break;
            case 2:
                cout << "Digite o nome do vertice a ser removido: ";
                cin >> v1;

                graph->deleteVertex(v1);

                break;
            case 3:
                cout << "Digite o nome do primeiro vertice do caminho: ";
                cin >> v1;

                cout << "Digite o nome do segundo vertice do caminho: ";
                cin >> v2;

                cout << "Digite o peso do caminho: ";
                cin >> weight;

                graph->addEdge(v1, v2, weight);

                break;
            case 4:
                cout << "Digite o nome do primeiro vertice do caminho: ";
                cin >> v1;

                cout << "Digite o nome do segundo vertice do caminho: ";
                cin >> v2;

                graph->deleteEdge(v1, v2);

                break;
            case 5:
                cout << *graph;
                break;
            case 6:
                exit(0);
        }
        cout << endl << endl;
        cout << "Pressione qualquer tecla para continuar...";
        cin.sync();
        cin.ignore();
    }
    return 0;
}
