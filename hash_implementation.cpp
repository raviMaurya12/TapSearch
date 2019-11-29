#include<bits/stdc++.h>
#include<fstream>
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define endl '\n'
using namespace std;

vector<vector<string>> paragraphs;

vector<vector<string>> index(){
	vector<vector<string>> para;
	string tmp;
	while(getline(cin,tmp)){
		if(tmp.size()>0){									//Paragraph shouldn't be empty
			stringstream tokenizer(tmp);
			string token;
			vector<string> currentPara;
			while(getline(tokenizer,token,' ')){			//tokenizing
				if(token[token.size()-1]=='.' || 			//Removing . and , from the tokens
					token[token.size()-1]==','  ){
					token.erase(token.begin()+(token.size()-1));
				}
				for(int i=0;i<token.size();i++){			//Converting to lowercase
					if(token[i]>='A' && token[i]<='Z'){
						token[i]=(int)(token[i]-'A')+'a';  
					}
				}
				currentPara.pb(token);
			}
			para.pb(currentPara);
		}
	}
	return para;
}

void clear(){
	paragraphs.clear();
}

int main(){
	ofstream myfile;

	clear();
	paragraphs=index();
	vector<string> searchInput=paragraphs[paragraphs.size()-1];

	map<string,unordered_map<int,int>> mp;
	for(int i=0;i<paragraphs.size()-1;i++){
    	for(int j=0;j<paragraphs[i].size();j++){
    		mp[paragraphs[i][j]][i]++;
    	}
    }

    myfile.open ("output.txt");
    for(int i=0;i<searchInput.size();i++){
    	myfile<<"<b>Search result for "<<searchInput[i]<<" : </b>"<<endl;
    	for(auto x:mp[searchInput[i]]){
    		myfile<<x.second<<" times in paragraph "<<x.first+1<<endl;
    	}
    	myfile<<endl;
    }
    myfile.close();
	return 0;
}