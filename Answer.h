
#ifndef ANSWER_H
#define ANSWER_H

#include<iostream>
#include<cstring>
using std::string;

class Answer {
    public:
        string text;
        bool correct;

        Answer() {
            correct = false;
        }

        bool operator==(const Answer& b) const {return this->text == b.text;}
        bool operator!=(const Answer& b) const {return this->text != b.text;}

        friend std::istream& operator>>(std::istream& is, Answer& a) {
            std::getline(is, a.text);
            return is;
        }
};

#endif
