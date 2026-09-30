vector<int> nums = {5, 10, 15};
nums.push_back(20);
nums.pop_back();
nums.push_back(100);
nums[0]=50;

for (int i = 0; i < nums.size(); i++) {
    cout<<nums[i]<<" ";
}




vector<int>numbs={10,20,30,40};
numbs.pop_back();
numbs.push_back(100);
numbs.push_back(200);

numbs[1]=999;
for(int i=numbs.size()-1;i>=0;i--){
    cout<<numbs[i]<<" ";
}





vector<int> numbers={4,7,2,9,1,8};
for(int i=0;i<numbers.size();i++){
    if(numbers[i]%2==0){
        cout<<numbers[i]<<" ";
        int count;
        count++
        cout<<count;  
    }
}






vector<int> nums = {12, 5, 27, 8, 19, 3};
int max=0;
for(int i=0;i<nums.size();i++){
    if(nums[i]>max){
        max=nums[i];
    }
}
cout<<max;







vector<int> nums = {12, 5, 27, 8, 19, 3, 30, 14};
int max = nums[0];
int min = nums[0];
int count = 0;
for(int i=0;i<nums.size();i++){
    if(nums[i]>max){
        max=nums[i];
    }
    if(nums[i]<min){
        min=nums[i];
    }if(nums[i]%2==0){

    count++;
}
}\







vector<int> nums = {10, 20, 30, 40, 50};
nums.front() = 100;
nums.back() = 500;
nums.at(2) = 999;
cout << "First element: " << nums.front() << endl;
cout << "Last element: " << nums.back() << endl;
for (int i = 0; i < nums.size(); i++) {
    cout << "Element at index " << i << ": " << nums.at(i) << endl;
}



vector<int> nums = {10, 20, 40, 50};
nums.insert(nums.begin() + 2, 30);
nums.erase(nums.back());
nums.insert(nums.begin(),5);
for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
}



vector<int> nums = {10, 20, 30, 40, 50, 60};
nums.erase(nums.begin()+1);
nums.erase(nums.begin()+4);
nums.insert(nums.begin()+1, 2);
for (int i = 0; i < nums.size(); i++) {
    cout << nums[i] << " ";
}




vector<int> nums = {5, 10, 15, 20};
void printVector(const vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}



void doubleValues(vector<int>& nums){
    
    for(int i=0;i<nums.size();i++){
        nums[i]*=2;
    }
}
int main (){
    vector<int> nums = {5, 10, 15, 20};
    doubleValues(nums);
}\


void removeOddNumbers(vector<int>& nums){
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2!=0){
            nums.erase(nums.begin()+i);
            i--;
        }
    }
}

int countEvenNumbers(const vector<int>& nums){
    int count = 0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            count++;
        }
    }
    return count;
}




vector<int> getEvenNumbers(const vector<int>& nums){
    vector<int> rezult;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            rezult.push_back(nums[i]);
        }
    }
    return rezult;
}


vector<int> doubleEvenNumbers(const vector<int>& nums){
    vector<int>rezult;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%2==0){
            rezult.push_back(nums[i]*2);
        }
    }
    return rezult;
}