
from typing import List

class Solution:
    def countSeniors(self, details: List[str]) -> int:

        result = 0

        for detail in details:
            age_decimal = detail[-4]
            age_year = detail[-3]

            result += age_decimal >= '6' and not (age_decimal == '6' and age_year == '0')

        return result