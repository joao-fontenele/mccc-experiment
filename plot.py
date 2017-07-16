# !/usr/bin/env python
# -*- coding: utf-8 -*-

import pandas as pd
import matplotlib.pyplot as plt
import sys


def plot(fname, arrayType):
    data = pd.read_csv(fname)
    fromType = data[data.values == arrayType]

    ax = None # needed to plot in the same figure
    for key, grp in fromType.groupby('sort'):
        line = grp[['n', 'avg']]
        ax = line.plot(x='n', y='avg', label=key, ax=ax)
    plt.title('{} arrays'.format(arrayType))
    plt.ylabel('average time (s)')
    plt.xlabel('array size')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    fname = sys.argv[1]
    arrayTypes = ['ordered', 'random', 'repeated', 'reversed']
    for arrayType in arrayTypes:
        plot(fname, arrayType)
