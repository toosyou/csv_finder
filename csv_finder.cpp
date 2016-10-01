#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 3){
        cout << "usage: ./tf csv_file key_word" <<endl;
        return -1;
    }

    fstream in_csv(argv[1], fstream::in);
    string key_word(argv[2]);
    int index_key = 0;
    string buffer;
    //first line
    int index_pre = 0;
    int index_next = 0;
    in_csv >> buffer;
    for(unsigned int i=0;i<buffer.size();++i){
        if(buffer[i] == ','){
            index_next = i;
            
            string tmp_str = buffer.substr(index_pre+1, index_next - index_pre-1);
            cout << tmp_str <<endl;
            if(tmp_str == key_word)
                break;

            index_pre = i;
            index_key++;
        }
    }

    //for all the lines
    cout << index_key <<endl;
    index_pre = 0;
    index_next = 0;
    while(in_csv >> buffer){
        int index_now = 0;
        string out_string;
        for(unsigned int i = 0;i<buffer.size();++i){
            if(buffer[i] == ','){
                index_next = i;
                if(index_now == index_key){
                    out_string = buffer.substr(index_pre+1, index_next - index_pre-1);
                    if(out_string.size() != 0){
                        cout << out_string <<"\t";
                    }
                    break;
                }
                index_now++;
                index_pre = i;
            }
        }
    }
    

    in_csv.close();
    return 0;
}
