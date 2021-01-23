# $NetBSD$

GITHUB_PROJECT=	rottexpr
GITHUB_TAG=	v0.01
DISTNAME=	v0.01
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S,^v,,}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=LTCHIPS/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/LTCHIPS/rottexpr/
COMMENT=	SDL2 source port of Rise of the Triad
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/rottexpr-0.01/src

MAKE_FLAGS+=	EXTRALDLIBS=-lexecinfo
#MAKE_FLAGS+=	SHAREWARE=1
USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin share/doc/rottexpr

do-install:
	${INSTALL_GAME} ${WRKSRC}/rott ${DESTDIR}${PREFIX}/bin/rottexpr
	${INSTALL_DATA} ${WRKSRC}/../*md ${DESTDIR}${PREFIX}/share/doc/rottexpr/

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libexecinfo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
