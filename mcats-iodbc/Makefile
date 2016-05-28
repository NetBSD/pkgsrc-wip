# $NetBSD: Makefile,v 1.13 2012/11/13 22:25:39 othyro Exp $
#

DISTNAME=	mcats-0.1.0
PKGNAME=	${DISTNAME:S/-/-iodbc-/}
CATEGORIES=	converters
MASTER_SITES=	http://mcats.net/files/

MAINTAINER=	pehr@mcats.net
HOMEPAGE=	http://mcats.net/
COMMENT=	MCatS iODBC module

#DEPENDS+=	mcats>=0.1.0:../../convertors/mcats
DEPENDS+=	mcats>=0.1.0:../../wip/mcats


GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake
USE_LIBTOOL=		YES
CONFIGURE_ARGS+=	--enable-iodbc

do-build:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${BUILD_TARGET}

do-install:
	cd ${WRKSRC}/src/modules/iodbc &&			\
	${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKE_FILE} ${INSTALL_TARGET}

.include "../../databases/iodbc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
