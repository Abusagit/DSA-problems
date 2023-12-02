from itertools import combinations_with_replacement
from collections import Counter
import numpy as np

def count_expectation_slow(deck):
    
    all_summs = [min(x) + max(x) for x in combinations_with_replacement(deck, r=3)]
    probs = Counter(all_summs)
    
    # print(all_summs, probs)
    
    probs = {k: v / len(all_summs) for k, v in probs.items()}
    
    mean = 0
    
    for k, v in probs.items():
        mean += k * v
    
    return mean

def count_expectation2(deck):

    d = deck * 3
    
    return np.mean(d)
    

def count_expectation(deck: list[int]) -> float:
    """
    deck contains t_i
    """
    
    unique_values_sorted: list[int] = list(sorted(set(deck)))
    
    # fill P(X_i=t) and then get F_X(t) = P(X <= t)
    F_x: dict[float] = Counter(deck)
    for number in unique_values_sorted:
        F_x[number] /= len(deck)
    
    # get CDF:
    for j in range(1, len(unique_values_sorted)):
        current_number = unique_values_sorted[j]
        prev_number = unique_values_sorted[j-1]
        
        F_x[current_number] += F_x[prev_number]
    
    # now we have cdf of X in F_x. Lets count CDF of min(X_1, X_2, X_3) and max(X_1, X_2, X_3)
    F_min: dict[float]= {}
    F_max: dict[float] = {}
    for number, cdf_number in F_x.items():
        F_min[number] = 1 - (1 - cdf_number) ** 3
        F_max[number] = cdf_number ** 3
    # now we have CDF of max and min of three iid r.v. X \in deck. Lets count their probabilty mass functions
    P_min: dict[float] = {unique_values_sorted[0]: F_min[unique_values_sorted[0]]}
    P_max: dict[float] = {unique_values_sorted[0]: F_max[unique_values_sorted[0]]}
    

    
    
    
    for j in range(1, len(unique_values_sorted)):
        current_number = unique_values_sorted[j]
        prev_number = unique_values_sorted[j-1]
        
        
        P_min[current_number] = F_min[current_number] - F_min[prev_number]
        P_max[current_number] = F_max[current_number] - F_max[prev_number]
    
    expected_value: float = 0.0
    
    for number in unique_values_sorted:
        expected_value += number * (P_min[number] + P_max[number])
        
    return expected_value

# Чтение данных из входного потока
# n = int(input())


# best_deck_index = -1
# best_expectation = -1


# for dec_index in range(1, n + 1):
#     nk = int(input())
#     deck = list(map(int, input().split()))
    
#     expected_value = count_expectation(deck=deck)
#     print(expected_value)
    
#     if expected_value > best_expectation:
#         best_expectation = expected_value
#         best_deck_index = dec_index

# print(best_deck_index, round(best_expectation, 4))

while True:
    
    n = np.random.randint(1, 20)
    
    best_deck_index = -1
    best_expectation = -1
    
    for dec_index in range(1, n + 1):
        nk = np.random.randint(5, 9)
        deck = np.random.randint(low=1, high=10, size=nk).tolist() #[1,1,4,5,6]#[1, 2, 2, 3, 3, 3, 3, 4]         #np.random.randint(low=1, high=10, size=nk)
        expected_value_slow = round(count_expectation_slow(deck=deck), 4)
        expected_value = round(count_expectation(deck=deck), 4)
        # expected_value2 = round(count_expectation2(deck=deck), 4)

        
        assert expected_value_slow == expected_value, f"{deck}, Correct: {expected_value_slow}, Your: {expected_value}"
        print(deck, expected_value_slow, expected_value)
        
        if expected_value > best_expectation:
            best_expectation = expected_value
            best_deck_index = dec_index