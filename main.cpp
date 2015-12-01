#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <vector>

using namespace std;

class ATM {
private:
	int maxServiceTime;
	int count;
	int averageTime;
public:
	ATM(int maxServiceTime) : maxServiceTime(maxServiceTime), count(0), averageTime(0) {

	}

	int service() {
		int serviceTime = rand() % maxServiceTime;
		averageTime =  ((double)(count) * averageTime + serviceTime) / (count + 1);
		count++;
		return serviceTime;
	}

	int getAverageTime() const {
		return averageTime;
	}
};

#define ATM_AMOUNT 4
#define CLIENT_AMOUNT 100
#define MAX_SERVICE_TIME 100
#define NEW_CLIENT_PERIOD 100

int main() {
	srand(time(NULL));

	vector<ATM> atms;
	for (int i = 0; i < ATM_AMOUNT; i++) {
		atms.push_back(ATM(MAX_SERVICE_TIME));
	}

	for (int i = 0; i < CLIENT_AMOUNT; i++) {
		int atmNumber = rand() % ATM_AMOUNT;
		atms.at(atmNumber).service();
	}
}
