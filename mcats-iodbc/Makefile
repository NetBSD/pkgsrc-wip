# $NetBSD: Makefile,v 1.1.1.1 2003/04/13 14:48:23 cjep Exp $
#

DISTNAME=	mcats-0.1.0
PKGNAME=	${DISTNAME:S/-/-iodbc-/}
CATEGORIES=	converters
MASTER_SITES=	http://mcats.net/files/

MAINTAINER=	pehr@mcats.net
HOMEPAGE=	http://mcats.net/	
COMMENT=	iODBC module for MCatS

GNU_CONFIGURE=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
CONFIGURE_ARGS+=	--enable-iodbc
BUILDLINK_DEPENDS.iodbc?=	iodbc>=2.50.3

DEPENDS+=	mcats>=0.1.0:../../converters/mcats

do-build:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${WRKSRC}/src/modules/iodbc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	${_PKG_SILENT}${_PKG_DEBUG}cd ${WRKSRC}/src/modules/iodbc && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../databases/iodbc/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
