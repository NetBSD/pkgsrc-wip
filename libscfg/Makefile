# $NetBSD$

DISTNAME=	libscfg-0.2.0
CATEGORIES=	devel
MASTER_SITES=	${HOMEPAGE}/archive/
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://codeberg.org/emersion/libscfg
COMMENT=	C library for a simple configuration file format
LICENSE=	mit

#USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/libscfg

PKGCONFIG_OVERRIDE_STAGE=	pre-build
PKGCONFIG_OVERRIDE=		output/meson-private/scfg.pc

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
