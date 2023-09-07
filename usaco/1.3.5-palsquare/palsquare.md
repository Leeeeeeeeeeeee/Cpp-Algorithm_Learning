Palindromic Squares(平方)
Rob Kolstad
Palindromes are numbers that read the same forwards as backwards. The number 12321 is a typical palindrome.

Given a number base B（B进制） (2 <= B <= 20 base 10), print all the integers N (1 <= N <= 300 base 10) such that the square of N is palindromic when expressed in base B; also print the value of that palindromic square. Use the letters 'A', 'B', and so on to represent the digits 10, 11, and so on.

Print both the number and its square in base B.

1.给定一个进制 B，该进制在2到20之间（以10进制表示）。
2.整数 N 的取值范围在1到300之间（以10进制表示）。
3.要求找出这些整数 N（不要求是回文），使得 N 的平方在给定的进制 B 下是回文数（palindrome），即从左往右读和从右往左读是相同的数字序列。
4.最后，你需要以进制 B 的形式打印出这些整数 N 和它们的平方值。
5.例如，如果 B 是10（十进制），则你需要找到那些整数 N，它们的平方是回文数。如果 B 是16（十六进制），则你需要找到那些整数 N，它们的平方在十六进制下是回文数，且将10表示为'A'，11表示为'B'，以此类推。
PROGRAM NAME: palsquare

INPUT FORMAT
A single line with B, the base (specified in base 10).
SAMPLE INPUT (file palsquare.in)
10

OUTPUT FORMAT
Lines with two integers represented in base B. The first integer is the number whose square is palindromic; the second integer is the square itself. NOTE WELL THAT BOTH INTEGERS ARE IN BASE B!
SAMPLE OUTPUT (file palsquare.out)
1 1
2 4
3 9
11 121
22 484
26 676
101 10201
111 12321
121 14641
202 40804
212 44944
264 69696