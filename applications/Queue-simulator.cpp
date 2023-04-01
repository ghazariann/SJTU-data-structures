#include <iostream>
using namespace std;
#include "../Queue.cpp"

class simulator {
    int arrivalLow;
    int arrivalHigh;
    int serviceTimeLow;
    int serviceTimeHigh;
    int customNum;

   public:
    simulator();
    int avgWaitTime() const;
};

simulator::simulator() {
    cout << "请输入到达时间间隔的上下界：";
    cin >> arrivalLow >> arrivalHigh;
    cout << "请输入服务时间的上下界：";
    cin >> serviceTimeLow >> serviceTimeHigh;
    cout << "请输入模拟的顾客数：";
    cin >> customNum;
    srand(time(NULL));  // 利用系统时间初始化随机
}
int simulator::avgWaitTime() const {
    int currentTime = 0;    // 当前时间
    int totalWaitTime = 0;  // 总的等待时间
    int eventTime;
    linkQueue<int> customerQueue = linkQueue<int>();
    int i;
    for (i = 0; i < customNum; ++i) {
        currentTime += arrivalLow +
                       (arrivalHigh - arrivalLow + 1) * rand() /
                           (RAND_MAX + 1);
        customerQueue.enQueue(currentTime);
    }

    currentTime = 0;
    while (!customerQueue.isEmpty()) {
        eventTime = customerQueue.deQueue();
        if (eventTime < currentTime)
            totalWaitTime += currentTime - eventTime;
        else
            currentTime = eventTime;
        currentTime += serviceTimeLow +
                       (serviceTimeHigh - serviceTimeLow + 1) * rand() / (RAND_MAX + 1);
    }
    return totalWaitTime / customNum;
}

int main() {
    simulator sim;
    cout << "平均等待时间:"
         << sim.avgWaitTime() << endl;
    return 0;
}