# $NetBSD$

VERSION=	2.28.2
DISTNAME=	SDL2-${VERSION}
PKGNAME=	SDL2_testgamecontroller-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=libsdl-org/}
GITHUB_PROJECT=	SDL
GITHUB_RELEASE=	release-${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/
COMMENT=	Gamepad and joystick configuration tools from SDL2
LICENSE=	zlib

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}/test

PROGRAMS+=	controllermap
PROGRAMS+=	testgamecontroller
PROGRAMS+=	testjoystick

DATA+=		axis.bmp
DATA+=		button.bmp
DATA+=		controllermap.bmp
DATA+=		controllermap_back.bmp
DATA+=		icon.bmp
DATA+=		sample.bmp

BUILD_TARGET=	${PROGRAMS}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	libexec
INSTALLATION_DIRS+=	share/SDL2_testgamecontroller

pre-configure:
.for prog in ${PROGRAMS}
	${SED} -e 's,@@PREFIX@@,${PREFIX},g' ${FILESDIR}/${prog}.template > ${WRKDIR}/${prog}
.endfor

do-install:
.for prog in ${PROGRAMS}
		${INSTALL_SCRIPT} ${WRKDIR}/${prog} ${DESTDIR}${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/${prog} ${DESTDIR}${PREFIX}/libexec
.endfor
.for file in ${DATA}
		${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${PREFIX}/share/SDL2_testgamecontroller
.endfor

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
