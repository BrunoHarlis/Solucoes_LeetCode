import unittest
from Substring_with_Concatenation_of_All_Words import findSubstring


class Substring_test(unittest.TestCase):
    def test1(self):
        self.assertEqual(findSubstring(
            "barfoothefoobarman", ["foo", "bar"]), [0, 9])

    def test2(self):
        self.assertEqual(findSubstring(
            "barfoothefoobarman", ["word", "good", "best", "word"]), [])

    def test3(self):
        self.assertEqual(findSubstring(
            "barfoofoobarthefoobarman", ["bar", "foo", "the"]), [6, 9, 12])

    def test4(self):
        self.assertEqual(findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", [
                         "fooo", "barr", "wing", "ding", "wing"]), [13])


if __name__ == '__main__':
    unittest.main()
