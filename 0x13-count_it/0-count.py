#!/usr/bin/python3
""" Recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, after="", to_print={}):
    """
    Recursive function that queries the Reddit API
    """

    if not after:
        for word in word_list:
            to_print[word] = 0

    url = "https://www.reddit.com/r/{}/hot.json{}".format(subreddit, after)
    response = requests.get(url, headers={'User-Agent': 'rosierrav20'})

    if response.status_code == 200:
        json_response = response.json()
        reddit_list = json_response.get('data').get('children')
    for reddit in reddit_list:
        title = reddit.get('data').get('title')
        tittle_word_list = title.split()
        for word in word_list:
            for tittle_word in tittle_word_list:
                if word.lower() == tittle_word.lower():
                    to_print[word] += 1

    next_name = json_response.get('data').get('after')
    after = "?after={}".format(next_name)

    if next_name is not None:
        count_words(subreddit, word_list, after, to_print)
    else:
        for word_count in sorted(to_print.items(),
                                 key=lambda item: item[1],
                                 reverse=True):
            if word_count[1] != 0:
                print("{}: {}".format(word_count[0], word_count[1]))
