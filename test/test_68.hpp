#include "head.hpp"
#include <string>
#include <vector>

class Test_68 {
public:
    Test_68() {
        {
            vector<string> words = {"This", "is", "an", "example", "of", "text", "justification."};
            for (const auto& s : fullJustify(words, 16)) cout << s << endl;
            cout << endl;
        }
        {
            vector<string> words = {"What","must","be","acknowledgment","shall","be"};
            for (const auto& s : fullJustify(words, 16)) cout << s << endl;
            cout << endl;
        }
        {
            vector<string> words = {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"};
            for (const auto& s : fullJustify(words, 20)) cout << s << endl;
            cout << endl;
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ret;
        for (int i = 0, j = 0; i <= j && j < words.size();) {
            int word_total_len = 0;
            while (j < words.size()) {
                const int word_len = words[j].size();
                // j - 1 : 至少需要的空格数
                if (word_total_len + words[j].size() + (j - i) > maxWidth) {
                    --j;    // 超过总长度
                    break;
                }
                word_total_len += words[j++].size();
            }
            string s;
            if (j >= words.size()) {
                // 最后一行，左对齐
                while (i <= words.size()) { s += words[i++] + " "; }
                s.resize(maxWidth, ' ');
            } else if (i == j) {
                // 一个单词一行的
                s = words[i++] + string(maxWidth - word_total_len, ' ');
            } else {
                vector<string> space_vec(j - i);
                for (int a = 0, use = 0; a <= j - i && use < maxWidth - word_total_len; ++a, ++use) {
                    if (a >= j - i) a = 0;
                    space_vec[a] += " ";
                }
                int space_index = 0;
                while (i <= j) {
                    s += words[i++];
                    if (i <= j) { s += space_vec[space_index++]; }
                }
            }
            j = i;
            ret.push_back(s);
        }
        return ret;
    }
};