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

key = b'mysecret'
key2 = get_random_bytes(8)
print(key2)

cipher = DES.new(key, DES.MODE_CBC)
print(cipher.iv)
print(DES.block_size)

plain = b'This is my message'
print(pad(plain, DES.block_size))

ciphertext = cipher.encrypt(pad(plain, DES.block_size))
iv = cipher.iv

decrypt_cipher = DES.new(key, DES.MODE_CBC, iv)
original_test = unpad(decrypt_cipher.decrypt(ciphertext), DES.block_size)

print(original_test.decode())
```

#### 2 version with comment
```py
from Crypto.Cipher import DES  # Brings in a tool to lock (encrypt) and unlock (decrypt) messages using DES
from Crypto.Util.Padding import pad  # Helps make messages the right size to lock
from Crypto.Util.Padding import unpad  # Helps fix the message size after unlocking
from Crypto.Random import get_random_bytes  # Helps make a random key (like a secret password)

key = b'mysecret'  # This is our secret password (key) for locking the message
key2 = get_random_bytes(8)  # This makes a random 8-byte secret key
print(key2)  # Shows the random key on the screen

cipher = DES.new(key, DES.MODE_CBC)  # Makes a lock using our key and a special method called CBC
print(cipher.iv)  # Shows the special starting piece (called IV) used in the lock
print(DES.block_size)  # Shows the size of message blocks that DES uses

plain = b'This is my message'  # This is the message we want to keep secret
print(pad(plain, DES.block_size))  # Makes the message the right size to lock by adding padding

ciphertext = cipher.encrypt(pad(plain, DES.block_size))  # Locks (encrypts) the message using our key
iv = cipher.iv  # Saves the special starting piece (IV) for later unlocking

decrypt_cipher = DES.new(key, DES.MODE_CBC, iv)  # Makes a new unlocker using the same key and IV
original_test = unpad(decrypt_cipher.decrypt(ciphertext), DES.block_size)  # Unlocks the message and removes the padding

print(original_test.decode())  # Shows the unlocked message as normal text
```