The algorithm implemented in `Math_GregCalendar.cpp` is designed to calculate the day of the year for a given date in the Gregorian calendar.

**Goal of Algorithm:**
The main goal of the algorithm is to determine the numerical day of the year given a specific date. For example, "2019-01-01" would return 1, "2019-02-01" would return 32, and so on.

**Input:**
The function `dayOfYear` takes a string `date` as input, which is a date represented in the "YYYY-MM-DD" format.

**Output:**
The function returns an integer representing the numerical day of the year for the provided date.

**Algorithm Steps:**

1. **Extract Year, Month, and Day:** The algorithm first extracts the year, month, and day from the input date string.

2. **Leap Year Check:** It then checks if the extracted year is a leap year. A year is considered a leap year if it is divisible by 4, but not divisible by 100, unless it is also divisible by 400. If the year is a leap year, February has 29 days. Otherwise, February has 28 days.

3. **Prepare Month Length Map:** The algorithm prepares a map `monLen` that stores the number of days in each month. It uses two vectors `Day_31` and `Day_30` that store the month numbers (1 to 12) for months having 31 and 30 days respectively. The values for February are set based on whether the year is a leap year or not.

4. **Calculate Day of Year:** The algorithm then calculates the sum of the days of all the months before the month of the given date, and adds the day of the month to that sum. This is the numerical day of the year, which is returned as the result.

**Time Complexity:** The time complexity of the algorithm is O(1), as the number of operations does not depend on the size of the input.

**Space Complexity:** The space complexity is also O(1), as only a fixed amount of space is needed to store the variables and the month length map.

For example, given the input date "2019-02-10", the algorithm will return 41, as February 10th is the 41st day of the year 2019, which is not a leap year.
