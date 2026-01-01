#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10007

typedef struct Entry {
    int key;
    int value;
    struct Entry* next;
} Entry;

typedef struct {
    Entry* buckets[TABLE_SIZE];
} HashMap;

int hash(int key) {
    int h = key % TABLE_SIZE;
    if (h < 0) {
        return h + TABLE_SIZE;
    } else {
        return h;
    }
}

void update(HashMap* map, int key) {
    int h = hash(key);
    Entry* curr = map->buckets[h];
    while (curr) {
        if (curr->key == key) {
            curr->value++;
            return;
        }
        curr = curr->next;
    }
    Entry* newEntry = (Entry*)malloc(sizeof(Entry));
    newEntry->key = key;
    newEntry->value = 1;
    newEntry->next = map->buckets[h];
    map->buckets[h] = newEntry;
}

int get(HashMap* map, int key) {
    int h = hash(key);
    Entry* curr = map->buckets[h];
    while (curr) {
        if (curr->key == key) return curr->value;
        curr = curr->next;
    }
    return 0;
}

void freeMap(HashMap* map) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Entry* curr = map->buckets[i];
        while (curr) {
            Entry* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

int subarraySum(int* nums, int numsSize, int k) {
    HashMap map = {0};
    update(&map, 0);
    
    int total = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
        count += get(&map, total - k);
        update(&map, total);
    }

    freeMap(&map);
    return count;
}