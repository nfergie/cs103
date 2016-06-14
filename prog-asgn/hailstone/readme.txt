CSCI 103 Programming Assignment 1, Hailstone, Spring 2015

Name: Nicole Fergie	

Email Address: fergiem@usc.edu

NOTE: You can delete the questions, we only need your responses.

NOTE: It is helpful if you write at most 80 characters per line,
and avoid including special characters, so we can read your responses.

Please summarize the help you found useful for this assignment, which
may include office hours, discussion with peers, tutors, et cetera.
Saying "a CP on Tuesday" is ok if you don't remember their name.
If none, say "none".

: none

================================ Questions ==================================

1. Which kind of a loop did you use for the first program? Why?

: I used a while loop for the first program because I wanted the loop to repeat
until I reached a certain number.

2a. Once you've completed the second program, run hailstats on the following
inputs, and record your results in the table below:

  input range  | minimum length | achieved by | maximum length | achieved by
-----------------------------------------------------------------------------
    50 100     |        6       |       64    |      118       |        97   
   100 200     |         7      |     128     |      124       |       171   
   200 400     |         8      |      256    |      143       |      327    

2b. What pattern do you think there is in the values achieving minimum length?
Can you explain why it holds?

:The values are all powers of 2. This holds because we are constantly 
dividing by two because the number will be even because it is a power of two.

3a. Let X be the smallest integer whose length is greater than 150.
By running your hailstats program several times on carefully chosen inputs,
determine what is the value of X.

X is : 703

3b. Explain, briefly, the way in which you used your hailstats program
(i.e., which inputs you gave it) to find this answer.

:I ran hailstats on intervals of 100. 400 to 500, 500 to 600, and 600 to 700.
Then I realised I was quite close and ran 700 to 750. The output was the maximum
length was 170 achieved by 703. At this point I ran it on 700 to 702 and the
maximum length was less than 150. Therefore I gathered that the smallest integer
whose length is greater than 150 is 703.

================================ Remarks ====================================

Filling in anything here is OPTIONAL.

Approximately how long did you spend on this assignment?

:

Were there any specific problems you encountered? This is especially useful to
know if you turned it in incomplete.

:

Do you have any other remarks?

:
