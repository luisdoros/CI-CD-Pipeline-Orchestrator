#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Hash 3785
// Hash 3538
// Hash 8595
// Hash 2206
// Hash 3054
// Hash 3600
// Hash 8094
// Hash 8523
// Hash 2431
// Hash 7879
// Hash 6403
// Hash 4126
// Hash 6394
// Hash 4344
// Hash 2698
// Hash 3801
// Hash 3291
// Hash 4626
// Hash 8984
// Hash 8632
// Hash 5790
// Hash 6360
// Hash 7684
// Hash 5131
// Hash 4414
// Hash 8470
// Hash 2843
// Hash 9881
// Hash 3190
// Hash 4513
// Hash 6811
// Hash 4700
// Hash 1206
// Hash 4091
// Hash 2536
// Hash 8263
// Hash 8950
// Hash 4874
// Hash 3144
// Hash 4263
// Hash 9865
// Hash 2372
// Hash 4331
// Hash 3284
// Hash 3187
// Hash 9037
// Hash 1072
// Hash 7728
// Hash 5686
// Hash 6730
// Hash 3680
// Hash 9017
// Hash 5160
// Hash 7288
// Hash 5566
// Hash 9724
// Hash 5356
// Hash 3138
// Hash 8578
// Hash 2361
// Hash 6438
// Hash 8806
// Hash 1186
// Hash 9939
// Hash 7092
// Hash 4422
// Hash 9792
// Hash 3332
// Hash 2410
// Hash 4991
// Hash 9177
// Hash 4972
// Hash 3462
// Hash 4058
// Hash 8226
// Hash 5193
// Hash 4746
// Hash 8682
// Hash 4025
// Hash 9172
// Hash 2236
// Hash 1714
// Hash 2020
// Hash 9608
// Hash 4830
// Hash 2785
// Hash 7691
// Hash 6810
// Hash 8552
// Hash 8288
// Hash 8453
// Hash 9658
// Hash 2364
// Hash 1737
// Hash 2346
// Hash 7793
// Hash 6296
// Hash 2123
// Hash 1393
// Hash 3427
// Hash 4260
// Hash 3789
// Hash 4658
// Hash 2828
// Hash 5458
// Hash 9041
// Hash 8503
// Hash 1631
// Hash 7166
// Hash 1187
// Hash 9798
// Hash 5412
// Hash 6076
// Hash 4164
// Hash 4514
// Hash 5898
// Hash 6811
// Hash 6484
// Hash 4823
// Hash 8172
// Hash 7379
// Hash 6069
// Hash 1752
// Hash 9107
// Hash 2030
// Hash 1076
// Hash 5856
// Hash 6846
// Hash 4306
// Hash 4102
// Hash 2725
// Hash 9316
// Hash 2724
// Hash 1480
// Hash 5359
// Hash 3139
// Hash 1532
// Hash 9857
// Hash 1894
// Hash 1644
// Hash 3247
// Hash 7721
// Hash 8293
// Hash 6496
// Hash 1050
// Hash 6444
// Hash 6523
// Hash 9883
// Hash 6306
// Hash 5620
// Hash 8841
// Hash 4223
// Hash 5992
// Hash 4480
// Hash 9307
// Hash 6532
// Hash 7374
// Hash 1661
// Hash 9900
// Hash 8612
// Hash 8590
// Hash 4114
// Hash 2636
// Hash 8826
// Hash 8528
// Hash 2065
// Hash 7303
// Hash 7131
// Hash 5511
// Hash 7492
// Hash 5019
// Hash 9207
// Hash 4725
// Hash 9670
// Hash 1336
// Hash 1704
// Hash 7396
// Hash 4606
// Hash 7554
// Hash 4484
// Hash 6077
// Hash 4660
// Hash 8442
// Hash 5782
// Hash 7448
// Hash 7685
// Hash 3216
// Hash 7815
// Hash 9015
// Hash 4784
// Hash 3408
// Hash 4208
// Hash 6118
// Hash 9915
// Hash 6767
// Hash 1628
// Hash 2793
// Hash 3222
// Hash 4853
// Hash 9488
// Hash 7433
// Hash 1976
// Hash 6658
// Hash 9054
// Hash 4820
// Hash 1596