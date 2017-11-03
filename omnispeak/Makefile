# $NetBSD$

GITHUB_PROJECT=	omnispeak
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=sulix/}
GITHUB_TAG=	5bfa6102d24e0fa06d577063d2a2f83d435ba20f
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davidgow.net/keen/omnispeak.html
COMMENT=	Open-source re-implementation of "Commander Keen in Goodbye Galaxy"
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake

WRKSRC=		${WRKDIR}/omnispeak-${GITHUB_TAG}

SUBST_CLASSES+=			search-path
SUBST_STAGE.search-path=	pre-configure
SUBST_MESSAGE.search-path=	Search for files in PREFIX.
SUBST_FILES.search-path=	src/id_ca.c
SUBST_SED.search-path=		-e 's,@@PKGSRC_DATA_DIR@@,${PREFIX}/share/omnispeak,g'

BUILD_DIRS=		src
BUILD_MAKE_FLAGS+=	X11_LDFLAGS=${X11_LDFLAGS:Q}
INSTALLATION_DIRS+=	bin share/omnispeak

do-install:
	${INSTALL_GAME} ${WRKSRC}/bin/omnispeak ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/*.* ${DESTDIR}${PREFIX}/share/omnispeak/

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
