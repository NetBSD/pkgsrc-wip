# $NetBSD$

DISTNAME=	eight2-0.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eight2/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/bopo/eight2
COMMENT=	Python Boilerplate contains all the boilerplate
LICENSE=	mit

PYTHON_VERSIONS_INCOMPATIBLE+=	27

BUILD_DEPENDS+=	${PYPKGPREFIX}-test-runner>=5.2:../../devel/py-test-runner
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=2.1:../../time/py-tzlocal
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.11.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.15.8:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-sxtwl>=1.1.0:../../wip/py-sxtwl
DEPENDS+=	${PYPKGPREFIX}-click>=7.1.2:../../devel/py-click
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.3.5:../../devel/py-test


.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
