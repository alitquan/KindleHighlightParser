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

## Approach 1 -- We are Going With This One
- simple nested arraylist structure
- example
    - ArrayList Struct Main
        -  Title #1 ArrayList -- entry 1, entry 2, entry 3
        -  Title #2 ArrayList -- entry 1, entry 2, entry 3

### DataStructure Workflow
TODO
1. extract.cpp serves as the driver file
2. it instantiates a kLot.cpp if it doesn't exist already
    - make a way for kLot.cpp to persist 
2. it instantiates a kList.cpp if it doesn't exist for a given title
    - kLot should have a method to locate the kList that has a given title 
    - kLot should create the kList if it doesn't have one
    - kLot should save its state


## Approach 2 
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

# Overall Flow
1. Controller node parses the highlights.
    - stores vectors
        - vector 1
            - each element is a string
            - each string is a book title
            - make it alphabetical and implement binary search
        - vector 2 
            - each element is a vector of ints
            - the index of each element refers to the 


# 09-26-26
## TODO
Use time trim util function in node.
Create a linux style counter variable for the date. Update node cpp using that 
Create a list using entries from the book
Store kLists in a lot object 

# 10-18-26
## Done Today  
### Index Util Function Created 
- index is being used -- combined values of mdy and hh:mm timestamps
- mdy index does not utilize mins and hrs. 
- mdy might be useful for computing other data and easily aggregate values 

#### Original Output -- Uses **mdy-index** 
0  ==========
TITLE :﻿CCNP and CCIE Enterprise Core ENCOR 350-401
META:- Your Highlight on page 84-84 | Added on Monday, September 15, 2025 8:25:37 PM
META -- Note Type: Highlight
84-84
META -- DETECTED PAGE NUMBER         : 84-84
META -- DETECTED DATE        : Monday, September 15, 2025 8:25:37 PM
META -- AM/PM :  PM
META -- HMS   :  8:25:37 PM
rmDayFromDate Base:Monday, September 15, 2025 8:25:37 PM
This is removed: September 15, 2025 8:25:37 PM
CALCULATED -- TIMESTAMP: September 15, 2025 8:25:37 PM
CALCULATED -- TIMESTAMP INDEX: 5780160
BODY:MST Configuration MST is configured using the following process
BODY:This is a test. I will love you.
BODY:Stay away from me.
6 -- Line Detected --
6  ==========
TITLE :﻿CCNP and CCIE Enterprise Core ENCOR 350-401
META:- Your Note on page 84 | Added on Monday, September 15, 2025 8:25:58 PM
META -- Note Type: Note
84
META -- DETECTED PAGE NUMBER         : 84
META -- DETECTED DATE        : Monday, September 15, 2025 8:25:58 PM
META -- AM/PM :  PM
META -- HMS   :  8:25:58 PM
rmDayFromDate Base:Monday, September 15, 2025 8:25:58 PM
This is removed: September 15, 2025 8:25:58 PM
CALCULATED -- TIMESTAMP: September 15, 2025 8:25:58 PM
CALCULATED -- TIMESTAMP INDEX: 5780160
BODY:Copy and understand
BODY:This is a test. I will fight you.
BODY:How are you?
6 -- Line Detected --
6  ==========

#### New Output -- Output uses **index**

0  ==========
TITLE :﻿CCNP and CCIE Enterprise Core ENCOR 350-401
META:- Your Highlight on page 84-84 | Added on Monday, September 15, 2025 8:25:37 PM
META -- Note Type: Highlight
84-84
META -- DETECTED PAGE NUMBER         : 84-84
META -- DETECTED DATE        : Monday, September 15, 2025 8:25:37 PM
META -- AM/PM :  PM
META -- HMS   :  8:25:37 PM
rmDayFromDate Base:Monday, September 15, 2025 8:25:37 PM
This is removed: September 15, 2025 8:25:37 PM
kUtil -- PM detected
CALCULATED -- TIMESTAMP: September 15, 2025 8:25:37 PM
CALCULATED -- TIMESTAMP INDEX: 5863417
BODY:MST Configuration MST is configured using the following process
BODY:This is a test. I will love you.
BODY:Stay away from me.
6 -- Line Detected --
6  ==========
TITLE :﻿CCNP and CCIE Enterprise Core ENCOR 350-401
META:- Your Note on page 84 | Added on Monday, September 15, 2025 8:25:58 PM
META -- Note Type: Note
84
META -- DETECTED PAGE NUMBER         : 84
META -- DETECTED DATE        : Monday, September 15, 2025 8:25:58 PM
META -- AM/PM :  PM
META -- HMS   :  8:25:58 PM
rmDayFromDate Base:Monday, September 15, 2025 8:25:58 PM
This is removed: September 15, 2025 8:25:58 PM
kUtil -- PM detected
CALCULATED -- TIMESTAMP: September 15, 2025 8:25:58 PM
CALCULATED -- TIMESTAMP INDEX: 5863438
BODY:Copy and understand
BODY:This is a test. I will fight you.
BODY:How are you?
6 -- Line Detected --
6  ==========

# 10-19-26 
## Progress 
### Finished destructor cascade: kLot->kList->kNode 
### Instantiated kLot inside the driver file 
### Fixed up pointer/reference issues with the linked list 

## TODO 
### Need to test out kList traversal? 
### Maybe might need to make kNodes doubly-linked? 
### Fix the node getAll() methods -- it looks like the body is not coming 




