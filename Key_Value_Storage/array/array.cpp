#include "kv_array.h"
#include <iostream>
#include <functional>
#include <chrono>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <random>

#define NR_TESTS (1 << 15)

using namespace std;
using namespace std::chrono;

array_storage as;

void putItems(const vector<string>& keys, bool debugFlag, bool sortFlag) {
    for (const auto& key : keys) {
        //cout << "Putting " << key <<"\n";
        as.put(key, "value_" + key.substr(4), sortFlag); // assuming that key is in the form "key_X"
        if (debugFlag) {
            cout << "Key: " << key << ", Value: " << "value_" + key.substr(4) << "\n";
        }
    }
}

void getItems(const vector<string>& keys, bool debugFlag) {
    for (const auto& key : keys) {
        string expectedValue = "value_" + key.substr(4);
        //cout << "getting " << key <<"\n";
        string value = as.get(key);

        if (debugFlag) {
            cout << "Value: " << value << "\n";
        }

        if (value.empty()) continue;

        if (value != expectedValue) {
            cerr << "Verification failed for key: " << key << "\n";
            exit(-1);
        }
    }
}

void removeItems(const vector<string>& keys, bool debugFlag) {
    for (const auto& key : keys) {
        as.remove(key);

        if (debugFlag) {
            cout << "Remove Key: " << key << "\n";
        }
    }
}

vector<string> createKeys(bool randomFlag) {
    vector<string> keys;

    keys.reserve(NR_TESTS);

    for (int i = 0; i < NR_TESTS; ++i) {
        keys.emplace_back("key_" + to_string(i));
    }

    if (randomFlag) {
        // Shuffle the keys if randomFlag is true
        std::random_device rd;
        std::mt19937 g(rd());
        shuffle(keys.begin(), keys.end(), g);
    }

    return keys;
}

double measureExecutionTime(function<void()> func) {
    auto start = high_resolution_clock::now();
    func();
    auto end = high_resolution_clock::now();
    return duration_cast<duration<double>>(end - start).count();
}

int main(int argc, char **argv) {
    bool randomFlag = false;
    bool debugFlag = false;
    bool sortFlag = false;

    double elapsedPut;
    double elapsedGet;
    double elapsedRemove;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-r") == 0) {
            randomFlag = true;
        }
        if (strcmp(argv[i], "-d") == 0) {
            debugFlag = true;
        }
        if (strcmp(argv[i], "-s") == 0) {
            sortFlag = true;
        }

    }

    cout << "Number of tests: " << NR_TESTS << "\n";

    vector<string> keys = createKeys(randomFlag);
    elapsedPut = measureExecutionTime([&]() { putItems(keys, debugFlag, sortFlag); });
    cout << "Time taken to put " << NR_TESTS << " items: " << elapsedPut << " seconds.\n";

    if (randomFlag) keys = createKeys(randomFlag);
    elapsedGet = measureExecutionTime([&]() { getItems(keys, debugFlag); });
    cout << "Time taken to get " << NR_TESTS << " items: " << elapsedGet << " seconds.\n";

    if (randomFlag) keys = createKeys(randomFlag);
    elapsedRemove = measureExecutionTime([&]() { removeItems(keys, debugFlag); });
    cout << "Time taken to remove " << NR_TESTS << " items: " << elapsedRemove << " seconds.\n";

    if (randomFlag) keys = createKeys(randomFlag);
    elapsedGet = measureExecutionTime([&]() { getItems(keys, debugFlag); });
    cout << "Time taken to get " << NR_TESTS << " items: " << elapsedGet << " seconds.\n";

    return 0;
}