# include <iostream>
# include <vector>

# define PRIME 1000000007
# define ull unsigned long long int

using namespace std;

int main(){

    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false); // faster input and output

    int n; cin >> n; 
    vector<ull> array(n);
    for (int i = 0; i < n; i++){
        cin >> array[i];
        // cout << array[i] << "\n";
    }

    // precompute remainder for every power of 2 from 0 to 100
    vector<ull> remainders_of_power_of_2(101);
    
    ull exp = 1;
    remainders_of_power_of_2[0] = 1;
    for (int i = 1; i <= 100; i++){
        exp <<= 1; // raise to the power of 2
        // cout << i << " " << exp << "\n";
        if (exp >= PRIME){
            exp -= PRIME;
        }

        remainders_of_power_of_2[i] = exp;
    }

    // vector<ull> remainders_of_power_of_2({1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 
    //                                         2048, 4096, 8192, 16384, 32768, 65536, 131072, 
    //                                         262144, 524288, 1048576, 2097152, 4194304, 8388608, 
    //                                         16777216, 33554432, 67108864, 134217728, 268435456, 
    //                                         536870912, 73741817, 147483634, 294967268, 589934536, 
    //                                         179869065, 359738130, 719476260, 438952513, 877905026, 
    //                                         755810045, 511620083, 23240159, 46480318, 92960636, 185921272, 
    //                                         371842544, 743685088, 487370169, 974740338, 949480669, 898961331, 
    //                                         797922655, 595845303, 191690599, 383381198, 766762396, 533524785, 
    //                                         67049563, 134099126, 268198252, 536396504, 72793001, 145586002, 
    //                                         291172004, 582344008, 164688009, 329376018, 658752036, 317504065, 
    //                                         635008130, 270016253, 540032506, 80065005, 160130010, 320260020, 
    //                                         640520040, 281040073, 562080146, 124160285, 248320570, 496641140, 
    //                                         993282280, 986564553, 973129099, 946258191, 892516375, 785032743, 
    //                                         570065479, 140130951, 280261902, 560523804, 121047601, 242095202, 
    //                                         484190404, 968380808, 936761609, 873523211, 747046415, 494092823, 
    //                                         988185646, 976371285});

    ull ways_to_cover_without_last_vertex = 1, ways_to_cover_with_last_vertex = 1;

    for (int i = 1; i < n; i++){
        // cout << ways_to_cover_without_last_vertex << " " << ways_to_cover_with_last_vertex<< " " << remainders_of_power_of_2[array[i]] << " " << array[i] << "\n";

        ull tmp = ways_to_cover_with_last_vertex;

        // dynamic step:
        ull s = (ways_to_cover_with_last_vertex + ways_to_cover_without_last_vertex) % PRIME;
        ways_to_cover_with_last_vertex = (remainders_of_power_of_2[array[i]] * s) % PRIME;
        
        ways_to_cover_without_last_vertex = tmp;
    }

    ull ans = (ways_to_cover_with_last_vertex + ways_to_cover_without_last_vertex) % PRIME;

    cout << ans << "\n";

    return 0;
}