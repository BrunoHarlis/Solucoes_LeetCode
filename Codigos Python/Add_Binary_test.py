import unittest

from Add_Binary import addBinary

# Tests adapted from `problem-specifications//canonical-data.json`


class TAdd_BinaryTest(unittest.TestCase):
    def test1(self):
        self.assertEqual(addBinary("1010", "1011"), "10101")

    def test0(self):
        self.assertEqual(addBinary("11", "1"), "100")

    def test2(self):
        self.assertEqual(addBinary('111', '111'), '1110')

    def test3(self):
        self.assertEqual(addBinary('111', '11001'), '100000')


if __name__ == "__main__":
    unittest.main()
