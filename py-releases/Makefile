# $NetBSD$

DISTNAME=	releases-1.6.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=   ${MASTER_SITE_PYPI:=r/releases/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bitprophet/releases
COMMENT=	Sphinx extension for changelog manipulation
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-semantic-version>=2.8.5:../../wip/py-semantic-version
DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.3:../../textproc/py-sphinx

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
