# $NetBSD$

DISTNAME=	0ad-0.0.20-alpha-unix-data
PKGNAME=	${DISTNAME:S/-unix-data//:S/0ad-/0ad-data-/:S/-alpha/.alpha/}
CATEGORIES=	games
MASTER_SITES=	http://releases.wildfiregames.com/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://releases.wildfiregames.com/
COMMENT=	Datafiles for the 0ad game
LICENSE=	public-domain AND cc-by-sa-v3.0

WRKSRC=		${WRKDIR}/${DISTNAME:S/-unix-data//}
USE_LANGUAGES=	# none

USE_TOOLS+=	pax

DATADIR_0AD=	${PREFIX}/share/0ad

INSTALLATION_DIRS+=	${DATADIR_0AD}

NO_BUILD=	yes

do-install:
	${RUN} cd ${WRKSRC} && ${PAX} -rw . ${DESTDIR}${DATADIR_0AD}

.include "../../mk/bsd.pkg.mk"
