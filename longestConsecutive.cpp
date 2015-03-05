int longestConsecutive(vector<int> &num) {
    unordered_map<int,int> dict;
    int cnt;
    int maxCnt=0;
    for (int i = 0; i < num.size(); i++)
    {
        auto it = dict.find(num[i]);
        if (it==dict.end())
        {
          auto lit = dict.find(num[i] - 1);
          auto rit = dict.find(num[i] + 1);
          int leftV = dict[num[i]-1];
          int rightV= dict[num[i]+1];
          if (lit == dict.end() && rit == dict.end() )
          {
                cnt = 1;
          }
          else if (lit != dict.end() && rit != dict.end()) 
          {
                cnt = leftV +rightV + 1;
                dict[num[i]-leftV] = cnt;
                dict[num[i]+rightV] = cnt;
                                 
          }
          else if (lit == dict.end() && rit != dict.end()) 
          {
                cnt = rightV + 1;
                dict[num[i]+rightV] = cnt;
          }
          else 
          {
                cnt = leftV + 1;
                dict[num[i]-leftV] = cnt;
          }
          maxCnt = max(maxCnt, cnt);
          dict.insert({num[i], cnt});
        }
    }
    return maxCnt;
}
