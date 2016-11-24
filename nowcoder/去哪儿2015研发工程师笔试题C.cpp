#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class Coder {
public:
	static vector<string> findCoder(vector<string> A, int n) {
		// write code here
		vector<string> lowerA;
		for (auto it_str = A.cbegin(); it_str != A.cend(); it_str++) {
			string str;
			for (auto it_char = it_str->cbegin(); it_char != it_str->cend(); it_char++) {
				str.push_back(tolower(*it_char));
			}
			lowerA.push_back(str);
		}
		struct str_and_times {
			string str;
			int times;
			str_and_times(string s, int t) :str(s), times(t) {}
			bool operator < (const str_and_times &b) const {
				return this->times > b.times;
			}
		};
		vector<str_and_times> V;
		for (auto it = lowerA.cbegin(); it != lowerA.cend(); it++) {
			if (it->find("coder") == string::npos) continue;
			int times = 0;
			for (auto loc = it->find("coder"); loc != string::npos;) {
				loc = it->find("coder", loc + 1);
				times++;
			}
			V.emplace_back(*it, times);
		}
		stable_sort(V.begin(), V.end());
		vector<string> ans;
		for (auto it = V.cbegin(); it != V.cend(); it++) {
			ans.push_back(it->str);
		}
		return ans;
	}
};

int main() {
	vector<string> v = { "coder","dccoderrlcoderxxpicoderhcoderbiwcoderdcoderrcodermcoderdbvcodertrwvycoderimvcoderuswfccoderczecoderczncoderkfuehcoderocoderiuvccoderfwcodervdiycoderifqjcoder","vxroicoderdqcoderfvcodermtyrcoderlcoderwrygcoder","hcoderwzmjccoderamfmvcoderazmcoderhcodersnuccoderceocodermsmifcoderpwpcodertqbqcoderentbcoderxsgpkcoderrqrbcoderucoder" };
	vector<string> ans = Coder::findCoder(v, 4);
	for (auto it = ans.cbegin(); it != ans.cend(); it++) {
		cout << *it << ",";
	}
	cout << endl;
	return 0;
}