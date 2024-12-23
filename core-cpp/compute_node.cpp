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