# Secure data transmission with hashed values

- [Python interpreter](https://python.org)
- [Pycharm IDE](https://www.jetbrains.com/pycharm/)
- [hashlib documentation](https://realpython.com/ref/stdlib/hashlib/)

### Data Encryption Standard (DES)- symmetric

1. Create new project,
1. Create new python file name it "MD5"
1. Go to package manager search "hashlib" and install
   or

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

<br>
<br>

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