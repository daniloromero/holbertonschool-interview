#!/usr/bin/python3
"""recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, hot_list=[], after='null', done=0):
    """ recursive function that queries the Reddit API to count word ocurrences
    Args:
        subreddit: is a string with subreddit'name
        word_list: is a list of words to count its ocurrances in sureddit
    """
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    agt = {"User-Agent": "MyBot/0.0.1"}
    payload = {"limit": "100", "after": after}
    hot = requests.get(url, headers=agt, params=payload, allow_redirects=False)
    if (hot.status_code != 200):
        return None

    if hot.status_code == 200:
        posts = hot.json().get("data").get("children")
        hot_list += [post.get("data").get("title") for post in posts]
        after = hot.json().get("data").get("after")
        if after is not None:
            count_words(subreddit, word_list, hot_list, after, done=1)
    if done == 0:
        print_words(word_list, hot_list)


def print_words(word_list, hot_list):
    """ prints words wit word count respectively """
    word_count = {}
    for word in word_list:
        c = 0
        for title in hot_list:
            t = title.lower().split()
            if word.lower().strip() in t:
                c += t.count(word.lower().strip())
        if word.lower() in word_count:
            word_count[word.lower()] += c
        else:
            word_count.update({word.lower(): c})

    for k, v in sorted(word_count.items(), key=lambda x: (-x[1], x[0])):
        if word_count.get(k) != 0:
            print("{}: {}".format(k, v))
