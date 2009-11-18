#!/usr/pkg/bin/python2.5

from distutils.core import setup

setup(
    name="spade",
    license="LGPLv2.1",
    version="0.2",
    description="Smart Python multi-Agent Development Environment",
    url="http://spade.gti-ia.dsic.upv.es/",
    packages=["spade","spade/mtp","templates",\
	      "templates/img","tlslite","tlslite/integration","tlslite/scripts",\
	      "tlslite/utils","xmpp","xmppd","xmppd/modules","xmppd/socker","xmppd/tools"],
    scripts=["configure.py","spade.sh","runspade.py"],
    long_description="""SPADE is a Multiagent and Organizations Platform based on ra the XMPP/Jabber technology and written in the Python programming language. This technology offers by itself many features and facilities that ease the construction of MAS, such as an existing communication channel, the concepts of users (agents) and servers (platforms) and an extensible communication protocol based on XML, just like FIPA-ACL. Many other agent platforms exist, but SPADE is the first to base its roots on the XMPP technology.""")
