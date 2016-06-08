# $NetBSD$

DISTNAME=	mps-youtube-0.2.5-2
CATEGORIES=	multimedia net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mps-youtube/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://github.com/np1/mps-youtube
COMMENT=	Terminal based YouTube player and downloader
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pafy>=0.3.72:../../wip/py-pafy

WRKSRC=		${WRKDIR}/mps-youtube-0.2.5

USE_LANGUAGES=	# none

SUBST_CLASSES+=         paths
SUBST_STAGE.paths=      pre-configure
SUBST_SED.paths+=       -e 's,linux,netbsd6,g'
SUBST_FILES.paths+=     setup.py
SUBST_MESSAGE.paths=    Fixing header search paths

.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
