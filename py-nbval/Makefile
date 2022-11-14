# $NetBSD$

DISTNAME=	nbval-0.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/nbval/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/computationalmodelling/nbval
COMMENT=	Py.test plugin to validate Jupyter notebooks
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-six>=1.16.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-jupyter_client>=7.3.5:../../devel/py-jupyter_client
DEPENDS+=	${PYPKGPREFIX}-nbformat>=5.4.0:../../www/py-nbformat
DEPENDS+=	${PYPKGPREFIX}-ipykernel>=6.16.2:../../devel/py-ipykernel
DEPENDS+=	${PYPKGPREFIX}-coverage>=6.5.0:../../devel/py-coverage

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
