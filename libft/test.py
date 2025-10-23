import subprocess

tests = {
	"ft_substr": [
		(["./test", "ft_substr", "", "0", "0"], "'', ''"),
		(["./test", "ft_substr", "", "0", "1"], "'', ''"),
		(["./test", "ft_substr", "a", "0", "2"], "'a', 'a'"),
		(["./test", "ft_substr", "a", "1", "2"], "'a', ''"),
		(["./test", "ft_substr", "a", "2", "2"], "'a', ''"),
		(["./test", "ft_substr", "a", "3", "2"], "'a', ''"),
		(["./test", "ft_substr", "testing", "0", "1"], "'testing', 't'"),
		(["./test", "ft_substr", "testing", "1", "1"], "'testing', 'e'"),
		(["./test", "ft_substr", "testing", "2", "1"], "'testing', 's'"),
		(["./test", "ft_substr", "testing", "6", "0"], "'testing', ''"),
		(["./test", "ft_substr", "testing", "7", "0"], "'testing', ''"),
		(["./test", "ft_substr", "testing", "8", "0"], "'testing', ''"),
		(["./test", "ft_substr", "testing", "10", "0"], "'testing', ''"),
		(["./test", "ft_substr", "testing", "0", "0"], "'testing', ''"),
		(["./test", "ft_substr", "testing", "0", "1"], "'testing', 't'"),
		(["./test", "ft_substr", "testing", "0", "4"], "'testing', 'test'"),
		(["./test", "ft_substr", "testing", "0", "7"], "'testing', 'testing'"),
		(["./test", "ft_substr", "testing", "0", "8"], "'testing', 'testing'"),
		(["./test", "ft_substr", "testing", "0", "10"], "'testing', 'testing'"),
	],
	"ft_strjoin": [
		(["./test", "ft_strjoin", "NULL", "NULL"], "''"),
		(["./test", "ft_strjoin", "NULL", ""], "''"),
		(["./test", "ft_strjoin", "NULL", "abc"], "'abc'"),
		(["./test", "ft_strjoin", "", "NULL"], "''"),
		(["./test", "ft_strjoin", "abc", "NULL"], "'abc'"),
		(["./test", "ft_strjoin", "abc", ""], "'abc'"),
		(["./test", "ft_strjoin", "", "abc"], "'abc'"),
		(["./test", "ft_strjoin", "", ""], "''"),
		(["./test", "ft_strjoin", "abc", "def"], "'abcdef'"),
		(["./test", "ft_strjoin", "def", "abc"], "'defabc'"),
		(["./test", "ft_strjoin", "	", " "], "'	 '"),
		(["./test", "ft_strjoin", "	", "   "], "'	   '")
	],
	"ft_strtrim": [
		(["./test", "ft_strtrim", "NULL", "NULL"], "'(null)'"),
		(["./test", "ft_strtrim", "NULL", ""], "'(null)'"),
		(["./test", "ft_strtrim", "", "NULL"], "'(null)'"),
		(["./test", "ft_strtrim", "", ""], "''"),
		(["./test", "ft_strtrim", "a", ""], "'a'"),
		(["./test", "ft_strtrim", " ", ""], "' '"),
		(["./test", "ft_strtrim", "", "a"], "''"),
		(["./test", "ft_strtrim", "a", "a"], "''"),
		(["./test", "ft_strtrim", "a", "b"], "'a'"),
		(["./test", "ft_strtrim", "abc", ""], "'abc'"),
		(["./test", "ft_strtrim", "", "abc"], "''"),
		(["./test", "ft_strtrim", "abc", "abc"], "''"),
		(["./test", "ft_strtrim", "bac", "abc"], "''"),
		(["./test", "ft_strtrim", "cba", "abc"], "''"),
		(["./test", "ft_strtrim", "abc", "ac"], "'b'"),
		(["./test", "ft_strtrim", "aaaaabccccc", "ac"], "'b'"),
		(["./test", "ft_strtrim", "aacccacbcacacacccc", "ac"], "'b'"),
		(["./test", "ft_strtrim", "b", "ac"], "'b'"),
		(["./test", "ft_strtrim", "baacb", "ac"], "'baacb'"),
		(["./test", "ft_strtrim", "aabaacb", "ac"], "'baacb'"),
		(["./test", "ft_strtrim", "aabaacbca", "ac"], "'baacb'"),
		(["./test", "ft_strtrim", "ccaabaacbaca", "ac"], "'baacb'"),
		(["./test", "ft_strtrim", "aabaacb", "ac"], "'baacb'"),
		(["./test", "ft_strtrim", " aabaacb ", "ac"], "' aabaacb '"),
		(["./test", "ft_strtrim", " aabaacb 	", "ac"], "' aabaacb 	'")
	],
	"ft_split": [
		(["./test", "ft_split", "NULL", "a"], "'(null)'"),
		(["./test", "ft_split", "", "a"], ""),
		(["./test", "ft_split", "a", "a"], ""),
		(["./test", "ft_split", "aa", "a"], ""),
		(["./test", "ft_split", "aaaa", "a"], ""),
		(["./test", "ft_split", "test", "a"], "'test'"),
		(["./test", "ft_split", "testaa", "a"], "'test'"),
		(["./test", "ft_split", "aatest", "a"], "'test'"),
		(["./test", "ft_split", "aatestaa", "a"], "'test'"),
		(["./test", "ft_split", "aatestaayo", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "aatestaayoa", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "aatestaayoaaa", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "testayo", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "atestayo", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "testayoa", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "atestayoa", "a"], "'test' 'yo'"),
		(["./test", "ft_split", "test1atest2aaaatest3", "a"], "'test1' 'test2' 'test3'"),
		(["./test", "ft_split", "aatest1atest2aaaatest3aa", "a"], "'test1' 'test2' 'test3'"),
		(["./test", "ft_split", "aatest1atest2aaaatest3aaa", "a"], "'test1' 'test2' 'test3'"),
		(["./test", "ft_split", "atest1atest2atest3a", "a"], "'test1' 'test2' 'test3'")
	],
	"ft_itoa": [
		(["./test", "ft_itoa", "0"], "'0'"),
		(["./test", "ft_itoa", "1"], "'1'"),
		(["./test", "ft_itoa", "2"], "'2'"),
		(["./test", "ft_itoa", "3"], "'3'"),
		(["./test", "ft_itoa", "5"], "'5'"),
		(["./test", "ft_itoa", "-1"], "'-1'"),
		(["./test", "ft_itoa", "-2"], "'-2'"),
		(["./test", "ft_itoa", "-3"], "'-3'"),
		(["./test", "ft_itoa", "-5"], "'-5'"),
		(["./test", "ft_itoa", "10"], "'10'"),
		(["./test", "ft_itoa", "100"], "'100'"),
		(["./test", "ft_itoa", "1000"], "'1000'"),
		(["./test", "ft_itoa", "-10"], "'-10'"),
		(["./test", "ft_itoa", "-100"], "'-100'"),
		(["./test", "ft_itoa", "-1000"], "'-1000'"),
		(["./test", "ft_itoa", "9"], "'9'"),
		(["./test", "ft_itoa", "99"], "'99'"),
		(["./test", "ft_itoa", "999"], "'999'"),
		(["./test", "ft_itoa", "-9"], "'-9'"),
		(["./test", "ft_itoa", "-99"], "'-99'"),
		(["./test", "ft_itoa", "-999"], "'-999'"),
		(["./test", "ft_itoa", "29379612"], "'29379612'"),
		(["./test", "ft_itoa", "-29379612"], "'-29379612'"),
		(["./test", "ft_itoa", "2147483646"], "'2147483646'"),
		(["./test", "ft_itoa", "2147483647"], "'2147483647'"),
		(["./test", "ft_itoa", "-2147483647"], "'-2147483647'"),
		(["./test", "ft_itoa", "-2147483648"], "'-2147483648'")
	],
	"ft_strmapi": [
		(["./test", "ft_strmapi", "NULL"], "'(null)' '(null)'"),
		(["./test", "ft_strmapi", ""], "'' ''"),
		(["./test", "ft_strmapi", "a"], "'a' 'b'"),
		(["./test", "ft_strmapi", "b"], "'a' 'c'"),
		(["./test", "ft_strmapi", "0"], "'a' '1'"),
		(["./test", "ft_strmapi", "012"], "'aaa' '123'"),
		(["./test", "ft_strmapi", "0123"], "'aaa3' '1234'"),
		(["./test", "ft_strmapi", "hello"], "'aaalo' 'ifmmp'"),
	],
	"ft_striteri": [
		(["./test", "ft_striteri", "NULL"], " '(null)'"),
		(["./test", "ft_striteri", ""], " ''"),
		(["./test", "ft_striteri", "a"], "'a' 'a'"),
		(["./test", "ft_striteri", "b"], "'b' 'a'"),
		(["./test", "ft_striteri", "0"], "'0' 'a'"),
		(["./test", "ft_striteri", "012"], "'0' 'aaa'"),
		(["./test", "ft_striteri", "0123"], "'0' 'aaa3'"),
		(["./test", "ft_striteri", "hello"], "'h' 'aaalo'"),
	],
}

