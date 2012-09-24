# $NetBSD: Makefile,v 1.8 2012/09/24 01:03:24 bubuchka Exp $

DISTNAME=	leveldb-1.5.0
CATEGORIES=	databases
MASTER_SITES=	http://leveldb.googlecode.com/files/

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://code.google.com/p/leveldb/
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

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
