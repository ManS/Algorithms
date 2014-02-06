#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>

using namespace std;

//1.1 Implement an algorithm to determine if a string has all unique characters  What if you 
//can not use additional data structures?

bool IsStringUniqueChars(string str)
{
	bool charsArr [255] = {false};
	for(int i = 0 ; i < str.size(); i++)
	{
		if(str[i] >= 'a' && str[i] <= 'z')
		{
			if(charsArr[str[i]-'a'])
				return false;
			charsArr[str[i]-'a'] = true;
			continue;
		}
		else if(str[i] >= 'A' && str[i] <= 'Z')
		{
				if(charsArr[str[i]-'A'])
					return false;
			charsArr[str[i]-'A'] = true;
		}
		else
			return false;
	}
	return true;
}

//Without using extra space buffer.
bool IsStringUniqueCharsWithoutExtraSpace(string str)
{
	int checker =0;
	for(int i = 0 ; i < str.size(); i++)
	{
		int val = str[i];
		if((checker & (1<<val)))
			return false;
		checker |= (1<<val);
	}
	return true;
}

/********************************************************/
//1.2 Write code to reverse a C-Style String  (C-String means that “abcd” is represented as 
//five characters, including the null character )

void ReverseString(char* str)
{
	char* end = str;
	char temp;
	if(str)
	{
		while(*end)
			++end;
		--end;
		while(str<end)
		{
			temp = *str;
			*str++ = *end;
			*end-- = temp; 
		}
	}
}
/*******************************************************/

//1.3 Design an algorithm and write code to remove the duplicate characters in a string 
//without using any additional buffer  NOTE: One or two additional variables are fine   
//An extra copy of the array is not 

string RemoveDublicates(string str)
{
	if(str.size() <2)
		return str;

	int len = str.size();
	int tail =1;

	for(int i = 1; i < len; i++)
	{
		int j;
		for(j = 0; j < tail;j++)
		{
			if(str[j]==str[i])//duplicate
				break;
		}
		if(j==tail)//unique char
		{
			str[tail++]=str[i];
		}
	}
	for(int i = tail; i< len; i++)
		str[i]=0;
	return str;
}

string RemoveDublicatesEff(string str)
{
	if(str=="")
		return str;
	if(str.size() < 2)
		return str;

	int len = str.size();
	int tail = 1;
	bool check[265] = {false};
	check[str[0]-'a'] = true;
	for(int i = 1; i< len; i++)
	{
		if(!check[str[i]-'a'])
		{
			str[tail++] = str[i];
			check[str[i]-'a'] = true;
		}
	}
	for(int i = tail; i< len; i++)
	str[i]=0;
	return str;

}
/********************************************************/
//1.4 Write a method to decide if two strings are anagrams or not 
bool checkAnagram(char* strA, char* strB)
{
	int lenA = strlen(strA);
	int lenB = strlen(strB);

	if(lenA != lenB)
		return false;

	//lower_string(strA);
	//lower_string(strB);
	int chars[265] = {0};

	for(int i = 0 ; i < lenA; i++)
	{
		chars[strA[i]-'a']++;
		chars[strB[i]-'a']--;
	}
	
	for(int i = 0 ; i < 265; i++)
		if(chars[i])
			return false;

	return true;
}

/*********************************************************/

//1.5 Write a method to replace all spaces in a string with ‘%20’  
char* replaceSpaces(char* str)
{
	int numOfSpaces = 0;
	int len = strlen(str);

	for(int i =0; i < len; i++)
	{
		if(str[i] == ' ')
			numOfSpaces++;
	}
	int newSize = numOfSpaces*2 + len +1;

	char* newStr = new char[newSize];

	for(int i =0,j=0 ;i < len ; i++)
	{
		if(str[i] == ' ')
		{
			newStr[j++] = '%';
			newStr[j++] = '2';
			newStr[j++] = '0';
		}	
		else
			newStr[j++] = str[i];
	}
	newStr[newSize-1]= 0;
	return newStr;
}
/*********************************************************/


//1.7 Write an algorithm such that if an element in an MxN matrix is 0, its entire row and 
// column is set to 0 
void checkMatrix(int matrix[][10], int n, int m)
{
	int** newMatrix = new int*[n];
	for(int i = 0 ; i < n; i++)
		newMatrix[i] = new int[m];
	
	for(int i =0 ; i < n; i++)
	{
		for(int j=0; j < m; j++)
		{
			newMatrix[i][j]=matrix[i][j];
		}
	}
	for(int i =0 ; i < n; i++)
	{
		for(int j=0; j < m; j++)
		{
			if(matrix[i][j]==0)
			{
				for(int k =0; k< n; k++)
					newMatrix[k][j] = 0;
				for(int k=0; k<m; k++)
					newMatrix[i][k] = 0;
			}
		}
	}
	for(int i =0 ; i < n; i++)
	{
		for(int j=0; j < m; j++)
		{
			matrix[i][j]=newMatrix[i][j];
		}
	}
	for(int i =0 ; i < m; i++)
		delete[] newMatrix[i];
	delete[] newMatrix; 
}
/*********************************************************/

// 1.8  write code to check if s2 is a rotation of s1 using 
// only one call to isSubstring 

