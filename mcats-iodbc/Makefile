# $NetBSD: Makefile,v 1.4 2004/01/25 02:32:44 grantbeattie Exp $
#

DISTNAME=	mcats-0.1.0
PKGNAME=	${DISTNAME:S/-/-iodbc-/}
CATEGORIES=	converters
MASTER_SITES=	http://mcats.net/files/

MAINTAINER=	pehr@mcats.net
HOMEPAGE=	http://mcats.net/
COMMENT=	iODBC module for MCatS

#DEPENDS+=	mcats>=0.1.0:../../convertors/mcats
DEPENDS+=	mcats>=0.1.0:../../wip/mcats

GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--enable-iodbc

do-build:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../databases/iodbc/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
