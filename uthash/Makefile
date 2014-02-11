# $NetBSD: Makefile,v 1.2 2014/02/11 21:04:07 noud4 Exp $

DISTNAME=		master
PKGNAME=		uthash-1.9.7
CATEGORIES=		devel
MASTER_SITES=		https://github.com/troydhanson/uthash/archive/
EXTRACT_SUFX=		.zip

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://troydhanson.github.io/uthash/
COMMENT=		Hash table, implemented in C
#LICENSE=		bsd-revised	# TODO

FETCH_USING=		curl
DIST_SUBDIR=		uthash/${PKGVERSION_NOREV}
WRKSRC=			${WRKDIR}/uthash-master
USE_LANGUAGES=		c c++
NO_BUILD=		YES
INSTALLATION_DIRS+=	include

do-install:
	${INSTALL_DATA} ${WRKDIR}/uthash-${DISTNAME}/src/uthash.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKDIR}/uthash-${DISTNAME}/src/utlist.h ${DESTDIR}${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
