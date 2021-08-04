import unittest

from String_to_int import myAtoi

# Tests adapted from `problem-specifications//canonical-data.json`


class TwoFerTest(unittest.TestCase):
    def test1(self):
        self.assertEqual(myAtoi('42'), 42)

    def test0(self):
        self.assertEqual(myAtoi('+42'), 42)

    def test2(self):
        self.assertEqual(myAtoi(' 42'), 42)

    def test3(self):
        self.assertEqual(myAtoi(' -42'), -42)

    def test4(self):
        self.assertEqual(myAtoi('-42'), -42)

    def test5(self):
        self.assertEqual(myAtoi('-42 '), -42)

    def test6(self):
        self.assertEqual(myAtoi('q42'), 0)

    def test7(self):
        self.assertEqual(myAtoi('42q'), 42)

    def test8(self):
        self.assertEqual(myAtoi('qwe 42'), 0)

    def test9(self):
        self.assertEqual(myAtoi('42 sdfa'), 42)

    def test10(self):
        self.assertEqual(myAtoi('-91283472332'), -2147483648)

    def test11(self):
        self.assertEqual(myAtoi('91283472332'), 2147483647)

    def test12(self):
        self.assertEqual(myAtoi('3.14159'), 3)

    def test13(self):
        self.assertEqual(myAtoi('.14159'), 0)

    def test14(self):
        self.assertEqual(myAtoi('045'), 45)

    def test15(self):
        self.assertEqual(myAtoi('00000-42a1234'), 0)

    def test16(self):
        self.assertEqual(myAtoi('-+42'), 0)

    def test17(self):
        self.assertEqual(myAtoi(''), 0)

    def test18(self):
        self.assertEqual(myAtoi(' '), 0)

    def test19(self):
        self.assertEqual(myAtoi('  -0012a42'), -12)

    def test20(self):
        self.assertEqual(myAtoi('-2147483647'), -2147483647)


if __name__ == "__main__":
    unittest.main()
