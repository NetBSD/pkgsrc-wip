# $NetBSD: Makefile,v 1.2 2003/05/16 03:50:43 jeremy-c-reed Exp $

DISTNAME=		strace-4.4.94
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=strace/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.wi.leidenuniv.nl/~wichert/strace/
COMMENT=		system call tracing utility

GNU_CONFIGURE=		YES

# operating system netbsdelf is not supported by strace
# XXX  for Linux, SunOS 4.x, System V release 4, Solaris 2.x and Irix 5.x
# XXX  only tested under Linux
ONLY_FOR_PLATFORM=     Linux-*-*

.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
