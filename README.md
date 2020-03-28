# Demand-Paging
Operating System project on Demand-Paging

# K18FG_11810525_Roll.no(21)
```
 Consider a scenario of demand paged memory. Page table is held in registers. It takes 8 milliseconds to service a page fault
 if an empty page is available or the replaced page is not modified and 20 milliseconds if the replaced page is modified. 
 Memory access time is 100 nanoseconds. Assume that the page to be replaced is modified 70 percent of the time. 
 Generate a solution to find maximum acceptable page-fault rate for access time that is not more than 200 nanoseconds.
```

# Solution

```
Given,
Time taken to service a Page-Fault for Empty Page or Unmodified Replaced Page = 8ms.
Time taken to service a Page-Fault for Modified Replaced Page  = 20ms
Memory access time = 100ns
Percentage for the time,the page to be replaced is modified = 70%
percentage value=0.7
Effective Access time = 200ns


 
Here, we have to find page-fault rate('p') for given effective access time('EAT') so by using the following equation, solve for 'p':
(Note: 1 millisecond = 1,000,000 nanoseconds = 1e6 nanoseconds)
      
      EAT= (1-p)*(memory access time) + p*(1-percentage value)*(page fault service with no moddcation) + p*(percentage value)*(page fault service with moddcation)
      EAT = (1-p)*(100) + (p)*((1-0.7)*(8msec) + (0.7)*(20msec))   
	  = 100 - 100p + (2.4e6)*p + (14e6)*p
	  = 100 + (16.4e6)*p - 100p
      200 = 100 + (16.4e6)*p - 100p
      p =6.0975981560e-6 ~ 6.1e-6
      p-->page Fault Rate
 ```
