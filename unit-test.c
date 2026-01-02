#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "test.c"

void test_hash_map() {
    HashMap map = {0};
    assert(get(&map, 10) == 0);
    update(&map, 10);
    assert(get(&map, 10) == 1);
    update(&map, 10);
    assert(get(&map, 10) == 2);
    update(&map, -5);
    assert(get(&map, -5) == 1);
    freeMap(&map);
}

void test_subarray_sum_normal() {
    int nums[] = {1, 1, 1};
    assert(subarraySum(nums, 3, 2) == 2);
    
    int nums2[] = {1, 2, 3};
    assert(subarraySum(nums2, 3, 3) == 2);
}

void test_subarray_sum_edge_cases() {
    int nums_neg[] = {1, -1, 0};
    assert(subarraySum(nums_neg, 3, 0) == 3);

    int nums_single[] = {1};
    assert(subarraySum(nums_single, 1, 0) == 0);
    
    int nums_zeros[] = {0, 0, 0};
    assert(subarraySum(nums_zeros, 3, 0) == 6);
}

int main() {
    test_hash_map();
    test_subarray_sum_normal();
    test_subarray_sum_edge_cases();
    printf("UNIT TESTS PASSED SUCCESSFULLY\n");
    return 0;
}