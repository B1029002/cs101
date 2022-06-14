#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class myString{
    
};

class ReadClass{
    private:
        ifstream in;
        string temp,outp,filename="main.cpp";
        int counter;
    public:
        ReadClass(){
            in.open(filename);
            counter = 0;
        }
        void showClass(){
            while(getline(in, temp)){
                string pt="";
                int cki = temp.find("class ");
                if(cki!=-1){
                    for(char t:temp){
                        if(t!='{')
                            pt+=t;
                        else{
                            outp+=pt+"\n";
                            counter++;
                        }
                            
                    }
                }
            }
            cout<<counter<<" class in "<<filename<<endl<<outp;
            in.close();
        }
};

int main(){
    ReadClass rfile;
    rfile.showClass();
    return 0;
}
