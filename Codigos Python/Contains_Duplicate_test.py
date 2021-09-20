import unittest

from Contains_Duplicate import containsDuplicate


class Contains_Duplicate_Test(unittest.TestCase):
    def test01(self):
        self.assertEqual(containsDuplicate([1, 2, 3, 1]), True)

    def test02(self):
        self.assertEqual(containsDuplicate([1, 2, 3, 4]), False)

    def test03(self):
        self.assertEqual(containsDuplicate(
            [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]), True)


if __name__ == "__main__":
    unittest.main()
