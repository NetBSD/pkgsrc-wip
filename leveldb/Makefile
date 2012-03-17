# $NetBSD: Makefile,v 1.2 2012/03/17 11:45:47 bubuchka Exp $

DISTNAME=	leveldb
PKGNAME=	${DISTNAME}-0
PKGREVISION=	${_GIT_PKGVERSION:S/.//g}
CATEGORIES=	databases
MASTER_SITES=	#

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://code.google.com/p/leveldb/
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	2-clause-bsd

GIT_REPOSITORIES=	leveldb
GIT_REPO.leveldb=	http://code.google.com/p/leveldb

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake

BUILD_TARGET=	libleveldb.a db_bench

INSTALLATION_DIRS+=	bin include/leveldb lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/include/leveldb/* ${DESTDIR}${PREFIX}/include/leveldb
	${INSTALL_LIB} ${WRKSRC}/libleveldb.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/db_bench ${DESTDIR}${PREFIX}/bin/leveldb_bench

.include "../../wip/mk/git-package.mk"
_GIT_FLAGS=	--quiet

.include "../../mk/bsd.pkg.mk"
