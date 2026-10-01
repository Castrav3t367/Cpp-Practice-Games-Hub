vector<int> nums = {73, 12, 45, 2, 91, 34, 8};

sort(nums.begin(), nums.end());
for(int i=0;i<nums.size();i++)
{
    cout << nums[i] << " ";
}

sort(nums.begin(), nums.end(), greater<int>());
for(int i=0;i<nums.size();i++)
{
    cout << nums[i] << " ";
}



vector<int> nums = {10, 25, 40, 15, 30, 50};

auto it =find(nums.begin(),nums.end(),40);
if(it==true){
    
    cout<<"Element found"<<*it;
    cout<<distance(nums.begin(),it);
}
else{
    cout<<"Element not found";
}


vector<int> nums = {5, 12, 8, 20, 33, 7};
for(int i=0;i<nums.size();i++){
    cout<<nums[i]<<" ";
}
reverse(nums.begin(),nums.end());
auto it = find(nums.begin(), nums.end(), 20);
if(it != nums.end()){
    cout<<*it<<distance(nums.begin(),it);
}else{
    cout<<"Element not found";
}



vector<int> nums = {10, 5, 20, 5, 30, 5, 40, 10};

int five=count(nums.begin(), nums.end(), 5);
cout<<five;
int ten=count(nums.begin(), nums.end(), 10);
cout<<ten;
int twenty=count(nums.begin(), nums.end(), 20);
cout<<twenty;