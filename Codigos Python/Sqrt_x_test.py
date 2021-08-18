import unittest

from Sqrt_x import mySqrt

# Tests adapted from `problem-specifications//canonical-data.json`


class Sqrt_xTest(unittest.TestCase):
    def test1(self):
        self.assertEqual(mySqrt(9), 3)

    def test0(self):
        self.assertEqual(mySqrt(1), 1)

    def test2(self):
        self.assertEqual(mySqrt(2), 1)

    def test3(self):
        self.assertEqual(mySqrt(3), 1)

    def test4(self):
        self.assertEqual(mySqrt(5), 2)

    def test5(self):
        self.assertEqual(mySqrt(100), 10)

    def test6(self):
        self.assertEqual(mySqrt(478), 21)

    def test7(self):
        self.assertEqual(mySqrt(2147483647), 46340)

    def test8(self):
        self.assertEqual(mySqrt(0), 0)


if __name__ == "__main__":
    unittest.main()
