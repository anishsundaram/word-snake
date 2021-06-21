// Anish Sundaram / anishsun
// Word Snake Problem



#include <vector>
#include <iostream>
#include <string>

using namespace std;

//Function to print matrix to command line
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
	//Randomly chooses whether snake goes left or right
    int counter = rand()%2;
	//Loop over words in word list vector
    for(uint i = 0; i < word_list.size(); ++i){
		//Alternates between horizontal or vertical
        if(i%2==0){
			//Alternates randomly for left-right snaking, this loop is for left
            if(counter==1 && (horiz_dist-int(word_list[i].size()))>0){
				//Loops over all characters in word and adjusts index 
                for(int start = 0; start< word_list[i].size(); ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    --horiz_dist;
                 }
				//Adjust indices and re-randomize counter
                vert_dist++;
                counter = rand()%2;
                ++horiz_dist;
            }
            else{
				//For right-snaking loop
                for(int start = 0; start< word_list[i].size(); ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    horiz_dist++;
                }
				//adjust for indices and randomize counter var
                horiz_dist--;
                vert_dist++;
                counter = rand()%2;
            }
        }        
		//For downward snaking
        else{
           for(uint start = 1; start < word_list[i].size(); ++start){
                    letter_matrix[vert_dist][horiz_dist] = word_list[i][start];
                    ++vert_dist;
           }
            --vert_dist;
        }
    }
	//Call print function and terminate
    print_matrix(letter_matrix);
}
// Function to read input from command line and input into a vector
// Also designates size value for 2D field of chars
uint parse_date(vector<string>& word_list){
    string temp = "";
    uint size = 0;
    while(cin >> temp){
        size+=temp.size();
        word_list.push_back(temp);
    }
    return size;
}


//driver code
int main(int argc, char *argv[]){
    //Include for Xcode and replace * with (1-4) inclusive
    //freopen("input1.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    vector<string> word_list;
    uint size = parse_date(word_list);
	
	// Initializes 2D Vector of chars to be filled with word snake
    vector<vector<char> > letter_matrix(size, vector<char>(size,' '));
    word_snake(word_list, letter_matrix);

    return 0;
}
