# $NetBSD$

GITHUB_PROJECT=	omnispeak
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${GITHUB_PROJECT}-1.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=sulix/}
GITHUB_TAG=	v1.1
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davidgow.net/keen/omnispeak.html
COMMENT=	Open-source re-implementation of "Commander Keen in Goodbye Galaxy"
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	NO
USE_LANGUAGES+=	c++
USE_TOOLS+=	gmake

BUILD_DIRS=		src
INSTALLATION_DIRS+=	bin share/omnispeak
CFLAGS+=		-DFS_DEFAULT_OMNI_PATH=\"${PREFIX}/share/omnispeak\"

do-install:
	${INSTALL_GAME} ${WRKSRC}/bin/omnispeak ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/bin/*.* ${DESTDIR}${PREFIX}/share/omnispeak/

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
