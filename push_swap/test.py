import subprocess
from itertools import permutations

# https://www.random.org/integer-sets/?sets=5&num=18&min=0&max=17&seqnos=on&order=index&format=html&rnd=new

CHECK_LEAKS = True

advanced_tests = {
	"args": [
		(["./push_swap"], "", ""),
		(["./push_swap", "0"], "", ""),
		(["./push_swap", "1"], "", ""),
		(["./push_swap", "-1"], "", ""),
		(["./push_swap", "9"], "", ""),
		(["./push_swap", "-9"], "", ""),
		(["./push_swap", "10"], "", ""),
		(["./push_swap", "-10"], "", ""),
		(["./push_swap", "-1147483649"], "", ""),
		(["./push_swap", "-2147473649"], "", ""),
		(["./push_swap", "-2147483647"], "", ""),
		(["./push_swap", "-2147483648"], "", ""),
		(["./push_swap", "1147483648"], "", ""),
		(["./push_swap", "2147473648"], "", ""),
		(["./push_swap", "2147483646"], "", ""),
		(["./push_swap", "2147483647"], "", ""),
		(["./push_swap", "-2147483649"], "", "Error\n"),
		(["./push_swap", "-2147483650"], "", "Error\n"),
		(["./push_swap", "-2148483648"], "", "Error\n"),
		(["./push_swap", "-3147483648"], "", "Error\n"),
		(["./push_swap", "2147483648"], "", "Error\n"),
		(["./push_swap", "2147483649"], "", "Error\n"),
		(["./push_swap", "2148483648"], "", "Error\n"),
		(["./push_swap", "3147483648"], "", "Error\n"),
		(["./push_swap", "a"], "", "Error\n"),
		(["./push_swap", "7a"], "", "Error\n"),
		(["./push_swap", "a7"], "", "Error\n"),
		(["./push_swap", "a7a"], "", "Error\n"),
		(["./push_swap", "7aaa"], "", "Error\n"),
		(["./push_swap", "aaa7"], "", "Error\n"),
		(["./push_swap", "aaa7aaa"], "", "Error\n"),
		(["./push_swap", "12a"], "", "Error\n"),
		(["./push_swap", "a12"], "", "Error\n"),
		(["./push_swap", "a12a"], "", "Error\n"),
		(["./push_swap", "aaaa12"], "", "Error\n"),
		(["./push_swap", "12aaaa"], "", "Error\n"),
		(["./push_swap", "aaaa12aaaa"], "", "Error\n"),
		(["./push_swap", "12 1 3 a"], "", "Error\n"),
		(["./push_swap", "12 a 1"], "", "Error\n"),
		(["./push_swap", "12 a"], "", "Error\n"),
		(["./push_swap", "-a"], "", "Error\n"),
		(["./push_swap", "-7a"], "", "Error\n"),
		(["./push_swap", "-a7"], "", "Error\n"),
		(["./push_swap", "-a7a"], "", "Error\n"),
		(["./push_swap", "-7aaa"], "", "Error\n"),
		(["./push_swap", "-aaa7"], "", "Error\n"),
		(["./push_swap", "-aaa7aaa"], "", "Error\n"),
		(["./push_swap", "-12a"], "", "Error\n"),
		(["./push_swap", "-a12"], "", "Error\n"),
		(["./push_swap", "-a12a"], "", "Error\n"),
		(["./push_swap", "-aaaa12"], "", "Error\n"),
		(["./push_swap", "-12aaaa"], "", "Error\n"),
		(["./push_swap", "-aaaa12aaaa"], "", "Error\n"),
		(["./push_swap", "0", "0"], "", "Error\n"),
		(["./push_swap", "0", "2", "0"], "", "Error\n"),
		(["./push_swap", "0", "-2", "0"], "", "Error\n"),
		(["./push_swap", "0", "2", "0"], "", "Error\n"),
		(["./push_swap", "0", "0", "2"], "", "Error\n"),
		(["./push_swap", "2", "0", "0"], "", "Error\n"),
		(["./push_swap", "-7", "12", "7", "-7"], "", "Error\n"),
		(["./push_swap", "-7", "12", "-7"], "", "Error\n"),
		(["./push_swap", "-7", "12", "0", "3", "-7"], "", "Error\n"),
		(["./push_swap", "7", "12", "0", "3", "7"], "", "Error\n"),
		(["./push_swap", "-7", "-7", "-7"], "", "Error\n"),
		(["./push_swap", "-7", "-7", "0"], "", "Error\n"),
		(["./push_swap", "-7", "12", "0", "7", "1", "2", "3", "7"], "", "Error\n"),
		# sorted
		(["./push_swap", "0"], "", ""),
		(["./push_swap", "0", "1"], "", ""),
		(["./push_swap", "0", "1", "2"], "", ""),
		(["./push_swap", "0", "1", "2", "3"], "", ""),
		(["./push_swap", "0", "1", "2", "3", "4"], "", ""),
		(["./push_swap", "0", "1", "2", "3", "4", "5"], "", ""),
		(["./push_swap", "0 1"], "", ""),
		(["./push_swap", "0 1 2"], "", ""),
		(["./push_swap", "0 1 2 3"], "", ""),
		(["./push_swap", "0 1 2 3 4"], "", ""),
		(["./push_swap", "0 1 2 3 4 5"], "", ""),
		(["./push_swap", "0 1 2 3 4 5 6 7 8 9"], "", ""),
		(["./push_swap", "0 1 2 3 4 5 6 7 8 9 10"], "", ""),
		(["./push_swap", "-1", "3"], "", ""),
		(["./push_swap", "-4", "7"], "", ""),
		(["./push_swap", "12", "13"], "", ""),
		(["./push_swap", "2", "4", "7"], "", ""),
		(["./push_swap", "2", "4", "7", "9", "12"], "", ""),
		(["./push_swap", "2", "4", "7", "9", "12"], "", ""),
	],
}

