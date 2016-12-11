Flat profile:

Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  Ts/call  Ts/call  name    
 86.36      2.16     2.16                             quickSort
 13.46      2.50     0.34                             newArray
  0.40      2.51     0.01                             insertionSort

			Call graph


granularity: each sample hit covers 2 byte(s) for 0.40% of 2.51 seconds

index % time    self  children    called     name
                             2160801             quickSort [1]
[1]     86.2    2.16    0.00       0+2160801 quickSort [1]
                             2160801             quickSort [1]
-----------------------------------------------
                                                 <spontaneous>
[2]     13.4    0.34    0.00                 newArray [2]
-----------------------------------------------
                                                 <spontaneous>
[3]      0.4    0.01    0.00                 insertionSort [3]
-----------------------------------------------

Index by function name

   [3] insertionSort           [2] newArray                [1] quickSort
