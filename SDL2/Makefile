# $NetBSD: Makefile,v 1.18 2014/03/01 18:55:02 othyro Exp $
#

REVISION=	8236
DISTNAME=	SDL-2.0.2-${REVISION}
PKGNAME=	${DISTNAME:S/SDL/SDL2/1:S/1-/1./1}
CATEGORIES=	devel
MASTER_SITES=	http://www.libsdl.org/tmp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/
COMMENT=	Simple DirectMedia Layer is a cross-platform multimedia library
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

PKGCONFIG_OVERRIDE+=	sdl2.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
BUILDLINK_TRANSFORM+=	rm:-ldl
.endif

SUBST_CLASSES+=		prefix
SUBST_FILES.prefix=	build/cmake_install.cmake
SUBST_MESSAGE.prefix=	Fixing PREFIX path.
SUBST_SED.prefix=	-e "s|/usr/local|${PREFIX}|1"
SUBST_STAGE.prefix=	pre-install

.include "options.mk"

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
.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
