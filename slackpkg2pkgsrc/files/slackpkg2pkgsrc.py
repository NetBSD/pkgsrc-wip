#!/usr/bin/python
#
# slackpkg2pkgsrc.py 1.0
#
# (C) 2004 Michal Pasternak <dotz@irc.pl>
#
# This script is distributed under BSD license
#
# $Id: slackpkg2pkgsrc.py,v 1.1.1.1 2004/03/15 12:38:51 mpasternak Exp $
#

import sys, os, socket, shutil

#
# TODO: make(1) detection !! Correct it.
#

MAKE = "/usr/bin/make"
if os.path.isfile("/usr/pkg/bin/bmake"):
    MAKE = "/usr/pkg/bin/bmake"

if not os.path.isdir("../../mk"):
    print "=" *75
    print "Please run this script in pkgsrc/category/pkgname"
    print "=" *75    
    sys.exit(1)

if len(sys.argv)!=2:
    print "=" *75    
    print "slackpkg2pkgsrc.py 1.0"
    print "(C) 2004 Michal Pasternak <dotz@irc.pl>"
    print "usage:"
    print "%s packagename" % sys.argv[0]
    print "%s group/packagename" % sys.argv[0]
    print ""
    print "packagename (and group) can be taken from MANIFEST.bz2 file, present"
    print "on mirrors with Slackware binary packages"
    print "For example:"
    print "   mkdir /usr/pkgsrc/wip/slackware_xxgdb"
    print "   cd /usr/pkgsrc/wip/slackware_xxgdb"
    print "   slackpkg2pkgsrc.py xap/xxgdb-1.12-i386-1.tgz"    
    print ""
    print "=" *75    
    sys.exit(1)
    
if os.path.isfile("Makefile"):
    print "="*75
    print "Old Makefile exists. Not removing it, quitting."
    print "="*75
    sys.exit(1)

print "=" *75
print "Converting %s..." % sys.argv[1]

grp = ""
pname = os.path.split(os.path.realpath(os.getcwd()))[-1]
dname = sys.argv[1]
if sys.argv[1].find("/")>0:
    tmp = sys.argv[1].split("/")
    grp = "\nSLACK_GROUP=\t\t%s\n" % tmp[0]
    dname = tmp[1]

if dname[-4:]==".tgz":
    dname=dname[:-4]

f = open("Makefile", "w")
f.write(
"""
# $NetBSD: slackpkg2pkgsrc.py,v 1.1.1.1 2004/03/15 12:38:51 mpasternak Exp $
# $Id: slackpkg2pkgsrc.py,v 1.1.1.1 2004/03/15 12:38:51 mpasternak Exp $
#

DISTNAME=		%s
PKGNAME=		%s
CATEGORIES=		emulators
MASTER_SITES=		${SLACKWARE_MASTER_SITES}

MAINTAINER=		YOURNAME@%s
HOMEPAGE=		http://slackware.com/
COMMENT=		%s for Slackware emulation
%s
.include "../../wip/slackware_compat/Makefile.common"
.include "../../mk/bsd.pkg.mk"
""" % (dname,
       pname,
       socket.getfqdn(),
       pname, grp))
f.close()

print "Makefile generated."

WRKSRC = os.popen("%s show-var VARNAME=WRKSRC" % MAKE).readlines()[0].strip()

os.system("%s clean" % MAKE)

os.system("%s mdi" % MAKE)

print "Checksum generated, extracting..."

os.system("%s extract" % MAKE)

print "Extracted, generating DESCR..."

shutil.move("%s/install/slack-desc" % WRKSRC, ".")

lines = open("slack-desc").readlines()
started = False
descr = open("DESCR", "w")
for line in lines:
    if started:
        descr.write(line[spaces:])
    if line.find("-handy-ruler-")>=0:
        started = True
        spaces = 2 + line.find("|")
descr.write("\nThis package is a binary package for Slackware emulation layer.")
descr.close()

shutil.rmtree("%s/install" % WRKSRC)
pass
