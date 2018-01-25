# $NetBSD$
# $OpenBSD: setup.py,v 1.1.1.1 2016/07/04 21:02:08 awolk Exp $

from setuptools import find_packages, setup
import sys, os

setup(
	name = "routersploit",
	version = "2.2.1",
	description = "The Router Exploitation Framework",
	author =  "Reverse Shell Security",
	author_email = "office@reverse-shell.com",
	license = "BSD",
	url = "https://github.com/reverse-shell/routersploit",
	packages=find_packages(),
	install_requires=[
		'requests>=2.9.1',
		'paramiko>=1.16.0',
		'beautifulsoup4>=4.4.1',
		'pysnmp>=4.3.2',
	],
	package_data = {'' : ['*.txt']},
	include_package_data = True,
	scripts = ('rsf.py',)
)

