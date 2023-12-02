
#include<fstream>
#include<cstdlib>
#include<ctime>
#include"List.h"
#include"Question.h"

#define File "Domande/pt. "
using std::ifstream;

int main() {
    srand(time(0));
    ifstream input;
    Question** questions = new Question*[300];
    std::cout << "----------" << std::endl;
    std::cout << "Buongiorno" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "Quale unita' vuoi provare? (inserisci 0 per provarle tutte): ";
    int choice;
    bool all;
    std::cin >> choice;
    if(choice < 1 || choice > 19) all = true;
    else all = false;
    int n = 0;
    if(!all) {
        input.open(File + std::to_string(choice) + ".txt");
        while(!input.eof()) {
            questions[n] = new Question();
            input >> *questions[n++];
        }
        input.close();
    }
    else {
        for(unsigned int i = 0; i < 19; i++) {
            input.open(File + std::to_string(i+1) + ".txt");
            while(!input.eof()) {
                questions[n] = new Question();
                input >> *questions[n++];
            }
            input.close();
        }
    }
    --n;
    int correct = 0;
    for(int i = n-1; i >= 0; i--) {
        int j = rand() % (i+1);
        std::swap(questions[i], questions[j]);
        correct += (questions[i]->printQuestion() ? 1 : 0);
        delete questions[i];
    }
    delete[] questions;
    std::cout << "_______________________________________________________" << std::endl;
    std::cout << "Hai totalizzato un punteggio di " << correct << "/" << n << std::endl;
    return 0;
}
