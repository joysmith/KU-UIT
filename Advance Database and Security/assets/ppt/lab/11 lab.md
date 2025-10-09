# Secure data transmission with hashed values

- [Theory](https://github.com/joysmith/KU-UIT/blob/main/Advance%20Database%20and%20Security/assets/ppt/Hashing.pdf)
- [Python interpreter](https://python.org)
- [Pycharm IDE](https://www.jetbrains.com/pycharm/)
- [hashlib documentation](https://realpython.com/ref/stdlib/hashlib/)

### MD5

1. Create new project,
1. Create new python file name it "MD5"
1. Go to package manager search "hashlib" and install or

```sh
# use terminal to install
pip install phashlib
```

1. copy code to MD5

```py
# message digest 5 (Rivest back in 1991)
# 128 bits long sequence (hash or the message digest)
# this approach is not collision free !!!
from hashlib import md5

s = 'This is a message!'

result = md5(s.encode())
# 32 hexadecimal characters -
# nibbles (we can store a hexadecimal character on 4 bits - 0.5 byte)
print(result.hexdigest())

```

#### MD5 with comment

```py
# message digest 5 (MD5) is a special tool made by a person named Rivest in 1991
# It turns messages into secret codes that are 128 bits long
# But it's not super safe — sometimes two messages can get the same code (called a collision)

from hashlib import md5  # This brings in the md5 tool from Python's hashlib toolbox.
                         # It helps us turn a message into a special secret code (called a hash).

s = 'This is a message!'  # We create a message and store it in s.

result = md5(s.encode())  # We change the message into computer code using .encode()
                          # Then we use md5 to turn it into a secret code and save it in result.

# The final code will be 32 characters long.
# These are hexadecimal characters (letters and numbers).
# Each character takes up 4 bits (which is half of a byte — also called a nibble!)

print(result.hexdigest())  # This shows the secret code on the screen in a way that's easy to read.

```

<br>
<br>

#### SHA256 without comment

1. Create new project,
1. Create new python file name it "SHA256"

```py
from hashlib import sha256

# output is a 256 bits long sequence (message digest)
# this is the hash Bitcoin uses
# result is a 64 character long hexadecimal sequence
# 1 hexadecimal character can be stored on 4 bits

s1 = 'Hello world!'
s2 = 'Hello world'

result1 = sha256(s1.encode())
result2 = sha256(s2.encode())

print(result1.hexdigest())
print(result2.hexdigest())
```

#### SHA256 with comment

```py
from hashlib import sha256  # This brings in a special tool called sha256 from the hashlib toolbox.
                            # It helps turn words into secret codes called hashes.
                            # The hash it makes is 256 bits long — that's like a long string of 1s and 0s.
                            # Bitcoin (a type of digital money) uses this kind of hash.
                            # The result will look like a 64-character code made of numbers and letters.
                            # Each of those characters uses 4 tiny pieces called bits.

s1 = 'Hello world!'         # We make a message called s1. It says: "Hello world!" (with an exclamation mark).

s2 = 'Hello world'          # We make another message called s2. It says: "Hello world" (without the exclamation mark).

result1 = sha256(s1.encode())  # We change s1 into a hash using sha256.
                               # First, .encode() turns the message into computer language.
                               # Then sha256 makes a secret code from it and saves it in result1.

result2 = sha256(s2.encode())  # We do the same thing for s2. The code is saved in result2.

print(result1.hexdigest())     # We show the secret code from result1.
                               # .hexdigest() makes it easier to read — just letters and numbers.

print(result2.hexdigest())     # We show the secret code from result2.

```

<br>
<br>

### SHA512

```py
from hashlib import sha512

# output is a 512 bits long sequence (message digest)
# this is the hash Bitcoin uses
# result is a 128 character long hexadecimal sequence
# 1 hexadecimal character can be stored on 4 bits
# 2^512 = the number of possible hashes
# because of the birthday paradox - 2^256

s1 = 'Hello world!'
s2 = 'Hello world'

result1 = sha512(s1.encode())
result2 = sha512(s2.encode())

print(result1.hexdigest())
print(result2.hexdigest())
```
