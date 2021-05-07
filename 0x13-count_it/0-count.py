#!/usr/bin/python3

"""Count it! """

import requests


def count_words(subreddit, word_list, after='', words_counting={}):
    """sorted count of given keywords"""

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'python3:holberton.task:v1.0'}
    params = {'limit': '100', 'after': after}
    response = requests.get(url, headers=headers,
                            params=params, allow_redirects=False)

    if not response.status_code == 200:
        return
    data = response.json().get('data')
    after = data.get('after')
    children = data.get('children')

    for child in children:
        title = child.get('data').get('title')
        for word in word_list:
            res = title.lower().split().count(word.lower())
            if res > 0:
                if word in words_counting:
                    words_counting[word] += res
                else:
                    words_counting[word] = res

    if after is not None:
        return count_words(subreddit, word_list, after, words_counting)
    else:
        if not len(words_counting) > 0:
            return
        sort = sorted(words_counting.items(),
                      key=lambda kv: (-kv[1], kv[0]))
        for key, value in sort:
            print('{}: {}'.format(key.lower(), value))
