# $NetBSD$

DISTNAME=	clock-signal-20211219
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=TomHarte/}
GITHUB_PROJECT=	CLK
GITHUB_TAG=	2021-12-19

MAINTAINER=	dressupgeekout@gmail.com
HOMEPAGE=	https://github.com/TomHarte/CLK
COMMENT=	Emulator of 8- and 16-bit platforms
LICENSE=	mit

EXTRACT_USING=	gtar
NO_CONFIGURE=	yes
USE_LANGUAGES=	c c++

SCONS_ARGS=	# defined
SCONS_ARGS+=	${_MAKE_JOBS}

do-build:
	cd ${WRKSRC}/OSBindings/SDL && \
	${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${LOCALBASE}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/OSBindings/SDL/clksignal ${DESTDIR}${LOCALBASE}/bin

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/scons/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
