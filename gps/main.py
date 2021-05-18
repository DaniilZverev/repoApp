import json
from code import *

with open("taps.json", "r") as read_file:
	taps = json.load(read_file)
	generate_code(1, taps)