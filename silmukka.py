#!/usr/bin/env python3


import sys


def main():
	"""."""
	try:
		while True:
			t = str(input("Jatketaanko, K/e? "))
			if t == "E" or t == "e":
				print("Lopetetaan...")
				sys.exit(0)
			else:
				print("Jatketaan...")
	except KeyboardInterrupt:
		print("Ohjelma keskeytettiin.")
		sys.exit(1)


if __name__ == "__main__":
	main()
