# $NetBSD$

DISTNAME=	libevdev-chunk-20231111
CATEGORIES=	devel
MASTER_SITES=	https://code.tetaneutral.net/mherrb/libevdev-openbsd/archive/
DISTFILES=	${DISTNAME:S/chunk/openbsd/}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://code.tetaneutral.net/mherrb/libevdev-openbsd/
COMMENT=	Minimal set of libevdev functions
LICENSE=	mit

WRKSRC=		${WRKDIR}/libevdev-openbsd

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	Makefile
SUBST_SED.prefix=	-e 's,/usr/local,${PREFIX},g'

INSTALLATION_DIRS+=	lib/pkgconfig
INSTALLATION_DIRS+=	include/libevdev

do-install:
	${INSTALL_LIB} ${WRKSRC}/libevdev.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libevdev.so.0 ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libevdev.so.0.0 ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libevdev.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libevdev/libevdev.h ${DESTDIR}${PREFIX}/include/libevdev
	${INSTALL_DATA} ${WRKSRC}/libevdev.pc ${DESTDIR}${PREFIX}/lib/pkgconfig

.include "../../wip/input-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
