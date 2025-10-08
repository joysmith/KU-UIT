# Implementing symmetric and asymmetric encryption on stored data

- [Python interpreter](https://python.org)
- [Pycharm IDE](https://www.jetbrains.com/pycharm/)
- [pycryptodome documentation](https://www.pycryptodome.org/)

### Data Encryption Standard (DES)- symmetric

1. Create new project,
1. Create new python file name it "DES"
1. Go to package manager search "pycryptodome" and install
   or

```sh
# use terminal to install
pip install pycryptodome
```

1. Copy code in python file

#### 1 version without comment

```py
from Crypto.Cipher import DES
from Crypto.Util.Padding import pad
from Crypto.Util.Padding import unpad
from Crypto.Random import get_random_bytes

# Encryption
key = b'mysecret'
key2 = get_random_bytes(8)
print("my Key")
print(key2)

cipher = DES.new(key, DES.MODE_CBC)
print(cipher.iv)
print(DES.block_size)

plain = b'This is my message'
print(pad(plain, DES.block_size))

ciphertext = cipher.encrypt(pad(plain, DES.block_size))
print(ciphertext)
iv = cipher.iv

print("--------------------------------------------------------------------")

decrypt_cipher = DES.new(key, DES.MODE_CBC, iv)
original_test = unpad(decrypt_cipher.decrypt(ciphertext), DES.block_size)

print(original_test.decode())
```

#### 2 version with comment

```py
from Crypto.Cipher import DES  # We bring in a special tool that can lock and unlock secret messages
from Crypto.Util.Padding import pad  # This helps us make the message the right size for locking
from Crypto.Util.Padding import unpad  # This helps us fix the message size after unlocking
from Crypto.Random import get_random_bytes  # This makes random secret keys like magic passwords

# Encryption (This part is about locking the message so no one else can read it)
key = b'mysecret'  # This is the secret key (like a password) we are using to lock the message
key2 = get_random_bytes(8)  # This makes a random secret key that is 8 bytes long(64 bit)
print("my Key")  # Just prints the words "my Key"
print(key2)  # Shows the random key so we can see what it looks like

cipher = DES.new(key, DES.MODE_CBC)  # This creates a lock using the key and a method called CBC
print(cipher.iv)  # Shows the initial vector (called IV) used to help lock the message
print(DES.block_size)  # Shows the size of message blocks DES works with (usually 8)

plain = b'This is my message'  # This is the message we want to keep secret
print(pad(plain, DES.block_size))  # This adds extra stuff to make the message the right size for locking

ciphertext = cipher.encrypt(pad(plain, DES.block_size))  # This locks (encrypts) the message using our secret key
print(ciphertext)  # Shows the locked (encrypted) message — it looks like random numbers and letters!
iv = cipher.iv  # Saves the IV so we can use it later to unlock the message

print("--------------------------------------------------------------------")  # Prints a line to separate the parts

# Decryption (This part is about unlocking the message so we can read it again)
decrypt_cipher = DES.new(key, DES.MODE_CBC, iv)  # Creates a new unlocker using the same key and IV
original_test = unpad(decrypt_cipher.decrypt(ciphertext), DES.block_size)  # Unlocks the message and removes extra padding

print(original_test.decode())  # Shows the original message in normal text so we can read it

```

<br>
<br>

### RSA (Rivest-Shamir-Adleman)(RSA)- asymmetric

<img src="../RSA-Encryption-Works.png" width="700">

[Theory](https://github.com/joysmith/KU-UIT/blob/main/Advance%20Database%20and%20Security/assets/ppt/rsa.pdf)

1. Create new project,
1. Create new python file name it "rsa"
1. Copy code in python file

```py

import random
from math import floor
from math import sqrt

RANDOM_START = 1e3
RANDOM_END = 1e5


def is_prime(num):
    # numbers smaller than 2 can not be primes
    if num < 2:
        return False

    # this is the only even prime number
    if num == 2:
        return True

    # even numbers can not be primes
    if num % 2 == 0:
        return False

    # we have already checked numbers < 3
    # finding primes up to N we just have to check numbers up to sqrt(N)
    # increment by 2 because we have already considered even numbers
    for i in range(3, floor(sqrt(num))):
        if num % i == 0:
            return False

    return True


# Euclid's greatest common divisor algorithm: this is how we can verify
# whether (e,phi) are coprime ... with the gcd(e,phi)=1 condition
def gcd(a, b):

    while b != 0:
        a, b = b, a % b

    return a


# extended Euclid's algorithm to find modular inverse in O(log m) so in linear time
# this is how we can find the d value which is the modular inverse of e in the RSA cryptosystem
def modular_inverse(a, b):

    # of course because gcd(0,b)=b and a*x+b*y=b - so x=0 and y=1
    if a == 0:
        return b, 0, 1

    # so we use the Euclidean algorithm for gcd()
    # b%a is always the smaller number - and 'a' is the smaller integer always in this implementation
    div, x1, y1 = modular_inverse(b % a, a)

    # and we update the parameters for x, y accordingly
    x = y1 - (b // a) * x1
    y = x1

    # we use recursion so this is how we send the result to the previous stack frame
    return div, x, y


def generate_large_prime(start=RANDOM_START, end=RANDOM_END):
    # generate a random number [RANDOM_START,RANDOM_END]
    num = random.randint(start, end)

    # and check whether it is prime or not
    while not is_prime(num):
        num = random.randint(start, end)

    # we know the number is prime
    return num


def generate_rsa_keys():
    # generate the first huge random prime number
    p = generate_large_prime()
    # generate the second huge random prime number
    q = generate_large_prime()

    # this is the trapdoor function: multiplying is fast but getting p and q
    # from n is an exponentially slow operation
    n = p * q

    # Euler's totient phi function
    phi = (p-1)*(q-1)

    e = random.randrange(1, phi)

    # we must make sure gcd(e,phi)=1 so e and phi are coprime
    # otherwise we cannot find d
    while gcd(e, phi) != 1:
        e = random.randrange(1, phi)

    # d is the modular inverse of e
    d = modular_inverse(e, phi)[1]

    # private key and the public key
    return (d, n), (e, n)


# encrypt messages: we use public keys for encryption
def encrypt(public_key, plain_text):
    # e and n are needed for encryption (these are public!!!)
    e, n = public_key

    # we use ASCII representations for the characters and the transformation
    # of every character is stored in an array
    cipher_text = []

    # consider all the letters one by one and use modular exponentiation
    for char in plain_text:
        a = ord(char)
        cipher_text.append(pow(a, e, n))

    return cipher_text


# decrypt messages: we use private keys for decryption
def decrypt(private_key, cipher_text):
    # d and n are needed for decryption (these are private!!!)
    d, n = private_key

    plain_text = ''

    for num in cipher_text:
        a = pow(num, d, n)
        plain_text = plain_text + str(chr(a))

    return plain_text

```

4. create another file "main.py"

```py
from rsa import *

if __name__ == '__main__':

    private_key, public_key = generate_rsa_keys()

    message = 'This is an example message with RSA algorithm!'
    print("Original message: %s" % message)
    cipher = encrypt(public_key, message)
    print("Cipher text: %s" % cipher)
    plain = decrypt(private_key, cipher)
    print("Decrypted text: %s" % plain)

```
