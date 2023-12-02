
#include"Question.h"

Question::~Question() {
    delete[] lAnswer;
    delete[] correct;
}

bool Question::printQuestion() const {
    if (answers <= 0) return false;
    std::cout << "--------------------------------------------------------------------------------------" << std::endl;
    std::cout << " - " << text << std::endl;
    for(unsigned int i = 0; i < answers; i++) {
        std::cout << i << ") " << lAnswer[i].text << std::endl;
    }
    bool* guessed = new bool[answers]{0};
    for(unsigned int i = 0; i < nOfCorrect; i++) {
        int tmp;
        std::cin >> tmp;
        if(tmp >= answers || tmp < 0 || !lAnswer[tmp].correct || guessed[tmp]) {
            std::cout << "------------------" << std::endl;
            std::cout << "Risposta sbagliata" << std::endl;
            std::cout << "------------------" << std::endl;
            std::cout << "Risposta corretta: " << std::endl;
            for(unsigned int i = 0; i < answers; i++) {
                if(lAnswer[i].correct) {
                    std::cout << i << ") " << lAnswer[i].text << std::endl;
                }
            }
            std::cout << std::endl;
            string tmp;
            std::getline(std::cin, tmp);
            return false;
        }
        else {
            guessed[tmp] = true;
        }
    }
    std::cout << "-----------------" << std::endl;
    std::cout << "Risposta corretta" << std::endl;
    std::cout << "-----------------" << std::endl << std::endl;
    return true;
}

bool Question::operator==(const Question& b) const {return this->text == b.text;}
bool Question::operator!=(const Question& b) const {return this->text != b.text;}