bool checkRotate(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	if(len1!=len2)
		return false;	
	for(int i = 0 ; i < len1; i++)
	{
		for(int j = 0; j < len2; j++)
		{
			if(str1[i]==str2[j])
			{
				int count = 0, k= i, l=j;
				while(str1[k]==str2[l]&&count<len1)
				{
					k= k%len1;
					l = l%len2;
					count++;
				}
				if(count == len1)
					return true;
			}	
		}
	}
	return false;
}

/*********************************************************/


void lower_string(char* str)
{
	while(*str)
	{
		if(*str>='A' && *str<='Z')
			*str = 'c';
		str++;
	}
}

vector<int> FindEquilibriumIndices(vector<int> arr)
{
	
	vector<int> res;
	if(arr.size()<2)
		return res;
	int sumf = 0;
	int sume = 0;

	for(int i = 1 ; i < arr.size(); i++)
	{
		sume += arr[i];
	}
	for(int i = 0; i < arr.size()-1; i++)
	{
		if(sume == sumf)
			res.push_back(i);
		sume -= arr[i+1];
		sumf += arr[i];
	}

	return res;
}

string FindLongestPalindromeSubstring(string str)
{
	string revstr ="";
	int len = str.size();
	for(int i = len-1; i>= 0; i--)
		revstr += str[i];
	int begin = 0, end =0;
	int palinLen = 1;
	bool db[100][100] = {false};
	for(int i =0 ; i < len ;i++)
		db[i][i] = true;

	for(int i = 0 ; i < len-1; i++)
	{
		if(str[i]==str[i+1])
		{
			db[i][i+1]=true;
			begin = i;
			palinLen =2;
		}
	}

	for(int l=3; l <= len; l++)
	{
		for(int i = 0; i < len-l+1; i++)
		{
			int j = i+len-1;
			if(str[i] == str[j] && db[i+1][j-1])
			{
				db[i][j]=true;
				begin = i;
				palinLen = l;
			}
		}
	}
	return str.substr(begin,palinLen);
}

/*
How do you reverse the order of words in a sentence, but keep words themselves unchanged? 
Words in a sentence are separated by blanks. For instance, the reversed output should be “student. a am I” when 
the input is “I am a student.”.
*/

void Reverse(char*& pBegin, char*& pEnd)
{
	if(pBegin == NULL || pEnd == NULL)
		return;
	while(pBegin<pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;
		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char*& pData)
{
	if(pData == NULL)
		return NULL;
	char* pEnd = pData;
	char* pBegin = pData;
	while(*pEnd != '\0')
		pEnd++;
	pEnd--;

	//reverse the whole sentence;
	Reverse(pBegin, pEnd);
	//reverse each word;
	pBegin = pEnd = pData;
	while(*pBegin != '\0')
	{
		if(*pBegin ==' ')
		{
			pBegin++;
			pEnd++;
		}
		else if(*pEnd = ' ' || *pEnd =='\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}
	return pData;
}

/*Count number of words*/

int countNumOfWords(char* str)
{
	int count =0;
	bool inword = false;
	while(*str)
	{
		if(!inword && *str!=' ')
		{
			inword = true;
			count++;
		}
		else if(inword && *str==' ')
			inword = false;
		++str;
	}
	return count;
}

/*
Sort the input character array based on the dictionary given. 
*/

string SortByDic(string str, vector<char> dictionary)
{
	string output ="";
	map<char,string> map;
	for(int i =0; i < dictionary.size(); i++)
		map.insert(make_pair(dictionary[i],""));

	for(int i=0; i < str.size(); i++)
		map[str[i]] = (str[i],map[str[i]]+str[i]);

	for(int i=0; i < dictionary.size(); i++)
		output +=map[dictionary[i]];

	return output;
}

string SortByDic(const string& str, const string& dic)
{
	string result = str;
	int map[256] = {0};
	for(int i =0 ; i < str.size(); i++)
		map[str[i]]++;
	int index =0;
	for(int i =0; i < dic.size(); i++)
	{
		char c = dic[i];
		while(map[c]>0)
		{
			result[index++] = c;
			map[c]--;
		}
	}
	return result;
}

/*
Print all valid words 

a word is valid if the letters follow their natural order in it. 
abcd is valid, acde is valid aaaa is valid, acb is not valid. 
condition for valid: char1<=char2<=char3<=… given a length n find all valid words of length n.
*/

const char EndChar = 'z';
int countwords = 0;

void PrintAllValidWords(string prefix, char start, int charCount)
{
	if(charCount == 0 || start>EndChar)
		return;

	for(char c = start; c <= EndChar; c++)
	{
		string newPrefix = prefix + c;

		if(charCount == 1)
		{
			cout<<newPrefix<<endl;
			countwords++;
		}
		else
			PrintAllValidWords(newPrefix, c, charCount -1);
	}
}

/*Find Max Num in array Divide and conqure*/
bool error = false;
int findMin(int arr[], int start, int end)
{
	if(start>end)
	{
		error = true;
		return -1;
	}
	if(start == end)
		return arr[start];
	return min(findMin(arr,start,(end+start)/2),findMin(arr,(end+start)/2+1,end));
}