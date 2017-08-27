# $NetBSD$

DISTNAME=	mps-youtube-0.2.7.1
CATEGORIES=	multimedia net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mps-youtube/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/np1/mps-youtube
COMMENT=	Terminal based YouTube player and downloader
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-pafy>=0.3.72:../../wip/py-pafy

USE_LANGUAGES=			# none
PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
