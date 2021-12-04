# $NetBSD$

PKGNAME=	libunit-${UNIT_VERSION}
DISTNAME=	unit-${UNIT_VERSION}
COMMENT=	Development kit for dynamic web application server

MAINTAINER=	osa@FreeBSD.org

DISTINFO_FILE=	${.CURDIR}/../unit/distinfo
PATCHDIR=	${.CURDIR}/../unit/patches

WRKSRC=		${WRKDIR}/${DISTNAME}

CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--ld-opt="-L${PREFIX}/lib -R${PREFIX}/lib"
CONFIGURE_ARGS+=	--no-regex

do-build:
	cd ${WRKSRC} && ${MAKE} build/libunit.a

do-install:
	${MAKE} -C ${WRKSRC} libunit-install DESTDIR=${DESTDIR}

.include "../../wip/unit/version.mk"
.include "../../wip/unit/Makefile.common"
.include "../../mk/bsd.prefs.mk"
.include "../../mk/bsd.pkg.mk"
