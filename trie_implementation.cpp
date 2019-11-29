#include<bits/stdc++.h>
#include<fstream>
#define pb emplace_back
#define mp make_pair
#define all(v) v.begin(),v.end()
#define rep(i,start,lim) for(long long (i)=(start);i<(lim);i++)
#define endl '\n'
using namespace std;

struct Trie{
	Trie *children[26];
	int isEnd;
};

Trie* createNode(){
	Trie *node =new Trie;
	node->isEnd=0;
	for(int i=0;i<26;i++){
		node->children[i]=NULL;
	}
	return node;
}

class Document{
	public:
		vector<vector<string>> paragraphs;							//2D vector to represent the document
		vector<Trie*> roots;										//Storing each paragraph in different trie

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
							if(token[i]<'a' || token[i]>'z'){		//Erasing any other character than lower case letters
								token.erase(token.begin()+i);		//Otherwise trie implementation will give segmentation fault
							}
						}
						currentPara.pb(token);
					}
					paragraphs.pb(currentPara);
				}
			}
		}

		//Function to store each paragraph in a different trie
		void store(){
			roots.clear();
			for(int i=0;i<paragraphs.size()-1;i++){
				Trie *root=createNode();
				for(int j=0;j<paragraphs[i].size();j++){
					string t=paragraphs[i][j];
					int n=t.size();
					Trie *temp=root;
					for(int i=0;i<n;i++){
						int index=t[i]-'a';
						if(!temp->children[index])temp->children[index]=createNode();
						temp=temp->children[index];
					}
					temp->isEnd=temp->isEnd+1;
				}
				roots.pb(root);
			}
		}

		//Function to search a string a all tries
		vector<pair<int,int>> search(string s){
			vector<pair<int,int>> ans;
			for(int i=0;i<roots.size();i++){
				Trie* root=roots[i];
				int n=s.size();
				Trie *temp=root;
				for(int i=0;i<n;i++){
					int index=s[i]-'a';
					if(!temp->children[index]){
						break;
					}
					temp=temp->children[index];
				}
				if((temp!=NULL) && (temp->isEnd > 0)){
					ans.pb(mp(i,temp->isEnd));
				}
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