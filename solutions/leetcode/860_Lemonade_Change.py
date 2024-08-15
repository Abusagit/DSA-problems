from typing import List

class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives = tens = 0

        for b in bills:
            if b == 5:
                fives += 1

            elif b == 10:
                tens += 1

                if fives > 0:
                    fives -= 1
                    
                else:
                    break

            else: # b == 20
                if fives > 0 and tens > 0:
                    fives -= 1
                    tens -= 1
                elif fives >= 3:
                    fives -= 3
                else:
                    break
        else:
            return True
        
        return False