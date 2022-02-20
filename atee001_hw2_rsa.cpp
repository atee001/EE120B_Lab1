#include <iostream>
#include <vector>
#include <map>

using namespace std;


int square_method(int base, int exponent, int mod, int result){
    
    if(exponent == 1) {
        result = (base*result)%mod;
        return result;
    }
    
    else if(exponent == 0) return result;
    
    else if(exponent%2 == 0){
        
        base = base * base;
        base = base % mod;
        exponent /= 2;
        return square_method(base, exponent, mod, result);
    }
    else if(!(exponent%2 == 0)){
        
        result *= base;
        result = result % mod;
        base = base * base;
        base = base % mod;
        exponent = (exponent-1)/2;
        return square_method(base, exponent, mod, result);
    }
    
    
}



int main()
{
    vector<int> vec{30, 673, 332, 785, 171, 589, 782, 171, 828, 589, 785, 568,
    782, 785, 713, 782, 813, 785, 123, 589, 828, 673, 589, 487,
    589, 785, 813, 890, 243, 813, 785, 733, 243, 813, 890, 589,
    733, 243, 813, 673, 422, 769, 785, 673, 769, 785, 769, 673,
    733, 171, 828, 589, 291, 785, 673, 813, 785, 673, 769, 785,
    782, 713, 828, 482, 785, 123, 589, 422, 243, 500, 769, 589,
    785, 813, 890, 589, 482, 785, 568, 782, 785, 713, 782, 813,
    785, 549, 589, 243, 828, 673, 367, 589, 785, 890, 782, 587,
    785, 422, 782, 733, 171, 828, 673, 422, 243, 813, 589, 568,
    785, 828, 673, 332, 589, 785, 673, 769, 777, 30};
    
    
    int result = 1;
    int exponent = 333;
    int mod = 901;
    char alpha = 'A';
    for(auto it : vec){
        
        if(square_method(it, exponent, mod, result) > 2 &&  square_method(it, exponent, mod, result) < 29){
            cout << char(alpha + (square_method(it, exponent, mod, result) - 3));
        }
        
        else if(square_method(it, exponent, mod, result) == 29) cout << " ";
        else if(square_method(it, exponent, mod, result) == 30) cout << "\"";
        else if(square_method(it, exponent, mod, result) == 31) cout << ".";
        else if(square_method(it, exponent, mod, result) == 32) cout << ",";
        else if(square_method(it, exponent, mod, result) == 33) cout << "'";
    
    }
    
    
    
    return 0;

  
}