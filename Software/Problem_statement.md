# Robot Artifact Collection Problem

**Objective:**  
Find the minimum number of moves it would require the robot to collect all the artifacts given the map of the building.

These buildings aren't as straightforward as they seem. They have some special doors which can be unlocked only if you have the particular artifact required.

---

## Task Description

You are given a map with the following elements:

- `@` : Starting position of the robot  
- `#` : Wall (the robot cannot pass through walls)  
- `.` : Empty space  
- `a`, `d`, `g`, etc. : Artifacts (lowercase letters)  
- `A`, `D`, `G`, etc. : Doors (uppercase letters matching their corresponding artifacts)

**Rules:**

- To pass through a door (e.g., `A`), the robot must have collected the corresponding artifact (e.g., `a`)
- Moves are allowed in the **four cardinal directions only**: up, down, left, right
- No diagonal movements are allowed
- If the robot cannot collect all artifacts, return `-1`

**Constraints:**

- There will be **no more than 7 artifacts** in any given map
- For every artifact present, the corresponding door will also be present in the map

---

## Examples

### Example 1:

**Input Map:**
["@..a.",
"###.#",
"b.A.B"]


**Minimum number of moves required:** `8`

**Explanation:**
Start at `@`  
→ Move 3 steps right to get `'a'`  
→ Move back 1 step left  
→ Move 2 steps down  
→ Move 1 step left to pass through door `'A'`  
→ Move 1 step right to collect `'b'`  
**Total: 8 moves**

---