advanced_tests = {
	"ft_putchar_fd": [
		(["./test", "ft_putchar_fd", "0", "1"], "0", ""),
		(["./test", "ft_putchar_fd", "1", "1"], "1", ""),
		(["./test", "ft_putchar_fd", "8", "1"], "8", ""),
		(["./test", "ft_putchar_fd", "9", "1"], "9", ""),
		(["./test", "ft_putchar_fd", "a", "1"], "a", ""),
		(["./test", "ft_putchar_fd", "b", "1"], "b", ""),
		(["./test", "ft_putchar_fd", "y", "1"], "y", ""),
		(["./test", "ft_putchar_fd", "z", "1"], "z", ""),
		(["./test", "ft_putchar_fd", " ", "1"], " ", ""),
		(["./test", "ft_putchar_fd", "	", "1"], "	", ""),
		(["./test", "ft_putchar_fd", "~", "1"], "~", ""),
		(["./test", "ft_putchar_fd", "!", "1"], "!", ""),
		(["./test", "ft_putchar_fd", "0", "2"], "", "0"),
		(["./test", "ft_putchar_fd", "1", "2"], "", "1"),
		(["./test", "ft_putchar_fd", "8", "2"], "", "8"),
		(["./test", "ft_putchar_fd", "9", "2"], "", "9")
	],
	"ft_putstr_fd": [
		(["./test", "ft_putstr_fd", "NULL", "1"], "", ""),
		(["./test", "ft_putstr_fd", "", "1"], "", ""),
		(["./test", "ft_putstr_fd", "A", "1"], "A", ""),
		(["./test", "ft_putstr_fd", "hello", "1"], "hello", ""),
		(["./test", "ft_putstr_fd", "0123456789", "1"], "0123456789", ""),
		(["./test", "ft_putstr_fd", "abcdefghijklmnopqrstuvwxyz", "1"], "abcdefghijklmnopqrstuvwxyz", ""),
		(["./test", "ft_putstr_fd", "&'(§!)", "1"], "&'(§!)", ""),
		(["./test", "ft_putstr_fd", "NULL", "2"], "", ""),
		(["./test", "ft_putstr_fd", "", "2"], "", ""),
		(["./test", "ft_putstr_fd", "A", "2"], "", "A"),
		(["./test", "ft_putstr_fd", "hello", "2"], "", "hello"),
		(["./test", "ft_putstr_fd", "0123456789", "2"], "", "0123456789"),
		(["./test", "ft_putstr_fd", "abcdefghijklmnopqrstuvwxyz", "2"], "", "abcdefghijklmnopqrstuvwxyz"),
		(["./test", "ft_putstr_fd", "&'(§!)", "2"], "", "&'(§!)")
	],
	"ft_putendl_fd": [
		(["./test", "ft_putendl_fd", "NULL", "1"], "", ""),
		(["./test", "ft_putendl_fd", "", "1"], "\n", ""),
		(["./test", "ft_putendl_fd", "A", "1"], "A\n", ""),
		(["./test", "ft_putendl_fd", "hello", "1"], "hello\n", ""),
		(["./test", "ft_putendl_fd", "0123456789", "1"], "0123456789\n", ""),
		(["./test", "ft_putendl_fd", "abcdefghijklmnopqrstuvwxyz", "1"], "abcdefghijklmnopqrstuvwxyz\n", ""),
		(["./test", "ft_putendl_fd", "&'(§!)", "1"], "&'(§!)\n", ""),
		(["./test", "ft_putendl_fd", "NULL", "2"], "", ""),
		(["./test", "ft_putendl_fd", "", "2"], "", "\n"),
		(["./test", "ft_putendl_fd", "A", "2"], "", "A\n"),
		(["./test", "ft_putendl_fd", "hello", "2"], "", "hello\n"),
		(["./test", "ft_putendl_fd", "0123456789", "2"], "", "0123456789\n"),
		(["./test", "ft_putendl_fd", "abcdefghijklmnopqrstuvwxyz", "2"], "", "abcdefghijklmnopqrstuvwxyz\n"),
		(["./test", "ft_putendl_fd", "&'(§!)", "2"], "", "&'(§!)\n")
	],
	"ft_putnbr_fd": [
		(["./test", "ft_putnbr_fd", "0", "1"], "0", ""),
		(["./test", "ft_putnbr_fd", "1", "1"], "1", ""),
		(["./test", "ft_putnbr_fd", "2", "1"], "2", ""),
		(["./test", "ft_putnbr_fd", "3", "1"], "3", ""),
		(["./test", "ft_putnbr_fd", "5", "1"], "5", ""),
		(["./test", "ft_putnbr_fd", "-1", "1"], "-1", ""),
		(["./test", "ft_putnbr_fd", "-2", "1"], "-2", ""),
		(["./test", "ft_putnbr_fd", "-3", "1"], "-3", ""),
		(["./test", "ft_putnbr_fd", "-5", "1"], "-5", ""),
		(["./test", "ft_putnbr_fd", "10", "1"], "10", ""),
		(["./test", "ft_putnbr_fd", "100", "1"], "100", ""),
		(["./test", "ft_putnbr_fd", "1000", "1"], "1000", ""),
		(["./test", "ft_putnbr_fd", "-10", "1"], "-10", ""),
		(["./test", "ft_putnbr_fd", "-100", "1"], "-100", ""),
		(["./test", "ft_putnbr_fd", "-1000", "1"], "-1000", ""),
		(["./test", "ft_putnbr_fd", "9", "1"], "9", ""),
		(["./test", "ft_putnbr_fd", "99", "1"], "99", ""),
		(["./test", "ft_putnbr_fd", "999", "1"], "999", ""),
		(["./test", "ft_putnbr_fd", "-9", "1"], "-9", ""),
		(["./test", "ft_putnbr_fd", "-99", "1"], "-99", ""),
		(["./test", "ft_putnbr_fd", "-999", "1"], "-999", ""),
		(["./test", "ft_putnbr_fd", "29379612", "1"], "29379612", ""),
		(["./test", "ft_putnbr_fd", "-29379612", "1"], "-29379612", ""),
		(["./test", "ft_putnbr_fd", "2147483646", "1"], "2147483646", ""),
		(["./test", "ft_putnbr_fd", "2147483647", "1"], "2147483647", ""),
		(["./test", "ft_putnbr_fd", "-2147483647", "1"], "-2147483647", ""),
		(["./test", "ft_putnbr_fd", "-2147483648", "1"], "-2147483648", ""),
		(["./test", "ft_putnbr_fd", "0", "2"], "", "0"),
		(["./test", "ft_putnbr_fd", "1", "2"], "", "1"),
		(["./test", "ft_putnbr_fd", "2", "2"], "", "2"),
		(["./test", "ft_putnbr_fd", "3", "2"], "", "3"),
		(["./test", "ft_putnbr_fd", "5", "2"], "", "5"),
		(["./test", "ft_putnbr_fd", "-1", "2"], "", "-1"),
		(["./test", "ft_putnbr_fd", "-2", "2"], "", "-2"),
		(["./test", "ft_putnbr_fd", "-3", "2"], "", "-3"),
		(["./test", "ft_putnbr_fd", "-5", "2"], "", "-5"),
		(["./test", "ft_putnbr_fd", "10", "2"], "", "10"),
		(["./test", "ft_putnbr_fd", "100", "2"], "", "100"),
		(["./test", "ft_putnbr_fd", "1000", "2"], "", "1000"),
		(["./test", "ft_putnbr_fd", "-10", "2"], "", "-10"),
		(["./test", "ft_putnbr_fd", "-100", "2"], "", "-100"),
		(["./test", "ft_putnbr_fd", "-1000", "2"], "", "-1000"),
		(["./test", "ft_putnbr_fd", "9", "2"], "", "9"),
		(["./test", "ft_putnbr_fd", "99", "2"], "", "99"),
		(["./test", "ft_putnbr_fd", "999", "2"], "", "999"),
		(["./test", "ft_putnbr_fd", "-9", "2"], "", "-9"),
		(["./test", "ft_putnbr_fd", "-99", "2"], "", "-99"),
		(["./test", "ft_putnbr_fd", "-999", "2"], "", "-999"),
		(["./test", "ft_putnbr_fd", "29379612", "2"], "", "29379612"),
		(["./test", "ft_putnbr_fd", "-29379612", "2"], "", "-29379612"),
		(["./test", "ft_putnbr_fd", "2147483646", "2"], "", "2147483646"),
		(["./test", "ft_putnbr_fd", "2147483647", "2"], "", "2147483647"),
		(["./test", "ft_putnbr_fd", "-2147483647", "2"], "", "-2147483647"),
		(["./test", "ft_putnbr_fd", "-2147483648", "2"], "", "-2147483648")
	],
	"ft_lstnew": [
		(["./test", "ft_lstnew", "NULL"], "(null)->(nil)", ""),
		(["./test", "ft_lstnew", ""], "->(nil)", ""),
		(["./test", "ft_lstnew", "a"], "a->(nil)", ""),
		(["./test", "ft_lstnew", "test"], "test->(nil)", "")
	],
	"ft_lstadd_front": [
		(["./test", "ft_lstadd_front"], "", ""),
		(["./test", "ft_lstadd_front", "a"], "a->(null)", ""),
		(["./test", "ft_lstadd_front", "a", "b"], "b->a->(null)", ""),
		(["./test", "ft_lstadd_front", "a", "b", "c"], "c->b->a->(null)", ""),
		(["./test", "ft_lstadd_front", "c", "b", "a"], "a->b->c->(null)", "")
	],
	"ft_lstsize": [
		(["./test", "ft_lstsize"], "[0]", ""),
		(["./test", "ft_lstsize", "a"], "[1]a->(null)", ""),
		(["./test", "ft_lstsize", "a", "b"], "[2]b->a->(null)", ""),
		(["./test", "ft_lstsize", "a", "b", "c"], "[3]c->b->a->(null)", ""),
		(["./test", "ft_lstsize", "c", "b", "a"], "[3]a->b->c->(null)", ""),
		(["./test", "ft_lstsize", "e", "d", "c", "b", "a"], "[5]a->b->c->d->e->(null)", "")
	],
	"ft_lstlast": [
		(["./test", "ft_lstlast"], "[(null)]", ""),
		(["./test", "ft_lstlast", "a"], "[a]a->(null)", ""),
		(["./test", "ft_lstlast", "a", "b"], "[a]b->a->(null)", ""),
		(["./test", "ft_lstlast", "a", "b", "c"], "[a]c->b->a->(null)", ""),
		(["./test", "ft_lstlast", "c", "b", "a"], "[c]a->b->c->(null)", ""),
		(["./test", "ft_lstlast", "e", "d", "c", "b", "a"], "[e]a->b->c->d->e->(null)", "")
	],
	"ft_lstadd_back": [
		(["./test", "ft_lstadd_back"], "", ""),
		(["./test", "ft_lstadd_back", "a"], "a->(null)", ""),
		(["./test", "ft_lstadd_back", "a", "b"], "a->b->(null)", ""),
		(["./test", "ft_lstadd_back", "a", "b", "c"], "a->b->c->(null)", ""),
		(["./test", "ft_lstadd_back", "c", "b", "a"], "c->b->a->(null)", ""),
		(["./test", "ft_lstadd_back", "e", "d", "c", "b", "a"], "e->d->c->b->a->(null)", "")
	],
	"ft_lstdelone": [
		(["./test", "ft_lstdelone", "NULL"], "[del]((null))", ""),
		(["./test", "ft_lstdelone", ""], "[del]()", ""),
		(["./test", "ft_lstdelone", "a"], "[del](a)", ""),
		(["./test", "ft_lstdelone", "test"], "[del](test)", "")
	],
	"ft_lstclear": [
		(["./test", "ft_lstclear"], "", ""),
		(["./test", "ft_lstclear", "a"], "a->(null)[del](a)", ""),
		(["./test", "ft_lstclear", "a", "b"], "a->b->(null)[del](a)[del](b)", ""),
		(["./test", "ft_lstclear", "a", "b", "c"], "a->b->c->(null)[del](a)[del](b)[del](c)", ""),
		(["./test", "ft_lstclear", "c", "b", "a"], "c->b->a->(null)[del](c)[del](b)[del](a)", ""),
		(["./test", "ft_lstclear", "e", "d", "c", "b", "a"], "e->d->c->b->a->(null)[del](e)[del](d)[del](c)[del](b)[del](a)", "")
	],
	"ft_lstiter": [
		(["./test", "ft_lstiter"], "_", ""),
		(["./test", "ft_lstiter", "a"], "a->(null)_a", ""),
		(["./test", "ft_lstiter", "a", "b"], "a->b->(null)_ab", ""),
		(["./test", "ft_lstiter", "a", "b", "c"], "a->b->c->(null)_abc", ""),
		(["./test", "ft_lstiter", "c", "b", "a"], "c->b->a->(null)_cba", ""),
		(["./test", "ft_lstiter", "e", "d", "c", "b", "a"], "e->d->c->b->a->(null)_edcba", "")
	],
	"ft_lstmap": [
		(["./test", "ft_lstmap"], "_", ""),
		(["./test", "ft_lstmap", "a"], "a->(null)_a->(null)", ""),
		(["./test", "ft_lstmap", "test"], "test->(null)_aest->(null)", ""),
		(["./test", "ft_lstmap", "a", "b"], "a->b->(null)_a->a->(null)", ""),
		(["./test", "ft_lstmap", "a", "b", "c"], "a->b->c->(null)_a->a->a->(null)", ""),
		(["./test", "ft_lstmap", "c", "b", "a"], "c->b->a->(null)_a->a->a->(null)", ""),
		(["./test", "ft_lstmap", "e", "d", "c", "b", "a"], "e->d->c->b->a->(null)_a->a->a->a->a->(null)", "")
	]
}

