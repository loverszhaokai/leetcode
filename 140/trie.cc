#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

struct UnitInfo {

  UnitInfo() : uc(0), is_end_word(false) {
  }

  UnitInfo(unsigned char _uc, bool _is_end_word) :
    uc(_uc), is_end_word(_is_end_word) {
    //std::cout << "\t contructor(" << _uc << "," << _is_end_word << ")" << std::endl;
  }

  ~UnitInfo() {
    //std::cout << "\t decontructor()" << std::endl;
  }

  const unsigned char uc;
  bool is_end_word;
  std::vector<UnitInfo*> children;
};

void InsertWord(UnitInfo* root, const std::string& word) {
  //std::cout << "\t InsertWord(word=" << word << ")" << std::endl;
  UnitInfo* uip = root;
  size_t i = 0, j = 0;
  unsigned char curr_uc = 0;

  for (i = 0; i < word.size(); i++) {
    curr_uc = word[i];
    //std::cout << "\t curr_uc=" << curr_uc
    //  << "\t uip->uc=" << uip->uc
    //  << "\t children size=" << uip->children.size() << std::endl;

    for (j = 0; j < uip->children.size(); j++) {
      //std::cout << "\t child uc=" << uip->children[j]->uc << std::endl;
      if (curr_uc == uip->children[j]->uc) {
        break;
      }
    }

    if (j == uip->children.size()) {
      // failed to find curr_uc in uip->children
      //std::cout << "\t new UnitInfo(" << curr_uc << "," << (i + 1 == word.size()) << ")" << std::endl;
      UnitInfo* uinfo = new UnitInfo(curr_uc, i + 1 == word.size());
      uip->children.push_back(uinfo);
      uip = uinfo;
    } else {
      uip = uip->children[j];
      if (i + 1 == word.size()) {
        uip->is_end_word = true;
      }
    }
  }
}

UnitInfo* CreateTrieTree(const unordered_set<std::string>& words) {
  UnitInfo* root = new UnitInfo();

  for (auto& word : words) {
    InsertWord(root, word);
  }

  return root;
}

void PrintTrieTree(const UnitInfo* uip) {
  std::cout << "\nPrintTrieTree()" << std::endl;
  std::queue<const UnitInfo*> q1, q2;

  for (auto uinfo : uip->children) {
    q1.push(uinfo);
  }

  while (!q1.empty() || !q2.empty()) {
    while (!q1.empty()) {
      const auto uinfo = q1.front();
      q1.pop();
      std::cout << "\t " << uinfo->uc
        << "[" << (uinfo->is_end_word ? "Y" : "N") << "]";
      for (auto c : uinfo->children) {
        q2.push(c);
      }
    }
    std::cout << std::endl;

    while (!q2.empty()) {
      const auto uinfo = q2.front();
      q2.pop();
      std::cout << "\t " << uinfo->uc
        << "[" << (uinfo->is_end_word ? "Y" : "N") << "]";
      for (auto c : uinfo->children) {
        q1.push(c);
      }
    }
    std::cout << std::endl;
  }
}

void DestroyTrieTree(UnitInfo* uip) {
  for (auto c : uip->children) {
    DestroyTrieTree(c);
  }

  delete uip;
  uip = nullptr;
}

std::vector<int> HasWord(const UnitInfo* uip,
                         const char* str) {
  std::vector<int> indexs;

  if (str == nullptr || str[0] == '\0') {
    return indexs;
  }

  int i = 0, j = 0;
  while (str[i] != '\0') {
    //std::cout << "\t str=" << str << std::endl;
    for (j = 0; j < uip->children.size(); j++) {
      //std::cout << "\t\t uc=" << uip->children[j]->uc << std::endl;
      if (str[i] == uip->children[j]->uc) {
        break;
      }
    }

    if (j == uip->children.size()) {
      // failed to find word
      break;
    } else {
      uip = uip->children[j];
      //std::cout << "\t\t uc=" << uip->uc << "\t is_end_word=" << uip->is_end_word << std::endl;
      if (uip->is_end_word) {
        indexs.push_back(i + 1);
      }
    }

    i++;
  }

  return indexs;
}

bool FindWord(const UnitInfo* root,
              const char* origin_str,
              const char* str,
              std::vector<std::vector<std::string> >* words,
              std::map<int, vector<vector<string> > >* index_words,
              std::set<int>* failed_indexs) {
  const int str_index = str - origin_str;
  //std::cout << " >>FindWord(index=" << str_index << ")" << std::endl;
  if (str == nullptr || *str == '\0') {
    //std::cout << "\t return true" << std::endl;
    words->push_back(vector<string>());
    return true;
  }

  if (failed_indexs->find(str_index) != failed_indexs->end()) {
    //std::cout << "\t return false" << std::endl;
    return false;
  }

  const auto iter = index_words->find(str_index);
  if (iter != index_words->end()) {
    *words = iter->second;
    //std::cout << "\t already words.size() = " << words->size() << std::endl;
    return true;
  }

  std::vector<int> indexs = HasWord(root, str);
  //std::cout << "\t indexs.size() = " << indexs.size() << std::endl;

  bool find_word = false;
  for (auto index : indexs) {
    std::vector<std::vector<std::string> > words_tmp;
    if (FindWord(root, origin_str, str + index, &words_tmp, index_words, failed_indexs)) {
      //std::cout << "\t\t index=" << str_index << "\t words_tmp.size()=" << words_tmp.size() << std::endl;
      for (auto& strs : words_tmp) {
        strs.push_back(std::string(str, index));
        words->push_back(strs);
      }
      find_word = true;
    }
  }

  if (!find_word) {
    //std::cout << "\t failed index=" << str_index << std::endl;
    failed_indexs->insert(str_index);
  } else {
    index_words->insert(iter,
    std::pair<int, vector<vector<string>>>(str_index, *words));
  }

  //std::cout << " <<FindWord(str=" << str << ")" << std::endl;
  //std::cout << " <<FindWord(index=" << str_index << ")" << std::endl;
  return find_word;
}

class Solution {
public:
  vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
    vector<string> strs;
    UnitInfo* root = CreateTrieTree(wordDict);
    //PrintTrieTree(root);

    // Store the middle value in order to avoid repetitive computation
    std::set<int> failed_indexs;
    std::map<int, vector<vector<string> > > index_words;
    vector<vector<string> > words;
    FindWord(root, s.c_str(), s.c_str(), &words, &index_words, &failed_indexs);

    for (const auto& tmp_strs : words) {
      std::string line;
      for (auto iter = tmp_strs.rbegin(); iter != tmp_strs.rend(); iter++) {
        line += *iter + " ";
      }
      if (line.size() > 0) {
        strs.push_back(line.substr(0, line.size() - 1));
      }
    }

    return strs;
  }
};

int main() {

  static struct TestCase {
    std::string str;
    unordered_set<string> wordDict;
  } test_cases [] = {
    {
      "aaaaaaa",
      { "aaaa","aa","a" }
    },
    {
      "catsanddog",
      { "cat","cats","and","sand","dog", }
    },

    {
      "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa",
      { "a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa" }
    },
  };

  Solution sln;
  for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i ++) {
    std::cout << "case #" << i << ":" << std::endl;
    vector<string> strs = sln.wordBreak(test_cases[i].str, test_cases[i].wordDict);
    for (const auto& str : strs) {
      std::cout << "str=" << str << "||" << std::endl;
    }
  }
  return 0;
}
