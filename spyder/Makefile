# $NetBSD$

DISTNAME=	spyder-2.3.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PYPI:=s/spyder/}
EXTRACT_SUFX=	.zip

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spyder-ide/spyder/wiki
COMMENT= 	Scientific PYthon Development EnviRonment, alternative to IDLE
LICENSE=	mit

DEPENDS+= 	${PYPKGPREFIX}-rope>=0.9.3:../../devel/py-rope
DEPENDS+= 	${PYPKGPREFIX}-sphinx>=1.2.3:../../textproc/py-sphinx

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		# none

post-extract:
	${MV} ${WRKSRC}/scripts/spyder ${WRKSRC}/scripts/spyder${PYVERSSUFFIX}

.include "options.mk"

.include "../../lang/python/distutils.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/py-qt4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
