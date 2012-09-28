# $NetBSD: Makefile,v 1.6 2012/09/28 23:07:55 asau Exp $
#

DISTNAME=		FVCool103
PKGNAME=		fvcool-1.0.3
CATEGORIES=		misc
MASTER_SITES=		http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nt.phys.kyushu-u.ac.jp/shimizu/download/fvcool/README-FVCool103.html
COMMENT=		Utility to make your AMD CPU cooler

HAS_CONFIGURE=		yes
ONLY_FOR_PLATFORM=	FreeBSD-*-i386
BUILD_TARGET=		# empty

INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fvcool ${DESTDIR}${PREFIX}/sbin/fvcool

.include "../../mk/bsd.pkg.mk"
