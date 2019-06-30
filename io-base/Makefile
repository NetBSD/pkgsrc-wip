# $NetBSD: Makefile,v 1.2 2009/04/09 01:00:42 jsonn Exp $

META_PACKAGE=	# empty

.include "../../wip/io-base/version.mk"

DISTNAME=	io-${IO_VERSION}
PKGNAME=	io-base-${IO_VERSION}
CATEGORIES=	meta-pkgs lang devel
LICENSE=	modified-bsd

MAINTAINER=	milos.negovanovic@googlemail.com
HOMEPAGE=	http://www.iolanguage.com/
COMMENT=	All base Io addons

DEPENDS+=	io-vm>=${IO_VERSION}:../../wip/io-vm
DEPENDS+=	io-blowfish>=${IO_VERSION}:../../wip/io-blowfish
DEPENDS+=	io-cgi>=${IO_VERSION}:../../wip/io-cgi
DEPENDS+=	io-continuedfraction>=${IO_VERSION}:../../wip/io-continuedfraction
# conflicts with securesocket
#DEPENDS+=	io-socket>=${IO_VERSION}:../../wip/io-socket
DEPENDS+=	io-distributedobjects>=${IO_VERSION}:../../wip/io-distributedobjects
DEPENDS+=	io-editline>=${IO_VERSION}:../../wip/io-editline
DEPENDS+=	io-fnmatch>=${IO_VERSION}:../../wip/io-fnmatch
DEPENDS+=	io-md5>=${IO_VERSION}:../../wip/io-md5
DEPENDS+=	io-sha1>=${IO_VERSION}:../../wip/io-sha1
DEPENDS+=	io-random>=${IO_VERSION}:../../wip/io-random
DEPENDS+=	io-range>=${IO_VERSION}:../../wip/io-range
DEPENDS+=	io-rational>=${IO_VERSION}:../../wip/io-rational
DEPENDS+=	io-securesocket>=${IO_VERSION}:../../wip/io-securesocket
DEPENDS+=	io-sqldatabase>=${IO_VERSION}:../../wip/io-sqldatabase
DEPENDS+=	io-syslog>=${IO_VERSION}:../../wip/io-syslog
DEPENDS+=	io-systemcall>=${IO_VERSION}:../../wip/io-systemcall
DEPENDS+=	io-thread>=${IO_VERSION}:../../wip/io-thread
DEPENDS+=	io-user>=${IO_VERSION}:../../wip/io-user
DEPENDS+=	io-zlib>=${IO_VERSION}:../../wip/io-zlib

.include "../../mk/bsd.pkg.mk"
