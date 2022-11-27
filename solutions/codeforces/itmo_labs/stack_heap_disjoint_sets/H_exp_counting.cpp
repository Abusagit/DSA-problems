#include <iostream>
#include <vector>
#include <string>
#define int long long int
using namespace std;


struct ClanInfo {
    int size;
    int exp;
};


vector<int> clans;
vector<ClanInfo> info;

int find_clan(int x){
    while (x != clans[x]){
        x = clans[x];
    }
    return x;
}

int get_exp(int x){
    if (clans[x] == x){
        return info[x].exp;
    }


    // every time we take into account difference between info[x] and and next clan of player x - b.c. if unite_2_clans we stored this difference in smaller clan exp field
    return get_exp(clans[x]) + info[x].exp;
}

void unite_2_clans(int clan_1_player, int clan_2_player){
    int clan_1 = find_clan(clan_1_player);
    int clan_2 = find_clan(clan_2_player);

    if (clan_1 == clan_2){
        return;
    }


    // merge smaller clan with larger one


    // T(union) = O(nlogn)
    if (info[clan_1].size < info[clan_2].size){
        // clan_1 is smaller
        info[clan_1].exp -= info[clan_2].exp; // store difference in exp between new root and old roow of smaller clan - will be used in get_exp(x)

        info[clan_2].size += info[clan_1].size;
        clans[clan_1] = clan_2;
    } else {
        // clan_1 is larger
        info[clan_2].exp -= info[clan_1].exp;

        info[clan_1].size += info[clan_2].size;
        clans[clan_2] = clan_1;
    }


}


signed main(){
    int n, m; cin >> n >> m;
    clans.resize(n + 1);
    info.resize(n + 1);

    for (int i = 1; i <= n; i++){
        clans[i] = i;
        info[i].exp = 0;
        info[i].size = 1;
    }

    for (int q = 0; q < m; q++){
        string command; cin >> command;

        if (command == "add"){
            int x, y; cin >> x >> y;
            info[find_clan(x)].exp += y;



        } else if (command == "join"){
            int x, y; cin >> x >> y;
            unite_2_clans(x, y);


        } else {
            int x; cin >> x;
            cout << get_exp(x) << '\n';
        }
    
    }

}