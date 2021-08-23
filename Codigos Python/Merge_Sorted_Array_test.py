import unittest
from Merge_Sorted_Array import merge


class Merge_Sorted_Array_Test(unittest.TestCase):
    def test1(self):
        self.assertEqual(merge([1, 2, 3, 0, 0, 0],  3, [
                         2, 5, 6], 3),  [1, 2, 2, 3, 5, 6])
