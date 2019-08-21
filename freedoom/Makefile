# $NetBSD$

DISTNAME=	freedoom-0.11.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=freedoom/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://freedoom.github.io/
COMMENT=	Free content game for Doom engine
LICENSE=	modified-bsd

USE_LANGUAGES=	# none

# DOOMWADDIR is intentionally shared with other Doom packages
DOOMWADDIR=		share/doom
INSTALLATION_DIRS=	${DOOMWADDIR}

MESSAGE_SRC+=		MESSAGE.freedoom
MESSAGE_SUBST+=		DOOMWADDIR="${PREFIX}/${DOOMWADDIR}"

NO_BUILD=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/freedoom1.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom1.wad
	${INSTALL_DATA} ${WRKSRC}/freedoom2.wad \
		${DESTDIR}${PREFIX}/share/doom/freedoom2.wad

.include "../../mk/bsd.pkg.mk"
