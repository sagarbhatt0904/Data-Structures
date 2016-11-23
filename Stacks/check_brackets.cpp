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
        // cout<<i<<" "<<text.length()<<endl;;
    std::stack <Bracket> opening_brackets_stack;
   // cout<<text<<"\n";
   
    for (int position = 0; position < text.length()-1; position++) {
        char next = text[position];
    
        if (next == '(' || next == '[' || next == '{') {
            Bracket br = Bracket(next,position);
            
            opening_brackets_stack.push(br);

            // Process opening pbracket, write your code here
        }

        if (next == ')' || next == ']' || next == '}') {
        // Process closing bracket, write your code herer 
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
    
    // Printing answer, write your code here
    
    return 0;
}
