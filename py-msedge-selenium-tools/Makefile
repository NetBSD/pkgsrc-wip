# $NetBSD$

DISTNAME=	msedge-selenium-tools-3.141.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=   ${MASTER_SITE_PYPI:=m/msedge-selenium-tools/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/microsoft/edge-selenium-tools
COMMENT=	Updated EdgeDriver implementation for Selenium 3
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-selenium>=3.141:../../www/py-selenium

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
