# $NetBSD$

GITHUB_PROJECT=	openfodder
DISTNAME=	1.4.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=segrax/}
DIST_SUBDIR=	${GITHUB_PROJECT}
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	data-${PKGVERSION_NOREV}.zip
SITES.data-1.4.0.zip= \
		-https://github.com/OpenFodder/data/releases/download/1.4/OpenFodder.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/segrax/openfodder/
COMMENT=	Engine for the Cannon Fodder game
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/openfodder-${PKGVERSION_NOREV}
USE_LANGUAGES=	c++14

CXXFLAGS+=	-D OPENFODDER_DATADIR=\"${PREFIX}/share/\"
CXXFLAGS+=	-I${WRKSRC}/Source
CXXFLAGS+=	`sdl2-config --cflags`
LIBS+=		`sdl2-config --libs`
LIBS+=		-lSDL2_mixer
LIBS+=		${X11_LDFLAGS}

FODDER_SRCDIRS=	Source Source/Amiga Source/PC Source/Structures
FODDER_SRCS=	${FODDER_SRCDIRS:=/*.cpp}

INSTALLATION_DIRS+=	bin share/OpenFodder

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o OpenFodder ${FODDER_SRCS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OpenFodder ${DESTDIR}${PREFIX}/bin
	cd ${WRKDIR}/OpenFodder && ${FIND} . -type d | while read d; do \
		${INSTALL_DATA_DIR} "${DESTDIR}${PREFIX}/share/OpenFodder/$$d" || exit 1; \
	done
	cd ${WRKDIR}/OpenFodder && ${FIND} . -type f | while read f; do \
		${INSTALL_DATA} "$$f" "${DESTDIR}${PREFIX}/share/OpenFodder/$${f%/*}" || exit 1; \
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
