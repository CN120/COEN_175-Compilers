#include <iostream>     // std::cin, std::cout
#include <fstream>  
#include <cctype>
#include <set> //is a template
#include <string>

using namespace std;

int main() {
    char c;
    
    set<string> keywords{"auto", "break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};
    set<string> operators{"=","|","||","&&","==","!=","<",">","<=",">=","+","-","*","/","%","&","!","++","--",".","->","(",")","[","]","{","}",";",":",","};
    
    while(c != EOF){
        c = cin.get();
        
        //int or long
        if(isdigit(c)){
            string buffer;
            buffer += c;
            
            while(isdigit(cin.peek())){
                c=cin.get();
                buffer += c;
            }
            if(cin.peek()=='l' || cin.peek()=='L'){
                c=cin.get();
                buffer += c;
                cout<< "long:" << buffer << endl;
            }
            else{
                cout<< "int:" << buffer <<endl;
            }
        }
        
        //string
        else if(c=='"'){
            string buffer;
            while(cin.peek() != '"'){
                c = cin.get();
                buffer += c;
            }
            cin.get();
            cout<< "string:\"" << buffer<< "\"" <<endl;
            
        }
        
        
        //keyword  or identifier
        else if(isalpha(c) || c=='_'){
            string buffer;
            buffer += c;
            while(isalnum(cin.peek()) || cin.peek()== '_'){
                c=cin.get();
                buffer += c;
            }
            if(keywords.find(buffer)!=keywords.end()){
                cout<< "keyword:" << buffer <<endl;
            }
            else{
                cout<< "identifier:" << buffer << endl;
            }
        }
        
        //inline comments
        else if(c=='/' && cin.peek()=='/'){
            do{
                c=cin.get();
            } while(c!='\n');
        }
        
        /* block comments */
        else if(c=='/' && cin.peek()=='*'){
            cin.get();
            do{
                c=cin.get();
            }while(c!='*' || cin.peek()!='/');
            cin.get();
        }
        
        
        //operators
        else if(operators.find(string(1,c)) != operators.end()){
            string buffer;
            buffer+=c;
            c=cin.peek();
            buffer+=c;
            if(operators.find(buffer) != operators.end()){
                cin.get();
            }
            else{
                buffer.pop_back();
            }
            
            cout<< "operator:" << buffer << endl;
        }
        
    }
    
    
}
