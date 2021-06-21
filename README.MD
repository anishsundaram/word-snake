# Word Snake

Simple Word Snake generator written in C/C++ for fun/practice 

## Constraints

- Program must take in an input word sequence from command line and turn it into a word snake
- It has to start in the top left corner
- Each word has to turn 90 degrees left or right to the previous word
- The snake can't intersect itself

## Usage
Available are 4 different input files with increasing complexity of words and arrangement. In accordance with the challenge rules listed in the post the final two input files are the "Challenge Inputs"

To use:
- First compile using the included Makefile by entering ```make``` into the command line. *Make sure you are in the right directory!*
- Next pass in the chosen input file by entering ```./word_snake < input*.txt``` replacing ```*``` with (1-4) inclusive

## Sample Output

Sample output from 'input1.txt': ```SHENANIGANS SALTY YOUNGSTER ROUND DOUBLET TERABYTE ESSENCE```


```
SHENANIGANS                                         
          A                                         
          L                                         
          T                                         
  RETSGNUOY                                         
  O                                                 
  U                                                 
  N                                                 
  DOUBLET                                           
        E                                           
        R                                           
        A                                           
        B                                           
        Y                                           
        T                                           
        ESSENCE   
```

Sample output from 'input2.txt': ```DELOREAN NEUTER RAMSHACKLE EAR RUMP PALINDROME EXEMPLARY YARD```

```
DELOREAN                                              
       E                                              
       U                                              
       T                                              
       E                                              
       RAMSHACKLE                                     
                A                                     
             PMUR                                     
             A                                        
             L                                        
             I                                        
             N                                        
             D                                        
             R                                        
             O                                        
             M                                        
             EXEMPLARY                                
                     A                                
                     R                                
                     D                                
```
## Credits

Inspired by this [post](https://old.reddit.com/r/dailyprogrammer/comments/3bi5na/20150629_challenge_221_easy_word_snake/) by u/XenophonOfAthens on r/dailyprogrammer
