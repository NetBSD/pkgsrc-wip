# $NetBSD: Makefile,v 1.2 2004/07/03 18:33:03 rillig Exp $
#

DISTNAME=		db.1.86
PKGNAME=		db1-1.86
CATEGORIES=		databases
MASTER_SITES=		http://www.sleepycat.com/update/snapshot/

MAINTAINER=		dotz@irc.pl
HOMEPAGE=		http://www.sleepycat.com/
COMMENT=		Berkeley DB 1.86

BUILD_DIRS=		${WRKSRC}/PORT/linux
ALL_TARGET=		libdb.a

do-install:
	${INSTALL_DATA} ${BUILD_DIRS}/libdb.a ${PREFIX}/lib
.for F in compat.h db.h mpool.h ndbm.h
	${INSTALL_DATA} ${BUILD_DIRS}/include/${F} ${PREFIX}/include/${F}
.endfor
.for F in btree.3 dbopen.3 hash.3 mpool.3 recno.3
	${INSTALL_MAN} ${WRKSRC}/man/${F} ${PREFIX}/man/man3/${F}
.endfor

.include "../../mk/bsd.pkg.mk"
