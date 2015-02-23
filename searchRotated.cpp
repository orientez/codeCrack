  mid = (first + last) / 2;
            if (target==A[first]) return first;
            if (target==A[mid]) return mid;
            if (target==A[last]) return last;
            
            if (A[first] < A[mid] && A[mid] < A[last])
            {
                if (A[first] < target && A[mid] > target)
                    last = mid - 1;
                else if (target > A[mid] && target < A[last])
                    first = mid + 1;
                else
                    return -1;
            }
            else if (A[first] < A[mid] && A[last] < A[first])
            {
                if (A[first] < target && A[mid] > target)
                    last = mid - 1;
                else if (target > A[mid] || target < A[last])
                    first = mid + 1;
                else
                    return -1;                
            } 
            else if (A[first] > A[mid] && A[first] > A[last])
            {
                if ( A[mid] > target || target > A[first])
                    last = mid - 1;
                else if (target > A[mid] && target < A[last])
                    first = mid + 1;
                else
                    return -1;                
            }  
            else if (A[first] < A[mid] && A[first] > A[last])
            {
                if (A[first] < target && A[mid] > target)
                    last = mid - 1;
                else if (target > A[mid] || target < A[last])
                    first = mid + 1;
                else
                    return -1;                
            }
            
            
