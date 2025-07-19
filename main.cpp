#include <iostream>
#include <iomanip>
#include <sstream>
#include "prime_analyzer.h"


using namespace std;

// Números não primos divisiveis por x primos


int insert(string message){
  again:
  string input;
  cout << message;
  cin >> input;

  try
  {
    return stoi(input);
  }
  catch(const std::exception& e)
  {
    cout << "Tente novamente..." << endl;
    goto again;
  }
}

int main() {
  prime_analyzer* analyzer = nullptr;
  string input;

  while (true) {
    cout  << "\n_____________[MENU]_____________" << endl
          << "1.Criar primos" << endl
          << "2.Mostrar conjunto" << endl
          << "3.Mostrar pulos" << endl
          << "4.Pertence ao conjunto" << endl
          << "5.Mostra o total" << endl
          << "6.Sair" << endl
          << "> ";

    cin >> input;

    if (input == "1") {
      int a = insert("Insira o numero inicial: ");
      int b = insert("Insira o numero final: ");
      if (analyzer) delete analyzer;
      analyzer = new prime_analyzer(a,b);
      analyzer->show();
    }
    else if ((input == "2" || input == "3" || input == "4" || input == "5") && analyzer == nullptr) {
      cout << "Primeiro crie o conjunto de primos..." << endl;
    }
    else if (input == "2") {
      analyzer->show();
    }
    else if (input == "3") {
      int a = insert("Insira numero maximo para analizar (Inicial~X): ");
      int b = insert("Insira o numero de adição opcional: ");
      analyzer->show_jump(a, b);
      cout << "Deseja carregar o resultado de pulos? ";
      cin >> input;
      char c = input[0];
      if (c == 's' || c == 'S' || c == 'y' || c == 'Y') *analyzer = analyzer->collect_jump(a, b);
    }
    else if (input == "4") {
      int a = insert("Insira o numero: ");
      cout << (analyzer->is_inside(a) ? "Esta dentro" : "Nao esta dentro") << endl;
    }
    else if (input == "5") {
      analyzer->total();
    }
    else if (input == "6") {
      cout << "Fechando..." << endl;
      break;
    }
    else {
      cout << "Valor invalido! Tente novamente..." << endl;
    }
  }
  if (analyzer) delete analyzer;

  return 0;
}


/*

  prime_analyzer p = prime_analyzer(2, 13);
  p.show();
  p.show_jump(500, 1);
  p.collect_jump(100000, 1).show();
  p.collect_jump(100000, 1).total(500);
  */
