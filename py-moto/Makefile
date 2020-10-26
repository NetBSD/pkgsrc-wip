# $NetBSD$

DISTNAME=	moto-1.3.16
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/moto/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/spulec/moto/
COMMENT=	Python tests to easily mock out the boto library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-test>=6.0.2:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-six>=1.15.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-xmltodict>=0.12.0:../../textproc/py-xmltodict
DEPENDS+=	${PYPKGPREFIX}-requests>=2.24.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-responses>=0.12.0:../../net/py-responses
DEPENDS+=	${PYPKGPREFIX}-markupsafe>=1.1.1:../../textproc/py-markupsafe

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
