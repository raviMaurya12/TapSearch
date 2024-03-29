#include<bits/stdc++.h>
#include<fstream>
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define endl '\n'
using namespace std;

class Document{
	public:
		vector<vector<string>> paragraphs;							//2D vector to represent the document
		map<string,unordered_map<int,int>> mp;						//Storing in map to get search result in O(1) time

		void clear(){
			paragraphs.clear();
		}

		//Tokenization followed by indexing
		void index(){
			clear();
			string tmp;
			while(getline(cin,tmp)){
				if(tmp.size()>1){									//Paragraph shouldn't be empty
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
					paragraphs.pb(currentPara);
				}
			}
		}

		//Storing words in Map
		void store(){
			mp.clear();
			for(int i=0;i<paragraphs.size()-1;i++){
		    	for(int j=0;j<paragraphs[i].size();j++){
		    		mp[paragraphs[i][j]][i]++;
		    	}
		    }
		}

		//Searching for presence of words in all paragraphs 
		vector<pair<int,int>> search(string s){
			vector<pair<int,int>> ans;
			for(auto x:mp[s]){
				ans.pb(x);
	    	}
	    	return ans;
		}
};

int main(){
	ofstream myfile;

	//Clearing, Indexing and Storing words
	Document doc;
	doc.index();
	doc.store();

	//Getting the Search inputs
	vector<string> searchInput=doc.paragraphs[doc.paragraphs.size()-1];

	//writing results in output.txt
    myfile.open ("output.txt");
    for(int i=0;i<searchInput.size();i++){
    	myfile<<"<b>Search result for "<<searchInput[i]<<" : </b>"<<endl;
    	vector<pair<int,int>> result=doc.search(searchInput[i]);
    	for(auto el:result){
    		myfile<<el.second<<" items in paragraph "<<el.first+1<<endl;
    	} 	
    	myfile<<endl;
    }
    myfile.close();

	return 0;
}