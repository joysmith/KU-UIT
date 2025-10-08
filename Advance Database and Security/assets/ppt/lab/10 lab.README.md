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