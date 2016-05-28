# $NetBSD: Makefile,v 1.12 2012/10/03 09:10:40 asau Exp $

DISTNAME=	libpthread-stubs-1.0
PKGREVISION=	6
CATEGORIES=	devel
DISTFILES=	# empty

MAINTAINER=	blair.sadewitz@gmail.com #drochner@NetBSD.org
COMMENT=	Library providing noop-stubs for pthread functions


WRKSRC=		${WRKDIR}
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	pthread-stubs.pc

PKGCONFIG_BASE=		${PKGBASE:S/lib//1}

SUBST_CLASSES+=		pc
SUBST_STAGE.pc=		post-extract
SUBST_MESSAGE.pc=	Creating pkg-config file
SUBST_FILES.pc+=	pthread-stubs.pc
SUBST_VARS.pc+=		PKGVERSION PKGCONFIG_BASE PREFIX

do-extract:
	${CP} ${FILESDIR}/pthread-stubs.c ${FILESDIR}/Makefile \
	${FILESDIR}/pthread-stubs.pc ${FILESDIR}/pth.sym ${WRKSRC}

.include "../../mk/bsd.pkg.mk"
