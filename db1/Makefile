# $NetBSD: Makefile,v 1.10 2012/09/28 21:24:30 asau Exp $
#

DISTNAME=		db.1.86
PKGNAME=		db1-1.86
CATEGORIES=		databases
MASTER_SITES=		http://downloads.sleepycat.com/ \
			ftp://ftp.sleepycat.com/release/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.oracle.com/database/berkeley-db.html
COMMENT=		Berkeley DB 1.86

BUILD_DIRS=		${WRKSRC}/PORT/linux
BUILD_TARGET=		libdb.a

do-install:
	${INSTALL_DATA} ${BUILD_DIRS}/libdb.a ${DESTDIR}${PREFIX}/lib
.for F in compat.h db.h mpool.h ndbm.h
	${INSTALL_DATA} ${BUILD_DIRS}/include/${F} ${DESTDIR}${PREFIX}/include/${F}
.endfor
.for F in btree.3 dbopen.3 hash.3 mpool.3 recno.3
	${INSTALL_MAN} ${WRKSRC}/man/${F} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/${F}
.endfor

.include "../../mk/bsd.pkg.mk"
