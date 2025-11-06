# Sample
```txt
==========
﻿CCNP and CCIE Enterprise Core ENCOR 350-401  
- Your Highlight on page 84-84 | Added on Monday, September 15, 2025 8:25:37 PM

MST Configuration MST is configured using the following process
==========
﻿CCNP and CCIE Enterprise Core ENCOR 350-401  
- Your Note on page 84 | Added on Monday, September 15, 2025 8:25:58 PM

Copy and understand
==========
```

# Parse Headers
- use ========== as seperator 
-tuse the 1st line after to get the title
    - store the title if it already appears
        1. search 
            - types of approaches
                - sequential read through an ArrayList
                - binary search through an ArrayList 
                - search via hashmap
        2. store it in order 
- use the 2nd line to extract:
    - the page number
    - the date of access 
- create a hash from the 2nd line to store as a prefix 
- 3rd line is space 
- line after space -- use as body 


# Organizing the Sources
- iterate through title offsets and store the line numbers where each entry can be parsed
- create a seperate method that builds seperate text files based on the vectors that have entries stored 
- example:
    - vectors: 
        - source 1 entry lines: 0,14,20,23,31,45
        - source 2 entry lines: 3,17,26,39 
    - thread: 
        - thread 1 goes to each entry line and synthesizes until line break for source 1
            - writes to text file built around source 1
        - thread 2 goes to each entry line and synthesizes until line break for source 2 
            - writes to text file built around source 2





