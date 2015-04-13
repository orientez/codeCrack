struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};



void printInter(vector<Interval> is)
{
    for (int i = 0; i < is.size(); i++)
    {
        cout << "[" << is[i].start << ", " << is[i].end << "], ";
    }
    cout << "\n";

}
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    int start = 0;
    int end = 0;
    vector<Interval> ret;
    bool isStartFound = false;
    int isize = intervals.size();
    int i = 0;
    while ( i < isize && !isStartFound)
    {
        if (newInterval.start > intervals[i].start)
        {
            start++;
            if (newInterval.start > intervals[i].end )
            {
                start++;
            }
            else
                isStartFound =true;
        }
        else
            isStartFound = true;
        i++;
    }
    if (i==isize) 
    {
        ret = intervals;
        ret.push_back(newInterval);
        return ret;
    }
    
    bool isEndFound = false;
    i--;
    end = (start/2)*2;
    while ( i < isize && !isEndFound)
    {
        if (newInterval.end >= intervals[i].start)
        {
            end++;
            if (newInterval.end > intervals[i].end )
            {
                end++;
            }
            else
                isEndFound =true;
        }
        else
            isEndFound = true;
        i++;
    }
    cout << start << " " << end << "\n";
    ret.insert(ret.end(), intervals.begin(), intervals.begin()+start/2);
    Interval inter;
    if (start%2==0) inter.start = newInterval.start;
    else inter.start = intervals[start/2].start;
    
    if (end%2==0) inter.end = newInterval.end;
    else inter.end = intervals[end/2].end;
    ret.push_back(inter);
    ret.insert(ret.end(), intervals.begin()+(end+1)/2, intervals.end());
    //printInter(ret);
    return ret;
}
