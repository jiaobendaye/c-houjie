//design
void print()
{}

template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)//sizeof...(args);
{
	cout << firstArg << endl;
	print(args...);
}
//uesr
print(3.4, "hello", bitset<16>(343), 432);

//auto
list<string> c;
...
list<string>::iterator ite;
ite = find(c.begin(), e.end(), target);
//
auto ite = find(c.begin(), e.end(), target);

//ranged-based for
for (dec2 : coll) {
	statement
}
for (int i : {2, 3, 4, 5, 6, 7, 9}){
	count<<i<<endl;
}

vector<double> vec;
...
for (auto elem : vec){
	cout << elem << endl;
}
for (auto& elem : evc) {
	elem *= 3;
}
