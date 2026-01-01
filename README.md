# Subarray Sum Equals K

## 1. Problem Description
The objective of this project is to find the total number of continuous subarrays within an integer array that sum up to a specific target value $k$.

* **LeetCode Reference:** [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)
* **Language:** C

---

## 2. Real-Life Use Case: Financial Pattern Detection
This algorithm is highly effective for **Financial Transaction Monitoring**. 

Imagine a bank monitoring a stream of credit card transactions. A common fraud technique involves "structuring"—breaking a large, suspicious transaction into several smaller ones to avoid detection. By using the Subarray Sum algorithm, the bank's system can scan a customer's transaction history in real-time to identify any continuous sequence of purchases that exactly equals a flagged "high-risk" total (the value $k$), even if that total is spread across multiple days.

---

## 3. Explanation of Approach
The solution uses a **Prefix Sum** strategy combined with a **Hash Map** to achieve linear time efficiency.

### Core Logic:
1.  **Prefix Sum:** We iterate through the array once, keeping a running `total` of all elements seen so far.
2.  **The Equation:** If the sum of elements from index $i$ to $j$ is $k$, then:
    $$\text{Sum}(i, j) = \text{PrefixSum}(j) - \text{PrefixSum}(i-1) = k$$
    This can be rearranged to find a previous prefix sum:
    $$\text{PrefixSum}(i-1) = \text{PrefixSum}(j) - k$$
3.  **Hash Map:** Since C does not have a native hash map, we implemented a custom **Hash Map using Chaining** (linked lists at each bucket) to handle collisions. This map stores the frequency of each prefix sum encountered. 
4.  **Single Pass:** For every new prefix sum calculated, we check the map to see how many times $(\text{current\_total} - k)$ has occurred previously. We add that frequency to our count and then update the map with the current total.



---

## 4. Time and Space Complexity

| Metric | Complexity | Reasoning |
| :--- | :--- | :--- |
| **Time Complexity** | $O(n)$ | We iterate through the array once. Hash map operations (insert/get) are $O(1)$ on average. |
| **Space Complexity** | $O(n)$ | In the worst case, we store every unique prefix sum in the hash map. |

---

## 5. How to Compile and Run

### Prerequisites
* A C compiler (e.g., `gcc` or `clang`).
* A test runner file (e.g., `main.c`) that includes the provided solution.

### Compilation
Open your terminal and run the following command to compile the project:

```bash
gcc -Wall -o subarray_solver solution.c
