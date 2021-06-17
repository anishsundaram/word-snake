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
    uint vert_dist=0;
    uint horiz_dist =0;
    uint counter = 0;
    for(uint i = 0; i < word_list.size(); ++i){
        if(i%2==0){
            if(counter%2==0){
                for(uint start = 0; start< word_list[i].size(); ++start){
                    letter_matrix[vert_dist][start] = word_list[i][start];
                    horiz_dist++;
                }
                horiz_dist--;
                vert_dist++;
            }
            else{
               for(uint start = word_list[i].size()-1; start >= 0; --start){
                    letter_matrix[vert_dist][start+horiz_dist-1] = word_list[i][start];
                    --horiz_dist;
                } 
            }
        }        
        else{
           for(uint start = 1; start < word_list[i].size()-1; ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    ++vert_dist;
                }
            horiz_dist++;
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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<string> word_list;
    uint size = parse_date(word_list);
    vector<vector<char> > letter_matrix(size, vector<char>(size,' '));
    word_snake(word_list, letter_matrix);

    return 0;
}
