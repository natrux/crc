#!/usr/bin/env python3

#Converts descriptions from https://reveng.sourceforge.io/crc-catalogue/ to code.
# Example: From
#   width=64 poly=0x42f0e1eba9ea3693 init=0x0000000000000000 refin=false refout=false xorout=0x0000000000000000 check=0x6c40df5f0b497347 residue=0x0000000000000000 name="CRC-64/ECMA-182"
# Creates
#  * a declaration file
#  * #include directive
#  * generate_table<> expression
#  * check<> expression

with open("todo", "r") as stream:
	text = stream.read()
lines = text.split("\n")

for line in lines:
	if len(line) == 0:
		continue

	d = {}
	for s in line.split(" "):
		(k, v) = s.split("=")
		d[k] = v.replace("\"", "")
	d["class_name"] = d["name"].replace("-", "_").replace("/", "_")
	d["lower_class_name"] = d["class_name"].lower()

	filename = "%s.h" % d["lower_class_name"]
	declaration = "using %s = CRC<%s, %s, %s, %s, %s, %s>;" %(d["class_name"], d["width"], d["poly"], d["refin"], d["refout"], d["init"], d["xorout"])


	#with open("declarations/%s" % filename, "w") as stream:
	#	stream.write(declaration)

	#print("#include \"%s\"" % filename)

	#print("generate_table<%s>(\"%s\");" % (d["class_name"], d["name"]))

	#print("check<%s>(%s);" % (d["class_name"], d["check"]))

