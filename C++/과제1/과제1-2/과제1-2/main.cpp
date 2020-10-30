//
//  main.cpp
//  과제1-2
//
//  Created by 최제현 on 2020/09/27.
//

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <iomanip>

using namespace std;

struct Word{ //컴파일러 버전에 따라 typedef를 제외할 수도 있다.
    string str;
    int count;
};

vector<Word*> wordList;


void countWord(string& buffer);
int duplicateCheck(string& buffer);
void showWordList();
bool wordCompare(const Word* a, const Word* b);

int main(int argc, const char * argv[]) {
    
    string buffer;
    char delimit[] = ",!\t\n \'\"";
    
    ifstream FILE;
    FILE.open("/Users/s85737/Documents/2020 2학ㄱ/C++/과제1/과제1-2/과제1-2/lyrics.txt");
    
    //파일 에러 예외처리
    if(!FILE.is_open()){
        cout << "FILE input ERROR !! " << endl;
        exit(1);
    }
    
    //파일의 단어를 버퍼에 저장
    while(!FILE.eof()){
        getline(FILE, buffer); //getline()은 구분자를 2개 이상 넣을 수 없음.
        // string클레스는 strtok등 cstring의 함수를 사용할 수 없음
        // ,!탭띄어쓰기 등을 없애는 토큰화를 위해서 char형으로 변환
        vector<char> stov(buffer.begin(), buffer.end());
        stov.push_back('\0');
        char* vtoc = &stov[0];
        vtoc = strtok(vtoc, delimit);
        if(vtoc == NULL) break; //빈 줄을 get 하고 토큰화 하면 버그발생 예외처리
        buffer = vtoc; // 토큰화한 단어를 다시 buffer에 저장
        transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);
        //buffer 소문자로 변환
        countWord(buffer);
        while(vtoc != NULL){
            vtoc = strtok(NULL, delimit);
            if(vtoc == NULL) break;
            buffer = vtoc; // 토큰화한 단어를 다시 buffer에 저장
            transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower); //buffer 소문자로 변환
            countWord(buffer);
        }
        
}
    sort(wordList.begin(), wordList.end(), wordCompare);
    showWordList();
    
    return 0;
}

void countWord(string& buffer){ //call by reference 이므로 &를 붙여준다.
    int wordIndex = duplicateCheck(buffer);
    if(wordIndex != -1){
        wordList[wordIndex]->count++;
    }else{
        //구조체도 class처럼 생성자를 사용해야함 c언어에서는 Malloc으로 사용
        Word* newWord = new Word;
        newWord -> str = buffer;
        newWord -> count = 1;
        wordList.push_back(newWord); //list에 새로운 단어 삽입
    }
}

int duplicateCheck(string& buffer){
    for(int wordIndex = 0; wordIndex < wordList.size(); wordIndex++){
        // wordList안에 같은 단어가 있다면, index return
        if(buffer.compare(wordList[wordIndex]->str) == 0) return wordIndex;
    }
    return -1;
}

void showWordList(){
    
    cout.setf(ios::left);
    for(int i =0; i<wordList.size(); i++){
        cout.width(15);
        cout <<wordList[i] -> str << setw(5) <<wordList[i] -> count << endl;
    }
}

// 사용자 정의 정렬
bool wordCompare(const Word* a, const Word* b){
    return (a->str < b->str);
}