def test_permutations(size, max_moves):
	perms = list(permutations(range(size)))
	tests = []
	for perm in perms:
		tests.append(([str(num) for num in perm], "OK", ""))

	print(f"permutations[{size}]: ", end='')
	is_ok = True
	bad_count = 0
	for i, (args, expected_stdout, expected_stderr) in enumerate(tests):
		# check if sorted
		pipe1 = subprocess.Popen(
			["./push_swap"] + args,
			stdout=subprocess.PIPE
		)
		pipe2 = subprocess.Popen(
			["./checker"] + args,
			stdin=pipe1.stdout,
			stdout=subprocess.PIPE
		)
		pipe1.stdout.close()

		pipe2_output, _ = pipe2.communicate()
		stdout = pipe2_output.decode()

		if stdout.strip() != expected_stdout and bad_count < 5:
			if is_ok:
				print("\033[91mfailed\033[0m")
				is_ok = False
			print(f"  [Test {i}] \033[91mdoes not match\033[0m")
			print(f"    \033[93mArgs: {' '.join(args)}")
			print(f"    Expected: \"{expected_stdout}\"")
			print(f"    Got:      \"{stdout}\"\033[0m")
			bad_count += 1
		
		if CHECK_LEAKS:
			leaks_cmd = ["./tests/leaks.sh"] + cmd
			leaks_result = subprocess.run(leaks_cmd, capture_output=True, text=True)
			leaks_stdout = leaks_result.stdout
	
			if leaks_stdout.strip() != "" and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91m[LEAKS]\033[0m")
				print(f"    \033[93mCommand: {' '.join(leaks_cmd)}")
				print(f"    Lost: {leaks_stdout}\033[0m")
				bad_count += 1

		pipe2.stdout.close()

	if max_moves != 0:
		for i, (args, expected_stdout, expected_stderr) in enumerate(tests):
			pipe1 = subprocess.Popen(
				["./push_swap"] + args,
				stdout=subprocess.PIPE
			)
			pipe2 = subprocess.Popen(
				["wc", "-l"],
				stdin=pipe1.stdout,
				stdout=subprocess.PIPE
			)
			pipe1.stdout.close()

			pipe2_output, _ = pipe2.communicate()
			stdout = pipe2_output.decode()
			moves = int(stdout.strip())

			if moves > max_moves and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91mtoo much moves\033[0m")
				print(f"    \033[93mArgs: {' '.join(args)}")
				print(f"    Max moves: {max_moves}")
				print(f"    Got:       {moves}\033[0m")
				bad_count += 1

			pipe2.stdout.close()

	if is_ok:
		print(f"\033[92mpassed\033[0m")

for name, test in advanced_tests.items():
	print(f"{name}: ", end='')
	is_ok = True
	bad_count = 0

	for i, (cmd, expected_stdout, expected_stderr) in enumerate(test, 1):
		try:
			result = subprocess.run(cmd, capture_output=True, text=True)
			stdout = result.stdout
			stderr = result.stderr

			if stdout != expected_stdout and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91mdoes not match\033[0m")
				print(f"    \033[93mCommand: {' '.join(cmd)}")
				print(f"    Expected: \"{expected_stdout}\"")
				print(f"    Got:      \"{stdout}\"\033[0m")
				bad_count += 1

			if stderr != expected_stderr and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91mdoes not match\033[0m")
				print(f"    \033[93mCommand: {' '.join(cmd)}")
				print(f"    Expected: \"{expected_stderr}\"")
				print(f"    Got:      \"{stderr}\"\033[0m")
				bad_count += 1

		except subprocess.CalledProcessError as e:
			print(f"  [Test {i}] \033[91mcrash: {' '.join(cmd)}\033[0m")
			print(f"    Exit code: {e.returncode}")
			print(f"    Stderr: {e.stderr.strip() if e.stderr else 'None'}")

		if CHECK_LEAKS:
			leaks_cmd = ["./tests/leaks.sh"] + cmd
			leaks_result = subprocess.run(leaks_cmd, capture_output=True, text=True)
			leaks_stdout = leaks_result.stdout
	
			if leaks_stdout.strip() != "" and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91m[LEAKS]\033[0m")
				print(f"    \033[93mCommand: {' '.join(leaks_cmd)}")
				print(f"    Lost: {leaks_stdout}\033[0m")
				bad_count += 1

	if is_ok:
		print(f"\033[92mpassed\033[0m")


test_permutations(3, 3)
test_permutations(5, 12)
