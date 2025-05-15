## Hashing Homework 
### 1. Define Hashing and Collision Resolution
- **Hashing**: A technique to convert keys into indices of a fixed-size table using a hash function.
- **Collision Resolution**: Methods used to handle cases where two keys hash to the same index.

---

### 2. What is a Hash Table and Why is Collision Resolution Necessary?
- A **hash table** is a data structure that maps keys to values using a hash function.
- **Collision resolution** is necessary because multiple keys may hash to the same index.

---

### 3. Key Differences Between Open Hashing and Closed Hashing

| Feature | Open Hashing (Chaining) | Closed Hashing (Open Addressing) |
|--------|--------------------------|----------------------------------|
| Storage | Linked list per slot | Uses table array only |
| Memory | Extra for pointers | No extra memory |
| Load Factor | Can exceed 1 | Must be ≤ 1 |
| Insertion | Easy, O(1) average | May require probing |
| Collision Handling | Lists in buckets | Search for empty slot |

---

### 4. Collision Resolution Techniques in Open Addressing

#### **Linear Probing**
- **How it works**: If collision occurs at one index try the next one, and the next one ... until you find an open slot
- **Pros**: Simple and fast.
- **Cons**: Leads to **primary clustering**.

#### **Quadratic Probing**
- **How it works**: Try `h(k) + i²` where `i` = 1, 2, ...
- **Pros**: Reduces primary clustering.
- **Cons**: Can still cause **secondary clustering** and may not probe all slots.

#### **Double Hashing**
- **How it works**: Use a second hash function to compute step size.
- **Pros**: Best dispersion, reduces clustering.
- **Cons**: more complex.

---

### 5. Which Technique Can Handle More Values Than Table Slots?
- **Open Hashing (Chaining)**: Can store more items than slots using linked lists.

---

### 6. Worst-Case Performance (Big O)

| Technique | Worst-Case Time |
|----------|------------------|
| Open Hashing | O(n) |
| Linear Probing | O(n) |
| Quadratic Probing | O(n) |
| Double Hashing | O(n) |

---

### 7. Impact of Hash Table Size

- A poor table size (like power of 2 or 10) may cause excessive collisions.
- **Prime number** sizes help distribute keys uniformly.

#### Pitfalls:
- Keys with patterns (e.g., multiples of 5) collide in tables sized as 10 or 100.
- Power-of-two sizes may align with binary patterns in the data.

---

## Part B: Simulation and Diagram Exercises

### Exercise 1: Open Hashing (Separate Chaining)

**Keys**: `5, 22, 17, 18, 35, 101, 16, 0, 8`  
**Hash function**: `h(k) = k % 10`

**Hash Table (with chaining):**

| Index | Linked List |
|-------|-------------|
| 0 | 0 |
| 1 | 101 |
| 2 | 22 |
| 3 | - |
| 4 | - |
| 5 | 5 → 35 |
| 6 | 16 |
| 7 | 17 |
| 8 | 18 → 8 |
| 9 | - |

**Collisions**:
- Index 5: 2 items (5, 35)
- Index 8: 2 items (18, 8)

---

### Exercise 2: Closed Hashing (Linear Probing)

**Keys**: `5, 22, 17, 18, 35, 101, 16, 0, 8`  
**Hash function**: `h(k) = k % 10`

**Insertions (Linear Probing):**

| Index | Key |
|-------|-----|
| 0 | 0 |
| 1 | 101 |
| 2 | 22 |
| 3 | 8 |
| 4 | - |
| 5 | 5 |
| 6 | 35 |
| 7 | 17 |
| 8 | 18 |
| 9 | 16 |

**Clustering**:
- Primary clustering is visible at positions 5 through 9.

---

### Exercise 3: Impact of Poor Table Sizes

**Keys**: `5, 10, 15, 20, 25, 30, 35, 40`

#### **Table Size = 10**

| Key | Hash | Final Index |
|-----|------|-------------|
| 5 | 5 | 5 |
| 10 | 0 | 0 |
| 15 | 5 (→ 6) | 6 |
| 20 | 0 (→ 1) | 1 |
| 25 | 5 (→ 6 → 7) | 7 |
| 30 | 0 (→ 1 → 2) | 2 |
| 35 | 5 (→ 6 → 7 → 8) | 8 |
| 40 | 0 (→ 1 → 2 → 3) | 3 |

- **Clustering observed** at 0-3 and 5-8.

#### **Table Size = 11 (prime)**

| Key | Hash (k % 11) | Index |
|-----|----------------|--------|
| 5 | 5 | 5 |
| 10 | 10 | 10 |
| 15 | 4 | 4 |
| 20 | 9 | 9 |
| 25 | 3 | 3 |
| 30 | 8 | 8 |
| 35 | 2 | 2 |
| 40 | 7 | 7 |

- **Very even distribution** — no clustering.

---

### Optional Extra Credit: Quadratic Probing

**Keys**: `12, 23, 34, 45, 56, 67, 78, 89`  
**Hash Function**: `h(k) = k % 10`  
**Table Size**: 10  
**Probing**: `h(k) + i²` for `i = 1, 2, ...`

| Key | Hash | Final Index |
|-----|------|-------------|
| 12 | 2 | 2 |
| 23 | 3 | 3 |
| 34 | 4 | 4 |
| 45 | 5 | 5 |
| 56 | 6 | 6 |
| 67 | 7 | 7 |
| 78 | 8 | 8 |
| 89 | 9 | 9 |

**Result**: All keys inserted without collision.

#### Benefits of Quadratic Probing:
- Reduces primary clustering.
- Spreads keys out better than linear probing.
- May still fail to find empty slots if table size is not suitable.
