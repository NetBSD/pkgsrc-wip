# $NetBSD: Makefile,v 1.5 2004/05/05 03:12:39 blef Exp $
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
USE_BUILDLINK3=		YES
CONFIGURE_ARGS+=	--enable-iodbc

do-build:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET}

do-install:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET}

.include "../../databases/iodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
