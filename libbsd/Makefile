# $NetBSD$

DISTNAME=	libbsd-0.11.6
CATEGORIES=	devel
MASTER_SITES=	https://libbsd.freedesktop.org/releases/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://libbsd.freedesktop.org/
COMMENT=	Compatibility library for BSD functions under other systems
LICENSE=	original-bsd AND modified-bsd AND 2-clause-bsd
LICENSE+=	AND isc AND mit AND beer-ware

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config autoconf automake autoreconf

CFLAGS+=	-ffat-lto-objects

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

do-test:
	${RUN} cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${MAKE} check

PKGCONFIG_OVERRIDE+=	src/libbsd-ctor.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd-overlay.pc.in
PKGCONFIG_OVERRIDE+=	src/libbsd.pc.in

.include "../../devel/libmd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
