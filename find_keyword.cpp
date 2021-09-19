#include<iostream>
#include<stdio.h>
#include<fstream>
#include<queue>
#include<string.h>

using namespace std;

const string k_key_word[32] = {
	"auto","break","case","char","const","continue","default","do","double","else","enum",
	"extern","float","for","goto","if","int","long","register","return","short","signed",
	"sizeof","stastic","struct","switch","typedef","union","unsigned","void","volatile","while"
};
queue <int> case_num;	//case����
int switch_num = 0;		//switch����


//�ҹؼ���
int SearchKeyword(string text, int keyword_num) {
	int k = text.size();
	if (k <= 1) {
		return keyword_num;
	}
	int flag;
	for (int i = 0 ; i <= 31 ; i++) {
		flag = text.find(k_key_word[i], 0);
		if (flag >= 0) {
			//cout << text << endl;
			keyword_num++;
			break;
		}
	}
	return keyword_num;
}

int main() {
	string text;			//�����ı�
	string file_address;	//�ı���ַ
	int search_level;		//��ѯ�ȼ�
	int keyword_num = 0;
	cout << "�����ļ���ַ" << endl;
	cin >> file_address;
	cout << "�����ѯ�ȼ�" << endl;
	cin >> search_level;
	ifstream read(file_address);
	while (read >> text) {
		keyword_num = SearchKeyword(text, keyword_num);
	}
	cout << "total num : " << keyword_num << endl;
}