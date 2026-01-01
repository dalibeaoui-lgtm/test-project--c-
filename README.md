# Subarray Sum Equals K (LeetCode #560)

## 📌 Problem Description
Given an array of integers `nums` and an integer `k`, this program returns the total number of continuous subarrays whose sum equals `k`.

* **LeetCode Reference:** [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
* **Implementation Language:** C (C11)

---

## 🌍 Real-Life Use Case: Financial Auditing
This algorithm is widely used in **FinTech for detecting "Structuring" or "Smurfing."** In financial auditing, a user might try to bypass reporting thresholds (like a $\$10,000$ limit) by making several smaller transactions that add up to that exact amount over a specific period. This program can scan a massive ledger of transactions in a single pass to identify every specific time window where the cumulative sum of money moved matches a target suspicious value.

---

## 🧠 Approach: Prefix Sum & Hash Map
The solution avoids the inefficient $O(n^2)$ brute-force approach by using a **Prefix Sum** strategy combined with a **Custom Hash Map**.

### 1. Mathematical Logic
We maintain a running total (prefix sum) as we iterate through the array. For any current index $i$, we want to find how many previous indices $j$ exist such that:
$$\text{Current Sum}_i - \text{Previous Sum}_j = k$$

This is equivalent to checking:
$$\text{Previous Sum}_j = \text{Current Sum}_i - k$$



### 2. Custom Hash Map Implementation
Since C does not have a built-in dictionary or hash map, this project implements a **Chaining Hash Map**:
* **Hashing:** Uses a modulo-based hash function with a prime table size ($10,007$) to minimize collisions.
* **Collision Handling:** Uses linked lists (chaining) at each bucket.
* **Efficiency:** Allows us to store and retrieve the frequency of every prefix sum in average $O(1)$ time.

---

## 📊 Complexity Analysis

| Metric | Complexity | Explanation |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We perform a single pass through the array. Hash map operations (insert/find) are $O(1)$ on average. |
| **Space Complexity** | $O(n)$ | In the worst case, we store every unique prefix sum in the hash map. |

---

## ⚙️ How to Compile and Run

### Prerequisites
* `gcc` (GNU Compiler Collection)
* Standard C libraries (`stdio.h`, `stdlib.h`)

### Compilation
Use the following command to compile the source code along with your test runner:
```bash
gcc -o subarray_solver main.c -O3
