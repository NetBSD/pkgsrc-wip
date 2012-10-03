# $NetBSD: Makefile,v 1.9 2012/10/03 09:10:36 asau Exp $

DISTNAME=	leveldb-1.5.0
CATEGORIES=	databases
MASTER_SITES=	http://leveldb.googlecode.com/files/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://code.google.com/p/leveldb/
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake pax

BUILD_TARGET=	libleveldb.a db_bench

INSTALLATION_DIRS+=	bin include/leveldb lib share/doc/leveldb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/db_bench 				\
		${DESTDIR}${PREFIX}/bin/leveldb_bench
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/*			\
		${DESTDIR}${PREFIX}/include/leveldb
	${INSTALL_LIB} ${WRKSRC}/libleveldb.a ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC}/doc && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/leveldb

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
