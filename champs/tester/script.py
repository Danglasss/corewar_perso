import os

RED = "\033[31m"
GREEN = "\033[32m"
RESET = "\033[37m"

success = 0
succes_file = 0
list_file = os.listdir('.')

for i in range(len(list_file)):
	total = 0
	success_file = 0
	for j in range(len(list_file)):
		if list_file[i] != "script.py" and list_file[j] != "script.py":
			os.system('gtimeout 10 ../../bin/corewar {} {} > ../zaz'.format(list_file[i], list_file[j]))
			os.system('gtimeout 10 ../../virtual_machine/corewar {} {} > ../our'.format(list_file[i], list_file[j]))
			os.system('diff ../zaz ../our > ../diff')
			if (os.stat("../diff").st_size == 0):
				success_file += 1
			else:
				print(RED + "[ {} ] [ {} ]".format(list_file[i], list_file[j]) + RESET)
			total += 1
	success += success_file
	print(GREEN + "[ {} / {} ] [ {} ]".format(success_file, total, list_file[i]) + RESET)

print("{} / {}".format(success, total * total))