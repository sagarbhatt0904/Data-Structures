#include <iostream>
#include <stack>
#include <string>
#include <fstream>

using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    char file[100];
    for (int i = 1; i <= 54; ++i)
    {
        sprintf(file,"%02d",i);

        ifstream fin(file); 
        std::string text;
        getline(fin, text);
    std::stack <Bracket> opening_brackets_stack;
   
    for (int position = 0; position < text.length()-1; position++) {
        char next = text[position];
    
        if (next == '(' || next == '[' || next == '{') {
            Bracket br = Bracket(next,position);
            
            opening_brackets_stack.push(br);
        }

        if (next == ')' || next == ']' || next == '}') {
            if(!opening_brackets_stack.empty()){
                if(opening_brackets_stack.top().Matchc(next))
                    opening_brackets_stack.pop(); 
                else break;
            }else{
                cout<<"The string is not balanced";
                break;
            }
        }
    }
    if(opening_brackets_stack.empty())
        cout << "yes for case "<<i<<"\n";
    else 
        cout << "no for case "<<i<<"\n";
    text.clear();
    fin.close();
    }
    
    return 0;
}
