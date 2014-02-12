# $NetBSD: Makefile,v 1.3 2014/02/12 09:29:55 thomasklausner Exp $

DISTNAME=		v1.9.8
PKGNAME=		${DISTNAME:S/v/uthash-/}
CATEGORIES=		devel
MASTER_SITES=		https://github.com/troydhanson/uthash/archive/

MAINTAINER=		noud4@users.sourceforge.net
HOMEPAGE=		http://troydhanson.github.io/uthash/
COMMENT=		Hash table, implemented in C
LICENSE=		2-clause-bsd # actually, 1-clause

DIST_SUBDIR=		uthash
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
NO_BUILD=		yes
INSTALLATION_DIRS+=	include share/doc/uthash

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/uthash

.include "../../mk/bsd.pkg.mk"
