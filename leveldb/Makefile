# $NetBSD: Makefile,v 1.12 2013/11/17 07:26:45 bubuchka Exp $

DISTNAME=	leveldb-1.14.0
CATEGORIES=	databases
MASTER_SITES=	http://leveldb.googlecode.com/files/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://code.google.com/p/leveldb/
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake pax

BUILD_TARGET=	all leveldbutil db_bench

INSTALLATION_DIRS+=	bin include/leveldb lib share/doc/leveldb

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SS=		dylib
.else
SS=		so
.endif

MAJOR=		${PKGVERSION_NOREV:R:R}
MINOR=		${PKGVERSION_NOREV:R:E}

# N.B.: leveldb Darwin support follows popular Unix .so naming convention
SS.M=		${SS}.${MAJOR}
SS.M.N=		${SS}.${MAJOR}.${MINOR}

PLIST_SUBST+=	SS=${SS:Q} SS.M=${SS.M:Q} SS.M.N=${SS.M.N:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/leveldbutil ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/db_bench 				\
		${DESTDIR}${PREFIX}/bin/leveldb_bench

	${INSTALL_LIB} ${WRKSRC}/libleveldb.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libleveldb.${SS.M.N} ${DESTDIR}${PREFIX}/lib
	${LN} -s libleveldb.${SS.M.N} ${DESTDIR}${PREFIX}/lib/libleveldb.${SS.M}
	${LN} -s libleveldb.${SS.M} ${DESTDIR}${PREFIX}/lib/libleveldb.${SS}

	${INSTALL_DATA} ${WRKSRC}/include/leveldb/*			\
		${DESTDIR}${PREFIX}/include/leveldb

	cd ${WRKSRC}/doc && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/leveldb

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
