# $NetBSD: Makefile,v 1.1 2004/06/01 11:49:20 johnrshannon Exp $
#

DISTNAME=		libiberty-1.0
CATEGORIES=		wip
MASTER_SITES=		http://www.johnrshannon.com/NetBSD/

MAINTAINER=		john@johnrshannon.com
HOMEPAGE=		http://www.johnrshannon.com/NetBSD/
COMMENT=		This package provides the -liberty library of free software

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make

do-configure:
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${WRKSRC}/configure ${CONFIGURE_ARGS})
	(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${GMAKE} configure-libiberty)

do-build:
	(cd ${WRKSRC}/libiberty && ${SETENV} ${BUILD_ENV} ${GMAKE})

do-test:
	(cd ${WRKSRC} && ${SETENV} ${BUILD_ENV} ${GMAKE} check)

do-install:
	${INSTALL_LIB} ${WRKSRC}/libiberty/libiberty.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/libiberty.h ${PREFIX}/include

.include "../../mk/bsd.pkg.mk"
