


class Solution {
public:
    string longestPalindrome(string s) {
        
        int start_index_of_longest_palindrom = 0;
        int max_length_of_palindrom = 1;

        for (int palindrom_middle_index = 0; palindrom_middle_index < s.size(); palindrom_middle_index++){
            

            // check from the middle odd length of palindrom
            check_for_palindrom(s, palindrom_middle_index, palindrom_middle_index, start_index_of_longest_palindrom, max_length_of_palindrom);

            // check from the middle even length of palindrom
            check_for_palindrom(s, palindrom_middle_index, palindrom_middle_index + 1, start_index_of_longest_palindrom, max_length_of_palindrom);

        }

        return s.substr(start_index_of_longest_palindrom, max_length_of_palindrom);
    }

private:

    void check_for_palindrom(string& s, 
        int left_pointer, 
        int right_pointer, 
        int& start_index_of_longest_palindrom,
        int& max_length_of_palindrom){


            while (left_pointer >= 0 && right_pointer < s.size() && s[left_pointer] == s[right_pointer]){

                left_pointer -= 1;
                right_pointer += 1;
            }

            if (right_pointer - left_pointer - 1 > max_length_of_palindrom){

                max_length_of_palindrom = right_pointer - left_pointer - 1;
                start_index_of_longest_palindrom = left_pointer + 1;
            }
        }
};