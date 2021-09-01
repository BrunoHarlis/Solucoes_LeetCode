import unittest
from Excel_Sheet_Column_Title import convertToTitle


class Excel_Sheet_Column_Title_Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(convertToTitle(52), 'AZ')

    def test2(self):
        self.assertEqual(convertToTitle(28), 'AB')

    def test3(self):
        self.assertEqual(convertToTitle(701), 'ZY')

    def test4(self):
        self.assertEqual(convertToTitle(2147483647), 'FXSHRXW')


if __name__ == "__main__":
    unittest.main()
