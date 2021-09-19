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
queue <int> case_num;	//case数量
int case_num_turn=0;
int switch_num = 0;		//switch数量


//找关键词
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
			if (k_key_word[i] == "switch") {
				case_num.push(case_num_turn);
				case_num_turn = 0;
				switch_num++;
			}
			else if (k_key_word[i] == "case") {
				case_num_turn++;
			}
			break;
		}
	}
	return keyword_num;
}

int main() {
	string text;			//输入文本
	string file_address;	//文本地址
	int search_level;		//查询等级
	int keyword_num = 0;
	cout << "输入文件地址" << endl;
	cin >> file_address;
	cout << "输入查询等级" << endl;
	cin >> search_level;
	ifstream read(file_address);
	while (read >> text) {
		keyword_num = SearchKeyword(text, keyword_num);
	}
	case_num.push(case_num_turn);
	case_num_turn = 0;
	cout << "total num : " << keyword_num << endl;
	if (search_level > 1) {
		cout << "switch num: " << switch_num << endl;
		cout << "case num:";
		int i;
		while (!case_num.empty()) {
			i = case_num.front();
			case_num.pop();
			if (i == 0) {
				continue;
			}
			cout << " " << i;
		}
		cout << endl;
	}
}