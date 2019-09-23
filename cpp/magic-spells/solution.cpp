#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";

void counterspell(Spell *spell) {

  /* Enter your code here */
    if(Fireball* f = dynamic_cast<Fireball*>(spell)){
        f->revealFirepower();   
    }else if(Frostbite* f = dynamic_cast<Frostbite*>(spell)){
        f->revealFrostpower();  
    }else if(Thunderstorm* f = dynamic_cast<Thunderstorm*>(spell)){
        f->revealThunderpower(); 
    }else if(Waterbolt* f = dynamic_cast<Waterbolt*>(spell)){
        f->revealWaterpower();
    }else{
        //std::cout<<6<<endl;
        string s1 = spell->revealScrollName();
        string s2 = SpellJournal::journal;
        int n= s1.size(), m = s2.size();
        int lcsMat[n+1][m+1];
        for (int i = 0; i <= n; ++i) {
            lcsMat[i][0] = 0;
        }

        for (int i = 0; i <= m; ++i) {
            lcsMat[0][i] = 0;
        }

        for(int i=1;i<= n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1])
                    lcsMat[i][j] = 1 + lcsMat[i-1][j-1];
                else
                    lcsMat[i][j] = std::max(lcsMat[i-1][j], lcsMat[i][j-1]);
            }
        }
        
        std::cout<<lcsMat[n][m]<<endl;
    }
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}
