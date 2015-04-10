  int threeSumClosest(vector<int> &num, int target) {
      int sum = 0;
      if (num.size() < 4)
      {
          for (int i = 0; i < num.size(); i++)
              sum += num[i];
          return sum;
      }
      sort(num.begin(), num.end());
      int mid, right;
      int tsum;
      sum = num[0]+num[1]+num[2];
      
      for (int left = 0; left < num.size() -2; left++)
      {
          mid = left + 1;
          right = num.size() - 1;
          tsum = num[left] + num[mid] + num[right];
          while (mid < right)
          {
              if (abs(target- sum) > abs(target-tsum))
              {
                  sum = tsum;
                  if (target==sum) return target;
              }
              if (target > tsum)
                  mid++;
              else
                  right--;

          }
      }
      return sum;
  }