for name, test in tests.items():
	print(f"{name}: ", end='')
	is_ok = True
	bad_count = 0

	for i, (cmd, expected_output) in enumerate(test, 1):
		try:
			result = subprocess.run(cmd, capture_output=True, text=True, check=True)
			actual_output = result.stdout

			if actual_output != expected_output and bad_count < 5:
				if is_ok:
					print("\033[91mfailed\033[0m")
					is_ok = False
				print(f"  [Test {i}] \033[91mdoes not match\033[0m")
				print(f"    \033[93mCommand: {' '.join(cmd)}")
				print(f"    Expected: \"{expected_output}\"")
				print(f"    Got:      \"{actual_output}\"\033[0m")
				bad_count += 1

		except subprocess.CalledProcessError as e:
			print(f"  [Test {i}] \033[91mcrash: {' '.join(cmd)}\033[0m")
			print(f"    Exit code: {e.returncode}")
			print(f"    Stderr: {e.stderr.strip() if e.stderr else 'None'}")

	if is_ok:
		print(f"\033[92mpassed\033[0m")

for name, test in advanced_tests.items():
	print(f"{name}: ", end='')
	is_ok = True
	bad_count = 0

	for i, (cmd, expected_stdout, expected_stderr) in enumerate(test, 1):
		try:
			result = subprocess.run(cmd, capture_output=True, text=True, check=True)
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


	if is_ok:
		print(f"\033[92mpassed\033[0m")
