# $NetBSD$

GITHUB_PROJECT=	openfodder
DISTNAME=	1.1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=segrax/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/segrax/openfodder/
COMMENT=	Engine for the Cannon Fodder game
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/openfodder-1.1.0
USE_LANGUAGES=	c++

CXXFLAGS+=	-std=c++0x
CXXFLAGS+=	-D OPENFODDER_DATADIR=\"${PREFIX}/share/openfodder\"
CXXFLAGS+=	-I${WRKSRC}/Source
CXXFLAGS+=	`sdl2-config --cflags`
LIBS+=		`sdl2-config --libs`
LIBS+=		-lSDL2_mixer
LIBS+=		${X11_LDFLAGS}

FODDER_SRCDIRS=	Source Source/PC Source/Amiga
FODDER_SRCS=	${FODDER_SRCDIRS:=/*.cpp}

INSTALLATION_DIRS+=	bin share/openfodder

do-build:
	cd ${WRKSRC} && ${CXX} ${CXXFLAGS} -o OpenFodder ${FODDER_SRCS} ${LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OpenFodder ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/Run && ${FIND} . -type d | while read d; do \
		${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/openfodder/$$d || exit 1; \
	done
	cd ${WRKSRC}/Run && ${FIND} . -type f | while read f; do \
		${INSTALL_DATA} $$f ${DESTDIR}${PREFIX}/share/openfodder/$${f%/*} || exit 1; \
	done

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
