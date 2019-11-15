#! /usr/bin/python3

import array_pb2
import sys
import time

# Main procedure:  Reads the entire address book from a file,
#   adds one person based on user input, then writes it back out to the same
#   file.
if len(sys.argv) != 2:
  print("Usage:", sys.argv[0], "ADDRESS_BOOK_FILE")
  sys.exit(-1)
array = array_pb2.array()
# Read the existing address book.
try:
  f = open(sys.argv[1], "rb")
  array.ParseFromString(f.read())
  f.close()
except IOError:
  print(sys.argv[1] + ": Could not open file.  Creating a new one.")

myset=array.sets.add()
myset.timestamp = int(time.time())
# Add an address.
while True:
  key = input("Enter a key (or leave blank to finish): ")
  print(key)
  if key == "":
    break
  entry=myset.entries.add()
  entry.key=key
  value = input("Enter a value: ")
  entry.value=int(value)

# Write the new address book back to disk.
f = open(sys.argv[1], "wb")
f.write(array.SerializeToString())
f.close()
