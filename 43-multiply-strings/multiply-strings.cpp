class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
    
        int m = num1.size(), n = num2.size();
        vector<int> result(m + n, 0);
        
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                int sum = product + result[i + j + 1];
                
                result[i + j + 1] = sum % 10;        
                result[i + j] += sum / 10;           
            }
        }
        
        
        string str;
        for (int num : result) {
            if (!(str.empty() && num == 0)) { 
                str += to_string(num);
            }
        }
        
        return str.empty() ? "0" : str;
        }
};