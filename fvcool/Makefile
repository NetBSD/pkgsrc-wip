# $NetBSD: Makefile,v 1.1.1.1 2004/01/01 17:02:39 mpasternak Exp $
#

DISTNAME=		FVCool103
PKGNAME=		fvcool-1.0.3
CATEGORIES=		misc
MASTER_SITES=		http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/README-FVCool100.html
COMMENT=		Utility to make your AMD CPU cooler

HAS_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	FreeBSD-*-i386
ALL_TARGET=		# empty

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${PREFIX}/sbin/fvcool

.include "../../mk/bsd.pkg.mk"
