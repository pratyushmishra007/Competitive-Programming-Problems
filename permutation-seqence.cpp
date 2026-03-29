class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        string ans = "";
        vector<int> vec;
        for(int i = 1; i<n; ++i){
            vec.push_back(i);
            fact*=i;
        }
        vec.push_back(n); k--;
        while(true){
            ans+=to_string(vec[k/fact]);
            vec.erase(vec.begin()+k/fact);
            if(vec.size() == 0) break;
            k%=fact;
            fact/=vec.size();
        }

        return ans;
    }
};