class Solution:
    def intToRoman(self, num: int) -> str:
        romans: dict[int, str] = {
                                    1: "I",
                                    5: "V",
                                    10: "X",
                                    50: "L",
                                    100: "C",
                                    500: "D",
                                    1000: "M",
                                    5000: "MMMMM"
                                }
        
        base = 1
        
        roman_string: list[str] = []
        
        while num > 0:
            
            residual = num % 10
            
            base_one = romans[base * 1]
            base_five = romans[base * 5]
            
            current_base_roman_encryption = ''
            
            if residual < 4:
                current_base_roman_encryption = base_one * residual
            elif residual == 4:
                current_base_roman_encryption = base_one + base_five
            elif 4 < residual < 9:
                current_base_roman_encryption = base_five + (residual - 5) * base_one
            elif residual == 9:
                current_base_roman_encryption = base_one + romans[(base * 10)]
                
            roman_string.append(current_base_roman_encryption)
            
            base *= 10
            num //= 10
    
        return ''.join(reversed(roman_string))