#include<iostream>
#include <string>
using namespace std;

typedef struct TrieNode
{
	struct TrieNode* child_arr[26];
	bool end;

} TrieNode;

TrieNode* CreateTrieNode()
{
	TrieNode *node = (TrieNode*)malloc(sizeof(TrieNode));
	for(int i=0;i<26;i++)
		node->child_arr[i] = null;
	node->end = false;
	return node;
}

TrieNode *head=null;

void InsertinTrie(string text)
{
	TrieNode *tmp=head;
	if(head==null)
	{
		TrieNode *topnode = CreateTrieNode();
		head = topnode;
		temp = head;
	}
	for(int i=0;i<text.length();i++)
	{
		int index = text[i]-97;
		if(temp==null)
		{
			TrieNode *node = CreateTrieNode();
			temp->child_arr[index]=node;
		}
		else if(temp->child_arr[index]==null)
		{
			TrieNode *node = CreateTrieNode();
			temp->child_arrp[index] = node;
		}
		temp = temp->child_arr[index];
	}
}

void vector<string> GetallChildString(string text)
{
	
}

int main()
{
	string line;
	ifstream cmdfile ("command_file.txt");
	if (cmdfile.is_open())
  	{
    	while ( getline (cmdfile,line) )
    	{
      		
    	}
    	cmdfile.close();
  }
}