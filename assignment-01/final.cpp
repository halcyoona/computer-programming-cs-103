#include<iostream>
#include<string>
using namespace std;


///////////////////////////////////////////////////



string plain_text(){
    
    int size_of_text;
    string text;
    cout<<"Enter the message : ";
    getline(cin,text);
    size_of_text = text.size();
    string final_text;
    char s_alphabet[27]="abcdefghijklmnopqrstuvwxyz";
    char c_alphabet[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char char_of_text;
    // loops to remove space and turn into uppercase.
    for (int i=0 ; i<size_of_text ; i++) {

        char_of_text = text[i];
        if (char_of_text == 'j' || char_of_text == 'J'){
            char_of_text = 'I';
        }
        for (int j=0 ; j<27 ; j++){
            if (c_alphabet[j] == char_of_text){
                final_text += char_of_text;
           }
            if (s_alphabet[j] == char_of_text){
                final_text += c_alphabet[j];
                
            }
        }
    }
    
    return final_text;
}



///////////////////////////////////////////////////////////////



string key(){
    int size_of_text;
    string text;
    cout<<"Enter the key : ";
    getline(cin,text);
    size_of_text = text.size();
    string value;
    char s_alphabet[27]="abcdefghijklmnopqrstuvwxyz";
    char c_alphabet[27]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char char_of_text;
    // loops to remove spaces and turn into uppercase. 
    for (int i=0 ; i<size_of_text ; i++) {
        char_of_text = text[i];
        if (char_of_text == 'j' || char_of_text == 'J'){
            char_of_text = 'I';
        }
        for (int j=0 ; j<27 ; j++){
            if (c_alphabet[j] == char_of_text){
                value += char_of_text;
            }
            if (s_alphabet[j] == char_of_text){
                value += c_alphabet[j];
            }
        }
    }
    string final_text;
    int size_of_value = value.size();
    //loop to remove repeatation.
    for(int i=0 ; i<size_of_value ; i++){
        
        for(int j=0 ; j<27 ;j++){

            if (c_alphabet[j]==value[i]){
                c_alphabet[j] = 'a';
                final_text +=value[i];
            }
        }
    }
    return final_text;
}



//////////////////////////////////////////////////////////////////



string fun(string key){
    char c_alphabet[26]="ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int size_of_key = key.size();
    string value = key;
    // This loop is to generate characters that have to be enter in the matrix table.
    for (int i = 0; i < 26;i++){
        int h = 0;
        for(int j=0 ; j<size_of_key ; j++){
            if (c_alphabet[i] == key[j]){
                h += 1 ;
                break;
            }
           
        }
        if (h==0){
            value +=c_alphabet[i];       
        }
    }
    return value;
}



///////////////////////////////////////////////////////////////////



string table(string value,string text1){
    int size_of_text1 = text1.size();
    string text;
    // This loop is to eliminate those pairs which have same character and introduce a character 'M' between them. 
    for (int i= 0; i < size_of_text1 ; i +=2 ){
         if (text1[i] == text1[i+1]){
              text += text1[i];
              text += 'M';
              i -= 1;
         }
         else{
             text += text1[i];
	         if(i+1<size_of_text1){              	
                 text += text1[i+1];
             }
         }
    }

    int size_of_text = (text.size());  
    if (size_of_text%2 == 0){
        int counter = 0;
        char table[5][5];

        // This loop is to assigning the value into the table.
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                table[i][j]=value[counter];
                counter += 1;
            }
        }
        // This loop is to print the encryption table.
        cout<<endl<<"--Encryption table--"<<endl<<endl;;
        for(int i =0; i<5; i++){
            cout<<"  ";
            for(int j=0; j<5; j++){
                cout<<" "<<table[i][j]<<" "; 
            }
            cout<<endl;
        }
        cout<<endl;
        string final_value;
        // this loop is to match the message characters in the encryption table.
    	for(int r= 0 ; r<size_of_text ;r+=2){
            int row1 , col1 , row2 ,col2;
            for(int i =0; i<5; i++){
                for(int j=0; j<5; j++){
                    table[i][j];
                    if(text[r]==table[i][j]){
                        row1 = i;
                        col1 = j;
                    }
                    if(text[r+1]==table[i][j]){
                        row2 = i;
                        col2 = j;
                    }   
                }
            }
            if(row2==row1){
                if (col1 == 4){
                    final_value += table[row1][0];
                    final_value += table[row2][col2+1];
                }
                else if(col2 == 4){
                    final_value += table[row1][col1+1];
                    final_value += table[row2][0];
                }
                else{    
                    final_value += table[row1][col1+1];
                    final_value += table[row1][col2+1];
                }
                
            }
            
            else{
                final_value += table[row2][col1];
                final_value += table[row1][col2];
                
            }  
        }    
    return final_value;
    }
    // introducing a character 'A' at the end of the plain text if there is odd number of character in the plain text and that 
    else{
        text += 'A';
        return table(value , text);
    }

}
   

int main(){
    string k,t,f,v;
    t = plain_text();
    k = key();
    f = fun(k);
    v = table(f,t);
    cout<<"Encrypted message is : "<<v<<endl;
    return 0;
}    

    
