# Intro to Cryptography
# Kade, Pitsch(t12r458)
# kadecarter82@gmail.com
# CSCI 476

# 03/28/2021



# Task 1: Reflection

## What is Cryptography?
Is a way to keep information secure while sending it 
to a recipient. This can be used when sending letters, 
mails or when (hopefully) when you log into your bank 
account. The sender and the recipient just have to know 
how the information was encrypted. Once the recipient 
gets the message they use the same method that was used 
to encrypt it, this is known as decryption.

## What problems does it solve?
The main thing that this solves is that it lets you 
communicate with someone and no one else can (easily)see 
what you are saying to that other person. This
also is the method used to keep all your personal 
information safe such as social security numbers and bank information.
In the past it was used to have secret conversations
in the same way we take for granted now. If you sent a
letter in the past about something secret. It passes through
so many peoples hands that it could be opened by anyone and you
would be exposed. Cryptography is just a way to keep your
information safe.

## Issues designing and using cryptography?
I think the biggest issue in designing new cryptography is that
computers are getting more powerful and the ways to break
these ciphers are getting easier. Like the DES standard that
was broken sooner than expected. If a quantum computer ever 
got released then that would break all current encryption standards.
Things are also getting more advanced where people were able to
break the encryption by analyzing the power consumption of the
chip at certain times. Which i do not even understand how that
works.

## What are the big, important ideas in cryptography?
The most important idea of cryptography is that it is a keystone
in our current technology. If you want to do anything online you are
using cryptography. Think about online banking, shopping, taxes and many more things
this is all thanks to cryptography. The second being that our current standards
of cryptography are not going to be the standards we use forever. As things evolve 
cryptographic standards are going to have to get better too.

# Task 2: Substitution Ciphers & Freq. Analysis.
Writing a freq analysis script in python we get the dict output 

### `{'a': 0.02, 'b': 0.029, 'c': 0.018, 'd': 0.001, 'e': 0.058, 'f': 0.056, 'g': 0.001, 'h': 0.05, 'i': 0.032, 'j': 0.03, 'k': 0.008, 'l': 0.026, 'm': 0.015, 'n': 0.0, 'o': 0.014, 'p': 0.063, 'q': 0.01, 'r': 0.023, 's': 0.013, 't': 0.054, 'u': 0.101, 'v': 0.023, 'w': 0.001, 'x': 0.073, 'y': 0.073, 'z': 0.031}`

and it looks like 'u' is the most common occurrence in the tet so my assumption is that 
#### `u -> e`
going to swap those two letters in the text and see what we get. 
After just guessing and checking for a little bit i was able to find another pattern in the text.
#### `yb` and `ybu` showed up a lot all over the text so after finding that u mapped to e
it only made sense that y was mapped to t and b was mapped to h after finding that a lot more of the text came together.
#### finding that `zthqufehyhue -> universities` made a huge difference in completing the cipher. 
from here it was just ~30 minutes of brute force.
With the final mappings being

### `cipher = {'a':'P', 'b':'H', 'c':'F', 'd':'J', 'e':'S', 'f':'R', 'g':'Q', 'h':'I', 'i':'L', 'j':'C', 'k':'K', 'l':'D', 'm':'W', 'n':'T', 'o':'G', 'p':'A', 'q':'V','r': 'Y', 's':'B', 't':'N', 'u':'E', 'v':'M', 'w':'X', 'x':'O', 'y':'T', 'z':'U'}`

#### ---------------and an excerpt of the final text---------------

IN THE PAST FEW YEARS UNIVERSITIES LIKE EVERYONE ELSE HAVE BECOME INCREASINGLY
AWARE OF ONLINE THREATS CAMPUSES HAVE SEEN THEIR PAYROLL SYSTEMS COMPROMISED BY
 CRIMINALS WHO STEAL FACULTY AND STAFF PASSWORDS OFTEN BY MEANS OF PHISHING EMAILS
 AND THEN USE THOSE CREDENTIALS TO REDIRECT DIRECT DEPOSIT SALARY PAYMENTS
SEVERAL HAVE BEEN TARGETED BY RANSOMWARE ATTACKS INCLUDING JUST IN THE PAST MONTH
REGIS UNIVERSITY AND STEVENS INSTITUTE OF TECHNOLOGY SOME HAVE SEEN EMAIL ACCOUNTS
COMPROMISED AND USED TO SEND OUT THOSE PHISHING MESSAGES BECAUSE EMAILS
SENT FROM AUTHENTICATED ADDRESSES ENDING IN EDU ARE OFTEN ABLE TO EVADE SPAM FILTERS
THE RISK OF INTELLECTUAL PROPERTY THEFT LOOMS LARGE FOR SOME CAMPUSES AS
 DOES THE RISK OF SPIES OR CRIMINALS USING COMPROMISED SERVERS ON US CAMPUSES
AS HOP POINTS TO ROUT AN ATTACK DIRECTED AT ANOTHER TARGET LIKE A GOVERNMENT
AGENCY OR PRIVATE COMPANY


