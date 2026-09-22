class Solution {
public:
    bool validSeg(string s) {
        if (s.size() > 3 || (s[0] == '0' && s.size() > 1)) return false;
        int seg = stoi(s);
        return seg <= 255;
    }
    void backtrack(string &s, vector<string>& ips, string ip, int dot, int idx) {
        int n = s.size();
        if (dot == 0) {
            string remain = s.substr(idx + 1);
            if (remain == "") return;
            if (validSeg(remain)) {
                ips.push_back(ip + remain);
            }
            return;
        }
        string seg = "";
        for (int i = idx + 1; i < n && i <= idx + 3; i++) {
            seg += s[i];
            if (validSeg(seg)) {
                string newIp = ip + seg + ".";
                backtrack(s, ips, newIp, dot - 1, i);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ips;
        string ip = "";
        backtrack(s, ips, ip, 3, -1);
        return ips;
    }
};
