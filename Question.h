
#ifndef QUESTION_H
#define QUESTION_H

#include"Answer.h"
#include"List.h"
#include<cstdlib>
#include<ctime>

class Question {
    private:
        string text;
        Answer* lAnswer;
        int answers;
        int nOfCorrect;
        int* correct;

    public:
        ~Question();
        bool printQuestion() const;

        bool operator==(const Question&) const;
        bool operator!=(const Question&) const;

        friend std::istream& operator>>(std::istream& is, Question& q) {
            srand(time(0));
            is >> q.nOfCorrect;
            q.correct = new int[q.nOfCorrect];
            for(unsigned int i = 0; i < q.nOfCorrect; i++) {
                is >> q.correct[i];
            }
            is >> q.answers;
            std::getline(is, q.text);
            std::getline(is, q.text);
            q.lAnswer = new Answer[q.answers];
            for(unsigned int i = 0, j = 0; i < q.answers; i++) {
                is >> q.lAnswer[i];
                if(j < q.nOfCorrect && i == q.correct[j]) {
                    q.lAnswer[i].correct = true;
                    j++;
                }
                else q.lAnswer[i].correct = false;
            }
            for(int i = q.answers - 1; i > 0; i--) {
                int j = rand() % (i+1);
                std::swap(q.lAnswer[i], q.lAnswer[j]);
            }
            return is;
        }
};

#endif
