#pragma once
#include <iostream>
#include <string>
#include <vector>

class Hashmap {
private:
    std::vector<std::vector<std::pair<std::string, std::string>>> hashmap;
    long getHash(std::string key);

public:
    int bucketSize;
    Hashmap(int bucketSize);
    void insert(std::string key, std::string ip);
    std::string search(std::string url);

};

Hashmap::Hashmap(int bucketSize) {
    //Constructor with bucketSize
    this->bucketSize = bucketSize;
    hashmap.resize(bucketSize);
}


void Hashmap::insert(std::string key, std::string ip) {
    //Get hash
    long hash = getHash(key);
    //Insert with hash
    this->hashmap.at(hash).push_back(std::pair<std::string, std::string>(key,ip));
}

std::string Hashmap::search(std::string url) {
    //Get hash
    long hash = getHash(url);

    //Get bucket with hash
    std::vector<std::pair<std::string, std::string>> urls = this->hashmap.at(hash);

    //Search within bucket
    for (int i = 0; i < urls.size(); i++) {
        if (urls.at(i).first == url) {
            return urls.at(i).second;
        }
    }
    //If not found
    return "";
}

long Hashmap::getHash(std::string key) {
    //Sum powers of 31 ascii
    long val = 0;
    int i = 0;
    while (i < key.length() && i < 10) {
        char t = key[i];
        val = ((31 * val + (int)t)) % bucketSize;
        i++;
    }
    return val;
}