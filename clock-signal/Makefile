# $NetBSD$

DISTNAME=	clock-signal-20230515
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=TomHarte/}
GITHUB_PROJECT=	CLK
GITHUB_TAG=	2023-05-15

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://github.com/TomHarte/CLK
COMMENT=	Emulator of 8- and 16-bit platforms
LICENSE=	mit

NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++

SCONS_ARGS+=	${_MAKE_JOBS}

# C++17
GCC_REQD+=	8.4

#TOOL_DEPENDS+=	patchelf-[0-9]*:../../devel/patchelf

do-build:
	cd ${WRKSRC}/OSBindings/SDL && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/OSBindings/SDL/clksignal ${DESTDIR}${LOCALBASE}/bin
	#${PREFIX}/bin/patchelf \
	#	--force-rpath --set-rpath \
	#	${PREFIX}/lib \
	#	${DESTDIR}${LOCALBASE}/bin/clksignal

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
