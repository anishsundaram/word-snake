#include <vector>
#include <iostream>
#include <string>

using namespace std;

void print_matrix(vector<vector<char> >& letter_matrix){
    for(vector<char>& vec : letter_matrix){
        for(char c : vec){
            cout << c;
        }
        cout << '\n';
    }
}

void word_snake(vector<string> word_list, vector<vector<char> >& letter_matrix){
    int vert_dist=0;
    int horiz_dist =0;
    int counter = rand()%2;
    for(uint i = 0; i < word_list.size(); ++i){
        if(i%2==0){
            if(counter==1 && (horiz_dist-int(word_list[i].size()))>0){
                for(int start =int(word_list[i].size()-1); start >=0; --start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    --horiz_dist;
                 }
                vert_dist++;
                counter = rand()%2;
                ++horiz_dist;
            }
            else{
                for(uint start = 0; start< word_list[i].size(); ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    horiz_dist++;
                }
                horiz_dist--;
                vert_dist++;
                counter = rand()%2;
            }
        }        
        else{
           for(uint start = 1; start < word_list[i].size()-1; ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    ++vert_dist;
           }
        }
    }
    print_matrix(letter_matrix);
}

uint parse_date(vector<string>& word_list){
    string temp = "";
    uint size = 0;
    while(cin >> temp){
        size+=temp.size();
        word_list.push_back(temp);
    }
    return size;
}



int main(int argc, char *argv[]){
    freopen("input1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> word_list;
    uint size = parse_date(word_list);
    vector<vector<char> > letter_matrix(size, vector<char>(size,' '));
    word_snake(word_list, letter_matrix);

    return 0;
}
