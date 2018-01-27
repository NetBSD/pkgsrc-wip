# $NetBSD$

GITHUB_PROJECT=	rocksdb
DISTNAME=	${GITHUB_PROJECT}-5.9.2
MASTER_SITES=	${MASTER_SITE_GITHUB:=facebook/}
DIST_SUBDIR=	${GITHUB_PROJECT}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	database

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rocksdb.org/
COMMENT=	RocksDB is an embeddable persistent key-value store for fast storage.
LICENSE=	apache-2.0

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl
BUILD_TARGET=		shared_lib static_lib tools tools_lib install-shared install-static install-headers
#INSTALL_TARGET=	install-shared install-static install-headers
PKG_DESTDIR_SUPPORT=	destdir

MAKE_ENV+=	PORTABLE=1 DEBUG_LEVEL=0
MAKE_ENV+=	INSTALL_PATH=${DESTDIR}${PREFIX}

PB_FROM= ${WRKDIR}/rocksdb-${PKGVERSION_NOREV}/
post-build:
	mkdir -p ${DESTDIR}${PREFIX}/bin
	cp ${PB_FROM}/sst_dump ${DESTDIR}${PREFIX}/bin/sst_dump
	cp ${PB_FROM}/db_sanity_test ${DESTDIR}${PREFIX}/bin/db_sanity_test
	cp ${PB_FROM}/db_stress ${DESTDIR}${PREFIX}/bin/db_stress
	cp ${PB_FROM}/write_stress ${DESTDIR}${PREFIX}/bin/write_stress
	cp ${PB_FROM}/ldb ${DESTDIR}${PREFIX}/bin/ldb
	cp ${PB_FROM}/db_repl_stress ${DESTDIR}${PREFIX}/bin/db_repl_stress
	cp ${PB_FROM}/rocksdb_dump ${DESTDIR}${PREFIX}/bin/rocksdb_dump
	cp ${PB_FROM}/rocksdb_undump ${DESTDIR}${PREFIX}/bin/rocksdb_undump
	cp ${PB_FROM}/blob_dump ${DESTDIR}${PREFIX}/bin/blob_dump
	cp ${PB_FROM}/librocksdb_tools.a ${DESTDIR}${PREFIX}/lib/librocksdb_tools.a

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
