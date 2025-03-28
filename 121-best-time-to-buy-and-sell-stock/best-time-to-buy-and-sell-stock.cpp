class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int mini = prices[0];
        // int maxProfit = 0;
        // for(int i=0;i<prices.size();i++){
        //     int cost = prices[i] - mini;
        //     int maxProit = max(maxProfit,cost);
        //     int mini = min(mini,prices[i]);
        // }
        // if(maxProfit){
        //      return maxProfit;
        // }else{
        //     return 0;
        // }
        // int buy = prices[0];
        // int profit = 0;
        // for (int i = 1; i < prices.size(); i++) {
        //     if (prices[i] < buy) {
        //         buy = prices[i];
        //     } else if (prices[i] - buy > profit) {
        //         profit = prices[i] - buy;
        //     }
        // }
        // return profit;
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for (int currentPrice : prices) {
            minPrice = min(currentPrice, minPrice);
            maxProfit = max(maxProfit, currentPrice - minPrice);
        }
        
        return maxProfit;
       
    }
};