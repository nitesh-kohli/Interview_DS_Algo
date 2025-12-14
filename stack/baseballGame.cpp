class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        for(auto op : operations){
            if(op == "+"){
                int last = s.top();
                s.pop();
                int secondLast = s.top();
                s.push(last);
                s.push(last + secondLast);
            }
            else if(op == "C"){
                s.pop();
            }
            else if(op == "D"){
                int last = s.top();
                int temp = 2*last;
                s.push(temp);
            }
            else    
                s.push(stoi(op));

        }

        int sum = 0;
        while(!s.empty()){
            sum += s.top();
            s.pop();
        }
        return sum;
    }
};