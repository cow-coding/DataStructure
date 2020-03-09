#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Arr.cpp"
using namespace std;

int main() {
    int M, N;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        cin >> N;
        
        Arr bank(N);
        
        for (int j = 0; j < N; j++) {
            int money;
            
            cin >> money;
            
            bank.add(j, money);
        }
        
        int ksum = 0, jsum = 0, csum = 0;
        double kavg = 0.0, javg = 0.0, cavg =0.0;
        int k = 0, jap = 0, c = 0;
        
        for (int j = 0; j < N ; j++) {

            if (j % 3 == 0) {
                if (bank[j] != 0){
                    ksum += bank[j];
                    k++;
                }
            }
            else if (j % 3 == 1) {
                if (bank[j] != 0) {
                    jsum += bank[j];
                    jap++;
                }
            }
            else if (j % 3 == 2) {
                if (bank[j] != 0) {
                    csum += bank[j];
                    c++;
                }
            }
        }
        
        if (k == 0) {
            kavg = 0;
            if (jap == 0) {
                javg = 0;
                if (c == 0) {
                    cavg = kavg;
                } else {
                    cavg = floor(csum / c);
                }
            } else {
                javg = floor(jsum / jap);
                if (c == 0)
                    cavg = 0;
                else
                    cavg = floor(csum/ c);
            }
        } else {
            kavg = floor(ksum / k);
            if (jap == 0) {
                javg = 0;
                if (c == 0) {
                    cavg = javg;
                } else {
                    cavg = floor(csum / c);
                }
            } else {
                javg = floor(jsum / jap);
                
                if (c == 0)
                    cavg = 0;
                else
                    cavg = floor(csum / c);
            }
        }
        
        cout << ksum << " " << jsum << " " << csum << "\n";
        cout << static_cast<int>(kavg) << " " << static_cast<int>(javg) << " " << static_cast<int>(cavg) << "\n";
    }
}
