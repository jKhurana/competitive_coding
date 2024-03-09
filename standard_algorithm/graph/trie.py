#!/bin/python3

import math
import os
import random
import re
import sys
import json


#
# Complete the 'run_search_suggestions' function below.
#

class TrieNode:
    def __init__(self, value): 
        self.value = value 
        self.children = [None] * 27
        self.top_elements = []
        
def insert_element(root, element):
    temp = root
    for i in range(len(element)):
        index = -1
        if element[i]==' ':
            index = 26
        else:
            index = ord(element[i]) - 97
        node = temp.children[index]
        if node is None:
            node = TrieNode(element[i])
            temp.children[index] = node

        node.top_elements.append(element)
        node.top_elements.sort()
        node.top_elements = node.top_elements[:3]
        temp = node
            

class SearchSuggester:

    def __init__(self, product_categories):
        self.root = TrieNode(-1)
        for category in product_categories:
            insert_element(self.root, category)
            print(category)
            print(self.root.children[3].top_elements)

    def get_suggested_product_categories(self, search_term):
        current_node = self.root
        for i in range(len(search_term)):
            index = -1
            if search_term[i]==' ':
                index = 26
            else:
                index = ord(search_term[i]) - 97
            if current_node.children[index] is None:
                return []
            current_node = current_node.children[index]
        return current_node.top_elements


def run_search_suggestions(search_term, product_categories):
    # Write your code here
    result = []
    ss = SearchSuggester(product_categories)
    for i in range(len(search_term)):
        suggestions = ss.get_suggested_product_categories(search_term[:i+1])
        result.append(suggestions)
    return result

if __name__ == '__main__':

    search_term_str = "dresser"
    product_categories_list = ["dresser", "drapes", "drawers", "drink cart", "drinking glasses"]

    result = run_search_suggestions(search_term_str, product_categories_list)

    print(result)