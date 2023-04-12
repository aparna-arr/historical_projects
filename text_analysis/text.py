import sys
import io
import argparse

#print("hello world")
parser = argparse.ArgumentParser()
parser.add_argument("in", help="input text file")
parser.add_argument("out", help="output file basename")
parser.parse_args()


