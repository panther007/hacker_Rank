#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops
struct Workshops{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops{
    int n;
    std::vector<Workshops> w;
};

//Implement the functions initialize and CalculateMaxWorkshops

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    for(int i=0;i<n;i++){
        Workshops ws;
        ws.start_time = start_time[i];
        ws.duration = duration[i];
        ws.end_time = start_time[i]+duration[i];
        aw->w.push_back(ws);
    }
    std::sort(aw->w.begin(),aw->w.end(), [](Workshops w1, Workshops w2){return w1.end_time<w2.end_time;});
    return aw;
}

int CalculateMaxWorkshops(Available_Workshops* ptr){
    int ret=0, lastET=-1;
    for(int i=0;i<ptr->n;i++){
        if(ptr->w[i].start_time >= lastET){
            ret++;
            lastET = ptr->w[i].end_time;
        }
    }
    return ret;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
