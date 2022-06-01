#include<iostream>
#include<conio.h>
#include<time.h>
#include<cstdlib>
#include<windows.h>
#define W 40
#define H 20
using namespace std;


class Snack{
    struct tail;
    struct Point;
    int length, ifpoint;
    typedef char drc;
    tail *head;
	tail *back;
    Point *p;
    int score;
    
    struct tail{
        int posx, posy;
        tail *next;
        tail(int a, int b): posx(a), posy(b), next(nullptr){}
    };
    
    struct Point{
    	int px, py;
    	Point(){
    		srand(time(0));
    		px = rand() % (W-4) +2;
    		py = rand() % (H-2) +1;
    		
		}
	};
    
    
    public:
    	Snack(int a, int x, int y){
    		length = a;
    		head = new tail(x, y);
    		back = head;
    		ifpoint = 0;
    		score = 0;
		}
		bool check(int x, int y){
			tail *t = head;
			while(t != nullptr){
				if(x == t-> posx && y == t-> posy){
					return true;
				}
				t = t-> next;
			}
			return false;
		}
		bool check_point(int x, int y){
			if(p-> px == x && p-> py == y){
				return true;
			}else return false;
		}
		void forward(){
			tail* t = head;
			if(head-> next == nullptr) return;
			while(t-> next-> next != nullptr){
				t = t-> next;
				
			}
			t-> next-> next = head;
			head = t-> next;
			t-> next = nullptr;
			back = t;
			
		}
		void move(drc d){
			int x, y;
			int i = back-> posy, j = back-> posx;
			switch(d){
				case 'W': case 'w':
					x = head-> posx + 0;
					y = head-> posy - 1;
					forward();
					head-> posx = x;
					head-> posy = y;
					break;
				case 'S': case 's':
					x = head-> posx + 0;
					y = head-> posy + 1; 
					forward();
					head-> posx = x;
					head-> posy = y;
					break;
				case 'A': case 'a':
					x = head-> posx - 1;
					y = head-> posy + 0; 
					forward();
					head-> posx = x;
					head-> posy = y;
					break;
				case 'D': case 'd':
					x = head-> posx + 1;
					y = head-> posy - 0; 
					forward();
					head-> posx = x;
					head-> posy = y;
					break;
				default:
					break;
			}
			eat(i, j);
		};
		void eat(int i, int j){
			if(head-> posx == p-> px && head-> posy == p-> py){
				tail *nt = new tail(j, i);
				back-> next = nt;
				back = nt;
				ifpoint = 0;
				delete p;
				score++;
			}
		}
		bool colli();
		void draw();
};

void Snack::draw(){
	int i, j, k;
	if(!ifpoint){
		p = new Point;
		ifpoint = 1;
	}
	
	cout << endl;
	for(k = 0; k < (74-W)/2; k++) cout << " ";
	cout << " ";
	for(j = 0; j < W; j++){
		cout << "M";
	}
	cout << endl;
	for(i = 0; i < H; i++){
		for(k = 0; k < (74-W)/2; k++) cout << " "; 
		cout << "|";
        for(j = 0; j < W; j++){
	        if(check(j, i)){
	        	cout << "O";
			}else if(check_point(j, i)){
				cout << "@";
			}else cout << " ";
        }
        cout << "|";
        if(i == H/2){
        	cout << "    score: " << score ;  
		}
        cout << endl;
        
    }
    for(k = 0; k < (74-W)/2; k++) cout << " ";
    cout << " ";
    for(j = 0; j < W; j++){
		cout << "W";
	}
	//cout << endl << head-> posx << " " << head-> posy << endl << p-> px << " " << p-> py << endl;
}

bool Snack::colli(){
	if(head-> posx >= W || head-> posx <= -1) return false;
	if(head-> posy >= H || head-> posy <= -1) return false;
	tail *t = head-> next;
	while(t != nullptr){
		if(head-> posx == t-> posx && head-> posy == t-> posy) return false;
		t = t-> next;
	}
	return true;
}

void alternate(char &c){
	switch(c){
		case 'W': case 'w': 
			c = 's';
			break;
		case 'S': case 's':
			c = 'w';
			break;
		case 'D': case 'd':
			c = 'a';
			break;
		case 'A': case 'a':
			c = 'd';
			break;
		default:
			break;
	}
}

int main(){
    int i, j, n = 0, tick = 500;
    char control = 'w', c = 'w'; 
    int round = 1;
    Snack Player(1, W/2, H/2);
    clock_t now = clock();
     
    
    
    while(Player.colli()){
        if(round){
			system("cls");
			Player.draw();
			Player.move(control);
        }
        clock_t pass = clock();
        round = 0;
        if(pass-now > tick){
        	now = pass;
        	round = 1;
        	if(tick > 100) tick = tick - 2;			
		}
		if(kbhit()){
            c = getch();
            alternate(c);
            if(control != c){
            	alternate(c);
            	control = c;
			}
        }
    }

    return 0;
}




