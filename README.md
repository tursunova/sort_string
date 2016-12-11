Flat  profile:



Each sample counts as 0.01 seconds.

 no time accumulated



   time | cumulative seconds | self seconds | calls | self Ts/call | total Ts/call | name 
------ | ------ | ------ | ------ | ------ | ------ | ------ 
 0.00 |  0.00 |  0.00 |  14 |  0.00 |  0.00 |  insertionSort 
 0.00 |  0.00 |  0.00 |  1 |  0.00 |  0.00 |  merge 


Call graph





granularity: each sample hit covers 2 byte(s) no time propagated


 index | % time | self | children | called | name 0.00 
------ | ------ | ------ | ------ | ------ | ------ 
 |  |  |  0.00 |  14/14 |  merge  [2]
 [1] |  0.0 |  0.00 |  0.00 |  14 |  insertionSort  [1]
 |  |  |  |  10 |  merge  [2]
 |  |  0.00 |  0.00 |  1/1 |  _fini  [18]
 [2] |  0.0 |  0.00 |  0.00 |  1+10 |  merge  [2]
 |  |  0.00 |  0.00 |  14/14 |  insertionSort  [1]
 |  |  |  |  10 |  merge  [2]

