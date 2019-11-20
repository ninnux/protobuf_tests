#! /usr/bin/python

import array_pb2
import sys

# Iterates though all people in the AddressBook and prints info about them.
def ListEntries(array):
  for myset in array.sets:
   print("Timestamp:", myset.timestamp)
   for entry in myset.entries:
     print("  key:", entry.key)
     print("  value:", entry.value)

# Main procedure:  Reads the entire address book from a file and prints all
#   the information inside.
if len(sys.argv) != 2:
  print("Usage:", sys.argv[0], "ADDRESS_BOOK_FILE")
  sys.exit(-1)

array = array_pb2.array()

# Read the existing address book.
f = open(sys.argv[1], "rb")
array.ParseFromString(f.read())
f.close()

ListEntries(array)
