# $NetBSD: Makefile,v 1.7 2012/03/19 00:28:17 bubuchka Exp $

DISTNAME=	leveldb
PKGNAME=	${DISTNAME}-1.2
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	databases
MASTER_SITES=	#

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://code.google.com/p/leveldb/
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

GIT_REPOSITORIES=	leveldb
GIT_REPO.leveldb=	http://code.google.com/p/leveldb

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

.include "../../wip/mk/git-package.mk"
# ignore --depth - it won't work with Google HTTP
_GIT_FLAGS=	--quiet

.include "../../mk/bsd.pkg.mk"
