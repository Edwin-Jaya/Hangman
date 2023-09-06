#include <iostream>
#include <string>
using namespace std;


string randomclue(int randomIdx){
    string clue[5]={"meow","moo","roof","snitch","ultrasonic sound"};
    string wordclue=clue[randomIdx];
    return wordclue;
}

int randomIndex(){
    srand(time(NULL));
    int randomint=rand() % 5;
    return randomint;
}
string randomWords(int randomIdx){
    string word[5]={"cat","cow","dog","rat","bat"};
    return word[randomIdx];
}

void createQuestion(string word, string* question){
    for (int i=0;i<word.length();i++){
        question[i]="_";
    }
}

void displayQuestion(string* word_arr,string wordclue){
    for (int i=0;i<3;i++){
        cout<<word_arr[i]<<" ";
    }
    cout<<endl<<wordclue<<endl;
}

void changeQuestionChar(char word,string* question,int numberIndex){
        question[numberIndex]=word;
}

bool winValidation(string* question,bool condition){
    for (int i=0;i<3;i++){
        if(question[i]=="_"){
            condition=false;
            break;
        }else{
            condition=true;
        }
    }
    return condition;
}

bool checkAnswer(char letter,string word, string* question){
    bool wordExist=false;
    for (int i=0;i<3;i++){
        if (word[i] == letter){
            changeQuestionChar(letter,question,i);
            wordExist=true;
        }
    }
    if (wordExist==false){
        return false;
    }else{
        return true;
    }

}

void winthegame(string word){
        cout<<"Congratulation! You won! The mystery word is "<<word;
}
void losethegame(){
        cout<<"You lose!";
}

void drawing(int position)
{
     
     switch(position)
     {
     case 1: 
            cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |         " <<endl;
            cout << "_|______________"<<endl; 
     break;      
     case 2:
            cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |       \\  " <<endl;
            cout << "_|______________"<<endl;
     break;      
     case 3:       cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |       \\ 0 " <<endl;
            cout << "_|______________"<<endl;     
     break;
     case 4:       
            cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |       \\ 0 /" <<endl;
            cout << "_|______________"<<endl;
     break;      
     case 5:
            cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |       \\ 0 /" <<endl;
            cout << " |         |"<<endl;
            cout << "_|______________"<<endl;
     break;            
     case 6:  
            cout << " ___________"<<endl;
            cout << " |         |"<<endl;
            cout << " |       \\ 0 /" <<endl;
            cout << " |         |"<<endl;
            cout << " |        / \\ "<<endl;
            cout << "_|______________"<<endl;
     }   
}

int main(){
    int randomIndexArr;
    randomIndexArr=randomIndex();
    string word;
    string wordclue;
    word=randomWords(randomIndexArr);
    wordclue=randomclue(randomIndexArr);
    string* question= new string[word.length()];
    createQuestion(word,question);
    bool win=false;
    bool ans_val;
    int chance=1;
    char userInput;
    while(win!=true && chance<7){
        if (win!=true && chance<7){
            cout<<"Chance left : "<<7-chance<<endl;
            drawing(chance);
            displayQuestion(question,wordclue);
            cout<<"Input your answers : ";
            cin>>userInput;
            ans_val=checkAnswer(userInput,word,question);
            if (ans_val==false){
                chance=chance+1;
            }
            win=winValidation(question,win);
            if(win==true){
                winthegame(word);
                break;
            }
        }
        else{
            break;
        }
    if(win==false && chance>6){
            losethegame();
        }
    }
}
