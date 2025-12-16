class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        int n = position.size();

        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], speed[i]});
        }

        sort(cars.begin(), cars.end());

        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            double time = (double)(target - cars[i].first) / cars[i].second;

            if (!st.empty() && time <= st.top()) {
                // joins the fleet ahead
                continue;
            }

            st.push(time);
        }

        return st.size();
    }
};
