import sys

author = "Rocky Bernstein"
author_email = "rb@dustyfeet.com"

import os.path as osp


py_modules = None
short_desc = "Determine if shell has a light or dark background"
url = "http://github.com/rocky/shell-term-background"

classifiers = [
    "Operating System :: OS Independent",
    "Programming Language :: Python :: 2.6",
    "Programming Language :: Python :: 2.7",
    "Programming Language :: Python :: 3.2",
    "Programming Language :: Python :: 3.3",
    "Programming Language :: Python :: 3.4",
    "Programming Language :: Python :: 3.5",
    "Programming Language :: Python :: 3.6",
    "Programming Language :: Python :: 3.7",
    "Programming Language :: Python :: 3.8",
    "Programming Language :: Python :: 3.9",
]

def get_srcdir():
    filename = osp.normcase(osp.dirname(osp.abspath(__file__)))
    return osp.realpath(filename)

def read(*rnames):
    return open(osp.join(get_srcdir(), *rnames)).read()

# Get/set __version__ and long_description from files
long_description = read("README.rst") + "\n"
exec(read("term_background/version.py"))
