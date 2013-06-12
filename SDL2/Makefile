# $NetBSD: Makefile,v 1.11 2013/06/12 01:44:49 othyro Exp $
#

REVISION=	7304
DISTNAME=	SDL-2.0.0-${REVISION}
PKGNAME=	${DISTNAME:S/SDL/SDL2/1:S/0-/0./1}
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/tmp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer is a cross-platform multimedia library
LICENSE=	zlib

WRKSRC=		${WRKDIR}/SDL-2.0.0-${REVISION}
GNU_CONFIGURE=	yes
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	sdl2.pc.in

.include "options.mk"

.if $(OPSYS) != "Linux"
BUILDLINK_TRANSFORM=	rm:-ldl
.endif

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	build/cmake_install.cmake
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	pre-install

pre-configure:
	cd ${WRKSRC} && ${MKDIR} build

do-configure:
	cd ${WRKSRC}/build && ${SETENV} ${CONFIGURE_ENV} ${CMAKE} ..

do-build:
	cd ${WRKSRC}/build && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM}

do-install:
	cd ${WRKSRC}/build && ${SETENV} ${INSTALL_ENV} ${MAKE_PROGRAM} ${INSTALL_TARGET}

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xproto/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
