from typing import List, Tuple, Dict

class Solution:
    def numberToWords(self, num: int, higher_order_integer: int=1_000_000_000) -> str:

        if higher_order_integer == 0:
            return ""
        
        if num == 0:
            return "Zero"
        
        higher_order, x = divmod(num, higher_order_integer)
        
        
        higher_order_string: str = self._parse_hundreds_decimals_numbers(x=higher_order, higher_order_integer=higher_order_integer)
        lower_order_string: str = self.numberToWords(num=x, higher_order_integer=higher_order_integer//1_000)
        
        return "{} {}".format(higher_order_string, lower_order_string).strip()
    
    @staticmethod
    def _parse_hundreds_decimals_numbers(x: int, higher_order_integer: int) -> Tuple[bool, str]:
        hundreds_mapping: Dict[int, str] = {
            0: "",
            1: "One Hundred",
            2: "Two Hundred",
            3: "Three Hundred",
            4: "Four Hundred",
            5: "Five Hundred",
            6: "Six Hundred",
            7: "Seven Hundred",
            8: "Eight Hundred",
            9: "Nine Hundred"
        }
        
        decimals_mapping: Dict[int, str] = {
            2: "Twenty",
            3: "Thirty",
            4: "Fourty",
            5: "Fifty",
            6: "Sixty",
            7: "Seventy",
            8: "Eighty",
            9: "Ninety" 
        }
        
        zero_to_nineteen_mapping: Dict[int, str] = {
            0: "",
            1: "One",
            2: "Two",
            3: "Three",
            4: "Four",
            5: "Five",
            6: "Six",
            7: "Seven",
            8: "Eight",
            9: "Nine",
            10: "Ten",
            11: "Eleven",
            12: "Twelve",
            13: "Thirteen",
            14: "Fourteen",
            15: "Fifteen",
            16: "Sixteen",
            17: "Seventeen",
            18: "Eighteen",
            19: "Nineteen",
        }
        
        number_of_hundreds, x_mod_100 = divmod(x, 100)
        
        if x_mod_100 < 20:
            decimals_str: str = zero_to_nineteen_mapping[x_mod_100]
        else:
            number_of_decimals, x_mod_1000 = divmod(x_mod_100, 10)
            
            decimals_str: str = '{} {}'.format(decimals_mapping[number_of_decimals], zero_to_nineteen_mapping[x_mod_1000]).strip()
            
        hundreds_str: str = hundreds_mapping[number_of_hundreds]
        
        
        final_string: str = '{} {}'.format([hundreds_str, decimals_str]).strip()
        print(f"{final_string=} {higher_order_integer=}")
        
        higher_order_integer_mapping: Dict[int, str] = {
            1_000_000_000: "Billion",
            1_000_000: "Million",
            1_000: "Thousand", 
            1: ""
        }
        
        if final_string:
            return "{} {}".format(final_string, higher_order_integer_mapping[higher_order_integer])
        
        return ""