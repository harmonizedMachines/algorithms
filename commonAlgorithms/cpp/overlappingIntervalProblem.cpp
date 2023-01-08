int count = 0; // Global parameters that are useful for results.
int minEnd = INT_MAX; // Key parameters characterizing the "active set" for overlapping intervals, e.g. the minimum ending point among all overlapping intervals.
sort(points.begin(), points.end()); // Sorting the intervals/pairs in ascending order of its starting point
for each interval {
      if(interval.start > minEnd) { // If the 
	 // changing some states, record some information, and start a new active set. 
	count++;
	minEnd = p.second;
      }
     else {
	// renew key parameters of the active set
	minEnd = min(minEnd, p.second);
      } 
 }
return the result recorded in or calculated from the global information;