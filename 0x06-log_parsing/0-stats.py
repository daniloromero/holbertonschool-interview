#!/usr/bin/python3
"""script that reads stdin line by line and computes metrics"""
import sys


status_code = {
    '200': 0,
    '301': 0,
    '400': 0,
    '401': 0,
    '403': 0,
    '404': 0,
    '405': 0,
    '500': 0
}

size = 0


def print_stats():
    print('File size: {}'.format(size))
    for s_code, count in sorted(status_code.items()):
        if count:
            print('{}: {}'.format(s_code, count))


try:
    for i, line in enumerate(sys.stdin, start=1):
        split_line = line.strip().split()
        try:
            if split_line[-2] in status_code.keys():
                status_code[split_line[-2]] += 1
                size += int(split_line[-1])
        except:
            pass
        if i % 10 == 0:
            print_stats()
            for k, v in status_code.items():
                status_code[k] = 0
    print_stats()
except KeyboardInterrupt:
    print_stats()
    raise
