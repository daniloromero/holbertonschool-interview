#!/usr/bin/python3
"""recursive function that queries the Reddit API"""
import requests


def count_words(subreddit, word_list, hot_list=[], after='null'):
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
            count_words(subreddit, word_list, hot_list, after)
    print(hot_list)
