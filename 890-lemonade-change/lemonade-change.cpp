class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5) five ++;
            else if(bills[i] == 10){
                if(five){
                    five -= 1;
                    ten += 1;
                }
                else return false;
            }
            else{
                if(ten && five){
                    ten = ten - 1;
                    five = five -1;
                }
                else if(five >= 3) five -= 3;
                else return false;
            }
        }
        return true;
    }
};