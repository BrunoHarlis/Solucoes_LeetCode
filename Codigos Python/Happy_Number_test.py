import unittest

from Happy_Number import isHappy


class Happy_Number_Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(isHappy(1), True)

    def test2(self):
        self.assertEqual(isHappy(2), False)

    def test3(self):
        self.assertEqual(isHappy(3), False)

    def test4(self):
        self.assertEqual(isHappy(4), False)

    def test5(self):
        self.assertEqual(isHappy(5), False)

    def test6(self):
        self.assertEqual(isHappy(6), False)

    def test7(self):
        self.assertEqual(isHappy(7), True)

    def test8(self):
        self.assertEqual(isHappy(8), False)

    def test9(self):
        self.assertEqual(isHappy(9), False)

    def test10(self):
        self.assertEqual(isHappy(10), True)

    def test11(self):
        self.assertEqual(isHappy(23), True)


if __name__ == "__main__":
    unittest.main()
